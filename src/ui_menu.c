#include "global.h"
#include "ui_menu.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "ygo.h"
#include "ygo_graphics.h"
#include "constants/ygo.h"
#include "field_camera.h"

#define TAG_CARD 60000

/*
 * 
 */
 
//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    WINDOW_1,
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sTilemapBuffers[2];

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx, u16 card);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .paletteMode = 1,
        .priority = 0
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 6,
        .mapBaseIndex = 20,
        .priority = 2
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 32,        // width (per 8 pixels)
        .height = 20,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    DUMMY_WIN_TEMPLATE,
};

static const u32 sNormalMonsterTiles[] = INCBIN_U32("graphics/cards/normal_monster.8bpp.lz");
static const u32 sNormalMonsterTilemap[] = INCBIN_U32("graphics/cards/normal_monster.bin.lz");
static const u16 sNormalMonsterPalette[] = INCBIN_U16("graphics/cards/normal_monster.gbapal");
static const u32 sEffectMonsterTiles[] = INCBIN_U32("graphics/cards/effect_monster.8bpp.lz");
static const u32 sEffectMonsterTilemap[] = INCBIN_U32("graphics/cards/effect_monster.bin.lz");
static const u16 sEffectMonsterPalette[] = INCBIN_U16("graphics/cards/effect_monster.gbapal");
static const u32 sSpellCardTiles[] = INCBIN_U32("graphics/cards/spell_card.8bpp.lz");
static const u32 sSpellCardTilemap[] = INCBIN_U32("graphics/cards/spell_card.bin.lz");
static const u16 sSpellCardPalette[] = INCBIN_U16("graphics/cards/spell_card.gbapal");
static const u32 sTrapCardTiles[] = INCBIN_U32("graphics/cards/trap_card.8bpp.lz");
static const u32 sTrapCardTilemap[] = INCBIN_U32("graphics/cards/trap_card.bin.lz");
static const u16 sTrapCardPalette[] = INCBIN_U16("graphics/cards/trap_card.gbapal");
static const u32 sFusionMonsterTiles[] = INCBIN_U32("graphics/cards/fusion_monster.8bpp.lz");
static const u32 sFusionMonsterTilemap[] = INCBIN_U32("graphics/cards/fusion_monster.bin.lz");
static const u16 sFusionMonsterPalette[] = INCBIN_U16("graphics/cards/fusion_monster.gbapal");
static const u32 sBackgroundTiles[] = INCBIN_U32("graphics/cards/background.4bpp.lz");
static const u32 sBackgroundTilemap[] = INCBIN_U32("graphics/cards/background.bin.lz");
static const u16 sBackgroundPalette[] = INCBIN_U16("graphics/cards/background.gbapal");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = CB2_ReturnToBagMenuPocket;
    
    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static const struct CompressedSpriteSheet sSpriteSheet_Cards[] =
{
    {
        .data = gCardPicLarge_4StarredLadybugofDoom_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_7ColoredFish_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AirknightParshath_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AquaMadoor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArmedDragonLV5_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AsuraPriest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BanisheroftheLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BattleOx_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BazootheSoulEater_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Bickuribox_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackLusterSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackSkullDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlastwithChain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlueEyesWhiteDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BookofMoon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BusterBlader_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CalloftheHaunted_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CannonSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Ceasefire_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChangeofHeart_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Confiscation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CrassClown_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CreatureSwap_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkBaltertheTerrible_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkNecrofear_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkRulerHaDes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DelinquentDuo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DonZaloog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DreamClown_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DustTornado_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Exchange_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ExiledForce_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ExodiatheForbiddenOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiberJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Fissure_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlameSwordsman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GaiatheDragonChampion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GaiaTheFierceKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GeminiElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantGerm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantRat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantSoldierofStone_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantTrunade_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GigaTechWolf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoblinAttackForce_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GracefulCharity_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GranmargtheRockMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersAssailant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersSpearSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersSpy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HarpiesFeatherDuster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HeavyStorm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ImperialOrder_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InjectionFairyLily_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JarofGreed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Jinzo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JiraiGumo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JudgeMan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JustDesserts_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KingTigerWanghu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Kuriboh_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KycootheGhostDestroyer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LaJinntheMysticalGenieoftheLamp_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LabyrinthTank_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LastWill_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LeftArmoftheForbiddenOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LeftLegoftheForbiddenOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicCylinder_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicJammer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicianofFaith_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ManEaterBug_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaskofDarkness_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaskedSorcerer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Mechanicalchaser_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Metamorphosis_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MirageofNightmare_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MirrorForce_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MobiustheFrostMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MonsterReborn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MorphingJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MukaMuka_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MysticTomato_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MysticalElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Necrovalley_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeotheMagicSwordsman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NightmareWheel_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NimbleMomonga_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NoblemanofCrossout_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Ookazi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PainfulChoice_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PenguinKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Polymerization_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PotofGreed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PrematureBurial_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Raigeki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReaperontheNightmare_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RedEyesBlackDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Reinforcements_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RightArmoftheForbiddenOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RightLegoftheForbiddenOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RingofDestruction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RobbinGoblin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RushRecklessly_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RyuSenshi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SacredPhoenixofNephthys_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Sangan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SevenToolsoftheBandit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SinisterSerpent_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SkullKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SkullLair_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SnatchSteal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolemnJudgment_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolemnWishes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulExchange_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpearDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpiritReaper_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StJoan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SummonedSkull_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SwordsofRevealingLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheFiendMegacyber_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheForcefulSentry_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheLastWarriorfromAnotherPlanet_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThestalostheFirestormMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThousandEyesRestrict_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThunderDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TimeSeal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TorrentialTribute_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TributetotheDoomed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TwinHeadedThunderDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_UltimateOffering_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_UnitedWeStand_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_UpstartGoblin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Waboku_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WallofIllusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WhiteMagicalHat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WitchoftheBlackForest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_YataGarasu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ZombyratheDark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {},
};

static const union AnimCmd sCardLeftAnimSequence[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sCardLeftAnimTable[] =
{
    sCardLeftAnimSequence,
};

static const struct OamData sCardLeftOamData =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_8BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sCardLeftSpriteTemplate =
{
    .tileTag = TAG_CARD,
    .paletteTag = TAG_CARD,
    .oam = &sCardLeftOamData,
    .anims = sCardLeftAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = NULL,
};

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    u8 spriteId;
    s16 tileNum = AllocSpriteTiles((u8)(CARD_PIC_SIZE / TILE_SIZE_8BPP)); //allocate for a 80x80 sprite
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ResetVramOamAndBgCntRegs();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        LoadCompressedSpriteSheet(&sSpriteSheet_Cards[card - 1]);
        LoadPalette(gCardInfo[card].pal, OBJ_PLTT_ID(0), PLTT_SIZE_4BPP*4);
        spriteId = CreateBigSprite(&sCardLeftSpriteTemplate, 16, 32, 0);
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gMain.state++;
        break;
    case 2:
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_InitWindows();
        gMain.state++;
        break;
    case 5:
        PrintToWindow(WINDOW_1, FONT_WHITE, card);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sTilemapBuffers[0]);
    try_free(sTilemapBuffers[1]);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sTilemapBuffers[0] = AllocZeroed(BG_SCREEN_SIZE);
    if (sTilemapBuffers[0] == NULL)
        return FALSE;
    sTilemapBuffers[1] = AllocZeroed(BG_SCREEN_SIZE);
    if (sTilemapBuffers[1] == NULL)
        return FALSE;
    
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sTilemapBuffers[0]);
    SetBgTilemapBuffer(2, sTilemapBuffers[1]);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_256COLOR);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    u8 cardType = gCardInfo[card].type;
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sBackgroundTiles, 0, 0, 0);
        if (cardType == TYPE_NORMAL_MONSTER)
            DecompressAndCopyTileDataToVram(1, sNormalMonsterTiles, 0, 0, 0);
        else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER)
            DecompressAndCopyTileDataToVram(1, sEffectMonsterTiles, 0, 0, 0);
        else if (cardType == TYPE_SPELL_CARD)
            DecompressAndCopyTileDataToVram(1, sSpellCardTiles, 0, 0, 0);
        else if (cardType == TYPE_TRAP_CARD)
            DecompressAndCopyTileDataToVram(1, sTrapCardTiles, 0, 0, 0);
        else if (cardType == TYPE_FUSION_MONSTER)
            DecompressAndCopyTileDataToVram(1, sFusionMonsterTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sBackgroundTilemap, sTilemapBuffers[1]);
            if (cardType == TYPE_NORMAL_MONSTER)
                LZDecompressWram(sNormalMonsterTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER)
                LZDecompressWram(sEffectMonsterTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_SPELL_CARD)
                LZDecompressWram(sSpellCardTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_TRAP_CARD)
                LZDecompressWram(sTrapCardTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_FUSION_MONSTER)
                LZDecompressWram(sFusionMonsterTilemap, sTilemapBuffers[0]);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sBackgroundPalette, 48, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    
    ScheduleBgCopyTilemapToVram(2);
}

enum {
    COLORID_NORMAL,
    COLORID_POCKET_NAME,
    COLORID_GRAY_CURSOR,
    COLORID_UNUSED,
    COLORID_TMHM_INFO,
    COLORID_NONE = 0xFF
};

static const u8 sFontColorTableUI[][3] = {
                            // bgColor, textColor, shadowColor
    [COLORID_NORMAL]      = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_POCKET_NAME] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_RED},
    [COLORID_GRAY_CURSOR] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_GREEN},
    [COLORID_UNUSED]      = {TEXT_COLOR_DARK_GRAY,   TEXT_COLOR_WHITE,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_TMHM_INFO]   = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5,  TEXT_DYNAMIC_COLOR_1}
};

static void PrintSmallNarrowTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string)
{
    left = (left * 4) - (GetStringWidth(FONT_SMALL_NARROW, string, -1) / 2u);
    AddTextPrinterParameterized3(windowId, FONT_SMALL_NARROW, left, 144, sFontColorTableUI[colorId], 0, string);
}

static void PrintToWindow(u8 windowId, u8 colorIdx, u16 card)
{
    const u8 *cardName = gCardInfo[card].name;
    const u8 cardType = gCardInfo[card].type;
    const u8 *cardDescription = gCardInfo[card].description;
    u8 x = 116;
    u8 y = 0;
    
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    // BlitBitmapToWindow(windowId, gCardPicLarge_DarkMagician, 0, 0, 64, 64);
    // LoadPalette(gCardPalLarge_DarkMagician_4bpp, 0, 32);
    PrintSmallNarrowTextCentered(windowId, 94, COLORID_NORMAL, cardName);
    // AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, x, y, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, cardName);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, x, y + 16, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, cardDescription);
    if (cardType == TYPE_NORMAL_MONSTER)
        LoadPalette(sNormalMonsterPalette, 0, 32*3);
    else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER)
        LoadPalette(sEffectMonsterPalette, 0, 32*3);
    else if (cardType == TYPE_SPELL_CARD)
        LoadPalette(sSpellCardPalette, 0, 32*3);
    else if (cardType == TYPE_TRAP_CARD)
        LoadPalette(sTrapCardPalette, 0, 32*3);
    else if (cardType == TYPE_FUSION_MONSTER)
        LoadPalette(sFusionMonsterPalette, 0, 32*3);
    SetBgTilemapPalette(2, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 3);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}


/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }
}





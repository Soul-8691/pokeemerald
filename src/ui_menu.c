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
#define TAG_ICON 60001

static const union AnimCmd sStarAnimSequence[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd *const sStarAnimTable[] =
{
    sStarAnimSequence,
};

static const struct OamData sStarData =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sStarSpriteTemplate =
{
    .tileTag = TAG_ICON,
    .paletteTag = TAG_ICON,
    .oam = &sStarData,
    .anims = sStarAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = NULL,
};

static const struct SpriteSheet sSpriteSheet_Icons[] =
{
    {
        .data = gStarIcon,
        .size = 8*8/2,
        .tag = TAG_ICON
    },
    {},
};

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
    WINDOW_2,
    WINDOW_3,
    WINDOW_4,
    WINDOW_5,
    WINDOW_6,
    WINDOW_7,
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
        .priority = 0
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .paletteMode = 1,
        .priority = 1
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
        .tilemapLeft = 14,   // position from left (per 8 pixels)
        .tilemapTop = 2,    // position from top (per 8 pixels)
        .width = 16,        // width (per 8 pixels)
        .height = 16,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    [WINDOW_2] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 8,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 5,        // width (per 8 pixels)
        .height = 4,        // height (per 8 pixels)
        .paletteNum = 8,   // palette index to use for text
        .baseBlock = 0x101,     // tile start in VRAM
    },
    [WINDOW_3] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 13,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 4,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 7,   // palette index to use for text
        .baseBlock = 0x115,     // tile start in VRAM
    },
    [WINDOW_4] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 18,    // position from top (per 8 pixels)
        .width = 32,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 0x11D,     // tile start in VRAM
    },
    [WINDOW_5] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 3,   // position from left (per 8 pixels)
        .tilemapTop = 15,    // position from top (per 8 pixels)
        .width = 5,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 0x15D,     // tile start in VRAM
    },
    [WINDOW_6] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 8,   // position from left (per 8 pixels)
        .tilemapTop = 15,    // position from top (per 8 pixels)
        .width = 4,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 0x167,     // tile start in VRAM
    },
    [WINDOW_7] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 10,        // width (per 8 pixels)
        .height = 3,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 0x16F,     // tile start in VRAM
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
static const u32 sRitualMonsterTiles[] = INCBIN_U32("graphics/cards/ritual_monster.8bpp.lz");
static const u32 sRitualMonsterTilemap[] = INCBIN_U32("graphics/cards/ritual_monster.bin.lz");
static const u16 sRitualMonsterPalette[] = INCBIN_U16("graphics/cards/ritual_monster.gbapal");
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

const u8 *const sCardAttributeIcons_[NUM_ATTRIBUTES + 1] =
{
    [ATTRIBUTE_DARK] = gDarkIcon,
    [ATTRIBUTE_LIGHT] = gLightIcon,
    [ATTRIBUTE_FIRE] = gFireIcon,
    [ATTRIBUTE_WATER] = gWaterIcon,
    [ATTRIBUTE_EARTH] = gEarthIcon,
    [ATTRIBUTE_WIND] = gWindIcon,
};

const u16 *const sCardAttributeIconPals_[NUM_ATTRIBUTES + 1] =
{
    [ATTRIBUTE_DARK] = gDarkIconPal,
    [ATTRIBUTE_LIGHT] = gLightIconPal,
    [ATTRIBUTE_FIRE] = gFireIconPal,
    [ATTRIBUTE_WATER] = gWaterIconPal,
    [ATTRIBUTE_EARTH] = gEarthIconPal,
    [ATTRIBUTE_WIND] = gWindIconPal,
};

const u8 *const sCardRaceIcons_[NUM_RACES + 1] =
{
    [RACE_SPELLCASTER] = gSpellcasterIcon,
    [RACE_DRAGON] = gDragonIcon,
    [RACE_ROCK] = gRockIcon,
    [RACE_WARRIOR] = gWarriorIcon,
    [RACE_FIEND] = gFiendIcon,
    [RACE_INSECT] = gBugIcon,
    [RACE_BEAST_WARRIOR] = gBeastWarriorIcon,
    [RACE_FISH] = gFishIcon,
    [RACE_THUNDER] = gLightningIcon,
    [RACE_MACHINE] = gMachineIcon,
    [RACE_PLANT] = gPlantIcon,
    [RACE_FAIRY] = gFairyIcon,
    [RACE_AQUA] = gAquaIcon,
    [RACE_BEAST] = gBeastIcon,
    [RACE_REPTILE] = gReptileIcon,
    [RACE_ZOMBIE] = gZombieIcon,
    [RACE_WINGED_BEAST] = gWingedBeastIcon,
    [RACE_PYRO] = gPyroIcon,
};

const u16 *const sCardRaceIconPals_[NUM_RACES + 1] =
{
    [RACE_SPELLCASTER] = gSpellcasterIconPal,
    [RACE_DRAGON] = gDragonIconPal,
    [RACE_ROCK] = gRockIconPal,
    [RACE_WARRIOR] = gWarriorIconPal,
    [RACE_FIEND] = gFiendIconPal,
    [RACE_INSECT] = gBugIconPal,
    [RACE_BEAST_WARRIOR] = gBeastWarriorIconPal,
    [RACE_FISH] = gFishIconPal,
    [RACE_THUNDER] = gLightningIconPal,
    [RACE_MACHINE] = gMachineIconPal,
    [RACE_PLANT] = gPlantIconPal,
    [RACE_FAIRY] = gFairyIconPal,
    [RACE_AQUA] = gAquaIconPal,
    [RACE_BEAST] = gBeastIconPal,
    [RACE_REPTILE] = gReptileIconPal,
    [RACE_ZOMBIE] = gZombieIconPal,
    [RACE_WINGED_BEAST] = gWingedBeastIconPal,
    [RACE_PYRO] = gPyroIconPal,
};

const u8 *const sCardTypeIcons_[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = gSpellIcon,
    [TYPE_TRAP_CARD] = gTrapIcon,
};

const u16 *const sCardTypeIconPals_[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = gSpellIconPal,
    [TYPE_TRAP_CARD] = gTrapIconPal,
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
        .data = gCardPicLarge_AWingbeatofGiantDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AbyssDweller_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AbyssSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Abysssphere_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Abysssquall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AccumulatedFortune_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AcidTrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AdreusKeeperofArmageddon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AdvancedRitualArt_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AirknightParshath_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AllureofDarkness_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AllyofJusticeCatastor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AllyofJusticeDecisiveArmor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AmazonessArcher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AncientFairyDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AncientGearGadjiltronDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AncientSacredWyvern_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AngelofZera_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AntiSpellFragrance_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ApprenticeMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AquaMadoor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AquaSpirit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArcaniteMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArchfiendSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArchlordKristya_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArmadesKeeperofBoundaries_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArmageddonKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArmoredKappa_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArmoryArm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactBeagalltach_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactDurendal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactIgnition_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactMoralltach_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactSanctum_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ArtifactScythe_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AsceticismoftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AsuraPriest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AtlanteanDragoons_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AtlanteanHeavyInfantry_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AtlanteanMarksman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AurkusLightswornDruid_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AutonomousActionUnit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AvengingKnightParshath_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_AzureEyesSilverDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BahamutShark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BanisheroftheLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BanisheroftheRadiance_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BarrelBehindtheDoor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BattleFader_Big,
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
        .data = gCardPicLarge_BeastKingBarbaros_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BeckoningLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BeelzeFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BerserkGorilla_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Bickuribox_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BigShieldGardna_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackHornofHeaven_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackLusterSoldierEnvoyoftheBeginning_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackRoseDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackSalvo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackSkullDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackWhirlwind_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingBlizzardtheFarNorth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingBoratheSpear_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingGaletheWhirlwind_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingKaluttheMoonShadow_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingShuratheBlueFlame_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingSilverwindtheAscendant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingSiroccotheDawn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingVayutheEmblemofHonor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingArmedWing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlackwingArmorMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BladeArmorNinja_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BladeKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlastwithChain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlasterDragonRulerofInfernos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlueThunderT45_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlueEyesUltimateDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BlueEyesWhiteDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BookofEclipse_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BookofLife_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BookofMoon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BookofTaiyou_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BottomlessTrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrainControl_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BreakertheMagicalWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BreakthroughSkill_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrionacDragonoftheIceBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistBear_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistBoar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistCardinal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistGorilla_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrotherhoodoftheFireFistTigerKing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BrowwHuntsmanofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujinHirume_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujinMikazuchi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujinYamato_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Bujincarnation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujingiCrane_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujingiHare_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujingiQuilin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujingiSinyou_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujingiTurtle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujinteiKagutsuchi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BujinteiSusanowo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BurialfromaDifferentDimension_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_BurnerDragonRulerofSparks_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CaiustheShadowMonarch_Big,
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
        .data = gCardPicLarge_CardDestruction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardofSafeReturn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardTrooper_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardcarD_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardsforBlackFeathers_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardsfromtheSky_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CardsofConsonance_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CastleofDragonSouls_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CastleWalls_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CatapultTurtle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Ceasefire_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CelestiaLightswornAngel_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChainDisappearance_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChainEnergy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChainStrike_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChangeofHeart_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChaosEmperorDragonEnvoyoftheEnd_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChaosSorcerer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChargeoftheLightBrigade_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CharubintheFireKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChimeratechFortressDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChimeratechOverdragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ChirontheMage_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Chivalry_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CipherSoldier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CircleoftheFireKings_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ClosedForest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CoachSoldierWolfbark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ColdWave_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ColossalFighter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CommonCharity_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CompulsoryEscapeDevice_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CompulsoryEvacuationDevice_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Confiscation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConsecratedLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarAlgiedi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarKaus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarOmega_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarPleiades_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarPollux_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarPtolemyM7_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ConstellarSombre_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ContractwiththeAbyss_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CorridorofAgony_Big,
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
        .data = gCardPicLarge_CreviceIntotheDifferentDimension_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CrimsonBlader_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CrusaderofEndymion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CrushCardVirus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CrystalSeer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CunningoftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CursedSealoftheForbiddenSpell_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberBlader_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberEndDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberOgre2_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberPhoenix_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberSaurus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberTwinDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberValley_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_CyberStein_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDAssailant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDCrow_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDDesignator_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDSurvivor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDWarriorLady_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDMDifferentDimensionMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DDRDifferentDimensionReincarnation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DaigustoEmeral_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DaigustoPhoenix_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Dandylion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkArmedDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkBaltertheTerrible_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkBladetheDragonKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkBribe_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkDustSpirit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkEndDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkEruption_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkFlareKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkGrepher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkMagicianofChaos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkMimicLV3_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkNephthys_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkPaladin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkRulerHaDes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkSmog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkStrikeFighter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkWorldDealings_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkWorldLightning_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkfireDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarkflareDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DarklordZerato_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeSpell_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DebrisDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Debunk_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeckDevastationVirus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeckLockdown_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeepDarkTrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeepSeaDiva_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeepseaShark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DekoichitheBattlechantedLocomotive_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DelinquentDuo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DeltaCrowAntiReverse_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DemiseKingofArmageddon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DesFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DesKoala_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DesWombat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DesertSunlight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyDraw_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODasher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODefender_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODiamondDude_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODiskCommander_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODogma_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHERODoomLord_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHEROFearMonger_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHEROMalicious_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DestinyHEROPlasma_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DewlorenTigerKingoftheIceBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DiamondDireWolf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DifferentDimensionCapsule_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DimensionFusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DimensionWall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DimensionalAlchemist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DimensionalFissure_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DimensionalPrison_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DivineDragonKnightFelgrand_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DivineSwordPhoenixBlade_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DivineWrath_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DNASurgery_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DonZaloog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DoomDozer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DoomcaliberKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DoomkaiserDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DoubleCyclone_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DoubleEdgedSwordTechnique_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DownerdMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DraggedDownintotheGrave_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragonRavine_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragonShrine_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragonesstheWickedKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragonicKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityArmaMystletainn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityCorsesca_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityDux_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityKnightGaeDearg_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityKnightVajrayana_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DragunityPhalanx_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DrillWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Drillroid_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DrollLockBird_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DropOff_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DupeFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_DustTornado_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EEmergencyCall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EclipseWyvern_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EffectVeiler_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EhrenLightswornMonk_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElderoftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElectricSnake_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElectricVirus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROAbsoluteZero_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROAirNeos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROBubbleman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROChaosNeos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHERODarkNeos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROElectrum_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROFlameWingman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROGaia_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROGrandNeos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROMariner_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHERONeosAlius_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROOcean_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROPhoenixEnforcer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROPrisma_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROShiningFlareWingman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROStratos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROTempest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROTheShining_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ElementalHEROWildheart_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EmergencyProvisions_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EmergencyTeleport_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EmpressJudge_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EnemyController_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EradicatorEpidemicVirus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EscapefromtheDarkDimension_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvigishkiMerrowgeist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilHERODarkGaia_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmBahamut_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmCastor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmExcitonKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmHeliotrope_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmKerykeion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmMandragora_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmOphion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmOuroboros_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvilswarmThunderbird_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvolzarDolkka_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_EvolzarLaggia_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ExarionUniverse_Big,
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
        .data = gCardPicLarge_ExploderDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FairyKingAlbverdich_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FakeTrap_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FencingFireFerret_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiberJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiendSkullDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiendishChain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FinalFlame_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireFormationGyokkou_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireFormationTenken_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireFormationTenki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireFormationTensen_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireFormationTensu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireHand_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireKingAvatarBarong_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireKingAvatarYaksha_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FireKingHighAvatarGarunix_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiresofDoomsday_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FishborgBlaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Fissure_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FiveHeadedDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlameGhost_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlameSwordsman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlamvellFiredog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlamvellGuard_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlamvellUruquizas_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlipFlopFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlowerWolf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FlyingC_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FogKing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FoolishBurial_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ForbiddenChalice_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ForbiddenDress_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ForbiddenLance_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FormulaSynchron_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FossilDynaPachycephalo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FullHouse_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FusilierDragontheDualModeBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Fusionist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_FutureFusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GBHunter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GachiGachiGantetsu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GagagaCowboy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GaiaDragontheThunderCharger_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GaiaKnighttheForceofEarth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GaiatheDragonChampion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GarothLightswornWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GatewayoftheSix_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GatlingDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GauntletLauncher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GearGigantX_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GearfriedtheIronKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geargiaccelerator_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geargiagear_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geargiano_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GeargianoMkII_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geargiarmor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geargiarsenal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Geartown_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GemKnightPearl_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GeminiElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GeminiImps_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GeminiSpark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GenerationShift_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GenexAllyBirdman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GenexController_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GenexUndine_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GhostrickAlucard_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantGerm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiantOrc_Big,
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
        .data = gCardPicLarge_Gigantes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Gigaplant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Gilasaurus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GiltiatheDKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastBestiari_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastDarius_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastEqueste_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastGaiodiaz_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastGyzarus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastHeraklinos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastHoplomus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastLaquari_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastMurmillo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastRetiari_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastSamnite_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastSecutor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastWarChariot_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorBeastsRespite_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GladiatorProvingGround_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GlowUpBulb_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoblinAttackForce_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoblinZombie_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoldSarcophagus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GolddWuLordofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoodGoblinHousekeeping_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GorztheEmissaryofDarkness_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GottomsEmergencyCall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GoyoGuardian_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GozenMatch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GracefulCharity_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GrandmasteroftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GrandsoiltheElementalLord_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GraphaDragonLordofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersAssailant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersCommandant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersDescendant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersGuard_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersRecruiter_Big,
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
        .data = gCardPicLarge_GravekeepersStele_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravekeepersWatcher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GravityBind_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GreatShogunShien_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GreatWhite_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GreenBaboonDefenderoftheForest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GreenGadget_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GungnirDragonoftheIceBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GyakuGirePanda_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_GyakutennoMegami_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HallowedLifeBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HammerShot_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HandDestruction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HaneHane_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Hanewata_Big,
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
        .data = gCardPicLarge_HeraldofGreenLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HeraldofOrangeLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HeraldofPureLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HerosRule2_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HeroicChampionExcalibur_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HiddenArmory_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticDragonKingofAtum_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticDragonofEset_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticDragonofSu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticDragonofTefnuit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticSealFromtheAshes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticSealofConvocation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HieraticSunDragonOverlordofHeliopolis_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HierophantofProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HighPriestessofProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Honest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HornofHeaven_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HornofthePhantomBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HorustheBlackFlameDragonLV6_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HorustheBlackFlameDragonLV8_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HTSPsyhemuth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_HundredEyesDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Hydrogeddon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_IcarusAttack_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_IceHand_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_IlBlud_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ImperialIronWall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ImperialOrder_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityArchfiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityAvenger_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityBeetle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityBreak_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityDoomDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityInferno_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityLauncher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityMirage_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfernityNecromancer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfestationInfection_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfestationPandemic_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InfestationTerminus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InjectionFairyLily_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InsectKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InstantFusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InzektorCentipede_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InzektorDragonfly_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InzektorExaBeetle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InzektorHornet_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_InzektorSwordZektkaliber_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_IronChainDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JainLightswornPaladin_Big,
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
        .data = gCardPicLarge_JowgentheSpiritualist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JudgeMan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JudgmentDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JudgmentofAnubis_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JunkDestroyer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JurracGuaiba_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JustDesserts_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_JusticeofProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Kabazauls_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KagemushaoftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Kagetokage_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriKomachimdl224Ninishi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriMerchantmdl177Inashichi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriMusomdl818Haipa_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriNinjamdl919Kuick_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriShogunmdl00Burei_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriSoldiermdl236Nisamu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriSteelShogunmdl00XBureido_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriStrategistmdl248Nishipachi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarakuriWatchdogmdl313Saizan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KarbonalaWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KingDragun_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KingoftheFeralImps_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KingTigerWanghu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KoakiMeiruDrago_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Krebons_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Kuriboh_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_KwagarHercules_Big,
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
        .data = gCardPicLarge_LabradoriteDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LabyrinthTank_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LastDayofWitch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LastWill_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LavaGolem_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LavalvalChain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LeechingtheLight_Big,
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
        .data = gCardPicLarge_LegacyofYataGarasu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LegendaryJujitsuMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LegendarySixSamuraiKageki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LegendarySixSamuraiKizan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LegendarySixSamuraiShiEn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LeotheKeeperoftheSacredTree_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LevelLimitAreaB_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LeviairtheSeaDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LightandDarknessDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LightImprisoningMirror_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LightningVortex_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LightningDragonRulerofDrafts_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LightpulsarDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LimitReverse_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LimiterRemoval_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LonefireBlossom_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LuminaLightswornSummoner_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_LylaLightswornSorceress_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MachinaCannon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MachinaForce_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MachinaFortress_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MachinaGearframe_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MachineDuplication_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MacroCosmos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MadolcheMagileine_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaestroketheSymphonyDjinn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagePower_Big,
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
        .data = gCardPicLarge_MagicalAndroid_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicalExplosion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicalMallet_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicalMerchant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicalScientist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicalStoneExcavation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MagicianofFaith_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaleficCyberEndDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaleficStardustDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MalevolentCatastrophe_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ManEaterBug_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ManjuoftheTenThousandHands_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MarkoftheRose_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Marshmallon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaskofDarkness_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaskofRestrict_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaskedSorcerer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MassDriver_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MasterHyperion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MasterofOz_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MaxxC_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MechaPhantomBeastDracossack_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MechaDogMarron_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Mechanicalchaser_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MechquippedAngineer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Megamorph_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MeiKouMasterofBarriers_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssgaios_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssgunde_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssleed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbysslinde_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssmegalo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbysspike_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssteus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbysstrite_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MermailAbyssturge_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MessengerofPeace_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MetaiontheTimelord_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MetalArmoredBug_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MetalDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Metamorphosis_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Mezuki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Minar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MindControl_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MindCrush_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MindDrain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MiracleFertilizer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MiracleFusion_Big,
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
        .data = gCardPicLarge_MirrorofOaths_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MistWurm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MobiustheFrostMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MonsterGate_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MonsterReborn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MonsterReincarnation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MorayofGreed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MorphingJar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MotherGrizzly_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MoulinglaciatheElementalLord_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MukaMuka_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MusicianKing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MyBodyasaShield_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MysticSwordsmanLV2_Big,
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
        .data = gCardPicLarge_MysticalRefpanel_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MysticalShineBall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MysticalSpaceTyphoon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MystikWok_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MythicTreeDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_MythicWaterDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NaturiaBarkion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NaturiaBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NecroGardna_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Necrovalley_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeedleCeiling_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NekoManeKing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeoBug_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeotheMagicSwordsman_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeoSpacianDarkPanther_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NeoSpacianGrandMole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Newdoria_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NightAssailant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NightBeam_Big,
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
        .data = gCardPicLarge_NinjaGrandmasterHanzo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NinjaGrandmasterSasuke_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NinjitsuArtofSuperTransformation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NitroWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NoblemanofCrossout_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NoblemanofExtermination_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NonAggressionArea_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number101SilentHonorARK_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number103Ragnazero_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number106GiantHand_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number11BigEye_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number16ShockMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number17LeviathanDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number20GigaBrilliant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number30AcidGolemofDestruction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number39Utopia_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number47NightmareShark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number50BlackshipofCorn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number61Volcasaurus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number66MasterKeyBeetle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number80RhapsodyinBerserk_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number82Heartlandraco_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number85CrazyBox_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Number96DarkMist_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_NumberC39UtopiaRay_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OjamaKing_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OjamaKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OjamaTrio_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OldVindictiveMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OneDayofPeace_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OneforOne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OnslaughtoftheFireKings_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Ookazi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OrientDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_OverloadFusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Overworked_Big,
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
        .data = gCardPicLarge_PhantomDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PhantomofChaos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PhoenixWingWindBlast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PhotonPapilloperative_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PhotonStrikeBounzer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PhotonThrasher_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PikerusCircleofEnchantment_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PlaguespreaderZombie_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PoisonDrawFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PoisonoftheOldMan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PolePosition_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Polymerization_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PotofAvarice_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PotofDuality_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PotofGreed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PowerToolDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PrematureBurial_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PrimeMaterialDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PrincessofTsurugi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Prohibition_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PrometheusKingoftheShadows_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ProtectoroftheSanctuary_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PsiBlocker_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PsychicCommander_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PsychicLifetrancer_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PullingtheRug_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PunishedEagle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PuppetPlant_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_PyramidTurtle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_QueenDragunDjinn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_QuickdrawSynchron_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Raigeki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RaigekiBreak_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RainbowLife_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RaizatheStormMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReactanDragonRulerofPebbles_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReaperontheNightmare_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Reasoning_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RebornTengu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RecklessGreed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RedDragonArchfiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RedGadget_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RedEyesDarknessMetalDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RedoxDragonRulerofBoulders_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReflectBounder_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReinforceTruth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReinforcementoftheArmy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Reinforcements_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Rekindling_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Relinquished_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Reload_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RemoveTrap_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RescueCat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RescueRabbit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Retort_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ReturnfromtheDifferentDimension_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RevivedKingHaDes_Big,
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
        .data = gCardPicLarge_RingofDefense_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RingofDestruction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RivalryofWarlords_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RoaringOceanSnake_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RobbinGoblin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Ronintoadin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RoseWarriorofRevenge_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RoyalDecree_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RoyalOppression_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RoyalTribute_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RushRecklessly_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RykoLightswornHunter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RyuKokki_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_RyuSenshi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SaberHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SaberSlash_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Sabersaurus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SacredCrane_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SacredSwordofSevenStars_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SafeZone_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SakuretsuArmor_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Salvage_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Sangan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Sanwitch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SasukeSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Scapegoat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapArchfiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapChimera_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapGoblin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ScrapGolem_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Scrapstorm_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SeaDragonLordGishilnodon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SecretBarrel_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SelfDestructButton_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SenjuoftheThousandHands_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SerialSpell_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SevenToolsoftheBandit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShadowImprisoningMirror_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShiensSmokeSignal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShiningAngel_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShiningElf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShinyBlackC_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ShootingStarDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Shrink_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SillvaWarlordofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SinisterSerpent_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SixSamuraiUnited_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SixthSense_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SkillDrain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SkilledDarkMagician_Big,
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
        .data = gCardPicLarge_SkullMeister_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SmashingGround_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SnatchSteal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SnipeHunter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SnowmanEater_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SnowwUnlightofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolarRecharge_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolemnJudgment_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolemnWarning_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SolemnWishes_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SonicBird_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulCharge_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulDrain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulExchange_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulofSilvermountain_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulRelease_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SoulTaker_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpearCretin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpearDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellCanceller_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellEconomics_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellReproduction_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellShieldType8_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellStriker_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookLibraryoftheCrescent_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookMagicianofProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofEternity_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofFate_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofJudgment_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofLife_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofPower_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofSecrets_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookoftheMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookofWisdom_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpellbookStarHall_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpiritoftheHarp_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpiritoftheSixSamurai_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpiritReaper_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SpiritualWaterArtAoi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Spiritualism_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SplendidRose_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Spore_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StJoan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StarEater_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StardustDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StardustSparkDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StarliegePaladynamo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StarlightRoad_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StealthBird_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SteamGyroid_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SteelswarmRoach_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StopDefense_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StreamDragonRulerofDroplets_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StrikeNinja_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StygianSergeants_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_StygianStreetPatrol_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Substitoad_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SummonLimit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SummonedSkull_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SummonerMonk_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperPolymerization_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperRejuvenation_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperRobolady_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperRoboyarou_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperSolarNutrient_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperVehicroidJumboDrill_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SuperNimbleMegaHamster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Supervise_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SwallowFlip_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SwapFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SwiftScarecrow_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SwordsofRevealingLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_SystemDown_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGHyperLibrarian_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGPowerGladiator_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGRushRhino_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGStriker_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGWarwolf_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TGWonderMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TemperanceofProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TempestMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TempestDragonRulerofStorms_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TemtempothePercussionDjinn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Terraforming_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TestTiger_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TG1EM1_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheAgentofCreationVenus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheAgentofMiraclesJupiter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheAgentofMysteryEarth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheFabledCatsith_Big,
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
        .data = gCardPicLarge_TheGatesofDarkWorld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheGrandSpellbookTower_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheLastWarriorfromAnotherPlanet_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheLightHexSealedFusion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheLittleSwordsmanofAile_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheSixSamuraiIrou_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheSixSamuraiKamon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheSixSamuraiYaichi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheSixSamuraiZanji_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheTransmigrationProphecy_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheWhiteStoneofLegend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TheWickedWormBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThestalostheFirestormMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThoughtRulerArchfiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThousandDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThousandEyesRestrict_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThreateningRoar_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThunderDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThunderKingRaiOh_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ThunderNyanNyan_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TidalDragonRulerofWaterfalls_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TimeSeal_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TinGoldfish_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TirasKeeperofGenesis_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ToonTableofContents_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TorrentialTribute_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TourGuideFromtheUnderworld_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TradeIn_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Tragoedia_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TranceArchfiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapDustshoot_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapEater_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapMaster_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrapStun_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TraptrixDionaea_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TraptrixMyrmeleo_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TraptrixTrapHoleNightmare_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TreacherousTrapHole_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TreebornFrog_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TremendousFire_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TribeInfectingVirus_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TributetotheDoomed_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TridentDragion_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Trigon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TrishulaDragonoftheIceBarrier_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Tsukuyomi_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TurboWarrior_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TwinHeadedBehemoth_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TwinHeadedThunderDragon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Twister_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_TytannialPrincessofCamellias_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_UFOTurtle_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_UltimateOffering_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Unifrog_Big,
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
        .data = gCardPicLarge_VanDalgyontheDarkDragonLord_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VanitysEmptiness_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VanitysFiend_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VolcanicQueen_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VolcanicRocket_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VolcanicShell_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VorseRaider_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_VortexTrooper_Big,
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
        .data = gCardPicLarge_WallofRevealingLight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WarriorElimination_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WarriorofTradition_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WaveMotionCannon_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WhiteMagicalHat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WidespreadDud_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WidespreadRuin_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpArsenalZenmaioh_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpCarrierZenmaity_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpFactory_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpHunter_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpMagician_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpRabbit_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpRat_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpShark_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpZenmaines_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WindUpZenmaister_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WingedKuriboh_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WingedRhynos_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_Wiretap_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WitchoftheBlackForest_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_WulfLightswornBeast_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XSaberAirbellum_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XSaberPashuul_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XSaberUrbellum_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XSaberWayne_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XingZhenHu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberBoggartKnight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberDarksoul_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberEmmersblade_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberFaultroll_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberFulhelmknight_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberGottoms_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberHyunlei_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XXSaberRagigura_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_XyzEncore_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_YataGarasu_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_YellowGadget_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ZaborgtheThunderMonarch_Big,
        .size = 80*80,
        .tag = TAG_CARD
    },
    {
        .data = gCardPicLarge_ZombieMaster_Big,
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

static const struct SpritePalette sIcon_SpritePalettes[] =
{
    {gStarIconPal,     TAG_ICON},
};

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    u8 spriteId;
    u32 i;
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    u8 level = gCardInfo[card].level;
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
        LoadSpriteSheet(&sSpriteSheet_Icons[0]);
        LoadSpritePaletteInSlot(&sIcon_SpritePalettes[0], 4);
        for (i = 0; i < level; i++)
        {
            if (level < 12)
                spriteId = CreateSprite(&sStarSpriteTemplate, 96 - (i * 8), 25, 0);
            else
                spriteId = CreateSprite(&sStarSpriteTemplate, 96 - (i * 7), 25, 0);
            gSprites[spriteId].callback = SpriteCallbackDummy;
        }
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
        else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER || cardType == TYPE_SPIRIT_MONSTER || cardType == TYPE_UNION_EFFECT_MONSTER || cardType == TYPE_TOON_MONSTER)
            DecompressAndCopyTileDataToVram(1, sEffectMonsterTiles, 0, 0, 0);
        else if (cardType == TYPE_SPELL_CARD)
            DecompressAndCopyTileDataToVram(1, sSpellCardTiles, 0, 0, 0);
        else if (cardType == TYPE_TRAP_CARD)
            DecompressAndCopyTileDataToVram(1, sTrapCardTiles, 0, 0, 0);
        else if (cardType == TYPE_FUSION_MONSTER)
            DecompressAndCopyTileDataToVram(1, sFusionMonsterTiles, 0, 0, 0);
        else if (cardType == TYPE_RITUAL_MONSTER || cardType == TYPE_RITUAL_EFFECT_MONSTER)
            DecompressAndCopyTileDataToVram(1, sRitualMonsterTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sBackgroundTilemap, sTilemapBuffers[1]);
            if (cardType == TYPE_NORMAL_MONSTER)
                LZDecompressWram(sNormalMonsterTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER || cardType == TYPE_SPIRIT_MONSTER || cardType == TYPE_UNION_EFFECT_MONSTER || cardType == TYPE_TOON_MONSTER)
                LZDecompressWram(sEffectMonsterTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_SPELL_CARD)
                LZDecompressWram(sSpellCardTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_TRAP_CARD)
                LZDecompressWram(sTrapCardTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_FUSION_MONSTER)
                LZDecompressWram(sFusionMonsterTilemap, sTilemapBuffers[0]);
            else if (cardType == TYPE_RITUAL_MONSTER || cardType == TYPE_RITUAL_EFFECT_MONSTER)
                LZDecompressWram(sRitualMonsterTilemap, sTilemapBuffers[0]);
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
    FillWindowPixelBuffer(WINDOW_2, 0);
    FillWindowPixelBuffer(WINDOW_3, 0);
    FillWindowPixelBuffer(WINDOW_4, 0);
    FillWindowPixelBuffer(WINDOW_5, 0);
    FillWindowPixelBuffer(WINDOW_6, 0);
    FillWindowPixelBuffer(WINDOW_7, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    PutWindowTilemap(WINDOW_2);
    PutWindowTilemap(WINDOW_3);
    PutWindowTilemap(WINDOW_4);
    PutWindowTilemap(WINDOW_5);
    PutWindowTilemap(WINDOW_6);
    PutWindowTilemap(WINDOW_7);
    CopyWindowToVram(WINDOW_1, 3);
    CopyWindowToVram(WINDOW_2, 3);
    CopyWindowToVram(WINDOW_3, 3);
    CopyWindowToVram(WINDOW_4, 3);
    CopyWindowToVram(WINDOW_5, 3);
    CopyWindowToVram(WINDOW_6, 3);
    CopyWindowToVram(WINDOW_7, 3);
    
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
    AddTextPrinterParameterized3(windowId, FONT_SMALL_NARROW, left, 0, sFontColorTableUI[colorId], 0, string);
}

static void PrintToWindow(u8 windowId, u8 colorIdx, u16 card)
{
    const u8 *cardName = gCardInfo[card].name;
    const u8 *cardNameShort = gCardInfo[card].nameShort;
    const u8 cardType = gCardInfo[card].type;
    const u8 race = gCardInfo[card].race;
    const u8 attribute = gCardInfo[card].attribute;
    const u8 *cardDescription = gCardInfo[card].description;
    const u16 cardAtk = gCardInfo[card].atk * 10;
    const u16 cardDef = gCardInfo[card].def * 10;
    u8 x = 0;
    u8 y = 0;
    
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PrintSmallNarrowTextCentered(WINDOW_4, 94, COLORID_NORMAL, cardName);
    AddTextPrinterParameterized4(WINDOW_7, FONT_SMALL_NARROWER, 6, 6, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, cardNameShort);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, x, y, 0, 0, sMenuWindowFontColors[colorIdx], 0xFF, cardDescription);
    if (cardType != TYPE_SPELL_CARD && cardType != TYPE_TRAP_CARD)
    {
        ConvertIntToDecimalStringN(gStringVar1, cardAtk, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_xAtk);
        AddTextPrinterParameterized4(WINDOW_5, FONT_SMALL_NARROWER, 2, 5, 0, 0, sMenuWindowFontColors[COLORID_NORMAL], 0xFF, gStringVar4);
        ConvertIntToDecimalStringN(gStringVar1, cardDef, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_xDef);
        AddTextPrinterParameterized4(WINDOW_6, FONT_SMALL_NARROWER, 0, 5, 0, 0, sMenuWindowFontColors[COLORID_NORMAL], 0xFF, gStringVar4);
    }
    if (cardType == TYPE_NORMAL_MONSTER)
        LoadPalette(sNormalMonsterPalette, 0, 32*3);
    else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER || cardType == TYPE_SPIRIT_MONSTER || cardType == TYPE_UNION_EFFECT_MONSTER || cardType == TYPE_TOON_MONSTER)
        LoadPalette(sEffectMonsterPalette, 0, 32*3);
    else if (cardType == TYPE_SPELL_CARD)
        LoadPalette(sSpellCardPalette, 0, 32*3);
    else if (cardType == TYPE_TRAP_CARD)
        LoadPalette(sTrapCardPalette, 0, 32*3);
    else if (cardType == TYPE_FUSION_MONSTER)
        LoadPalette(sFusionMonsterPalette, 0, 32*3);
    else if (cardType == TYPE_RITUAL_MONSTER || cardType == TYPE_RITUAL_EFFECT_MONSTER)
        LoadPalette(sRitualMonsterPalette, 0, 32*3);
    SetBgTilemapPalette(2, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 3);
    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_3, PIXEL_FILL(0));
    if (cardType == TYPE_SPELL_CARD || cardType == TYPE_TRAP_CARD)
    {
        BlitBitmapToWindow(WINDOW_2, sCardTypeIcons_[cardType], 22, 6, 16, 16);
        LoadPalette(sCardTypeIconPals_[cardType], BG_PLTT_ID(8), 32);
    }
    else
    {
        BlitBitmapToWindow(WINDOW_3, sCardRaceIcons_[race], 6, 0, 16, 16);
        LoadPalette(sCardRaceIconPals_[race], BG_PLTT_ID(7), 32);
        BlitBitmapToWindow(WINDOW_2, sCardAttributeIcons_[attribute], 22, 6, 16, 16);
        LoadPalette(sCardAttributeIconPals_[attribute], BG_PLTT_ID(8), 32);
    }
    PutWindowTilemap(windowId);
    PutWindowTilemap(WINDOW_2);
    PutWindowTilemap(WINDOW_3);
    PutWindowTilemap(WINDOW_4);
    PutWindowTilemap(WINDOW_5);
    PutWindowTilemap(WINDOW_6);
    PutWindowTilemap(WINDOW_7);
    CopyWindowToVram(windowId, 3);
    CopyWindowToVram(WINDOW_2, 3);
    CopyWindowToVram(WINDOW_3, 3);
    CopyWindowToVram(WINDOW_4, 3);
    CopyWindowToVram(WINDOW_5, 3);
    CopyWindowToVram(WINDOW_6, 3);
    CopyWindowToVram(WINDOW_7, 3);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
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





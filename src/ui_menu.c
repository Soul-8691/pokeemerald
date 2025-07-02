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
static EWRAM_DATA u8 sScrollDown = 0;
EWRAM_DATA bool8 sDidInitialDraw = FALSE;

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
        .charBaseIndex = 2,
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



const u8 *const sCardAttributeIcons[NUM_ATTRIBUTES + 1] =
{
    [ATTRIBUTE_DARK] = gDarkIcon,
    [ATTRIBUTE_LIGHT] = gLightIcon,
    [ATTRIBUTE_FIRE] = gFireIcon,
    [ATTRIBUTE_WATER] = gWaterIcon,
    [ATTRIBUTE_EARTH] = gEarthIcon,
    [ATTRIBUTE_WIND] = gWindIcon,
};

const u16 *const sCardAttributeIconPals[NUM_ATTRIBUTES + 1] =
{
    [ATTRIBUTE_DARK] = gDarkIconPal,
    [ATTRIBUTE_LIGHT] = gLightIconPal,
    [ATTRIBUTE_FIRE] = gFireIconPal,
    [ATTRIBUTE_WATER] = gWaterIconPal,
    [ATTRIBUTE_EARTH] = gEarthIconPal,
    [ATTRIBUTE_WIND] = gWindIconPal,
};

const u8 *const sCardRaceIcons[NUM_RACES + 1] =
{
    [RACE_AQUA] = gAquaIcon,
    [RACE_BEAST] = gBeastIcon,
    [RACE_BEAST_WARRIOR] = gBeastWarriorIcon,
    [RACE_DINOSAUR] = gDinosaurIcon,
    [RACE_DRAGON] = gDragonIcon,
    [RACE_FAIRY] = gFairyIcon,
    [RACE_FIEND] = gFiendIcon,
    [RACE_FISH] = gFishIcon,
    [RACE_INSECT] = gBugIcon,
    [RACE_MACHINE] = gMachineIcon,
    [RACE_PLANT] = gPlantIcon,
    [RACE_PYRO] = gPyroIcon,
    [RACE_REPTILE] = gReptileIcon,
    [RACE_ROCK] = gRockIcon,
    [RACE_SEA_SERPENT] = gSeaSerpentIcon,
    [RACE_SPELLCASTER] = gSpellcasterIcon,
    [RACE_THUNDER] = gLightningIcon,
    [RACE_WARRIOR] = gWarriorIcon,
    [RACE_WINGED_BEAST] = gWingedBeastIcon,
    [RACE_ZOMBIE] = gZombieIcon,
};

const u16 *const sCardRaceIconPals[NUM_RACES + 1] =
{
    [RACE_AQUA] = gAquaIconPal,
    [RACE_BEAST] = gBeastIconPal,
    [RACE_BEAST_WARRIOR] = gBeastWarriorIconPal,
    [RACE_DINOSAUR] = gDinosaurIconPal,
    [RACE_DRAGON] = gDragonIconPal,
    [RACE_FAIRY] = gFairyIconPal,
    [RACE_FIEND] = gFiendIconPal,
    [RACE_FISH] = gFishIconPal,
    [RACE_INSECT] = gBugIconPal,
    [RACE_MACHINE] = gMachineIconPal,
    [RACE_PLANT] = gPlantIconPal,
    [RACE_PYRO] = gPyroIconPal,
    [RACE_REPTILE] = gReptileIconPal,
    [RACE_ROCK] = gRockIconPal,
    [RACE_SEA_SERPENT] = gSeaSerpentIconPal,
    [RACE_SPELLCASTER] = gSpellcasterIconPal,
    [RACE_THUNDER] = gLightningIconPal,
    [RACE_WARRIOR] = gWarriorIconPal,
    [RACE_WINGED_BEAST] = gWingedBeastIconPal,
    [RACE_ZOMBIE] = gZombieIconPal,
};

const u8 *const sCardTypeIcons[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = gSpellIcon,
    [TYPE_TRAP_CARD] = gTrapIcon,
};

const u16 *const sCardTypeIconPals[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = gSpellIconPal,
    [TYPE_TRAP_CARD] = gTrapIconPal,
};

const u8 *const gCardTypeText[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = gText_Spell,
    [TYPE_TRAP_CARD] = gText_Trap,
    [TYPE_SPIRIT_MONSTER] = gText_Spirit,
    [TYPE_EFFECT_MONSTER] = gText_Effect,
    [TYPE_FLIP_EFFECT_MONSTER] = gText_FlipEffect,
    [TYPE_RITUAL_MONSTER] = gText_Ritual,
    [TYPE_RITUAL_EFFECT_MONSTER] = gText_RitualEffect,
    [TYPE_FUSION_MONSTER] = gText_Fusion,
    [TYPE_UNION_EFFECT_MONSTER] = gText_UnionEffect,
    [TYPE_NORMAL_MONSTER] = gText_NormalMonster,
    [TYPE_TOON_MONSTER] = gText_Toon,
    [TYPE_XYZ_MONSTER] = gText_XYZ,
    [TYPE_SYNCHRO_MONSTER] = gText_Synchro,
    [TYPE_TUNER_MONSTER] = gText_Tuner,
    [TYPE_SYNCHRO_TUNER_MONSTER] = gText_SynchroTuner,
};

const u8 gSupportedTypes[NUM_TYPES + 1] =
{
    [TYPE_SPELL_CARD] = 1,
    [TYPE_TRAP_CARD] = 1,
    [TYPE_SPIRIT_MONSTER] = 1,
    [TYPE_EFFECT_MONSTER] = 1,
    [TYPE_FLIP_EFFECT_MONSTER] = 1,
    [TYPE_RITUAL_MONSTER] = 1,
    [TYPE_RITUAL_EFFECT_MONSTER] = 1,
    [TYPE_FUSION_MONSTER] = 1,
    [TYPE_UNION_EFFECT_MONSTER] = 1,
    [TYPE_NORMAL_MONSTER] = 1,
    [TYPE_TOON_MONSTER] = 1,
    [TYPE_XYZ_MONSTER] = 1,
    [TYPE_SYNCHRO_MONSTER] = 1,
    [TYPE_TUNER_MONSTER] = 1,
    [TYPE_SYNCHRO_TUNER_MONSTER] = 1,
};

const u8 sMenuWindowFontColors[][3] = 
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
			.data = gCardPicLarge_ALegendaryOcean_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AbyssSoldier_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AirknightParshath_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AmazonessArcher_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AmphibiousBugrothMK3_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AntiSpellFragrance_Big,
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
			.data = gCardPicLarge_ArchfiendSoldier_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArsenalBug_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArsenalSummoner_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AsuraPriest_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AxeofDespair_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BanisheroftheLight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BarrelBehindtheDoor_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BattleFootballer_Big,
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
			.data = gCardPicLarge_BigBangShot_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BigShieldGardna_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BigTuskedMammoth_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackIllusionRitual_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackLusterSoldierEnvoyoftheBeginning_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackPendant_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackSkullDragon_Big,
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
			.data = gCardPicLarge_BlazingInpachi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlindlyLoyalGoblin_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlockAttack_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlowbackDragon_Big,
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
			.data = gCardPicLarge_Bowganian_Big,
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
			.data = gCardPicLarge_BrowwHuntsmanofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BrronMadKingofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BusterBlader_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ByserShock_Big,
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
			.data = gCardPicLarge_CastleofDarkIllusions_Big,
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
			.data = gCardPicLarge_ChainsawInsect_Big,
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
			.data = gCardPicLarge_CharcoalInpachi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ChirontheMage_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CipherSoldier_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ColdWave_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CommandKnight_Big,
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
			.data = gCardPicLarge_CrushCardVirus_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CursedSealoftheForbiddenSpell_Big,
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
			.data = gCardPicLarge_CyberHarpieLady_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberJar_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberTwinDragon_Big,
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
			.data = gCardPicLarge_DDCrazyBeast_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DDSurvivor_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DDTrainer_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DDWarriorLady_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkBlade_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkBladetheDragonKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkDeal_Big,
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
			.data = gCardPicLarge_DarkMagicCurtain_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMagician_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMagicianofChaos_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMimicLV1_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMimicLV3_Big,
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
			.data = gCardPicLarge_DarkScorpionChicktheYellow_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkScorpionClifftheTrapRemover_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkWorldLightning_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DeSpell_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DeckDevastationVirus_Big,
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
			.data = gCardPicLarge_DesDendle_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DesKoala_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DesLacooda_Big,
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
			.data = gCardPicLarge_DianKetotheCureMaster_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DimensionFusion_Big,
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
			.data = gCardPicLarge_DraggedDownintotheGrave_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DragonsMirror_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DragonsRage_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DreamClown_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Drillroid_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DropOff_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DunamesDarkWitch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DustTornado_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EarthboundSpirit_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ElectricSnake_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ElementalHEROClayman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ElementalHEROFlameWingman_Big,
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
			.data = gCardPicLarge_EmissaryoftheAfterlife_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EnemyController_Big,
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
			.data = gCardPicLarge_ExchangeoftheSpirit_Big,
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
			.data = gCardPicLarge_FakeTrap_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FamiliarPossessedAussa_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FamiliarPossessedEria_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FamiliarPossessedHiita_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FamiliarPossessedWynn_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FiberJar_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FinalFlame_Big,
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
			.data = gCardPicLarge_FlyingKamakiri1_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FusilierDragontheDualModeBeast_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Gagagigo_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GaiaPower_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GaiatheDragonChampion_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GatlingDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GearGolemtheMovingFortress_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GearfriedtheIronKnight_Big,
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
			.data = gCardPicLarge_GiantRedSeasnake_Big,
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
			.data = gCardPicLarge_GilGarth_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Gilasaurus_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GoblinAttackForce_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GoblinEliteAttackForce_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Gokipon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GolemSentry_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GoraTurtle_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GracefulCharity_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GravekeepersAssailant_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GravekeepersGuard_Big,
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
			.data = gCardPicLarge_GreatWhite_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GuardianSphinx_Big,
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
			.data = gCardPicLarge_HaneHane_Big,
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
			.data = gCardPicLarge_Hieracosphinx_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_HornofHeaven_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_HowlingInsect_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_HumanoidSlime_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Hydrogeddon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_HyperHammerhead_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ImperialOrder_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_InabaWhiteRabbit_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_IndomitableFighterLeiLei_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_InjectionFairyLily_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Inpachi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_InsectKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_IslandTurtle_Big,
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
			.data = gCardPicLarge_JustDesserts_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KaiserSeaHorse_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KarmaCut_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KingDragun_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KingoftheSwamp_Big,
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
			.data = gCardPicLarge_LadyNinjaYae_Big,
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
			.data = gCardPicLarge_LegendaryJujitsuMaster_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LevelLimitAreaB_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LeviaDragonDaedalus_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LightofIntervention_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LightningVortex_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LimiterRemoval_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LusterDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MadDogofDarkness_Big,
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
			.data = gCardPicLarge_MagicalDimension_Big,
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
			.data = gCardPicLarge_MagicianofFaith_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MagiciansCircle_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MagiciansValkyria_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MaidenoftheAqua_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MakyuratheDestructor_Big,
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
			.data = gCardPicLarge_ManticoreofDarkness_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MaraudingCaptain_Big,
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
			.data = gCardPicLarge_MaskedDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MaskedSorcerer_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MatazatheZapper_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Mechanicalchaser_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Megamorph_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MermaidKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MessengerofPeace_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MetalReflectSlime_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Metamorphosis_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MilusRadiant_Big,
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
			.data = gCardPicLarge_MineGolem_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MiracleRestoring_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MirageDragon_Big,
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
			.data = gCardPicLarge_MoaiInterceptorCannons_Big,
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
			.data = gCardPicLarge_MukaMuka_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MysticSwordsmanLV2_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MysticSwordsmanLV4_Big,
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
			.data = gCardPicLarge_NightmareWheel_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_NightmaresSteelcage_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_NimbleMomonga_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_NinKenDog_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_NinjaGrandmasterSasuke_Big,
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
			.data = gCardPicLarge_OfferingstotheDoomed_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_OjamaKing_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_OjamaTrio_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Ookazi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_OppressedPeople_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Opticlops_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PainfulChoice_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PaladinofWhiteDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PenguinKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PhoenixWingWindBlast_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PikerusCircleofEnchantment_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PinchHopper_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PitchBlackPowerStone_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PoisonoftheOldMan_Big,
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
			.data = gCardPicLarge_PotofGenerosity_Big,
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
			.data = gCardPicLarge_PreventRat_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PrickleFairy_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PrincessofTsurugi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ProtectoroftheSanctuary_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_PyramidTurtle_Big,
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
			.data = gCardPicLarge_RecklessGreed_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ReflectBounder_Big,
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
			.data = gCardPicLarge_ReturnfromtheDifferentDimension_Big,
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
			.data = gCardPicLarge_RisingAirCurrent_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RobbinGoblin_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RouletteBarrel_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RoyalDecree_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RoyalMagicalLibrary_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RoyalOppression_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RushRecklessly_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RyuKokki_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SaberBeetle_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SacredCrane_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SacredPhoenixofNephthys_Big,
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
			.data = gCardPicLarge_SandMoth_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Sangan_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SasukeSamurai_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SasukeSamurai4_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Scapegoat_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SeaSerpentWarriorofDarkness_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SecondCoinToss_Big,
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
			.data = gCardPicLarge_SerialSpell_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SerpentinePrincess_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SevenToolsoftheBandit_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ShiningAngel_Big,
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
			.data = gCardPicLarge_Silpheed_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SinisterSerpent_Big,
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
			.data = gCardPicLarge_SkilledWhiteMagician_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SkullDogMarron_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SkullLair_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SkyScout_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SlateWarrior_Big,
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
			.data = gCardPicLarge_SoulTiger_Big,
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
			.data = gCardPicLarge_SpellReproduction_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SpiritoftheHarp_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SpiritReaper_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SpiritualEarthArtKurogane_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SpiritualWaterArtAoi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SpiritualWindArtMiyabi_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Spiritualism_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_StealthBird_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_StoneStatueoftheAztecs_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_StopDefense_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SummonedSkull_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SwarmofLocusts_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SwarmofScarabs_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SwordsofRevealingLight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Terraforming_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheBigMarchofAnimals_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheDragonDwellingintheCave_Big,
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
			.data = gCardPicLarge_TheForgivingMaiden_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheLastWarriorfromAnotherPlanet_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheLittleSwordsmanofAile_Big,
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
			.data = gCardPicLarge_ThrowstoneUnit_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderNyanNyan_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TimeSeal_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ToonCannonSoldier_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ToonDarkMagicianGirl_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ToonGeminiElf_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ToonGoblinAttackForce_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ToonMaskedSorcerer_Big,
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
			.data = gCardPicLarge_TrapDustshoot_Big,
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
			.data = gCardPicLarge_Tsukuyomi_Big,
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
			.data = gCardPicLarge_UltimateInsectLV3_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_UltimateInsectLV5_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_UltimateInsectLV7_Big,
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
			.data = gCardPicLarge_VampireLord_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_VorseRaider_Big,
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
			.data = gCardPicLarge_WaveMotionCannon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_WhiteDragonRitual_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_WhiteMagicalHat_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_WidespreadRuin_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_WitchoftheBlackForest_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_XHeadCannon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_XingZhenHu_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_YataGarasu_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_YomiShip_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ZaborgtheThunderMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ZombyratheDark_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ZureKnightofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AmazonessSpiritualist_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AncientGearDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_AngmarltheFiendishMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ApprenticeIllusionMagician_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendCavalry_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendCommander_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendGiant_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendHeiress_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendInterceptor_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendofGilfer_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ArchfiendsAdvent_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BakutheBeastNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BeginningKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BeiigeVanguardofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BerlineththeFirestormVassal_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackDragonsChick_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlackMetalDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BlueFlameSwordsman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_BoneArchfiend_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CaiustheShadowMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ChronicleSorceress_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberDragonDrei_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberDragonVier_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberDragonZwei_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberLarva_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_CyberdarkWurm_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMagicianGirl_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DarkMagicianGirltheMagiciansApprentice_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DefenderofNephthys_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DelgtheDarkMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DictatorofD_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DimensionConjurer_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DiscipleofNephthys_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_DupeFrog_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EidostheUnderworldMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EidostheUnderworldSquire_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ElementalHEROBlazeman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ElementalHEROWoodsman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EnvoyofChaos_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_EveningTwilightKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FightingFlameSwordsman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FlipFlopFrog_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_FusionDevourer_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GearfriedtheRedEyesIronKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GemKnightQuartz_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GentaGatemanofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GiltiatheDKnightSoulSpear_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GoblinPotholeSquad_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GranmargtheRockMonarch_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GreenNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_GrenTacticianofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_HandofNephthys_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_IceKnight_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_InfernalqueenSalmon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KagerotheCannonNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Kaibaman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KeeperofDragonMagic_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_KeeperoftheShrine_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LancerArchfiend_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LesserFiend_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LordofD_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LucentNetherlordofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_LuciustheShadowVassal_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MadArchfiend_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MagiciansRobe_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MagiciansRod_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MagiciansSouls_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Magikuriboh_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MaskedNinjaEbisu_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MatriarchofNephthys_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MetalflameSwordsman_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MitsutheInsectNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_MysticalElfWhiteLightning_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_NinjaGrandmasterHanzo_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ParlHermitofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RedDragonNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RedEyesBabyDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RedEyesBlackMeteorDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RedEyesRetroDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_RedEyesWyvern_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Relinkuriboh_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Ronintoadin_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SalamandratheFlyingFlameDragon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ScarrScoutofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SeniorSilverNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SenjuoftheThousandHands_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SkilledRedMagician_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SnowwUnlightofDarkWorld_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SonicBird_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SphereKuriboh_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Substitoad_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SuperSoldierSoul_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_SwapFrog_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TADPOLE_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Tenmataitei_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheBlackStoneofLegend_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheDarkHexSealedFusion_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheEarthHexSealedFusion_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TheLightHexSealedFusion_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderDragondark_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderDragonhawk_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderDragonmatrix_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderDragonroar_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_ThunderSeaHorse_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TlakalelHisMalevolentMajesty_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TobaritheSkyNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Tradetoad_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixArachnocampa_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixAtrax_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixDionaea_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixGenlisea_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixMantis_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixMyrmeleo_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixNepenthes_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixPudica_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TraptrixVesiculo_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TwilightNinjaNichirintheChunin_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_TwilightNinjaShingetsu_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_UpstartGoldenNinja_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_VisionHEROVyon_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_Wroughtweiler_Big,
			.size = 80*80,
			.tag = TAG_CARD
		},
    {
			.data = gCardPicLarge_YellowNinja_Big,
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
        else
            DecompressAndCopyTileDataToVram(1, sNormalMonsterTiles, 0, 0, 0);
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
            else
                LZDecompressWram(sNormalMonsterTilemap, sTilemapBuffers[0]);
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
    else
        LoadPalette(sNormalMonsterPalette, 0, 32*3);
    SetBgTilemapPalette(2, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 3);
    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_3, PIXEL_FILL(0));
    if (cardType == TYPE_SPELL_CARD || cardType == TYPE_TRAP_CARD)
    {
        BlitBitmapToWindow(WINDOW_2, sCardTypeIcons[cardType], 22, 6, 16, 16);
        LoadPalette(sCardTypeIconPals[cardType], BG_PLTT_ID(8), 32);
    }
    else
    {
        BlitBitmapToWindow(WINDOW_3, sCardRaceIcons[race], 6, 0, 16, 16);
        LoadPalette(sCardRaceIconPals[race], BG_PLTT_ID(7), 32);
        BlitBitmapToWindow(WINDOW_2, sCardAttributeIcons[attribute], 22, 6, 16, 16);
        LoadPalette(sCardAttributeIconPals[attribute], BG_PLTT_ID(8), 32);
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

void DrawScrolledText(const u8 *fullText, u32 startIndex, u8 linesToDraw)
{
    u8 buffer[512];
    u32 i = startIndex;
    u32 bufIndex = 0;
    u8 lines = 0;

    DebugPrintf("DrawScrolledText: startIndex=%d, linesToDraw=%d", startIndex, linesToDraw);

    while (fullText[i] != EOS && lines < linesToDraw)
    {
        if (fullText[i] == CHAR_NEWLINE)
            lines++;

        buffer[bufIndex++] = fullText[i++];
    }

    buffer[bufIndex] = EOS;

    DebugPrintf("Displayed text:\n%s", buffer);

    // Draw to window
    FillWindowPixelBuffer(WINDOW_1, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_1);
    AddTextPrinterParameterized4(WINDOW_1, FONT_SMALL_NARROWER, 0, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, buffer);
    CopyWindowToVram(WINDOW_1, 3);
}

u16 CountNumLines(const u8 *text)
{
    u16 i, count = 1;  // Start from 1 for the first line
    for (i = 0; text[i] != EOS; i++)
        if (text[i] == CHAR_NEWLINE)
            count++;
    return count;
}

u32 GetLineStartIndex(const u8 *text, u8 lineNum)
{
    u32 i = 0, currentLine = 0;

    if (lineNum == 0)
        return 0;

    while (text[i] != EOS)
    {
        if (text[i] == CHAR_NEWLINE)
        {
            currentLine++;
            if (currentLine == lineNum)
                return i + 1;  // Start after newline
        }
        i++;
    }

    return i;  // End of string if lineNum too large
}

#define NUM_VISIBLE_LINES 15

static void Task_MenuMain(u8 taskId)
{
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    const u8 *cardDescription = gCardInfo[card].description;
    u8 totalLines = CountNumLines(cardDescription);
    u32 startIdx;

    if (!sDidInitialDraw)
    {
        sScrollDown = 0;
        startIdx = GetLineStartIndex(cardDescription, sScrollDown);
        DrawScrolledText(cardDescription, startIdx, NUM_VISIBLE_LINES);
        DebugPrintf("Initial draw: totalLines=%d", totalLines);
        sDidInitialDraw = TRUE;
    }

    if (JOY_NEW(B_BUTTON))
    {
        sScrollDown = 0;
        sDidInitialDraw = FALSE;
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
        return;
    }

    if (JOY_NEW(DPAD_DOWN) && sScrollDown + NUM_VISIBLE_LINES < totalLines)
    {
        sScrollDown++;
        startIdx = GetLineStartIndex(cardDescription, sScrollDown);
        DebugPrintf("DPAD_DOWN: sScrollDown=%d startIdx=%d", sScrollDown, startIdx);
        DrawScrolledText(cardDescription, startIdx, NUM_VISIBLE_LINES);
    }

    if (JOY_NEW(DPAD_UP) && sScrollDown > 0)
    {
        sScrollDown--;
        startIdx = GetLineStartIndex(cardDescription, sScrollDown);
        DebugPrintf("DPAD_UP: sScrollDown=%d startIdx=%d", sScrollDown, startIdx);
        DrawScrolledText(cardDescription, startIdx, NUM_VISIBLE_LINES);
    }
}





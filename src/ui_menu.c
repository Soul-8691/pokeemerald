#include "global.h"
#include "ui_menu.h"
#include "strings.h"
#include "bg.h"
#include "battle_main.h"
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

const struct SpriteTemplate sStarSpriteTemplate =
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
EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
EWRAM_DATA u8 *sTilemapBuffers[2];
EWRAM_DATA u8 sScrollDown = 0;
EWRAM_DATA bool8 sDidInitialDraw = FALSE;

//==========STATIC=DEFINES==========//

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
        .paletteNum = 10,   // palette index to use for text
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
        .paletteNum = 10,   // palette index to use for text
        .baseBlock = 0x11D,     // tile start in VRAM
    },
    [WINDOW_5] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 3,   // position from left (per 8 pixels)
        .tilemapTop = 15,    // position from top (per 8 pixels)
        .width = 5,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 10,   // palette index to use for text
        .baseBlock = 0x15D,     // tile start in VRAM
    },
    [WINDOW_6] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 8,   // position from left (per 8 pixels)
        .tilemapTop = 15,    // position from top (per 8 pixels)
        .width = 4,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 10,   // palette index to use for text
        .baseBlock = 0x167,     // tile start in VRAM
    },
    [WINDOW_7] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 10,        // width (per 8 pixels)
        .height = 3,        // height (per 8 pixels)
        .paletteNum = 10,   // palette index to use for text
        .baseBlock = 0x16F,     // tile start in VRAM
    },
    DUMMY_WIN_TEMPLATE,
};

const u32 sNormalMonsterTiles[] = INCBIN_U32("graphics/cards/normal_monster.8bpp.lz");
const u32 sNormalMonsterTilemap[] = INCBIN_U32("graphics/cards/normal_monster.bin.lz");
const u16 sNormalMonsterPalette[] = INCBIN_U16("graphics/cards/normal_monster.gbapal");
const u32 sEffectMonsterTiles[] = INCBIN_U32("graphics/cards/effect_monster.8bpp.lz");
const u32 sEffectMonsterTilemap[] = INCBIN_U32("graphics/cards/effect_monster.bin.lz");
const u16 sEffectMonsterPalette[] = INCBIN_U16("graphics/cards/effect_monster.gbapal");
const u32 sSpellCardTiles[] = INCBIN_U32("graphics/cards/spell_card.8bpp.lz");
const u32 sSpellCardTilemap[] = INCBIN_U32("graphics/cards/spell_card.bin.lz");
const u16 sSpellCardPalette[] = INCBIN_U16("graphics/cards/spell_card.gbapal");
const u32 sTrapCardTiles[] = INCBIN_U32("graphics/cards/trap_card.8bpp.lz");
const u32 sTrapCardTilemap[] = INCBIN_U32("graphics/cards/trap_card.bin.lz");
const u16 sTrapCardPalette[] = INCBIN_U16("graphics/cards/trap_card.gbapal");
const u32 sFusionMonsterTiles[] = INCBIN_U32("graphics/cards/fusion_monster.8bpp.lz");
const u32 sFusionMonsterTilemap[] = INCBIN_U32("graphics/cards/fusion_monster.bin.lz");
const u16 sFusionMonsterPalette[] = INCBIN_U16("graphics/cards/fusion_monster.gbapal");
const u32 sRitualMonsterTiles[] = INCBIN_U32("graphics/cards/ritual_monster.8bpp.lz");
const u32 sRitualMonsterTilemap[] = INCBIN_U32("graphics/cards/ritual_monster.bin.lz");
const u16 sRitualMonsterPalette[] = INCBIN_U16("graphics/cards/ritual_monster.gbapal");
const u32 sBackgroundTiles[] = INCBIN_U32("graphics/cards/background.4bpp.lz");
const u32 sBackgroundTilemap[] = INCBIN_U32("graphics/cards/background.bin.lz");
const u16 sBackgroundPalette[] = INCBIN_U16("graphics/cards/background.gbapal");
const u32 sPendulumMonsterTiles[] = INCBIN_U32("graphics/cards/pendulum.8bpp.lz");
const u32 sPendulumMonsterTilemap[] = INCBIN_U32("graphics/cards/pendulum.bin.lz");
const u16 sPendulumMonsterPalette[] = INCBIN_U16("graphics/cards/pendulum.gbapal");
const u32 sLinkMonsterTiles[] = INCBIN_U32("graphics/cards/link.8bpp.lz");
const u32 sLinkMonsterTilemap[] = INCBIN_U32("graphics/cards/link.bin.lz");
const u16 sLinkMonsterPalette[] = INCBIN_U16("graphics/cards/link.gbapal");
const u32 sXYZMonsterTiles[] = INCBIN_U32("graphics/cards/xyz.8bpp.lz");
const u32 sXYZMonsterTilemap[] = INCBIN_U32("graphics/cards/xyz.bin.lz");
const u16 sXYZMonsterPalette[] = INCBIN_U16("graphics/cards/xyz.gbapal");
const u32 sSynchroMonsterTiles[] = INCBIN_U32("graphics/cards/synchro.8bpp.lz");
const u32 sSynchroMonsterTilemap[] = INCBIN_U32("graphics/cards/synchro.bin.lz");
const u16 sSynchroMonsterPalette[] = INCBIN_U16("graphics/cards/synchro.gbapal");

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

#define TYPE_NORMAL_MONSTER 0
#define TYPE_EFFECT_MONSTER 1
#define TYPE_FLIP_EFFECT_MONSTER 2
#define TYPE_FLIP_TUNER_EFFECT_MONSTER 3
#define TYPE_FUSION_MONSTER 4
#define TYPE_GEMINI_MONSTER 5
#define TYPE_LINK_MONSTER 6
#define TYPE_NORMAL_TUNER_MONSTER 7
#define TYPE_PENDULUM_EFFECT_FUSION_MONSTER 8
#define TYPE_PENDULUM_EFFECT_MONSTER 9
#define TYPE_PENDULUM_EFFECT_RITUAL_MONSTER 10
#define TYPE_PENDULUM_FLIP_EFFECT_MONSTER 11
#define TYPE_PENDULUM_NORMAL_MONSTER 12
#define TYPE_PENDULUM_TUNER_EFFECT_MONSTER 13
#define TYPE_RITUAL_EFFECT_MONSTER 14
#define TYPE_RITUAL_MONSTER 15
#define TYPE_SPELL_CARD 16
#define TYPE_SPIRIT_MONSTER 17
#define TYPE_SYNCHRO_MONSTER 18
#define TYPE_SYNCHRO_PENDULUM_EFFECT_MONSTER 19
#define TYPE_SYNCHRO_TUNER_MONSTER 20
#define TYPE_TOKEN 21
#define TYPE_TOON_MONSTER 22
#define TYPE_TRAP_CARD 23
#define TYPE_TUNER_MONSTER 24
#define TYPE_UNION_EFFECT_MONSTER 25
#define TYPE_XYZ_MONSTER 26
#define TYPE_XYZ_PENDULUM_EFFECT_MONSTER 27

const u8 *const gCardTypeText[NUM_TYPES + 1] =
{
    [TYPE_EFFECT_MONSTER] = gText_Effect,
    [TYPE_FLIP_EFFECT_MONSTER] = gText_FlipEffect,
    [TYPE_FLIP_TUNER_EFFECT_MONSTER] = gText_FlipTuner,
    [TYPE_FUSION_MONSTER] = gText_Fusion,
    [TYPE_LINK_MONSTER] = gText_Link,
    [TYPE_NORMAL_MONSTER] = gText_NormalMonster,
    [TYPE_NORMAL_TUNER_MONSTER] = gText_NormalTuner,
    [TYPE_PENDULUM_EFFECT_FUSION_MONSTER] = gText_PendulumEffect,
    [TYPE_PENDULUM_EFFECT_MONSTER] = gText_PendulumEffect,
    [TYPE_PENDULUM_EFFECT_RITUAL_MONSTER] = gText_PendulumRitual,
    [TYPE_PENDULUM_FLIP_EFFECT_MONSTER] = gText_PendulumFlip,
    [TYPE_PENDULUM_NORMAL_MONSTER] = gText_PendulumNormal,
    [TYPE_PENDULUM_TUNER_EFFECT_MONSTER] = gText_PendulumTuner,
    [TYPE_RITUAL_EFFECT_MONSTER] = gText_RitualEffect,
    [TYPE_RITUAL_MONSTER] = gText_Ritual,
    [TYPE_SPELL_CARD] = gText_Spell,
    [TYPE_SPIRIT_MONSTER] = gText_Spirit,
    [TYPE_SYNCHRO_MONSTER] = gText_Synchro,
    [TYPE_SYNCHRO_PENDULUM_EFFECT_MONSTER] = gText_SynchroPendulum,
    [TYPE_SYNCHRO_TUNER_MONSTER] = gText_SynchroTuner,
    [TYPE_TOON_MONSTER] = gText_Toon,
    [TYPE_TRAP_CARD] = gText_Trap,
    [TYPE_TUNER_MONSTER] = gText_Tuner,
    [TYPE_UNION_EFFECT_MONSTER] = gText_UnionEffect,
    [TYPE_XYZ_MONSTER] = gText_XYZ,
    [TYPE_XYZ_PENDULUM_EFFECT_MONSTER] = gText_XYZPendulum,
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
	if (battle) sMenuDataPtr->savedCallback = CB2_InitYGODuelInternal;
    
    SetMainCallback2(Menu_RunSetup);
}

void Menu_RunSetup(void)
{
    while (1)
    {
        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

const struct CompressedSpriteSheet sSpriteSheet_Cards[] =
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
		.data = gCardPicLarge_ABCDragonBuster_Big,
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
		.data = gCardPicLarge_AdvancedRitualArt_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AgidotheAncientSentinel_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AirknightParshath_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlbaLenatustheAbyssDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlbaztheAshen_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlbiontheSanctifireDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlbiontheShroudedDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlexandriteDragon_Big,
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
		.data = gCardPicLarge_AllyofJusticeCycleReader_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AlubertheJesterofDespia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AmazonessArcher_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AmazonessSpiritualist_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AmphibiousBugrothMK3_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AmuletDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AncientFairyDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AncientGearDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AncientGearGolemUltimatePound_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AngmarltheFiendishMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AntiSpellFragrance_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ApollousaBowoftheGoddess_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ApprenticeIllusionMagician_Big,
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
		.data = gCardPicLarge_ArchfiendBlackSkullDragon_Big,
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
		.data = gCardPicLarge_ArchfiendEccentrick_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArchfiendEmpress_Big,
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
		.data = gCardPicLarge_ArchfiendSoldier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArchfiendsAdvent_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArchfiendsManifestation_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArchnemesesProtos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArielPriestessoftheNekroz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArisenGaiatheFierceKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArmageddonKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArmedNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArmoredCybern_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ArmoryArm_Big,
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
		.data = gCardPicLarge_ArtifactLancea_Big,
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
		.data = gCardPicLarge_AshBlossomJoyousSpring_Big,
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
		.data = gCardPicLarge_AvanceSwordsmanoftheNekroz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AxeDragonute_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_AxeofDespair_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BakutheBeastNinja_Big,
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
		.data = gCardPicLarge_Baobaboon_Big,
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
		.data = gCardPicLarge_BaxiaBrightnessoftheYangZing_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BazootheSoulEater_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BeastofTalwar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BeastofTalwarTheSwordSummit_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BeatriceLadyoftheEternal_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BeckoningLight_Big,
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
		.data = gCardPicLarge_BerserkDragon_Big,
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
		.data = gCardPicLarge_BlackDragonsChick_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlackHornofHeaven_Big,
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
		.data = gCardPicLarge_BlackLusterSoldierEnvoyoftheEveningTwilight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlackMetalDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlackPendant_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlackRoseDragon_Big,
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
		.data = gCardPicLarge_BlazingCartesiatheVirtuous_Big,
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
		.data = gCardPicLarge_BlueFlameSwordsman_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesAlternativeUltimateDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesAlternativeWhiteDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesJetDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesToonDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesTwinBurstDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BlueEyesTyrantDragon_Big,
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
		.data = gCardPicLarge_BM4BlastSpider_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BoneArchfiend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Bonfire_Big,
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
		.data = gCardPicLarge_BorreloadDragon_Big,
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
		.data = gCardPicLarge_BrandedinHighSpirits_Big,
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
		.data = gCardPicLarge_BrigrandtheGloryDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BrilliantRose_Big,
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
		.data = gCardPicLarge_BusterBlader_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BusterBladertheDestructionSwordmaster_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BusterBladertheDragonDestroyerSwordsman_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ByserShock_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BystialBaldrake_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BystialDruiswurm_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BystialMagnamhut_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_BystialSaronir_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CaiustheMegaMonarch_Big,
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
		.data = gCardPicLarge_CalledbytheGrave_Big,
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
		.data = gCardPicLarge_CardofDemise_Big,
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
		.data = gCardPicLarge_CasteltheSkyblasterMusketeer_Big,
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
		.data = gCardPicLarge_ChaosHunter_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ChaosNephthys_Big,
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
		.data = gCardPicLarge_ChargeoftheLightBrigade_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ChargingGaiatheFierceKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ChickenGame_Big,
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
		.data = gCardPicLarge_ChronicleMagician_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ChronicleSorceress_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CipherSoldier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CirMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ClorlessChaosKingofDarkWorld_Big,
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
		.data = gCardPicLarge_ConsecratedLight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CosmicCyclone_Big,
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
		.data = gCardPicLarge_CrimsonNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CrossoutDesignator_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CrushCardVirus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CrystalRose_Big,
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
		.data = gCardPicLarge_CyberDragonDrei_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CyberDragonInfinity_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CyberDragonNova_Big,
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
		.data = gCardPicLarge_CyberEltanin_Big,
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
		.data = gCardPicLarge_CyberLarva_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CyberPhoenix_Big,
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
		.data = gCardPicLarge_CyberdarkWurm_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_CynetMining_Big,
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
		.data = gCardPicLarge_DDCrow_Big,
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
		.data = gCardPicLarge_DaigustoEmeral_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DancePrincessoftheNekroz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Dandylion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DangerNessie_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DanteTraveleroftheBurningAbyss_Big,
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
		.data = gCardPicLarge_DarkCavalry_Big,
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
		.data = gCardPicLarge_DarkEndDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkEradicatorWarlock_Big,
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
		.data = gCardPicLarge_DarkMagicianGirl_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkMagicianGirltheDragonKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkMagicianGirltheMagiciansApprentice_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkMagicianofChaos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkMagiciantheDragonKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DarkMagiciantheKnightofDragonMagic_Big,
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
		.data = gCardPicLarge_DarkRulerNoMore_Big,
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
		.data = gCardPicLarge_DarkStrikeFighter_Big,
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
		.data = gCardPicLarge_DarklordZerato_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DeFusion_Big,
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
		.data = gCardPicLarge_DeepSeaDiva_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DeepEyesWhiteDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DefenderofNephthys_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DekoichitheBattlechantedLocomotive_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DelgtheDarkMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DelinquentDuo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DemiseKingofArmageddon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DenkoSekka_Big,
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
		.data = gCardPicLarge_DestinyDraw_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DestinyHEROCelestial_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DestinyHERODasher_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DestinyHERODestroyerPhoenixEnforcer_Big,
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
		.data = gCardPicLarge_DharctheDarkCharmerGloomy_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DiabellstartheBlackWitch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DiamondDireWolf_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DianKetotheCureMaster_Big,
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
		.data = gCardPicLarge_DimensionFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DimensionShifter_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DimensionWall_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DimensionalBarrier_Big,
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
		.data = gCardPicLarge_DingirsutheOrcustoftheEveningStar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DinomightKnighttheTrueDracofighter_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DinosterPowertheMightyDracoslayer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DinowrestlerCapaptera_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DinowrestlerPankratops_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DinowrestlerValeonyx_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DiscipleofNephthys_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DivineArsenalAAZEUSSkyThunder_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DivineDragonKnightFelgrand_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DivineTempleoftheSnakeEye_Big,
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
		.data = gCardPicLarge_DominusImpulse_Big,
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
		.data = gCardPicLarge_DownerdMagician_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DracoFaceOff_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DracobacktheRideableDragon_Big,
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
		.data = gCardPicLarge_DragonesstheWickedKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DragonicDiagram_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_DragunityCorsesca_Big,
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
		.data = gCardPicLarge_DunamesDarkWitch_Big,
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
		.data = gCardPicLarge_EarthEffigy_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EarthboundSpirit_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EffectVeiler_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EhthertheHeavenlyMonarch_Big,
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
		.data = gCardPicLarge_ElShaddollAnoyatyllis_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollApkallone_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollConstruct_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollGrysta_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollShekhinaga_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollWendigo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElShaddollWinda_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElderEntityNorden_Big,
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
		.data = gCardPicLarge_ElementalHEROBlazeman_Big,
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
		.data = gCardPicLarge_ElementalHEROPrisma_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElementalHEROStratos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElementalHEROWildheart_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ElementalHEROWoodsman_Big,
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
		.data = gCardPicLarge_EmiliaDancePriestessoftheNekroz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EmissaryoftheAfterlife_Big,
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
		.data = gCardPicLarge_EnvoyofChaos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EradicatorEpidemicVirus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ErebustheUnderworldMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EscapefromtheDarkDimension_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EveningTwilightKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EvenlyMatched_Big,
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
		.data = gCardPicLarge_EvilswarmKetos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_EvolzarLaggia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ExaEnforceroftheNekroz_Big,
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
		.data = gCardPicLarge_ExtRyzeal_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FabledLurrie_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FairyTailSnow_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FairyWind_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FakeTrap_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FallenofAlbaz_Big,
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
		.data = gCardPicLarge_FantasticalDragonPhantazmay_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FarfaMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FatefulAdventure_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiberJar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiendGriefing_Big,
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
		.data = gCardPicLarge_FiendsmithEngraver_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiendsmithsLacrima_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiendsmithsRequiem_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiendsmithsSequence_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FiendsmithsTract_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FightingFlameSwordsman_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FinalFlame_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FireFormationTenki_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FireHand_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FireKingHighAvatarKirin_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FireLakeoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FirewallDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Fissure_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FlameBufferlo_Big,
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
		.data = gCardPicLarge_FlamvellGuard_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FlipFlopFrog_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FloodgateTrapHole_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FlyingC_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FlyingKamakiri1_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FoolishBurial_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ForbiddenApocrypha_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ForbiddenChalice_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ForbiddenDroplet_Big,
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
		.data = gCardPicLarge_FrontierWiseman_Big,
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
		.data = gCardPicLarge_FusionDestiny_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FusionDevourer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_FusionSubstitute_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GagagaCowboy_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Gagagigo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GaiaKnighttheForceofEarth_Big,
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
		.data = gCardPicLarge_GaiaTheFierceKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GalateatheOrcustAutomaton_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GalaxyCyclone_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GamecieltheSeaTurtleKaiju_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GarothLightswornWarrior_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GaruraWingsofResonantLife_Big,
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
		.data = gCardPicLarge_GearfriedtheRedEyesIronKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemArmadillo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemElephant_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightAlexandrite_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightEmerald_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightGarnet_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightHollowcore_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightLadyRoseDiamond_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightNepyrim_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightPrismaura_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightQuartz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightRuby_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightSapphire_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightTourmaline_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemKnightZirconia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GemTurtle_Big,
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
		.data = gCardPicLarge_GeneWarpedWarwolf_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GentaGatemanofDarkWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GhostBelleHauntedMansion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GhostMournerMoonlitChill_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GhostOgreSnowRabbit_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GhostReaperWinterCherries_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GhostSisterSpookyDogwood_Big,
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
		.data = gCardPicLarge_GiganticSpright_Big,
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
		.data = gCardPicLarge_GiltiatheDKnightSoulSpear_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiAriel_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiAvance_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiBeast_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiChain_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiEmilia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiGrimness_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiMarker_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiNatalia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiNoellia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiShadow_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiVanity_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GishkiVision_Big,
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
		.data = gCardPicLarge_GoblinPotholeSquad_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GoblinZombie_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Gokipon_Big,
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
		.data = gCardPicLarge_GracefulCharity_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GraffMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GranguignoltheDuskDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GranmargtheMegaMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GranmargtheRockMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GraphaDragonLordofDarkWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GraphaDragonOverlordofDarkWorld_Big,
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
		.data = gCardPicLarge_GuardianSphinx_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GuardragonGarmides_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GuidingAriadne_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_GunkanSushipShari_Big,
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
		.data = gCardPicLarge_HandofNephthys_Big,
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
		.data = gCardPicLarge_HeartoftheBlueEyes_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_HeavyStorm_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_HeavyStormDuster_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_HeraldofOrangeLight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_HeraldoftheArcLight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Hieracosphinx_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_HiitatheFireCharmerAblaze_Big,
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
		.data = gCardPicLarge_IPMasquerena_Big,
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
		.data = gCardPicLarge_IceKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IceRyzeal_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IgnisterProminencetheBlastingDracoslayer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IllusionofChaos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IllusorySnatcher_Big,
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
		.data = gCardPicLarge_InabaWhiteRabbit_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IncredibleEcclesiatheVirtuous_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IndomitableFighterLeiLei_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfernalqueenSalmon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfernityArchfiend_Big,
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
		.data = gCardPicLarge_InfernityNecromancer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfernoidDecatron_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfernoidHarmadik_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfernoidPatrulea_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InfiniteImpermanence_Big,
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
		.data = gCardPicLarge_InstantFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_InterruptedKaijuSlumber_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IslandTurtle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_IsoldeTwoTalesoftheNobleKnights_Big,
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
		.data = gCardPicLarge_JiohtheGravityNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_JiraiGumo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_JongleurGhoulIllusionist_Big,
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
		.data = gCardPicLarge_KashtiraBirth_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KashtiraFenrir_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KashtiraRiseheart_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KashtiraUnicorn_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Kashtiratheosis_Big,
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
		.data = gCardPicLarge_KelbektheAncientVanguard_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KeldotheSacredProtector_Big,
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
		.data = gCardPicLarge_KnightmareCerberus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KnightmareGoblin_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KnightmarePhoenix_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KnightmareUnicorn_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KozmoDarkDestroyer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KozmoFarmgirl_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KozmoSliprider_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KozmoTincan_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Kozmojo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KozmollWickedwitch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Kozmotown_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Krebons_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KumongoustheStickyStringKaiju_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Kuriboh_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_KurikaraDivincarnate_Big,
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
		.data = gCardPicLarge_LabrynthArchfiend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LabyrinthTank_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LacrimatheCrimsonTears_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LadyNinjaYae_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LancerArchfiend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LastWill_Big,
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
		.data = gCardPicLarge_LegendarySixSamuraiKizan_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Leotron_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LesserFiend_Big,
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
		.data = gCardPicLarge_LeviairtheSeaDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LibicMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LightandDarknessDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LightofIntervention_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LightImprisoningMirror_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LightningStorm_Big,
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
		.data = gCardPicLarge_LimiterRemoval_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LinkSpider_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Linkuriboh_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LonefireBlossom_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LordofD_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LubelliontheSearingDragon_Big,
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
		.data = gCardPicLarge_LullabyofObedience_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LuminaLightswornSummoner_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LunalightBlackSheep_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LusterDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LusterPendulumtheDracoslayer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_LylaLightswornSorceress_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MXSaberInvoker_Big,
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
		.data = gCardPicLarge_MadArchfiend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MadDogofDarkness_Big,
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
		.data = gCardPicLarge_MagicDeflector_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MagicJammer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MagicalAbductor_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MagicalAndroid_Big,
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
		.data = gCardPicLarge_MagicianofDarkIllusion_Big,
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
		.data = gCardPicLarge_MagiciansValkyria_Big,
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
		.data = gCardPicLarge_MaidenoftheAqua_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaidenofWhite_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaidenwithEyesofBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MajespecterRaccoonBunbuku_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MajespecterUnicornKirin_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MajesterPaladintheAscendingDracoslayer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MajestysFiend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MakyuratheDestructor_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaleficBlueEyesWhiteDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaleficCyberEndDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaleficRedEyesBlackDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MalevolentCatastrophe_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MalissinUnderground_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MalissPDormouse_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MalissPWhiteRabbit_Big,
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
		.data = gCardPicLarge_MaskedNinjaEbisu_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MaskedSorcerer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterHyperion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterofChaos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterofOz_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterPeacetheTrueDracoslayingKing_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterPendulumtheDracoslayer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MasterwithEyesofBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MatazatheZapper_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Mathematician_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MatriarchofNephthys_Big,
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
		.data = gCardPicLarge_Mechanicalchaser_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MegalosmasherX_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Megamorph_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MeizentheBattleNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MekkKnightAvram_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MereologicAggregator_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MermaidKnight_Big,
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
		.data = gCardPicLarge_MetalReflectSlime_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MetalflameSwordsman_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MetalfoesGoldriver_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MetalfoesSilverd_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MetalfoesSteelen_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MetalfoesVolflame_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Metaltronus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Metamorphosis_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MeteorBlackCometDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MeteorDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Mezuki_Big,
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
		.data = gCardPicLarge_MindCrush_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MindProtector_Big,
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
		.data = gCardPicLarge_MirageKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MirageofNightmare_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MirageSwordsman_Big,
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
		.data = gCardPicLarge_MissusRadiant_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MistWurm_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Mistake_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MitsutheInsectNinja_Big,
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
		.data = gCardPicLarge_MobiustheMegaMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MonkoftheTenyi_Big,
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
		.data = gCardPicLarge_MoonoftheClosedHeaven_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MorphingJar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MorphingJar2_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MotherGrizzly_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MudoratheSwordOracle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MudragonoftheSwamp_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MukaMuka_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MulcharmyFuwalos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MulcharmyMeowls_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MulcharmyPurulia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MyBodyasaShield_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MysteryShellDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_MysticMine_Big,
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
		.data = gCardPicLarge_MysticalElfWhiteLightning_Big,
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
		.data = gCardPicLarge_NaelshaddollAriel_Big,
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
		.data = gCardPicLarge_NekrozCycle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozKaleidoscope_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozMirror_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozofBrionac_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozofClausolas_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozofUnicore_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NekrozofValkyrus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NeoBug_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NeoKaiserSeaHorse_Big,
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
		.data = gCardPicLarge_Newdoria_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NibiruthePrimalBeing_Big,
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
		.data = gCardPicLarge_NightmareMagician_Big,
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
		.data = gCardPicLarge_NimbleAngler_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_NimbleBeaver_Big,
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
		.data = gCardPicLarge_Number101SilentHonorARK_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Number11BigEye_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Number17LeviathanDragon_Big,
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
		.data = gCardPicLarge_Number41BagooskatheTerriblyTiredTapir_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Number66MasterKeyBeetle_Big,
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
		.data = gCardPicLarge_OrcustCymbalSkeleton_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_OrcustHarpHorror_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_OrcustKnightmare_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_OrcustratedReturn_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_OriginalSinfulSpoilsSnakeEye_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_OverloadFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PainfulChoice_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PainfulDecision_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaladinofWhiteDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicAnomalocaris_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicCanadia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicDinomischus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicMarrella_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicOlenoides_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PaleozoicOpabinia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PalladiumOracleMahad_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PantheismoftheMonarchs_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ParlHermitofDarkWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PenguinKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PenguinNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformageDamageJuggler_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformageHatTricker_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformageMirrorConductor_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformagePlushfire_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformageTrapezeMagician_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformageTrickClown_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalGuitartle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalLizardraw_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalMonkeyboard_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalPendulumSorcerer_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalSilverClaw_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PerformapalSkullcrobatJoker_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PhantomGryphon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PhantomKnightsFogBlade_Big,
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
		.data = gCardPicLarge_PlaguespreaderZombie_Big,
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
		.data = gCardPicLarge_PotofDesires_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PotofDuality_Big,
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
		.data = gCardPicLarge_PotofProsperity_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsDodoDoodleDoo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsDropsies_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsFansies_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsLampsies_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsPlace_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrankKidsRocksies_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PredaplantDragostapelia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PredaplantVerteAnaconda_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrematureBurial_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PressuredPlanetWraitsoth_Big,
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
		.data = gCardPicLarge_PriestesswithEyesofBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrimalDragonthePrimordial_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PrimevalPlanetPerlereino_Big,
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
		.data = gCardPicLarge_PrometheanPrincessBestowerofFlames_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ProtectoroftheSanctuary_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ProtectorwithEyesofBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PsiBlocker_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PSYFrameDriver_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_PSYFramegearGamma_Big,
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
		.data = gCardPicLarge_QadshaddollKeios_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_QliphortCarrier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_QliphortDisk_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_QliphortHelix_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_QliphortScout_Big,
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
		.data = gCardPicLarge_RaizatheMegaMonarch_Big,
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
		.data = gCardPicLarge_RedDragonNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedReboot_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesAlternativeBlackDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBabyDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBlackDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBlackDragonSword_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBlackFullmetalDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBlackMetalDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesBlackMeteorDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesDarknessMetalDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesRetroDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesSlashDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesSoul_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesToonDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesWyvern_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedEyesZombieDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RedoxDragonRulerofBoulders_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ReeshaddollWendi_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ReflectBounder_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ReignBeauxOverkingofDarkWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ReignBeauxOverlordofDarkWorld_Big,
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
		.data = gCardPicLarge_Relinkuriboh_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Relinquished_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RelinquishedAnima_Big,
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
		.data = gCardPicLarge_RengeGatekeeperofDarkWorld_Big,
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
		.data = gCardPicLarge_RetaliatingC_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ReturnfromtheDifferentDimension_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RideroftheStormWinds_Big,
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
		.data = gCardPicLarge_RiteofAramesir_Big,
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
		.data = gCardPicLarge_RubicMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RunickDestruction_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RunickFlashingFire_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RunickFreezingCurses_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RunickTip_Big,
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
		.data = gCardPicLarge_RyzealCross_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RyzealDetonator_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_RyzealDuoDrive_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SPLittleKnight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SaberBeetle_Big,
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
		.data = gCardPicLarge_SacredPhoenixofNephthys_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SacredSwordofSevenStars_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SagewithEyesofBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SakuretsuArmor_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamandratheFlyingFlameDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamangreatBalelynx_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamangreatFoxy_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamangreatRagingPhoenix_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamangreatSpinny_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SalamangreatSunlightWolf_Big,
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
		.data = gCardPicLarge_SangenKaimen_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SangenSummoning_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Saqlifice_Big,
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
		.data = gCardPicLarge_ScarmMalebrancheoftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ScarrScoutofDarkWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ScrapDragon_Big,
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
		.data = gCardPicLarge_ShaddollBeast_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollFalco_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollHedgehog_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollHound_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShaddollSquamata_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShadowImprisoningMirror_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SharedRide_Big,
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
		.data = gCardPicLarge_ShinyBlackC_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShinyBlackCSquadder_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Shrink_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShuffleReborn_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ShuritStrategistoftheNekroz_Big,
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
		.data = gCardPicLarge_SinisterShadowGames_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SixSamuraiUnited_Big,
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
		.data = gCardPicLarge_SkilledRedMagician_Big,
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
		.data = gCardPicLarge_SkyIris_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyScout_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerAceKagari_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerAceRaye_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerAceRoze_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerAceShizuku_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerManeuverAfterburners_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerMechaHornetDrones_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerMechaSharkCannon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerMechaWidowAnchor_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SkyStrikerMobilizeEngage_Big,
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
		.data = gCardPicLarge_SnakeEyeAsh_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SnakeEyeBirch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SnakeEyeOak_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SnakeEyesDiabellstar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SnakeEyesFlambergeDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SnakeEyesPoplar_Big,
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
		.data = gCardPicLarge_SolemnStrike_Big,
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
		.data = gCardPicLarge_SoulExchange_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SoulTaker_Big,
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
		.data = gCardPicLarge_SpeedroidTaketomborg_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SpeedroidTerrortop_Big,
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
		.data = gCardPicLarge_SpellShatteringArrow_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SpellbookMagicianofProphecy_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SpellbookofJudgment_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SpellbookofSecrets_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SphereKuriboh_Big,
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
		.data = gCardPicLarge_SprightBlue_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightCarrot_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightElf_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightJet_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightRed_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightSmashers_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightSprind_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SprightStarter_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_StardustDragon_Big,
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
		.data = gCardPicLarge_SteelswarmRoach_Big,
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
		.data = gCardPicLarge_SummonersArt_Big,
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
		.data = gCardPicLarge_SuperSoldierSoul_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SuperStarslayerTYPHONSkyCrisis_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwapFrog_Big,
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
		.data = gCardPicLarge_SwiftScarecrow_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordRyzeal_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsofRevealingLight_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulBlackout_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulEmergence_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulGrandmasterChixiao_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulofMoYe_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulofTaia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SwordsoulStrategistLongyuan_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_SystemDown_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TADPOLE_Big,
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
		.data = gCardPicLarge_TearlamentsCryme_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsHavnis_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsHeartbeat_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsKaleidoHeart_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsKashtira_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsKitkallos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsMerrli_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsReinoheart_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsRulkallos_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsScheiren_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsScream_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TearlamentsSulliek_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TellarknightPtolemaeus_Big,
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
		.data = gCardPicLarge_TenacityoftheMonarchs_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Tenmataitei_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TenpaiDragonChundra_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TenpaiDragonFadra_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TenyiSpiritAdhara_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TenyiSpiritAshuna_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TenyiSpiritVishuda_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Terraforming_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TerrorkingSalmon_Big,
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
		.data = gCardPicLarge_ThatGrassLooksGreener_Big,
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
		.data = gCardPicLarge_TheBigMarchofAnimals_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheBlackStoneofLegend_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheBystialAluber_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheBystialLubellion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheDarkHexSealedFusion_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheDarkMagicians_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheDragonDwellingintheCave_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheEarthHexSealedFusion_Big,
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
		.data = gCardPicLarge_TheGoldenSwordsoul_Big,
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
		.data = gCardPicLarge_TheMonarchsStormforth_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThePhantomKnightsofAncientCloak_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThePhantomKnightsofBreakSword_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThePhantomKnightsofSilentBoots_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThePrimeMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheTricky_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TheWhiteStoneofAncients_Big,
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
		.data = gCardPicLarge_TheWingedDragonofRaSphereMode_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThereCanBeOnlyOne_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThestalostheFirestormMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThestalostheMegaMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThestalostheShadowfireMonarch_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThoughtRulerArchfiend_Big,
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
		.data = gCardPicLarge_ThunderDragonColossus_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThunderDragonTitan_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThunderDragondark_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThunderDragonduo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThunderDragonhawk_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ThunderDragonlord_Big,
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
		.data = gCardPicLarge_ThunderSeaHorse_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TidalDragonRulerofWaterfalls_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TimaeustheUnitedDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TimeSeal_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TimeSpaceTrapHole_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TitanikladtheAshDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TlakalelHisMalevolentMajesty_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ToadallyAwesome_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TobaritheSkyNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TokenCollector_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ToonCannonSoldier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ToonCyberDragon_Big,
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
		.data = gCardPicLarge_ToonSummonedSkull_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ToonTableofContents_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TornadoDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TorrentialTribute_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TotemBird_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TourGuideFromtheUnderworld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Tradetoad_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Tragoedia_Big,
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
		.data = gCardPicLarge_TraptrixRafflesia_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TraptrixTrapHoleNightmare_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TraptrixVesiculo_Big,
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
		.data = gCardPicLarge_TriBrigadeFraktall_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TriBrigadeKitt_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TriBrigadeNervall_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TriBrigadeRevolt_Big,
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
		.data = gCardPicLarge_TrickstarCandina_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrickstarLightStage_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrickstarLycoris_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrickstarReincarnation_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TripleTacticsTalent_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TripleTacticsThrust_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrishulaDragonoftheIceBarrier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrueDracoHeritage_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TrueKingsReturn_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Tsukuyomi_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_TwilightNinjaGetsugatheShogun_Big,
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
		.data = gCardPicLarge_TwinTwisters_Big,
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
		.data = gCardPicLarge_Typhoon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_UFOTurtle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_UltimateFlameSwordsman_Big,
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
		.data = gCardPicLarge_UltimateSlayer_Big,
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
		.data = gCardPicLarge_UpstartGoldenNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VampireLord_Big,
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
		.data = gCardPicLarge_VectorPendulumtheDracoverlord_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VesselfortheDragonCycle_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VirgilRockStaroftheBurningAbyss_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VisionHEROVyon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VoidFeast_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VoidVanishment_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_VolcanicScattershot_Big,
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
		.data = gCardPicLarge_WanderingGryphonRider_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WANTEDSeekerofSinfulSpoils_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WaterEnchantressoftheTemple_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WaveMotionCannon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WaveringEyes_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteDragonNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteDragonRitual_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteDragonWyverburster_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteMagicalHat_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteNightDragon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WhiteNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WidespreadRuin_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WindUpFactory_Big,
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
		.data = gCardPicLarge_WitchoftheBlackForest_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Wroughtweiler_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_WulfLightswornBeast_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_XHeadCannon_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_XSaberAirbellum_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_XSaberUrbellum_Big,
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
		.data = gCardPicLarge_YellowDragonNinja_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_YellowNinja_Big,
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
		.data = gCardPicLarge_ZombieMaster_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZombieWorld_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_Zombino_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZombyratheDark_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacBarrage_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacBoarbow_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacBroadbull_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacChakanine_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacCombo_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacDrident_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacHammerkong_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacRamram_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacRatpier_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacThoroughblade_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacTigermortar_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZoodiacWhiptail_Big,
		.size = 80*80,
		.tag = TAG_CARD
	},
    {
		.data = gCardPicLarge_ZureKnightofDarkWorld_Big,
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

const struct SpriteTemplate sCardLeftSpriteTemplate =
{
    .tileTag = TAG_CARD,
    .paletteTag = TAG_CARD,
    .oam = &sCardLeftOamData,
    .anims = sCardLeftAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = NULL,
};

const struct SpriteSheet sSpriteSheet_Icons[] =
{
    {
        .data = gStarIcon,
        .size = 8*8/2,
        .tag = TAG_ICON
    },
    {},
};

const struct SpritePalette sIcon_SpritePalettes[] =
{
    {gStarIconPal,     TAG_ICON},
};

bool8 Menu_DoGfxSetup(void)
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
		LoadPalette(gStarIconPal, BG_PLTT_ID(9), 32);
		LoadPalette(gStandardMenuPalette, BG_PLTT_ID(10), 32);
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

void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

bool8 Menu_InitBgs(void)
{
	if (!battle)
	    ResetAllBgsCoordinates();
    sTilemapBuffers[0] = AllocZeroed(BG_SCREEN_SIZE);
    if (sTilemapBuffers[0] == NULL && !battle)
        return FALSE;
    sTilemapBuffers[1] = AllocZeroed(BG_SCREEN_SIZE);
    if (sTilemapBuffers[1] == NULL && !battle)
        return FALSE;
    
	if (!battle)
	{
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
	}
	else
	{
		SetBgTilemapBuffer(2, sTilemapBuffers[0]);
		SetBgTilemapBuffer(0, sTilemapBuffers[1]);
	}
    
    return TRUE;
}

bool8 Menu_LoadGraphics(void)
{
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    u8 cardType = gCardInfo[card].type;
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sBackgroundTiles, 0, 0, 0);
        if (cardType == TYPE_NORMAL_MONSTER || TYPE_NORMAL_TUNER_MONSTER)
            DecompressAndCopyTileDataToVram(1, sNormalMonsterTiles, 0, 0, 0);
        else if (cardType == TYPE_EFFECT_MONSTER || cardType == TYPE_FLIP_EFFECT_MONSTER || cardType == TYPE_SPIRIT_MONSTER || cardType == TYPE_UNION_EFFECT_MONSTER || cardType == TYPE_TOON_MONSTER || cardType == TYPE_FLIP_TUNER_EFFECT_MONSTER || cardType == TYPE_GEMINI_MONSTER)
            DecompressAndCopyTileDataToVram(1, sEffectMonsterTiles, 0, 0, 0);
		else if (cardType == TYPE_SYNCHRO_MONSTER || cardType == TYPE_SYNCHRO_TUNER_MONSTER)
            DecompressAndCopyTileDataToVram(1, sSynchroMonsterTiles, 0, 0, 0);
		else if (cardType == TYPE_LINK_MONSTER)
            DecompressAndCopyTileDataToVram(1, sLinkMonsterTiles, 0, 0, 0);
		else if (cardType == TYPE_XYZ_PENDULUM_EFFECT_MONSTER || cardType == TYPE_XYZ_MONSTER)
            DecompressAndCopyTileDataToVram(1, sXYZMonsterTiles, 0, 0, 0);
		else if (cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_RITUAL_MONSTER || cardType == TYPE_PENDULUM_FLIP_EFFECT_MONSTER || cardType == TYPE_PENDULUM_NORMAL_MONSTER || cardType == TYPE_PENDULUM_TUNER_EFFECT_MONSTER || cardType == TYPE_SYNCHRO_PENDULUM_EFFECT_MONSTER)
            DecompressAndCopyTileDataToVram(1, sPendulumMonsterTiles, 0, 0, 0);
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
			else if (cardType == TYPE_SYNCHRO_MONSTER || cardType == TYPE_SYNCHRO_TUNER_MONSTER)
				LZDecompressWram(sSynchroMonsterTilemap, sTilemapBuffers[0]);
			else if (cardType == TYPE_LINK_MONSTER)
				LZDecompressWram(sLinkMonsterTilemap, sTilemapBuffers[0]);
			else if (cardType == TYPE_XYZ_PENDULUM_EFFECT_MONSTER || cardType == TYPE_XYZ_MONSTER)
				LZDecompressWram(sXYZMonsterTilemap, sTilemapBuffers[0]);
			else if (cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_RITUAL_MONSTER || cardType == TYPE_PENDULUM_FLIP_EFFECT_MONSTER || cardType == TYPE_PENDULUM_NORMAL_MONSTER || cardType == TYPE_PENDULUM_TUNER_EFFECT_MONSTER || cardType == TYPE_SYNCHRO_PENDULUM_EFFECT_MONSTER)
				LZDecompressWram(sPendulumMonsterTilemap, sTilemapBuffers[0]);
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
    [COLORID_POCKET_NAME] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_GRAY_CURSOR] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_GREEN},
    [COLORID_UNUSED]      = {TEXT_COLOR_DARK_GRAY,   TEXT_COLOR_WHITE,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_TMHM_INFO]   = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5,  TEXT_DYNAMIC_COLOR_1}
};

void PrintSmallNarrowTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string)
{
    left = (left * 4) - (GetStringWidth(FONT_SMALL_NARROW, string, -1) / 2u);
    AddTextPrinterParameterized3(windowId, FONT_SMALL_NARROW, left, 0, sFontColorTableUI[colorId], 0, string);
}

void PrintToWindow(u8 windowId, u8 colorIdx, u16 card)
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
        AddTextPrinterParameterized4(WINDOW_5, FONT_SMALL_NARROWER, 2, 5, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);
        ConvertIntToDecimalStringN(gStringVar1, cardDef, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_xDef);
        AddTextPrinterParameterized4(WINDOW_6, FONT_SMALL_NARROWER, 0, 5, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);
    }
    if (cardType == TYPE_NORMAL_MONSTER)
        LoadPalette(sNormalMonsterPalette, 0, 32*3);
	else if (cardType == TYPE_SYNCHRO_MONSTER || cardType == TYPE_SYNCHRO_TUNER_MONSTER)
		LoadPalette(sNormalMonsterPalette, 0, 32*3);
	else if (cardType == TYPE_LINK_MONSTER)
		LoadPalette(sNormalMonsterPalette, 0, 32*3);
	else if (cardType == TYPE_XYZ_PENDULUM_EFFECT_MONSTER || cardType == TYPE_XYZ_MONSTER)
		LoadPalette(sNormalMonsterPalette, 0, 32*3);
	else if (cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_FUSION_MONSTER || cardType == TYPE_PENDULUM_EFFECT_RITUAL_MONSTER || cardType == TYPE_PENDULUM_FLIP_EFFECT_MONSTER || cardType == TYPE_PENDULUM_NORMAL_MONSTER || cardType == TYPE_PENDULUM_TUNER_EFFECT_MONSTER || cardType == TYPE_SYNCHRO_PENDULUM_EFFECT_MONSTER)
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

void Task_MenuWaitFadeIn(u8 taskId)
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

void DrawScrolledText(u8 windowId, const u8 *fullText, u32 startIndex, u8 linesToDraw)
{
    u8 buffer[512];
    u32 i = startIndex;
    u32 bufIndex = 0;
    u8 lines = 0;

    while (fullText[i] != EOS && lines < linesToDraw)
    {
        if (fullText[i] == CHAR_NEWLINE)
            lines++;

        buffer[bufIndex++] = fullText[i++];
    }

    buffer[bufIndex] = EOS;

    // Draw to window
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);
    AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, 0, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, buffer);
    CopyWindowToVram(windowId, 3);
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

void Task_MenuMain(u8 taskId)
{
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    const u8 *cardDescription = gCardInfo[card].description;
    u8 totalLines = CountNumLines(cardDescription);
    u32 startIdx;

    if (!sDidInitialDraw)
    {
        sScrollDown = 0;
        startIdx = GetLineStartIndex(cardDescription, sScrollDown);
        DrawScrolledText(WINDOW_1, cardDescription, startIdx, NUM_VISIBLE_LINES);
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
        DrawScrolledText(WINDOW_1, cardDescription, startIdx, NUM_VISIBLE_LINES);
    }

    if (JOY_NEW(DPAD_UP) && sScrollDown > 0)
    {
        sScrollDown--;
        startIdx = GetLineStartIndex(cardDescription, sScrollDown);
        DrawScrolledText(WINDOW_1, cardDescription, startIdx, NUM_VISIBLE_LINES);
    }
}





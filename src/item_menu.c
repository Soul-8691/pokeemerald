#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_pyramid.h"
#include "frontier_util.h"
#include "battle_pyramid_bag.h"
#include "berry_tag_screen.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu_icons.h"
#include "item_use.h"
#include "lilycove_lady.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "ygo.h"
#include "ygo_graphics.h"
#include "constants/ygo.h"

#define TAG_POCKET_SCROLL_ARROW 110
#define TAG_BAG_SCROLL_ARROW    111

// The buffer for the bag item list needs to be large enough to hold the maximum
// number of item slots that could fit in a single pocket, + 1 for Cancel.
// This constant picks the max of the existing pocket sizes.
// By default, the largest pocket is BAG_TMHM_COUNT at 64.
#define MAX_POCKET_ITEMS  ((max(BAG_TMHM_COUNT,              \
                            max(BAG_BERRIES_COUNT,           \
                            max(BAG_ITEMS_COUNT,             \
                            max(BAG_KEYITEMS_COUNT,          \
                            max(BAG_TRUNK_COUNT,             \
                            max(BAG_MAIN_DECK_COUNT,         \
                            max(BAG_EXTRA_DECK_COUNT,        \
                            max(BAG_SIDE_DECK_COUNT,         \
                                BAG_POKEBALLS_COUNT))))))))) + 1)

// Up to 8 item slots can be visible at a time
#define MAX_ITEMS_SHOWN 8

enum {
    SWITCH_POCKET_NONE,
    SWITCH_POCKET_LEFT,
    SWITCH_POCKET_RIGHT
};

enum {
    ACTION_USE,
    ACTION_TOSS,
    ACTION_REGISTER,
    ACTION_GIVE,
    ACTION_CANCEL,
    ACTION_BATTLE_USE,
    ACTION_CHECK,
    ACTION_WALK,
    ACTION_DESELECT,
    ACTION_CHECK_TAG,
    ACTION_CONFIRM,
    ACTION_SHOW,
    ACTION_GIVE_FAVOR_LADY,
    ACTION_CONFIRM_QUIZ_LADY,
    ACTION_BY_NAME,
    ACTION_BY_TYPE,
    ACTION_BY_AMOUNT,
    ACTION_BY_ID,
    ACTION_BY_LEVEL,
    ACTION_BY_ATK,
    ACTION_BY_DEF,
    ACTION_BY_PRICE_YK,
    ACTION_BY_PRICE_CRITTER,
    ACTION_BY_PRICE_TREASURE,
    ACTION_BY_PRICE_IMPERIAL,
    ACTION_BY_PRICE_ANDROID,
    ACTION_BY_PRICE_JP,
    ACTION_BY_PRICE_FIBER,
    ACTION_BY_PRICE_YATA,
    ACTION_BY_PRICE_SCIENTIST,
    ACTION_BY_PRICE_VAMPIRE,
    ACTION_BY_PRICE_CHAOS,
    ACTION_BY_PRICE_WARRIOR,
    ACTION_BY_PRICE_GOAT,
    ACTION_BY_PRICE_CYBER,
    ACTION_BY_PRICE_REAPER,
    ACTION_BY_PRICE_VENDOR_1,
    ACTION_BY_PRICE_VENDOR_2,
    ACTION_BY_PRICE_VENDOR_3,
    ACTION_DESCRIPTION,
    ACTION_DUMMY,
};

enum {
    WIN_ITEM_LIST,
    WIN_DESCRIPTION,
    WIN_POCKET_NAME,
    WIN_UPPER,
    WIN_UPPER_2,
    WIN_TMHM_INFO_ICONS,
    WIN_TMHM_INFO,
};

// Item list ID for toSwapPos to indicate an item is not currently being swapped
#define NOT_SWAPPING 0xFF

struct ListBuffer1 {
    struct ListMenuItem subBuffers[MAX_POCKET_ITEMS];
};

struct ListBuffer2 {
    u8 name[MAX_POCKET_ITEMS][ITEM_NAME_LENGTH + 10];
};

struct TempWallyBag {
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u16 unused;
    u16 pocket;
};

static void CB2_Bag(void);
static bool8 SetupBagMenu(void);
static void BagMenu_InitBGs(void);
static bool8 LoadBagMenu_Graphics(void);
static void LoadBagMenuTextWindows(void);
static void AllocateBagItemListBuffers(void);
static void LoadBagItemListBuffers(u8);
static void PrintPocketNames(const u8 *, const u8 *);
static void CopyPocketNameToWindow(u32);
static void DrawPocketIndicatorSquare(u8, bool8);
static void CreatePocketScrollArrowPair(void);
static void CreatePocketSwitchArrowPair(void);
static void DestroyPocketSwitchArrowPair(void);
static void PrepareTMHMMoveWindow(void);
static bool8 IsWallysBag(void);
static void Task_WallyTutorialBagMenu(u8);
static void Task_BagMenu_HandleInput(u8);
static void GetItemNameFromPocket(u8 *, u16);
static void PrintItemDescription(int);
static void BagMenu_PrintCursorAtPos(u8, u8);
static void BagMenu_Print(u8, u8, const u8 *, u8, u8, u8, u8, u8, u8);
static void Task_CloseBagMenu(u8);
static u8 AddItemMessageWindow(u8);
static void RemoveItemMessageWindow(u8);
static void ReturnToItemList(u8);
static void PrintItemQuantity(u8, s16);

static u8 BagMenu_AddWindow(u8);
static u8 GetSwitchBagPocketDirection(void);
static void SwitchBagPocket(u8, s16, bool16);
static bool8 CanSwapItems(void);
static void StartItemSwap(u8 taskId);
static void Task_SwitchBagPocket(u8);
static void Task_HandleSwappingItemsInput(u8);
static void DoItemSwap(u8);
static void CancelItemSwap(u8);
static void PrintTMHMMoveData(u16);
static void PrintContextMenuItems(u8);
static void PrintContextMenuItemGrid(u8, u8, u8);
static void Task_ItemContext_SingleRow(u8);
static void Task_ItemContext_MultipleRows(u8);
static bool8 IsValidContextMenuPos(s8);
static void BagMenu_RemoveWindow(u8);
static void PrintThereIsNoPokemon(u8);
static void Task_ChooseHowManyToToss(u8);
static void AskTossItems(u8);
static void Task_RemoveItemFromBag(u8);
static void ItemMenu_Cancel(u8);
static void HandleErrorMessage(u8);
static void PrintItemCantBeHeld(u8);
static void DisplayCurrentMoneyWindow(void);
static void DisplaySellItemPriceAndConfirm(u8);
static void InitSellHowManyInput(u8);
static void AskSellItems(u8);
static void RemoveMoneyWindow(void);
static void Task_ChooseHowManyToSell(u8);
static void SellItem(u8);
static void WaitAfterItemSell(u8);
static void TryDepositItem(u8);
static void Task_ChooseHowManyToDeposit(u8 taskId);

// .rodata
static void WaitDepositErrorMessage(u8);
static void CB2_ApprenticeExitBagMenu(void);
static void CB2_FavorLadyExitBagMenu(void);
static void CB2_QuizLadyExitBagMenu(void);
static void UpdatePocketItemLists(void);
static void InitPocketListPositions(void);
static void InitPocketScrollPositions(void);
static u8 CreateBagInputHandlerTask(u8);
static void DrawItemListBgRow(u8);
static void BagMenu_MoveCursorCallback(s32, bool8, struct ListMenu *);
static void BagMenu_ItemPrintCallback(u8, u32, u8);
static void ItemMenu_UseOutOfBattle(u8);
static void ItemMenu_Toss(u8);
static void ItemMenu_Register(u8);
static void ItemMenu_Give(u8);
static void ItemMenu_Cancel(u8);
static void ItemMenu_UseInBattle(u8);
static void ItemMenu_CheckTag(u8);
static void ItemMenu_Show(u8);
static void ItemMenu_GiveFavorLady(u8);
static void ItemMenu_ConfirmQuizLady(u8);
static void Task_ItemContext_Normal(u8);
static void Task_ItemContext_GiveToParty(u8);
static void Task_ItemContext_Sell(u8);
static void Task_ItemContext_Deposit(u8);
static void Task_ItemContext_GiveToPC(u8);
static void ConfirmToss(u8);
static void CancelToss(u8);
static void ConfirmSell(u8);
static void CancelSell(u8);

//bag sort
static void Task_LoadBagSortOptions(u8 taskId);
static void ItemMenu_SortByName(u8 taskId);
static void ItemMenu_SortByType(u8 taskId);
static void ItemMenu_SortByAmount(u8 taskId);
static void ItemMenu_SortById(u8 taskId);
static void ItemMenu_SortByLevel(u8 taskId);
static void ItemMenu_SortByAtk(u8 taskId);
static void ItemMenu_SortByDef(u8 taskId);
static void ItemMenu_SortByPriceYK(u8 taskId);
static void ItemMenu_SortByPriceCritter(u8 taskId);
static void ItemMenu_SortByPriceTreasure(u8 taskId);
static void ItemMenu_SortByPriceImperial(u8 taskId);
static void ItemMenu_SortByPriceAndroid(u8 taskId);
static void ItemMenu_SortByPriceJP(u8 taskId);
static void ItemMenu_SortByPriceFiber(u8 taskId);
static void ItemMenu_SortByPriceYata(u8 taskId);
static void ItemMenu_SortByPriceScientist(u8 taskId);
static void ItemMenu_SortByPriceVampire(u8 taskId);
static void ItemMenu_SortByPriceChaos(u8 taskId);
static void ItemMenu_SortByPriceWarrior(u8 taskId);
static void ItemMenu_SortByPriceGoat(u8 taskId);
static void ItemMenu_SortByPriceCyber(u8 taskId);
static void ItemMenu_SortByPriceReaper(u8 taskId);
static void ItemMenu_SortByPriceVendor1(u8 taskId);
static void ItemMenu_SortByPriceVendor2(u8 taskId);
static void ItemMenu_SortByPriceVendor3(u8 taskId);
static void SortBagItems(u8 taskId);
static void Task_SortFinish(u8 taskId);
static void SortItemsInBag(u8 pocket, u8 type);
static void MergeSort(struct ItemSlot* array, u32 low, u32 high, s8 (*comparator)(struct ItemSlot*, struct ItemSlot*));
static void Merge(struct ItemSlot* array, u32 low, u32 mid, u32 high, s8 (*comparator)(struct ItemSlot*, struct ItemSlot*));
static s8 CompareItemsAlphabetically(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByMost(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByType(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsById(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByLevel(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByAtk(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByDef(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceYK(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceCritter(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceTreasure(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceImperial(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceAndroid(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceJP(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceFiber(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceYata(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceScientist(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceVampire(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceChaos(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceWarrior(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceGoat(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceCyber(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceReaper(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceVendor1(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceVendor2(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);
static s8 CompareItemsByPriceVendor3(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2);

static const struct BgTemplate sBgTemplates_ItemMenu[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = BagMenu_MoveCursorCallback,
    .itemPrintFunc = BagMenu_ItemPrintCallback,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = WIN_ITEM_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const u8 sMenuText_ByName[] = _("Name");
static const u8 sMenuText_ByType[] = _("Type");
static const u8 sMenuText_ByAmount[] = _("Amount");
static const u8 sMenuText_ById[] = _("ID");
static const u8 sMenuText_ByNumber[] = _("Number");
static const u8 sMenuText_ByLevel[] = _("Level");
static const u8 sMenuText_ByAtk[] = _("ATK");
static const u8 sMenuText_ByDef[] = _("DEF");
static const u8 sMenuText_ByPriceYK[] = _("Yugi-Kaiba");
static const u8 sMenuText_ByPriceCritter[] = _("Critter");
static const u8 sMenuText_ByPriceTreasure[] = _("Treasure");
static const u8 sMenuText_ByPriceImperial[] = _("Imperial");
static const u8 sMenuText_ByPriceAndroid[] = _("Android");
static const u8 sMenuText_ByPriceJP[] = _("Joey-Pegasus");
static const u8 sMenuText_ByPriceFiber[] = _("Fiber");
static const u8 sMenuText_ByPriceYata[] = _("Yata");
static const u8 sMenuText_ByPriceScientist[] = _("Scientist");
static const u8 sMenuText_ByPriceVampire[] = _("Vampire");
static const u8 sMenuText_ByPriceChaos[] = _("Chaos");
static const u8 sMenuText_ByPriceWarrior[] = _("Warrior");
static const u8 sMenuText_ByPriceGoat[] = _("Goat");
static const u8 sMenuText_ByPriceCyber[] = _("Cyber");
static const u8 sMenuText_ByPriceReaper[] = _("Reaper");
static const u8 sMenuText_ByPriceVendor1[] = _("Vendor 1");
static const u8 sMenuText_ByPriceVendor2[] = _("Vendor 2");
static const u8 sMenuText_ByPriceVendor3[] = _("Vendor 3");
static const u8 sMenuText_Description[] = _("Description");
static const u8 sText_NothingToSort[] = _("There's nothing to sort!");
static const struct MenuAction sItemMenuActions[] = {
    [ACTION_USE]               = {gMenuText_Use,      ItemMenu_UseOutOfBattle},
    [ACTION_TOSS]              = {gMenuText_Toss,     ItemMenu_Toss},
    [ACTION_REGISTER]          = {gMenuText_Register, ItemMenu_Register},
    [ACTION_GIVE]              = {gMenuText_Give,     ItemMenu_Give},
    [ACTION_CANCEL]            = {gText_Cancel2,      ItemMenu_Cancel},
    [ACTION_BATTLE_USE]        = {gMenuText_Use,      ItemMenu_UseInBattle},
    [ACTION_CHECK]             = {gMenuText_Check,    ItemMenu_UseOutOfBattle},
    [ACTION_WALK]              = {gMenuText_Walk,     ItemMenu_UseOutOfBattle},
    [ACTION_DESELECT]          = {gMenuText_Deselect, ItemMenu_Register},
    [ACTION_CHECK_TAG]         = {gMenuText_CheckTag, ItemMenu_CheckTag},
    [ACTION_CONFIRM]           = {gMenuText_Confirm,  Task_FadeAndCloseBagMenu},
    [ACTION_SHOW]              = {gMenuText_Show,     ItemMenu_Show},
    [ACTION_GIVE_FAVOR_LADY]   = {gMenuText_Give2,    ItemMenu_GiveFavorLady},
    [ACTION_CONFIRM_QUIZ_LADY] = {gMenuText_Confirm,  ItemMenu_ConfirmQuizLady},
    [ACTION_BY_NAME]           = {sMenuText_ByName,   ItemMenu_SortByName},
    [ACTION_BY_TYPE]           = {sMenuText_ByType,   ItemMenu_SortByType},
    [ACTION_BY_AMOUNT]         = {sMenuText_ByAmount, ItemMenu_SortByAmount},
    [ACTION_BY_ID]             = {sMenuText_ById,     ItemMenu_SortById},
    [ACTION_BY_LEVEL]          = {sMenuText_ByLevel,     ItemMenu_SortByLevel},
    [ACTION_BY_ATK]            = {sMenuText_ByAtk,     ItemMenu_SortByAtk},
    [ACTION_BY_DEF]            = {sMenuText_ByDef,     ItemMenu_SortByDef},
    [ACTION_BY_PRICE_YK]       = {sMenuText_ByPriceYK, ItemMenu_SortByPriceYK},
    [ACTION_BY_PRICE_CRITTER]  = {sMenuText_ByPriceCritter, ItemMenu_SortByPriceCritter},
    [ACTION_BY_PRICE_TREASURE]  = {sMenuText_ByPriceTreasure, ItemMenu_SortByPriceTreasure},
    [ACTION_BY_PRICE_IMPERIAL]  = {sMenuText_ByPriceImperial, ItemMenu_SortByPriceImperial},
    [ACTION_BY_PRICE_ANDROID]  = {sMenuText_ByPriceAndroid, ItemMenu_SortByPriceAndroid},
    [ACTION_BY_PRICE_JP]  = {sMenuText_ByPriceJP, ItemMenu_SortByPriceJP},
    [ACTION_BY_PRICE_FIBER]  = {sMenuText_ByPriceFiber, ItemMenu_SortByPriceFiber},
    [ACTION_BY_PRICE_YATA]  = {sMenuText_ByPriceYata, ItemMenu_SortByPriceYata},
    [ACTION_BY_PRICE_SCIENTIST]  = {sMenuText_ByPriceScientist, ItemMenu_SortByPriceScientist},
    [ACTION_BY_PRICE_VAMPIRE]  = {sMenuText_ByPriceVampire, ItemMenu_SortByPriceVampire},
    [ACTION_BY_PRICE_CHAOS]  = {sMenuText_ByPriceChaos, ItemMenu_SortByPriceChaos},
    [ACTION_BY_PRICE_WARRIOR]  = {sMenuText_ByPriceWarrior, ItemMenu_SortByPriceWarrior},
    [ACTION_BY_PRICE_GOAT]  = {sMenuText_ByPriceGoat, ItemMenu_SortByPriceGoat},
    [ACTION_BY_PRICE_CYBER]  = {sMenuText_ByPriceCyber, ItemMenu_SortByPriceCyber},
    [ACTION_BY_PRICE_REAPER]  = {sMenuText_ByPriceReaper, ItemMenu_SortByPriceReaper},
    [ACTION_BY_PRICE_VENDOR_1]  = {sMenuText_ByPriceVendor1, ItemMenu_SortByPriceVendor1},
    [ACTION_BY_PRICE_VENDOR_2]  = {sMenuText_ByPriceVendor2, ItemMenu_SortByPriceVendor2},
    [ACTION_BY_PRICE_VENDOR_3]  = {sMenuText_ByPriceVendor3, ItemMenu_SortByPriceVendor3},
    [ACTION_DESCRIPTION]       = {sMenuText_Description, ItemMenu_UseOutOfBattle},
    [ACTION_DUMMY]             = {gText_EmptyString2, NULL}
};

// these are all 2D arrays with a width of 2 but are represented as 1D arrays
// ACTION_DUMMY is used to represent blank spaces
static const u8 sContextMenuItems_ItemsPocket[] = {
    ACTION_USE,         ACTION_GIVE,
    ACTION_TOSS,        ACTION_CANCEL
};

static const u8 sContextMenuCards_ItemsPocket[] = {
    ACTION_DESCRIPTION, ACTION_CANCEL
};

static const u8 sContextMenuItems_KeyItemsPocket[] = {
    ACTION_USE,         ACTION_REGISTER,
    ACTION_DUMMY,       ACTION_CANCEL
};

static const u8 sContextMenuItems_BallsPocket[] = {
    ACTION_GIVE,        ACTION_DUMMY,
    ACTION_TOSS,        ACTION_CANCEL
};

static const u8 sContextMenuItems_TmHmPocket[] = {
    ACTION_USE,         ACTION_GIVE,
    ACTION_DUMMY,       ACTION_CANCEL
};

static const u8 sContextMenuItems_BerriesPocket[] = {
    ACTION_CHECK_TAG,   ACTION_DUMMY,
    ACTION_USE,         ACTION_GIVE,
    ACTION_TOSS,        ACTION_CANCEL
};

static const u8 sContextMenuItems_BattleUse[] = {
    ACTION_BATTLE_USE,  ACTION_CANCEL
};

static const u8 sContextMenuItems_Give[] = {
    ACTION_GIVE,        ACTION_CANCEL
};

static const u8 sContextMenuItems_Cancel[] = {
    ACTION_CANCEL
};

static const u8 sContextMenuItems_BerryBlenderCrush[] = {
    ACTION_CONFIRM,     ACTION_CHECK_TAG,
    ACTION_DUMMY,       ACTION_CANCEL
};

static const u8 sContextMenuItems_Apprentice[] = {
    ACTION_SHOW,        ACTION_CANCEL
};

static const u8 sContextMenuItems_FavorLady[] = {
    ACTION_GIVE_FAVOR_LADY, ACTION_CANCEL
};

static const u8 sContextMenuItems_QuizLady[] = {
    ACTION_CONFIRM_QUIZ_LADY, ACTION_CANCEL
};

static const TaskFunc sContextMenuFuncs[] = {
    [ITEMMENULOCATION_FIELD] =                  Task_ItemContext_Normal,
    [ITEMMENULOCATION_BATTLE] =                 Task_ItemContext_Normal,
    [ITEMMENULOCATION_PARTY] =                  Task_ItemContext_GiveToParty,
    [ITEMMENULOCATION_SHOP] =                   Task_ItemContext_Sell,
    [ITEMMENULOCATION_BERRY_TREE] =             Task_FadeAndCloseBagMenu,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] =    Task_ItemContext_Normal,
    [ITEMMENULOCATION_ITEMPC] =                 Task_ItemContext_Deposit,
    [ITEMMENULOCATION_FAVOR_LADY] =             Task_ItemContext_Normal,
    [ITEMMENULOCATION_QUIZ_LADY] =              Task_ItemContext_Normal,
    [ITEMMENULOCATION_APPRENTICE] =             Task_ItemContext_Normal,
    [ITEMMENULOCATION_WALLY] =                  NULL,
    [ITEMMENULOCATION_PCBOX] =                  Task_ItemContext_GiveToPC
};

static const struct YesNoFuncTable sYesNoTossFunctions = {ConfirmToss, CancelToss};

static const struct YesNoFuncTable sYesNoSellItemFunctions = {ConfirmSell, CancelSell};

static const struct ScrollArrowsTemplate sBagScrollArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_LEFT,
    .firstX = 28,
    .firstY = 16,
    .secondArrowType = SCROLL_ARROW_RIGHT,
    .secondX = 100,
    .secondY = 16,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = TAG_BAG_SCROLL_ARROW,
    .palTag = TAG_BAG_SCROLL_ARROW,
    .palNum = 0,
};

static const u8 sRegisteredSelect_Gfx[] = INCBIN_U8("graphics/bag/select_button.4bpp");

enum {
    COLORID_NORMAL,
    COLORID_POCKET_NAME,
    COLORID_GRAY_CURSOR,
    COLORID_UNUSED,
    COLORID_TMHM_INFO,
    COLORID_NONE = 0xFF
};
static const u8 sFontColorTable[][3] = {
                            // bgColor, textColor, shadowColor
    [COLORID_NORMAL]      = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_POCKET_NAME] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_RED},
    [COLORID_GRAY_CURSOR] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_GREEN},
    [COLORID_UNUSED]      = {TEXT_COLOR_DARK_GRAY,   TEXT_COLOR_WHITE,      TEXT_COLOR_LIGHT_GRAY},
    [COLORID_TMHM_INFO]   = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_5,  TEXT_DYNAMIC_COLOR_1}
};

static const struct WindowTemplate sDefaultBagWindows[] =
{
    [WIN_ITEM_LIST] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 2,
        .width = 15,
        .height = 16,
        .paletteNum = 1,
        .baseBlock = 0x27,
    },
    [WIN_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 8,
        .width = 14,
        .height = 8,
        .paletteNum = 1,
        .baseBlock = 0x117,
    },
    [WIN_POCKET_NAME] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 1,
        .width = 8,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 0x1BD,
    },
    [WIN_TMHM_INFO_ICONS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 5,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x187,
    },
    [WIN_TMHM_INFO] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 13,
        .width = 4,
        .height = 6,
        .paletteNum = 12,
        .baseBlock = 0x1A5,
    },
    [WIN_UPPER] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 3,
        .width = 4,
        .height = 4,
        .paletteNum = 7,
        .baseBlock = 0x1CD,
    },
    [WIN_UPPER_2] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 3,
        .width = 4,
        .height = 4,
        .paletteNum = 8,
        .baseBlock = 0x1ED,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sContextMenuWindowTemplates[] =
{
    [ITEMWIN_1x1] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_1x2] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 8,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_2x2] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_2x3] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_3x8] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 23,
        .height = 16,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_MESSAGE] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x259,
    },
    [ITEMWIN_YESNO_LOW] = { // Yes/No tucked in corner, for toss confirm
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_YESNO_HIGH] = { // Yes/No higher up, positioned above a lower message box
        .bg = 1,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_QUANTITY] = { // Used for quantity of items to Toss/Deposit
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 17,
        .width = 5,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x21D,
    },
    [ITEMWIN_QUANTITY_WIDE] = { // Used for quantity and price of items to Sell
        .bg = 1,
        .tilemapLeft = 18,
        .tilemapTop = 11,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x245,
    },
    [ITEMWIN_MONEY] = {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x231,
    },
};

EWRAM_DATA struct BagMenu *gBagMenu = 0;
EWRAM_DATA struct BagPosition gBagPosition = {0};
static EWRAM_DATA struct ListBuffer1 *sListBuffer1 = 0;
static EWRAM_DATA struct ListBuffer2 *sListBuffer2 = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = 0;
static EWRAM_DATA struct TempWallyBag *sTempWallyBag = 0;

void ResetBagScrollPositions(void)
{
    gBagPosition.pocket = ITEMS_POCKET;
    memset(gBagPosition.cursorPosition, 0, sizeof(gBagPosition.cursorPosition));
    memset(gBagPosition.scrollPosition, 0, sizeof(gBagPosition.scrollPosition));
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void CB2_BagMenuFromBattle(void)
{
    if (!InBattlePyramid())
        GoToBagMenu(ITEMMENULOCATION_BATTLE, POCKETS_COUNT, CB2_SetUpReshowBattleScreenAfterMenu2);
    else
        GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_BATTLE, CB2_SetUpReshowBattleScreenAfterMenu2);
}

// Choosing berry to plant
void CB2_ChooseBerry(void)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_TREE, BERRIES_POCKET, CB2_ReturnToFieldContinueScript);
}

// Choosing berry for Berry Blender or Berry Crush
void ChooseBerryForMachine(void (*exitCallback)(void))
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_BLENDER_CRUSH, BERRIES_POCKET, exitCallback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void CB2_GoToItemDepositMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_ITEMPC, POCKETS_COUNT, CB2_PlayerPCExitBagMenu);
}

void ApprenticeOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_APPRENTICE, POCKETS_COUNT, CB2_ApprenticeExitBagMenu);
    gSpecialVar_0x8005 = ITEM_NONE;
    gSpecialVar_Result = FALSE;
}

void FavorLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FAVOR_LADY, POCKETS_COUNT, CB2_FavorLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void QuizLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_QUIZ_LADY, POCKETS_COUNT, CB2_QuizLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void GoToBagMenu(u8 location, u8 pocket, void ( *exitCallback)())
{
    gBagMenu = AllocZeroed(sizeof(*gBagMenu));
    if (gBagMenu == NULL)
    {
        // Alloc failed, exit
        SetMainCallback2(exitCallback);
    }
    else
    {
        if (location != ITEMMENULOCATION_LAST)
            gBagPosition.location = location;
        if (exitCallback)
            gBagPosition.exitCallback = exitCallback;
        if (pocket < POCKETS_COUNT)
            gBagPosition.pocket = pocket;
        if (gBagPosition.location == ITEMMENULOCATION_BERRY_TREE ||
            gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
            gBagMenu->pocketSwitchDisabled = TRUE;
        gBagMenu->newScreenCallback = NULL;
        gBagMenu->toSwapPos = NOT_SWAPPING;
        gBagMenu->pocketScrollArrowsTask = TASK_NONE;
        gBagMenu->pocketSwitchArrowsTask = TASK_NONE;
        memset(gBagMenu->spriteIds, SPRITE_NONE, sizeof(gBagMenu->spriteIds));
        memset(gBagMenu->windowIds, WINDOW_NONE, sizeof(gBagMenu->windowIds));
        SetMainCallback2(CB2_Bag);
    }
}

void CB2_BagMenuRun(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void VBlankCB_BagMenuRun(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tListTaskId        data[0]
#define tListPosition      data[1]
#define tQuantity          data[2]
#define tNeverRead         data[3]
#define tItemCount         data[8]
#define tMsgWindowId       data[10]
#define tPocketSwitchDir   data[11]
#define tPocketSwitchTimer data[12]
#define tPocketSwitchState data[13]

static void CB2_Bag(void)
{
    while(MenuHelpers_ShouldWaitForLinkRecv() != TRUE && SetupBagMenu() != TRUE && MenuHelpers_IsLinkActive() != TRUE)
        {};
}

static bool8 SetupBagMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        BagMenu_InitBGs();
        gBagMenu->graphicsLoadState = 0;
        gMain.state++;
        break;
    case 8:
        if (!LoadBagMenu_Graphics())
            break;
        gMain.state++;
        break;
    case 9:
        LoadBagMenuTextWindows();
        gMain.state++;
        break;
    case 10:
        UpdatePocketItemLists();
        InitPocketListPositions();
        InitPocketScrollPositions();
        gMain.state++;
        break;
    case 11:
        AllocateBagItemListBuffers();
        gMain.state++;
        break;
    case 12:
        LoadBagItemListBuffers(gBagPosition.pocket);
        gMain.state++;
        break;
    case 13:
        PrintPocketNames(gPocketNamesStringsTable[gBagPosition.pocket], 0);
        CopyPocketNameToWindow(0);
        DrawPocketIndicatorSquare(gBagPosition.pocket, TRUE);
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPosition.location);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        gTasks[taskId].tNeverRead = 0;
        gTasks[taskId].tItemCount = 0;
        gMain.state++;
        break;
    case 15:
        AddBagVisualSprite(gBagPosition.pocket);
        gMain.state++;
        break;
    case 16:
        CreateItemMenuSwapLine();
        gMain.state++;
        break;
    case 17:
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        gMain.state++;
        break;
    case 18:
        PrepareTMHMMoveWindow();
        gMain.state++;
        break;
    case 19:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 20:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_BagMenuRun);
        SetMainCallback2(CB2_BagMenuRun);
        return TRUE;
    }
    return FALSE;
}

static void BagMenu_InitBGs(void)
{
    ResetVramOamAndBgCntRegs();
    memset(gBagMenu->tilemapBuffer, 0, sizeof(gBagMenu->tilemapBuffer));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_ItemMenu, ARRAY_COUNT(sBgTemplates_ItemMenu));
    SetBgTilemapBuffer(2, gBagMenu->tilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadBagMenu_Graphics(void)
{
    switch (gBagMenu->graphicsLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, gBagScreen_Gfx, 0, 0, 0);
        gBagMenu->graphicsLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(gBagScreen_GfxTileMap, gBagMenu->tilemapBuffer);
            gBagMenu->graphicsLoadState++;
        }
        break;
    case 2:
        if (!IsWallysBag() && gSaveBlock2Ptr->playerGender != MALE)
            LoadCompressedPalette(gBagScreenFemale_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        else
            LoadCompressedPalette(gBagScreenMale_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        gBagMenu->graphicsLoadState++;
        break;
    case 3:
        if (IsWallysBag() == TRUE || gSaveBlock2Ptr->playerGender == MALE)
            LoadCompressedSpriteSheet(&gBagMaleSpriteSheet);
        else
            LoadCompressedSpriteSheet(&gBagFemaleSpriteSheet);
        gBagMenu->graphicsLoadState++;
        break;
    case 4:
        LoadCompressedSpritePalette(&gBagPaletteTable);
        gBagMenu->graphicsLoadState++;
        break;
    default:
        LoadListMenuSwapLineGfx();
        gBagMenu->graphicsLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static u8 CreateBagInputHandlerTask(u8 location)
{
    u8 taskId;
    if (location == ITEMMENULOCATION_WALLY)
        taskId = CreateTask(Task_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu_HandleInput, 0);
    return taskId;
}

static void AllocateBagItemListBuffers(void)
{
    sListBuffer1 = Alloc(sizeof(*sListBuffer1));
    sListBuffer2 = Alloc(sizeof(*sListBuffer2));
}

static void LoadBagItemListBuffers(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    struct ListMenuItem *subBuffer;

    if (!gBagMenu->hideCloseBagText)
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId] - 1; i++)
        {
            GetItemNameFromPocket(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(sListBuffer2->name[i], gText_CloseBag);
        subBuffer = sListBuffer1->subBuffers;
        subBuffer[i].name = sListBuffer2->name[i];
        subBuffer[i].id = LIST_CANCEL;
    }
    else
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId]; i++)
        {
            GetItemNameFromPocket(sListBuffer2->name[i], pocket->itemSlots[i].itemId);
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = sItemListMenu;
    gMultiuseListMenuTemplate.totalItems = gBagMenu->numItemStacks[pocketId];
    gMultiuseListMenuTemplate.items = sListBuffer1->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gBagMenu->numShownItems[pocketId];
}

static void GetItemNameFromPocket(u8 *dest, u16 itemId)
{
    switch (gBagPosition.pocket)
    {
    case TMHM_POCKET:
        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(itemId)]);
        if (itemId >= ITEM_HM01)
        {
            // Get HM number
            ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
            StringExpandPlaceholders(dest, gText_NumberItem_HM);
        }
        else
        {
            // Get TM number
            ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
        }
        break;
    case BERRIES_POCKET:
        ConvertIntToDecimalStringN(gStringVar1, itemId - FIRST_BERRY_INDEX + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
        CopyItemName(itemId, gStringVar2);
        StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
        break;
    default:
        CopyItemName(itemId, dest);
        break;
    }
}

static void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        ShakeBagSprite();
    }
    if (gBagMenu->toSwapPos == NOT_SWAPPING)
    {
        RemoveBagItemIconSprite(gBagMenu->itemIconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
           AddBagItemIconSprite(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex), gBagMenu->itemIconSlot);
        else
           AddBagItemIconSprite(ITEM_LIST_END, gBagMenu->itemIconSlot);
        gBagMenu->itemIconSlot ^= 1;
        if (!gBagMenu->inhibitItemDescriptionPrint)
            PrintItemDescription(itemIndex);
    }
}

static void BagMenu_ItemPrintCallback(u8 windowId, u32 itemIndex, u8 y)
{
    u16 itemId;
    u16 itemQuantity;
    int offset;

    if (itemIndex != LIST_CANCEL)
    {
        if (gBagMenu->toSwapPos != NOT_SWAPPING)
        {
            // Swapping items, draw cursor at original item's location
            if (gBagMenu->toSwapPos == (u8)itemIndex)
                BagMenu_PrintCursorAtPos(y, COLORID_GRAY_CURSOR);
            else
                BagMenu_PrintCursorAtPos(y, COLORID_NONE);
        }

        itemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex);
        itemQuantity = BagGetQuantityByPocketPosition(gBagPosition.pocket + 1, itemIndex);

        // Draw HM icon
        if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
            BlitBitmapToWindow(windowId, gBagMenuHMIcon_Gfx, 8, y - 1, 16, 16);

        if (gBagPosition.pocket == BERRIES_POCKET)
        {
            // Print berry quantity
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, BERRY_CAPACITY_DIGITS);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 119);
            BagMenu_Print(windowId, FONT_NARROW, gStringVar4, offset, y, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        }
        else if (gBagPosition.pocket != KEYITEMS_POCKET && GetItemImportance(itemId) == FALSE)
        {
            // Print item quantity
            ConvertIntToDecimalStringN(gStringVar1, itemQuantity, STR_CONV_MODE_RIGHT_ALIGN, BAG_ITEM_CAPACITY_DIGITS);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 119);
            BagMenu_Print(windowId, FONT_NARROW, gStringVar4, offset, y, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        }
        else
        {
            // Print registered icon
            if (gSaveBlock1Ptr->registeredItem != ITEM_NONE && gSaveBlock1Ptr->registeredItem == itemId)
                BlitBitmapToWindow(windowId, sRegisteredSelect_Gfx, 96, y - 1, 24, 16);
        }
    }
}

enum Colors_
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors_[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
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

const u16 *const sCardRaceIconPals[NUM_RACES + 1] =
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

static void PrintItemDescription(int itemIndex)
{
    const u8 *str;
    u16 itemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, itemIndex);
    u16 card = CardIdMapping[itemId];
    u8 attribute = gCardInfo[card].attribute;
    u8 race = gCardInfo[card].race;
    u8 type = gCardInfo[card].type;
    const u8 *cardName = gCardInfo[card].nameShort;
    u16 cardAtk = gCardInfo[card].atk * 10;
    u16 cardDef = gCardInfo[card].def * 10;
    u8 cardLevel = gCardInfo[card].level;
    if (itemIndex != LIST_CANCEL)
    {
        str = GetItemDescription(itemId);
    }
    else
    {
        // Print 'Cancel' description
        StringCopy(gStringVar1, gBagMenu_ReturnToStrings[gBagPosition.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
    }
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_UPPER, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_UPPER_2, PIXEL_FILL(0));
    if (card == 0) {
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, str, 3, 4, 0, 0, 0, COLORID_NORMAL);
        ClearWindowTilemap(WIN_UPPER);
        ClearWindowTilemap(WIN_UPPER_2);
        ScheduleBgCopyTilemapToVram(0);
    }
    else
    {
        BagMenu_Print(WIN_DESCRIPTION, FONT_SMALL_NARROWER, cardName, 3, 4, 0, 0, 0, COLORID_NORMAL);
        ConvertIntToDecimalStringN(gStringVar1, cardLevel, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_xLevel);
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 20, 0, 0, 0, COLORID_NORMAL);
        ConvertIntToDecimalStringN(gStringVar1, cardAtk, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_xAtk);
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 36, 0, 0, 0, COLORID_NORMAL);
        ConvertIntToDecimalStringN(gStringVar1, cardDef, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, gText_xDef);
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 52, 0, 0, 0, COLORID_NORMAL);
        if (type == TYPE_SPELL_CARD || type == TYPE_TRAP_CARD)
        {
            BlitBitmapToWindow(WIN_UPPER, sCardTypeIcons[type], 14, 8, 16, 16);
            LoadPalette(sCardTypeIconPals[type], BG_PLTT_ID(7), 32);
        }
        else
        {
            BlitBitmapToWindow(WIN_UPPER, sCardRaceIcons[race], 14, 8, 16, 16);
            LoadPalette(sCardRaceIconPals[race], BG_PLTT_ID(7), 32);
            BlitBitmapToWindow(WIN_UPPER_2, sCardAttributeIcons[attribute], 0, 6, 16, 16);
            LoadPalette(sCardAttributeIconPals[attribute], BG_PLTT_ID(8), 32);
        }
        CopyWindowToVram(WIN_UPPER, COPYWIN_GFX);
        CopyWindowToVram(WIN_UPPER_2, COPYWIN_GFX);
        PutWindowTilemap(WIN_UPPER);
        PutWindowTilemap(WIN_UPPER_2);
        ScheduleBgCopyTilemapToVram(0);
    }
}

static void BagMenu_PrintCursor(u8 listTaskId, u8 colorIndex)
{
    BagMenu_PrintCursorAtPos(ListMenuGetYCoordForPrintingArrowCursor(listTaskId), colorIndex);
}

static void BagMenu_PrintCursorAtPos(u8 y, u8 colorIndex)
{
    if (colorIndex == COLORID_NONE)
        FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 0, y, GetMenuCursorDimensionByFont(FONT_NORMAL, 0), GetMenuCursorDimensionByFont(FONT_NORMAL, 1));
    else
        BagMenu_Print(WIN_ITEM_LIST, FONT_NORMAL, gText_SelectorArrow2, 0, y, 0, 0, 0, colorIndex);

}

static void CreatePocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask == TASK_NONE)
        gBagMenu->pocketScrollArrowsTask = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            172,
            12,
            148,
            gBagMenu->numItemStacks[gBagPosition.pocket] - gBagMenu->numShownItems[gBagPosition.pocket],
            TAG_POCKET_SCROLL_ARROW,
            TAG_POCKET_SCROLL_ARROW,
            &gBagPosition.scrollPosition[gBagPosition.pocket]);
}

void BagDestroyPocketScrollArrowPair(void)
{
    if (gBagMenu->pocketScrollArrowsTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketScrollArrowsTask);
        gBagMenu->pocketScrollArrowsTask = TASK_NONE;
    }
    DestroyPocketSwitchArrowPair();
}

static void CreatePocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchDisabled != TRUE && gBagMenu->pocketSwitchArrowsTask == TASK_NONE)
        gBagMenu->pocketSwitchArrowsTask = AddScrollIndicatorArrowPair(&sBagScrollArrowsTemplate, &gBagPosition.pocketSwitchArrowPos);
}

static void DestroyPocketSwitchArrowPair(void)
{
    if (gBagMenu->pocketSwitchArrowsTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(gBagMenu->pocketSwitchArrowsTask);
        gBagMenu->pocketSwitchArrowsTask = TASK_NONE;
    }
}

static void FreeBagMenu(void)
{
    Free(sListBuffer2);
    Free(sListBuffer1);
    FreeAllWindowBuffers();
    Free(gBagMenu);
}

void Task_FadeAndCloseBagMenu(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_CloseBagMenu;
}

static void Task_CloseBagMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);

        // If ready for a new screen (e.g. party menu for giving an item) go to that screen
        // Otherwise exit the bag and use callback set up when the bag was first opened
        if (gBagMenu->newScreenCallback != NULL)
            SetMainCallback2(gBagMenu->newScreenCallback);
        else
            SetMainCallback2(gBagPosition.exitCallback);

        BagDestroyPocketScrollArrowPair();
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeBagMenu();
        DestroyTask(taskId);
    }
}

void UpdatePocketItemList(u8 pocketId)
{
    u16 i;
    struct BagPocket *pocket = &gBagPockets[pocketId];
    switch (pocketId)
    {
    case TMHM_POCKET:
    case BERRIES_POCKET:
        SortBerriesOrTMHMs(pocket);
        break;
    default:
        CompactItemsInBagPocket(pocket);
        break;
    }

    gBagMenu->numItemStacks[pocketId] = 0;

    for (i = 0; i < pocket->capacity && pocket->itemSlots[i].itemId; i++)
        gBagMenu->numItemStacks[pocketId]++;

    if (!gBagMenu->hideCloseBagText)
        gBagMenu->numItemStacks[pocketId]++;

    if (gBagMenu->numItemStacks[pocketId] > MAX_ITEMS_SHOWN)
        gBagMenu->numShownItems[pocketId] = MAX_ITEMS_SHOWN;
    else
        gBagMenu->numShownItems[pocketId] = gBagMenu->numItemStacks[pocketId];
}

static void UpdatePocketItemLists(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketItemList(i);
}

void UpdatePocketListPosition(u8 pocketId)
{
    SetCursorWithinListBounds(&gBagPosition.scrollPosition[pocketId], &gBagPosition.cursorPosition[pocketId], gBagMenu->numShownItems[pocketId], gBagMenu->numItemStacks[pocketId]);
}

static void InitPocketListPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketListPosition(i);
}

static void InitPocketScrollPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        SetCursorScrollWithinListBounds(&gBagPosition.scrollPosition[i], &gBagPosition.cursorPosition[i], gBagMenu->numShownItems[i], gBagMenu->numItemStacks[i], MAX_ITEMS_SHOWN);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gBagPosition.scrollPosition[pocketId] + gBagPosition.cursorPosition[pocketId];
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, void (*callback)(u8 taskId))
{
    s16 *data = gTasks[taskId].data;

    tMsgWindowId = AddItemMessageWindow(ITEMWIN_MESSAGE);
    FillWindowPixelBuffer(tMsgWindowId, PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, tMsgWindowId, 10, 13, fontId, GetPlayerTextSpeedDelay(), str, callback);
    ScheduleBgCopyTilemapToVram(1);
}

void CloseItemMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    ReturnToItemList(taskId);
}

static void AddItemQuantityWindow(u8 windowType)
{
    PrintItemQuantity(BagMenu_AddWindow(windowType), 1);
}

static void PrintItemQuantity(u8 windowId, s16 quantity)
{
    u8 numDigits = (gBagPosition.pocket == BERRIES_POCKET) ? BERRY_CAPACITY_DIGITS : BAG_ITEM_CAPACITY_DIGITS;
    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 0x28), 2, 0, 0);
}

// Prints the quantity of items to be sold and the amount that would be earned
static void PrintItemSoldAmount(int windowId, int numSold, int moneyEarned)
{
    u8 numDigits = (gBagPosition.pocket == BERRIES_POCKET) ? BERRY_CAPACITY_DIGITS : BAG_ITEM_CAPACITY_DIGITS;
    ConvertIntToDecimalStringN(gStringVar1, numSold, STR_CONV_MODE_LEADING_ZEROS, numDigits);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, 0);
    PrintMoneyAmount(windowId, 38, 1, moneyEarned, 0);
}

static void Task_BagMenu_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    s32 listPosition;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        switch (GetSwitchBagPocketDirection())
        {
        case SWITCH_POCKET_LEFT:
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, FALSE);
            return;
        case SWITCH_POCKET_RIGHT:
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
            return;
        default:
            if (JOY_NEW(SELECT_BUTTON))
            {
                if (CanSwapItems() == TRUE)
                {
                    ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
                    if ((*scrollPos + *cursorPos) != gBagMenu->numItemStacks[gBagPosition.pocket] - 1)
                    {
                        PlaySE(SE_SELECT);
                        StartItemSwap(taskId);
                    }
                }
                return;
            }
            else if (JOY_NEW(START_BUTTON))
            {
                if ((gBagMenu->numItemStacks[gBagPosition.pocket] - 1) <= 1) //can't sort with 0 or 1 item in bag
                {
                    static const u8 sText_NothingToSort[] = _("There's nothing to sort!");
                    PlaySE(SE_FAILURE);
                    DisplayItemMessage(taskId, 1, sText_NothingToSort, HandleErrorMessage);
                    break;
                }
                
                data[1] = GetItemListPosition(gBagPosition.pocket);
                data[2] = BagGetQuantityByPocketPosition(gBagPosition.pocket + 1, data[1]);
                if (gBagPosition.cursorPosition[gBagPosition.pocket] == gBagMenu->numItemStacks[gBagPosition.pocket] - 1)
                    break;
                else
                    gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, data[1]);
                
                PlaySE(SE_SELECT);
                BagDestroyPocketScrollArrowPair();
                BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
                ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
                gTasks[taskId].func = Task_LoadBagSortOptions;
                return;
            }
            break;
        }

        listPosition = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        switch (listPosition)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            if (gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
            {
                PlaySE(SE_FAILURE);
                break;
            }
            PlaySE(SE_SELECT);
            gSpecialVar_ItemId = ITEM_NONE;
            gTasks[taskId].func = Task_FadeAndCloseBagMenu;
            break;
        default: // A_BUTTON
            PlaySE(SE_SELECT);
            BagDestroyPocketScrollArrowPair();
            BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
            tListPosition = listPosition;
            tQuantity = BagGetQuantityByPocketPosition(gBagPosition.pocket + 1, listPosition);
            gSpecialVar_ItemId = BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, listPosition);
            sContextMenuFuncs[gBagPosition.location](taskId);
            break;
        }
    }
}

static void ReturnToItemList(u8 taskId)
{
    CreatePocketScrollArrowPair();
    CreatePocketSwitchArrowPair();
    ClearWindowTilemap(WIN_TMHM_INFO_ICONS);
    ClearWindowTilemap(WIN_TMHM_INFO);
    PutWindowTilemap(WIN_DESCRIPTION);
    PutWindowTilemap(WIN_UPPER);
    PutWindowTilemap(WIN_UPPER_2);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;
    if (gBagMenu->pocketSwitchDisabled)
        return SWITCH_POCKET_NONE;
    LRKeys = GetLRKeysPressed();
    if (JOY_NEW(DPAD_LEFT) || LRKeys == MENU_L_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_LEFT;
    }
    if (JOY_NEW(DPAD_RIGHT) || LRKeys == MENU_R_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_RIGHT;
    }
    return SWITCH_POCKET_NONE;
}

static void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == MENU_CURSOR_DELTA_RIGHT && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == MENU_CURSOR_DELTA_LEFT && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

static void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, bool16 skipEraseList)
{
    s16 *data = gTasks[taskId].data;
    u8 newPocket;

    tPocketSwitchState = 0;
    tPocketSwitchTimer = 0;
    tPocketSwitchDir = deltaBagPocketId;
    if (!skipEraseList)
    {
        ClearWindowTilemap(WIN_ITEM_LIST);
        ClearWindowTilemap(WIN_DESCRIPTION);
        ClearWindowTilemap(WIN_UPPER);
        ClearWindowTilemap(WIN_UPPER_2);
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        ScheduleBgCopyTilemapToVram(0);
        gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)]].invisible = TRUE;
        BagDestroyPocketScrollArrowPair();
    }
    newPocket = gBagPosition.pocket;
    ChangeBagPocketId(&newPocket, deltaBagPocketId);
    if (deltaBagPocketId == MENU_CURSOR_DELTA_RIGHT)
    {
        PrintPocketNames(gPocketNamesStringsTable[gBagPosition.pocket], gPocketNamesStringsTable[newPocket]);
        CopyPocketNameToWindow(0);
    }
    else
    {
        PrintPocketNames(gPocketNamesStringsTable[newPocket], gPocketNamesStringsTable[gBagPosition.pocket]);
        CopyPocketNameToWindow(8);
    }
    DrawPocketIndicatorSquare(gBagPosition.pocket, FALSE);
    DrawPocketIndicatorSquare(newPocket, TRUE);
    FillBgTilemapBufferRect_Palette0(2, 11, 14, 2, 15, 16);
    ScheduleBgCopyTilemapToVram(2);
    SetBagVisualPocketId(newPocket, TRUE);
    RemoveBagSprite(ITEMMENUSPRITE_BALL);
    AddSwitchPocketRotatingBallSprite(deltaBagPocketId);
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchBagPocket, gTasks[taskId].func);
}

static void Task_SwitchBagPocket(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!MenuHelpers_IsLinkActive() && !IsWallysBag())
    {
        switch (GetSwitchBagPocketDirection())
        {
        case SWITCH_POCKET_LEFT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, TRUE);
            return;
        case SWITCH_POCKET_RIGHT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, TRUE);
            return;
        }
    }
    switch (tPocketSwitchState)
    {
    case 0:
        DrawItemListBgRow(tPocketSwitchTimer);
        if (!(++tPocketSwitchTimer & 1))
        {
            if (tPocketSwitchDir == MENU_CURSOR_DELTA_RIGHT)
                CopyPocketNameToWindow((u8)(tPocketSwitchTimer >> 1));
            else
                CopyPocketNameToWindow((u8)(8 - (tPocketSwitchTimer >> 1)));
        }
        if (tPocketSwitchTimer == 16)
            tPocketSwitchState++;
        break;
    case 1:
        ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        PutWindowTilemap(WIN_DESCRIPTION);
        PutWindowTilemap(WIN_POCKET_NAME);
        ScheduleBgCopyTilemapToVram(0);
        CreatePocketScrollArrowPair();
        CreatePocketSwitchArrowPair();
        SwitchTaskToFollowupFunc(taskId);
    }
}

// The background of the item list is a lighter color than the surrounding menu
// When the pocket is switched this lighter background is redrawn row by row
static void DrawItemListBgRow(u8 y)
{
    FillBgTilemapBufferRect_Palette0(2, 17, 14, y + 2, 15, 1);
    ScheduleBgCopyTilemapToVram(2);
}

static void DrawPocketIndicatorSquare(u8 x, bool8 isCurrentPocket)
{
    if (!isCurrentPocket)
        FillBgTilemapBufferRect_Palette0(2, 0x1017, x + 4, 3, 1, 1);
    else
        FillBgTilemapBufferRect_Palette0(2, 0x102B, x + 4, 3, 1, 1);
    ScheduleBgCopyTilemapToVram(2);
}

static bool8 CanSwapItems(void)
{
    // Swaps can only be done from the field or in battle (as opposed to while selling items, for example)
    if (gBagPosition.location == ITEMMENULOCATION_FIELD
     || gBagPosition.location == ITEMMENULOCATION_BATTLE)
    {
        // TMHMs and berries are numbered, and so may not be swapped
        if (gBagPosition.pocket != TMHM_POCKET
         && gBagPosition.pocket != BERRIES_POCKET)
            return TRUE;
    }
    return FALSE;
}

static void StartItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ListMenuSetTemplateField(tListTaskId, LISTFIELD_CURSORKIND, CURSOR_INVISIBLE);
    tListPosition = gBagPosition.scrollPosition[gBagPosition.pocket] + gBagPosition.cursorPosition[gBagPosition.pocket];
    gBagMenu->toSwapPos = tListPosition;
    CopyItemName(BagGetItemIdByPocketPosition(gBagPosition.pocket + 1, tListPosition), gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_MoveVar1Where);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
    UpdateItemMenuSwapLinePos(tListPosition);
    DestroyPocketSwitchArrowPair();
    BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
    gTasks[taskId].func = Task_HandleSwappingItemsInput;
}

static void Task_HandleSwappingItemsInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(SELECT_BUTTON))
        {
            PlaySE(SE_SELECT);
            ListMenuGetScrollAndRow(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
            DoItemSwap(taskId);
        }
        else
        {
            s32 input = ListMenu_ProcessInput(tListTaskId);
            ListMenuGetScrollAndRow(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
            SetItemMenuSwapLineInvisibility(FALSE);
            UpdateItemMenuSwapLinePos(gBagPosition.cursorPosition[gBagPosition.pocket]);
            switch (input)
            {
            case LIST_NOTHING_CHOSEN:
                break;
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                if (JOY_NEW(A_BUTTON))
                    DoItemSwap(taskId);
                else
                    CancelItemSwap(taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                DoItemSwap(taskId);
                break;
            }
        }
    }
}

static void DoItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    u16 realPos = (*scrollPos + *cursorPos);

    if (tListPosition == realPos || tListPosition == realPos - 1)
    {
        // Position is the same as the original, cancel
        CancelItemSwap(taskId);
    }
    else
    {
        MoveItemSlotInList(gBagPockets[gBagPosition.pocket].itemSlots, tListPosition, realPos);
        gBagMenu->toSwapPos = NOT_SWAPPING;
        DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
        if (tListPosition < realPos)
            gBagPosition.cursorPosition[gBagPosition.pocket]--;
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        SetItemMenuSwapLineInvisibility(TRUE);
        CreatePocketSwitchArrowPair();
        gTasks[taskId].func = Task_BagMenu_HandleInput;
    }
}

static void CancelItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    gBagMenu->toSwapPos = NOT_SWAPPING;
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    if (tListPosition < *scrollPos + *cursorPos)
        gBagPosition.cursorPosition[gBagPosition.pocket]--;
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    SetItemMenuSwapLineInvisibility(TRUE);
    CreatePocketSwitchArrowPair();
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static void OpenContextMenu(u8 taskId)
{
    u16 card = CardIdMapping[gSpecialVar_ItemId];
    switch (gBagPosition.location)
    {
    case ITEMMENULOCATION_BATTLE:
    case ITEMMENULOCATION_WALLY:
        if (GetItemBattleUsage(gSpecialVar_ItemId))
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_BattleUse;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BattleUse);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_BERRY_BLENDER_CRUSH:
        gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerryBlenderCrush;
        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerryBlenderCrush);
        break;
    case ITEMMENULOCATION_APPRENTICE:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Apprentice;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Apprentice);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_FAVOR_LADY:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_FavorLady;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_FavorLady);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_QUIZ_LADY:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_QuizLady;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_QuizLady);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_PARTY:
    case ITEMMENULOCATION_SHOP:
    case ITEMMENULOCATION_BERRY_TREE:
    case ITEMMENULOCATION_ITEMPC:
    default:
        if (MenuHelpers_IsLinkActive() == TRUE || InUnionRoom() == TRUE)
        {
            if (gBagPosition.pocket == KEYITEMS_POCKET || !IsHoldingItemAllowed(gSpecialVar_ItemId))
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Give;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Give);
            }
        }
        else
        {
            switch (gBagPosition.pocket)
            {
            case ITEMS_POCKET:
            case TRUNK_POCKET:
            case MAIN_DECK_POCKET:
            case EXTRA_DECK_POCKET:
            case SIDE_DECK_POCKET:
                gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                if (card == 0)
                {
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_ItemsPocket);
                    memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_ItemsPocket, sizeof(sContextMenuItems_ItemsPocket));
                }
                else
                {
                    gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuCards_ItemsPocket);
                    memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuCards_ItemsPocket, sizeof(sContextMenuCards_ItemsPocket));
                    
                }
                if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                    gBagMenu->contextMenuItemsBuffer[0] = ACTION_CHECK;
                break;
            case KEYITEMS_POCKET:
                gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_KeyItemsPocket);
                memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_KeyItemsPocket, sizeof(sContextMenuItems_KeyItemsPocket));
                if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                    gBagMenu->contextMenuItemsBuffer[1] = ACTION_DESELECT;
                if (gSpecialVar_ItemId == ITEM_MACH_BIKE || gSpecialVar_ItemId == ITEM_ACRO_BIKE)
                {
                    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
                        gBagMenu->contextMenuItemsBuffer[0] = ACTION_WALK;
                }
                break;
            case BALLS_POCKET:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_BallsPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BallsPocket);
                break;
            case TMHM_POCKET:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_TmHmPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_TmHmPocket);
                break;
            case BERRIES_POCKET:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerriesPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerriesPocket);
                break;
            }
        }
    }
    if (gBagPosition.pocket == TMHM_POCKET)
    {
        ClearWindowTilemap(WIN_DESCRIPTION);
        ClearWindowTilemap(WIN_UPPER);
        ClearWindowTilemap(WIN_UPPER_2);
        PrintTMHMMoveData(gSpecialVar_ItemId);
        PutWindowTilemap(WIN_TMHM_INFO_ICONS);
        PutWindowTilemap(WIN_TMHM_INFO);
        ScheduleBgCopyTilemapToVram(0);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1IsSelected);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
    }
    if (gBagMenu->contextMenuNumItems == 1)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x1));
    else if (gBagMenu->contextMenuNumItems == 2)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x2));
    else if (gBagMenu->contextMenuNumItems <= 4)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x2), 2, 2);
    else if (gBagMenu->contextMenuNumItems <= 6)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x3), 2, 3);
    else
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_3x8), 3, 8);
}

static void PrintContextMenuItems(u8 windowId)
{
    PrintMenuActionTexts(windowId, FONT_NARROW, 8, 1, 0, 16, gBagMenu->contextMenuNumItems, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuInUpperLeftCornerNormal(windowId, gBagMenu->contextMenuNumItems, 0);
}

static void PrintContextMenuItemGrid(u8 windowId, u8 columns, u8 rows)
{
    PrintMenuActionGrid(windowId, FONT_NARROW, 8, 1, 56, columns, rows, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuActionGrid(windowId, 56, columns, rows, 0);
}

static void Task_ItemContext_Normal(u8 taskId)
{
    OpenContextMenu(taskId);

    // Context menu width is never greater than 2 columns, so if
    // there are more than 2 items then there are multiple rows
    if (gBagMenu->contextMenuNumItems <= 2)
        gTasks[taskId].func = Task_ItemContext_SingleRow;
    else
        gTasks[taskId].func = Task_ItemContext_MultipleRows;
}

static void Task_ItemContext_SingleRow(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 selection = Menu_ProcessInputNoWrap();
        u16 card = CardIdMapping[gSpecialVar_ItemId];
        switch (selection)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sItemMenuActions[ACTION_CANCEL].func.void_u8(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[selection]].func.void_u8(taskId);
            break;
        }
    }
}

static void Task_ItemContext_MultipleRows(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 cursorPos = Menu_GetCursorPos();
        if (JOY_NEW(DPAD_UP))
        {
            if (cursorPos > 0 && IsValidContextMenuPos(cursorPos - 2))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (cursorPos < (gBagMenu->contextMenuNumItems - 2) && IsValidContextMenuPos(cursorPos + 2))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
            }
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if ((cursorPos & 1) && IsValidContextMenuPos(cursorPos - 1))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (!(cursorPos & 1) && IsValidContextMenuPos(cursorPos + 1))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[cursorPos]].func.void_u8(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[ACTION_CANCEL].func.void_u8(taskId);
        }
    }
}

static bool8 IsValidContextMenuPos(s8 cursorPos)
{
    if (cursorPos < 0)
        return FALSE;
    if (cursorPos > gBagMenu->contextMenuNumItems)
        return FALSE;
    if (gBagMenu->contextMenuItemsPtr[cursorPos] == ACTION_DUMMY)
        return FALSE;
    return TRUE;
}

static void RemoveContextWindow(void)
{
    if (gBagMenu->contextMenuNumItems == 1)
        BagMenu_RemoveWindow(ITEMWIN_1x1);
    else if (gBagMenu->contextMenuNumItems == 2)
        BagMenu_RemoveWindow(ITEMWIN_1x2);
    else if (gBagMenu->contextMenuNumItems <= 4)
        BagMenu_RemoveWindow(ITEMWIN_2x2);
    else if (gBagMenu->contextMenuNumItems <= 6)
        BagMenu_RemoveWindow(ITEMWIN_2x3);
    else
        BagMenu_RemoveWindow(ITEMWIN_3x8);
}

static void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (GetItemFieldFunc(gSpecialVar_ItemId))
    {
        RemoveContextWindow();
        if (CalculatePlayerPartyCount() == 0 && GetItemType(gSpecialVar_ItemId) == ITEM_USE_PARTY_MENU)
        {
            PrintThereIsNoPokemon(taskId);
        }
        else
        {
            FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
            ScheduleBgCopyTilemapToVram(0);
            if (gBagPosition.pocket != BERRIES_POCKET)
                GetItemFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                ItemUseOutOfBattle_Berry(taskId);
        }
    }
}

static void ItemMenu_Toss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveContextWindow();
    tItemCount = 1;
    if (tQuantity == 1)
    {
        AskTossItems(taskId);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
        AddItemQuantityWindow(ITEMWIN_QUANTITY);
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

static void AskTossItems(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
    BagMenu_YesNo(taskId, ITEMWIN_YESNO_LOW, &sYesNoTossFunctions);
}

static void CancelToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PrintItemDescription(tListPosition);
    BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void Task_ChooseHowManyToToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintItemQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        AskTossItems(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        CancelToss(taskId);
    }
}

static void ConfirmToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
    gTasks[taskId].func = Task_RemoveItemFromBag;
}

// Remove selected item(s) from the bag and update list
// For when items are tossed or deposited
static void Task_RemoveItemFromBag(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, tItemCount);
        DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
        UpdatePocketItemList(gBagPosition.pocket);
        UpdatePocketListPosition(gBagPosition.pocket);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        ScheduleBgCopyTilemapToVram(0);
        ReturnToItemList(taskId);
    }
}

static void ItemMenu_Register(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    ItemMenu_Cancel(taskId);
}

static void ItemMenu_Give(u8 taskId)
{
    RemoveContextWindow();
    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    }
    else if (!GetItemImportance(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
        {
            PrintThereIsNoPokemon(taskId);
        }
        else
        {
            gBagMenu->newScreenCallback = CB2_ChooseMonToGiveItem;
            Task_FadeAndCloseBagMenu(taskId);
        }
    }
    else
    {
        PrintItemCantBeHeld(taskId);
    }
}

static void PrintThereIsNoPokemon(u8 taskId)
{
    DisplayItemMessage(taskId, FONT_NORMAL, gText_NoPokemon, HandleErrorMessage);
}

static void PrintItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, HandleErrorMessage);
}

static void HandleErrorMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseItemMessage(taskId);
    }
}

static void ItemMenu_CheckTag(u8 taskId)
{
    gBagMenu->newScreenCallback = DoBerryTagScreen;
    Task_FadeAndCloseBagMenu(taskId);
}

static void ItemMenu_Cancel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveContextWindow();
    PrintItemDescription(tListPosition);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void ItemMenu_UseInBattle(u8 taskId)
{
    if (GetItemBattleFunc(gSpecialVar_ItemId))
    {
        RemoveContextWindow();
        GetItemBattleFunc(gSpecialVar_ItemId)(taskId);
    }
}

void CB2_ReturnToBagMenuPocket(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, NULL);
}

static void Task_ItemContext_GiveToParty(u8 taskId)
{
    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    }
    else if (!IsHoldingItemAllowed(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, HandleErrorMessage);
    }
    else if (gBagPosition.pocket != KEYITEMS_POCKET && !GetItemImportance(gSpecialVar_ItemId))
    {
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        PrintItemCantBeHeld(taskId);
    }
}

// Selected item to give to a Pokémon in PC storage
static void Task_ItemContext_GiveToPC(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    else if (gBagPosition.pocket != KEYITEMS_POCKET && !GetItemImportance(gSpecialVar_ItemId))
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    else
        PrintItemCantBeHeld(taskId);
}

#define tUsingRegisteredKeyItem data[3] // See usage in item_use.c

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() == TRUE || InBattlePyramid() || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, BG_COORD_SET);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
        {
            LockPlayerFieldControls();
            FreezeObjectEvents();
            PlayerFreeze();
            StopPlayerAvatar();
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
            taskId = CreateTask(GetItemFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
            gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
            return TRUE;
        }
        else
        {
            gSaveBlock1Ptr->registeredItem = ITEM_NONE;
        }
    }
    ScriptContext_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

#undef tUsingRegisteredKeyItem

static void Task_ItemContext_Sell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (GetItemPrice(gSpecialVar_ItemId) == 0)
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
    }
    else
    {
        tItemCount = 1;
        if (tQuantity == 1)
        {
            DisplayCurrentMoneyWindow();
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            CopyItemName(gSpecialVar_ItemId, gStringVar2);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, InitSellHowManyInput);
        }
    }
}

static void DisplaySellItemPriceAndConfirm(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ConvertIntToDecimalStringN(gStringVar1, (GetItemPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, AskSellItems);
}

static void AskSellItems(u8 taskId)
{
    BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sYesNoSellItemFunctions);
}

static void CancelSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveMoneyWindow();
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
    ReturnToItemList(taskId);
}

static void InitSellHowManyInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowId = BagMenu_AddWindow(ITEMWIN_QUANTITY_WIDE);

    PrintItemSoldAmount(windowId, 1, (GetItemPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DisplayCurrentMoneyWindow();
    gTasks[taskId].func = Task_ChooseHowManyToSell;
}

static void Task_ChooseHowManyToSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintItemSoldAmount(gBagMenu->windowIds[ITEMWIN_QUANTITY_WIDE], tItemCount, (GetItemPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY_WIDE);
        DisplaySellItemPriceAndConfirm(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        RemoveMoneyWindow();
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY_WIDE);
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        ReturnToItemList(taskId);
    }
}

static void ConfirmSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    ConvertIntToDecimalStringN(gStringVar1, (GetItemPrice(gSpecialVar_ItemId) / 2) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, SellItem);
}

static void SellItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    PlaySE(SE_SHOP);
    RemoveBagItem(gSpecialVar_ItemId, tItemCount);
    AddMoney(&gSaveBlock1Ptr->money, (GetItemPrice(gSpecialVar_ItemId) / 2) * tItemCount);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
    PrintMoneyAmountInMoneyBox(gBagMenu->windowIds[ITEMWIN_MONEY], GetMoney(&gSaveBlock1Ptr->money), 0);
    gTasks[taskId].func = WaitAfterItemSell;
}

static void WaitAfterItemSell(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveMoneyWindow();
        CloseItemMessage(taskId);
    }
}

static void Task_ItemContext_Deposit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tItemCount = 1;
    if (tQuantity == 1)
    {
        TryDepositItem(taskId);
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gText_DepositHowManyVar1);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
        AddItemQuantityWindow(ITEMWIN_QUANTITY);
        gTasks[taskId].func = Task_ChooseHowManyToDeposit;
    }
}

static void Task_ChooseHowManyToDeposit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintItemQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        TryDepositItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        PrintItemDescription(tListPosition);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        ReturnToItemList(taskId);
    }
}

static void TryDepositItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    if (GetItemImportance(gSpecialVar_ItemId))
    {
        // Can't deposit important items
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gText_CantStoreImportantItems, 3, 4, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = WaitDepositErrorMessage;
    }
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount) == TRUE)
    {
        // Successfully deposited
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
        StringExpandPlaceholders(gStringVar4, gText_DepositedVar2Var1s);
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 4, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = Task_RemoveItemFromBag;
    }
    else
    {
        // No room to deposit
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gText_NoRoomForItems, 3, 4, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = WaitDepositErrorMessage;
    }
}

static void WaitDepositErrorMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        PrintItemDescription(tListPosition);
        BagMenu_PrintCursor(tListTaskId, COLORID_NORMAL);
        ReturnToItemList(taskId);
    }
}

static bool8 IsWallysBag(void)
{
    if (gBagPosition.location == ITEMMENULOCATION_WALLY)
        return TRUE;
    return FALSE;
}

static void PrepareBagForWallyTutorial(void)
{
    u32 i;

    sTempWallyBag = AllocZeroed(sizeof(*sTempWallyBag));
    memcpy(sTempWallyBag->bagPocket_Items, gSaveBlock1Ptr->bagPocket_Items, sizeof(gSaveBlock1Ptr->bagPocket_Items));
    memcpy(sTempWallyBag->bagPocket_PokeBalls, gSaveBlock1Ptr->bagPocket_PokeBalls, sizeof(gSaveBlock1Ptr->bagPocket_PokeBalls));
    sTempWallyBag->pocket = gBagPosition.pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        sTempWallyBag->cursorPosition[i] = gBagPosition.cursorPosition[i];
        sTempWallyBag->scrollPosition[i] = gBagPosition.scrollPosition[i];
    }
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_Items, BAG_ITEMS_COUNT);
    ClearItemSlots(gSaveBlock1Ptr->bagPocket_PokeBalls, BAG_POKEBALLS_COUNT);
    ResetBagScrollPositions();
}

static void RestoreBagAfterWallyTutorial(void)
{
    u32 i;

    memcpy(gSaveBlock1Ptr->bagPocket_Items, sTempWallyBag->bagPocket_Items, sizeof(sTempWallyBag->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bagPocket_PokeBalls, sTempWallyBag->bagPocket_PokeBalls, sizeof(sTempWallyBag->bagPocket_PokeBalls));
    gBagPosition.pocket = sTempWallyBag->pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        gBagPosition.cursorPosition[i] = sTempWallyBag->cursorPosition[i];
        gBagPosition.scrollPosition[i] = sTempWallyBag->scrollPosition[i];
    }
    Free(sTempWallyBag);
}

void DoWallyTutorialBagMenu(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(ITEMMENULOCATION_WALLY, ITEMS_POCKET, CB2_SetUpReshowBattleScreenAfterMenu2);
}

#define tTimer data[8]
#define WALLY_BAG_DELAY 102 // The number of frames between each action Wally takes in the bag

static void Task_WallyTutorialBagMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (tTimer)
        {
        case WALLY_BAG_DELAY * 1:
            PlaySE(SE_SELECT);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 2:
            PlaySE(SE_SELECT);
            BagMenu_PrintCursor(tListTaskId, COLORID_GRAY_CURSOR);
            gSpecialVar_ItemId = ITEM_POKE_BALL;
            OpenContextMenu(taskId);
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 3:
            PlaySE(SE_SELECT);
            RemoveContextWindow();
            DestroyListMenuTask(tListTaskId, 0, 0);
            RestoreBagAfterWallyTutorial();
            Task_FadeAndCloseBagMenu(taskId);
            break;
        default:
            tTimer++;
            break;
        }
    }
}

#undef tTimer

// This action is used to show the Apprentice an item when
// they ask what item they should make their Pokémon hold
static void ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_ApprenticeExitBagMenu(void)
{
    gFieldCallback = Apprentice_ScriptContext_Enable;
    SetMainCallback2(CB2_ReturnToField);
}

static void ItemMenu_GiveFavorLady(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_FavorLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_FavorLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

// This action is used to confirm which item to use as
// a prize for a custom quiz with the Lilycove Quiz Lady
static void ItemMenu_ConfirmQuizLady(u8 taskId)
{
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_QuizLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_QuizLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

static void PrintPocketNames(const u8 *pocketName1, const u8 *pocketName2)
{
    struct WindowTemplate window = {0};
    u16 windowId;
    int offset;

    window.width = 16;
    window.height = 2;
    windowId = AddWindow(&window);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    offset = GetStringCenterAlignXOffset(FONT_NORMAL, pocketName1, 0x40);
    BagMenu_Print(windowId, FONT_NORMAL, pocketName1, offset, 1, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    if (pocketName2)
    {
        offset = GetStringCenterAlignXOffset(FONT_NORMAL, pocketName2, 0x40);
        BagMenu_Print(windowId, FONT_NORMAL, pocketName2, offset + 0x40, 1, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    }
    CpuCopy32((u8 *)GetWindowAttribute(windowId, WINDOW_TILE_DATA), gBagMenu->pocketNameBuffer, sizeof(gBagMenu->pocketNameBuffer));
    RemoveWindow(windowId);
}

static void CopyPocketNameToWindow(u32 a)
{
    u8 (*tileDataBuffer)[32][32];
    u8 *windowTileData;
    int b;
    if (a > 8)
        a = 8;
    tileDataBuffer = &gBagMenu->pocketNameBuffer;
    windowTileData = (u8 *)GetWindowAttribute(2, WINDOW_TILE_DATA);
    CpuCopy32(&tileDataBuffer[0][a], windowTileData, 0x100); // Top half of pocket name
    b = a + 16;
    CpuCopy32(&tileDataBuffer[0][b], windowTileData + 0x100, 0x100); // Bottom half of pocket name
    CopyWindowToVram(WIN_POCKET_NAME, COPYWIN_GFX);
}

static void LoadBagMenuTextWindows(void)
{
    u8 i;

    InitWindows(sDefaultBagWindows);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadMessageBoxGfx(0, 10, BG_PLTT_ID(13));
    ListMenuLoadStdPalAt(BG_PLTT_ID(12), 1);
    LoadPalette(&gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    for (i = 0; i <= WIN_UPPER_2; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
}

static void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIndex)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[colorIndex], speed, str);
}

static u8 UNUSED BagMenu_GetWindowId(u8 windowType)
{
    return gBagMenu->windowIds[windowType];
}

static u8 BagMenu_AddWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId == WINDOW_NONE)
    {
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
        DrawStdFrameWithCustomTileAndPalette(*windowId, FALSE, 1, 14);
        ScheduleBgCopyTilemapToVram(1);
    }
    return *windowId;
}

static void BagMenu_RemoveWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(*windowId, FALSE);
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        ScheduleBgCopyTilemapToVram(1);
        *windowId = WINDOW_NONE;
    }
}

static u8 AddItemMessageWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId == WINDOW_NONE)
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
    return *windowId;
}

static void RemoveItemMessageWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId != WINDOW_NONE)
    {
        ClearDialogWindowAndFrameToTransparent(*windowId, FALSE);
        // This ClearWindowTilemap call is redundant, since ClearDialogWindowAndFrameToTransparent already calls it.
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        ScheduleBgCopyTilemapToVram(1);
        *windowId = WINDOW_NONE;
    }
}

void BagMenu_YesNo(u8 taskId, u8 windowType, const struct YesNoFuncTable *funcTable)
{
    CreateYesNoMenuWithCallbacks(taskId, &sContextMenuWindowTemplates[windowType], 1, 0, 2, 1, 14, funcTable);
}

static void DisplayCurrentMoneyWindow(void)
{
    u8 windowId = BagMenu_AddWindow(ITEMWIN_MONEY);
    PrintMoneyAmountInMoneyBoxWithBorder(windowId, 1, 14, GetMoney(&gSaveBlock1Ptr->money));
    AddMoneyLabelObject(19, 11);
}

static void RemoveMoneyWindow(void)
{
    BagMenu_RemoveWindow(ITEMWIN_MONEY);
    RemoveMoneyLabelObject();
}

static void PrepareTMHMMoveWindow(void)
{
    FillWindowPixelBuffer(WIN_TMHM_INFO_ICONS, PIXEL_FILL(0));
    BlitMenuInfoIcon(WIN_TMHM_INFO_ICONS, MENU_INFO_ICON_TYPE, 0, 0);
    BlitMenuInfoIcon(WIN_TMHM_INFO_ICONS, MENU_INFO_ICON_POWER, 0, 12);
    BlitMenuInfoIcon(WIN_TMHM_INFO_ICONS, MENU_INFO_ICON_ACCURACY, 0, 24);
    BlitMenuInfoIcon(WIN_TMHM_INFO_ICONS, MENU_INFO_ICON_PP, 0, 36);
    CopyWindowToVram(WIN_TMHM_INFO_ICONS, COPYWIN_GFX);
}

static void PrintTMHMMoveData(u16 itemId)
{
    u8 i;
    u16 move;
    const u8 *text;

    FillWindowPixelBuffer(WIN_TMHM_INFO, PIXEL_FILL(0));
    if (itemId == ITEM_NONE)
    {
        for (i = 0; i < 4; i++)
            BagMenu_Print(WIN_TMHM_INFO, FONT_NORMAL, gText_ThreeDashes, 7, i * 12, 0, 0, TEXT_SKIP_DRAW, COLORID_TMHM_INFO);
        CopyWindowToVram(WIN_TMHM_INFO, COPYWIN_GFX);
    }
    else
    {
        move = ItemIdToBattleMoveId(itemId);
        BlitMenuInfoIcon(WIN_TMHM_INFO, gBattleMoves[move].type + 1, 0, 0);

        // Print TMHM power
        if (gBattleMoves[move].power <= 1)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(WIN_TMHM_INFO, FONT_NORMAL, text, 7, 12, 0, 0, TEXT_SKIP_DRAW, COLORID_TMHM_INFO);

        // Print TMHM accuracy
        if (gBattleMoves[move].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            text = gStringVar1;
        }
        BagMenu_Print(WIN_TMHM_INFO, FONT_NORMAL, text, 7, 24, 0, 0, TEXT_SKIP_DRAW, COLORID_TMHM_INFO);

        // Print TMHM pp
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].pp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        BagMenu_Print(WIN_TMHM_INFO, FONT_NORMAL, gStringVar1, 7, 36, 0, 0, TEXT_SKIP_DRAW, COLORID_TMHM_INFO);

        CopyWindowToVram(WIN_TMHM_INFO, COPYWIN_GFX);
    }
}

// bag sorting
enum BagSortOptions
{
    SORT_ALPHABETICALLY,
    SORT_BY_TYPE,
    SORT_BY_AMOUNT, //greatest->least
    SORT_BY_ID, //greatest->least
    SORT_BY_LEVEL, //greatest->least
    SORT_BY_ATK, //greatest->least
    SORT_BY_DEF, //greatest->least
    SORT_BY_PRICE_YK, //greatest->least
    SORT_BY_PRICE_CRITTER, //greatest->least
    SORT_BY_PRICE_TREASURE, //greatest->least
    SORT_BY_PRICE_IMPERIAL, //greatest->least
    SORT_BY_PRICE_ANDROID, //greatest->least
    SORT_BY_PRICE_JP, //greatest->least
    SORT_BY_PRICE_FIBER, //greatest->least
    SORT_BY_PRICE_YATA, //greatest->least
    SORT_BY_PRICE_SCIENTIST, //greatest->least
    SORT_BY_PRICE_VAMPIRE, //greatest->least
    SORT_BY_PRICE_CHAOS, //greatest->least
    SORT_BY_PRICE_WARRIOR, //greatest->least
    SORT_BY_PRICE_GOAT, //greatest->least
    SORT_BY_PRICE_CYBER, //greatest->least
    SORT_BY_PRICE_REAPER, //greatest->least
    SORT_BY_PRICE_VENDOR_1, //greatest->least
    SORT_BY_PRICE_VENDOR_2, //greatest->least
    SORT_BY_PRICE_VENDOR_3, //greatest->least
};
enum ItemSortType
{
	ITEM_TYPE_FIELD_USE,
	ITEM_TYPE_HEALTH_RECOVERY,
	ITEM_TYPE_STATUS_RECOVERY,
	ITEM_TYPE_PP_RECOVERY,
	ITEM_TYPE_STAT_BOOST_DRINK,
	ITEM_TYPE_STAT_BOOST_FEATHER,
	ITEM_TYPE_EVOLUTION_STONE,
	ITEM_TYPE_EVOLUTION_ITEM,
	ITEM_TYPE_BATTLE_ITEM,
	ITEM_TYPE_FLUTE,
	ITEM_TYPE_STAT_BOOST_HELD_ITEM,
	ITEM_TYPE_HELD_ITEM,
	ITEM_TYPE_GEM,
	ITEM_TYPE_PLATE,
	ITEM_TYPE_MEMORY,
	ITEM_TYPE_DRIVE,
	ITEM_TYPE_INCENSE,
	ITEM_TYPE_MEGA_STONE,
	ITEM_TYPE_Z_CRYSTAL,
	ITEM_TYPE_NECTAR,
	ITEM_TYPE_SELLABLE,
	ITEM_TYPE_RELIC,
	ITEM_TYPE_SHARD,
	ITEM_TYPE_FOSSIL,
	ITEM_TYPE_MAIL,
};
static const u8 sText_SortItemsHow[] = _("Sort items how?");
static const u8 sText_Name[] = _("name");
static const u8 sText_Type[] = _("type");
static const u8 sText_Amount[] = _("amount");
static const u8 sText_Id[] = _("ID");
static const u8 sText_Level[] = _("level");
static const u8 sText_Atk[] = _("ATK");
static const u8 sText_Def[] = _("DEF");
static const u8 sText_PriceYK[] = _("Yugi-Kaiba");
static const u8 sText_PriceCritter[] = _("Critter");
static const u8 sText_PriceTreasure[] = _("Treasure");
static const u8 sText_PriceImperial[] = _("Imperial");
static const u8 sText_PriceAndroid[] = _("Android");
static const u8 sText_PriceJP[] = _("Joey-Pegasus");
static const u8 sText_PriceFiber[] = _("Fiber");
static const u8 sText_PriceYata[] = _("Yata");
static const u8 sText_PriceScientist[] = _("Scientist");
static const u8 sText_PriceVampire[] = _("Vampire");
static const u8 sText_PriceChaos[] = _("Chaos");
static const u8 sText_PriceWarrior[] = _("Warrior");
static const u8 sText_PriceGoat[] = _("Goat");
static const u8 sText_PriceCyber[] = _("Cyber");
static const u8 sText_PriceReaper[] = _("Reaper");
static const u8 sText_PriceVendor1[] = _("Vendor 1");
static const u8 sText_PriceVendor2[] = _("Vendor 2");
static const u8 sText_PriceVendor3[] = _("Vendor 3");
static const u8 sText_ItemsSorted[] = _("Items sorted by {STR_VAR_1}!");
static const u8 *const sSortTypeStrings[] = 
{
    [SORT_ALPHABETICALLY] = sText_Name,
    [SORT_BY_TYPE] = sText_Type,
    [SORT_BY_AMOUNT] = sText_Amount,
    [SORT_BY_ID] = sText_Id,
    [SORT_BY_LEVEL] = sText_Level,
    [SORT_BY_ATK] = sText_Atk,
    [SORT_BY_DEF] = sText_Def,
    [SORT_BY_PRICE_YK] = sText_PriceYK,
    [SORT_BY_PRICE_CRITTER] = sText_PriceCritter,
    [SORT_BY_PRICE_TREASURE] = sText_PriceTreasure,
    [SORT_BY_PRICE_IMPERIAL] = sText_PriceImperial,
    [SORT_BY_PRICE_ANDROID] = sText_PriceAndroid,
    [SORT_BY_PRICE_JP] = sText_PriceJP,
    [SORT_BY_PRICE_FIBER] = sText_PriceFiber,
    [SORT_BY_PRICE_YATA] = sText_PriceYata,
    [SORT_BY_PRICE_SCIENTIST] = sText_PriceScientist,
    [SORT_BY_PRICE_VAMPIRE] = sText_PriceVampire,
    [SORT_BY_PRICE_CHAOS] = sText_PriceChaos,
    [SORT_BY_PRICE_WARRIOR] = sText_PriceWarrior,
    [SORT_BY_PRICE_GOAT] = sText_PriceGoat,
    [SORT_BY_PRICE_CYBER] = sText_PriceCyber,
    [SORT_BY_PRICE_REAPER] = sText_PriceReaper,
    [SORT_BY_PRICE_VENDOR_1] = sText_PriceVendor1,
    [SORT_BY_PRICE_VENDOR_2] = sText_PriceVendor2,
    [SORT_BY_PRICE_VENDOR_3] = sText_PriceVendor3,
};

static const u8 sBagMenuSortItems[] =
{
    ACTION_BY_NAME,
    ACTION_BY_AMOUNT,
    ACTION_BY_ID,
    ACTION_BY_LEVEL,
    ACTION_BY_ATK,
    ACTION_BY_DEF,
    ACTION_BY_PRICE_YK,
    ACTION_BY_PRICE_CRITTER,
    ACTION_BY_PRICE_TREASURE,
    ACTION_BY_PRICE_IMPERIAL,
    ACTION_BY_PRICE_ANDROID,
    ACTION_BY_PRICE_JP,
    ACTION_BY_PRICE_FIBER,
    ACTION_BY_PRICE_YATA,
    ACTION_BY_PRICE_SCIENTIST,
    ACTION_BY_PRICE_VAMPIRE,
    ACTION_BY_PRICE_CHAOS,
    ACTION_BY_PRICE_WARRIOR,
    ACTION_BY_PRICE_GOAT,
    ACTION_BY_PRICE_CYBER,
    ACTION_BY_PRICE_REAPER,
    ACTION_BY_PRICE_VENDOR_1,
    ACTION_BY_PRICE_VENDOR_2,
    ACTION_BY_PRICE_VENDOR_3,
};

static const u8 sBagMenuSortKeyItems[] =
{
    ACTION_BY_NAME,
    ACTION_CANCEL,
};

static const u8 sBagMenuSortPokeBallsBerries[] =
{
    ACTION_BY_NAME,
    ACTION_BY_AMOUNT,
    ACTION_DUMMY,
    ACTION_CANCEL,
};

static const u16 sItemsByType[ITEMS_COUNT] =
{
    [ITEM_REPEL] = ITEM_TYPE_FIELD_USE,
    [ITEM_SUPER_REPEL] = ITEM_TYPE_FIELD_USE,
    [ITEM_MAX_REPEL] = ITEM_TYPE_FIELD_USE,
    [ITEM_ESCAPE_ROPE] = ITEM_TYPE_FIELD_USE,
    [ITEM_HEART_SCALE] = ITEM_TYPE_FIELD_USE,

    [ITEM_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_FULL_RESTORE] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_MAX_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_HYPER_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_SUPER_POTION] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_REVIVE] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_MAX_REVIVE] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_FRESH_WATER] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_SODA_POP] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_LEMONADE] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_MOOMOO_MILK] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_ENERGY_POWDER] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_ENERGY_ROOT] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_REVIVAL_HERB] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_BERRY_JUICE] = ITEM_TYPE_HEALTH_RECOVERY,
    [ITEM_SACRED_ASH] = ITEM_TYPE_HEALTH_RECOVERY,

    [ITEM_ANTIDOTE] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_BURN_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_ICE_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_AWAKENING] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_PARALYZE_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_FULL_HEAL] = ITEM_TYPE_STATUS_RECOVERY,
    [ITEM_LAVA_COOKIE] = ITEM_TYPE_STATUS_RECOVERY,
    
    [ITEM_ETHER] = ITEM_TYPE_PP_RECOVERY,
    [ITEM_MAX_ETHER] = ITEM_TYPE_PP_RECOVERY,
    [ITEM_ELIXIR] = ITEM_TYPE_PP_RECOVERY,
    [ITEM_MAX_ELIXIR] = ITEM_TYPE_PP_RECOVERY,

    [ITEM_HP_UP] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_PROTEIN] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_IRON] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_CARBOS] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_CALCIUM] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_RARE_CANDY] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_PP_UP] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_ZINC] = ITEM_TYPE_STAT_BOOST_DRINK,
    [ITEM_PP_MAX] = ITEM_TYPE_STAT_BOOST_DRINK,
    
    [ITEM_MACHO_BRACE] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,

    [ITEM_SUN_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    [ITEM_MOON_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    [ITEM_FIRE_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    [ITEM_THUNDER_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    [ITEM_WATER_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    [ITEM_LEAF_STONE] = ITEM_TYPE_EVOLUTION_STONE,
    
    [ITEM_KINGS_ROCK] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_DEEP_SEA_TOOTH] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_DEEP_SEA_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_EVERSTONE] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_METAL_COAT] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_DRAGON_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
    [ITEM_UP_GRADE] = ITEM_TYPE_EVOLUTION_ITEM,
    
    [ITEM_GUARD_SPEC] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_DIRE_HIT] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_X_ATTACK] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_X_DEFEND] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_X_SPEED] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_X_ACCURACY] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_X_SPECIAL] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_POKE_DOLL] = ITEM_TYPE_BATTLE_ITEM,
    [ITEM_FLUFFY_TAIL] = ITEM_TYPE_BATTLE_ITEM,

    [ITEM_BRIGHT_POWDER] = ITEM_TYPE_HELD_ITEM,
    [ITEM_WHITE_HERB] = ITEM_TYPE_HELD_ITEM,
    [ITEM_EXP_SHARE] = ITEM_TYPE_HELD_ITEM,
    [ITEM_QUICK_CLAW] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SOOTHE_BELL] = ITEM_TYPE_HELD_ITEM,
    [ITEM_MENTAL_HERB] = ITEM_TYPE_HELD_ITEM,
    [ITEM_CHOICE_BAND] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SILVER_POWDER] = ITEM_TYPE_HELD_ITEM,
    [ITEM_AMULET_COIN] = ITEM_TYPE_HELD_ITEM,
    [ITEM_CLEANSE_TAG] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SOUL_DEW] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SMOKE_BALL] = ITEM_TYPE_HELD_ITEM,
    [ITEM_FOCUS_BAND] = ITEM_TYPE_HELD_ITEM,
    [ITEM_LUCKY_EGG] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SCOPE_LENS] = ITEM_TYPE_HELD_ITEM,
    [ITEM_LEFTOVERS] = ITEM_TYPE_HELD_ITEM,
    [ITEM_LIGHT_BALL] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SOFT_SAND] = ITEM_TYPE_HELD_ITEM,
    [ITEM_HARD_STONE] = ITEM_TYPE_HELD_ITEM,
    [ITEM_MIRACLE_SEED] = ITEM_TYPE_HELD_ITEM,
    [ITEM_BLACK_GLASSES] = ITEM_TYPE_HELD_ITEM,
    [ITEM_BLACK_BELT] = ITEM_TYPE_HELD_ITEM,
    [ITEM_MAGNET] = ITEM_TYPE_HELD_ITEM,
    [ITEM_MYSTIC_WATER] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SHARP_BEAK] = ITEM_TYPE_HELD_ITEM,
    [ITEM_POISON_BARB] = ITEM_TYPE_HELD_ITEM,
    [ITEM_NEVER_MELT_ICE] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SPELL_TAG] = ITEM_TYPE_HELD_ITEM,
    [ITEM_TWISTED_SPOON] = ITEM_TYPE_HELD_ITEM,
    [ITEM_CHARCOAL] = ITEM_TYPE_HELD_ITEM,
    [ITEM_DRAGON_FANG] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SILK_SCARF] = ITEM_TYPE_HELD_ITEM,
    [ITEM_SHELL_BELL] = ITEM_TYPE_HELD_ITEM,
    [ITEM_LUCKY_PUNCH] = ITEM_TYPE_HELD_ITEM,
    [ITEM_METAL_POWDER] = ITEM_TYPE_HELD_ITEM,
    [ITEM_THICK_CLUB] = ITEM_TYPE_HELD_ITEM,
    [ITEM_STICK] = ITEM_TYPE_HELD_ITEM,
    
    [ITEM_SEA_INCENSE] = ITEM_TYPE_INCENSE,
    [ITEM_LAX_INCENSE] = ITEM_TYPE_INCENSE,
    
    [ITEM_RED_ORB] = ITEM_TYPE_MEGA_STONE,
    [ITEM_BLUE_ORB] = ITEM_TYPE_MEGA_STONE,
    
    [ITEM_BLUE_FLUTE] = ITEM_TYPE_FLUTE,
    [ITEM_YELLOW_FLUTE] = ITEM_TYPE_FLUTE,
    [ITEM_RED_FLUTE] = ITEM_TYPE_FLUTE,
    [ITEM_BLACK_FLUTE] = ITEM_TYPE_FLUTE,
    [ITEM_WHITE_FLUTE] = ITEM_TYPE_FLUTE,
    
    [ITEM_SHOAL_SALT] = ITEM_TYPE_SELLABLE,
    [ITEM_SHOAL_SHELL] = ITEM_TYPE_SELLABLE,
    [ITEM_TINY_MUSHROOM] = ITEM_TYPE_SELLABLE,
    [ITEM_BIG_MUSHROOM] = ITEM_TYPE_SELLABLE,
    [ITEM_PEARL] = ITEM_TYPE_SELLABLE,
    [ITEM_BIG_PEARL] = ITEM_TYPE_SELLABLE,
    [ITEM_STARDUST] = ITEM_TYPE_SELLABLE,
    [ITEM_STAR_PIECE] = ITEM_TYPE_SELLABLE,
    [ITEM_NUGGET] = ITEM_TYPE_SELLABLE,
   
    [ITEM_RED_SHARD] = ITEM_TYPE_SHARD,
    [ITEM_BLUE_SHARD] = ITEM_TYPE_SHARD,
    [ITEM_YELLOW_SHARD] = ITEM_TYPE_SHARD,
    [ITEM_GREEN_SHARD] = ITEM_TYPE_SHARD,

    [ITEM_HELIX_FOSSIL] = ITEM_TYPE_FOSSIL,
    [ITEM_DOME_FOSSIL] = ITEM_TYPE_FOSSIL,
    [ITEM_OLD_AMBER] = ITEM_TYPE_FOSSIL,

    [ITEM_ORANGE_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_HARBOR_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_GLITTER_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_MECH_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_WOOD_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_WAVE_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_BEAD_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_SHADOW_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_TROPIC_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_DREAM_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_FAB_MAIL] = ITEM_TYPE_MAIL,
    [ITEM_RETRO_MAIL] = ITEM_TYPE_MAIL,
    
    #ifdef ITEM_EXPANSION
        [ITEM_HONEY] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_BIG_MALASADA] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_CASTELIACONE] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_LUMIOSE_GALETTE] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_RAGE_CANDY_BAR] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_SHALOUR_SABLE] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_OLD_GATEAU] = ITEM_TYPE_STATUS_RECOVERY,
        [ITEM_HEAL_POWDER] = ITEM_TYPE_STATUS_RECOVERY,
        
        [ITEM_SWEET_HEART] = ITEM_TYPE_HEALTH_RECOVERY,
        
        [ITEM_ADAMANT_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_LUSTROUS_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_GRISEOUS_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_EXPERT_BELT] = ITEM_TYPE_HELD_ITEM,
        [ITEM_POWER_HERB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_WIDE_LENS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ZOOM_LENS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_DESTINY_KNOT] = ITEM_TYPE_HELD_ITEM,
        [ITEM_SMOOTH_ROCK] = ITEM_TYPE_HELD_ITEM,
        [ITEM_DAMP_ROCK] = ITEM_TYPE_HELD_ITEM,
        [ITEM_HEAT_ROCK] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ICY_ROCK] = ITEM_TYPE_HELD_ITEM,
        [ITEM_BIG_ROOT] = ITEM_TYPE_HELD_ITEM,
        [ITEM_LIGHT_CLAY] = ITEM_TYPE_HELD_ITEM,
        [ITEM_SAFETY_GOGGLES] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ROCKY_HELMET] = ITEM_TYPE_HELD_ITEM,
        [ITEM_WEAKNESS_POLICY] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ASSAULT_VEST] = ITEM_TYPE_HELD_ITEM,
        [ITEM_EVIOLITE] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ABSORB_BULB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_AIR_BALLOON] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ADRENALINE_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_BINDING_BAND] = ITEM_TYPE_HELD_ITEM,
        [ITEM_CELL_BATTERY] = ITEM_TYPE_HELD_ITEM,
        [ITEM_EJECT_BUTTON] = ITEM_TYPE_HELD_ITEM,
        [ITEM_FLOAT_STONE] = ITEM_TYPE_HELD_ITEM,
        [ITEM_FOCUS_SASH] = ITEM_TYPE_HELD_ITEM,
        [ITEM_GRIP_CLAW] = ITEM_TYPE_HELD_ITEM,
        [ITEM_IRON_BALL] = ITEM_TYPE_HELD_ITEM,
        [ITEM_LAGGING_TAIL] = ITEM_TYPE_HELD_ITEM,
        [ITEM_LUMINOUS_MOSS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_QUICK_POWDER] = ITEM_TYPE_HELD_ITEM,
        [ITEM_METRONOME] = ITEM_TYPE_HELD_ITEM,
        [ITEM_MUSCLE_BAND] = ITEM_TYPE_HELD_ITEM,
        [ITEM_PROTECTIVE_PADS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_RED_CARD] = ITEM_TYPE_HELD_ITEM,
        [ITEM_RING_TARGET] = ITEM_TYPE_HELD_ITEM,
        [ITEM_SHED_SHELL] = ITEM_TYPE_HELD_ITEM,
        [ITEM_SNOWBALL] = ITEM_TYPE_HELD_ITEM,
        [ITEM_STICKY_BARB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_TERRAIN_EXTENDER] = ITEM_TYPE_HELD_ITEM,
        [ITEM_WISE_GLASSES] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ELECTRIC_SEED] = ITEM_TYPE_HELD_ITEM,
        [ITEM_GRASSY_SEED] = ITEM_TYPE_HELD_ITEM,
        [ITEM_MISTY_SEED] = ITEM_TYPE_HELD_ITEM,
        [ITEM_PSYCHIC_SEED] = ITEM_TYPE_HELD_ITEM,
        [ITEM_LIFE_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_TOXIC_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_FLAME_ORB] = ITEM_TYPE_HELD_ITEM,
        [ITEM_BLACK_SLUDGE] = ITEM_TYPE_HELD_ITEM,
        [ITEM_CHOICE_SPECS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_CHOICE_SCARF] = ITEM_TYPE_HELD_ITEM,
        [ITEM_EJECT_PACK] = ITEM_TYPE_HELD_ITEM,
        [ITEM_ROOM_SERVICE] = ITEM_TYPE_HELD_ITEM,
        [ITEM_BLUNDER_POLICY] = ITEM_TYPE_HELD_ITEM,
        [ITEM_HEAVY_DUTY_BOOTS] = ITEM_TYPE_HELD_ITEM,
        [ITEM_UTILITY_UMBRELLA] = ITEM_TYPE_HELD_ITEM,
        [ITEM_THROAT_SPRAY] = ITEM_TYPE_HELD_ITEM,
        [ITEM_FIST_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_SKY_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_TOXIC_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_EARTH_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_STONE_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_INSECT_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_SPOOKY_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_IRON_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_FLAME_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_SPLASH_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_MEADOW_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_ZAP_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_MIND_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_ICICLE_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_DRACO_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_DREAD_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_PIXIE_PLATE] = ITEM_TYPE_PLATE,
        [ITEM_FIGHTING_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_FLYING_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_POISON_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_GROUND_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_ROCK_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_BUG_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_GHOST_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_STEEL_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_FIRE_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_WATER_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_GRASS_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_ELECTRIC_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_PSYCHIC_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_ICE_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_DRAGON_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_DARK_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_FAIRY_MEMORY] = ITEM_TYPE_MEMORY,
        [ITEM_BURN_DRIVE] = ITEM_TYPE_DRIVE,
        [ITEM_DOUSE_DRIVE] = ITEM_TYPE_DRIVE,
        [ITEM_SHOCK_DRIVE] = ITEM_TYPE_DRIVE,
        [ITEM_CHILL_DRIVE] = ITEM_TYPE_DRIVE,
        [ITEM_NORMAL_GEM] = ITEM_TYPE_GEM,
        [ITEM_FIGHTING_GEM] = ITEM_TYPE_GEM,
        [ITEM_FLYING_GEM] = ITEM_TYPE_GEM,
        [ITEM_POISON_GEM] = ITEM_TYPE_GEM,
        [ITEM_GROUND_GEM] = ITEM_TYPE_GEM,
        [ITEM_ROCK_GEM] = ITEM_TYPE_GEM,
        [ITEM_BUG_GEM] = ITEM_TYPE_GEM,
        [ITEM_GHOST_GEM] = ITEM_TYPE_GEM,
        [ITEM_STEEL_GEM] = ITEM_TYPE_GEM,
        [ITEM_FIRE_GEM] = ITEM_TYPE_GEM,
        [ITEM_WATER_GEM] = ITEM_TYPE_GEM,
        [ITEM_GRASS_GEM] = ITEM_TYPE_GEM,
        [ITEM_ELECTRIC_GEM] = ITEM_TYPE_GEM,
        [ITEM_PSYCHIC_GEM] = ITEM_TYPE_GEM,
        [ITEM_ICE_GEM] = ITEM_TYPE_GEM,
        [ITEM_DRAGON_GEM] = ITEM_TYPE_GEM,
        [ITEM_DARK_GEM] = ITEM_TYPE_GEM,
        [ITEM_FAIRY_GEM] = ITEM_TYPE_GEM,
        
        [ITEM_LUCK_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_FULL_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_ODD_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_PURE_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_ROCK_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_ROSE_INCENSE] = ITEM_TYPE_INCENSE,
        [ITEM_WAVE_INCENSE] = ITEM_TYPE_INCENSE,
        
        [ITEM_VENUSAURITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_CHARIZARDITE_X] = ITEM_TYPE_MEGA_STONE,
        [ITEM_CHARIZARDITE_Y] = ITEM_TYPE_MEGA_STONE,
        [ITEM_BLASTOISINITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_BEEDRILLITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_PIDGEOTITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_ALAKAZITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SLOWBRONITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GENGARITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_KANGASKHANITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_PINSIRITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GYARADOSITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_AERODACTYLITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_MEWTWONITE_X] = ITEM_TYPE_MEGA_STONE,
        [ITEM_MEWTWONITE_Y] = ITEM_TYPE_MEGA_STONE,
        [ITEM_AMPHAROSITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_STEELIXITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SCIZORITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_HERACRONITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_HOUNDOOMINITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_TYRANITARITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SCEPTILITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_BLAZIKENITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SWAMPERTITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GARDEVOIRITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SABLENITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_MAWILITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_AGGRONITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_MEDICHAMITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_MANECTITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SHARPEDONITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_CAMERUPTITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_ALTARIANITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_BANETTITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_ABSOLITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GLALITITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_SALAMENCITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_METAGROSSITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_LATIASITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_LATIOSITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_LOPUNNITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GARCHOMPITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_LUCARIONITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_ABOMASITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_GALLADITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_AUDINITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_DIANCITE] = ITEM_TYPE_MEGA_STONE,
        [ITEM_ULTRANECROZIUM_Z] =  ITEM_TYPE_MEGA_STONE,
        
        [ITEM_NORMALIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_FIGHTINIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_FLYINIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_POISONIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_GROUNDIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_ROCKIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_BUGINIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_GHOSTIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_STEELIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_FIRIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_WATERIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_GRASSIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_ELECTRIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_PSYCHIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_ICIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_DRAGONIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_DARKINIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_FAIRIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_ALORAICHIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_DECIDIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_EEVIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_INCINIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_KOMMONIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_LUNALIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_LYCANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_MARSHADIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_MEWNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_MIMIKIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_PIKANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_PIKASHUNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_PRIMARIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_SNORLIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_SOLGANIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        [ITEM_TAPUNIUM_Z] = ITEM_TYPE_Z_CRYSTAL,
        
        [ITEM_RED_NECTAR] = ITEM_TYPE_NECTAR,
        [ITEM_YELLOW_NECTAR] = ITEM_TYPE_NECTAR,
        [ITEM_PINK_NECTAR] = ITEM_TYPE_NECTAR,
        [ITEM_PURPLE_NECTAR] = ITEM_TYPE_NECTAR,
        
        [ITEM_ABILITY_CAPSULE] = ITEM_TYPE_STAT_BOOST_DRINK,
        [ITEM_HEALTH_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_MUSCLE_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_RESIST_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_GENIUS_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_CLEVER_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_SWIFT_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        [ITEM_PRETTY_FEATHER] = ITEM_TYPE_STAT_BOOST_FEATHER,
        
        [ITEM_POWER_BRACER] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        [ITEM_POWER_BELT] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        [ITEM_POWER_LENS] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        [ITEM_POWER_BAND] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        [ITEM_POWER_ANKLET] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        [ITEM_POWER_WEIGHT] = ITEM_TYPE_STAT_BOOST_HELD_ITEM,
        
        [ITEM_DAWN_STONE] = ITEM_TYPE_EVOLUTION_STONE,
        [ITEM_DUSK_STONE] = ITEM_TYPE_EVOLUTION_STONE,
        [ITEM_SHINY_STONE] = ITEM_TYPE_EVOLUTION_STONE,
        [ITEM_ICE_STONE] = ITEM_TYPE_EVOLUTION_STONE,
        [ITEM_OVAL_STONE] = ITEM_TYPE_EVOLUTION_STONE,
        
        [ITEM_PROTECTOR] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_MAGMARIZER] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_PRISM_SCALE] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_SACHET] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_WHIPPED_DREAM] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_RAZOR_CLAW] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_RAZOR_FANG] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_REAPER_CLOTH] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_DUBIOUS_DISC] = ITEM_TYPE_EVOLUTION_ITEM,
        [ITEM_ELECTIRIZER] = ITEM_TYPE_EVOLUTION_ITEM,
        
        [ITEM_RARE_BONE] = ITEM_TYPE_SELLABLE,
        [ITEM_PEARL_STRING] = ITEM_TYPE_SELLABLE,
        [ITEM_BIG_NUGGET] = ITEM_TYPE_SELLABLE,
        [ITEM_COMET_SHARD] = ITEM_TYPE_SELLABLE,
        [ITEM_BALM_MUSHROOM] = ITEM_TYPE_SELLABLE,
        [ITEM_ODD_KEYSTONE] = ITEM_TYPE_SELLABLE,
        [ITEM_BOTTLE_CAP] = ITEM_TYPE_SELLABLE,
        [ITEM_GOLD_BOTTLE_CAP] = ITEM_TYPE_SELLABLE,
        [ITEM_WISHING_PIECE] = ITEM_TYPE_SELLABLE,
        [ITEM_RELIC_COPPER] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_SILVER] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_GOLD] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_VASE] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_BAND] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_STATUE] = ITEM_TYPE_RELIC,
        [ITEM_RELIC_CROWN] = ITEM_TYPE_RELIC,
        
        [ITEM_ROOT_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_CLAW_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_SKULL_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_ARMOR_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_COVER_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_PLUME_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_JAW_FOSSIL] = ITEM_TYPE_FOSSIL,
        [ITEM_SAIL_FOSSIL] = ITEM_TYPE_FOSSIL,
    #endif
};

static void AddBagSortSubMenu(void)
{
    switch (gBagPosition.pocket + 1)
    {
        case POCKET_KEY_ITEMS:
            gBagMenu->contextMenuItemsPtr = sBagMenuSortKeyItems;
            memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortKeyItems, NELEMS(sBagMenuSortKeyItems));
            gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortKeyItems);
            break;
        case POCKET_POKE_BALLS:
        case POCKET_BERRIES:
        case POCKET_TM_HM:
            gBagMenu->contextMenuItemsPtr = sBagMenuSortPokeBallsBerries;
            memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortPokeBallsBerries, NELEMS(sBagMenuSortPokeBallsBerries));
            gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortPokeBallsBerries);
            break;
        default:
            gBagMenu->contextMenuItemsPtr = sBagMenuSortItems;
            memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortItems, NELEMS(sBagMenuSortItems));
            gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortItems);
            break;
    }
    
    StringExpandPlaceholders(gStringVar4, sText_SortItemsHow);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);
    
    if (gBagMenu->contextMenuNumItems == 2)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x2));
    else if (gBagMenu->contextMenuNumItems <= 4)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x2), 2, 2);
    else if (gBagMenu->contextMenuNumItems <= 6)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x3), 2, 3);
    else
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_3x8), 3, 8);
}

static void Task_LoadBagSortOptions(u8 taskId)
{
    AddBagSortSubMenu();
    if (gBagMenu->contextMenuNumItems <= 2)
        gTasks[taskId].func = Task_ItemContext_SingleRow;
    else
        gTasks[taskId].func = Task_ItemContext_MultipleRows;
}

#define tSortType data[2]
static void ItemMenu_SortByName(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_ALPHABETICALLY;
    StringCopy(gStringVar1, sSortTypeStrings[SORT_ALPHABETICALLY]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByType(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_TYPE;
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_TYPE]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByAmount(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_AMOUNT; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_AMOUNT]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortById(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_ID; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_ID]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByLevel(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_LEVEL; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_LEVEL]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByAtk(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_ATK; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_ATK]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByDef(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_DEF; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_DEF]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceYK(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_YK; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_YK]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceCritter(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_CRITTER; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_CRITTER]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceTreasure(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_TREASURE; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_TREASURE]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceImperial(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_IMPERIAL; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_IMPERIAL]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceAndroid(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_ANDROID; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_ANDROID]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceJP(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_JP; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_JP]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceFiber(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_FIBER; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_FIBER]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceYata(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_YATA; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_YATA]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceScientist(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_SCIENTIST; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_SCIENTIST]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceVampire(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_VAMPIRE; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_VAMPIRE]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceChaos(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_CHAOS; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_CHAOS]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceWarrior(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_WARRIOR; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_WARRIOR]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceGoat(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_GOAT; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_GOAT]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceCyber(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_CYBER; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_CYBER]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceReaper(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_REAPER; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_REAPER]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceVendor1(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_VENDOR_1; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_VENDOR_1]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceVendor2(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_VENDOR_2; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_VENDOR_2]);
    gTasks[taskId].func = SortBagItems;
}
static void ItemMenu_SortByPriceVendor3(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_PRICE_VENDOR_3; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_PRICE_VENDOR_3]);
    gTasks[taskId].func = SortBagItems;
}

static void SortBagItems(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    RemoveContextWindow();
    
    SortItemsInBag(gBagPosition.pocket, tSortType);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(0);

    StringCopy(gStringVar1, sSortTypeStrings[tSortType]);
    StringExpandPlaceholders(gStringVar4, sText_ItemsSorted);
    DisplayItemMessage(taskId, 1, gStringVar4, Task_SortFinish);
}

static void Task_SortFinish(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        ReturnToItemList(taskId);
    }
}

static void SortItemsInBag(u8 pocket, u8 type)
{
    struct ItemSlot* itemMem;
    u8 itemAmount;
    s8 (*func)(struct ItemSlot*, struct ItemSlot*);

    switch (pocket)
    {
    case ITEMS_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_Items;
        itemAmount = BAG_ITEMS_COUNT;
        break;
    case TRUNK_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_Trunk;
        itemAmount = BAG_TRUNK_COUNT;
        break;
    case MAIN_DECK_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_MainDeck;
        itemAmount = BAG_MAIN_DECK_COUNT;
        break;
    case EXTRA_DECK_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_ExtraDeck;
        itemAmount = BAG_EXTRA_DECK_COUNT;
        break;
    case SIDE_DECK_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_SideDeck;
        itemAmount = BAG_SIDE_DECK_COUNT;
        break;
    case KEYITEMS_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_KeyItems;
        itemAmount = BAG_KEYITEMS_COUNT;
        break;
    case BALLS_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_PokeBalls;
        itemAmount = BAG_POKEBALLS_COUNT;
        break;
    case BERRIES_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_Berries;
        itemAmount = BAG_BERRIES_COUNT;
        break;
    case TMHM_POCKET:
        itemMem = gSaveBlock1Ptr->bagPocket_TMHM;
        itemAmount = BAG_TMHM_COUNT;
        break;
    default:
        return;
    }

    switch (type)
    {
    case SORT_ALPHABETICALLY:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsAlphabetically);
        break;
    case SORT_BY_AMOUNT:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByMost);
        break;
    case SORT_BY_ID:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsById);
        break;
    case SORT_BY_LEVEL:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByLevel);
        break;
    case SORT_BY_ATK:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByAtk);
        break;
    case SORT_BY_DEF:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByDef);
        break;
    case SORT_BY_PRICE_YK:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceYK);
        break;
    case SORT_BY_PRICE_CRITTER:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceCritter);
        break;
    case SORT_BY_PRICE_TREASURE:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceTreasure);
        break;
    case SORT_BY_PRICE_IMPERIAL:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceImperial);
        break;
    case SORT_BY_PRICE_ANDROID:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceAndroid);
        break;
    case SORT_BY_PRICE_JP:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceJP);
        break;
    case SORT_BY_PRICE_FIBER:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceFiber);
        break;
    case SORT_BY_PRICE_YATA:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceYata);
        break;
    case SORT_BY_PRICE_SCIENTIST:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceScientist);
        break;
    case SORT_BY_PRICE_VAMPIRE:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceVampire);
        break;
    case SORT_BY_PRICE_CHAOS:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceChaos);
        break;
    case SORT_BY_PRICE_WARRIOR:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceWarrior);
        break;
    case SORT_BY_PRICE_GOAT:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceGoat);
        break;
    case SORT_BY_PRICE_CYBER:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceCyber);
        break;
    case SORT_BY_PRICE_REAPER:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceReaper);
        break;
    case SORT_BY_PRICE_VENDOR_1:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceVendor1);
        break;
    case SORT_BY_PRICE_VENDOR_2:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceVendor2);
        break;
    case SORT_BY_PRICE_VENDOR_3:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByPriceVendor3);
        break;
    default:
        MergeSort(itemMem, 0, itemAmount - 1, CompareItemsByType);
        break;
    }
}

static void MergeSort(struct ItemSlot* array, u32 low, u32 high, s8 (*comparator)(struct ItemSlot*, struct ItemSlot*))
{
    u32 mid;
    
    if (high <= low)
        return;

    mid = low + (high - low) / 2;
    MergeSort(array, low, mid, comparator); //Sort left half.
    MergeSort(array, mid + 1, high, comparator); //Sort right half.
    Merge(array, low, mid, high, comparator); //Merge results.
}

static void Merge(struct ItemSlot* array, u32 low, u32 mid, u32 high, s8 (*comparator)(struct ItemSlot*, struct ItemSlot*))
{
    u32 i = low;
    u32 j = mid + 1;
    u32 k;
    struct ItemSlot aux[high + 1];

    for (k = low; k <= high; ++k)
        aux[k] = array[k];

    for (k = low; k <= high; ++k)
    { //Merge back to a[low..high]
        if (i > mid)
            array[k] = aux[j++];
        else if (j > high)
            array[k] = aux[i++];
        else if (comparator(&aux[j], &aux[i]) < 0)
            array[k] = aux[j++];
        else
            array[k] = aux[i++];
    }
}

static s8 CompareItemsAlphabetically(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    int i;
    const u8 *name1;
    const u8 *name2;

    if (item1 == ITEM_NONE)
        return 1;
    else if (item2 == ITEM_NONE)
        return -1;

    name1 = GetItemName(item1);
    name2 = GetItemName(item2);

    for (i = 0; ; ++i)
    {
        if (name1[i] == EOS && name2[i] != EOS)
            return -1;
        else if (name1[i] != EOS && name2[i] == EOS)
            return 1;
        else if (name1[i] == EOS && name2[i] == EOS)
            return 0;

        if (name1[i] < name2[i])
            return -1;
        else if (name1[i] > name2[i])
            return 1;
    }

    return 0; //Will never be reached
}

static s8 CompareItemsById(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 id1;
    u16 id2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    id1 = gCardInfo[card1].id;
    id2 = gCardInfo[card2].id;

    if (id1 < id2)
        return -1;
    else if (id1 > id2)
        return 1;

    return 0; //Will never be reached
}

static s8 CompareItemsByLevel(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].level;
    price2 = gCardInfo[card2].level;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByAtk(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].atk;
    price2 = gCardInfo[card2].atk;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByDef(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].def;
    price2 = gCardInfo[card2].def;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceYK(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceYK;
    price2 = gCardInfo[card2].priceYK;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceCritter(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceCritter;
    price2 = gCardInfo[card2].priceCritter;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceTreasure(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceTreasure;
    price2 = gCardInfo[card2].priceTreasure;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceImperial(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceImperial;
    price2 = gCardInfo[card2].priceImperial;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceAndroid(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceAndroid;
    price2 = gCardInfo[card2].priceAndroid;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceJP(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceJoeyPegasus;
    price2 = gCardInfo[card2].priceJoeyPegasus;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceFiber(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceFiber;
    price2 = gCardInfo[card2].priceFiber;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceYata(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceYata;
    price2 = gCardInfo[card2].priceYata;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceScientist(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceScientist;
    price2 = gCardInfo[card2].priceScientist;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceVampire(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceVampire;
    price2 = gCardInfo[card2].priceVampire;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceChaos(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceChaos;
    price2 = gCardInfo[card2].priceChaos;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceWarrior(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceWarrior;
    price2 = gCardInfo[card2].priceWarrior;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceGoat(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceGoat;
    price2 = gCardInfo[card2].priceGoat;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceCyber(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceCyber;
    price2 = gCardInfo[card2].priceCyber;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceReaper(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].priceReaper;
    price2 = gCardInfo[card2].priceReaper;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceVendor1(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].price1;
    price2 = gCardInfo[card2].price1;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceVendor2(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].price2;
    price2 = gCardInfo[card2].price2;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByPriceVendor3(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 item1 = itemSlot1->itemId;
    u16 item2 = itemSlot2->itemId;
    u16 card1 = CardIdMapping[item1];
    u16 card2 = CardIdMapping[item2];
    u16 price1;
    u16 price2;

    if (item1 < 377)
        return 1;
    else if (item2 < 377)
        return -1;

    price1 = gCardInfo[card1].price3;
    price2 = gCardInfo[card2].price3;

    if (price1 < price2)
        return 1;
    else if (price1 > price2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same price so sort alphabetically
}

static s8 CompareItemsByMost(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    u16 quantity1 = GetBagItemQuantity(&itemSlot1->quantity);
    u16 quantity2 = GetBagItemQuantity(&itemSlot2->quantity);

    if (itemSlot1->itemId == ITEM_NONE)
        return 1;
    else if (itemSlot2->itemId == ITEM_NONE)
        return -1;

    if (quantity1 < quantity2)
        return 1;
    else if (quantity1 > quantity2)
        return -1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items have same quantity so sort alphabetically
}

static s8 CompareItemsByType(struct ItemSlot* itemSlot1, struct ItemSlot* itemSlot2)
{
    //Null items go last
    u8 type1 = (itemSlot1->itemId == ITEM_NONE) ? 0xFF : sItemsByType[itemSlot1->itemId];
    u8 type2 = (itemSlot2->itemId == ITEM_NONE) ? 0xFF : sItemsByType[itemSlot2->itemId];

    if (type1 < type2)
        return -1;
    else if (type1 > type2)
        return 1;

    return CompareItemsAlphabetically(itemSlot1, itemSlot2); //Items are of same type so sort alphabetically
}

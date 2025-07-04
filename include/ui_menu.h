#ifndef GUARD_UI_MENU_H
#define GUARD_UI_MENU_H

#include "main.h"
#include "constants/ygo.h"

void Task_OpenMenuFromStartMenu(u8 taskId);
void Menu_Init(MainCallback callback);
void Task_MenuTurnOff(u8 taskId);
extern const u8 *const sCardRaceIcons[NUM_RACES + 1];
extern const u8 *const sCardAttributeIcons[NUM_ATTRIBUTES + 1];
extern const u16 *const sCardAttributeIconPals[NUM_ATTRIBUTES + 1];
extern const u16 *const sCardRaceIconPals[NUM_RACES + 1];
extern const u8 *const sCardTypeIcons[NUM_TYPES + 1];
extern const u16 *const sCardTypeIconPals[NUM_TYPES + 1];
extern const u8 *const gCardTypeText[NUM_TYPES + 1];
extern const u8 gSupportedTypes[NUM_TYPES + 1];
extern const u8 sMenuWindowFontColors[4][3];
extern bool8 sDidInitialDraw;
extern u8 sScrollDown;
extern const struct SpritePalette sIcon_SpritePalettes[];
extern const struct SpriteTemplate sStarSpriteTemplate;
extern const u16 sBackgroundPalette[];
extern const u32 sNormalMonsterTiles[];
extern const u32 sNormalMonsterTilemap[];
extern const u16 sNormalMonsterPalette[];
extern const u32 sEffectMonsterTiles[];
extern const u32 sEffectMonsterTilemap[];
extern const u16 sEffectMonsterPalette[];
extern const u32 sSpellCardTiles[];
extern const u32 sSpellCardTilemap[];
extern const u16 sSpellCardPalette[];
extern const u32 sTrapCardTiles[];
extern const u32 sTrapCardTilemap[];
extern const u16 sTrapCardPalette[];
extern const u32 sFusionMonsterTiles[];
extern const u32 sFusionMonsterTilemap[];
extern const u16 sFusionMonsterPalette[];
extern const u32 sRitualMonsterTiles[];
extern const u32 sRitualMonsterTilemap[];
extern const u16 sRitualMonsterPalette[];
extern const u32 sBackgroundTiles[];
extern const u32 sBackgroundTilemap[];
extern const u16 sBackgroundPalette[];
void PrintToWindow(u8 windowId, u8 colorIdx, u16 card);
const struct CompressedSpriteSheet sSpriteSheet_Cards[NUM_CARDS + 1];
const struct SpriteTemplate sCardLeftSpriteTemplate;
u8 *sTilemapBuffers[2];
void PrintSmallNarrowTextCentered(u8 windowId, u8 left, u8 colorId, const u8 *string);

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

#define NUM_VISIBLE_LINES 15

u32 GetLineStartIndex(const u8 *text, u8 lineNum);
u16 CountNumLines(const u8 *text);
void DrawScrolledText(u8 windowId, const u8 *fullText, u32 startIndex, u8 linesToDraw);

#endif // GUARD_UI_MENU_H

#ifndef GUARD_UI_MENU_H
#define GUARD_UI_MENU_H

#include "main.h"
#include "constants/ygo.h"

void Task_OpenMenuFromStartMenu(u8 taskId);
void Menu_Init(MainCallback callback);
void Task_MenuTurnOff(u8 taskId);
const u8 *const sCardRaceIcons[NUM_RACES + 1];
const u8 *const sCardAttributeIcons[NUM_ATTRIBUTES + 1];
const u16 *const sCardAttributeIconPals[NUM_ATTRIBUTES + 1];
const u16 *const sCardRaceIconPals[NUM_RACES + 1];
const u8 *const sCardTypeIcons[NUM_TYPES + 1];
const u16 *const sCardTypeIconPals[NUM_TYPES + 1];
const u8 *const gCardTypeText[NUM_TYPES + 1];
const u8 gSupportedTypes[NUM_TYPES + 1];
const u8 sMenuWindowFontColors[4][3];
extern bool8 sDidInitialDraw;

#endif // GUARD_UI_MENU_H

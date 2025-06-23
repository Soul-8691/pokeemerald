#include "global.h"
#include "ygo.h"
#include "constants/ygo.h"
#include "ygo_graphics.h"
#include "constants/items.h"

const u8 gCardDescription_BlueEyesWhiteDragon[] = _("This legendary dragon is a\npowerful engine of\ndestruction. Virtually\ninvincible, very few have\nfaced this awesome creature\nand lived to tell the tale.");
const u8 gCardDescription_DarkMagician[] = _("The ultimate wizard in terms\nof attack and defense.");
const u8 gCardDescription_RedEyesBlackDragon[] = _("A ferocious dragon with a\ndeadly attack.");

const u8 CardIdMapping[] = 
{
    [ITEM_DARK_MAGICIAN] = 1,
    [ITEM_BLUE_EYES_WHITE_DRAGON] = 2,
    [ITEM_RED_EYES_BLACK_DRAGON] = 3,
};

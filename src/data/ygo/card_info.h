const u8 gCardName_DarkMagician[] = _("Dark Magician");
const u8 gCardDescription_DarkMagician[] = _("The ultimate wizard in terms\nof attack and defense.");
const u8 gCardPassword_DarkMagician[] = _("46986414");

const struct CardInfo gCardInfo[] =
{
    [CARD_NONE] = {0},

    [CARD_DARK_MAGICIAN] =
    {
        .name = gCardName_DarkMagician,
        .description = gCardDescription_DarkMagician,
        .password = gCardPassword_DarkMagician,
        .pic = gCardPicLarge_DarkMagician_Big,
        .iconSquare = gCardIconSquare_DarkMagician,
        .iconLarge = gCardIconLarge_DarkMagician,
        .iconSmall = gCardIconSmall_DarkMagician,
        .effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},
        .type = TYPE_NORMAL,
        .attribute = ATTRIBUTE_DARK,
        .level = 7,
        .atk = 250,
        .def = 210,
        .race = RACE_SPELLCASTER,
        .id = 4041,
    }
};

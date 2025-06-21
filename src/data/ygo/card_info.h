const u8 gCardName_DarkMagician[] = _("Dark Magician");
const u8 gCardNameShort_DarkMagician[] = _("Dark Magician");
const u8 gCardDescription_DarkMagician[] = _("The ultimate wizard in terms\nof attack and defense.");
const u8 gCardPassword_DarkMagician[] = _("46986414");
const u8 gCardName_BlueEyesWhiteDragon[] = _("Blue-Eyes White Dragon");
const u8 gCardNameShort_BlueEyesWhiteDragon[] = _("B. Eyes White Dragon");
const u8 gCardDescription_BlueEyesWhiteDragon[] = _("This legendary dragon is a powerful engine of destruction. Virtually invincible, very few have faced this awesome creature and lived to tell the tale.");
const u8 gCardPassword_BlueEyesWhiteDragon[] = _("89631139");

const struct CardInfo gCardInfo[] =
{
    [CARD_NONE] = {0},

    [CARD_DARK_MAGICIAN] =
    {
        .name = gCardName_DarkMagician,
        .nameShort = gCardNameShort_DarkMagician,
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
    },
    [CARD_BLUE_EYES_WHITE_DRAGON] =
    {
        .name = gCardName_BlueEyesWhiteDragon,
        .nameShort = gCardNameShort_BlueEyesWhiteDragon,
        .description = gCardDescription_BlueEyesWhiteDragon,
        .password = gCardPassword_BlueEyesWhiteDragon,
        .pic = gCardPicLarge_BlueEyesWhiteDragon_Big,
        .iconSquare = gCardIconSquare_BlueEyesWhiteDragon,
        .iconLarge = gCardIconLarge_BlueEyesWhiteDragon,
        .iconSmall = gCardIconSmall_BlueEyesWhiteDragon,
        .effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},
        .type = TYPE_NORMAL,
        .attribute = ATTRIBUTE_LIGHT,
        .level = 8,
        .atk = 300,
        .def = 250,
        .race = RACE_DRAGON,
        .id = 4007,
    }
};

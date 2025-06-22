const u8 gCardName_DarkMagician[] = _("Dark Magician");
const u8 gCardNameShort_DarkMagician[] = _("Dark Magician");
const u8 gCardPassword_DarkMagician[] = _("46986414");
const u8 gCardName_BlueEyesWhiteDragon[] = _("Blue-Eyes White Dragon");
const u8 gCardNameShort_BlueEyesWhiteDragon[] = _("B. Eyes W. Dragon");
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
        .pal = gCardPalLarge_DarkMagician,
        .iconSquare = gCardIconSquare_DarkMagician,
        .iconLarge = gCardIconLarge_DarkMagician,
        .iconSmall = gCardIconSmall_DarkMagician,
        .effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},
        .type = TYPE_NORMAL,
        .attribute = ATTRIBUTE_DARK,
        .level = 7,
        .atk = 250,
        .def = 210,
        .race = RACE_SPELLCASTER,
        .id = 4041,
        .archetypesSeries = {ARCHETYPE_DARK_MAGICIAN, ARCHETYPE_NONE, ARCHETYPE_NONE},
    },
    [CARD_BLUE_EYES_WHITE_DRAGON] =
    {
        .name = gCardName_BlueEyesWhiteDragon,
        .nameShort = gCardNameShort_BlueEyesWhiteDragon,
        .description = gCardDescription_BlueEyesWhiteDragon,
        .password = gCardPassword_BlueEyesWhiteDragon,
        .pic = gCardPicLarge_BlueEyesWhiteDragon_Big,
        .pal = gCardPalLarge_BlueEyesWhiteDragon,
        .iconSquare = gCardIconSquare_BlueEyesWhiteDragon,
        .iconLarge = gCardIconLarge_BlueEyesWhiteDragon,
        .iconSmall = gCardIconSmall_BlueEyesWhiteDragon,
        .effects = {EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE, EFFECT_NONE},
        .type = TYPE_NORMAL,
        .attribute = ATTRIBUTE_LIGHT,
        .level = 8,
        .atk = 300,
        .def = 250,
        .race = RACE_DRAGON,
        .id = 4007,
        .archetypesSeries = {ARCHETYPE_BLUE_EYES, ARCHETYPE_NONE, ARCHETYPE_NONE},
    }
};

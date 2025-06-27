const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
        .name = _("MASTER BALL"),
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = sMasterBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_MASTER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = _("ULTRA BALL"),
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = sUltraBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_ULTRA_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = _("GREAT BALL"),
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = sGreatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_GREAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,
    },

    [ITEM_POKE_BALL] =
    {
        .name = _("POKé BALL"),
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = sPokeBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_POKE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = _("SAFARI BALL"),
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = sSafariBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_SAFARI_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,
    },

    [ITEM_NET_BALL] =
    {
        .name = _("NET BALL"),
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = sNetBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_NET_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_NET_BALL - FIRST_BALL,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = _("DIVE BALL"),
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = sDiveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_DIVE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,
    },

    [ITEM_NEST_BALL] =
    {
        .name = _("NEST BALL"),
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = sNestBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_NEST_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_NEST_BALL - FIRST_BALL,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = _("REPEAT BALL"),
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = sRepeatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_REPEAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = _("TIMER BALL"),
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = sTimerBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_TIMER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = _("LUXURY BALL"),
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = sLuxuryBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_LUXURY_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = _("PREMIER BALL"),
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = sPremierBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_PREMIER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = _("POTION"),
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = _("ANTIDOTE"),
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = sAntidoteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = _("BURN HEAL"),
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = sBurnHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = _("ICE HEAL"),
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = sIceHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_AWAKENING] =
    {
        .name = _("AWAKENING"),
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = sAwakeningDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = _("PARLYZ HEAL"),
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = sParalyzeHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = _("FULL RESTORE"),
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_POTION] =
    {
        .name = _("MAX POTION"),
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = _("HYPER POTION"),
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 200,
        .description = sHyperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = _("SUPER POTION"),
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 50,
        .description = sSuperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = _("FULL HEAL"),
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVE] =
    {
        .name = _("REVIVE"),
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = sReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = _("MAX REVIVE"),
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = _("FRESH WATER"),
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 50,
        .description = sFreshWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SODA_POP] =
    {
        .name = _("SODA POP"),
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 60,
        .description = sSodaPopDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEMONADE] =
    {
        .name = _("LEMONADE"),
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 80,
        .description = sLemonadeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = _("MOOMOO MILK"),
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = _("ENERGYPOWDER"),
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = sEnergyPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = _("ENERGY ROOT"),
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = sEnergyRootDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = _("HEAL POWDER"),
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = sHealPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = _("REVIVAL HERB"),
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = sRevivalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ETHER] =
    {
        .name = _("ETHER"),
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = _("MAX ETHER"),
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ELIXIR] =
    {
        .name = _("ELIXIR"),
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = _("MAX ELIXIR"),
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = _("LAVA COOKIE"),
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = sLavaCookieDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLUE_FLUTE] =
    {
        .name = _("BLUE FLUTE"),
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = sBlueFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = _("YELLOW FLUTE"),
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = sYellowFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = _("RED FLUTE"),
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = sRedFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLACK_FLUTE] =
    {
        .name = _("BLACK FLUTE"),
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = _("WHITE FLUTE"),
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = _("BERRY JUICE"),
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = _("SACRED ASH"),
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = sSacredAshDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
        .name = _("SHOAL SALT"),
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = sShoalSaltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = _("SHOAL SHELL"),
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = sShoalShellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SHARD] =
    {
        .name = _("RED SHARD"),
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = sRedShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = _("BLUE SHARD"),
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = sBlueShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = _("YELLOW SHARD"),
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = sYellowShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = _("GREEN SHARD"),
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = sGreenShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_034] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_035] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_036] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_037] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_038] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_039] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03D] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03E] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = _("HP UP"),
        .itemId = ITEM_HP_UP,
        .price = 9800,
        .description = sHPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PROTEIN] =
    {
        .name = _("PROTEIN"),
        .itemId = ITEM_PROTEIN,
        .price = 9800,
        .description = sProteinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_IRON] =
    {
        .name = _("IRON"),
        .itemId = ITEM_IRON,
        .price = 9800,
        .description = sIronDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CARBOS] =
    {
        .name = _("CARBOS"),
        .itemId = ITEM_CARBOS,
        .price = 9800,
        .description = sCarbosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CALCIUM] =
    {
        .name = _("CALCIUM"),
        .itemId = ITEM_CALCIUM,
        .price = 9800,
        .description = sCalciumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_RARE_CANDY] =
    {
        .name = _("RARE CANDY"),
        .itemId = ITEM_RARE_CANDY,
        .price = 4800,
        .description = sRareCandyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
    },

    [ITEM_PP_UP] =
    {
        .name = _("PP UP"),
        .itemId = ITEM_PP_UP,
        .price = 9800,
        .description = sPPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_ZINC] =
    {
        .name = _("ZINC"),
        .itemId = ITEM_ZINC,
        .price = 9800,
        .description = sZincDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PP_MAX] =
    {
        .name = _("PP MAX"),
        .itemId = ITEM_PP_MAX,
        .price = 9800,
        .description = sPPMaxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_048] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
        .name = _("GUARD SPEC."),
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = sGuardSpecDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = _("DIRE HIT"),
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = sDireHitDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ATTACK] =
    {
        .name = _("X ATTACK"),
        .itemId = ITEM_X_ATTACK,
        .price = 500,
        .description = sXAttackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_DEFEND] =
    {
        .name = _("X DEFEND"),
        .itemId = ITEM_X_DEFEND,
        .price = 550,
        .description = sXDefendDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPEED] =
    {
        .name = _("X SPEED"),
        .itemId = ITEM_X_SPEED,
        .price = 350,
        .description = sXSpeedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = _("X ACCURACY"),
        .itemId = ITEM_X_ACCURACY,
        .price = 950,
        .description = sXAccuracyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPECIAL] =
    {
        .name = _("X SPECIAL"),
        .itemId = ITEM_X_SPECIAL,
        .price = 350,
        .description = sXSpecialDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = _("POKé DOLL"),
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = _("FLUFFY TAIL"),
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = sFluffyTailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_052] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
        .name = _("SUPER REPEL"),
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = _("MAX REPEL"),
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = _("ESCAPE ROPE"),
        .itemId = ITEM_ESCAPE_ROPE,
        .price = 550,
        .description = sEscapeRopeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
    },

    [ITEM_REPEL] =
    {
        .name = _("REPEL"),
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_057] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_058] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_059] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
        .name = _("SUN STONE"),
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = sSunStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_MOON_STONE] =
    {
        .name = _("MOON STONE"),
        .itemId = ITEM_MOON_STONE,
        .price = 0,
        .description = sMoonStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_FIRE_STONE] =
    {
        .name = _("FIRE STONE"),
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = sFireStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = _("THUNDERSTONE"),
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = sThunderStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_WATER_STONE] =
    {
        .name = _("WATER STONE"),
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = sWaterStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = _("LEAF STONE"),
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = sLeafStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_063] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_064] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_065] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_066] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Valuable items

    [ITEM_TINY_MUSHROOM] =
    {
        .name = _("TINYMUSHROOM"),
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = sTinyMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = _("BIG MUSHROOM"),
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_069] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PEARL] =
    {
        .name = _("PEARL"),
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = sPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = _("BIG PEARL"),
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = sBigPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARDUST] =
    {
        .name = _("STARDUST"),
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = sStardustDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = _("STAR PIECE"),
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = sStarPieceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NUGGET] =
    {
        .name = _("NUGGET"),
        .itemId = ITEM_NUGGET,
        .price = 10000,
        .description = sNuggetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = _("HEART SCALE"),
        .itemId = ITEM_HEART_SCALE,
        .price = 100,
        .description = sHeartScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_070] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_071] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_072] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_073] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_074] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_075] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_076] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_077] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_078] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
        .name = _("ORANGE MAIL"),
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = sOrangeMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = _("HARBOR MAIL"),
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = sHarborMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = _("GLITTER MAIL"),
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = sGlitterMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
        .name = _("MECH MAIL"),
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = sMechMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = _("WOOD MAIL"),
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = sWoodMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = _("WAVE MAIL"),
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = sWaveMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = _("BEAD MAIL"),
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = _("SHADOW MAIL"),
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = sShadowMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = _("TROPIC MAIL"),
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = sTropicMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = _("DREAM MAIL"),
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = sDreamMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
        .name = _("FAB MAIL"),
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = sFabMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = _("RETRO MAIL"),
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = sRetroMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = _("CHERI BERRY"),
        .itemId = ITEM_CHERI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = sCheriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = _("CHESTO BERRY"),
        .itemId = ITEM_CHESTO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = sChestoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = _("PECHA BERRY"),
        .itemId = ITEM_PECHA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = sPechaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = _("RAWST BERRY"),
        .itemId = ITEM_RAWST_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = sRawstBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = _("ASPEAR BERRY"),
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = sAspearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = _("LEPPA BERRY"),
        .itemId = ITEM_LEPPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = _("ORAN BERRY"),
        .itemId = ITEM_ORAN_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = _("PERSIM BERRY"),
        .itemId = ITEM_PERSIM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = sPersimBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = _("LUM BERRY"),
        .itemId = ITEM_LUM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = sLumBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = _("SITRUS BERRY"),
        .itemId = ITEM_SITRUS_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = sSitrusBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = _("FIGY BERRY"),
        .itemId = ITEM_FIGY_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = _("WIKI BERRY"),
        .itemId = ITEM_WIKI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = _("MAGO BERRY"),
        .itemId = ITEM_MAGO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = _("AGUAV BERRY"),
        .itemId = ITEM_AGUAV_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = _("IAPAPA BERRY"),
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = _("RAZZ BERRY"),
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = sRazzBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = _("BLUK BERRY"),
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = sBlukBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = _("NANAB BERRY"),
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = sNanabBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = _("WEPEAR BERRY"),
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = sWepearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = _("PINAP BERRY"),
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = sPinapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = _("POMEG BERRY"),
        .itemId = ITEM_POMEG_BERRY,
        .price = 20,
        .description = sPomegBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = _("KELPSY BERRY"),
        .itemId = ITEM_KELPSY_BERRY,
        .price = 20,
        .description = sKelpsyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = _("QUALOT BERRY"),
        .itemId = ITEM_QUALOT_BERRY,
        .price = 20,
        .description = sQualotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = _("HONDEW BERRY"),
        .itemId = ITEM_HONDEW_BERRY,
        .price = 20,
        .description = sHondewBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = _("GREPA BERRY"),
        .itemId = ITEM_GREPA_BERRY,
        .price = 20,
        .description = sGrepaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = _("TAMATO BERRY"),
        .itemId = ITEM_TAMATO_BERRY,
        .price = 20,
        .description = sTamatoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = _("CORNN BERRY"),
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = sCornnBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = _("MAGOST BERRY"),
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = sMagostBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = _("RABUTA BERRY"),
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = sRabutaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = _("NOMEL BERRY"),
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = sNomelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = _("SPELON BERRY"),
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = sSpelonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = _("PAMTRE BERRY"),
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = sPamtreBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = _("WATMEL BERRY"),
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = sWatmelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = _("DURIN BERRY"),
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = sDurinBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = _("BELUE BERRY"),
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = sBelueBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = _("LIECHI BERRY"),
        .itemId = ITEM_LIECHI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = _("GANLON BERRY"),
        .itemId = ITEM_GANLON_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = _("SALAC BERRY"),
        .itemId = ITEM_SALAC_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = _("PETAYA BERRY"),
        .itemId = ITEM_PETAYA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = _("APICOT BERRY"),
        .itemId = ITEM_APICOT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = _("LANSAT BERRY"),
        .itemId = ITEM_LANSAT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = _("STARF BERRY"),
        .itemId = ITEM_STARF_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = _("ENIGMA BERRY"),
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = sEnigmaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = _("BRIGHTPOWDER"),
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = _("WHITE HERB"),
        .itemId = ITEM_WHITE_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = sWhiteHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACHO_BRACE] =
    {
        .name = _("MACHO BRACE"),
        .itemId = ITEM_MACHO_BRACE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = sMachoBraceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = _("EXP. SHARE"),
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = sExpShareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = _("QUICK CLAW"),
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = _("SOOTHE BELL"),
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = sSootheBellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = _("MENTAL HERB"),
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
        .description = sMentalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHOICE_BAND] =
    {
        .name = _("CHOICE BAND"),
        .itemId = ITEM_CHOICE_BAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = sChoiceBandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = _("KING'S ROCK"),
        .itemId = ITEM_KINGS_ROCK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = _("SILVERPOWDER"),
        .itemId = ITEM_SILVER_POWDER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = _("AMULET COIN"),
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = _("CLEANSE TAG"),
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sCleanseTagDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = _("SOUL DEW"),
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .description = sSoulDewDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = _("DEEPSEATOOTH"),
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = sDeepSeaToothDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = _("DEEPSEASCALE"),
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = sDeepSeaScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = _("SMOKE BALL"),
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = sSmokeBallDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EVERSTONE] =
    {
        .name = _("EVERSTONE"),
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = sEverstoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = _("FOCUS BAND"),
        .itemId = ITEM_FOCUS_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = _("LUCKY EGG"),
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = sLuckyEggDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = _("SCOPE LENS"),
        .itemId = ITEM_SCOPE_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = sScopeLensDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_COAT] =
    {
        .name = _("METAL COAT"),
        .itemId = ITEM_METAL_COAT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = _("LEFTOVERS"),
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = _("DRAGON SCALE"),
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIGHT_BALL] =
    {
        .name = _("LIGHT BALL"),
        .itemId = ITEM_LIGHT_BALL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = sLightBallDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = _("SOFT SAND"),
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HARD_STONE] =
    {
        .name = _("HARD STONE"),
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = _("MIRACLE SEED"),
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = _("BLACKGLASSES"),
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = _("BLACK BELT"),
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGNET] =
    {
        .name = _("MAGNET"),
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = _("MYSTIC WATER"),
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = _("SHARP BEAK"),
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_BARB] =
    {
        .name = _("POISON BARB"),
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = _("NEVERMELTICE"),
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = _("SPELL TAG"),
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = _("TWISTEDSPOON"),
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHARCOAL] =
    {
        .name = _("CHARCOAL"),
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = _("DRAGON FANG"),
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILK_SCARF] =
    {
        .name = _("SILK SCARF"),
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UP_GRADE] =
    {
        .name = _("UP-GRADE"),
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_UP_GRADE,
        .description = sUpGradeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = _("SHELL BELL"),
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SEA_INCENSE] =
    {
        .name = _("SEA INCENSE"),
        .itemId = ITEM_SEA_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = _("LAX INCENSE"),
        .itemId = ITEM_LAX_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 5,
        .description = sLaxIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("LUCKY PUNCH"),
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = sLuckyPunchDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = _("METAL POWDER"),
        .itemId = ITEM_METAL_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = sMetalPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = _("THICK CLUB"),
        .itemId = ITEM_THICK_CLUB,
        .price = 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = sThickClubDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STICK] =
    {
        .name = _("STICK"),
        .itemId = ITEM_STICK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICK,
        .description = sStickDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0ED] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EF] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F0] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FD] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SCARF] =
    {
        .name = _("RED SCARF"),
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = sRedScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = _("BLUE SCARF"),
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = sBlueScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = _("PINK SCARF"),
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = sPinkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = _("GREEN SCARF"),
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = sGreenScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = _("YELLOW SCARF"),
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = sYellowScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
        .name = _("MACH BIKE"),
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = sMachBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_COIN_CASE] =
    {
        .name = _("COIN CASE"),
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = sCoinCaseDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_ITEMFINDER] =
    {
        .name = _("ITEMFINDER"),
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = sItemfinderDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_OLD_ROD] =
    {
        .name = _("OLD ROD"),
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = sOldRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = _("GOOD ROD"),
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = sGoodRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = _("SUPER ROD"),
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = sSuperRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_SS_TICKET] =
    {
        .name = _("S.S. TICKET"),
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = sSSTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = _("CONTEST PASS"),
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = sContestPassDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_10B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = _("WAILMER PAIL"),
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = sWailmerPailDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_DEVON_GOODS] =
    {
        .name = _("DEVON GOODS"),
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = sDevonGoodsDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = _("SOOT SACK"),
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = sSootSackDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = _("BASEMENT KEY"),
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = sBasementKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = _("ACRO BIKE"),
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = sAcroBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = _("{POKEBLOCK} CASE"),
        .itemId = ITEM_POKEBLOCK_CASE,
        .price = 0,
        .description = sPokeblockCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_LETTER] =
    {
        .name = _("LETTER"),
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = sLetterDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
        .name = _("EON TICKET"),
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = sEonTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
        .name = _("RED ORB"),
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = sRedOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = _("BLUE ORB"),
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = sBlueOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .name = _("SCANNER"),
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = sScannerDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = _("GO-GOGGLES"),
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = sGoGogglesDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
        .name = _("METEORITE"),
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = sMeteoriteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .name = _("RM. 1 KEY"),
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = sRoom1KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .name = _("RM. 2 KEY"),
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = sRoom2KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .name = _("RM. 4 KEY"),
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = sRoom4KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .name = _("RM. 6 KEY"),
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = sRoom6KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = _("STORAGE KEY"),
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = sStorageKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = _("ROOT FOSSIL"),
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = sRootFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = _("CLAW FOSSIL"),
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = sClawFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = _("DEVON SCOPE"),
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = sDevonScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// TMs/HMs

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .itemId = ITEM_TM01,
        .price = 3000,
        .description = sTM01Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .itemId = ITEM_TM02,
        .price = 3000,
        .description = sTM02Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = _("TM03"),
        .itemId = ITEM_TM03,
        .price = 3000,
        .description = sTM03Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = _("TM04"),
        .itemId = ITEM_TM04,
        .price = 3000,
        .description = sTM04Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .name = _("TM05"),
        .itemId = ITEM_TM05,
        .price = 1000,
        .description = sTM05Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = _("TM06"),
        .itemId = ITEM_TM06,
        .price = 3000,
        .description = sTM06Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .name = _("TM07"),
        .itemId = ITEM_TM07,
        .price = 3000,
        .description = sTM07Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = _("TM08"),
        .itemId = ITEM_TM08,
        .price = 3000,
        .description = sTM08Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = _("TM09"),
        .itemId = ITEM_TM09,
        .price = 3000,
        .description = sTM09Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .itemId = ITEM_TM10,
        .price = 3000,
        .description = sTM10Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .itemId = ITEM_TM11,
        .price = 2000,
        .description = sTM11Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = _("TM12"),
        .itemId = ITEM_TM12,
        .price = 3000,
        .description = sTM12Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = _("TM13"),
        .itemId = ITEM_TM13,
        .price = 3000,
        .description = sTM13Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = _("TM14"),
        .itemId = ITEM_TM14,
        .price = 5500,
        .description = sTM14Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .itemId = ITEM_TM15,
        .price = 7500,
        .description = sTM15Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .itemId = ITEM_TM16,
        .price = 3000,
        .description = sTM16Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = _("TM17"),
        .itemId = ITEM_TM17,
        .price = 3000,
        .description = sTM17Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .itemId = ITEM_TM18,
        .price = 2000,
        .description = sTM18Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .itemId = ITEM_TM19,
        .price = 3000,
        .description = sTM19Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = _("TM20"),
        .itemId = ITEM_TM20,
        .price = 3000,
        .description = sTM20Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = _("TM21"),
        .itemId = ITEM_TM21,
        .price = 1000,
        .description = sTM21Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = _("TM22"),
        .itemId = ITEM_TM22,
        .price = 3000,
        .description = sTM22Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = _("TM23"),
        .itemId = ITEM_TM23,
        .price = 3000,
        .description = sTM23Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .itemId = ITEM_TM24,
        .price = 3000,
        .description = sTM24Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = _("TM25"),
        .itemId = ITEM_TM25,
        .price = 5500,
        .description = sTM25Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .itemId = ITEM_TM26,
        .price = 3000,
        .description = sTM26Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .name = _("TM27"),
        .itemId = ITEM_TM27,
        .price = 1000,
        .description = sTM27Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = _("TM28"),
        .itemId = ITEM_TM28,
        .price = 2000,
        .description = sTM28Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = _("TM29"),
        .itemId = ITEM_TM29,
        .price = 2000,
        .description = sTM29Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .itemId = ITEM_TM30,
        .price = 3000,
        .description = sTM30Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .itemId = ITEM_TM31,
        .price = 3000,
        .description = sTM31Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .itemId = ITEM_TM32,
        .price = 2000,
        .description = sTM32Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = _("TM33"),
        .itemId = ITEM_TM33,
        .price = 3000,
        .description = sTM33Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .itemId = ITEM_TM34,
        .price = 3000,
        .description = sTM34Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .itemId = ITEM_TM35,
        .price = 3000,
        .description = sTM35Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .itemId = ITEM_TM36,
        .price = 1000,
        .description = sTM36Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = _("TM37"),
        .itemId = ITEM_TM37,
        .price = 2000,
        .description = sTM37Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .itemId = ITEM_TM38,
        .price = 5500,
        .description = sTM38Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .itemId = ITEM_TM39,
        .price = 3000,
        .description = sTM39Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .itemId = ITEM_TM40,
        .price = 3000,
        .description = sTM40Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = _("TM41"),
        .itemId = ITEM_TM41,
        .price = 3000,
        .description = sTM41Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = _("TM42"),
        .itemId = ITEM_TM42,
        .price = 3000,
        .description = sTM42Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = _("TM43"),
        .itemId = ITEM_TM43,
        .price = 3000,
        .description = sTM43Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = _("TM44"),
        .itemId = ITEM_TM44,
        .price = 3000,
        .description = sTM44Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = _("TM45"),
        .itemId = ITEM_TM45,
        .price = 3000,
        .description = sTM45Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = _("TM46"),
        .itemId = ITEM_TM46,
        .price = 3000,
        .description = sTM46Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = _("TM47"),
        .itemId = ITEM_TM47,
        .price = 3000,
        .description = sTM47Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .itemId = ITEM_TM48,
        .price = 3000,
        .description = sTM48Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = _("TM49"),
        .itemId = ITEM_TM49,
        .price = 3000,
        .description = sTM49Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = _("TM50"),
        .itemId = ITEM_TM50,
        .price = 3000,
        .description = sTM50Desc,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
        .name = _("HM01"),
        .itemId = ITEM_HM01,
        .price = 0,
        .description = sHM01Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
        .name = _("HM02"),
        .itemId = ITEM_HM02,
        .price = 0,
        .description = sHM02Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
        .name = _("HM03"),
        .itemId = ITEM_HM03,
        .price = 0,
        .description = sHM03Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = _("HM04"),
        .itemId = ITEM_HM04,
        .price = 0,
        .description = sHM04Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
        .name = _("HM05"),
        .itemId = ITEM_HM05,
        .price = 0,
        .description = sHM05Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = _("HM06"),
        .itemId = ITEM_HM06,
        .price = 0,
        .description = sHM06Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = _("HM07"),
        .itemId = ITEM_HM07,
        .price = 0,
        .description = sHM07Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
        .name = _("HM08"),
        .itemId = ITEM_HM08,
        .price = 0,
        .description = sHM08Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_15B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_15C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// FireRed/LeafGreen key items

    [ITEM_OAKS_PARCEL] =
    {
        .name = _("OAK'S PARCEL"),
        .itemId = ITEM_OAKS_PARCEL,
        .price = 0,
        .description = sOaksParcelDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = _("POKé FLUTE"),
        .itemId = ITEM_POKE_FLUTE,
        .price = 0,
        .description = sPokeFluteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = _("SECRET KEY"),
        .itemId = ITEM_SECRET_KEY,
        .price = 0,
        .description = sSecretKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = _("BIKE VOUCHER"),
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = sBikeVoucherDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = _("GOLD TEETH"),
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = sGoldTeethDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = _("OLD AMBER"),
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = sOldAmberDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
        .name = _("CARD KEY"),
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = sCardKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = _("LIFT KEY"),
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = sLiftKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HELIX_FOSSIL] =
    {
        .name = _("HELIX FOSSIL"),
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = sHelixFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = _("DOME FOSSIL"),
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = sDomeFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("SILPH SCOPE"),
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = sSilphScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BICYCLE] =
    {
        .name = _("BICYCLE"),
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = sBicycleDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = _("TOWN MAP"),
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = sTownMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = _("VS SEEKER"),
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = sVSSeekerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = _("FAME CHECKER"),
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = sFameCheckerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TM_CASE] =
    {
        .name = _("TM CASE"),
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = sTMCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = _("BERRY POUCH"),
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = sBerryPouchDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = _("TEACHY TV"),
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = sTeachyTVDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("TRI-PASS"),
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = sTriPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = _("RAINBOW PASS"),
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = sRainbowPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
        .name = _("TEA"),
        .itemId = ITEM_TEA,
        .price = 0,
        .description = sTeaDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = _("MYSTICTICKET"),
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = sMysticTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("AURORATICKET"),
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = sAuroraTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = _("POWDER JAR"),
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = sPowderJarDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_RUBY] =
    {
        .name = _("RUBY"),
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = sRubyDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = _("SAPPHIRE"),
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = sSapphireDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = _("MAGMA EMBLEM"),
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = sMagmaEmblemDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = _("OLD SEA MAP"),
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = sOldSeaMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

	[ITEM_4_STARRED_LADYBUG_OF_DOOM] =
    {
        .name = _("4StarredLadyb"),
        .itemId = ITEM_4_STARRED_LADYBUG_OF_DOOM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_7_COLORED_FISH] =
    {
        .name = _("7ColoredFish"),
        .itemId = ITEM_7_COLORED_FISH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_A_WINGBEAT_OF_GIANT_DRAGON] =
    {
        .name = _("AWingbeatofGi"),
        .itemId = ITEM_A_WINGBEAT_OF_GIANT_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ABYSS_DWELLER] =
    {
        .name = _("AbyssDweller"),
        .itemId = ITEM_ABYSS_DWELLER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ABYSS_SOLDIER] =
    {
        .name = _("AbyssSoldier"),
        .itemId = ITEM_ABYSS_SOLDIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ABYSS_SPHERE] =
    {
        .name = _("Abysssphere"),
        .itemId = ITEM_ABYSS_SPHERE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ABYSS_SQUALL] =
    {
        .name = _("Abysssquall"),
        .itemId = ITEM_ABYSS_SQUALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ACCUMULATED_FORTUNE] =
    {
        .name = _("AccumulatedFo"),
        .itemId = ITEM_ACCUMULATED_FORTUNE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ACID_TRAP_HOLE] =
    {
        .name = _("AcidTrapHole"),
        .itemId = ITEM_ACID_TRAP_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ADREUS_KEEPER_OF_ARMAGEDDON] =
    {
        .name = _("AdreusKeepero"),
        .itemId = ITEM_ADREUS_KEEPER_OF_ARMAGEDDON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ADVANCED_RITUAL_ART] =
    {
        .name = _("AdvancedRitua"),
        .itemId = ITEM_ADVANCED_RITUAL_ART,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AIRKNIGHT_PARSHATH] =
    {
        .name = _("AirknightPars"),
        .itemId = ITEM_AIRKNIGHT_PARSHATH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ALLURE_OF_DARKNESS] =
    {
        .name = _("AllureofDarkn"),
        .itemId = ITEM_ALLURE_OF_DARKNESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ALLY_OF_JUSTICE_CATASTOR] =
    {
        .name = _("AllyofJustice"),
        .itemId = ITEM_ALLY_OF_JUSTICE_CATASTOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ALLY_OF_JUSTICE_DECISIVE_ARMOR] =
    {
        .name = _("AllyofJustice"),
        .itemId = ITEM_ALLY_OF_JUSTICE_DECISIVE_ARMOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AMAZONESS_ARCHER] =
    {
        .name = _("AmazonessArch"),
        .itemId = ITEM_AMAZONESS_ARCHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ANCIENT_FAIRY_DRAGON] =
    {
        .name = _("AncientFairyD"),
        .itemId = ITEM_ANCIENT_FAIRY_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ANCIENT_GEAR_GADJILTRON_DRAGON] =
    {
        .name = _("AncientGearGa"),
        .itemId = ITEM_ANCIENT_GEAR_GADJILTRON_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ANCIENT_SACRED_WYVERN] =
    {
        .name = _("AncientSacred"),
        .itemId = ITEM_ANCIENT_SACRED_WYVERN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ANGEL_OF_ZERA] =
    {
        .name = _("AngelofZera"),
        .itemId = ITEM_ANGEL_OF_ZERA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ANTI_SPELL_FRAGRANCE] =
    {
        .name = _("AntiSpellFrag"),
        .itemId = ITEM_ANTI_SPELL_FRAGRANCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_APPRENTICE_MAGICIAN] =
    {
        .name = _("ApprenticeMag"),
        .itemId = ITEM_APPRENTICE_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AQUA_MADOOR] =
    {
        .name = _("AquaMadoor"),
        .itemId = ITEM_AQUA_MADOOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AQUA_SPIRIT] =
    {
        .name = _("AquaSpirit"),
        .itemId = ITEM_AQUA_SPIRIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARCANITE_MAGICIAN] =
    {
        .name = _("ArcaniteMagic"),
        .itemId = ITEM_ARCANITE_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARCHFIEND_SOLDIER] =
    {
        .name = _("ArchfiendSold"),
        .itemId = ITEM_ARCHFIEND_SOLDIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARCHLORD_KRISTYA] =
    {
        .name = _("ArchlordKrist"),
        .itemId = ITEM_ARCHLORD_KRISTYA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARMADES_KEEPER_OF_BOUNDARIES] =
    {
        .name = _("ArmadesKeeper"),
        .itemId = ITEM_ARMADES_KEEPER_OF_BOUNDARIES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARMAGEDDON_KNIGHT] =
    {
        .name = _("ArmageddonKni"),
        .itemId = ITEM_ARMAGEDDON_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARMORED_KAPPA] =
    {
        .name = _("ArmoredKappa"),
        .itemId = ITEM_ARMORED_KAPPA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARMORY_ARM] =
    {
        .name = _("ArmoryArm"),
        .itemId = ITEM_ARMORY_ARM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_BEAGALLTACH] =
    {
        .name = _("ArtifactBeaga"),
        .itemId = ITEM_ARTIFACT_BEAGALLTACH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_DURENDAL] =
    {
        .name = _("ArtifactDuren"),
        .itemId = ITEM_ARTIFACT_DURENDAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_IGNITION] =
    {
        .name = _("ArtifactIgnit"),
        .itemId = ITEM_ARTIFACT_IGNITION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_MORALLTACH] =
    {
        .name = _("ArtifactMoral"),
        .itemId = ITEM_ARTIFACT_MORALLTACH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_SANCTUM] =
    {
        .name = _("ArtifactSanct"),
        .itemId = ITEM_ARTIFACT_SANCTUM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ARTIFACT_SCYTHE] =
    {
        .name = _("ArtifactScyth"),
        .itemId = ITEM_ARTIFACT_SCYTHE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ASCETICISM_OF_THE_SIX_SAMURAI] =
    {
        .name = _("Asceticismoft"),
        .itemId = ITEM_ASCETICISM_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ASURA_PRIEST] =
    {
        .name = _("AsuraPriest"),
        .itemId = ITEM_ASURA_PRIEST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ATLANTEAN_DRAGOONS] =
    {
        .name = _("AtlanteanDrag"),
        .itemId = ITEM_ATLANTEAN_DRAGOONS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ATLANTEAN_HEAVY_INFANTRY] =
    {
        .name = _("AtlanteanHeav"),
        .itemId = ITEM_ATLANTEAN_HEAVY_INFANTRY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ATLANTEAN_MARKSMAN] =
    {
        .name = _("AtlanteanMark"),
        .itemId = ITEM_ATLANTEAN_MARKSMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AURKUS_LIGHTSWORN_DRUID] =
    {
        .name = _("AurkusLightsw"),
        .itemId = ITEM_AURKUS_LIGHTSWORN_DRUID,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AUTONOMOUS_ACTION_UNIT] =
    {
        .name = _("AutonomousAct"),
        .itemId = ITEM_AUTONOMOUS_ACTION_UNIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AVENGING_KNIGHT_PARSHATH] =
    {
        .name = _("AvengingKnigh"),
        .itemId = ITEM_AVENGING_KNIGHT_PARSHATH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_AZURE_EYES_SILVER_DRAGON] =
    {
        .name = _("AzureEyesSilv"),
        .itemId = ITEM_AZURE_EYES_SILVER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BAHAMUT_SHARK] =
    {
        .name = _("BahamutShark"),
        .itemId = ITEM_BAHAMUT_SHARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BANISHER_OF_THE_LIGHT] =
    {
        .name = _("Banisherofthe"),
        .itemId = ITEM_BANISHER_OF_THE_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BANISHER_OF_THE_RADIANCE] =
    {
        .name = _("Banisherofthe"),
        .itemId = ITEM_BANISHER_OF_THE_RADIANCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BARREL_BEHIND_THE_DOOR] =
    {
        .name = _("BarrelBehindt"),
        .itemId = ITEM_BARREL_BEHIND_THE_DOOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BATTLE_FADER] =
    {
        .name = _("BattleFader"),
        .itemId = ITEM_BATTLE_FADER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BATTLE_OX] =
    {
        .name = _("BattleOx"),
        .itemId = ITEM_BATTLE_OX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BAZOO_THE_SOUL_EATER] =
    {
        .name = _("BazootheSoulE"),
        .itemId = ITEM_BAZOO_THE_SOUL_EATER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BEAST_KING_BARBAROS] =
    {
        .name = _("BeastKingBarb"),
        .itemId = ITEM_BEAST_KING_BARBAROS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BECKONING_LIGHT] =
    {
        .name = _("BeckoningLigh"),
        .itemId = ITEM_BECKONING_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BEELZE_FROG] =
    {
        .name = _("BeelzeFrog"),
        .itemId = ITEM_BEELZE_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BERSERK_GORILLA] =
    {
        .name = _("BerserkGorill"),
        .itemId = ITEM_BERSERK_GORILLA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BICKURIBOX] =
    {
        .name = _("Bickuribox"),
        .itemId = ITEM_BICKURIBOX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BIG_SHIELD_GARDNA] =
    {
        .name = _("BigShieldGard"),
        .itemId = ITEM_BIG_SHIELD_GARDNA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_HORN_OF_HEAVEN] =
    {
        .name = _("BlackHornofHe"),
        .itemId = ITEM_BLACK_HORN_OF_HEAVEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING] =
    {
        .name = _("BlackLusterSo"),
        .itemId = ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_ROSE_DRAGON] =
    {
        .name = _("BlackRoseDrag"),
        .itemId = ITEM_BLACK_ROSE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_SALVO] =
    {
        .name = _("BlackSalvo"),
        .itemId = ITEM_BLACK_SALVO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_SKULL_DRAGON] =
    {
        .name = _("BlackSkullDra"),
        .itemId = ITEM_BLACK_SKULL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACK_WHIRLWIND] =
    {
        .name = _("BlackWhirlwin"),
        .itemId = ITEM_BLACK_WHIRLWIND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_BLIZZARD_THE_FAR_NORTH] =
    {
        .name = _("BlackwingBliz"),
        .itemId = ITEM_BLACKWING_BLIZZARD_THE_FAR_NORTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_BORA_THE_SPEAR] =
    {
        .name = _("BlackwingBora"),
        .itemId = ITEM_BLACKWING_BORA_THE_SPEAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_GALE_THE_WHIRLWIND] =
    {
        .name = _("BlackwingGale"),
        .itemId = ITEM_BLACKWING_GALE_THE_WHIRLWIND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_KALUT_THE_MOON_SHADOW] =
    {
        .name = _("BlackwingKalu"),
        .itemId = ITEM_BLACKWING_KALUT_THE_MOON_SHADOW,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_SHURA_THE_BLUE_FLAME] =
    {
        .name = _("BlackwingShur"),
        .itemId = ITEM_BLACKWING_SHURA_THE_BLUE_FLAME,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_SILVERWIND_THE_ASCENDANT] =
    {
        .name = _("BlackwingSilv"),
        .itemId = ITEM_BLACKWING_SILVERWIND_THE_ASCENDANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_SIROCCO_THE_DAWN] =
    {
        .name = _("BlackwingSiro"),
        .itemId = ITEM_BLACKWING_SIROCCO_THE_DAWN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_VAYU_THE_EMBLEM_OF_HONOR] =
    {
        .name = _("BlackwingVayu"),
        .itemId = ITEM_BLACKWING_VAYU_THE_EMBLEM_OF_HONOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_ARMED_WING] =
    {
        .name = _("BlackwingArme"),
        .itemId = ITEM_BLACKWING_ARMED_WING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLACKWING_ARMOR_MASTER] =
    {
        .name = _("BlackwingArmo"),
        .itemId = ITEM_BLACKWING_ARMOR_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLADE_ARMOR_NINJA] =
    {
        .name = _("BladeArmorNin"),
        .itemId = ITEM_BLADE_ARMOR_NINJA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLADE_KNIGHT] =
    {
        .name = _("BladeKnight"),
        .itemId = ITEM_BLADE_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLAST_WITH_CHAIN] =
    {
        .name = _("BlastwithChai"),
        .itemId = ITEM_BLAST_WITH_CHAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLASTER_DRAGON_RULER_OF_INFERNOS] =
    {
        .name = _("BlasterDragon"),
        .itemId = ITEM_BLASTER_DRAGON_RULER_OF_INFERNOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLUE_THUNDER_T_45] =
    {
        .name = _("BlueThunderT4"),
        .itemId = ITEM_BLUE_THUNDER_T_45,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLUE_EYES_ULTIMATE_DRAGON] =
    {
        .name = _("BlueEyesUltim"),
        .itemId = ITEM_BLUE_EYES_ULTIMATE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BLUE_EYES_WHITE_DRAGON] =
    {
        .name = _("BlueEyesWhite"),
        .itemId = ITEM_BLUE_EYES_WHITE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BOOK_OF_ECLIPSE] =
    {
        .name = _("BookofEclipse"),
        .itemId = ITEM_BOOK_OF_ECLIPSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BOOK_OF_LIFE] =
    {
        .name = _("BookofLife"),
        .itemId = ITEM_BOOK_OF_LIFE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BOOK_OF_MOON] =
    {
        .name = _("BookofMoon"),
        .itemId = ITEM_BOOK_OF_MOON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BOOK_OF_TAIYOU] =
    {
        .name = _("BookofTaiyou"),
        .itemId = ITEM_BOOK_OF_TAIYOU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BOTTOMLESS_TRAP_HOLE] =
    {
        .name = _("BottomlessTra"),
        .itemId = ITEM_BOTTOMLESS_TRAP_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BRAIN_CONTROL] =
    {
        .name = _("BrainControl"),
        .itemId = ITEM_BRAIN_CONTROL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BREAKER_THE_MAGICAL_WARRIOR] =
    {
        .name = _("BreakertheMag"),
        .itemId = ITEM_BREAKER_THE_MAGICAL_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BREAKTHROUGH_SKILL] =
    {
        .name = _("BreakthroughS"),
        .itemId = ITEM_BREAKTHROUGH_SKILL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BRIONAC_DRAGON_OF_THE_ICE_BARRIER] =
    {
        .name = _("BrionacDragon"),
        .itemId = ITEM_BRIONAC_DRAGON_OF_THE_ICE_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_BEAR] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_BEAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_BOAR] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_BOAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_CARDINAL] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_CARDINAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_DRAGON] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_GORILLA] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_GORILLA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_TIGER_KING] =
    {
        .name = _("Brotherhoodof"),
        .itemId = ITEM_BROTHERHOOD_OF_THE_FIRE_FIST_TIGER_KING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD] =
    {
        .name = _("BrowwHuntsman"),
        .itemId = ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJIN_HIRUME] =
    {
        .name = _("BujinHirume"),
        .itemId = ITEM_BUJIN_HIRUME,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJIN_MIKAZUCHI] =
    {
        .name = _("BujinMikazuch"),
        .itemId = ITEM_BUJIN_MIKAZUCHI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJIN_YAMATO] =
    {
        .name = _("BujinYamato"),
        .itemId = ITEM_BUJIN_YAMATO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINCARNATION] =
    {
        .name = _("Bujincarnatio"),
        .itemId = ITEM_BUJINCARNATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINGI_CRANE] =
    {
        .name = _("BujingiCrane"),
        .itemId = ITEM_BUJINGI_CRANE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINGI_HARE] =
    {
        .name = _("BujingiHare"),
        .itemId = ITEM_BUJINGI_HARE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINGI_QUILIN] =
    {
        .name = _("BujingiQuilin"),
        .itemId = ITEM_BUJINGI_QUILIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINGI_SINYOU] =
    {
        .name = _("BujingiSinyou"),
        .itemId = ITEM_BUJINGI_SINYOU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINGI_TURTLE] =
    {
        .name = _("BujingiTurtle"),
        .itemId = ITEM_BUJINGI_TURTLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINTEI_KAGUTSUCHI] =
    {
        .name = _("BujinteiKagut"),
        .itemId = ITEM_BUJINTEI_KAGUTSUCHI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BUJINTEI_SUSANOWO] =
    {
        .name = _("BujinteiSusan"),
        .itemId = ITEM_BUJINTEI_SUSANOWO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BURIAL_FROM_A_DIFFERENT_DIMENSION] =
    {
        .name = _("BurialfromaDi"),
        .itemId = ITEM_BURIAL_FROM_A_DIFFERENT_DIMENSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_BURNER_DRAGON_RULER_OF_SPARKS] =
    {
        .name = _("BurnerDragonR"),
        .itemId = ITEM_BURNER_DRAGON_RULER_OF_SPARKS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CAIUS_THE_SHADOW_MONARCH] =
    {
        .name = _("CaiustheShado"),
        .itemId = ITEM_CAIUS_THE_SHADOW_MONARCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CALL_OF_THE_HAUNTED] =
    {
        .name = _("CalloftheHaun"),
        .itemId = ITEM_CALL_OF_THE_HAUNTED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CANNON_SOLDIER] =
    {
        .name = _("CannonSoldier"),
        .itemId = ITEM_CANNON_SOLDIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARD_DESTRUCTION] =
    {
        .name = _("CardDestructi"),
        .itemId = ITEM_CARD_DESTRUCTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARD_OF_SAFE_RETURN] =
    {
        .name = _("CardofSafeRet"),
        .itemId = ITEM_CARD_OF_SAFE_RETURN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARD_TROOPER] =
    {
        .name = _("CardTrooper"),
        .itemId = ITEM_CARD_TROOPER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARDCAR_D] =
    {
        .name = _("CardcarD"),
        .itemId = ITEM_CARDCAR_D,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARDS_FOR_BLACK_FEATHERS] =
    {
        .name = _("CardsforBlack"),
        .itemId = ITEM_CARDS_FOR_BLACK_FEATHERS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARDS_FROM_THE_SKY] =
    {
        .name = _("CardsfromtheS"),
        .itemId = ITEM_CARDS_FROM_THE_SKY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CARDS_OF_CONSONANCE] =
    {
        .name = _("CardsofConson"),
        .itemId = ITEM_CARDS_OF_CONSONANCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CASTLE_OF_DRAGON_SOULS] =
    {
        .name = _("CastleofDrago"),
        .itemId = ITEM_CASTLE_OF_DRAGON_SOULS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CASTLE_WALLS] =
    {
        .name = _("CastleWalls"),
        .itemId = ITEM_CASTLE_WALLS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CATAPULT_TURTLE] =
    {
        .name = _("CatapultTurtl"),
        .itemId = ITEM_CATAPULT_TURTLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CEASEFIRE] =
    {
        .name = _("Ceasefire"),
        .itemId = ITEM_CEASEFIRE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CELESTIA_LIGHTSWORN_ANGEL] =
    {
        .name = _("CelestiaLight"),
        .itemId = ITEM_CELESTIA_LIGHTSWORN_ANGEL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHAIN_DISAPPEARANCE] =
    {
        .name = _("ChainDisappea"),
        .itemId = ITEM_CHAIN_DISAPPEARANCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHAIN_ENERGY] =
    {
        .name = _("ChainEnergy"),
        .itemId = ITEM_CHAIN_ENERGY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHAIN_STRIKE] =
    {
        .name = _("ChainStrike"),
        .itemId = ITEM_CHAIN_STRIKE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHANGE_OF_HEART] =
    {
        .name = _("ChangeofHeart"),
        .itemId = ITEM_CHANGE_OF_HEART,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END] =
    {
        .name = _("ChaosEmperorD"),
        .itemId = ITEM_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHAOS_SORCERER] =
    {
        .name = _("ChaosSorcerer"),
        .itemId = ITEM_CHAOS_SORCERER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHARGE_OF_THE_LIGHT_BRIGADE] =
    {
        .name = _("ChargeoftheLi"),
        .itemId = ITEM_CHARGE_OF_THE_LIGHT_BRIGADE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHARUBIN_THE_FIRE_KNIGHT] =
    {
        .name = _("CharubintheFi"),
        .itemId = ITEM_CHARUBIN_THE_FIRE_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHIMERATECH_FORTRESS_DRAGON] =
    {
        .name = _("ChimeratechFo"),
        .itemId = ITEM_CHIMERATECH_FORTRESS_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHIMERATECH_OVERDRAGON] =
    {
        .name = _("ChimeratechOv"),
        .itemId = ITEM_CHIMERATECH_OVERDRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHIRON_THE_MAGE] =
    {
        .name = _("ChirontheMage"),
        .itemId = ITEM_CHIRON_THE_MAGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CHIVALRY] =
    {
        .name = _("Chivalry"),
        .itemId = ITEM_CHIVALRY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CIPHER_SOLDIER] =
    {
        .name = _("CipherSoldier"),
        .itemId = ITEM_CIPHER_SOLDIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CIRCLE_OF_THE_FIRE_KINGS] =
    {
        .name = _("CircleoftheFi"),
        .itemId = ITEM_CIRCLE_OF_THE_FIRE_KINGS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CLOSED_FOREST] =
    {
        .name = _("ClosedForest"),
        .itemId = ITEM_CLOSED_FOREST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COACH_SOLDIER_WOLFBARK] =
    {
        .name = _("CoachSoldierW"),
        .itemId = ITEM_COACH_SOLDIER_WOLFBARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COLD_WAVE] =
    {
        .name = _("ColdWave"),
        .itemId = ITEM_COLD_WAVE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COLOSSAL_FIGHTER] =
    {
        .name = _("ColossalFight"),
        .itemId = ITEM_COLOSSAL_FIGHTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COMMON_CHARITY] =
    {
        .name = _("CommonCharity"),
        .itemId = ITEM_COMMON_CHARITY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COMPULSORY_ESCAPE_DEVICE] =
    {
        .name = _("CompulsoryEsc"),
        .itemId = ITEM_COMPULSORY_ESCAPE_DEVICE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_COMPULSORY_EVACUATION_DEVICE] =
    {
        .name = _("CompulsoryEva"),
        .itemId = ITEM_COMPULSORY_EVACUATION_DEVICE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONFISCATION] =
    {
        .name = _("Confiscation"),
        .itemId = ITEM_CONFISCATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSECRATED_LIGHT] =
    {
        .name = _("ConsecratedLi"),
        .itemId = ITEM_CONSECRATED_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_ALGIEDI] =
    {
        .name = _("ConstellarAlg"),
        .itemId = ITEM_CONSTELLAR_ALGIEDI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_KAUS] =
    {
        .name = _("ConstellarKau"),
        .itemId = ITEM_CONSTELLAR_KAUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_OMEGA] =
    {
        .name = _("ConstellarOme"),
        .itemId = ITEM_CONSTELLAR_OMEGA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_PLEIADES] =
    {
        .name = _("ConstellarPle"),
        .itemId = ITEM_CONSTELLAR_PLEIADES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_POLLUX] =
    {
        .name = _("ConstellarPol"),
        .itemId = ITEM_CONSTELLAR_POLLUX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_PTOLEMY_M7] =
    {
        .name = _("ConstellarPto"),
        .itemId = ITEM_CONSTELLAR_PTOLEMY_M7,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONSTELLAR_SOMBRE] =
    {
        .name = _("ConstellarSom"),
        .itemId = ITEM_CONSTELLAR_SOMBRE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CONTRACT_WITH_THE_ABYSS] =
    {
        .name = _("Contractwitht"),
        .itemId = ITEM_CONTRACT_WITH_THE_ABYSS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CORRIDOR_OF_AGONY] =
    {
        .name = _("CorridorofAgo"),
        .itemId = ITEM_CORRIDOR_OF_AGONY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CRASS_CLOWN] =
    {
        .name = _("CrassClown"),
        .itemId = ITEM_CRASS_CLOWN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CREATURE_SWAP] =
    {
        .name = _("CreatureSwap"),
        .itemId = ITEM_CREATURE_SWAP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CREVICE_INTO_THE_DIFFERENT_DIMENSION] =
    {
        .name = _("CreviceIntoth"),
        .itemId = ITEM_CREVICE_INTO_THE_DIFFERENT_DIMENSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CRIMSON_BLADER] =
    {
        .name = _("CrimsonBlader"),
        .itemId = ITEM_CRIMSON_BLADER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CRUSADER_OF_ENDYMION] =
    {
        .name = _("CrusaderofEnd"),
        .itemId = ITEM_CRUSADER_OF_ENDYMION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CRUSH_CARD_VIRUS] =
    {
        .name = _("CrushCardViru"),
        .itemId = ITEM_CRUSH_CARD_VIRUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CRYSTAL_SEER] =
    {
        .name = _("CrystalSeer"),
        .itemId = ITEM_CRYSTAL_SEER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CUNNING_OF_THE_SIX_SAMURAI] =
    {
        .name = _("CunningoftheS"),
        .itemId = ITEM_CUNNING_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL] =
    {
        .name = _("CursedSealoft"),
        .itemId = ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_BLADER] =
    {
        .name = _("CyberBlader"),
        .itemId = ITEM_CYBER_BLADER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_DRAGON] =
    {
        .name = _("CyberDragon"),
        .itemId = ITEM_CYBER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_END_DRAGON] =
    {
        .name = _("CyberEndDrago"),
        .itemId = ITEM_CYBER_END_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_JAR] =
    {
        .name = _("CyberJar"),
        .itemId = ITEM_CYBER_JAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_OGRE_2] =
    {
        .name = _("CyberOgre2"),
        .itemId = ITEM_CYBER_OGRE_2,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_PHOENIX] =
    {
        .name = _("CyberPhoenix"),
        .itemId = ITEM_CYBER_PHOENIX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_SAURUS] =
    {
        .name = _("CyberSaurus"),
        .itemId = ITEM_CYBER_SAURUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_TWIN_DRAGON] =
    {
        .name = _("CyberTwinDrag"),
        .itemId = ITEM_CYBER_TWIN_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_VALLEY] =
    {
        .name = _("CyberValley"),
        .itemId = ITEM_CYBER_VALLEY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_CYBER_STEIN] =
    {
        .name = _("CyberStein"),
        .itemId = ITEM_CYBER_STEIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_ASSAILANT] =
    {
        .name = _("DDAssailant"),
        .itemId = ITEM_D_D_ASSAILANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_CROW] =
    {
        .name = _("DDCrow"),
        .itemId = ITEM_D_D_CROW,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_DESIGNATOR] =
    {
        .name = _("DDDesignator"),
        .itemId = ITEM_D_D_DESIGNATOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_SURVIVOR] =
    {
        .name = _("DDSurvivor"),
        .itemId = ITEM_D_D_SURVIVOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_WARRIOR] =
    {
        .name = _("DDWarrior"),
        .itemId = ITEM_D_D_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_WARRIOR_LADY] =
    {
        .name = _("DDWarriorLady"),
        .itemId = ITEM_D_D_WARRIOR_LADY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_M_DIFFERENT_DIMENSION_MASTER] =
    {
        .name = _("DDMDifferentD"),
        .itemId = ITEM_D_D_M_DIFFERENT_DIMENSION_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_D_D_R_DIFFERENT_DIMENSION_REINCARNATION] =
    {
        .name = _("DDRDifferentD"),
        .itemId = ITEM_D_D_R_DIFFERENT_DIMENSION_REINCARNATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DAIGUSTO_EMERAL] =
    {
        .name = _("DaigustoEmera"),
        .itemId = ITEM_DAIGUSTO_EMERAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DAIGUSTO_PHOENIX] =
    {
        .name = _("DaigustoPhoen"),
        .itemId = ITEM_DAIGUSTO_PHOENIX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DANDYLION] =
    {
        .name = _("Dandylion"),
        .itemId = ITEM_DANDYLION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_ARMED_DRAGON] =
    {
        .name = _("DarkArmedDrag"),
        .itemId = ITEM_DARK_ARMED_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_BALTER_THE_TERRIBLE] =
    {
        .name = _("DarkBalterthe"),
        .itemId = ITEM_DARK_BALTER_THE_TERRIBLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_BLADE_THE_DRAGON_KNIGHT] =
    {
        .name = _("DarkBladetheD"),
        .itemId = ITEM_DARK_BLADE_THE_DRAGON_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_BRIBE] =
    {
        .name = _("DarkBribe"),
        .itemId = ITEM_DARK_BRIBE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_DUST_SPIRIT] =
    {
        .name = _("DarkDustSpiri"),
        .itemId = ITEM_DARK_DUST_SPIRIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_ELF] =
    {
        .name = _("DarkElf"),
        .itemId = ITEM_DARK_ELF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_END_DRAGON] =
    {
        .name = _("DarkEndDragon"),
        .itemId = ITEM_DARK_END_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_ERUPTION] =
    {
        .name = _("DarkEruption"),
        .itemId = ITEM_DARK_ERUPTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_FLARE_KNIGHT] =
    {
        .name = _("DarkFlareKnig"),
        .itemId = ITEM_DARK_FLARE_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_GREPHER] =
    {
        .name = _("DarkGrepher"),
        .itemId = ITEM_DARK_GREPHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_HOLE] =
    {
        .name = _("DarkHole"),
        .itemId = ITEM_DARK_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_MAGICIAN_OF_CHAOS] =
    {
        .name = _("DarkMagiciano"),
        .itemId = ITEM_DARK_MAGICIAN_OF_CHAOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_MIMIC_LV3] =
    {
        .name = _("DarkMimicLV3"),
        .itemId = ITEM_DARK_MIMIC_LV3,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_NEPHTHYS] =
    {
        .name = _("DarkNephthys"),
        .itemId = ITEM_DARK_NEPHTHYS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_PALADIN] =
    {
        .name = _("DarkPaladin"),
        .itemId = ITEM_DARK_PALADIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_RULER_HA_DES] =
    {
        .name = _("DarkRulerHaDe"),
        .itemId = ITEM_DARK_RULER_HA_DES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_SMOG] =
    {
        .name = _("DarkSmog"),
        .itemId = ITEM_DARK_SMOG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_STRIKE_FIGHTER] =
    {
        .name = _("DarkStrikeFig"),
        .itemId = ITEM_DARK_STRIKE_FIGHTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_WORLD_DEALINGS] =
    {
        .name = _("DarkWorldDeal"),
        .itemId = ITEM_DARK_WORLD_DEALINGS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARK_WORLD_LIGHTNING] =
    {
        .name = _("DarkWorldLigh"),
        .itemId = ITEM_DARK_WORLD_LIGHTNING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARKFIRE_DRAGON] =
    {
        .name = _("DarkfireDrago"),
        .itemId = ITEM_DARKFIRE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARKFLARE_DRAGON] =
    {
        .name = _("DarkflareDrag"),
        .itemId = ITEM_DARKFLARE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DARKLORD_ZERATO] =
    {
        .name = _("DarklordZerat"),
        .itemId = ITEM_DARKLORD_ZERATO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DE_SPELL] =
    {
        .name = _("DeSpell"),
        .itemId = ITEM_DE_SPELL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEBRIS_DRAGON] =
    {
        .name = _("DebrisDragon"),
        .itemId = ITEM_DEBRIS_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEBUNK] =
    {
        .name = _("Debunk"),
        .itemId = ITEM_DEBUNK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DECK_DEVASTATION_VIRUS] =
    {
        .name = _("DeckDevastati"),
        .itemId = ITEM_DECK_DEVASTATION_VIRUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DECK_LOCKDOWN] =
    {
        .name = _("DeckLockdown"),
        .itemId = ITEM_DECK_LOCKDOWN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEEP_DARK_TRAP_HOLE] =
    {
        .name = _("DeepDarkTrapH"),
        .itemId = ITEM_DEEP_DARK_TRAP_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEEP_SEA_DIVA] =
    {
        .name = _("DeepSeaDiva"),
        .itemId = ITEM_DEEP_SEA_DIVA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEEPSEA_SHARK] =
    {
        .name = _("DeepseaShark"),
        .itemId = ITEM_DEEPSEA_SHARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE] =
    {
        .name = _("DekoichitheBa"),
        .itemId = ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DELINQUENT_DUO] =
    {
        .name = _("DelinquentDuo"),
        .itemId = ITEM_DELINQUENT_DUO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DELTA_CROW_ANTI_REVERSE] =
    {
        .name = _("DeltaCrowAnti"),
        .itemId = ITEM_DELTA_CROW_ANTI_REVERSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEMISE_KING_OF_ARMAGEDDON] =
    {
        .name = _("DemiseKingofA"),
        .itemId = ITEM_DEMISE_KING_OF_ARMAGEDDON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DES_FROG] =
    {
        .name = _("DesFrog"),
        .itemId = ITEM_DES_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DES_KOALA] =
    {
        .name = _("DesKoala"),
        .itemId = ITEM_DES_KOALA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DES_WOMBAT] =
    {
        .name = _("DesWombat"),
        .itemId = ITEM_DES_WOMBAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESERT_SUNLIGHT] =
    {
        .name = _("DesertSunligh"),
        .itemId = ITEM_DESERT_SUNLIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_DRAW] =
    {
        .name = _("DestinyDraw"),
        .itemId = ITEM_DESTINY_DRAW,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DASHER] =
    {
        .name = _("DestinyHERODa"),
        .itemId = ITEM_DESTINY_HERO_DASHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DEFENDER] =
    {
        .name = _("DestinyHERODe"),
        .itemId = ITEM_DESTINY_HERO_DEFENDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DIAMOND_DUDE] =
    {
        .name = _("DestinyHERODi"),
        .itemId = ITEM_DESTINY_HERO_DIAMOND_DUDE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DISK_COMMANDER] =
    {
        .name = _("DestinyHERODi"),
        .itemId = ITEM_DESTINY_HERO_DISK_COMMANDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DOGMA] =
    {
        .name = _("DestinyHERODo"),
        .itemId = ITEM_DESTINY_HERO_DOGMA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_DOOM_LORD] =
    {
        .name = _("DestinyHERODo"),
        .itemId = ITEM_DESTINY_HERO_DOOM_LORD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_FEAR_MONGER] =
    {
        .name = _("DestinyHEROFe"),
        .itemId = ITEM_DESTINY_HERO_FEAR_MONGER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_MALICIOUS] =
    {
        .name = _("DestinyHEROMa"),
        .itemId = ITEM_DESTINY_HERO_MALICIOUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DESTINY_HERO_PLASMA] =
    {
        .name = _("DestinyHEROPl"),
        .itemId = ITEM_DESTINY_HERO_PLASMA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DEWLOREN_TIGER_KING_OF_THE_ICE_BARRIER] =
    {
        .name = _("DewlorenTiger"),
        .itemId = ITEM_DEWLOREN_TIGER_KING_OF_THE_ICE_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIAMOND_DIRE_WOLF] =
    {
        .name = _("DiamondDireWo"),
        .itemId = ITEM_DIAMOND_DIRE_WOLF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIFFERENT_DIMENSION_CAPSULE] =
    {
        .name = _("DifferentDime"),
        .itemId = ITEM_DIFFERENT_DIMENSION_CAPSULE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIMENSION_FUSION] =
    {
        .name = _("DimensionFusi"),
        .itemId = ITEM_DIMENSION_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIMENSION_WALL] =
    {
        .name = _("DimensionWall"),
        .itemId = ITEM_DIMENSION_WALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIMENSIONAL_ALCHEMIST] =
    {
        .name = _("DimensionalAl"),
        .itemId = ITEM_DIMENSIONAL_ALCHEMIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIMENSIONAL_FISSURE] =
    {
        .name = _("DimensionalFi"),
        .itemId = ITEM_DIMENSIONAL_FISSURE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIMENSIONAL_PRISON] =
    {
        .name = _("DimensionalPr"),
        .itemId = ITEM_DIMENSIONAL_PRISON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIVINE_DRAGON_KNIGHT_FELGRAND] =
    {
        .name = _("DivineDragonK"),
        .itemId = ITEM_DIVINE_DRAGON_KNIGHT_FELGRAND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIVINE_SWORD_PHOENIX_BLADE] =
    {
        .name = _("DivineSwordPh"),
        .itemId = ITEM_DIVINE_SWORD_PHOENIX_BLADE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DIVINE_WRATH] =
    {
        .name = _("DivineWrath"),
        .itemId = ITEM_DIVINE_WRATH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DNA_SURGERY] =
    {
        .name = _("DNASurgery"),
        .itemId = ITEM_DNA_SURGERY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DON_ZALOOG] =
    {
        .name = _("DonZaloog"),
        .itemId = ITEM_DON_ZALOOG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOOM_DOZER] =
    {
        .name = _("DoomDozer"),
        .itemId = ITEM_DOOM_DOZER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOOMCALIBER_KNIGHT] =
    {
        .name = _("DoomcaliberKn"),
        .itemId = ITEM_DOOMCALIBER_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOOMKAISER_DRAGON] =
    {
        .name = _("DoomkaiserDra"),
        .itemId = ITEM_DOOMKAISER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOUBLE_CYCLONE] =
    {
        .name = _("DoubleCyclone"),
        .itemId = ITEM_DOUBLE_CYCLONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOUBLE_EDGED_SWORD_TECHNIQUE] =
    {
        .name = _("DoubleEdgedSw"),
        .itemId = ITEM_DOUBLE_EDGED_SWORD_TECHNIQUE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DOWNERD_MAGICIAN] =
    {
        .name = _("DownerdMagici"),
        .itemId = ITEM_DOWNERD_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGGED_DOWN_INTO_THE_GRAVE] =
    {
        .name = _("DraggedDownin"),
        .itemId = ITEM_DRAGGED_DOWN_INTO_THE_GRAVE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGON_RAVINE] =
    {
        .name = _("DragonRavine"),
        .itemId = ITEM_DRAGON_RAVINE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGON_SHRINE] =
    {
        .name = _("DragonShrine"),
        .itemId = ITEM_DRAGON_SHRINE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGONESS_THE_WICKED_KNIGHT] =
    {
        .name = _("DragonesstheW"),
        .itemId = ITEM_DRAGONESS_THE_WICKED_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGONIC_KNIGHT] =
    {
        .name = _("DragonicKnigh"),
        .itemId = ITEM_DRAGONIC_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_ARMA_MYSTLETAINN] =
    {
        .name = _("DragunityArma"),
        .itemId = ITEM_DRAGUNITY_ARMA_MYSTLETAINN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_CORSESCA] =
    {
        .name = _("DragunityCors"),
        .itemId = ITEM_DRAGUNITY_CORSESCA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_DUX] =
    {
        .name = _("DragunityDux"),
        .itemId = ITEM_DRAGUNITY_DUX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_KNIGHT_GAE_DEARG] =
    {
        .name = _("DragunityKnig"),
        .itemId = ITEM_DRAGUNITY_KNIGHT_GAE_DEARG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_KNIGHT_VAJRAYANA] =
    {
        .name = _("DragunityKnig"),
        .itemId = ITEM_DRAGUNITY_KNIGHT_VAJRAYANA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRAGUNITY_PHALANX] =
    {
        .name = _("DragunityPhal"),
        .itemId = ITEM_DRAGUNITY_PHALANX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRILL_WARRIOR] =
    {
        .name = _("DrillWarrior"),
        .itemId = ITEM_DRILL_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DRILLROID] =
    {
        .name = _("Drillroid"),
        .itemId = ITEM_DRILLROID,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DROLL_LOCK_BIRD] =
    {
        .name = _("DrollLockBird"),
        .itemId = ITEM_DROLL_LOCK_BIRD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DROP_OFF] =
    {
        .name = _("DropOff"),
        .itemId = ITEM_DROP_OFF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DUPE_FROG] =
    {
        .name = _("DupeFrog"),
        .itemId = ITEM_DUPE_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_DUST_TORNADO] =
    {
        .name = _("DustTornado"),
        .itemId = ITEM_DUST_TORNADO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_E_EMERGENCY_CALL] =
    {
        .name = _("EEmergencyCal"),
        .itemId = ITEM_E_EMERGENCY_CALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ECLIPSE_WYVERN] =
    {
        .name = _("EclipseWyvern"),
        .itemId = ITEM_ECLIPSE_WYVERN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EFFECT_VEILER] =
    {
        .name = _("EffectVeiler"),
        .itemId = ITEM_EFFECT_VEILER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EHREN_LIGHTSWORN_MONK] =
    {
        .name = _("EhrenLightswo"),
        .itemId = ITEM_EHREN_LIGHTSWORN_MONK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELDER_OF_THE_SIX_SAMURAI] =
    {
        .name = _("ElderoftheSix"),
        .itemId = ITEM_ELDER_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELECTRIC_SNAKE] =
    {
        .name = _("ElectricSnake"),
        .itemId = ITEM_ELECTRIC_SNAKE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELECTRIC_VIRUS] =
    {
        .name = _("ElectricVirus"),
        .itemId = ITEM_ELECTRIC_VIRUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_ABSOLUTE_ZERO] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_ABSOLUTE_ZERO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_AIR_NEOS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_AIR_NEOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_BUBBLEMAN] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_BUBBLEMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_CHAOS_NEOS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_CHAOS_NEOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_DARK_NEOS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_DARK_NEOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_ELECTRUM] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_ELECTRUM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_FLAME_WINGMAN] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_FLAME_WINGMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_GAIA] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_GAIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_GRAND_NEOS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_GRAND_NEOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_MARINER] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_MARINER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_NEOS_ALIUS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_NEOS_ALIUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_OCEAN] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_OCEAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_PHOENIX_ENFORCER] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_PHOENIX_ENFORCER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_PRISMA] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_PRISMA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_SHINING_FLARE_WINGMAN] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_SHINING_FLARE_WINGMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_STRATOS] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_STRATOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_TEMPEST] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_TEMPEST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_THE_SHINING] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_THE_SHINING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ELEMENTAL_HERO_WILDHEART] =
    {
        .name = _("ElementalHERO"),
        .itemId = ITEM_ELEMENTAL_HERO_WILDHEART,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EMERGENCY_PROVISIONS] =
    {
        .name = _("EmergencyProv"),
        .itemId = ITEM_EMERGENCY_PROVISIONS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EMERGENCY_TELEPORT] =
    {
        .name = _("EmergencyTele"),
        .itemId = ITEM_EMERGENCY_TELEPORT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EMPRESS_JUDGE] =
    {
        .name = _("EmpressJudge"),
        .itemId = ITEM_EMPRESS_JUDGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ENEMY_CONTROLLER] =
    {
        .name = _("EnemyControll"),
        .itemId = ITEM_ENEMY_CONTROLLER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ERADICATOR_EPIDEMIC_VIRUS] =
    {
        .name = _("EradicatorEpi"),
        .itemId = ITEM_ERADICATOR_EPIDEMIC_VIRUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ESCAPE_FROM_THE_DARK_DIMENSION] =
    {
        .name = _("Escapefromthe"),
        .itemId = ITEM_ESCAPE_FROM_THE_DARK_DIMENSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVIGISHKI_MERROWGEIST] =
    {
        .name = _("EvigishkiMerr"),
        .itemId = ITEM_EVIGISHKI_MERROWGEIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVIL_HERO_DARK_GAIA] =
    {
        .name = _("EvilHERODarkG"),
        .itemId = ITEM_EVIL_HERO_DARK_GAIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_BAHAMUT] =
    {
        .name = _("EvilswarmBaha"),
        .itemId = ITEM_EVILSWARM_BAHAMUT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_CASTOR] =
    {
        .name = _("EvilswarmCast"),
        .itemId = ITEM_EVILSWARM_CASTOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_EXCITON_KNIGHT] =
    {
        .name = _("EvilswarmExci"),
        .itemId = ITEM_EVILSWARM_EXCITON_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_HELIOTROPE] =
    {
        .name = _("EvilswarmHeli"),
        .itemId = ITEM_EVILSWARM_HELIOTROPE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_KERYKEION] =
    {
        .name = _("EvilswarmKery"),
        .itemId = ITEM_EVILSWARM_KERYKEION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_MANDRAGORA] =
    {
        .name = _("EvilswarmMand"),
        .itemId = ITEM_EVILSWARM_MANDRAGORA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_OPHION] =
    {
        .name = _("EvilswarmOphi"),
        .itemId = ITEM_EVILSWARM_OPHION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_OUROBOROS] =
    {
        .name = _("EvilswarmOuro"),
        .itemId = ITEM_EVILSWARM_OUROBOROS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVILSWARM_THUNDERBIRD] =
    {
        .name = _("EvilswarmThun"),
        .itemId = ITEM_EVILSWARM_THUNDERBIRD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVOLZAR_DOLKKA] =
    {
        .name = _("EvolzarDolkka"),
        .itemId = ITEM_EVOLZAR_DOLKKA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EVOLZAR_LAGGIA] =
    {
        .name = _("EvolzarLaggia"),
        .itemId = ITEM_EVOLZAR_LAGGIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EXARION_UNIVERSE] =
    {
        .name = _("ExarionUniver"),
        .itemId = ITEM_EXARION_UNIVERSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EXCHANGE] =
    {
        .name = _("Exchange"),
        .itemId = ITEM_EXCHANGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EXILED_FORCE] =
    {
        .name = _("ExiledForce"),
        .itemId = ITEM_EXILED_FORCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EXODIA_THE_FORBIDDEN_ONE] =
    {
        .name = _("ExodiatheForb"),
        .itemId = ITEM_EXODIA_THE_FORBIDDEN_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_EXPLODER_DRAGON] =
    {
        .name = _("ExploderDrago"),
        .itemId = ITEM_EXPLODER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FAIRY_KING_ALBVERDICH] =
    {
        .name = _("FairyKingAlbv"),
        .itemId = ITEM_FAIRY_KING_ALBVERDICH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FAKE_TRAP] =
    {
        .name = _("FakeTrap"),
        .itemId = ITEM_FAKE_TRAP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FENCING_FIRE_FERRET] =
    {
        .name = _("FencingFireFe"),
        .itemId = ITEM_FENCING_FIRE_FERRET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIBER_JAR] =
    {
        .name = _("FiberJar"),
        .itemId = ITEM_FIBER_JAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIEND_SKULL_DRAGON] =
    {
        .name = _("FiendSkullDra"),
        .itemId = ITEM_FIEND_SKULL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIENDISH_CHAIN] =
    {
        .name = _("FiendishChain"),
        .itemId = ITEM_FIENDISH_CHAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FINAL_FLAME] =
    {
        .name = _("FinalFlame"),
        .itemId = ITEM_FINAL_FLAME,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_FORMATION_GYOKKOU] =
    {
        .name = _("FireFormation"),
        .itemId = ITEM_FIRE_FORMATION_GYOKKOU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_FORMATION_TENKEN] =
    {
        .name = _("FireFormation"),
        .itemId = ITEM_FIRE_FORMATION_TENKEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_FORMATION_TENKI] =
    {
        .name = _("FireFormation"),
        .itemId = ITEM_FIRE_FORMATION_TENKI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_FORMATION_TENSEN] =
    {
        .name = _("FireFormation"),
        .itemId = ITEM_FIRE_FORMATION_TENSEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_FORMATION_TENSU] =
    {
        .name = _("FireFormation"),
        .itemId = ITEM_FIRE_FORMATION_TENSU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_HAND] =
    {
        .name = _("FireHand"),
        .itemId = ITEM_FIRE_HAND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_KING_AVATAR_BARONG] =
    {
        .name = _("FireKingAvata"),
        .itemId = ITEM_FIRE_KING_AVATAR_BARONG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_KING_AVATAR_YAKSHA] =
    {
        .name = _("FireKingAvata"),
        .itemId = ITEM_FIRE_KING_AVATAR_YAKSHA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRE_KING_HIGH_AVATAR_GARUNIX] =
    {
        .name = _("FireKingHighA"),
        .itemId = ITEM_FIRE_KING_HIGH_AVATAR_GARUNIX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIRES_OF_DOOMSDAY] =
    {
        .name = _("FiresofDoomsd"),
        .itemId = ITEM_FIRES_OF_DOOMSDAY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FISHBORG_BLASTER] =
    {
        .name = _("FishborgBlast"),
        .itemId = ITEM_FISHBORG_BLASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FISSURE] =
    {
        .name = _("Fissure"),
        .itemId = ITEM_FISSURE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FIVE_HEADED_DRAGON] =
    {
        .name = _("FiveHeadedDra"),
        .itemId = ITEM_FIVE_HEADED_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLAME_GHOST] =
    {
        .name = _("FlameGhost"),
        .itemId = ITEM_FLAME_GHOST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLAME_SWORDSMAN] =
    {
        .name = _("FlameSwordsma"),
        .itemId = ITEM_FLAME_SWORDSMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLAMVELL_FIREDOG] =
    {
        .name = _("FlamvellFired"),
        .itemId = ITEM_FLAMVELL_FIREDOG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLAMVELL_GUARD] =
    {
        .name = _("FlamvellGuard"),
        .itemId = ITEM_FLAMVELL_GUARD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLAMVELL_URUQUIZAS] =
    {
        .name = _("FlamvellUruqu"),
        .itemId = ITEM_FLAMVELL_URUQUIZAS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLIP_FLOP_FROG] =
    {
        .name = _("FlipFlopFrog"),
        .itemId = ITEM_FLIP_FLOP_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLOWER_WOLF] =
    {
        .name = _("FlowerWolf"),
        .itemId = ITEM_FLOWER_WOLF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FLYING_C_] =
    {
        .name = _("FlyingC"),
        .itemId = ITEM_FLYING_C_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FOG_KING] =
    {
        .name = _("FogKing"),
        .itemId = ITEM_FOG_KING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FOOLISH_BURIAL] =
    {
        .name = _("FoolishBurial"),
        .itemId = ITEM_FOOLISH_BURIAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FORBIDDEN_CHALICE] =
    {
        .name = _("ForbiddenChal"),
        .itemId = ITEM_FORBIDDEN_CHALICE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FORBIDDEN_DRESS] =
    {
        .name = _("ForbiddenDres"),
        .itemId = ITEM_FORBIDDEN_DRESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FORBIDDEN_LANCE] =
    {
        .name = _("ForbiddenLanc"),
        .itemId = ITEM_FORBIDDEN_LANCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FORMULA_SYNCHRON] =
    {
        .name = _("FormulaSynchr"),
        .itemId = ITEM_FORMULA_SYNCHRON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FOSSIL_DYNA_PACHYCEPHALO] =
    {
        .name = _("FossilDynaPac"),
        .itemId = ITEM_FOSSIL_DYNA_PACHYCEPHALO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FULL_HOUSE] =
    {
        .name = _("FullHouse"),
        .itemId = ITEM_FULL_HOUSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST] =
    {
        .name = _("FusilierDrago"),
        .itemId = ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FUSIONIST] =
    {
        .name = _("Fusionist"),
        .itemId = ITEM_FUSIONIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_FUTURE_FUSION] =
    {
        .name = _("FutureFusion"),
        .itemId = ITEM_FUTURE_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_G_B_HUNTER] =
    {
        .name = _("GBHunter"),
        .itemId = ITEM_G_B_HUNTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GACHI_GACHI_GANTETSU] =
    {
        .name = _("GachiGachiGan"),
        .itemId = ITEM_GACHI_GACHI_GANTETSU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAGAGA_COWBOY] =
    {
        .name = _("GagagaCowboy"),
        .itemId = ITEM_GAGAGA_COWBOY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAIA_DRAGON_THE_THUNDER_CHARGER] =
    {
        .name = _("GaiaDragonthe"),
        .itemId = ITEM_GAIA_DRAGON_THE_THUNDER_CHARGER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAIA_KNIGHT_THE_FORCE_OF_EARTH] =
    {
        .name = _("GaiaKnightthe"),
        .itemId = ITEM_GAIA_KNIGHT_THE_FORCE_OF_EARTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAIA_THE_DRAGON_CHAMPION] =
    {
        .name = _("GaiatheDragon"),
        .itemId = ITEM_GAIA_THE_DRAGON_CHAMPION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAROTH_LIGHTSWORN_WARRIOR] =
    {
        .name = _("GarothLightsw"),
        .itemId = ITEM_GAROTH_LIGHTSWORN_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GATEWAY_OF_THE_SIX] =
    {
        .name = _("GatewayoftheS"),
        .itemId = ITEM_GATEWAY_OF_THE_SIX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GATLING_DRAGON] =
    {
        .name = _("GatlingDragon"),
        .itemId = ITEM_GATLING_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GAUNTLET_LAUNCHER] =
    {
        .name = _("GauntletLaunc"),
        .itemId = ITEM_GAUNTLET_LAUNCHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEAR_GIGANT_X] =
    {
        .name = _("GearGigantX"),
        .itemId = ITEM_GEAR_GIGANT_X,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARFRIED_THE_IRON_KNIGHT] =
    {
        .name = _("GearfriedtheI"),
        .itemId = ITEM_GEARFRIED_THE_IRON_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIACCELERATOR] =
    {
        .name = _("Geargiacceler"),
        .itemId = ITEM_GEARGIACCELERATOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIAGEAR] =
    {
        .name = _("Geargiagear"),
        .itemId = ITEM_GEARGIAGEAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIANO] =
    {
        .name = _("Geargiano"),
        .itemId = ITEM_GEARGIANO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIANO_MK_II] =
    {
        .name = _("GeargianoMkII"),
        .itemId = ITEM_GEARGIANO_MK_II,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIARMOR] =
    {
        .name = _("Geargiarmor"),
        .itemId = ITEM_GEARGIARMOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARGIARSENAL] =
    {
        .name = _("Geargiarsenal"),
        .itemId = ITEM_GEARGIARSENAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEARTOWN] =
    {
        .name = _("Geartown"),
        .itemId = ITEM_GEARTOWN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEM_KNIGHT_PEARL] =
    {
        .name = _("GemKnightPear"),
        .itemId = ITEM_GEM_KNIGHT_PEARL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEMINI_ELF] =
    {
        .name = _("GeminiElf"),
        .itemId = ITEM_GEMINI_ELF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEMINI_IMPS] =
    {
        .name = _("GeminiImps"),
        .itemId = ITEM_GEMINI_IMPS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GEMINI_SPARK] =
    {
        .name = _("GeminiSpark"),
        .itemId = ITEM_GEMINI_SPARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GENERATION_SHIFT] =
    {
        .name = _("GenerationShi"),
        .itemId = ITEM_GENERATION_SHIFT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GENEX_ALLY_BIRDMAN] =
    {
        .name = _("GenexAllyBird"),
        .itemId = ITEM_GENEX_ALLY_BIRDMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GENEX_CONTROLLER] =
    {
        .name = _("GenexControll"),
        .itemId = ITEM_GENEX_CONTROLLER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GENEX_UNDINE] =
    {
        .name = _("GenexUndine"),
        .itemId = ITEM_GENEX_UNDINE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GHOSTRICK_ALUCARD] =
    {
        .name = _("GhostrickAluc"),
        .itemId = ITEM_GHOSTRICK_ALUCARD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIANT_GERM] =
    {
        .name = _("GiantGerm"),
        .itemId = ITEM_GIANT_GERM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIANT_ORC] =
    {
        .name = _("GiantOrc"),
        .itemId = ITEM_GIANT_ORC,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIANT_RAT] =
    {
        .name = _("GiantRat"),
        .itemId = ITEM_GIANT_RAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIANT_SOLDIER_OF_STONE] =
    {
        .name = _("GiantSoldiero"),
        .itemId = ITEM_GIANT_SOLDIER_OF_STONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIANT_TRUNADE] =
    {
        .name = _("GiantTrunade"),
        .itemId = ITEM_GIANT_TRUNADE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIGA_TECH_WOLF] =
    {
        .name = _("GigaTechWolf"),
        .itemId = ITEM_GIGA_TECH_WOLF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIGANTES] =
    {
        .name = _("Gigantes"),
        .itemId = ITEM_GIGANTES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GIGAPLANT] =
    {
        .name = _("Gigaplant"),
        .itemId = ITEM_GIGAPLANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GILASAURUS] =
    {
        .name = _("Gilasaurus"),
        .itemId = ITEM_GILASAURUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GILTIA_THE_D_KNIGHT] =
    {
        .name = _("GiltiatheDKni"),
        .itemId = ITEM_GILTIA_THE_D_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_BESTIARI] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_BESTIARI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_DARIUS] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_DARIUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_EQUESTE] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_EQUESTE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_GAIODIAZ] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_GAIODIAZ,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_GYZARUS] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_GYZARUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_HERAKLINOS] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_HERAKLINOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_HOPLOMUS] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_HOPLOMUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_LAQUARI] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_LAQUARI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_MURMILLO] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_MURMILLO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_RETIARI] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_RETIARI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_SAMNITE] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_SAMNITE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_SECUTOR] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_SECUTOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_WAR_CHARIOT] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_WAR_CHARIOT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_BEAST_S_RESPITE] =
    {
        .name = _("GladiatorBeas"),
        .itemId = ITEM_GLADIATOR_BEAST_S_RESPITE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLADIATOR_PROVING_GROUND] =
    {
        .name = _("GladiatorProv"),
        .itemId = ITEM_GLADIATOR_PROVING_GROUND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GLOW_UP_BULB] =
    {
        .name = _("GlowUpBulb"),
        .itemId = ITEM_GLOW_UP_BULB,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOBLIN_ATTACK_FORCE] =
    {
        .name = _("GoblinAttackF"),
        .itemId = ITEM_GOBLIN_ATTACK_FORCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOBLIN_ZOMBIE] =
    {
        .name = _("GoblinZombie"),
        .itemId = ITEM_GOBLIN_ZOMBIE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOLD_SARCOPHAGUS] =
    {
        .name = _("GoldSarcophag"),
        .itemId = ITEM_GOLD_SARCOPHAGUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOLDD_WU_LORD_OF_DARK_WORLD] =
    {
        .name = _("GolddWuLordof"),
        .itemId = ITEM_GOLDD_WU_LORD_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOOD_GOBLIN_HOUSEKEEPING] =
    {
        .name = _("GoodGoblinHou"),
        .itemId = ITEM_GOOD_GOBLIN_HOUSEKEEPING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GORZ_THE_EMISSARY_OF_DARKNESS] =
    {
        .name = _("GorztheEmissa"),
        .itemId = ITEM_GORZ_THE_EMISSARY_OF_DARKNESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOTTOMS_EMERGENCY_CALL] =
    {
        .name = _("GottomsEmerge"),
        .itemId = ITEM_GOTTOMS_EMERGENCY_CALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOYO_GUARDIAN] =
    {
        .name = _("GoyoGuardian"),
        .itemId = ITEM_GOYO_GUARDIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GOZEN_MATCH] =
    {
        .name = _("GozenMatch"),
        .itemId = ITEM_GOZEN_MATCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRACEFUL_CHARITY] =
    {
        .name = _("GracefulChari"),
        .itemId = ITEM_GRACEFUL_CHARITY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRANDMASTER_OF_THE_SIX_SAMURAI] =
    {
        .name = _("Grandmasterof"),
        .itemId = ITEM_GRANDMASTER_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRANDSOIL_THE_ELEMENTAL_LORD] =
    {
        .name = _("GrandsoiltheE"),
        .itemId = ITEM_GRANDSOIL_THE_ELEMENTAL_LORD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAPHA_DRAGON_LORD_OF_DARK_WORLD] =
    {
        .name = _("GraphaDragonL"),
        .itemId = ITEM_GRAPHA_DRAGON_LORD_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_ASSAILANT] =
    {
        .name = _("GravekeepersA"),
        .itemId = ITEM_GRAVEKEEPER_S_ASSAILANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_COMMANDANT] =
    {
        .name = _("GravekeepersC"),
        .itemId = ITEM_GRAVEKEEPER_S_COMMANDANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_DESCENDANT] =
    {
        .name = _("GravekeepersD"),
        .itemId = ITEM_GRAVEKEEPER_S_DESCENDANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_GUARD] =
    {
        .name = _("GravekeepersG"),
        .itemId = ITEM_GRAVEKEEPER_S_GUARD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_RECRUITER] =
    {
        .name = _("GravekeepersR"),
        .itemId = ITEM_GRAVEKEEPER_S_RECRUITER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_SPEAR_SOLDIER] =
    {
        .name = _("GravekeepersS"),
        .itemId = ITEM_GRAVEKEEPER_S_SPEAR_SOLDIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_SPY] =
    {
        .name = _("GravekeepersS"),
        .itemId = ITEM_GRAVEKEEPER_S_SPY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_STELE] =
    {
        .name = _("GravekeepersS"),
        .itemId = ITEM_GRAVEKEEPER_S_STELE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVEKEEPER_S_WATCHER] =
    {
        .name = _("GravekeepersW"),
        .itemId = ITEM_GRAVEKEEPER_S_WATCHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GRAVITY_BIND] =
    {
        .name = _("GravityBind"),
        .itemId = ITEM_GRAVITY_BIND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GREAT_SHOGUN_SHIEN] =
    {
        .name = _("GreatShogunSh"),
        .itemId = ITEM_GREAT_SHOGUN_SHIEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GREAT_WHITE] =
    {
        .name = _("GreatWhite"),
        .itemId = ITEM_GREAT_WHITE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GREEN_BABOON_DEFENDER_OF_THE_FOREST] =
    {
        .name = _("GreenBaboonDe"),
        .itemId = ITEM_GREEN_BABOON_DEFENDER_OF_THE_FOREST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GREEN_GADGET] =
    {
        .name = _("GreenGadget"),
        .itemId = ITEM_GREEN_GADGET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GUNGNIR_DRAGON_OF_THE_ICE_BARRIER] =
    {
        .name = _("GungnirDragon"),
        .itemId = ITEM_GUNGNIR_DRAGON_OF_THE_ICE_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GYAKU_GIRE_PANDA] =
    {
        .name = _("GyakuGirePand"),
        .itemId = ITEM_GYAKU_GIRE_PANDA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_GYAKUTENNO_MEGAMI] =
    {
        .name = _("GyakutennoMeg"),
        .itemId = ITEM_GYAKUTENNO_MEGAMI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HALLOWED_LIFE_BARRIER] =
    {
        .name = _("HallowedLifeB"),
        .itemId = ITEM_HALLOWED_LIFE_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HAMMER_SHOT] =
    {
        .name = _("HammerShot"),
        .itemId = ITEM_HAMMER_SHOT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HAND_DESTRUCTION] =
    {
        .name = _("HandDestructi"),
        .itemId = ITEM_HAND_DESTRUCTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HANE_HANE] =
    {
        .name = _("HaneHane"),
        .itemId = ITEM_HANE_HANE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HANEWATA] =
    {
        .name = _("Hanewata"),
        .itemId = ITEM_HANEWATA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HARPIE_S_FEATHER_DUSTER] =
    {
        .name = _("HarpiesFeathe"),
        .itemId = ITEM_HARPIE_S_FEATHER_DUSTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HEAVY_STORM] =
    {
        .name = _("HeavyStorm"),
        .itemId = ITEM_HEAVY_STORM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HERALD_OF_GREEN_LIGHT] =
    {
        .name = _("HeraldofGreen"),
        .itemId = ITEM_HERALD_OF_GREEN_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HERALD_OF_ORANGE_LIGHT] =
    {
        .name = _("HeraldofOrang"),
        .itemId = ITEM_HERALD_OF_ORANGE_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HERALD_OF_PURE_LIGHT] =
    {
        .name = _("HeraldofPureL"),
        .itemId = ITEM_HERALD_OF_PURE_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HERO_S_RULE_2] =
    {
        .name = _("HerosRule2"),
        .itemId = ITEM_HERO_S_RULE_2,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HEROIC_CHAMPION_EXCALIBUR] =
    {
        .name = _("HeroicChampio"),
        .itemId = ITEM_HEROIC_CHAMPION_EXCALIBUR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIDDEN_ARMORY] =
    {
        .name = _("HiddenArmory"),
        .itemId = ITEM_HIDDEN_ARMORY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_DRAGON_KING_OF_ATUM] =
    {
        .name = _("HieraticDrago"),
        .itemId = ITEM_HIERATIC_DRAGON_KING_OF_ATUM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_DRAGON_OF_ESET] =
    {
        .name = _("HieraticDrago"),
        .itemId = ITEM_HIERATIC_DRAGON_OF_ESET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_DRAGON_OF_SU] =
    {
        .name = _("HieraticDrago"),
        .itemId = ITEM_HIERATIC_DRAGON_OF_SU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_DRAGON_OF_TEFNUIT] =
    {
        .name = _("HieraticDrago"),
        .itemId = ITEM_HIERATIC_DRAGON_OF_TEFNUIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_SEAL_FROM_THE_ASHES] =
    {
        .name = _("HieraticSealF"),
        .itemId = ITEM_HIERATIC_SEAL_FROM_THE_ASHES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_SEAL_OF_CONVOCATION] =
    {
        .name = _("HieraticSealo"),
        .itemId = ITEM_HIERATIC_SEAL_OF_CONVOCATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIERATIC_SUN_DRAGON_OVERLORD_OF_HELIOPOLIS] =
    {
        .name = _("HieraticSunDr"),
        .itemId = ITEM_HIERATIC_SUN_DRAGON_OVERLORD_OF_HELIOPOLIS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIEROPHANT_OF_PROPHECY] =
    {
        .name = _("HierophantofP"),
        .itemId = ITEM_HIEROPHANT_OF_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HIGH_PRIESTESS_OF_PROPHECY] =
    {
        .name = _("HighPriestess"),
        .itemId = ITEM_HIGH_PRIESTESS_OF_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HONEST] =
    {
        .name = _("Honest"),
        .itemId = ITEM_HONEST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HORN_OF_HEAVEN] =
    {
        .name = _("HornofHeaven"),
        .itemId = ITEM_HORN_OF_HEAVEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HORN_OF_THE_PHANTOM_BEAST] =
    {
        .name = _("HornofthePhan"),
        .itemId = ITEM_HORN_OF_THE_PHANTOM_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HORUS_THE_BLACK_FLAME_DRAGON_LV6] =
    {
        .name = _("HorustheBlack"),
        .itemId = ITEM_HORUS_THE_BLACK_FLAME_DRAGON_LV6,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HORUS_THE_BLACK_FLAME_DRAGON_LV8] =
    {
        .name = _("HorustheBlack"),
        .itemId = ITEM_HORUS_THE_BLACK_FLAME_DRAGON_LV8,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HTS_PSYHEMUTH] =
    {
        .name = _("HTSPsyhemuth"),
        .itemId = ITEM_HTS_PSYHEMUTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HUNDRED_EYES_DRAGON] =
    {
        .name = _("HundredEyesDr"),
        .itemId = ITEM_HUNDRED_EYES_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_HYDROGEDDON] =
    {
        .name = _("Hydrogeddon"),
        .itemId = ITEM_HYDROGEDDON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ICARUS_ATTACK] =
    {
        .name = _("IcarusAttack"),
        .itemId = ITEM_ICARUS_ATTACK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ICE_HAND] =
    {
        .name = _("IceHand"),
        .itemId = ITEM_ICE_HAND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_IL_BLUD] =
    {
        .name = _("IlBlud"),
        .itemId = ITEM_IL_BLUD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_IMPERIAL_IRON_WALL] =
    {
        .name = _("ImperialIronW"),
        .itemId = ITEM_IMPERIAL_IRON_WALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_IMPERIAL_ORDER] =
    {
        .name = _("ImperialOrder"),
        .itemId = ITEM_IMPERIAL_ORDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_ARCHFIEND] =
    {
        .name = _("InfernityArch"),
        .itemId = ITEM_INFERNITY_ARCHFIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_AVENGER] =
    {
        .name = _("InfernityAven"),
        .itemId = ITEM_INFERNITY_AVENGER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_BARRIER] =
    {
        .name = _("InfernityBarr"),
        .itemId = ITEM_INFERNITY_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_BEETLE] =
    {
        .name = _("InfernityBeet"),
        .itemId = ITEM_INFERNITY_BEETLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_BREAK] =
    {
        .name = _("InfernityBrea"),
        .itemId = ITEM_INFERNITY_BREAK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_DOOM_DRAGON] =
    {
        .name = _("InfernityDoom"),
        .itemId = ITEM_INFERNITY_DOOM_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_INFERNO] =
    {
        .name = _("InfernityInfe"),
        .itemId = ITEM_INFERNITY_INFERNO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_LAUNCHER] =
    {
        .name = _("InfernityLaun"),
        .itemId = ITEM_INFERNITY_LAUNCHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_MIRAGE] =
    {
        .name = _("InfernityMira"),
        .itemId = ITEM_INFERNITY_MIRAGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFERNITY_NECROMANCER] =
    {
        .name = _("InfernityNecr"),
        .itemId = ITEM_INFERNITY_NECROMANCER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFESTATION_INFECTION] =
    {
        .name = _("InfestationIn"),
        .itemId = ITEM_INFESTATION_INFECTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFESTATION_PANDEMIC] =
    {
        .name = _("InfestationPa"),
        .itemId = ITEM_INFESTATION_PANDEMIC,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INFESTATION_TERMINUS] =
    {
        .name = _("InfestationTe"),
        .itemId = ITEM_INFESTATION_TERMINUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INJECTION_FAIRY_LILY] =
    {
        .name = _("InjectionFair"),
        .itemId = ITEM_INJECTION_FAIRY_LILY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INSECT_KNIGHT] =
    {
        .name = _("InsectKnight"),
        .itemId = ITEM_INSECT_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INSTANT_FUSION] =
    {
        .name = _("InstantFusion"),
        .itemId = ITEM_INSTANT_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INZEKTOR_CENTIPEDE] =
    {
        .name = _("InzektorCenti"),
        .itemId = ITEM_INZEKTOR_CENTIPEDE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INZEKTOR_DRAGONFLY] =
    {
        .name = _("InzektorDrago"),
        .itemId = ITEM_INZEKTOR_DRAGONFLY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INZEKTOR_EXA_BEETLE] =
    {
        .name = _("InzektorExaBe"),
        .itemId = ITEM_INZEKTOR_EXA_BEETLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INZEKTOR_HORNET] =
    {
        .name = _("InzektorHorne"),
        .itemId = ITEM_INZEKTOR_HORNET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_INZEKTOR_SWORD_ZEKTKALIBER] =
    {
        .name = _("InzektorSword"),
        .itemId = ITEM_INZEKTOR_SWORD_ZEKTKALIBER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_IRON_CHAIN_DRAGON] =
    {
        .name = _("IronChainDrag"),
        .itemId = ITEM_IRON_CHAIN_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JAIN_LIGHTSWORN_PALADIN] =
    {
        .name = _("JainLightswor"),
        .itemId = ITEM_JAIN_LIGHTSWORN_PALADIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JAR_OF_GREED] =
    {
        .name = _("JarofGreed"),
        .itemId = ITEM_JAR_OF_GREED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JINZO] =
    {
        .name = _("Jinzo"),
        .itemId = ITEM_JINZO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JIRAI_GUMO] =
    {
        .name = _("JiraiGumo"),
        .itemId = ITEM_JIRAI_GUMO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JOWGEN_THE_SPIRITUALIST] =
    {
        .name = _("JowgentheSpir"),
        .itemId = ITEM_JOWGEN_THE_SPIRITUALIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUDGE_MAN] =
    {
        .name = _("JudgeMan"),
        .itemId = ITEM_JUDGE_MAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUDGMENT_DRAGON] =
    {
        .name = _("JudgmentDrago"),
        .itemId = ITEM_JUDGMENT_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUDGMENT_OF_ANUBIS] =
    {
        .name = _("JudgmentofAnu"),
        .itemId = ITEM_JUDGMENT_OF_ANUBIS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUNK_DESTROYER] =
    {
        .name = _("JunkDestroyer"),
        .itemId = ITEM_JUNK_DESTROYER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JURRAC_GUAIBA] =
    {
        .name = _("JurracGuaiba"),
        .itemId = ITEM_JURRAC_GUAIBA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUST_DESSERTS] =
    {
        .name = _("JustDesserts"),
        .itemId = ITEM_JUST_DESSERTS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_JUSTICE_OF_PROPHECY] =
    {
        .name = _("JusticeofProp"),
        .itemId = ITEM_JUSTICE_OF_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KABAZAULS] =
    {
        .name = _("Kabazauls"),
        .itemId = ITEM_KABAZAULS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KAGEMUSHA_OF_THE_SIX_SAMURAI] =
    {
        .name = _("Kagemushaofth"),
        .itemId = ITEM_KAGEMUSHA_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KAGETOKAGE] =
    {
        .name = _("Kagetokage"),
        .itemId = ITEM_KAGETOKAGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_KOMACHI_MDL_224_NINISHI_] =
    {
        .name = _("KarakuriKomac"),
        .itemId = ITEM_KARAKURI_KOMACHI_MDL_224_NINISHI_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_MERCHANT_MDL_177_INASHICHI_] =
    {
        .name = _("KarakuriMerch"),
        .itemId = ITEM_KARAKURI_MERCHANT_MDL_177_INASHICHI_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_MUSO_MDL_818_HAIPA_] =
    {
        .name = _("KarakuriMusom"),
        .itemId = ITEM_KARAKURI_MUSO_MDL_818_HAIPA_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_NINJA_MDL_919_KUICK_] =
    {
        .name = _("KarakuriNinja"),
        .itemId = ITEM_KARAKURI_NINJA_MDL_919_KUICK_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_SHOGUN_MDL_00_BUREI_] =
    {
        .name = _("KarakuriShogu"),
        .itemId = ITEM_KARAKURI_SHOGUN_MDL_00_BUREI_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_SOLDIER_MDL_236_NISAMU_] =
    {
        .name = _("KarakuriSoldi"),
        .itemId = ITEM_KARAKURI_SOLDIER_MDL_236_NISAMU_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_STEEL_SHOGUN_MDL_00X_BUREIDO_] =
    {
        .name = _("KarakuriSteel"),
        .itemId = ITEM_KARAKURI_STEEL_SHOGUN_MDL_00X_BUREIDO_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_STRATEGIST_MDL_248_NISHIPACHI_] =
    {
        .name = _("KarakuriStrat"),
        .itemId = ITEM_KARAKURI_STRATEGIST_MDL_248_NISHIPACHI_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARAKURI_WATCHDOG_MDL_313_SAIZAN_] =
    {
        .name = _("KarakuriWatch"),
        .itemId = ITEM_KARAKURI_WATCHDOG_MDL_313_SAIZAN_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KARBONALA_WARRIOR] =
    {
        .name = _("KarbonalaWarr"),
        .itemId = ITEM_KARBONALA_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KING_DRAGUN] =
    {
        .name = _("KingDragun"),
        .itemId = ITEM_KING_DRAGUN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KING_OF_THE_FERAL_IMPS] =
    {
        .name = _("KingoftheFera"),
        .itemId = ITEM_KING_OF_THE_FERAL_IMPS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KING_TIGER_WANGHU] =
    {
        .name = _("KingTigerWang"),
        .itemId = ITEM_KING_TIGER_WANGHU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KOA_KI_MEIRU_DRAGO] =
    {
        .name = _("KoakiMeiruDra"),
        .itemId = ITEM_KOA_KI_MEIRU_DRAGO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KREBONS] =
    {
        .name = _("Krebons"),
        .itemId = ITEM_KREBONS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KURIBOH] =
    {
        .name = _("Kuriboh"),
        .itemId = ITEM_KURIBOH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KWAGAR_HERCULES] =
    {
        .name = _("KwagarHercule"),
        .itemId = ITEM_KWAGAR_HERCULES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_KYCOO_THE_GHOST_DESTROYER] =
    {
        .name = _("KycootheGhost"),
        .itemId = ITEM_KYCOO_THE_GHOST_DESTROYER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP] =
    {
        .name = _("LaJinntheMyst"),
        .itemId = ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LABRADORITE_DRAGON] =
    {
        .name = _("LabradoriteDr"),
        .itemId = ITEM_LABRADORITE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LABYRINTH_TANK] =
    {
        .name = _("LabyrinthTank"),
        .itemId = ITEM_LABYRINTH_TANK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LAST_DAY_OF_WITCH] =
    {
        .name = _("LastDayofWitc"),
        .itemId = ITEM_LAST_DAY_OF_WITCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LAST_WILL] =
    {
        .name = _("LastWill"),
        .itemId = ITEM_LAST_WILL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LAVA_GOLEM] =
    {
        .name = _("LavaGolem"),
        .itemId = ITEM_LAVA_GOLEM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LAVALVAL_CHAIN] =
    {
        .name = _("LavalvalChain"),
        .itemId = ITEM_LAVALVAL_CHAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEECHING_THE_LIGHT] =
    {
        .name = _("LeechingtheLi"),
        .itemId = ITEM_LEECHING_THE_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE] =
    {
        .name = _("LeftArmoftheF"),
        .itemId = ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE] =
    {
        .name = _("LeftLegoftheF"),
        .itemId = ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEGACY_OF_YATA_GARASU] =
    {
        .name = _("LegacyofYataG"),
        .itemId = ITEM_LEGACY_OF_YATA_GARASU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEGENDARY_JUJITSU_MASTER] =
    {
        .name = _("LegendaryJuji"),
        .itemId = ITEM_LEGENDARY_JUJITSU_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEGENDARY_SIX_SAMURAI_KAGEKI] =
    {
        .name = _("LegendarySixS"),
        .itemId = ITEM_LEGENDARY_SIX_SAMURAI_KAGEKI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEGENDARY_SIX_SAMURAI_KIZAN] =
    {
        .name = _("LegendarySixS"),
        .itemId = ITEM_LEGENDARY_SIX_SAMURAI_KIZAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEGENDARY_SIX_SAMURAI_SHI_EN] =
    {
        .name = _("LegendarySixS"),
        .itemId = ITEM_LEGENDARY_SIX_SAMURAI_SHI_EN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEO_THE_KEEPER_OF_THE_SACRED_TREE] =
    {
        .name = _("LeotheKeepero"),
        .itemId = ITEM_LEO_THE_KEEPER_OF_THE_SACRED_TREE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEVEL_LIMIT_AREA_B] =
    {
        .name = _("LevelLimitAre"),
        .itemId = ITEM_LEVEL_LIMIT_AREA_B,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LEVIAIR_THE_SEA_DRAGON] =
    {
        .name = _("LeviairtheSea"),
        .itemId = ITEM_LEVIAIR_THE_SEA_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIGHT_AND_DARKNESS_DRAGON] =
    {
        .name = _("LightandDarkn"),
        .itemId = ITEM_LIGHT_AND_DARKNESS_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIGHT_IMPRISONING_MIRROR] =
    {
        .name = _("LightImprison"),
        .itemId = ITEM_LIGHT_IMPRISONING_MIRROR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIGHTNING_VORTEX] =
    {
        .name = _("LightningVort"),
        .itemId = ITEM_LIGHTNING_VORTEX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIGHTNING_DRAGON_RULER_OF_DRAFTS] =
    {
        .name = _("LightningDrag"),
        .itemId = ITEM_LIGHTNING_DRAGON_RULER_OF_DRAFTS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIGHTPULSAR_DRAGON] =
    {
        .name = _("LightpulsarDr"),
        .itemId = ITEM_LIGHTPULSAR_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIMIT_REVERSE] =
    {
        .name = _("LimitReverse"),
        .itemId = ITEM_LIMIT_REVERSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LIMITER_REMOVAL] =
    {
        .name = _("LimiterRemova"),
        .itemId = ITEM_LIMITER_REMOVAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LONEFIRE_BLOSSOM] =
    {
        .name = _("LonefireBloss"),
        .itemId = ITEM_LONEFIRE_BLOSSOM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LUMINA_LIGHTSWORN_SUMMONER] =
    {
        .name = _("LuminaLightsw"),
        .itemId = ITEM_LUMINA_LIGHTSWORN_SUMMONER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_LYLA_LIGHTSWORN_SORCERESS] =
    {
        .name = _("LylaLightswor"),
        .itemId = ITEM_LYLA_LIGHTSWORN_SORCERESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACHINA_CANNON] =
    {
        .name = _("MachinaCannon"),
        .itemId = ITEM_MACHINA_CANNON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACHINA_FORCE] =
    {
        .name = _("MachinaForce"),
        .itemId = ITEM_MACHINA_FORCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACHINA_FORTRESS] =
    {
        .name = _("MachinaFortre"),
        .itemId = ITEM_MACHINA_FORTRESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACHINA_GEARFRAME] =
    {
        .name = _("MachinaGearfr"),
        .itemId = ITEM_MACHINA_GEARFRAME,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACHINE_DUPLICATION] =
    {
        .name = _("MachineDuplic"),
        .itemId = ITEM_MACHINE_DUPLICATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MACRO_COSMOS] =
    {
        .name = _("MacroCosmos"),
        .itemId = ITEM_MACRO_COSMOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MADOLCHE_MAGILEINE] =
    {
        .name = _("MadolcheMagil"),
        .itemId = ITEM_MADOLCHE_MAGILEINE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAESTROKE_THE_SYMPHONY_DJINN] =
    {
        .name = _("MaestroketheS"),
        .itemId = ITEM_MAESTROKE_THE_SYMPHONY_DJINN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGE_POWER] =
    {
        .name = _("MagePower"),
        .itemId = ITEM_MAGE_POWER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGIC_CYLINDER] =
    {
        .name = _("MagicCylinder"),
        .itemId = ITEM_MAGIC_CYLINDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGIC_JAMMER] =
    {
        .name = _("MagicJammer"),
        .itemId = ITEM_MAGIC_JAMMER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_ANDROID] =
    {
        .name = _("MagicalAndroi"),
        .itemId = ITEM_MAGICAL_ANDROID,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_EXPLOSION] =
    {
        .name = _("MagicalExplos"),
        .itemId = ITEM_MAGICAL_EXPLOSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_MALLET] =
    {
        .name = _("MagicalMallet"),
        .itemId = ITEM_MAGICAL_MALLET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_MERCHANT] =
    {
        .name = _("MagicalMercha"),
        .itemId = ITEM_MAGICAL_MERCHANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_SCIENTIST] =
    {
        .name = _("MagicalScient"),
        .itemId = ITEM_MAGICAL_SCIENTIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICAL_STONE_EXCAVATION] =
    {
        .name = _("MagicalStoneE"),
        .itemId = ITEM_MAGICAL_STONE_EXCAVATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAGICIAN_OF_FAITH] =
    {
        .name = _("MagicianofFai"),
        .itemId = ITEM_MAGICIAN_OF_FAITH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MALEFIC_CYBER_END_DRAGON] =
    {
        .name = _("MaleficCyberE"),
        .itemId = ITEM_MALEFIC_CYBER_END_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MALEFIC_STARDUST_DRAGON] =
    {
        .name = _("MaleficStardu"),
        .itemId = ITEM_MALEFIC_STARDUST_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MALEVOLENT_CATASTROPHE] =
    {
        .name = _("MalevolentCat"),
        .itemId = ITEM_MALEVOLENT_CATASTROPHE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAN_EATER_BUG] =
    {
        .name = _("ManEaterBug"),
        .itemId = ITEM_MAN_EATER_BUG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS] =
    {
        .name = _("ManjuoftheTen"),
        .itemId = ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MARK_OF_THE_ROSE] =
    {
        .name = _("MarkoftheRose"),
        .itemId = ITEM_MARK_OF_THE_ROSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MARSHMALLON] =
    {
        .name = _("Marshmallon"),
        .itemId = ITEM_MARSHMALLON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASK_OF_DARKNESS] =
    {
        .name = _("MaskofDarknes"),
        .itemId = ITEM_MASK_OF_DARKNESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASK_OF_RESTRICT] =
    {
        .name = _("MaskofRestric"),
        .itemId = ITEM_MASK_OF_RESTRICT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASKED_SORCERER] =
    {
        .name = _("MaskedSorcere"),
        .itemId = ITEM_MASKED_SORCERER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASS_DRIVER] =
    {
        .name = _("MassDriver"),
        .itemId = ITEM_MASS_DRIVER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASTER_HYPERION] =
    {
        .name = _("MasterHyperio"),
        .itemId = ITEM_MASTER_HYPERION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MASTER_OF_OZ] =
    {
        .name = _("MasterofOz"),
        .itemId = ITEM_MASTER_OF_OZ,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MAXX_C_] =
    {
        .name = _("MaxxC"),
        .itemId = ITEM_MAXX_C_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MECHA_PHANTOM_BEAST_DRACOSSACK] =
    {
        .name = _("MechaPhantomB"),
        .itemId = ITEM_MECHA_PHANTOM_BEAST_DRACOSSACK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MECHA_DOG_MARRON] =
    {
        .name = _("MechaDogMarro"),
        .itemId = ITEM_MECHA_DOG_MARRON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MECHANICALCHASER] =
    {
        .name = _("Mechanicalcha"),
        .itemId = ITEM_MECHANICALCHASER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MECHQUIPPED_ANGINEER] =
    {
        .name = _("MechquippedAn"),
        .itemId = ITEM_MECHQUIPPED_ANGINEER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MEGAMORPH] =
    {
        .name = _("Megamorph"),
        .itemId = ITEM_MEGAMORPH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MEI_KOU_MASTER_OF_BARRIERS] =
    {
        .name = _("MeiKouMastero"),
        .itemId = ITEM_MEI_KOU_MASTER_OF_BARRIERS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSGAIOS] =
    {
        .name = _("MermailAbyssg"),
        .itemId = ITEM_MERMAIL_ABYSSGAIOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSGUNDE] =
    {
        .name = _("MermailAbyssg"),
        .itemId = ITEM_MERMAIL_ABYSSGUNDE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSLEED] =
    {
        .name = _("MermailAbyssl"),
        .itemId = ITEM_MERMAIL_ABYSSLEED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSLINDE] =
    {
        .name = _("MermailAbyssl"),
        .itemId = ITEM_MERMAIL_ABYSSLINDE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSMEGALO] =
    {
        .name = _("MermailAbyssm"),
        .itemId = ITEM_MERMAIL_ABYSSMEGALO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSPIKE] =
    {
        .name = _("MermailAbyssp"),
        .itemId = ITEM_MERMAIL_ABYSSPIKE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSTEUS] =
    {
        .name = _("MermailAbysst"),
        .itemId = ITEM_MERMAIL_ABYSSTEUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSTRITE] =
    {
        .name = _("MermailAbysst"),
        .itemId = ITEM_MERMAIL_ABYSSTRITE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MERMAIL_ABYSSTURGE] =
    {
        .name = _("MermailAbysst"),
        .itemId = ITEM_MERMAIL_ABYSSTURGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MESSENGER_OF_PEACE] =
    {
        .name = _("MessengerofPe"),
        .itemId = ITEM_MESSENGER_OF_PEACE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_METAION_THE_TIMELORD] =
    {
        .name = _("MetaiontheTim"),
        .itemId = ITEM_METAION_THE_TIMELORD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_METAL_ARMORED_BUG] =
    {
        .name = _("MetalArmoredB"),
        .itemId = ITEM_METAL_ARMORED_BUG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_METAL_DRAGON] =
    {
        .name = _("MetalDragon"),
        .itemId = ITEM_METAL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_METAMORPHOSIS] =
    {
        .name = _("Metamorphosis"),
        .itemId = ITEM_METAMORPHOSIS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MEZUKI] =
    {
        .name = _("Mezuki"),
        .itemId = ITEM_MEZUKI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MINAR] =
    {
        .name = _("Minar"),
        .itemId = ITEM_MINAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIND_CONTROL] =
    {
        .name = _("MindControl"),
        .itemId = ITEM_MIND_CONTROL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIND_CRUSH] =
    {
        .name = _("MindCrush"),
        .itemId = ITEM_MIND_CRUSH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIND_DRAIN] =
    {
        .name = _("MindDrain"),
        .itemId = ITEM_MIND_DRAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIRACLE_FERTILIZER] =
    {
        .name = _("MiracleFertil"),
        .itemId = ITEM_MIRACLE_FERTILIZER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIRACLE_FUSION] =
    {
        .name = _("MiracleFusion"),
        .itemId = ITEM_MIRACLE_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIRAGE_OF_NIGHTMARE] =
    {
        .name = _("MirageofNight"),
        .itemId = ITEM_MIRAGE_OF_NIGHTMARE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIRROR_FORCE] =
    {
        .name = _("MirrorForce"),
        .itemId = ITEM_MIRROR_FORCE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIRROR_OF_OATHS] =
    {
        .name = _("MirrorofOaths"),
        .itemId = ITEM_MIRROR_OF_OATHS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MIST_WURM] =
    {
        .name = _("MistWurm"),
        .itemId = ITEM_MIST_WURM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MOBIUS_THE_FROST_MONARCH] =
    {
        .name = _("MobiustheFros"),
        .itemId = ITEM_MOBIUS_THE_FROST_MONARCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MONSTER_GATE] =
    {
        .name = _("MonsterGate"),
        .itemId = ITEM_MONSTER_GATE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MONSTER_REBORN] =
    {
        .name = _("MonsterReborn"),
        .itemId = ITEM_MONSTER_REBORN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MONSTER_REINCARNATION] =
    {
        .name = _("MonsterReinca"),
        .itemId = ITEM_MONSTER_REINCARNATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MORAY_OF_GREED] =
    {
        .name = _("MorayofGreed"),
        .itemId = ITEM_MORAY_OF_GREED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MORPHING_JAR] =
    {
        .name = _("MorphingJar"),
        .itemId = ITEM_MORPHING_JAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MOTHER_GRIZZLY] =
    {
        .name = _("MotherGrizzly"),
        .itemId = ITEM_MOTHER_GRIZZLY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MOULINGLACIA_THE_ELEMENTAL_LORD] =
    {
        .name = _("Moulinglaciat"),
        .itemId = ITEM_MOULINGLACIA_THE_ELEMENTAL_LORD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MUKA_MUKA] =
    {
        .name = _("MukaMuka"),
        .itemId = ITEM_MUKA_MUKA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MUSICIAN_KING] =
    {
        .name = _("MusicianKing"),
        .itemId = ITEM_MUSICIAN_KING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MY_BODY_AS_A_SHIELD] =
    {
        .name = _("MyBodyasaShie"),
        .itemId = ITEM_MY_BODY_AS_A_SHIELD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTIC_SWORDSMAN_LV2] =
    {
        .name = _("MysticSwordsm"),
        .itemId = ITEM_MYSTIC_SWORDSMAN_LV2,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTIC_TOMATO] =
    {
        .name = _("MysticTomato"),
        .itemId = ITEM_MYSTIC_TOMATO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTICAL_ELF] =
    {
        .name = _("MysticalElf"),
        .itemId = ITEM_MYSTICAL_ELF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTICAL_REFPANEL] =
    {
        .name = _("MysticalRefpa"),
        .itemId = ITEM_MYSTICAL_REFPANEL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTICAL_SHINE_BALL] =
    {
        .name = _("MysticalShine"),
        .itemId = ITEM_MYSTICAL_SHINE_BALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTICAL_SPACE_TYPHOON] =
    {
        .name = _("MysticalSpace"),
        .itemId = ITEM_MYSTICAL_SPACE_TYPHOON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYSTIK_WOK] =
    {
        .name = _("MystikWok"),
        .itemId = ITEM_MYSTIK_WOK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYTHIC_TREE_DRAGON] =
    {
        .name = _("MythicTreeDra"),
        .itemId = ITEM_MYTHIC_TREE_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_MYTHIC_WATER_DRAGON] =
    {
        .name = _("MythicWaterDr"),
        .itemId = ITEM_MYTHIC_WATER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NATURIA_BARKION] =
    {
        .name = _("NaturiaBarkio"),
        .itemId = ITEM_NATURIA_BARKION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NATURIA_BEAST] =
    {
        .name = _("NaturiaBeast"),
        .itemId = ITEM_NATURIA_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NECRO_GARDNA] =
    {
        .name = _("NecroGardna"),
        .itemId = ITEM_NECRO_GARDNA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NECROVALLEY] =
    {
        .name = _("Necrovalley"),
        .itemId = ITEM_NECROVALLEY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEEDLE_CEILING] =
    {
        .name = _("NeedleCeiling"),
        .itemId = ITEM_NEEDLE_CEILING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEKO_MANE_KING] =
    {
        .name = _("NekoManeKing"),
        .itemId = ITEM_NEKO_MANE_KING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEO_BUG] =
    {
        .name = _("NeoBug"),
        .itemId = ITEM_NEO_BUG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEO_THE_MAGIC_SWORDSMAN] =
    {
        .name = _("NeotheMagicSw"),
        .itemId = ITEM_NEO_THE_MAGIC_SWORDSMAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEO_SPACIAN_DARK_PANTHER] =
    {
        .name = _("NeoSpacianDar"),
        .itemId = ITEM_NEO_SPACIAN_DARK_PANTHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEO_SPACIAN_GRAND_MOLE] =
    {
        .name = _("NeoSpacianGra"),
        .itemId = ITEM_NEO_SPACIAN_GRAND_MOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NEWDORIA] =
    {
        .name = _("Newdoria"),
        .itemId = ITEM_NEWDORIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NIGHT_ASSAILANT] =
    {
        .name = _("NightAssailan"),
        .itemId = ITEM_NIGHT_ASSAILANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NIGHT_BEAM] =
    {
        .name = _("NightBeam"),
        .itemId = ITEM_NIGHT_BEAM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NIGHTMARE_WHEEL] =
    {
        .name = _("NightmareWhee"),
        .itemId = ITEM_NIGHTMARE_WHEEL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NIMBLE_MOMONGA] =
    {
        .name = _("NimbleMomonga"),
        .itemId = ITEM_NIMBLE_MOMONGA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NINJA_GRANDMASTER_HANZO] =
    {
        .name = _("NinjaGrandmas"),
        .itemId = ITEM_NINJA_GRANDMASTER_HANZO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NINJA_GRANDMASTER_SASUKE] =
    {
        .name = _("NinjaGrandmas"),
        .itemId = ITEM_NINJA_GRANDMASTER_SASUKE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NINJITSU_ART_OF_SUPER_TRANSFORMATION] =
    {
        .name = _("NinjitsuArtof"),
        .itemId = ITEM_NINJITSU_ART_OF_SUPER_TRANSFORMATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NITRO_WARRIOR] =
    {
        .name = _("NitroWarrior"),
        .itemId = ITEM_NITRO_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NOBLEMAN_OF_CROSSOUT] =
    {
        .name = _("NoblemanofCro"),
        .itemId = ITEM_NOBLEMAN_OF_CROSSOUT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NOBLEMAN_OF_EXTERMINATION] =
    {
        .name = _("NoblemanofExt"),
        .itemId = ITEM_NOBLEMAN_OF_EXTERMINATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NON_AGGRESSION_AREA] =
    {
        .name = _("NonAggression"),
        .itemId = ITEM_NON_AGGRESSION_AREA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_101_SILENT_HONOR_ARK] =
    {
        .name = _("Number101Sile"),
        .itemId = ITEM_NUMBER_101_SILENT_HONOR_ARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_103_RAGNAZERO] =
    {
        .name = _("Number103Ragn"),
        .itemId = ITEM_NUMBER_103_RAGNAZERO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_106_GIANT_HAND] =
    {
        .name = _("Number106Gian"),
        .itemId = ITEM_NUMBER_106_GIANT_HAND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_11_BIG_EYE] =
    {
        .name = _("Number11BigEy"),
        .itemId = ITEM_NUMBER_11_BIG_EYE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_16_SHOCK_MASTER] =
    {
        .name = _("Number16Shock"),
        .itemId = ITEM_NUMBER_16_SHOCK_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_17_LEVIATHAN_DRAGON] =
    {
        .name = _("Number17Levia"),
        .itemId = ITEM_NUMBER_17_LEVIATHAN_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_20_GIGA_BRILLIANT] =
    {
        .name = _("Number20GigaB"),
        .itemId = ITEM_NUMBER_20_GIGA_BRILLIANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_30_ACID_GOLEM_OF_DESTRUCTION] =
    {
        .name = _("Number30AcidG"),
        .itemId = ITEM_NUMBER_30_ACID_GOLEM_OF_DESTRUCTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_39_UTOPIA] =
    {
        .name = _("Number39Utopi"),
        .itemId = ITEM_NUMBER_39_UTOPIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_47_NIGHTMARE_SHARK] =
    {
        .name = _("Number47Night"),
        .itemId = ITEM_NUMBER_47_NIGHTMARE_SHARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_50_BLACKSHIP_OF_CORN] =
    {
        .name = _("Number50Black"),
        .itemId = ITEM_NUMBER_50_BLACKSHIP_OF_CORN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_61_VOLCASAURUS] =
    {
        .name = _("Number61Volca"),
        .itemId = ITEM_NUMBER_61_VOLCASAURUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_66_MASTER_KEY_BEETLE] =
    {
        .name = _("Number66Maste"),
        .itemId = ITEM_NUMBER_66_MASTER_KEY_BEETLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_80_RHAPSODY_IN_BERSERK] =
    {
        .name = _("Number80Rhaps"),
        .itemId = ITEM_NUMBER_80_RHAPSODY_IN_BERSERK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_82_HEARTLANDRACO] =
    {
        .name = _("Number82Heart"),
        .itemId = ITEM_NUMBER_82_HEARTLANDRACO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_85_CRAZY_BOX] =
    {
        .name = _("Number85Crazy"),
        .itemId = ITEM_NUMBER_85_CRAZY_BOX,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_96_DARK_MIST] =
    {
        .name = _("Number96DarkM"),
        .itemId = ITEM_NUMBER_96_DARK_MIST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_NUMBER_C39_UTOPIA_RAY] =
    {
        .name = _("NumberC39Utop"),
        .itemId = ITEM_NUMBER_C39_UTOPIA_RAY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OJAMA_KING] =
    {
        .name = _("OjamaKing"),
        .itemId = ITEM_OJAMA_KING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OJAMA_KNIGHT] =
    {
        .name = _("OjamaKnight"),
        .itemId = ITEM_OJAMA_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OJAMA_TRIO] =
    {
        .name = _("OjamaTrio"),
        .itemId = ITEM_OJAMA_TRIO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OLD_VINDICTIVE_MAGICIAN] =
    {
        .name = _("OldVindictive"),
        .itemId = ITEM_OLD_VINDICTIVE_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ONE_DAY_OF_PEACE] =
    {
        .name = _("OneDayofPeace"),
        .itemId = ITEM_ONE_DAY_OF_PEACE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ONE_FOR_ONE] =
    {
        .name = _("OneforOne"),
        .itemId = ITEM_ONE_FOR_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ONSLAUGHT_OF_THE_FIRE_KINGS] =
    {
        .name = _("Onslaughtofth"),
        .itemId = ITEM_ONSLAUGHT_OF_THE_FIRE_KINGS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OOKAZI] =
    {
        .name = _("Ookazi"),
        .itemId = ITEM_OOKAZI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ORIENT_DRAGON] =
    {
        .name = _("OrientDragon"),
        .itemId = ITEM_ORIENT_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OVERLOAD_FUSION] =
    {
        .name = _("OverloadFusio"),
        .itemId = ITEM_OVERLOAD_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_OVERWORKED] =
    {
        .name = _("Overworked"),
        .itemId = ITEM_OVERWORKED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PAINFUL_CHOICE] =
    {
        .name = _("PainfulChoice"),
        .itemId = ITEM_PAINFUL_CHOICE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PENGUIN_KNIGHT] =
    {
        .name = _("PenguinKnight"),
        .itemId = ITEM_PENGUIN_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHANTOM_DRAGON] =
    {
        .name = _("PhantomDragon"),
        .itemId = ITEM_PHANTOM_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHANTOM_OF_CHAOS] =
    {
        .name = _("PhantomofChao"),
        .itemId = ITEM_PHANTOM_OF_CHAOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHOENIX_WING_WIND_BLAST] =
    {
        .name = _("PhoenixWingWi"),
        .itemId = ITEM_PHOENIX_WING_WIND_BLAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHOTON_PAPILLOPERATIVE] =
    {
        .name = _("PhotonPapillo"),
        .itemId = ITEM_PHOTON_PAPILLOPERATIVE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHOTON_STRIKE_BOUNZER] =
    {
        .name = _("PhotonStrikeB"),
        .itemId = ITEM_PHOTON_STRIKE_BOUNZER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PHOTON_THRASHER] =
    {
        .name = _("PhotonThrashe"),
        .itemId = ITEM_PHOTON_THRASHER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PIKERU_S_CIRCLE_OF_ENCHANTMENT] =
    {
        .name = _("PikerusCircle"),
        .itemId = ITEM_PIKERU_S_CIRCLE_OF_ENCHANTMENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PLAGUESPREADER_ZOMBIE] =
    {
        .name = _("Plaguespreade"),
        .itemId = ITEM_PLAGUESPREADER_ZOMBIE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POISON_DRAW_FROG] =
    {
        .name = _("PoisonDrawFro"),
        .itemId = ITEM_POISON_DRAW_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POISON_OF_THE_OLD_MAN] =
    {
        .name = _("PoisonoftheOl"),
        .itemId = ITEM_POISON_OF_THE_OLD_MAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POLE_POSITION] =
    {
        .name = _("PolePosition"),
        .itemId = ITEM_POLE_POSITION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POLYMERIZATION] =
    {
        .name = _("Polymerizatio"),
        .itemId = ITEM_POLYMERIZATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POT_OF_AVARICE] =
    {
        .name = _("PotofAvarice"),
        .itemId = ITEM_POT_OF_AVARICE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POT_OF_DUALITY] =
    {
        .name = _("PotofDuality"),
        .itemId = ITEM_POT_OF_DUALITY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POT_OF_GREED] =
    {
        .name = _("PotofGreed"),
        .itemId = ITEM_POT_OF_GREED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_POWER_TOOL_DRAGON] =
    {
        .name = _("PowerToolDrag"),
        .itemId = ITEM_POWER_TOOL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PREMATURE_BURIAL] =
    {
        .name = _("PrematureBuri"),
        .itemId = ITEM_PREMATURE_BURIAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PRIME_MATERIAL_DRAGON] =
    {
        .name = _("PrimeMaterial"),
        .itemId = ITEM_PRIME_MATERIAL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PRINCESS_OF_TSURUGI] =
    {
        .name = _("PrincessofTsu"),
        .itemId = ITEM_PRINCESS_OF_TSURUGI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PROHIBITION] =
    {
        .name = _("Prohibition"),
        .itemId = ITEM_PROHIBITION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PROMETHEUS_KING_OF_THE_SHADOWS] =
    {
        .name = _("PrometheusKin"),
        .itemId = ITEM_PROMETHEUS_KING_OF_THE_SHADOWS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PROTECTOR_OF_THE_SANCTUARY] =
    {
        .name = _("Protectorofth"),
        .itemId = ITEM_PROTECTOR_OF_THE_SANCTUARY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PSI_BLOCKER] =
    {
        .name = _("PsiBlocker"),
        .itemId = ITEM_PSI_BLOCKER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PSYCHIC_COMMANDER] =
    {
        .name = _("PsychicComman"),
        .itemId = ITEM_PSYCHIC_COMMANDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PSYCHIC_LIFETRANCER] =
    {
        .name = _("PsychicLifetr"),
        .itemId = ITEM_PSYCHIC_LIFETRANCER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PULLING_THE_RUG] =
    {
        .name = _("PullingtheRug"),
        .itemId = ITEM_PULLING_THE_RUG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PUNISHED_EAGLE] =
    {
        .name = _("PunishedEagle"),
        .itemId = ITEM_PUNISHED_EAGLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PUPPET_PLANT] =
    {
        .name = _("PuppetPlant"),
        .itemId = ITEM_PUPPET_PLANT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_PYRAMID_TURTLE] =
    {
        .name = _("PyramidTurtle"),
        .itemId = ITEM_PYRAMID_TURTLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_QUEEN_DRAGUN_DJINN] =
    {
        .name = _("QueenDragunDj"),
        .itemId = ITEM_QUEEN_DRAGUN_DJINN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_QUICKDRAW_SYNCHRON] =
    {
        .name = _("QuickdrawSync"),
        .itemId = ITEM_QUICKDRAW_SYNCHRON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RAIGEKI] =
    {
        .name = _("Raigeki"),
        .itemId = ITEM_RAIGEKI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RAIGEKI_BREAK] =
    {
        .name = _("RaigekiBreak"),
        .itemId = ITEM_RAIGEKI_BREAK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RAINBOW_LIFE] =
    {
        .name = _("RainbowLife"),
        .itemId = ITEM_RAINBOW_LIFE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RAIZA_THE_STORM_MONARCH] =
    {
        .name = _("RaizatheStorm"),
        .itemId = ITEM_RAIZA_THE_STORM_MONARCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REACTAN_DRAGON_RULER_OF_PEBBLES] =
    {
        .name = _("ReactanDragon"),
        .itemId = ITEM_REACTAN_DRAGON_RULER_OF_PEBBLES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REAPER_ON_THE_NIGHTMARE] =
    {
        .name = _("ReaperontheNi"),
        .itemId = ITEM_REAPER_ON_THE_NIGHTMARE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REASONING] =
    {
        .name = _("Reasoning"),
        .itemId = ITEM_REASONING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REBORN_TENGU] =
    {
        .name = _("RebornTengu"),
        .itemId = ITEM_REBORN_TENGU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RECKLESS_GREED] =
    {
        .name = _("RecklessGreed"),
        .itemId = ITEM_RECKLESS_GREED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RED_DRAGON_ARCHFIEND] =
    {
        .name = _("RedDragonArch"),
        .itemId = ITEM_RED_DRAGON_ARCHFIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RED_GADGET] =
    {
        .name = _("RedGadget"),
        .itemId = ITEM_RED_GADGET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RED_EYES_DARKNESS_METAL_DRAGON] =
    {
        .name = _("RedEyesDarkne"),
        .itemId = ITEM_RED_EYES_DARKNESS_METAL_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REDOX_DRAGON_RULER_OF_BOULDERS] =
    {
        .name = _("RedoxDragonRu"),
        .itemId = ITEM_REDOX_DRAGON_RULER_OF_BOULDERS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REFLECT_BOUNDER] =
    {
        .name = _("ReflectBounde"),
        .itemId = ITEM_REFLECT_BOUNDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REINFORCE_TRUTH] =
    {
        .name = _("ReinforceTrut"),
        .itemId = ITEM_REINFORCE_TRUTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REINFORCEMENT_OF_THE_ARMY] =
    {
        .name = _("Reinforcement"),
        .itemId = ITEM_REINFORCEMENT_OF_THE_ARMY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REINFORCEMENTS] =
    {
        .name = _("Reinforcement"),
        .itemId = ITEM_REINFORCEMENTS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REKINDLING] =
    {
        .name = _("Rekindling"),
        .itemId = ITEM_REKINDLING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RELINQUISHED] =
    {
        .name = _("Relinquished"),
        .itemId = ITEM_RELINQUISHED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RELOAD] =
    {
        .name = _("Reload"),
        .itemId = ITEM_RELOAD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REMOVE_TRAP] =
    {
        .name = _("RemoveTrap"),
        .itemId = ITEM_REMOVE_TRAP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RESCUE_CAT] =
    {
        .name = _("RescueCat"),
        .itemId = ITEM_RESCUE_CAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RESCUE_RABBIT] =
    {
        .name = _("RescueRabbit"),
        .itemId = ITEM_RESCUE_RABBIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RETORT] =
    {
        .name = _("Retort"),
        .itemId = ITEM_RETORT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION] =
    {
        .name = _("Returnfromthe"),
        .itemId = ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_REVIVED_KING_HA_DES] =
    {
        .name = _("RevivedKingHa"),
        .itemId = ITEM_REVIVED_KING_HA_DES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE] =
    {
        .name = _("RightArmofthe"),
        .itemId = ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE] =
    {
        .name = _("RightLegofthe"),
        .itemId = ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RING_OF_DEFENSE] =
    {
        .name = _("RingofDefense"),
        .itemId = ITEM_RING_OF_DEFENSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RING_OF_DESTRUCTION] =
    {
        .name = _("RingofDestruc"),
        .itemId = ITEM_RING_OF_DESTRUCTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RIVALRY_OF_WARLORDS] =
    {
        .name = _("RivalryofWarl"),
        .itemId = ITEM_RIVALRY_OF_WARLORDS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROARING_OCEAN_SNAKE] =
    {
        .name = _("RoaringOceanS"),
        .itemId = ITEM_ROARING_OCEAN_SNAKE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROBBIN_GOBLIN] =
    {
        .name = _("RobbinGoblin"),
        .itemId = ITEM_ROBBIN_GOBLIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RONINTOADIN] =
    {
        .name = _("Ronintoadin"),
        .itemId = ITEM_RONINTOADIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROSE_WARRIOR_OF_REVENGE] =
    {
        .name = _("RoseWarriorof"),
        .itemId = ITEM_ROSE_WARRIOR_OF_REVENGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROYAL_DECREE] =
    {
        .name = _("RoyalDecree"),
        .itemId = ITEM_ROYAL_DECREE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROYAL_OPPRESSION] =
    {
        .name = _("RoyalOppressi"),
        .itemId = ITEM_ROYAL_OPPRESSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ROYAL_TRIBUTE] =
    {
        .name = _("RoyalTribute"),
        .itemId = ITEM_ROYAL_TRIBUTE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RUSH_RECKLESSLY] =
    {
        .name = _("RushRecklessl"),
        .itemId = ITEM_RUSH_RECKLESSLY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RYKO_LIGHTSWORN_HUNTER] =
    {
        .name = _("RykoLightswor"),
        .itemId = ITEM_RYKO_LIGHTSWORN_HUNTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RYU_KOKKI] =
    {
        .name = _("RyuKokki"),
        .itemId = ITEM_RYU_KOKKI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_RYU_SENSHI] =
    {
        .name = _("RyuSenshi"),
        .itemId = ITEM_RYU_SENSHI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SABER_HOLE] =
    {
        .name = _("SaberHole"),
        .itemId = ITEM_SABER_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SABER_SLASH] =
    {
        .name = _("SaberSlash"),
        .itemId = ITEM_SABER_SLASH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SABERSAURUS] =
    {
        .name = _("Sabersaurus"),
        .itemId = ITEM_SABERSAURUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SACRED_CRANE] =
    {
        .name = _("SacredCrane"),
        .itemId = ITEM_SACRED_CRANE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SACRED_SWORD_OF_SEVEN_STARS] =
    {
        .name = _("SacredSwordof"),
        .itemId = ITEM_SACRED_SWORD_OF_SEVEN_STARS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SAFE_ZONE] =
    {
        .name = _("SafeZone"),
        .itemId = ITEM_SAFE_ZONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SAKURETSU_ARMOR] =
    {
        .name = _("SakuretsuArmo"),
        .itemId = ITEM_SAKURETSU_ARMOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SALVAGE] =
    {
        .name = _("Salvage"),
        .itemId = ITEM_SALVAGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SANGAN] =
    {
        .name = _("Sangan"),
        .itemId = ITEM_SANGAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SANWITCH] =
    {
        .name = _("Sanwitch"),
        .itemId = ITEM_SANWITCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SASUKE_SAMURAI] =
    {
        .name = _("SasukeSamurai"),
        .itemId = ITEM_SASUKE_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCAPEGOAT] =
    {
        .name = _("Scapegoat"),
        .itemId = ITEM_SCAPEGOAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_ARCHFIEND] =
    {
        .name = _("ScrapArchfien"),
        .itemId = ITEM_SCRAP_ARCHFIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_BEAST] =
    {
        .name = _("ScrapBeast"),
        .itemId = ITEM_SCRAP_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_CHIMERA] =
    {
        .name = _("ScrapChimera"),
        .itemId = ITEM_SCRAP_CHIMERA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_DRAGON] =
    {
        .name = _("ScrapDragon"),
        .itemId = ITEM_SCRAP_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_GOBLIN] =
    {
        .name = _("ScrapGoblin"),
        .itemId = ITEM_SCRAP_GOBLIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAP_GOLEM] =
    {
        .name = _("ScrapGolem"),
        .itemId = ITEM_SCRAP_GOLEM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SCRAPSTORM] =
    {
        .name = _("Scrapstorm"),
        .itemId = ITEM_SCRAPSTORM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SEA_DRAGON_LORD_GISHILNODON] =
    {
        .name = _("SeaDragonLord"),
        .itemId = ITEM_SEA_DRAGON_LORD_GISHILNODON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SECRET_BARREL] =
    {
        .name = _("SecretBarrel"),
        .itemId = ITEM_SECRET_BARREL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SELF_DESTRUCT_BUTTON] =
    {
        .name = _("SelfDestructB"),
        .itemId = ITEM_SELF_DESTRUCT_BUTTON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SENJU_OF_THE_THOUSAND_HANDS] =
    {
        .name = _("SenjuoftheTho"),
        .itemId = ITEM_SENJU_OF_THE_THOUSAND_HANDS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SERIAL_SPELL] =
    {
        .name = _("SerialSpell"),
        .itemId = ITEM_SERIAL_SPELL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SEVEN_TOOLS_OF_THE_BANDIT] =
    {
        .name = _("SevenToolsoft"),
        .itemId = ITEM_SEVEN_TOOLS_OF_THE_BANDIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHADOW_IMPRISONING_MIRROR] =
    {
        .name = _("ShadowImpriso"),
        .itemId = ITEM_SHADOW_IMPRISONING_MIRROR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHIEN_S_SMOKE_SIGNAL] =
    {
        .name = _("ShiensSmokeSi"),
        .itemId = ITEM_SHIEN_S_SMOKE_SIGNAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHINING_ANGEL] =
    {
        .name = _("ShiningAngel"),
        .itemId = ITEM_SHINING_ANGEL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHINING_ELF] =
    {
        .name = _("ShiningElf"),
        .itemId = ITEM_SHINING_ELF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHINY_BLACK_C_] =
    {
        .name = _("ShinyBlackC"),
        .itemId = ITEM_SHINY_BLACK_C_,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHOOTING_STAR_DRAGON] =
    {
        .name = _("ShootingStarD"),
        .itemId = ITEM_SHOOTING_STAR_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SHRINK] =
    {
        .name = _("Shrink"),
        .itemId = ITEM_SHRINK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SILLVA_WARLORD_OF_DARK_WORLD] =
    {
        .name = _("SillvaWarlord"),
        .itemId = ITEM_SILLVA_WARLORD_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SINISTER_SERPENT] =
    {
        .name = _("SinisterSerpe"),
        .itemId = ITEM_SINISTER_SERPENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SIX_SAMURAI_UNITED] =
    {
        .name = _("SixSamuraiUni"),
        .itemId = ITEM_SIX_SAMURAI_UNITED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SIXTH_SENSE] =
    {
        .name = _("SixthSense"),
        .itemId = ITEM_SIXTH_SENSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SKILL_DRAIN] =
    {
        .name = _("SkillDrain"),
        .itemId = ITEM_SKILL_DRAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SKILLED_DARK_MAGICIAN] =
    {
        .name = _("SkilledDarkMa"),
        .itemId = ITEM_SKILLED_DARK_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SKULL_KNIGHT] =
    {
        .name = _("SkullKnight"),
        .itemId = ITEM_SKULL_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SKULL_LAIR] =
    {
        .name = _("SkullLair"),
        .itemId = ITEM_SKULL_LAIR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SKULL_MEISTER] =
    {
        .name = _("SkullMeister"),
        .itemId = ITEM_SKULL_MEISTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SMASHING_GROUND] =
    {
        .name = _("SmashingGroun"),
        .itemId = ITEM_SMASHING_GROUND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SNATCH_STEAL] =
    {
        .name = _("SnatchSteal"),
        .itemId = ITEM_SNATCH_STEAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SNIPE_HUNTER] =
    {
        .name = _("SnipeHunter"),
        .itemId = ITEM_SNIPE_HUNTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SNOWMAN_EATER] =
    {
        .name = _("SnowmanEater"),
        .itemId = ITEM_SNOWMAN_EATER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD] =
    {
        .name = _("SnowwUnlighto"),
        .itemId = ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOLAR_RECHARGE] =
    {
        .name = _("SolarRecharge"),
        .itemId = ITEM_SOLAR_RECHARGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOLEMN_JUDGMENT] =
    {
        .name = _("SolemnJudgmen"),
        .itemId = ITEM_SOLEMN_JUDGMENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOLEMN_WARNING] =
    {
        .name = _("SolemnWarning"),
        .itemId = ITEM_SOLEMN_WARNING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOLEMN_WISHES] =
    {
        .name = _("SolemnWishes"),
        .itemId = ITEM_SOLEMN_WISHES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SONIC_BIRD] =
    {
        .name = _("SonicBird"),
        .itemId = ITEM_SONIC_BIRD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_CHARGE] =
    {
        .name = _("SoulCharge"),
        .itemId = ITEM_SOUL_CHARGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_DRAIN] =
    {
        .name = _("SoulDrain"),
        .itemId = ITEM_SOUL_DRAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_EXCHANGE] =
    {
        .name = _("SoulExchange"),
        .itemId = ITEM_SOUL_EXCHANGE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_OF_SILVERMOUNTAIN] =
    {
        .name = _("SoulofSilverm"),
        .itemId = ITEM_SOUL_OF_SILVERMOUNTAIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_RELEASE] =
    {
        .name = _("SoulRelease"),
        .itemId = ITEM_SOUL_RELEASE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SOUL_TAKER] =
    {
        .name = _("SoulTaker"),
        .itemId = ITEM_SOUL_TAKER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPEAR_CRETIN] =
    {
        .name = _("SpearCretin"),
        .itemId = ITEM_SPEAR_CRETIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPEAR_DRAGON] =
    {
        .name = _("SpearDragon"),
        .itemId = ITEM_SPEAR_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELL_CANCELLER] =
    {
        .name = _("SpellCancelle"),
        .itemId = ITEM_SPELL_CANCELLER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELL_ECONOMICS] =
    {
        .name = _("SpellEconomic"),
        .itemId = ITEM_SPELL_ECONOMICS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELL_REPRODUCTION] =
    {
        .name = _("SpellReproduc"),
        .itemId = ITEM_SPELL_REPRODUCTION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELL_SHIELD_TYPE_8] =
    {
        .name = _("SpellShieldTy"),
        .itemId = ITEM_SPELL_SHIELD_TYPE_8,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELL_STRIKER] =
    {
        .name = _("SpellStriker"),
        .itemId = ITEM_SPELL_STRIKER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_LIBRARY_OF_THE_CRESCENT] =
    {
        .name = _("SpellbookLibr"),
        .itemId = ITEM_SPELLBOOK_LIBRARY_OF_THE_CRESCENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_MAGICIAN_OF_PROPHECY] =
    {
        .name = _("SpellbookMagi"),
        .itemId = ITEM_SPELLBOOK_MAGICIAN_OF_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_ETERNITY] =
    {
        .name = _("SpellbookofEt"),
        .itemId = ITEM_SPELLBOOK_OF_ETERNITY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_FATE] =
    {
        .name = _("SpellbookofFa"),
        .itemId = ITEM_SPELLBOOK_OF_FATE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_JUDGMENT] =
    {
        .name = _("SpellbookofJu"),
        .itemId = ITEM_SPELLBOOK_OF_JUDGMENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_LIFE] =
    {
        .name = _("SpellbookofLi"),
        .itemId = ITEM_SPELLBOOK_OF_LIFE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_POWER] =
    {
        .name = _("SpellbookofPo"),
        .itemId = ITEM_SPELLBOOK_OF_POWER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_SECRETS] =
    {
        .name = _("SpellbookofSe"),
        .itemId = ITEM_SPELLBOOK_OF_SECRETS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_THE_MASTER] =
    {
        .name = _("Spellbookofth"),
        .itemId = ITEM_SPELLBOOK_OF_THE_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_OF_WISDOM] =
    {
        .name = _("SpellbookofWi"),
        .itemId = ITEM_SPELLBOOK_OF_WISDOM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPELLBOOK_STAR_HALL] =
    {
        .name = _("SpellbookStar"),
        .itemId = ITEM_SPELLBOOK_STAR_HALL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPIRIT_OF_THE_HARP] =
    {
        .name = _("SpiritoftheHa"),
        .itemId = ITEM_SPIRIT_OF_THE_HARP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPIRIT_OF_THE_SIX_SAMURAI] =
    {
        .name = _("SpiritoftheSi"),
        .itemId = ITEM_SPIRIT_OF_THE_SIX_SAMURAI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPIRIT_REAPER] =
    {
        .name = _("SpiritReaper"),
        .itemId = ITEM_SPIRIT_REAPER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPIRITUAL_WATER_ART_AOI] =
    {
        .name = _("SpiritualWate"),
        .itemId = ITEM_SPIRITUAL_WATER_ART_AOI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPIRITUALISM] =
    {
        .name = _("Spiritualism"),
        .itemId = ITEM_SPIRITUALISM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPLENDID_ROSE] =
    {
        .name = _("SplendidRose"),
        .itemId = ITEM_SPLENDID_ROSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SPORE] =
    {
        .name = _("Spore"),
        .itemId = ITEM_SPORE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ST_JOAN] =
    {
        .name = _("StJoan"),
        .itemId = ITEM_ST_JOAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STAR_EATER] =
    {
        .name = _("StarEater"),
        .itemId = ITEM_STAR_EATER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STARDUST_DRAGON] =
    {
        .name = _("StardustDrago"),
        .itemId = ITEM_STARDUST_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STARDUST_SPARK_DRAGON] =
    {
        .name = _("StardustSpark"),
        .itemId = ITEM_STARDUST_SPARK_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STARLIEGE_PALADYNAMO] =
    {
        .name = _("StarliegePala"),
        .itemId = ITEM_STARLIEGE_PALADYNAMO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STARLIGHT_ROAD] =
    {
        .name = _("StarlightRoad"),
        .itemId = ITEM_STARLIGHT_ROAD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STEALTH_BIRD] =
    {
        .name = _("StealthBird"),
        .itemId = ITEM_STEALTH_BIRD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STEAM_GYROID] =
    {
        .name = _("SteamGyroid"),
        .itemId = ITEM_STEAM_GYROID,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STEELSWARM_ROACH] =
    {
        .name = _("SteelswarmRoa"),
        .itemId = ITEM_STEELSWARM_ROACH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STOP_DEFENSE] =
    {
        .name = _("StopDefense"),
        .itemId = ITEM_STOP_DEFENSE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STREAM_DRAGON_RULER_OF_DROPLETS] =
    {
        .name = _("StreamDragonR"),
        .itemId = ITEM_STREAM_DRAGON_RULER_OF_DROPLETS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STRIKE_NINJA] =
    {
        .name = _("StrikeNinja"),
        .itemId = ITEM_STRIKE_NINJA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STYGIAN_SERGEANTS] =
    {
        .name = _("StygianSergea"),
        .itemId = ITEM_STYGIAN_SERGEANTS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_STYGIAN_STREET_PATROL] =
    {
        .name = _("StygianStreet"),
        .itemId = ITEM_STYGIAN_STREET_PATROL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUBSTITOAD] =
    {
        .name = _("Substitoad"),
        .itemId = ITEM_SUBSTITOAD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUMMON_LIMIT] =
    {
        .name = _("SummonLimit"),
        .itemId = ITEM_SUMMON_LIMIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUMMONED_SKULL] =
    {
        .name = _("SummonedSkull"),
        .itemId = ITEM_SUMMONED_SKULL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUMMONER_MONK] =
    {
        .name = _("SummonerMonk"),
        .itemId = ITEM_SUMMONER_MONK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_POLYMERIZATION] =
    {
        .name = _("SuperPolymeri"),
        .itemId = ITEM_SUPER_POLYMERIZATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_REJUVENATION] =
    {
        .name = _("SuperRejuvena"),
        .itemId = ITEM_SUPER_REJUVENATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_ROBOLADY] =
    {
        .name = _("SuperRobolady"),
        .itemId = ITEM_SUPER_ROBOLADY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_ROBOYAROU] =
    {
        .name = _("SuperRoboyaro"),
        .itemId = ITEM_SUPER_ROBOYAROU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_SOLAR_NUTRIENT] =
    {
        .name = _("SuperSolarNut"),
        .itemId = ITEM_SUPER_SOLAR_NUTRIENT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_VEHICROID_JUMBO_DRILL] =
    {
        .name = _("SuperVehicroi"),
        .itemId = ITEM_SUPER_VEHICROID_JUMBO_DRILL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPER_NIMBLE_MEGA_HAMSTER] =
    {
        .name = _("SuperNimbleMe"),
        .itemId = ITEM_SUPER_NIMBLE_MEGA_HAMSTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SUPERVISE] =
    {
        .name = _("Supervise"),
        .itemId = ITEM_SUPERVISE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SWALLOW_FLIP] =
    {
        .name = _("SwallowFlip"),
        .itemId = ITEM_SWALLOW_FLIP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SWAP_FROG] =
    {
        .name = _("SwapFrog"),
        .itemId = ITEM_SWAP_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SWIFT_SCARECROW] =
    {
        .name = _("SwiftScarecro"),
        .itemId = ITEM_SWIFT_SCARECROW,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SWORDS_OF_REVEALING_LIGHT] =
    {
        .name = _("SwordsofRevea"),
        .itemId = ITEM_SWORDS_OF_REVEALING_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_SYSTEM_DOWN] =
    {
        .name = _("SystemDown"),
        .itemId = ITEM_SYSTEM_DOWN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_HYPER_LIBRARIAN] =
    {
        .name = _("TGHyperLibrar"),
        .itemId = ITEM_T_G_HYPER_LIBRARIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_POWER_GLADIATOR] =
    {
        .name = _("TGPowerGladia"),
        .itemId = ITEM_T_G_POWER_GLADIATOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_RUSH_RHINO] =
    {
        .name = _("TGRushRhino"),
        .itemId = ITEM_T_G_RUSH_RHINO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_STRIKER] =
    {
        .name = _("TGStriker"),
        .itemId = ITEM_T_G_STRIKER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_WARWOLF] =
    {
        .name = _("TGWarwolf"),
        .itemId = ITEM_T_G_WARWOLF,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_T_G_WONDER_MAGICIAN] =
    {
        .name = _("TGWonderMagic"),
        .itemId = ITEM_T_G_WONDER_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TEMPERANCE_OF_PROPHECY] =
    {
        .name = _("TemperanceofP"),
        .itemId = ITEM_TEMPERANCE_OF_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TEMPEST_MAGICIAN] =
    {
        .name = _("TempestMagici"),
        .itemId = ITEM_TEMPEST_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TEMPEST_DRAGON_RULER_OF_STORMS] =
    {
        .name = _("TempestDragon"),
        .itemId = ITEM_TEMPEST_DRAGON_RULER_OF_STORMS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TEMTEMPO_THE_PERCUSSION_DJINN] =
    {
        .name = _("TemtempothePe"),
        .itemId = ITEM_TEMTEMPO_THE_PERCUSSION_DJINN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TERRAFORMING] =
    {
        .name = _("Terraforming"),
        .itemId = ITEM_TERRAFORMING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TEST_TIGER] =
    {
        .name = _("TestTiger"),
        .itemId = ITEM_TEST_TIGER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TG1_EM1] =
    {
        .name = _("TG1EM1"),
        .itemId = ITEM_TG1_EM1,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_AGENT_OF_CREATION_VENUS] =
    {
        .name = _("TheAgentofCre"),
        .itemId = ITEM_THE_AGENT_OF_CREATION_VENUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_AGENT_OF_MIRACLES_JUPITER] =
    {
        .name = _("TheAgentofMir"),
        .itemId = ITEM_THE_AGENT_OF_MIRACLES_JUPITER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_AGENT_OF_MYSTERY_EARTH] =
    {
        .name = _("TheAgentofMys"),
        .itemId = ITEM_THE_AGENT_OF_MYSTERY_EARTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_FABLED_CATSITH] =
    {
        .name = _("TheFabledCats"),
        .itemId = ITEM_THE_FABLED_CATSITH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_FIEND_MEGACYBER] =
    {
        .name = _("TheFiendMegac"),
        .itemId = ITEM_THE_FIEND_MEGACYBER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_FORCEFUL_SENTRY] =
    {
        .name = _("TheForcefulSe"),
        .itemId = ITEM_THE_FORCEFUL_SENTRY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_GATES_OF_DARK_WORLD] =
    {
        .name = _("TheGatesofDar"),
        .itemId = ITEM_THE_GATES_OF_DARK_WORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_GRAND_SPELLBOOK_TOWER] =
    {
        .name = _("TheGrandSpell"),
        .itemId = ITEM_THE_GRAND_SPELLBOOK_TOWER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET] =
    {
        .name = _("TheLastWarrio"),
        .itemId = ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_LIGHT_HEX_SEALED_FUSION] =
    {
        .name = _("TheLightHexSe"),
        .itemId = ITEM_THE_LIGHT_HEX_SEALED_FUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_LITTLE_SWORDSMAN_OF_AILE] =
    {
        .name = _("TheLittleSwor"),
        .itemId = ITEM_THE_LITTLE_SWORDSMAN_OF_AILE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_SIX_SAMURAI_IROU] =
    {
        .name = _("TheSixSamurai"),
        .itemId = ITEM_THE_SIX_SAMURAI_IROU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_SIX_SAMURAI_KAMON] =
    {
        .name = _("TheSixSamurai"),
        .itemId = ITEM_THE_SIX_SAMURAI_KAMON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_SIX_SAMURAI_YAICHI] =
    {
        .name = _("TheSixSamurai"),
        .itemId = ITEM_THE_SIX_SAMURAI_YAICHI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_SIX_SAMURAI_ZANJI] =
    {
        .name = _("TheSixSamurai"),
        .itemId = ITEM_THE_SIX_SAMURAI_ZANJI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_TRANSMIGRATION_PROPHECY] =
    {
        .name = _("TheTransmigra"),
        .itemId = ITEM_THE_TRANSMIGRATION_PROPHECY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_WHITE_STONE_OF_LEGEND] =
    {
        .name = _("TheWhiteStone"),
        .itemId = ITEM_THE_WHITE_STONE_OF_LEGEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THE_WICKED_WORM_BEAST] =
    {
        .name = _("TheWickedWorm"),
        .itemId = ITEM_THE_WICKED_WORM_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THESTALOS_THE_FIRESTORM_MONARCH] =
    {
        .name = _("ThestalostheF"),
        .itemId = ITEM_THESTALOS_THE_FIRESTORM_MONARCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THOUGHT_RULER_ARCHFIEND] =
    {
        .name = _("ThoughtRulerA"),
        .itemId = ITEM_THOUGHT_RULER_ARCHFIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THOUSAND_DRAGON] =
    {
        .name = _("ThousandDrago"),
        .itemId = ITEM_THOUSAND_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THOUSAND_EYES_RESTRICT] =
    {
        .name = _("ThousandEyesR"),
        .itemId = ITEM_THOUSAND_EYES_RESTRICT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THREATENING_ROAR] =
    {
        .name = _("ThreateningRo"),
        .itemId = ITEM_THREATENING_ROAR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THUNDER_DRAGON] =
    {
        .name = _("ThunderDragon"),
        .itemId = ITEM_THUNDER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THUNDER_KING_RAI_OH] =
    {
        .name = _("ThunderKingRa"),
        .itemId = ITEM_THUNDER_KING_RAI_OH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_THUNDER_NYAN_NYAN] =
    {
        .name = _("ThunderNyanNy"),
        .itemId = ITEM_THUNDER_NYAN_NYAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TIDAL_DRAGON_RULER_OF_WATERFALLS] =
    {
        .name = _("TidalDragonRu"),
        .itemId = ITEM_TIDAL_DRAGON_RULER_OF_WATERFALLS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TIME_SEAL] =
    {
        .name = _("TimeSeal"),
        .itemId = ITEM_TIME_SEAL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TIN_GOLDFISH] =
    {
        .name = _("TinGoldfish"),
        .itemId = ITEM_TIN_GOLDFISH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TIRAS_KEEPER_OF_GENESIS] =
    {
        .name = _("TirasKeeperof"),
        .itemId = ITEM_TIRAS_KEEPER_OF_GENESIS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TOON_TABLE_OF_CONTENTS] =
    {
        .name = _("ToonTableofCo"),
        .itemId = ITEM_TOON_TABLE_OF_CONTENTS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TORRENTIAL_TRIBUTE] =
    {
        .name = _("TorrentialTri"),
        .itemId = ITEM_TORRENTIAL_TRIBUTE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TOUR_GUIDE_FROM_THE_UNDERWORLD] =
    {
        .name = _("TourGuideFrom"),
        .itemId = ITEM_TOUR_GUIDE_FROM_THE_UNDERWORLD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRADE_IN] =
    {
        .name = _("TradeIn"),
        .itemId = ITEM_TRADE_IN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAGOEDIA] =
    {
        .name = _("Tragoedia"),
        .itemId = ITEM_TRAGOEDIA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRANCE_ARCHFIEND] =
    {
        .name = _("TranceArchfie"),
        .itemId = ITEM_TRANCE_ARCHFIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAP_DUSTSHOOT] =
    {
        .name = _("TrapDustshoot"),
        .itemId = ITEM_TRAP_DUSTSHOOT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAP_EATER] =
    {
        .name = _("TrapEater"),
        .itemId = ITEM_TRAP_EATER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAP_HOLE] =
    {
        .name = _("TrapHole"),
        .itemId = ITEM_TRAP_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAP_MASTER] =
    {
        .name = _("TrapMaster"),
        .itemId = ITEM_TRAP_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAP_STUN] =
    {
        .name = _("TrapStun"),
        .itemId = ITEM_TRAP_STUN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAPTRIX_DIONAEA] =
    {
        .name = _("TraptrixDiona"),
        .itemId = ITEM_TRAPTRIX_DIONAEA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAPTRIX_MYRMELEO] =
    {
        .name = _("TraptrixMyrme"),
        .itemId = ITEM_TRAPTRIX_MYRMELEO,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRAPTRIX_TRAP_HOLE_NIGHTMARE] =
    {
        .name = _("TraptrixTrapH"),
        .itemId = ITEM_TRAPTRIX_TRAP_HOLE_NIGHTMARE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TREACHEROUS_TRAP_HOLE] =
    {
        .name = _("TreacherousTr"),
        .itemId = ITEM_TREACHEROUS_TRAP_HOLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TREEBORN_FROG] =
    {
        .name = _("TreebornFrog"),
        .itemId = ITEM_TREEBORN_FROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TREMENDOUS_FIRE] =
    {
        .name = _("TremendousFir"),
        .itemId = ITEM_TREMENDOUS_FIRE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRIBE_INFECTING_VIRUS] =
    {
        .name = _("TribeInfectin"),
        .itemId = ITEM_TRIBE_INFECTING_VIRUS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRIBUTE_TO_THE_DOOMED] =
    {
        .name = _("TributetotheD"),
        .itemId = ITEM_TRIBUTE_TO_THE_DOOMED,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRIDENT_DRAGION] =
    {
        .name = _("TridentDragio"),
        .itemId = ITEM_TRIDENT_DRAGION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRIGON] =
    {
        .name = _("Trigon"),
        .itemId = ITEM_TRIGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TRISHULA_DRAGON_OF_THE_ICE_BARRIER] =
    {
        .name = _("TrishulaDrago"),
        .itemId = ITEM_TRISHULA_DRAGON_OF_THE_ICE_BARRIER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TSUKUYOMI] =
    {
        .name = _("Tsukuyomi"),
        .itemId = ITEM_TSUKUYOMI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TURBO_WARRIOR] =
    {
        .name = _("TurboWarrior"),
        .itemId = ITEM_TURBO_WARRIOR,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TWIN_HEADED_BEHEMOTH] =
    {
        .name = _("TwinHeadedBeh"),
        .itemId = ITEM_TWIN_HEADED_BEHEMOTH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TWIN_HEADED_THUNDER_DRAGON] =
    {
        .name = _("TwinHeadedThu"),
        .itemId = ITEM_TWIN_HEADED_THUNDER_DRAGON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TWISTER] =
    {
        .name = _("Twister"),
        .itemId = ITEM_TWISTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_TYTANNIAL_PRINCESS_OF_CAMELLIAS] =
    {
        .name = _("TytannialPrin"),
        .itemId = ITEM_TYTANNIAL_PRINCESS_OF_CAMELLIAS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_UFO_TURTLE] =
    {
        .name = _("UFOTurtle"),
        .itemId = ITEM_UFO_TURTLE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ULTIMATE_OFFERING] =
    {
        .name = _("UltimateOffer"),
        .itemId = ITEM_ULTIMATE_OFFERING,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_UNIFROG] =
    {
        .name = _("Unifrog"),
        .itemId = ITEM_UNIFROG,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_UNITED_WE_STAND] =
    {
        .name = _("UnitedWeStand"),
        .itemId = ITEM_UNITED_WE_STAND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_UPSTART_GOBLIN] =
    {
        .name = _("UpstartGoblin"),
        .itemId = ITEM_UPSTART_GOBLIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VAN_DALGYON_THE_DARK_DRAGON_LORD] =
    {
        .name = _("VanDalgyonthe"),
        .itemId = ITEM_VAN_DALGYON_THE_DARK_DRAGON_LORD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VANITY_S_EMPTINESS] =
    {
        .name = _("VanitysEmptin"),
        .itemId = ITEM_VANITY_S_EMPTINESS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VANITY_S_FIEND] =
    {
        .name = _("VanitysFiend"),
        .itemId = ITEM_VANITY_S_FIEND,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VOLCANIC_QUEEN] =
    {
        .name = _("VolcanicQueen"),
        .itemId = ITEM_VOLCANIC_QUEEN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VOLCANIC_ROCKET] =
    {
        .name = _("VolcanicRocke"),
        .itemId = ITEM_VOLCANIC_ROCKET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VOLCANIC_SHELL] =
    {
        .name = _("VolcanicShell"),
        .itemId = ITEM_VOLCANIC_SHELL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VORSE_RAIDER] =
    {
        .name = _("VorseRaider"),
        .itemId = ITEM_VORSE_RAIDER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_VORTEX_TROOPER] =
    {
        .name = _("VortexTrooper"),
        .itemId = ITEM_VORTEX_TROOPER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WABOKU] =
    {
        .name = _("Waboku"),
        .itemId = ITEM_WABOKU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WALL_OF_ILLUSION] =
    {
        .name = _("WallofIllusio"),
        .itemId = ITEM_WALL_OF_ILLUSION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WALL_OF_REVEALING_LIGHT] =
    {
        .name = _("WallofReveali"),
        .itemId = ITEM_WALL_OF_REVEALING_LIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WARRIOR_ELIMINATION] =
    {
        .name = _("WarriorElimin"),
        .itemId = ITEM_WARRIOR_ELIMINATION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WARRIOR_OF_TRADITION] =
    {
        .name = _("WarriorofTrad"),
        .itemId = ITEM_WARRIOR_OF_TRADITION,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WAVE_MOTION_CANNON] =
    {
        .name = _("WaveMotionCan"),
        .itemId = ITEM_WAVE_MOTION_CANNON,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WHITE_MAGICAL_HAT] =
    {
        .name = _("WhiteMagicalH"),
        .itemId = ITEM_WHITE_MAGICAL_HAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIDESPREAD_DUD] =
    {
        .name = _("WidespreadDud"),
        .itemId = ITEM_WIDESPREAD_DUD,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIDESPREAD_RUIN] =
    {
        .name = _("WidespreadRui"),
        .itemId = ITEM_WIDESPREAD_RUIN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_ARSENAL_ZENMAIOH] =
    {
        .name = _("WindUpArsenal"),
        .itemId = ITEM_WIND_UP_ARSENAL_ZENMAIOH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_CARRIER_ZENMAITY] =
    {
        .name = _("WindUpCarrier"),
        .itemId = ITEM_WIND_UP_CARRIER_ZENMAITY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_FACTORY] =
    {
        .name = _("WindUpFactory"),
        .itemId = ITEM_WIND_UP_FACTORY,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_HUNTER] =
    {
        .name = _("WindUpHunter"),
        .itemId = ITEM_WIND_UP_HUNTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_MAGICIAN] =
    {
        .name = _("WindUpMagicia"),
        .itemId = ITEM_WIND_UP_MAGICIAN,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_RABBIT] =
    {
        .name = _("WindUpRabbit"),
        .itemId = ITEM_WIND_UP_RABBIT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_RAT] =
    {
        .name = _("WindUpRat"),
        .itemId = ITEM_WIND_UP_RAT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_SHARK] =
    {
        .name = _("WindUpShark"),
        .itemId = ITEM_WIND_UP_SHARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_ZENMAINES] =
    {
        .name = _("WindUpZenmain"),
        .itemId = ITEM_WIND_UP_ZENMAINES,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIND_UP_ZENMAISTER] =
    {
        .name = _("WindUpZenmais"),
        .itemId = ITEM_WIND_UP_ZENMAISTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WINGED_KURIBOH] =
    {
        .name = _("WingedKuriboh"),
        .itemId = ITEM_WINGED_KURIBOH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WINGED_RHYNOS] =
    {
        .name = _("WingedRhynos"),
        .itemId = ITEM_WINGED_RHYNOS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WIRETAP] =
    {
        .name = _("Wiretap"),
        .itemId = ITEM_WIRETAP,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WITCH_OF_THE_BLACK_FOREST] =
    {
        .name = _("WitchoftheBla"),
        .itemId = ITEM_WITCH_OF_THE_BLACK_FOREST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_WULF_LIGHTSWORN_BEAST] =
    {
        .name = _("WulfLightswor"),
        .itemId = ITEM_WULF_LIGHTSWORN_BEAST,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_X_SABER_AIRBELLUM] =
    {
        .name = _("XSaberAirbell"),
        .itemId = ITEM_X_SABER_AIRBELLUM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_X_SABER_PASHUUL] =
    {
        .name = _("XSaberPashuul"),
        .itemId = ITEM_X_SABER_PASHUUL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_X_SABER_URBELLUM] =
    {
        .name = _("XSaberUrbellu"),
        .itemId = ITEM_X_SABER_URBELLUM,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_X_SABER_WAYNE] =
    {
        .name = _("XSaberWayne"),
        .itemId = ITEM_X_SABER_WAYNE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XING_ZHEN_HU] =
    {
        .name = _("XingZhenHu"),
        .itemId = ITEM_XING_ZHEN_HU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_BOGGART_KNIGHT] =
    {
        .name = _("XXSaberBoggar"),
        .itemId = ITEM_XX_SABER_BOGGART_KNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_DARKSOUL] =
    {
        .name = _("XXSaberDarkso"),
        .itemId = ITEM_XX_SABER_DARKSOUL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_EMMERSBLADE] =
    {
        .name = _("XXSaberEmmers"),
        .itemId = ITEM_XX_SABER_EMMERSBLADE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_FAULTROLL] =
    {
        .name = _("XXSaberFaultr"),
        .itemId = ITEM_XX_SABER_FAULTROLL,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_FULHELMKNIGHT] =
    {
        .name = _("XXSaberFulhel"),
        .itemId = ITEM_XX_SABER_FULHELMKNIGHT,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_GOTTOMS] =
    {
        .name = _("XXSaberGottom"),
        .itemId = ITEM_XX_SABER_GOTTOMS,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_HYUNLEI] =
    {
        .name = _("XXSaberHyunle"),
        .itemId = ITEM_XX_SABER_HYUNLEI,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XX_SABER_RAGIGURA] =
    {
        .name = _("XXSaberRagigu"),
        .itemId = ITEM_XX_SABER_RAGIGURA,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_XYZ_ENCORE] =
    {
        .name = _("XyzEncore"),
        .itemId = ITEM_XYZ_ENCORE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_YATA_GARASU] =
    {
        .name = _("YataGarasu"),
        .itemId = ITEM_YATA_GARASU,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_YELLOW_GADGET] =
    {
        .name = _("YellowGadget"),
        .itemId = ITEM_YELLOW_GADGET,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ZABORG_THE_THUNDER_MONARCH] =
    {
        .name = _("ZaborgtheThun"),
        .itemId = ITEM_ZABORG_THE_THUNDER_MONARCH,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ZOMBIE_MASTER] =
    {
        .name = _("ZombieMaster"),
        .itemId = ITEM_ZOMBIE_MASTER,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },

	[ITEM_ZOMBYRA_THE_DARK] =
    {
        .name = _("ZombyratheDar"),
        .itemId = ITEM_ZOMBYRA_THE_DARK,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_TRUNK,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_DeckBuilder,
    },
};

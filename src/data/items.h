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

	[ITEM_CARD_4_STARRED_LADYBUG_OF_DOOM] =
	{
		.name = _("4StarredLadyb"),
		.itemId = ITEM_CARD_4_STARRED_LADYBUG_OF_DOOM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_7_COLORED_FISH] =
	{
		.name = _("7ColoredFish"),
		.itemId = ITEM_CARD_7_COLORED_FISH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_A_LEGENDARY_OCEAN] =
	{
		.name = _("ALegendaryOce"),
		.itemId = ITEM_CARD_A_LEGENDARY_OCEAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ABC_DRAGON_BUSTER] =
	{
		.name = _("ABCDragonBust"),
		.itemId = ITEM_CARD_ABC_DRAGON_BUSTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ABYSS_DWELLER] =
	{
		.name = _("AbyssDweller"),
		.itemId = ITEM_CARD_ABYSS_DWELLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ABYSS_SOLDIER] =
	{
		.name = _("AbyssSoldier"),
		.itemId = ITEM_CARD_ABYSS_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ABYSS_SPHERE] =
	{
		.name = _("Abysssphere"),
		.itemId = ITEM_CARD_ABYSS_SPHERE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ADVANCED_RITUAL_ART] =
	{
		.name = _("AdvancedRitua"),
		.itemId = ITEM_CARD_ADVANCED_RITUAL_ART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AGIDO_THE_ANCIENT_SENTINEL] =
	{
		.name = _("AgidotheAncie"),
		.itemId = ITEM_CARD_AGIDO_THE_ANCIENT_SENTINEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AIRKNIGHT_PARSHATH] =
	{
		.name = _("AirknightPars"),
		.itemId = ITEM_CARD_AIRKNIGHT_PARSHATH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALBA_LENATUS_THE_ABYSS_DRAGON] =
	{
		.name = _("AlbaLenatusth"),
		.itemId = ITEM_CARD_ALBA_LENATUS_THE_ABYSS_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALBAZ_THE_ASHEN] =
	{
		.name = _("AlbaztheAshen"),
		.itemId = ITEM_CARD_ALBAZ_THE_ASHEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALBION_THE_SANCTIFIRE_DRAGON] =
	{
		.name = _("AlbiontheSanc"),
		.itemId = ITEM_CARD_ALBION_THE_SANCTIFIRE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALBION_THE_SHROUDED_DRAGON] =
	{
		.name = _("AlbiontheShro"),
		.itemId = ITEM_CARD_ALBION_THE_SHROUDED_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALEXANDRITE_DRAGON] =
	{
		.name = _("AlexandriteDr"),
		.itemId = ITEM_CARD_ALEXANDRITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALLURE_OF_DARKNESS] =
	{
		.name = _("AllureofDarkn"),
		.itemId = ITEM_CARD_ALLURE_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALLY_OF_JUSTICE_CATASTOR] =
	{
		.name = _("AllyofJustice"),
		.itemId = ITEM_CARD_ALLY_OF_JUSTICE_CATASTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALLY_OF_JUSTICE_CYCLE_READER] =
	{
		.name = _("AllyofJustice"),
		.itemId = ITEM_CARD_ALLY_OF_JUSTICE_CYCLE_READER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ALUBER_THE_JESTER_OF_DESPIA] =
	{
		.name = _("AlubertheJest"),
		.itemId = ITEM_CARD_ALUBER_THE_JESTER_OF_DESPIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AMAZONESS_ARCHER] =
	{
		.name = _("AmazonessArch"),
		.itemId = ITEM_CARD_AMAZONESS_ARCHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AMAZONESS_SPIRITUALIST] =
	{
		.name = _("AmazonessSpir"),
		.itemId = ITEM_CARD_AMAZONESS_SPIRITUALIST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AMPHIBIOUS_BUGROTH_MK_3] =
	{
		.name = _("AmphibiousBug"),
		.itemId = ITEM_CARD_AMPHIBIOUS_BUGROTH_MK_3,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AMULET_DRAGON] =
	{
		.name = _("AmuletDragon"),
		.itemId = ITEM_CARD_AMULET_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ANCIENT_FAIRY_DRAGON] =
	{
		.name = _("AncientFairyD"),
		.itemId = ITEM_CARD_ANCIENT_FAIRY_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ANCIENT_GEAR_DRAGON] =
	{
		.name = _("AncientGearDr"),
		.itemId = ITEM_CARD_ANCIENT_GEAR_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ANCIENT_GEAR_GOLEM_ULTIMATE_POUND] =
	{
		.name = _("AncientGearGo"),
		.itemId = ITEM_CARD_ANCIENT_GEAR_GOLEM_ULTIMATE_POUND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ANGMARL_THE_FIENDISH_MONARCH] =
	{
		.name = _("AngmarltheFie"),
		.itemId = ITEM_CARD_ANGMARL_THE_FIENDISH_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ANTI_SPELL_FRAGRANCE] =
	{
		.name = _("AntiSpellFrag"),
		.itemId = ITEM_CARD_ANTI_SPELL_FRAGRANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_APOLLOUSA_BOW_OF_THE_GODDESS] =
	{
		.name = _("ApollousaBowo"),
		.itemId = ITEM_CARD_APOLLOUSA_BOW_OF_THE_GODDESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_APPRENTICE_ILLUSION_MAGICIAN] =
	{
		.name = _("ApprenticeIll"),
		.itemId = ITEM_CARD_APPRENTICE_ILLUSION_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AQUA_MADOOR] =
	{
		.name = _("AquaMadoor"),
		.itemId = ITEM_CARD_AQUA_MADOOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AQUA_SPIRIT] =
	{
		.name = _("AquaSpirit"),
		.itemId = ITEM_CARD_AQUA_SPIRIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCANITE_MAGICIAN] =
	{
		.name = _("ArcaniteMagic"),
		.itemId = ITEM_CARD_ARCANITE_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_BLACK_SKULL_DRAGON] =
	{
		.name = _("ArchfiendBlac"),
		.itemId = ITEM_CARD_ARCHFIEND_BLACK_SKULL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_CAVALRY] =
	{
		.name = _("ArchfiendCava"),
		.itemId = ITEM_CARD_ARCHFIEND_CAVALRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_COMMANDER] =
	{
		.name = _("ArchfiendComm"),
		.itemId = ITEM_CARD_ARCHFIEND_COMMANDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_ECCENTRICK] =
	{
		.name = _("ArchfiendEcce"),
		.itemId = ITEM_CARD_ARCHFIEND_ECCENTRICK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_EMPRESS] =
	{
		.name = _("ArchfiendEmpr"),
		.itemId = ITEM_CARD_ARCHFIEND_EMPRESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_GIANT] =
	{
		.name = _("ArchfiendGian"),
		.itemId = ITEM_CARD_ARCHFIEND_GIANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_HEIRESS] =
	{
		.name = _("ArchfiendHeir"),
		.itemId = ITEM_CARD_ARCHFIEND_HEIRESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_INTERCEPTOR] =
	{
		.name = _("ArchfiendInte"),
		.itemId = ITEM_CARD_ARCHFIEND_INTERCEPTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_OF_GILFER] =
	{
		.name = _("ArchfiendofGi"),
		.itemId = ITEM_CARD_ARCHFIEND_OF_GILFER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_SOLDIER] =
	{
		.name = _("ArchfiendSold"),
		.itemId = ITEM_CARD_ARCHFIEND_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_S_ADVENT] =
	{
		.name = _("ArchfiendsAdv"),
		.itemId = ITEM_CARD_ARCHFIEND_S_ADVENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHFIEND_S_MANIFESTATION] =
	{
		.name = _("ArchfiendsMan"),
		.itemId = ITEM_CARD_ARCHFIEND_S_MANIFESTATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARCHNEMESES_PROTOS] =
	{
		.name = _("ArchnemesesPr"),
		.itemId = ITEM_CARD_ARCHNEMESES_PROTOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARIEL_PRIESTESS_OF_THE_NEKROZ] =
	{
		.name = _("ArielPriestes"),
		.itemId = ITEM_CARD_ARIEL_PRIESTESS_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARISEN_GAIA_THE_FIERCE_KNIGHT] =
	{
		.name = _("ArisenGaiathe"),
		.itemId = ITEM_CARD_ARISEN_GAIA_THE_FIERCE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARMAGEDDON_KNIGHT] =
	{
		.name = _("ArmageddonKni"),
		.itemId = ITEM_CARD_ARMAGEDDON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARMED_NINJA] =
	{
		.name = _("ArmedNinja"),
		.itemId = ITEM_CARD_ARMED_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARMORED_CYBERN] =
	{
		.name = _("ArmoredCybern"),
		.itemId = ITEM_CARD_ARMORED_CYBERN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARMORY_ARM] =
	{
		.name = _("ArmoryArm"),
		.itemId = ITEM_CARD_ARMORY_ARM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARSENAL_BUG] =
	{
		.name = _("ArsenalBug"),
		.itemId = ITEM_CARD_ARSENAL_BUG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARSENAL_SUMMONER] =
	{
		.name = _("ArsenalSummon"),
		.itemId = ITEM_CARD_ARSENAL_SUMMONER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARTIFACT_LANCEA] =
	{
		.name = _("ArtifactLance"),
		.itemId = ITEM_CARD_ARTIFACT_LANCEA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARTIFACT_MORALLTACH] =
	{
		.name = _("ArtifactMoral"),
		.itemId = ITEM_CARD_ARTIFACT_MORALLTACH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ARTIFACT_SANCTUM] =
	{
		.name = _("ArtifactSanct"),
		.itemId = ITEM_CARD_ARTIFACT_SANCTUM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ASH_BLOSSOM_JOYOUS_SPRING] =
	{
		.name = _("AshBlossomJoy"),
		.itemId = ITEM_CARD_ASH_BLOSSOM_JOYOUS_SPRING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ASURA_PRIEST] =
	{
		.name = _("AsuraPriest"),
		.itemId = ITEM_CARD_ASURA_PRIEST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ATLANTEAN_DRAGOONS] =
	{
		.name = _("AtlanteanDrag"),
		.itemId = ITEM_CARD_ATLANTEAN_DRAGOONS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ATLANTEAN_HEAVY_INFANTRY] =
	{
		.name = _("AtlanteanHeav"),
		.itemId = ITEM_CARD_ATLANTEAN_HEAVY_INFANTRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ATLANTEAN_MARKSMAN] =
	{
		.name = _("AtlanteanMark"),
		.itemId = ITEM_CARD_ATLANTEAN_MARKSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AURKUS_LIGHTSWORN_DRUID] =
	{
		.name = _("AurkusLightsw"),
		.itemId = ITEM_CARD_AURKUS_LIGHTSWORN_DRUID,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AVANCE_SWORDSMAN_OF_THE_NEKROZ] =
	{
		.name = _("AvanceSwordsm"),
		.itemId = ITEM_CARD_AVANCE_SWORDSMAN_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AXE_DRAGONUTE] =
	{
		.name = _("AxeDragonute"),
		.itemId = ITEM_CARD_AXE_DRAGONUTE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_AXE_OF_DESPAIR] =
	{
		.name = _("AxeofDespair"),
		.itemId = ITEM_CARD_AXE_OF_DESPAIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BAKU_THE_BEAST_NINJA] =
	{
		.name = _("BakutheBeastN"),
		.itemId = ITEM_CARD_BAKU_THE_BEAST_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BANISHER_OF_THE_LIGHT] =
	{
		.name = _("Banisherofthe"),
		.itemId = ITEM_CARD_BANISHER_OF_THE_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BANISHER_OF_THE_RADIANCE] =
	{
		.name = _("Banisherofthe"),
		.itemId = ITEM_CARD_BANISHER_OF_THE_RADIANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BAOBABOON] =
	{
		.name = _("Baobaboon"),
		.itemId = ITEM_CARD_BAOBABOON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BARREL_BEHIND_THE_DOOR] =
	{
		.name = _("BarrelBehindt"),
		.itemId = ITEM_CARD_BARREL_BEHIND_THE_DOOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BATTLE_FOOTBALLER] =
	{
		.name = _("BattleFootbal"),
		.itemId = ITEM_CARD_BATTLE_FOOTBALLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BATTLE_OX] =
	{
		.name = _("BattleOx"),
		.itemId = ITEM_CARD_BATTLE_OX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BAXIA_BRIGHTNESS_OF_THE_YANG_ZING] =
	{
		.name = _("BaxiaBrightne"),
		.itemId = ITEM_CARD_BAXIA_BRIGHTNESS_OF_THE_YANG_ZING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BAZOO_THE_SOUL_EATER] =
	{
		.name = _("BazootheSoulE"),
		.itemId = ITEM_CARD_BAZOO_THE_SOUL_EATER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BEAST_OF_TALWAR] =
	{
		.name = _("BeastofTalwar"),
		.itemId = ITEM_CARD_BEAST_OF_TALWAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BEAST_OF_TALWAR_THE_SWORD_SUMMIT] =
	{
		.name = _("BeastofTalwar"),
		.itemId = ITEM_CARD_BEAST_OF_TALWAR_THE_SWORD_SUMMIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BEATRICE_LADY_OF_THE_ETERNAL] =
	{
		.name = _("BeatriceLadyo"),
		.itemId = ITEM_CARD_BEATRICE_LADY_OF_THE_ETERNAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BECKONING_LIGHT] =
	{
		.name = _("BeckoningLigh"),
		.itemId = ITEM_CARD_BECKONING_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BEGINNING_KNIGHT] =
	{
		.name = _("BeginningKnig"),
		.itemId = ITEM_CARD_BEGINNING_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BEIIGE_VANGUARD_OF_DARK_WORLD] =
	{
		.name = _("BeiigeVanguar"),
		.itemId = ITEM_CARD_BEIIGE_VANGUARD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BERLINETH_THE_FIRESTORM_VASSAL] =
	{
		.name = _("BerlineththeF"),
		.itemId = ITEM_CARD_BERLINETH_THE_FIRESTORM_VASSAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BERSERK_DRAGON] =
	{
		.name = _("BerserkDragon"),
		.itemId = ITEM_CARD_BERSERK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BERSERK_GORILLA] =
	{
		.name = _("BerserkGorill"),
		.itemId = ITEM_CARD_BERSERK_GORILLA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BICKURIBOX] =
	{
		.name = _("Bickuribox"),
		.itemId = ITEM_CARD_BICKURIBOX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BIG_BANG_SHOT] =
	{
		.name = _("BigBangShot"),
		.itemId = ITEM_CARD_BIG_BANG_SHOT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BIG_SHIELD_GARDNA] =
	{
		.name = _("BigShieldGard"),
		.itemId = ITEM_CARD_BIG_SHIELD_GARDNA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BIG_TUSKED_MAMMOTH] =
	{
		.name = _("BigTuskedMamm"),
		.itemId = ITEM_CARD_BIG_TUSKED_MAMMOTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_DRAGON_S_CHICK] =
	{
		.name = _("BlackDragonsC"),
		.itemId = ITEM_CARD_BLACK_DRAGON_S_CHICK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_HORN_OF_HEAVEN] =
	{
		.name = _("BlackHornofHe"),
		.itemId = ITEM_CARD_BLACK_HORN_OF_HEAVEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_ILLUSION_RITUAL] =
	{
		.name = _("BlackIllusion"),
		.itemId = ITEM_CARD_BLACK_ILLUSION_RITUAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING] =
	{
		.name = _("BlackLusterSo"),
		.itemId = ITEM_CARD_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_EVENING_TWILIGHT] =
	{
		.name = _("BlackLusterSo"),
		.itemId = ITEM_CARD_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_EVENING_TWILIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_METAL_DRAGON] =
	{
		.name = _("BlackMetalDra"),
		.itemId = ITEM_CARD_BLACK_METAL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_PENDANT] =
	{
		.name = _("BlackPendant"),
		.itemId = ITEM_CARD_BLACK_PENDANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_ROSE_DRAGON] =
	{
		.name = _("BlackRoseDrag"),
		.itemId = ITEM_CARD_BLACK_ROSE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_SKULL_DRAGON] =
	{
		.name = _("BlackSkullDra"),
		.itemId = ITEM_CARD_BLACK_SKULL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACK_WHIRLWIND] =
	{
		.name = _("BlackWhirlwin"),
		.itemId = ITEM_CARD_BLACK_WHIRLWIND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_BLIZZARD_THE_FAR_NORTH] =
	{
		.name = _("BlackwingBliz"),
		.itemId = ITEM_CARD_BLACKWING_BLIZZARD_THE_FAR_NORTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_BORA_THE_SPEAR] =
	{
		.name = _("BlackwingBora"),
		.itemId = ITEM_CARD_BLACKWING_BORA_THE_SPEAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_GALE_THE_WHIRLWIND] =
	{
		.name = _("BlackwingGale"),
		.itemId = ITEM_CARD_BLACKWING_GALE_THE_WHIRLWIND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_KALUT_THE_MOON_SHADOW] =
	{
		.name = _("BlackwingKalu"),
		.itemId = ITEM_CARD_BLACKWING_KALUT_THE_MOON_SHADOW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_SHURA_THE_BLUE_FLAME] =
	{
		.name = _("BlackwingShur"),
		.itemId = ITEM_CARD_BLACKWING_SHURA_THE_BLUE_FLAME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_SILVERWIND_THE_ASCENDANT] =
	{
		.name = _("BlackwingSilv"),
		.itemId = ITEM_CARD_BLACKWING_SILVERWIND_THE_ASCENDANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_SIROCCO_THE_DAWN] =
	{
		.name = _("BlackwingSiro"),
		.itemId = ITEM_CARD_BLACKWING_SIROCCO_THE_DAWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_VAYU_THE_EMBLEM_OF_HONOR] =
	{
		.name = _("BlackwingVayu"),
		.itemId = ITEM_CARD_BLACKWING_VAYU_THE_EMBLEM_OF_HONOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_ARMED_WING] =
	{
		.name = _("BlackwingArme"),
		.itemId = ITEM_CARD_BLACKWING_ARMED_WING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLACKWING_ARMOR_MASTER] =
	{
		.name = _("BlackwingArmo"),
		.itemId = ITEM_CARD_BLACKWING_ARMOR_MASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLADE_KNIGHT] =
	{
		.name = _("BladeKnight"),
		.itemId = ITEM_CARD_BLADE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLAST_WITH_CHAIN] =
	{
		.name = _("BlastwithChai"),
		.itemId = ITEM_CARD_BLAST_WITH_CHAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLASTER_DRAGON_RULER_OF_INFERNOS] =
	{
		.name = _("BlasterDragon"),
		.itemId = ITEM_CARD_BLASTER_DRAGON_RULER_OF_INFERNOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLAZING_CARTESIA_THE_VIRTUOUS] =
	{
		.name = _("BlazingCartes"),
		.itemId = ITEM_CARD_BLAZING_CARTESIA_THE_VIRTUOUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLAZING_INPACHI] =
	{
		.name = _("BlazingInpach"),
		.itemId = ITEM_CARD_BLAZING_INPACHI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLINDLY_LOYAL_GOBLIN] =
	{
		.name = _("BlindlyLoyalG"),
		.itemId = ITEM_CARD_BLINDLY_LOYAL_GOBLIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLOCK_ATTACK] =
	{
		.name = _("BlockAttack"),
		.itemId = ITEM_CARD_BLOCK_ATTACK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLOWBACK_DRAGON] =
	{
		.name = _("BlowbackDrago"),
		.itemId = ITEM_CARD_BLOWBACK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_FLAME_SWORDSMAN] =
	{
		.name = _("BlueFlameSwor"),
		.itemId = ITEM_CARD_BLUE_FLAME_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_ALTERNATIVE_ULTIMATE_DRAGON] =
	{
		.name = _("BlueEyesAlter"),
		.itemId = ITEM_CARD_BLUE_EYES_ALTERNATIVE_ULTIMATE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_ALTERNATIVE_WHITE_DRAGON] =
	{
		.name = _("BlueEyesAlter"),
		.itemId = ITEM_CARD_BLUE_EYES_ALTERNATIVE_WHITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_JET_DRAGON] =
	{
		.name = _("BlueEyesJetDr"),
		.itemId = ITEM_CARD_BLUE_EYES_JET_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_TOON_DRAGON] =
	{
		.name = _("BlueEyesToonD"),
		.itemId = ITEM_CARD_BLUE_EYES_TOON_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_TWIN_BURST_DRAGON] =
	{
		.name = _("BlueEyesTwinB"),
		.itemId = ITEM_CARD_BLUE_EYES_TWIN_BURST_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_TYRANT_DRAGON] =
	{
		.name = _("BlueEyesTyran"),
		.itemId = ITEM_CARD_BLUE_EYES_TYRANT_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_ULTIMATE_DRAGON] =
	{
		.name = _("BlueEyesUltim"),
		.itemId = ITEM_CARD_BLUE_EYES_ULTIMATE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BLUE_EYES_WHITE_DRAGON] =
	{
		.name = _("BlueEyesWhite"),
		.itemId = ITEM_CARD_BLUE_EYES_WHITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BM_4_BLAST_SPIDER] =
	{
		.name = _("BM4BlastSpide"),
		.itemId = ITEM_CARD_BM_4_BLAST_SPIDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BONE_ARCHFIEND] =
	{
		.name = _("BoneArchfiend"),
		.itemId = ITEM_CARD_BONE_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BONFIRE] =
	{
		.name = _("Bonfire"),
		.itemId = ITEM_CARD_BONFIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOOK_OF_ECLIPSE] =
	{
		.name = _("BookofEclipse"),
		.itemId = ITEM_CARD_BOOK_OF_ECLIPSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOOK_OF_LIFE] =
	{
		.name = _("BookofLife"),
		.itemId = ITEM_CARD_BOOK_OF_LIFE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOOK_OF_MOON] =
	{
		.name = _("BookofMoon"),
		.itemId = ITEM_CARD_BOOK_OF_MOON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOOK_OF_TAIYOU] =
	{
		.name = _("BookofTaiyou"),
		.itemId = ITEM_CARD_BOOK_OF_TAIYOU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BORRELOAD_DRAGON] =
	{
		.name = _("BorreloadDrag"),
		.itemId = ITEM_CARD_BORRELOAD_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOTTOMLESS_TRAP_HOLE] =
	{
		.name = _("BottomlessTra"),
		.itemId = ITEM_CARD_BOTTOMLESS_TRAP_HOLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BOWGANIAN] =
	{
		.name = _("Bowganian"),
		.itemId = ITEM_CARD_BOWGANIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRAIN_CONTROL] =
	{
		.name = _("BrainControl"),
		.itemId = ITEM_CARD_BRAIN_CONTROL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRANDED_IN_HIGH_SPIRITS] =
	{
		.name = _("BrandedinHigh"),
		.itemId = ITEM_CARD_BRANDED_IN_HIGH_SPIRITS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BREAKER_THE_MAGICAL_WARRIOR] =
	{
		.name = _("BreakertheMag"),
		.itemId = ITEM_CARD_BREAKER_THE_MAGICAL_WARRIOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BREAKTHROUGH_SKILL] =
	{
		.name = _("BreakthroughS"),
		.itemId = ITEM_CARD_BREAKTHROUGH_SKILL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRIGRAND_THE_GLORY_DRAGON] =
	{
		.name = _("BrigrandtheGl"),
		.itemId = ITEM_CARD_BRIGRAND_THE_GLORY_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRILLIANT_ROSE] =
	{
		.name = _("BrilliantRose"),
		.itemId = ITEM_CARD_BRILLIANT_ROSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRIONAC_DRAGON_OF_THE_ICE_BARRIER] =
	{
		.name = _("BrionacDragon"),
		.itemId = ITEM_CARD_BRIONAC_DRAGON_OF_THE_ICE_BARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BROTHERHOOD_OF_THE_FIRE_FIST_BEAR] =
	{
		.name = _("Brotherhoodof"),
		.itemId = ITEM_CARD_BROTHERHOOD_OF_THE_FIRE_FIST_BEAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BROWW_HUNTSMAN_OF_DARK_WORLD] =
	{
		.name = _("BrowwHuntsman"),
		.itemId = ITEM_CARD_BROWW_HUNTSMAN_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BRRON_MAD_KING_OF_DARK_WORLD] =
	{
		.name = _("BrronMadKingo"),
		.itemId = ITEM_CARD_BRRON_MAD_KING_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BURIAL_FROM_A_DIFFERENT_DIMENSION] =
	{
		.name = _("BurialfromaDi"),
		.itemId = ITEM_CARD_BURIAL_FROM_A_DIFFERENT_DIMENSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BURNER_DRAGON_RULER_OF_SPARKS] =
	{
		.name = _("BurnerDragonR"),
		.itemId = ITEM_CARD_BURNER_DRAGON_RULER_OF_SPARKS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BUSTER_BLADER] =
	{
		.name = _("BusterBlader"),
		.itemId = ITEM_CARD_BUSTER_BLADER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BUSTER_BLADER_THE_DESTRUCTION_SWORDMASTER] =
	{
		.name = _("BusterBladert"),
		.itemId = ITEM_CARD_BUSTER_BLADER_THE_DESTRUCTION_SWORDMASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BUSTER_BLADER_THE_DRAGON_DESTROYER_SWORDSMAN] =
	{
		.name = _("BusterBladert"),
		.itemId = ITEM_CARD_BUSTER_BLADER_THE_DRAGON_DESTROYER_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BYSER_SHOCK] =
	{
		.name = _("ByserShock"),
		.itemId = ITEM_CARD_BYSER_SHOCK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BYSTIAL_BALDRAKE] =
	{
		.name = _("BystialBaldra"),
		.itemId = ITEM_CARD_BYSTIAL_BALDRAKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BYSTIAL_DRUISWURM] =
	{
		.name = _("BystialDruisw"),
		.itemId = ITEM_CARD_BYSTIAL_DRUISWURM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BYSTIAL_MAGNAMHUT] =
	{
		.name = _("BystialMagnam"),
		.itemId = ITEM_CARD_BYSTIAL_MAGNAMHUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_BYSTIAL_SARONIR] =
	{
		.name = _("BystialSaroni"),
		.itemId = ITEM_CARD_BYSTIAL_SARONIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CAIUS_THE_MEGA_MONARCH] =
	{
		.name = _("CaiustheMegaM"),
		.itemId = ITEM_CARD_CAIUS_THE_MEGA_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CAIUS_THE_SHADOW_MONARCH] =
	{
		.name = _("CaiustheShado"),
		.itemId = ITEM_CARD_CAIUS_THE_SHADOW_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CALL_OF_THE_HAUNTED] =
	{
		.name = _("CalloftheHaun"),
		.itemId = ITEM_CARD_CALL_OF_THE_HAUNTED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CALLED_BY_THE_GRAVE] =
	{
		.name = _("CalledbytheGr"),
		.itemId = ITEM_CARD_CALLED_BY_THE_GRAVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CANNON_SOLDIER] =
	{
		.name = _("CannonSoldier"),
		.itemId = ITEM_CARD_CANNON_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARD_DESTRUCTION] =
	{
		.name = _("CardDestructi"),
		.itemId = ITEM_CARD_CARD_DESTRUCTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARD_OF_DEMISE] =
	{
		.name = _("CardofDemise"),
		.itemId = ITEM_CARD_CARD_OF_DEMISE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARD_OF_SAFE_RETURN] =
	{
		.name = _("CardofSafeRet"),
		.itemId = ITEM_CARD_CARD_OF_SAFE_RETURN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARD_TROOPER] =
	{
		.name = _("CardTrooper"),
		.itemId = ITEM_CARD_CARD_TROOPER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARDS_FROM_THE_SKY] =
	{
		.name = _("CardsfromtheS"),
		.itemId = ITEM_CARD_CARDS_FROM_THE_SKY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CARDS_OF_CONSONANCE] =
	{
		.name = _("CardsofConson"),
		.itemId = ITEM_CARD_CARDS_OF_CONSONANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CASTEL_THE_SKYBLASTER_MUSKETEER] =
	{
		.name = _("CasteltheSkyb"),
		.itemId = ITEM_CARD_CASTEL_THE_SKYBLASTER_MUSKETEER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CASTLE_OF_DARK_ILLUSIONS] =
	{
		.name = _("CastleofDarkI"),
		.itemId = ITEM_CARD_CASTLE_OF_DARK_ILLUSIONS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CASTLE_WALLS] =
	{
		.name = _("CastleWalls"),
		.itemId = ITEM_CARD_CASTLE_WALLS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CATAPULT_TURTLE] =
	{
		.name = _("CatapultTurtl"),
		.itemId = ITEM_CARD_CATAPULT_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CEASEFIRE] =
	{
		.name = _("Ceasefire"),
		.itemId = ITEM_CARD_CEASEFIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CELESTIA_LIGHTSWORN_ANGEL] =
	{
		.name = _("CelestiaLight"),
		.itemId = ITEM_CARD_CELESTIA_LIGHTSWORN_ANGEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAIN_DISAPPEARANCE] =
	{
		.name = _("ChainDisappea"),
		.itemId = ITEM_CARD_CHAIN_DISAPPEARANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAIN_ENERGY] =
	{
		.name = _("ChainEnergy"),
		.itemId = ITEM_CARD_CHAIN_ENERGY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAINSAW_INSECT] =
	{
		.name = _("ChainsawInsec"),
		.itemId = ITEM_CARD_CHAINSAW_INSECT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHANGE_OF_HEART] =
	{
		.name = _("ChangeofHeart"),
		.itemId = ITEM_CARD_CHANGE_OF_HEART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END] =
	{
		.name = _("ChaosEmperorD"),
		.itemId = ITEM_CARD_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAOS_HUNTER] =
	{
		.name = _("ChaosHunter"),
		.itemId = ITEM_CARD_CHAOS_HUNTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAOS_NEPHTHYS] =
	{
		.name = _("ChaosNephthys"),
		.itemId = ITEM_CARD_CHAOS_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHAOS_SORCERER] =
	{
		.name = _("ChaosSorcerer"),
		.itemId = ITEM_CARD_CHAOS_SORCERER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHARCOAL_INPACHI] =
	{
		.name = _("CharcoalInpac"),
		.itemId = ITEM_CARD_CHARCOAL_INPACHI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHARGE_OF_THE_LIGHT_BRIGADE] =
	{
		.name = _("ChargeoftheLi"),
		.itemId = ITEM_CARD_CHARGE_OF_THE_LIGHT_BRIGADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHARGING_GAIA_THE_FIERCE_KNIGHT] =
	{
		.name = _("ChargingGaiat"),
		.itemId = ITEM_CARD_CHARGING_GAIA_THE_FIERCE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHICKEN_GAME] =
	{
		.name = _("ChickenGame"),
		.itemId = ITEM_CARD_CHICKEN_GAME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHIMERATECH_FORTRESS_DRAGON] =
	{
		.name = _("ChimeratechFo"),
		.itemId = ITEM_CARD_CHIMERATECH_FORTRESS_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHIMERATECH_OVERDRAGON] =
	{
		.name = _("ChimeratechOv"),
		.itemId = ITEM_CARD_CHIMERATECH_OVERDRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHIRON_THE_MAGE] =
	{
		.name = _("ChirontheMage"),
		.itemId = ITEM_CARD_CHIRON_THE_MAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHRONICLE_MAGICIAN] =
	{
		.name = _("ChronicleMagi"),
		.itemId = ITEM_CARD_CHRONICLE_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CHRONICLE_SORCERESS] =
	{
		.name = _("ChronicleSorc"),
		.itemId = ITEM_CARD_CHRONICLE_SORCERESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CIPHER_SOLDIER] =
	{
		.name = _("CipherSoldier"),
		.itemId = ITEM_CARD_CIPHER_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CIR_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("CirMalebranch"),
		.itemId = ITEM_CARD_CIR_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CLORLESS_CHAOS_KING_OF_DARK_WORLD] =
	{
		.name = _("ClorlessChaos"),
		.itemId = ITEM_CARD_CLORLESS_CHAOS_KING_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_COLD_WAVE] =
	{
		.name = _("ColdWave"),
		.itemId = ITEM_CARD_COLD_WAVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_COLOSSAL_FIGHTER] =
	{
		.name = _("ColossalFight"),
		.itemId = ITEM_CARD_COLOSSAL_FIGHTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_COMMAND_KNIGHT] =
	{
		.name = _("CommandKnight"),
		.itemId = ITEM_CARD_COMMAND_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_COMPULSORY_EVACUATION_DEVICE] =
	{
		.name = _("CompulsoryEva"),
		.itemId = ITEM_CARD_COMPULSORY_EVACUATION_DEVICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CONFISCATION] =
	{
		.name = _("Confiscation"),
		.itemId = ITEM_CARD_CONFISCATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CONSECRATED_LIGHT] =
	{
		.name = _("ConsecratedLi"),
		.itemId = ITEM_CARD_CONSECRATED_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_COSMIC_CYCLONE] =
	{
		.name = _("CosmicCyclone"),
		.itemId = ITEM_CARD_COSMIC_CYCLONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CRASS_CLOWN] =
	{
		.name = _("CrassClown"),
		.itemId = ITEM_CARD_CRASS_CLOWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CREATURE_SWAP] =
	{
		.name = _("CreatureSwap"),
		.itemId = ITEM_CARD_CREATURE_SWAP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CREVICE_INTO_THE_DIFFERENT_DIMENSION] =
	{
		.name = _("CreviceIntoth"),
		.itemId = ITEM_CARD_CREVICE_INTO_THE_DIFFERENT_DIMENSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CRIMSON_BLADER] =
	{
		.name = _("CrimsonBlader"),
		.itemId = ITEM_CARD_CRIMSON_BLADER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CRIMSON_NINJA] =
	{
		.name = _("CrimsonNinja"),
		.itemId = ITEM_CARD_CRIMSON_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CROSSOUT_DESIGNATOR] =
	{
		.name = _("CrossoutDesig"),
		.itemId = ITEM_CARD_CROSSOUT_DESIGNATOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CRUSH_CARD_VIRUS] =
	{
		.name = _("CrushCardViru"),
		.itemId = ITEM_CARD_CRUSH_CARD_VIRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CRYSTAL_ROSE] =
	{
		.name = _("CrystalRose"),
		.itemId = ITEM_CARD_CRYSTAL_ROSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL] =
	{
		.name = _("CursedSealoft"),
		.itemId = ITEM_CARD_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON] =
	{
		.name = _("CyberDragon"),
		.itemId = ITEM_CARD_CYBER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON_DREI] =
	{
		.name = _("CyberDragonDr"),
		.itemId = ITEM_CARD_CYBER_DRAGON_DREI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON_INFINITY] =
	{
		.name = _("CyberDragonIn"),
		.itemId = ITEM_CARD_CYBER_DRAGON_INFINITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON_NOVA] =
	{
		.name = _("CyberDragonNo"),
		.itemId = ITEM_CARD_CYBER_DRAGON_NOVA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON_VIER] =
	{
		.name = _("CyberDragonVi"),
		.itemId = ITEM_CARD_CYBER_DRAGON_VIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_DRAGON_ZWEI] =
	{
		.name = _("CyberDragonZw"),
		.itemId = ITEM_CARD_CYBER_DRAGON_ZWEI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_ELTANIN] =
	{
		.name = _("CyberEltanin"),
		.itemId = ITEM_CARD_CYBER_ELTANIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_END_DRAGON] =
	{
		.name = _("CyberEndDrago"),
		.itemId = ITEM_CARD_CYBER_END_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_HARPIE_LADY] =
	{
		.name = _("CyberHarpieLa"),
		.itemId = ITEM_CARD_CYBER_HARPIE_LADY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_JAR] =
	{
		.name = _("CyberJar"),
		.itemId = ITEM_CARD_CYBER_JAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_LARVA] =
	{
		.name = _("CyberLarva"),
		.itemId = ITEM_CARD_CYBER_LARVA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_PHOENIX] =
	{
		.name = _("CyberPhoenix"),
		.itemId = ITEM_CARD_CYBER_PHOENIX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_TWIN_DRAGON] =
	{
		.name = _("CyberTwinDrag"),
		.itemId = ITEM_CARD_CYBER_TWIN_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_VALLEY] =
	{
		.name = _("CyberValley"),
		.itemId = ITEM_CARD_CYBER_VALLEY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBER_STEIN] =
	{
		.name = _("CyberStein"),
		.itemId = ITEM_CARD_CYBER_STEIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYBERDARK_WURM] =
	{
		.name = _("CyberdarkWurm"),
		.itemId = ITEM_CARD_CYBERDARK_WURM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_CYNET_MINING] =
	{
		.name = _("CynetMining"),
		.itemId = ITEM_CARD_CYNET_MINING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_ASSAILANT] =
	{
		.name = _("DDAssailant"),
		.itemId = ITEM_CARD_D_D_ASSAILANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_CRAZY_BEAST] =
	{
		.name = _("DDCrazyBeast"),
		.itemId = ITEM_CARD_D_D_CRAZY_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_CROW] =
	{
		.name = _("DDCrow"),
		.itemId = ITEM_CARD_D_D_CROW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_SURVIVOR] =
	{
		.name = _("DDSurvivor"),
		.itemId = ITEM_CARD_D_D_SURVIVOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_TRAINER] =
	{
		.name = _("DDTrainer"),
		.itemId = ITEM_CARD_D_D_TRAINER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_D_D_WARRIOR_LADY] =
	{
		.name = _("DDWarriorLady"),
		.itemId = ITEM_CARD_D_D_WARRIOR_LADY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DAIGUSTO_EMERAL] =
	{
		.name = _("DaigustoEmera"),
		.itemId = ITEM_CARD_DAIGUSTO_EMERAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DANCE_PRINCESS_OF_THE_NEKROZ] =
	{
		.name = _("DancePrincess"),
		.itemId = ITEM_CARD_DANCE_PRINCESS_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DANDYLION] =
	{
		.name = _("Dandylion"),
		.itemId = ITEM_CARD_DANDYLION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DANGER_NESSIE_] =
	{
		.name = _("DangerNessie"),
		.itemId = ITEM_CARD_DANGER_NESSIE_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DANTE_TRAVELER_OF_THE_BURNING_ABYSS] =
	{
		.name = _("DanteTraveler"),
		.itemId = ITEM_CARD_DANTE_TRAVELER_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_ARMED_DRAGON] =
	{
		.name = _("DarkArmedDrag"),
		.itemId = ITEM_CARD_DARK_ARMED_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_BALTER_THE_TERRIBLE] =
	{
		.name = _("DarkBalterthe"),
		.itemId = ITEM_CARD_DARK_BALTER_THE_TERRIBLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_BLADE] =
	{
		.name = _("DarkBlade"),
		.itemId = ITEM_CARD_DARK_BLADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_BLADE_THE_DRAGON_KNIGHT] =
	{
		.name = _("DarkBladetheD"),
		.itemId = ITEM_CARD_DARK_BLADE_THE_DRAGON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_CAVALRY] =
	{
		.name = _("DarkCavalry"),
		.itemId = ITEM_CARD_DARK_CAVALRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_DEAL] =
	{
		.name = _("DarkDeal"),
		.itemId = ITEM_CARD_DARK_DEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_ELF] =
	{
		.name = _("DarkElf"),
		.itemId = ITEM_CARD_DARK_ELF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_END_DRAGON] =
	{
		.name = _("DarkEndDragon"),
		.itemId = ITEM_CARD_DARK_END_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_ERADICATOR_WARLOCK] =
	{
		.name = _("DarkEradicato"),
		.itemId = ITEM_CARD_DARK_ERADICATOR_WARLOCK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_FLARE_KNIGHT] =
	{
		.name = _("DarkFlareKnig"),
		.itemId = ITEM_CARD_DARK_FLARE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_GREPHER] =
	{
		.name = _("DarkGrepher"),
		.itemId = ITEM_CARD_DARK_GREPHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_HOLE] =
	{
		.name = _("DarkHole"),
		.itemId = ITEM_CARD_DARK_HOLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGIC_CURTAIN] =
	{
		.name = _("DarkMagicCurt"),
		.itemId = ITEM_CARD_DARK_MAGIC_CURTAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN] =
	{
		.name = _("DarkMagician"),
		.itemId = ITEM_CARD_DARK_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_GIRL] =
	{
		.name = _("DarkMagicianG"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_GIRL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_GIRL_THE_DRAGON_KNIGHT] =
	{
		.name = _("DarkMagicianG"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_GIRL_THE_DRAGON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_GIRL_THE_MAGICIAN_S_APPRENTICE] =
	{
		.name = _("DarkMagicianG"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_GIRL_THE_MAGICIAN_S_APPRENTICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_OF_CHAOS] =
	{
		.name = _("DarkMagiciano"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_OF_CHAOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_THE_DRAGON_KNIGHT] =
	{
		.name = _("DarkMagiciant"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_THE_DRAGON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MAGICIAN_THE_KNIGHT_OF_DRAGON_MAGIC] =
	{
		.name = _("DarkMagiciant"),
		.itemId = ITEM_CARD_DARK_MAGICIAN_THE_KNIGHT_OF_DRAGON_MAGIC,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MIMIC_LV1] =
	{
		.name = _("DarkMimicLV1"),
		.itemId = ITEM_CARD_DARK_MIMIC_LV1,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_MIMIC_LV3] =
	{
		.name = _("DarkMimicLV3"),
		.itemId = ITEM_CARD_DARK_MIMIC_LV3,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_NEPHTHYS] =
	{
		.name = _("DarkNephthys"),
		.itemId = ITEM_CARD_DARK_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_PALADIN] =
	{
		.name = _("DarkPaladin"),
		.itemId = ITEM_CARD_DARK_PALADIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_RULER_HA_DES] =
	{
		.name = _("DarkRulerHaDe"),
		.itemId = ITEM_CARD_DARK_RULER_HA_DES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_RULER_NO_MORE] =
	{
		.name = _("DarkRulerNoMo"),
		.itemId = ITEM_CARD_DARK_RULER_NO_MORE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_SCORPION_CHICK_THE_YELLOW] =
	{
		.name = _("DarkScorpionC"),
		.itemId = ITEM_CARD_DARK_SCORPION_CHICK_THE_YELLOW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER] =
	{
		.name = _("DarkScorpionC"),
		.itemId = ITEM_CARD_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_STRIKE_FIGHTER] =
	{
		.name = _("DarkStrikeFig"),
		.itemId = ITEM_CARD_DARK_STRIKE_FIGHTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARK_WORLD_LIGHTNING] =
	{
		.name = _("DarkWorldLigh"),
		.itemId = ITEM_CARD_DARK_WORLD_LIGHTNING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARKFIRE_DRAGON] =
	{
		.name = _("DarkfireDrago"),
		.itemId = ITEM_CARD_DARKFIRE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DARKLORD_ZERATO] =
	{
		.name = _("DarklordZerat"),
		.itemId = ITEM_CARD_DARKLORD_ZERATO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DE_FUSION] =
	{
		.name = _("DeFusion"),
		.itemId = ITEM_CARD_DE_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DE_SPELL] =
	{
		.name = _("DeSpell"),
		.itemId = ITEM_CARD_DE_SPELL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEBRIS_DRAGON] =
	{
		.name = _("DebrisDragon"),
		.itemId = ITEM_CARD_DEBRIS_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEBUNK] =
	{
		.name = _("Debunk"),
		.itemId = ITEM_CARD_DEBUNK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DECK_DEVASTATION_VIRUS] =
	{
		.name = _("DeckDevastati"),
		.itemId = ITEM_CARD_DECK_DEVASTATION_VIRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEEP_SEA_DIVA] =
	{
		.name = _("DeepSeaDiva"),
		.itemId = ITEM_CARD_DEEP_SEA_DIVA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEEP_EYES_WHITE_DRAGON] =
	{
		.name = _("DeepEyesWhite"),
		.itemId = ITEM_CARD_DEEP_EYES_WHITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEFENDER_OF_NEPHTHYS] =
	{
		.name = _("DefenderofNep"),
		.itemId = ITEM_CARD_DEFENDER_OF_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE] =
	{
		.name = _("DekoichitheBa"),
		.itemId = ITEM_CARD_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DELG_THE_DARK_MONARCH] =
	{
		.name = _("DelgtheDarkMo"),
		.itemId = ITEM_CARD_DELG_THE_DARK_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DELINQUENT_DUO] =
	{
		.name = _("DelinquentDuo"),
		.itemId = ITEM_CARD_DELINQUENT_DUO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DEMISE_KING_OF_ARMAGEDDON] =
	{
		.name = _("DemiseKingofA"),
		.itemId = ITEM_CARD_DEMISE_KING_OF_ARMAGEDDON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DENKO_SEKKA] =
	{
		.name = _("DenkoSekka"),
		.itemId = ITEM_CARD_DENKO_SEKKA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DES_DENDLE] =
	{
		.name = _("DesDendle"),
		.itemId = ITEM_CARD_DES_DENDLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DES_KOALA] =
	{
		.name = _("DesKoala"),
		.itemId = ITEM_CARD_DES_KOALA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DES_LACOODA] =
	{
		.name = _("DesLacooda"),
		.itemId = ITEM_CARD_DES_LACOODA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DES_WOMBAT] =
	{
		.name = _("DesWombat"),
		.itemId = ITEM_CARD_DES_WOMBAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESERT_SUNLIGHT] =
	{
		.name = _("DesertSunligh"),
		.itemId = ITEM_CARD_DESERT_SUNLIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_DRAW] =
	{
		.name = _("DestinyDraw"),
		.itemId = ITEM_CARD_DESTINY_DRAW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_CELESTIAL] =
	{
		.name = _("DestinyHEROCe"),
		.itemId = ITEM_CARD_DESTINY_HERO_CELESTIAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_DASHER] =
	{
		.name = _("DestinyHERODa"),
		.itemId = ITEM_CARD_DESTINY_HERO_DASHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_DESTROYER_PHOENIX_ENFORCER] =
	{
		.name = _("DestinyHERODe"),
		.itemId = ITEM_CARD_DESTINY_HERO_DESTROYER_PHOENIX_ENFORCER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_DIAMOND_DUDE] =
	{
		.name = _("DestinyHERODi"),
		.itemId = ITEM_CARD_DESTINY_HERO_DIAMOND_DUDE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_DISK_COMMANDER] =
	{
		.name = _("DestinyHERODi"),
		.itemId = ITEM_CARD_DESTINY_HERO_DISK_COMMANDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_FEAR_MONGER] =
	{
		.name = _("DestinyHEROFe"),
		.itemId = ITEM_CARD_DESTINY_HERO_FEAR_MONGER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DESTINY_HERO_MALICIOUS] =
	{
		.name = _("DestinyHEROMa"),
		.itemId = ITEM_CARD_DESTINY_HERO_MALICIOUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DHARC_THE_DARK_CHARMER_GLOOMY] =
	{
		.name = _("DharctheDarkC"),
		.itemId = ITEM_CARD_DHARC_THE_DARK_CHARMER_GLOOMY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIABELLSTAR_THE_BLACK_WITCH] =
	{
		.name = _("Diabellstarth"),
		.itemId = ITEM_CARD_DIABELLSTAR_THE_BLACK_WITCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIAMOND_DIRE_WOLF] =
	{
		.name = _("DiamondDireWo"),
		.itemId = ITEM_CARD_DIAMOND_DIRE_WOLF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIAN_KETO_THE_CURE_MASTER] =
	{
		.name = _("DianKetotheCu"),
		.itemId = ITEM_CARD_DIAN_KETO_THE_CURE_MASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DICTATOR_OF_D_] =
	{
		.name = _("DictatorofD"),
		.itemId = ITEM_CARD_DICTATOR_OF_D_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSION_CONJURER] =
	{
		.name = _("DimensionConj"),
		.itemId = ITEM_CARD_DIMENSION_CONJURER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSION_FUSION] =
	{
		.name = _("DimensionFusi"),
		.itemId = ITEM_CARD_DIMENSION_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSION_SHIFTER] =
	{
		.name = _("DimensionShif"),
		.itemId = ITEM_CARD_DIMENSION_SHIFTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSION_WALL] =
	{
		.name = _("DimensionWall"),
		.itemId = ITEM_CARD_DIMENSION_WALL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSIONAL_BARRIER] =
	{
		.name = _("DimensionalBa"),
		.itemId = ITEM_CARD_DIMENSIONAL_BARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSIONAL_FISSURE] =
	{
		.name = _("DimensionalFi"),
		.itemId = ITEM_CARD_DIMENSIONAL_FISSURE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIMENSIONAL_PRISON] =
	{
		.name = _("DimensionalPr"),
		.itemId = ITEM_CARD_DIMENSIONAL_PRISON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINGIRSU_THE_ORCUST_OF_THE_EVENING_STAR] =
	{
		.name = _("DingirsutheOr"),
		.itemId = ITEM_CARD_DINGIRSU_THE_ORCUST_OF_THE_EVENING_STAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINOMIGHT_KNIGHT_THE_TRUE_DRACOFIGHTER] =
	{
		.name = _("DinomightKnig"),
		.itemId = ITEM_CARD_DINOMIGHT_KNIGHT_THE_TRUE_DRACOFIGHTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINOSTER_POWER_THE_MIGHTY_DRACOSLAYER] =
	{
		.name = _("DinosterPower"),
		.itemId = ITEM_CARD_DINOSTER_POWER_THE_MIGHTY_DRACOSLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINOWRESTLER_CAPAPTERA] =
	{
		.name = _("DinowrestlerC"),
		.itemId = ITEM_CARD_DINOWRESTLER_CAPAPTERA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINOWRESTLER_PANKRATOPS] =
	{
		.name = _("DinowrestlerP"),
		.itemId = ITEM_CARD_DINOWRESTLER_PANKRATOPS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DINOWRESTLER_VALEONYX] =
	{
		.name = _("DinowrestlerV"),
		.itemId = ITEM_CARD_DINOWRESTLER_VALEONYX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DISCIPLE_OF_NEPHTHYS] =
	{
		.name = _("DiscipleofNep"),
		.itemId = ITEM_CARD_DISCIPLE_OF_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIVINE_ARSENAL_AA_ZEUS_SKY_THUNDER] =
	{
		.name = _("DivineArsenal"),
		.itemId = ITEM_CARD_DIVINE_ARSENAL_AA_ZEUS_SKY_THUNDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIVINE_DRAGON_KNIGHT_FELGRAND] =
	{
		.name = _("DivineDragonK"),
		.itemId = ITEM_CARD_DIVINE_DRAGON_KNIGHT_FELGRAND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIVINE_TEMPLE_OF_THE_SNAKE_EYE] =
	{
		.name = _("DivineTempleo"),
		.itemId = ITEM_CARD_DIVINE_TEMPLE_OF_THE_SNAKE_EYE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DIVINE_WRATH] =
	{
		.name = _("DivineWrath"),
		.itemId = ITEM_CARD_DIVINE_WRATH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DNA_SURGERY] =
	{
		.name = _("DNASurgery"),
		.itemId = ITEM_CARD_DNA_SURGERY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DOMINUS_IMPULSE] =
	{
		.name = _("DominusImpuls"),
		.itemId = ITEM_CARD_DOMINUS_IMPULSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DON_ZALOOG] =
	{
		.name = _("DonZaloog"),
		.itemId = ITEM_CARD_DON_ZALOOG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DOOM_DOZER] =
	{
		.name = _("DoomDozer"),
		.itemId = ITEM_CARD_DOOM_DOZER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DOOMCALIBER_KNIGHT] =
	{
		.name = _("DoomcaliberKn"),
		.itemId = ITEM_CARD_DOOMCALIBER_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DOOMKAISER_DRAGON] =
	{
		.name = _("DoomkaiserDra"),
		.itemId = ITEM_CARD_DOOMKAISER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DOWNERD_MAGICIAN] =
	{
		.name = _("DownerdMagici"),
		.itemId = ITEM_CARD_DOWNERD_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRACO_FACE_OFF] =
	{
		.name = _("DracoFaceOff"),
		.itemId = ITEM_CARD_DRACO_FACE_OFF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRACOBACK_THE_RIDEABLE_DRAGON] =
	{
		.name = _("DracobacktheR"),
		.itemId = ITEM_CARD_DRACOBACK_THE_RIDEABLE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGGED_DOWN_INTO_THE_GRAVE] =
	{
		.name = _("DraggedDownin"),
		.itemId = ITEM_CARD_DRAGGED_DOWN_INTO_THE_GRAVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGON_RAVINE] =
	{
		.name = _("DragonRavine"),
		.itemId = ITEM_CARD_DRAGON_RAVINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGON_SHRINE] =
	{
		.name = _("DragonShrine"),
		.itemId = ITEM_CARD_DRAGON_SHRINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGON_S_MIRROR] =
	{
		.name = _("DragonsMirror"),
		.itemId = ITEM_CARD_DRAGON_S_MIRROR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGON_S_RAGE] =
	{
		.name = _("DragonsRage"),
		.itemId = ITEM_CARD_DRAGON_S_RAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGONESS_THE_WICKED_KNIGHT] =
	{
		.name = _("DragonesstheW"),
		.itemId = ITEM_CARD_DRAGONESS_THE_WICKED_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGONIC_DIAGRAM] =
	{
		.name = _("DragonicDiagr"),
		.itemId = ITEM_CARD_DRAGONIC_DIAGRAM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRAGUNITY_CORSESCA] =
	{
		.name = _("DragunityCors"),
		.itemId = ITEM_CARD_DRAGUNITY_CORSESCA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DREAM_CLOWN] =
	{
		.name = _("DreamClown"),
		.itemId = ITEM_CARD_DREAM_CLOWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DRILLROID] =
	{
		.name = _("Drillroid"),
		.itemId = ITEM_CARD_DRILLROID,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DROLL_LOCK_BIRD] =
	{
		.name = _("DrollLockBird"),
		.itemId = ITEM_CARD_DROLL_LOCK_BIRD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DROP_OFF] =
	{
		.name = _("DropOff"),
		.itemId = ITEM_CARD_DROP_OFF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DUNAMES_DARK_WITCH] =
	{
		.name = _("DunamesDarkWi"),
		.itemId = ITEM_CARD_DUNAMES_DARK_WITCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DUPE_FROG] =
	{
		.name = _("DupeFrog"),
		.itemId = ITEM_CARD_DUPE_FROG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_DUST_TORNADO] =
	{
		.name = _("DustTornado"),
		.itemId = ITEM_CARD_DUST_TORNADO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EARTH_EFFIGY] =
	{
		.name = _("EarthEffigy"),
		.itemId = ITEM_CARD_EARTH_EFFIGY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EARTHBOUND_SPIRIT] =
	{
		.name = _("EarthboundSpi"),
		.itemId = ITEM_CARD_EARTHBOUND_SPIRIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EFFECT_VEILER] =
	{
		.name = _("EffectVeiler"),
		.itemId = ITEM_CARD_EFFECT_VEILER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EHTHER_THE_HEAVENLY_MONARCH] =
	{
		.name = _("EhthertheHeav"),
		.itemId = ITEM_CARD_EHTHER_THE_HEAVENLY_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EIDOS_THE_UNDERWORLD_MONARCH] =
	{
		.name = _("EidostheUnder"),
		.itemId = ITEM_CARD_EIDOS_THE_UNDERWORLD_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EIDOS_THE_UNDERWORLD_SQUIRE] =
	{
		.name = _("EidostheUnder"),
		.itemId = ITEM_CARD_EIDOS_THE_UNDERWORLD_SQUIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_ANOYATYLLIS] =
	{
		.name = _("ElShaddollAno"),
		.itemId = ITEM_CARD_EL_SHADDOLL_ANOYATYLLIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_APKALLONE] =
	{
		.name = _("ElShaddollApk"),
		.itemId = ITEM_CARD_EL_SHADDOLL_APKALLONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_CONSTRUCT] =
	{
		.name = _("ElShaddollCon"),
		.itemId = ITEM_CARD_EL_SHADDOLL_CONSTRUCT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_FUSION] =
	{
		.name = _("ElShaddollFus"),
		.itemId = ITEM_CARD_EL_SHADDOLL_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_GRYSTA] =
	{
		.name = _("ElShaddollGry"),
		.itemId = ITEM_CARD_EL_SHADDOLL_GRYSTA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_SHEKHINAGA] =
	{
		.name = _("ElShaddollShe"),
		.itemId = ITEM_CARD_EL_SHADDOLL_SHEKHINAGA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_WENDIGO] =
	{
		.name = _("ElShaddollWen"),
		.itemId = ITEM_CARD_EL_SHADDOLL_WENDIGO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EL_SHADDOLL_WINDA] =
	{
		.name = _("ElShaddollWin"),
		.itemId = ITEM_CARD_EL_SHADDOLL_WINDA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELDER_ENTITY_NORDEN] =
	{
		.name = _("ElderEntityNo"),
		.itemId = ITEM_CARD_ELDER_ENTITY_NORDEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELECTRIC_SNAKE] =
	{
		.name = _("ElectricSnake"),
		.itemId = ITEM_CARD_ELECTRIC_SNAKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELECTRIC_VIRUS] =
	{
		.name = _("ElectricVirus"),
		.itemId = ITEM_CARD_ELECTRIC_VIRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_BLAZEMAN] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_BLAZEMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_CLAYMAN] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_CLAYMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_FLAME_WINGMAN] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_FLAME_WINGMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_PRISMA] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_PRISMA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_STRATOS] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_STRATOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_WILDHEART] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_WILDHEART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ELEMENTAL_HERO_WOODSMAN] =
	{
		.name = _("ElementalHERO"),
		.itemId = ITEM_CARD_ELEMENTAL_HERO_WOODSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EMERGENCY_PROVISIONS] =
	{
		.name = _("EmergencyProv"),
		.itemId = ITEM_CARD_EMERGENCY_PROVISIONS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EMERGENCY_TELEPORT] =
	{
		.name = _("EmergencyTele"),
		.itemId = ITEM_CARD_EMERGENCY_TELEPORT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EMILIA_DANCE_PRIESTESS_OF_THE_NEKROZ] =
	{
		.name = _("EmiliaDancePr"),
		.itemId = ITEM_CARD_EMILIA_DANCE_PRIESTESS_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EMISSARY_OF_THE_AFTERLIFE] =
	{
		.name = _("Emissaryofthe"),
		.itemId = ITEM_CARD_EMISSARY_OF_THE_AFTERLIFE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EMPRESS_JUDGE] =
	{
		.name = _("EmpressJudge"),
		.itemId = ITEM_CARD_EMPRESS_JUDGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ENEMY_CONTROLLER] =
	{
		.name = _("EnemyControll"),
		.itemId = ITEM_CARD_ENEMY_CONTROLLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ENVOY_OF_CHAOS] =
	{
		.name = _("EnvoyofChaos"),
		.itemId = ITEM_CARD_ENVOY_OF_CHAOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ERADICATOR_EPIDEMIC_VIRUS] =
	{
		.name = _("EradicatorEpi"),
		.itemId = ITEM_CARD_ERADICATOR_EPIDEMIC_VIRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EREBUS_THE_UNDERWORLD_MONARCH] =
	{
		.name = _("ErebustheUnde"),
		.itemId = ITEM_CARD_EREBUS_THE_UNDERWORLD_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ESCAPE_FROM_THE_DARK_DIMENSION] =
	{
		.name = _("Escapefromthe"),
		.itemId = ITEM_CARD_ESCAPE_FROM_THE_DARK_DIMENSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVENING_TWILIGHT_KNIGHT] =
	{
		.name = _("EveningTwilig"),
		.itemId = ITEM_CARD_EVENING_TWILIGHT_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVENLY_MATCHED] =
	{
		.name = _("EvenlyMatched"),
		.itemId = ITEM_CARD_EVENLY_MATCHED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVILSWARM_EXCITON_KNIGHT] =
	{
		.name = _("EvilswarmExci"),
		.itemId = ITEM_CARD_EVILSWARM_EXCITON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVILSWARM_HELIOTROPE] =
	{
		.name = _("EvilswarmHeli"),
		.itemId = ITEM_CARD_EVILSWARM_HELIOTROPE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVILSWARM_KETOS] =
	{
		.name = _("EvilswarmKeto"),
		.itemId = ITEM_CARD_EVILSWARM_KETOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EVOLZAR_LAGGIA] =
	{
		.name = _("EvolzarLaggia"),
		.itemId = ITEM_CARD_EVOLZAR_LAGGIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXA_ENFORCER_OF_THE_NEKROZ] =
	{
		.name = _("ExaEnforcerof"),
		.itemId = ITEM_CARD_EXA_ENFORCER_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXARION_UNIVERSE] =
	{
		.name = _("ExarionUniver"),
		.itemId = ITEM_CARD_EXARION_UNIVERSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXCHANGE] =
	{
		.name = _("Exchange"),
		.itemId = ITEM_CARD_EXCHANGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXCHANGE_OF_THE_SPIRIT] =
	{
		.name = _("Exchangeofthe"),
		.itemId = ITEM_CARD_EXCHANGE_OF_THE_SPIRIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXILED_FORCE] =
	{
		.name = _("ExiledForce"),
		.itemId = ITEM_CARD_EXILED_FORCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXODIA_THE_FORBIDDEN_ONE] =
	{
		.name = _("ExodiatheForb"),
		.itemId = ITEM_CARD_EXODIA_THE_FORBIDDEN_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_EXT_RYZEAL] =
	{
		.name = _("ExtRyzeal"),
		.itemId = ITEM_CARD_EXT_RYZEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FABLED_LURRIE] =
	{
		.name = _("FabledLurrie"),
		.itemId = ITEM_CARD_FABLED_LURRIE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAIRY_TAIL_SNOW] =
	{
		.name = _("FairyTailSnow"),
		.itemId = ITEM_CARD_FAIRY_TAIL_SNOW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAIRY_WIND] =
	{
		.name = _("FairyWind"),
		.itemId = ITEM_CARD_FAIRY_WIND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAKE_TRAP] =
	{
		.name = _("FakeTrap"),
		.itemId = ITEM_CARD_FAKE_TRAP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FALLEN_OF_ALBAZ] =
	{
		.name = _("FallenofAlbaz"),
		.itemId = ITEM_CARD_FALLEN_OF_ALBAZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAMILIAR_POSSESSED_AUSSA] =
	{
		.name = _("FamiliarPosse"),
		.itemId = ITEM_CARD_FAMILIAR_POSSESSED_AUSSA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAMILIAR_POSSESSED_ERIA] =
	{
		.name = _("FamiliarPosse"),
		.itemId = ITEM_CARD_FAMILIAR_POSSESSED_ERIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAMILIAR_POSSESSED_HIITA] =
	{
		.name = _("FamiliarPosse"),
		.itemId = ITEM_CARD_FAMILIAR_POSSESSED_HIITA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FAMILIAR_POSSESSED_WYNN] =
	{
		.name = _("FamiliarPosse"),
		.itemId = ITEM_CARD_FAMILIAR_POSSESSED_WYNN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FANTASTICAL_DRAGON_PHANTAZMAY] =
	{
		.name = _("FantasticalDr"),
		.itemId = ITEM_CARD_FANTASTICAL_DRAGON_PHANTAZMAY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FARFA_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("FarfaMalebran"),
		.itemId = ITEM_CARD_FARFA_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FATEFUL_ADVENTURE] =
	{
		.name = _("FatefulAdvent"),
		.itemId = ITEM_CARD_FATEFUL_ADVENTURE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIBER_JAR] =
	{
		.name = _("FiberJar"),
		.itemId = ITEM_CARD_FIBER_JAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIEND_GRIEFING] =
	{
		.name = _("FiendGriefing"),
		.itemId = ITEM_CARD_FIEND_GRIEFING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIEND_SKULL_DRAGON] =
	{
		.name = _("FiendSkullDra"),
		.itemId = ITEM_CARD_FIEND_SKULL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDISH_CHAIN] =
	{
		.name = _("FiendishChain"),
		.itemId = ITEM_CARD_FIENDISH_CHAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDSMITH_ENGRAVER] =
	{
		.name = _("FiendsmithEng"),
		.itemId = ITEM_CARD_FIENDSMITH_ENGRAVER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDSMITH_S_LACRIMA] =
	{
		.name = _("FiendsmithsLa"),
		.itemId = ITEM_CARD_FIENDSMITH_S_LACRIMA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDSMITH_S_REQUIEM] =
	{
		.name = _("FiendsmithsRe"),
		.itemId = ITEM_CARD_FIENDSMITH_S_REQUIEM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDSMITH_S_SEQUENCE] =
	{
		.name = _("FiendsmithsSe"),
		.itemId = ITEM_CARD_FIENDSMITH_S_SEQUENCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIENDSMITH_S_TRACT] =
	{
		.name = _("FiendsmithsTr"),
		.itemId = ITEM_CARD_FIENDSMITH_S_TRACT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIGHTING_FLAME_SWORDSMAN] =
	{
		.name = _("FightingFlame"),
		.itemId = ITEM_CARD_FIGHTING_FLAME_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FINAL_FLAME] =
	{
		.name = _("FinalFlame"),
		.itemId = ITEM_CARD_FINAL_FLAME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIRE_FORMATION_TENKI] =
	{
		.name = _("FireFormation"),
		.itemId = ITEM_CARD_FIRE_FORMATION_TENKI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIRE_HAND] =
	{
		.name = _("FireHand"),
		.itemId = ITEM_CARD_FIRE_HAND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIRE_KING_HIGH_AVATAR_KIRIN] =
	{
		.name = _("FireKingHighA"),
		.itemId = ITEM_CARD_FIRE_KING_HIGH_AVATAR_KIRIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIRE_LAKE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("FireLakeofthe"),
		.itemId = ITEM_CARD_FIRE_LAKE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FIREWALL_DRAGON] =
	{
		.name = _("FirewallDrago"),
		.itemId = ITEM_CARD_FIREWALL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FISSURE] =
	{
		.name = _("Fissure"),
		.itemId = ITEM_CARD_FISSURE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLAME_BUFFERLO] =
	{
		.name = _("FlameBufferlo"),
		.itemId = ITEM_CARD_FLAME_BUFFERLO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLAME_GHOST] =
	{
		.name = _("FlameGhost"),
		.itemId = ITEM_CARD_FLAME_GHOST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLAME_SWORDSMAN] =
	{
		.name = _("FlameSwordsma"),
		.itemId = ITEM_CARD_FLAME_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLAMVELL_GUARD] =
	{
		.name = _("FlamvellGuard"),
		.itemId = ITEM_CARD_FLAMVELL_GUARD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLIP_FLOP_FROG] =
	{
		.name = _("FlipFlopFrog"),
		.itemId = ITEM_CARD_FLIP_FLOP_FROG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLOODGATE_TRAP_HOLE] =
	{
		.name = _("FloodgateTrap"),
		.itemId = ITEM_CARD_FLOODGATE_TRAP_HOLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLYING_C_] =
	{
		.name = _("FlyingC"),
		.itemId = ITEM_CARD_FLYING_C_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FLYING_KAMAKIRI_1] =
	{
		.name = _("FlyingKamakir"),
		.itemId = ITEM_CARD_FLYING_KAMAKIRI_1,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FOOLISH_BURIAL] =
	{
		.name = _("FoolishBurial"),
		.itemId = ITEM_CARD_FOOLISH_BURIAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FORBIDDEN_APOCRYPHA] =
	{
		.name = _("ForbiddenApoc"),
		.itemId = ITEM_CARD_FORBIDDEN_APOCRYPHA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FORBIDDEN_CHALICE] =
	{
		.name = _("ForbiddenChal"),
		.itemId = ITEM_CARD_FORBIDDEN_CHALICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FORBIDDEN_DROPLET] =
	{
		.name = _("ForbiddenDrop"),
		.itemId = ITEM_CARD_FORBIDDEN_DROPLET,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FORBIDDEN_LANCE] =
	{
		.name = _("ForbiddenLanc"),
		.itemId = ITEM_CARD_FORBIDDEN_LANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FORMULA_SYNCHRON] =
	{
		.name = _("FormulaSynchr"),
		.itemId = ITEM_CARD_FORMULA_SYNCHRON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FOSSIL_DYNA_PACHYCEPHALO] =
	{
		.name = _("FossilDynaPac"),
		.itemId = ITEM_CARD_FOSSIL_DYNA_PACHYCEPHALO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FRONTIER_WISEMAN] =
	{
		.name = _("FrontierWisem"),
		.itemId = ITEM_CARD_FRONTIER_WISEMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FULL_HOUSE] =
	{
		.name = _("FullHouse"),
		.itemId = ITEM_CARD_FULL_HOUSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST] =
	{
		.name = _("FusilierDrago"),
		.itemId = ITEM_CARD_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FUSION_DESTINY] =
	{
		.name = _("FusionDestiny"),
		.itemId = ITEM_CARD_FUSION_DESTINY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FUSION_DEVOURER] =
	{
		.name = _("FusionDevoure"),
		.itemId = ITEM_CARD_FUSION_DEVOURER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_FUSION_SUBSTITUTE] =
	{
		.name = _("FusionSubstit"),
		.itemId = ITEM_CARD_FUSION_SUBSTITUTE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAGAGA_COWBOY] =
	{
		.name = _("GagagaCowboy"),
		.itemId = ITEM_CARD_GAGAGA_COWBOY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAGAGIGO] =
	{
		.name = _("Gagagigo"),
		.itemId = ITEM_CARD_GAGAGIGO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAIA_KNIGHT_THE_FORCE_OF_EARTH] =
	{
		.name = _("GaiaKnightthe"),
		.itemId = ITEM_CARD_GAIA_KNIGHT_THE_FORCE_OF_EARTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAIA_POWER] =
	{
		.name = _("GaiaPower"),
		.itemId = ITEM_CARD_GAIA_POWER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAIA_THE_DRAGON_CHAMPION] =
	{
		.name = _("GaiatheDragon"),
		.itemId = ITEM_CARD_GAIA_THE_DRAGON_CHAMPION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAIA_THE_FIERCE_KNIGHT] =
	{
		.name = _("GaiaTheFierce"),
		.itemId = ITEM_CARD_GAIA_THE_FIERCE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GALATEA_THE_ORCUST_AUTOMATON] =
	{
		.name = _("GalateatheOrc"),
		.itemId = ITEM_CARD_GALATEA_THE_ORCUST_AUTOMATON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GALAXY_CYCLONE] =
	{
		.name = _("GalaxyCyclone"),
		.itemId = ITEM_CARD_GALAXY_CYCLONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAMECIEL_THE_SEA_TURTLE_KAIJU] =
	{
		.name = _("GamecieltheSe"),
		.itemId = ITEM_CARD_GAMECIEL_THE_SEA_TURTLE_KAIJU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GAROTH_LIGHTSWORN_WARRIOR] =
	{
		.name = _("GarothLightsw"),
		.itemId = ITEM_CARD_GAROTH_LIGHTSWORN_WARRIOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GARURA_WINGS_OF_RESONANT_LIFE] =
	{
		.name = _("GaruraWingsof"),
		.itemId = ITEM_CARD_GARURA_WINGS_OF_RESONANT_LIFE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GATLING_DRAGON] =
	{
		.name = _("GatlingDragon"),
		.itemId = ITEM_CARD_GATLING_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEAR_GOLEM_THE_MOVING_FORTRESS] =
	{
		.name = _("GearGolemtheM"),
		.itemId = ITEM_CARD_GEAR_GOLEM_THE_MOVING_FORTRESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEARFRIED_THE_IRON_KNIGHT] =
	{
		.name = _("GearfriedtheI"),
		.itemId = ITEM_CARD_GEARFRIED_THE_IRON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEARFRIED_THE_RED_EYES_IRON_KNIGHT] =
	{
		.name = _("GearfriedtheR"),
		.itemId = ITEM_CARD_GEARFRIED_THE_RED_EYES_IRON_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_ARMADILLO] =
	{
		.name = _("GemArmadillo"),
		.itemId = ITEM_CARD_GEM_ARMADILLO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_ELEPHANT] =
	{
		.name = _("GemElephant"),
		.itemId = ITEM_CARD_GEM_ELEPHANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_ALEXANDRITE] =
	{
		.name = _("GemKnightAlex"),
		.itemId = ITEM_CARD_GEM_KNIGHT_ALEXANDRITE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_EMERALD] =
	{
		.name = _("GemKnightEmer"),
		.itemId = ITEM_CARD_GEM_KNIGHT_EMERALD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_GARNET] =
	{
		.name = _("GemKnightGarn"),
		.itemId = ITEM_CARD_GEM_KNIGHT_GARNET,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_HOLLOWCORE] =
	{
		.name = _("GemKnightHoll"),
		.itemId = ITEM_CARD_GEM_KNIGHT_HOLLOWCORE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_LADY_ROSE_DIAMOND] =
	{
		.name = _("GemKnightLady"),
		.itemId = ITEM_CARD_GEM_KNIGHT_LADY_ROSE_DIAMOND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_NEPYRIM] =
	{
		.name = _("GemKnightNepy"),
		.itemId = ITEM_CARD_GEM_KNIGHT_NEPYRIM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_PRISMAURA] =
	{
		.name = _("GemKnightPris"),
		.itemId = ITEM_CARD_GEM_KNIGHT_PRISMAURA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_QUARTZ] =
	{
		.name = _("GemKnightQuar"),
		.itemId = ITEM_CARD_GEM_KNIGHT_QUARTZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_RUBY] =
	{
		.name = _("GemKnightRuby"),
		.itemId = ITEM_CARD_GEM_KNIGHT_RUBY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_SAPPHIRE] =
	{
		.name = _("GemKnightSapp"),
		.itemId = ITEM_CARD_GEM_KNIGHT_SAPPHIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_TOURMALINE] =
	{
		.name = _("GemKnightTour"),
		.itemId = ITEM_CARD_GEM_KNIGHT_TOURMALINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_KNIGHT_ZIRCONIA] =
	{
		.name = _("GemKnightZirc"),
		.itemId = ITEM_CARD_GEM_KNIGHT_ZIRCONIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEM_TURTLE] =
	{
		.name = _("GemTurtle"),
		.itemId = ITEM_CARD_GEM_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEMINI_ELF] =
	{
		.name = _("GeminiElf"),
		.itemId = ITEM_CARD_GEMINI_ELF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GEMINI_IMPS] =
	{
		.name = _("GeminiImps"),
		.itemId = ITEM_CARD_GEMINI_IMPS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GENE_WARPED_WARWOLF] =
	{
		.name = _("GeneWarpedWar"),
		.itemId = ITEM_CARD_GENE_WARPED_WARWOLF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GENTA_GATEMAN_OF_DARK_WORLD] =
	{
		.name = _("GentaGatemano"),
		.itemId = ITEM_CARD_GENTA_GATEMAN_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GHOST_BELLE_HAUNTED_MANSION] =
	{
		.name = _("GhostBelleHau"),
		.itemId = ITEM_CARD_GHOST_BELLE_HAUNTED_MANSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GHOST_MOURNER_MOONLIT_CHILL] =
	{
		.name = _("GhostMournerM"),
		.itemId = ITEM_CARD_GHOST_MOURNER_MOONLIT_CHILL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GHOST_OGRE_SNOW_RABBIT] =
	{
		.name = _("GhostOgreSnow"),
		.itemId = ITEM_CARD_GHOST_OGRE_SNOW_RABBIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GHOST_REAPER_WINTER_CHERRIES] =
	{
		.name = _("GhostReaperWi"),
		.itemId = ITEM_CARD_GHOST_REAPER_WINTER_CHERRIES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GHOST_SISTER_SPOOKY_DOGWOOD] =
	{
		.name = _("GhostSisterSp"),
		.itemId = ITEM_CARD_GHOST_SISTER_SPOOKY_DOGWOOD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_GERM] =
	{
		.name = _("GiantGerm"),
		.itemId = ITEM_CARD_GIANT_GERM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_ORC] =
	{
		.name = _("GiantOrc"),
		.itemId = ITEM_CARD_GIANT_ORC,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_RAT] =
	{
		.name = _("GiantRat"),
		.itemId = ITEM_CARD_GIANT_RAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_RED_SEASNAKE] =
	{
		.name = _("GiantRedSeasn"),
		.itemId = ITEM_CARD_GIANT_RED_SEASNAKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_SOLDIER_OF_STONE] =
	{
		.name = _("GiantSoldiero"),
		.itemId = ITEM_CARD_GIANT_SOLDIER_OF_STONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIANT_TRUNADE] =
	{
		.name = _("GiantTrunade"),
		.itemId = ITEM_CARD_GIANT_TRUNADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIGA_TECH_WOLF] =
	{
		.name = _("GigaTechWolf"),
		.itemId = ITEM_CARD_GIGA_TECH_WOLF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIGANTES] =
	{
		.name = _("Gigantes"),
		.itemId = ITEM_CARD_GIGANTES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIGANTIC_SPRIGHT] =
	{
		.name = _("GiganticSprig"),
		.itemId = ITEM_CARD_GIGANTIC_SPRIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GIL_GARTH] =
	{
		.name = _("GilGarth"),
		.itemId = ITEM_CARD_GIL_GARTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GILASAURUS] =
	{
		.name = _("Gilasaurus"),
		.itemId = ITEM_CARD_GILASAURUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GILTIA_THE_D_KNIGHT_SOUL_SPEAR] =
	{
		.name = _("GiltiatheDKni"),
		.itemId = ITEM_CARD_GILTIA_THE_D_KNIGHT_SOUL_SPEAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_ABYSS] =
	{
		.name = _("GishkiAbyss"),
		.itemId = ITEM_CARD_GISHKI_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_ARIEL] =
	{
		.name = _("GishkiAriel"),
		.itemId = ITEM_CARD_GISHKI_ARIEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_AVANCE] =
	{
		.name = _("GishkiAvance"),
		.itemId = ITEM_CARD_GISHKI_AVANCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_BEAST] =
	{
		.name = _("GishkiBeast"),
		.itemId = ITEM_CARD_GISHKI_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_CHAIN] =
	{
		.name = _("GishkiChain"),
		.itemId = ITEM_CARD_GISHKI_CHAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_EMILIA] =
	{
		.name = _("GishkiEmilia"),
		.itemId = ITEM_CARD_GISHKI_EMILIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_GRIMNESS] =
	{
		.name = _("GishkiGrimnes"),
		.itemId = ITEM_CARD_GISHKI_GRIMNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_MARKER] =
	{
		.name = _("GishkiMarker"),
		.itemId = ITEM_CARD_GISHKI_MARKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_NATALIA] =
	{
		.name = _("GishkiNatalia"),
		.itemId = ITEM_CARD_GISHKI_NATALIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_NOELLIA] =
	{
		.name = _("GishkiNoellia"),
		.itemId = ITEM_CARD_GISHKI_NOELLIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_SHADOW] =
	{
		.name = _("GishkiShadow"),
		.itemId = ITEM_CARD_GISHKI_SHADOW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_VANITY] =
	{
		.name = _("GishkiVanity"),
		.itemId = ITEM_CARD_GISHKI_VANITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GISHKI_VISION] =
	{
		.name = _("GishkiVision"),
		.itemId = ITEM_CARD_GISHKI_VISION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_BESTIARI] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_BESTIARI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_DARIUS] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_DARIUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_GAIODIAZ] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_GAIODIAZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_GYZARUS] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_GYZARUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_HERAKLINOS] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_HERAKLINOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_LAQUARI] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_LAQUARI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GLADIATOR_BEAST_MURMILLO] =
	{
		.name = _("GladiatorBeas"),
		.itemId = ITEM_CARD_GLADIATOR_BEAST_MURMILLO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOBLIN_ATTACK_FORCE] =
	{
		.name = _("GoblinAttackF"),
		.itemId = ITEM_CARD_GOBLIN_ATTACK_FORCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOBLIN_ELITE_ATTACK_FORCE] =
	{
		.name = _("GoblinEliteAt"),
		.itemId = ITEM_CARD_GOBLIN_ELITE_ATTACK_FORCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOBLIN_POTHOLE_SQUAD] =
	{
		.name = _("GoblinPothole"),
		.itemId = ITEM_CARD_GOBLIN_POTHOLE_SQUAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOBLIN_ZOMBIE] =
	{
		.name = _("GoblinZombie"),
		.itemId = ITEM_CARD_GOBLIN_ZOMBIE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOKIPON] =
	{
		.name = _("Gokipon"),
		.itemId = ITEM_CARD_GOKIPON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOLD_SARCOPHAGUS] =
	{
		.name = _("GoldSarcophag"),
		.itemId = ITEM_CARD_GOLD_SARCOPHAGUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOLDD_WU_LORD_OF_DARK_WORLD] =
	{
		.name = _("GolddWuLordof"),
		.itemId = ITEM_CARD_GOLDD_WU_LORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOLEM_SENTRY] =
	{
		.name = _("GolemSentry"),
		.itemId = ITEM_CARD_GOLEM_SENTRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GORA_TURTLE] =
	{
		.name = _("GoraTurtle"),
		.itemId = ITEM_CARD_GORA_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GORZ_THE_EMISSARY_OF_DARKNESS] =
	{
		.name = _("GorztheEmissa"),
		.itemId = ITEM_CARD_GORZ_THE_EMISSARY_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOTTOMS_EMERGENCY_CALL] =
	{
		.name = _("GottomsEmerge"),
		.itemId = ITEM_CARD_GOTTOMS_EMERGENCY_CALL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GOYO_GUARDIAN] =
	{
		.name = _("GoyoGuardian"),
		.itemId = ITEM_CARD_GOYO_GUARDIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRACEFUL_CHARITY] =
	{
		.name = _("GracefulChari"),
		.itemId = ITEM_CARD_GRACEFUL_CHARITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAFF_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("GraffMalebran"),
		.itemId = ITEM_CARD_GRAFF_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRANGUIGNOL_THE_DUSK_DRAGON] =
	{
		.name = _("Granguignolth"),
		.itemId = ITEM_CARD_GRANGUIGNOL_THE_DUSK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRANMARG_THE_MEGA_MONARCH] =
	{
		.name = _("GranmargtheMe"),
		.itemId = ITEM_CARD_GRANMARG_THE_MEGA_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRANMARG_THE_ROCK_MONARCH] =
	{
		.name = _("GranmargtheRo"),
		.itemId = ITEM_CARD_GRANMARG_THE_ROCK_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAPHA_DRAGON_LORD_OF_DARK_WORLD] =
	{
		.name = _("GraphaDragonL"),
		.itemId = ITEM_CARD_GRAPHA_DRAGON_LORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAPHA_DRAGON_OVERLORD_OF_DARK_WORLD] =
	{
		.name = _("GraphaDragonO"),
		.itemId = ITEM_CARD_GRAPHA_DRAGON_OVERLORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVEKEEPER_S_ASSAILANT] =
	{
		.name = _("GravekeepersA"),
		.itemId = ITEM_CARD_GRAVEKEEPER_S_ASSAILANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVEKEEPER_S_GUARD] =
	{
		.name = _("GravekeepersG"),
		.itemId = ITEM_CARD_GRAVEKEEPER_S_GUARD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVEKEEPER_S_SPEAR_SOLDIER] =
	{
		.name = _("GravekeepersS"),
		.itemId = ITEM_CARD_GRAVEKEEPER_S_SPEAR_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVEKEEPER_S_SPY] =
	{
		.name = _("GravekeepersS"),
		.itemId = ITEM_CARD_GRAVEKEEPER_S_SPY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVEKEEPER_S_WATCHER] =
	{
		.name = _("GravekeepersW"),
		.itemId = ITEM_CARD_GRAVEKEEPER_S_WATCHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GRAVITY_BIND] =
	{
		.name = _("GravityBind"),
		.itemId = ITEM_CARD_GRAVITY_BIND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GREAT_WHITE] =
	{
		.name = _("GreatWhite"),
		.itemId = ITEM_CARD_GREAT_WHITE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GREEN_NINJA] =
	{
		.name = _("GreenNinja"),
		.itemId = ITEM_CARD_GREEN_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GREN_TACTICIAN_OF_DARK_WORLD] =
	{
		.name = _("GrenTactician"),
		.itemId = ITEM_CARD_GREN_TACTICIAN_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GUARDIAN_SPHINX] =
	{
		.name = _("GuardianSphin"),
		.itemId = ITEM_CARD_GUARDIAN_SPHINX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GUARDRAGON_GARMIDES] =
	{
		.name = _("GuardragonGar"),
		.itemId = ITEM_CARD_GUARDRAGON_GARMIDES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GUIDING_ARIADNE] =
	{
		.name = _("GuidingAriadn"),
		.itemId = ITEM_CARD_GUIDING_ARIADNE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GUNKAN_SUSHIP_SHARI] =
	{
		.name = _("GunkanSushipS"),
		.itemId = ITEM_CARD_GUNKAN_SUSHIP_SHARI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GYAKU_GIRE_PANDA] =
	{
		.name = _("GyakuGirePand"),
		.itemId = ITEM_CARD_GYAKU_GIRE_PANDA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_GYAKUTENNO_MEGAMI] =
	{
		.name = _("GyakutennoMeg"),
		.itemId = ITEM_CARD_GYAKUTENNO_MEGAMI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HALLOWED_LIFE_BARRIER] =
	{
		.name = _("HallowedLifeB"),
		.itemId = ITEM_CARD_HALLOWED_LIFE_BARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HAMMER_SHOT] =
	{
		.name = _("HammerShot"),
		.itemId = ITEM_CARD_HAMMER_SHOT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HAND_OF_NEPHTHYS] =
	{
		.name = _("HandofNephthy"),
		.itemId = ITEM_CARD_HAND_OF_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HANE_HANE] =
	{
		.name = _("HaneHane"),
		.itemId = ITEM_CARD_HANE_HANE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HANEWATA] =
	{
		.name = _("Hanewata"),
		.itemId = ITEM_CARD_HANEWATA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HARPIE_S_FEATHER_DUSTER] =
	{
		.name = _("HarpiesFeathe"),
		.itemId = ITEM_CARD_HARPIE_S_FEATHER_DUSTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HEART_OF_THE_BLUE_EYES] =
	{
		.name = _("HeartoftheBlu"),
		.itemId = ITEM_CARD_HEART_OF_THE_BLUE_EYES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HEAVY_STORM] =
	{
		.name = _("HeavyStorm"),
		.itemId = ITEM_CARD_HEAVY_STORM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HEAVY_STORM_DUSTER] =
	{
		.name = _("HeavyStormDus"),
		.itemId = ITEM_CARD_HEAVY_STORM_DUSTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HERALD_OF_ORANGE_LIGHT] =
	{
		.name = _("HeraldofOrang"),
		.itemId = ITEM_CARD_HERALD_OF_ORANGE_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HERALD_OF_THE_ARC_LIGHT] =
	{
		.name = _("HeraldoftheAr"),
		.itemId = ITEM_CARD_HERALD_OF_THE_ARC_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HIERACOSPHINX] =
	{
		.name = _("Hieracosphinx"),
		.itemId = ITEM_CARD_HIERACOSPHINX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HIITA_THE_FIRE_CHARMER_ABLAZE] =
	{
		.name = _("HiitatheFireC"),
		.itemId = ITEM_CARD_HIITA_THE_FIRE_CHARMER_ABLAZE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HONEST] =
	{
		.name = _("Honest"),
		.itemId = ITEM_CARD_HONEST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HORN_OF_HEAVEN] =
	{
		.name = _("HornofHeaven"),
		.itemId = ITEM_CARD_HORN_OF_HEAVEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HORN_OF_THE_PHANTOM_BEAST] =
	{
		.name = _("HornofthePhan"),
		.itemId = ITEM_CARD_HORN_OF_THE_PHANTOM_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HOWLING_INSECT] =
	{
		.name = _("HowlingInsect"),
		.itemId = ITEM_CARD_HOWLING_INSECT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HUMANOID_SLIME] =
	{
		.name = _("HumanoidSlime"),
		.itemId = ITEM_CARD_HUMANOID_SLIME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HYDROGEDDON] =
	{
		.name = _("Hydrogeddon"),
		.itemId = ITEM_CARD_HYDROGEDDON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_HYPER_HAMMERHEAD] =
	{
		.name = _("HyperHammerhe"),
		.itemId = ITEM_CARD_HYPER_HAMMERHEAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_I_P_MASQUERENA] =
	{
		.name = _("IPMasquerena"),
		.itemId = ITEM_CARD_I_P_MASQUERENA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ICARUS_ATTACK] =
	{
		.name = _("IcarusAttack"),
		.itemId = ITEM_CARD_ICARUS_ATTACK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ICE_HAND] =
	{
		.name = _("IceHand"),
		.itemId = ITEM_CARD_ICE_HAND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ICE_KNIGHT] =
	{
		.name = _("IceKnight"),
		.itemId = ITEM_CARD_ICE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ICE_RYZEAL] =
	{
		.name = _("IceRyzeal"),
		.itemId = ITEM_CARD_ICE_RYZEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_IGNISTER_PROMINENCE_THE_BLASTING_DRACOSLAYER] =
	{
		.name = _("IgnisterPromi"),
		.itemId = ITEM_CARD_IGNISTER_PROMINENCE_THE_BLASTING_DRACOSLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ILLUSION_OF_CHAOS] =
	{
		.name = _("IllusionofCha"),
		.itemId = ITEM_CARD_ILLUSION_OF_CHAOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ILLUSORY_SNATCHER] =
	{
		.name = _("IllusorySnatc"),
		.itemId = ITEM_CARD_ILLUSORY_SNATCHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_IMPERIAL_IRON_WALL] =
	{
		.name = _("ImperialIronW"),
		.itemId = ITEM_CARD_IMPERIAL_IRON_WALL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_IMPERIAL_ORDER] =
	{
		.name = _("ImperialOrder"),
		.itemId = ITEM_CARD_IMPERIAL_ORDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INABA_WHITE_RABBIT] =
	{
		.name = _("InabaWhiteRab"),
		.itemId = ITEM_CARD_INABA_WHITE_RABBIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INCREDIBLE_ECCLESIA_THE_VIRTUOUS] =
	{
		.name = _("IncredibleEcc"),
		.itemId = ITEM_CARD_INCREDIBLE_ECCLESIA_THE_VIRTUOUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INDOMITABLE_FIGHTER_LEI_LEI] =
	{
		.name = _("IndomitableFi"),
		.itemId = ITEM_CARD_INDOMITABLE_FIGHTER_LEI_LEI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNALQUEEN_SALMON] =
	{
		.name = _("Infernalqueen"),
		.itemId = ITEM_CARD_INFERNALQUEEN_SALMON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_ARCHFIEND] =
	{
		.name = _("InfernityArch"),
		.itemId = ITEM_CARD_INFERNITY_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_BARRIER] =
	{
		.name = _("InfernityBarr"),
		.itemId = ITEM_CARD_INFERNITY_BARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_BEETLE] =
	{
		.name = _("InfernityBeet"),
		.itemId = ITEM_CARD_INFERNITY_BEETLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_INFERNO] =
	{
		.name = _("InfernityInfe"),
		.itemId = ITEM_CARD_INFERNITY_INFERNO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_LAUNCHER] =
	{
		.name = _("InfernityLaun"),
		.itemId = ITEM_CARD_INFERNITY_LAUNCHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNITY_NECROMANCER] =
	{
		.name = _("InfernityNecr"),
		.itemId = ITEM_CARD_INFERNITY_NECROMANCER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNOID_DECATRON] =
	{
		.name = _("InfernoidDeca"),
		.itemId = ITEM_CARD_INFERNOID_DECATRON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNOID_HARMADIK] =
	{
		.name = _("InfernoidHarm"),
		.itemId = ITEM_CARD_INFERNOID_HARMADIK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFERNOID_PATRULEA] =
	{
		.name = _("InfernoidPatr"),
		.itemId = ITEM_CARD_INFERNOID_PATRULEA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INFINITE_IMPERMANENCE] =
	{
		.name = _("InfiniteImper"),
		.itemId = ITEM_CARD_INFINITE_IMPERMANENCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INJECTION_FAIRY_LILY] =
	{
		.name = _("InjectionFair"),
		.itemId = ITEM_CARD_INJECTION_FAIRY_LILY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INPACHI] =
	{
		.name = _("Inpachi"),
		.itemId = ITEM_CARD_INPACHI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INSECT_KNIGHT] =
	{
		.name = _("InsectKnight"),
		.itemId = ITEM_CARD_INSECT_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INSTANT_FUSION] =
	{
		.name = _("InstantFusion"),
		.itemId = ITEM_CARD_INSTANT_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_INTERRUPTED_KAIJU_SLUMBER] =
	{
		.name = _("InterruptedKa"),
		.itemId = ITEM_CARD_INTERRUPTED_KAIJU_SLUMBER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ISLAND_TURTLE] =
	{
		.name = _("IslandTurtle"),
		.itemId = ITEM_CARD_ISLAND_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ISOLDE_TWO_TALES_OF_THE_NOBLE_KNIGHTS] =
	{
		.name = _("IsoldeTwoTale"),
		.itemId = ITEM_CARD_ISOLDE_TWO_TALES_OF_THE_NOBLE_KNIGHTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JAR_OF_GREED] =
	{
		.name = _("JarofGreed"),
		.itemId = ITEM_CARD_JAR_OF_GREED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JINZO] =
	{
		.name = _("Jinzo"),
		.itemId = ITEM_CARD_JINZO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JIOH_THE_GRAVITY_NINJA] =
	{
		.name = _("JiohtheGravit"),
		.itemId = ITEM_CARD_JIOH_THE_GRAVITY_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JIRAI_GUMO] =
	{
		.name = _("JiraiGumo"),
		.itemId = ITEM_CARD_JIRAI_GUMO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JONGLEUR_GHOUL_ILLUSIONIST] =
	{
		.name = _("JongleurGhoul"),
		.itemId = ITEM_CARD_JONGLEUR_GHOUL_ILLUSIONIST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JOWGEN_THE_SPIRITUALIST] =
	{
		.name = _("JowgentheSpir"),
		.itemId = ITEM_CARD_JOWGEN_THE_SPIRITUALIST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JUDGE_MAN] =
	{
		.name = _("JudgeMan"),
		.itemId = ITEM_CARD_JUDGE_MAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JUDGMENT_DRAGON] =
	{
		.name = _("JudgmentDrago"),
		.itemId = ITEM_CARD_JUDGMENT_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JURRAC_GUAIBA] =
	{
		.name = _("JurracGuaiba"),
		.itemId = ITEM_CARD_JURRAC_GUAIBA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_JUST_DESSERTS] =
	{
		.name = _("JustDesserts"),
		.itemId = ITEM_CARD_JUST_DESSERTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KABAZAULS] =
	{
		.name = _("Kabazauls"),
		.itemId = ITEM_CARD_KABAZAULS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KAGEMUSHA_OF_THE_SIX_SAMURAI] =
	{
		.name = _("Kagemushaofth"),
		.itemId = ITEM_CARD_KAGEMUSHA_OF_THE_SIX_SAMURAI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KAGERO_THE_CANNON_NINJA] =
	{
		.name = _("KagerotheCann"),
		.itemId = ITEM_CARD_KAGERO_THE_CANNON_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KAIBAMAN] =
	{
		.name = _("Kaibaman"),
		.itemId = ITEM_CARD_KAIBAMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KAISER_SEA_HORSE] =
	{
		.name = _("KaiserSeaHors"),
		.itemId = ITEM_CARD_KAISER_SEA_HORSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KARMA_CUT] =
	{
		.name = _("KarmaCut"),
		.itemId = ITEM_CARD_KARMA_CUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KASHTIRA_BIRTH] =
	{
		.name = _("KashtiraBirth"),
		.itemId = ITEM_CARD_KASHTIRA_BIRTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KASHTIRA_FENRIR] =
	{
		.name = _("KashtiraFenri"),
		.itemId = ITEM_CARD_KASHTIRA_FENRIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KASHTIRA_RISEHEART] =
	{
		.name = _("KashtiraRiseh"),
		.itemId = ITEM_CARD_KASHTIRA_RISEHEART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KASHTIRA_UNICORN] =
	{
		.name = _("KashtiraUnico"),
		.itemId = ITEM_CARD_KASHTIRA_UNICORN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KASHTIRATHEOSIS] =
	{
		.name = _("Kashtiratheos"),
		.itemId = ITEM_CARD_KASHTIRATHEOSIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KEEPER_OF_DRAGON_MAGIC] =
	{
		.name = _("KeeperofDrago"),
		.itemId = ITEM_CARD_KEEPER_OF_DRAGON_MAGIC,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KEEPER_OF_THE_SHRINE] =
	{
		.name = _("KeeperoftheSh"),
		.itemId = ITEM_CARD_KEEPER_OF_THE_SHRINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KELBEK_THE_ANCIENT_VANGUARD] =
	{
		.name = _("KelbektheAnci"),
		.itemId = ITEM_CARD_KELBEK_THE_ANCIENT_VANGUARD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KELDO_THE_SACRED_PROTECTOR] =
	{
		.name = _("KeldotheSacre"),
		.itemId = ITEM_CARD_KELDO_THE_SACRED_PROTECTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KING_DRAGUN] =
	{
		.name = _("KingDragun"),
		.itemId = ITEM_CARD_KING_DRAGUN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KING_OF_THE_FERAL_IMPS] =
	{
		.name = _("KingoftheFera"),
		.itemId = ITEM_CARD_KING_OF_THE_FERAL_IMPS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KING_OF_THE_SWAMP] =
	{
		.name = _("KingoftheSwam"),
		.itemId = ITEM_CARD_KING_OF_THE_SWAMP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KING_TIGER_WANGHU] =
	{
		.name = _("KingTigerWang"),
		.itemId = ITEM_CARD_KING_TIGER_WANGHU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KNIGHTMARE_CERBERUS] =
	{
		.name = _("KnightmareCer"),
		.itemId = ITEM_CARD_KNIGHTMARE_CERBERUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KNIGHTMARE_GOBLIN] =
	{
		.name = _("KnightmareGob"),
		.itemId = ITEM_CARD_KNIGHTMARE_GOBLIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KNIGHTMARE_PHOENIX] =
	{
		.name = _("KnightmarePho"),
		.itemId = ITEM_CARD_KNIGHTMARE_PHOENIX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KNIGHTMARE_UNICORN] =
	{
		.name = _("KnightmareUni"),
		.itemId = ITEM_CARD_KNIGHTMARE_UNICORN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMO_DARK_DESTROYER] =
	{
		.name = _("KozmoDarkDest"),
		.itemId = ITEM_CARD_KOZMO_DARK_DESTROYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMO_FARMGIRL] =
	{
		.name = _("KozmoFarmgirl"),
		.itemId = ITEM_CARD_KOZMO_FARMGIRL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMO_SLIPRIDER] =
	{
		.name = _("KozmoSlipride"),
		.itemId = ITEM_CARD_KOZMO_SLIPRIDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMO_TINCAN] =
	{
		.name = _("KozmoTincan"),
		.itemId = ITEM_CARD_KOZMO_TINCAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMOJO] =
	{
		.name = _("Kozmojo"),
		.itemId = ITEM_CARD_KOZMOJO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMOLL_WICKEDWITCH] =
	{
		.name = _("KozmollWicked"),
		.itemId = ITEM_CARD_KOZMOLL_WICKEDWITCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KOZMOTOWN] =
	{
		.name = _("Kozmotown"),
		.itemId = ITEM_CARD_KOZMOTOWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KREBONS] =
	{
		.name = _("Krebons"),
		.itemId = ITEM_CARD_KREBONS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KUMONGOUS_THE_STICKY_STRING_KAIJU] =
	{
		.name = _("KumongoustheS"),
		.itemId = ITEM_CARD_KUMONGOUS_THE_STICKY_STRING_KAIJU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KURIBOH] =
	{
		.name = _("Kuriboh"),
		.itemId = ITEM_CARD_KURIBOH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KURIKARA_DIVINCARNATE] =
	{
		.name = _("KurikaraDivin"),
		.itemId = ITEM_CARD_KURIKARA_DIVINCARNATE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_KYCOO_THE_GHOST_DESTROYER] =
	{
		.name = _("KycootheGhost"),
		.itemId = ITEM_CARD_KYCOO_THE_GHOST_DESTROYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP] =
	{
		.name = _("LaJinntheMyst"),
		.itemId = ITEM_CARD_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LABRYNTH_ARCHFIEND] =
	{
		.name = _("LabrynthArchf"),
		.itemId = ITEM_CARD_LABRYNTH_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LABYRINTH_TANK] =
	{
		.name = _("LabyrinthTank"),
		.itemId = ITEM_CARD_LABYRINTH_TANK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LACRIMA_THE_CRIMSON_TEARS] =
	{
		.name = _("LacrimatheCri"),
		.itemId = ITEM_CARD_LACRIMA_THE_CRIMSON_TEARS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LADY_NINJA_YAE] =
	{
		.name = _("LadyNinjaYae"),
		.itemId = ITEM_CARD_LADY_NINJA_YAE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LANCER_ARCHFIEND] =
	{
		.name = _("LancerArchfie"),
		.itemId = ITEM_CARD_LANCER_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LAST_WILL] =
	{
		.name = _("LastWill"),
		.itemId = ITEM_CARD_LAST_WILL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEECHING_THE_LIGHT] =
	{
		.name = _("LeechingtheLi"),
		.itemId = ITEM_CARD_LEECHING_THE_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEFT_ARM_OF_THE_FORBIDDEN_ONE] =
	{
		.name = _("LeftArmoftheF"),
		.itemId = ITEM_CARD_LEFT_ARM_OF_THE_FORBIDDEN_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEFT_LEG_OF_THE_FORBIDDEN_ONE] =
	{
		.name = _("LeftLegoftheF"),
		.itemId = ITEM_CARD_LEFT_LEG_OF_THE_FORBIDDEN_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEGACY_OF_YATA_GARASU] =
	{
		.name = _("LegacyofYataG"),
		.itemId = ITEM_CARD_LEGACY_OF_YATA_GARASU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEGENDARY_JUJITSU_MASTER] =
	{
		.name = _("LegendaryJuji"),
		.itemId = ITEM_CARD_LEGENDARY_JUJITSU_MASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEGENDARY_SIX_SAMURAI_KIZAN] =
	{
		.name = _("LegendarySixS"),
		.itemId = ITEM_CARD_LEGENDARY_SIX_SAMURAI_KIZAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEOTRON] =
	{
		.name = _("Leotron"),
		.itemId = ITEM_CARD_LEOTRON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LESSER_FIEND] =
	{
		.name = _("LesserFiend"),
		.itemId = ITEM_CARD_LESSER_FIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEVEL_LIMIT_AREA_B] =
	{
		.name = _("LevelLimitAre"),
		.itemId = ITEM_CARD_LEVEL_LIMIT_AREA_B,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEVIA_DRAGON_DAEDALUS] =
	{
		.name = _("LeviaDragonDa"),
		.itemId = ITEM_CARD_LEVIA_DRAGON_DAEDALUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LEVIAIR_THE_SEA_DRAGON] =
	{
		.name = _("LeviairtheSea"),
		.itemId = ITEM_CARD_LEVIAIR_THE_SEA_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIBIC_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("LibicMalebran"),
		.itemId = ITEM_CARD_LIBIC_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHT_AND_DARKNESS_DRAGON] =
	{
		.name = _("LightandDarkn"),
		.itemId = ITEM_CARD_LIGHT_AND_DARKNESS_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHT_OF_INTERVENTION] =
	{
		.name = _("LightofInterv"),
		.itemId = ITEM_CARD_LIGHT_OF_INTERVENTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHT_IMPRISONING_MIRROR] =
	{
		.name = _("LightImprison"),
		.itemId = ITEM_CARD_LIGHT_IMPRISONING_MIRROR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHTNING_STORM] =
	{
		.name = _("LightningStor"),
		.itemId = ITEM_CARD_LIGHTNING_STORM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHTNING_VORTEX] =
	{
		.name = _("LightningVort"),
		.itemId = ITEM_CARD_LIGHTNING_VORTEX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHTNING_DRAGON_RULER_OF_DRAFTS] =
	{
		.name = _("LightningDrag"),
		.itemId = ITEM_CARD_LIGHTNING_DRAGON_RULER_OF_DRAFTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIGHTPULSAR_DRAGON] =
	{
		.name = _("LightpulsarDr"),
		.itemId = ITEM_CARD_LIGHTPULSAR_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LIMITER_REMOVAL] =
	{
		.name = _("LimiterRemova"),
		.itemId = ITEM_CARD_LIMITER_REMOVAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LINK_SPIDER] =
	{
		.name = _("LinkSpider"),
		.itemId = ITEM_CARD_LINK_SPIDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LINKURIBOH] =
	{
		.name = _("Linkuriboh"),
		.itemId = ITEM_CARD_LINKURIBOH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LONEFIRE_BLOSSOM] =
	{
		.name = _("LonefireBloss"),
		.itemId = ITEM_CARD_LONEFIRE_BLOSSOM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LORD_OF_D_] =
	{
		.name = _("LordofD"),
		.itemId = ITEM_CARD_LORD_OF_D_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUBELLION_THE_SEARING_DRAGON] =
	{
		.name = _("LubelliontheS"),
		.itemId = ITEM_CARD_LUBELLION_THE_SEARING_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUCENT_NETHERLORD_OF_DARK_WORLD] =
	{
		.name = _("LucentNetherl"),
		.itemId = ITEM_CARD_LUCENT_NETHERLORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUCIUS_THE_SHADOW_VASSAL] =
	{
		.name = _("LuciustheShad"),
		.itemId = ITEM_CARD_LUCIUS_THE_SHADOW_VASSAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LULLABY_OF_OBEDIENCE] =
	{
		.name = _("LullabyofObed"),
		.itemId = ITEM_CARD_LULLABY_OF_OBEDIENCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUMINA_LIGHTSWORN_SUMMONER] =
	{
		.name = _("LuminaLightsw"),
		.itemId = ITEM_CARD_LUMINA_LIGHTSWORN_SUMMONER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUNALIGHT_BLACK_SHEEP] =
	{
		.name = _("LunalightBlac"),
		.itemId = ITEM_CARD_LUNALIGHT_BLACK_SHEEP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUSTER_DRAGON] =
	{
		.name = _("LusterDragon"),
		.itemId = ITEM_CARD_LUSTER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LUSTER_PENDULUM_THE_DRACOSLAYER] =
	{
		.name = _("LusterPendulu"),
		.itemId = ITEM_CARD_LUSTER_PENDULUM_THE_DRACOSLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_LYLA_LIGHTSWORN_SORCERESS] =
	{
		.name = _("LylaLightswor"),
		.itemId = ITEM_CARD_LYLA_LIGHTSWORN_SORCERESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_M_X_SABER_INVOKER] =
	{
		.name = _("MXSaberInvoke"),
		.itemId = ITEM_CARD_M_X_SABER_INVOKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MACHINE_DUPLICATION] =
	{
		.name = _("MachineDuplic"),
		.itemId = ITEM_CARD_MACHINE_DUPLICATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MACRO_COSMOS] =
	{
		.name = _("MacroCosmos"),
		.itemId = ITEM_CARD_MACRO_COSMOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAD_ARCHFIEND] =
	{
		.name = _("MadArchfiend"),
		.itemId = ITEM_CARD_MAD_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAD_DOG_OF_DARKNESS] =
	{
		.name = _("MadDogofDarkn"),
		.itemId = ITEM_CARD_MAD_DOG_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAESTROKE_THE_SYMPHONY_DJINN] =
	{
		.name = _("MaestroketheS"),
		.itemId = ITEM_CARD_MAESTROKE_THE_SYMPHONY_DJINN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGE_POWER] =
	{
		.name = _("MagePower"),
		.itemId = ITEM_CARD_MAGE_POWER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGIC_CYLINDER] =
	{
		.name = _("MagicCylinder"),
		.itemId = ITEM_CARD_MAGIC_CYLINDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGIC_DEFLECTOR] =
	{
		.name = _("MagicDeflecto"),
		.itemId = ITEM_CARD_MAGIC_DEFLECTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGIC_JAMMER] =
	{
		.name = _("MagicJammer"),
		.itemId = ITEM_CARD_MAGIC_JAMMER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICAL_ABDUCTOR] =
	{
		.name = _("MagicalAbduct"),
		.itemId = ITEM_CARD_MAGICAL_ABDUCTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICAL_ANDROID] =
	{
		.name = _("MagicalAndroi"),
		.itemId = ITEM_CARD_MAGICAL_ANDROID,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICAL_DIMENSION] =
	{
		.name = _("MagicalDimens"),
		.itemId = ITEM_CARD_MAGICAL_DIMENSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICAL_MERCHANT] =
	{
		.name = _("MagicalMercha"),
		.itemId = ITEM_CARD_MAGICAL_MERCHANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICAL_SCIENTIST] =
	{
		.name = _("MagicalScient"),
		.itemId = ITEM_CARD_MAGICAL_SCIENTIST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_OF_DARK_ILLUSION] =
	{
		.name = _("MagicianofDar"),
		.itemId = ITEM_CARD_MAGICIAN_OF_DARK_ILLUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_OF_FAITH] =
	{
		.name = _("MagicianofFai"),
		.itemId = ITEM_CARD_MAGICIAN_OF_FAITH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_S_CIRCLE] =
	{
		.name = _("MagiciansCirc"),
		.itemId = ITEM_CARD_MAGICIAN_S_CIRCLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_S_ROBE] =
	{
		.name = _("MagiciansRobe"),
		.itemId = ITEM_CARD_MAGICIAN_S_ROBE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_S_ROD] =
	{
		.name = _("MagiciansRod"),
		.itemId = ITEM_CARD_MAGICIAN_S_ROD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIAN_S_VALKYRIA] =
	{
		.name = _("MagiciansValk"),
		.itemId = ITEM_CARD_MAGICIAN_S_VALKYRIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGICIANS_SOULS] =
	{
		.name = _("MagiciansSoul"),
		.itemId = ITEM_CARD_MAGICIANS_SOULS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAGIKURIBOH] =
	{
		.name = _("Magikuriboh"),
		.itemId = ITEM_CARD_MAGIKURIBOH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAIDEN_OF_THE_AQUA] =
	{
		.name = _("MaidenoftheAq"),
		.itemId = ITEM_CARD_MAIDEN_OF_THE_AQUA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAIDEN_OF_WHITE] =
	{
		.name = _("MaidenofWhite"),
		.itemId = ITEM_CARD_MAIDEN_OF_WHITE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAIDEN_WITH_EYES_OF_BLUE] =
	{
		.name = _("MaidenwithEye"),
		.itemId = ITEM_CARD_MAIDEN_WITH_EYES_OF_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAJESPECTER_RACCOON_BUNBUKU] =
	{
		.name = _("MajespecterRa"),
		.itemId = ITEM_CARD_MAJESPECTER_RACCOON_BUNBUKU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAJESPECTER_UNICORN_KIRIN] =
	{
		.name = _("MajespecterUn"),
		.itemId = ITEM_CARD_MAJESPECTER_UNICORN_KIRIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAJESTER_PALADIN_THE_ASCENDING_DRACOSLAYER] =
	{
		.name = _("MajesterPalad"),
		.itemId = ITEM_CARD_MAJESTER_PALADIN_THE_ASCENDING_DRACOSLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAJESTY_S_FIEND] =
	{
		.name = _("MajestysFiend"),
		.itemId = ITEM_CARD_MAJESTY_S_FIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAKYURA_THE_DESTRUCTOR] =
	{
		.name = _("MakyuratheDes"),
		.itemId = ITEM_CARD_MAKYURA_THE_DESTRUCTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALEFIC_BLUE_EYES_WHITE_DRAGON] =
	{
		.name = _("MaleficBlueEy"),
		.itemId = ITEM_CARD_MALEFIC_BLUE_EYES_WHITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALEFIC_CYBER_END_DRAGON] =
	{
		.name = _("MaleficCyberE"),
		.itemId = ITEM_CARD_MALEFIC_CYBER_END_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALEFIC_RED_EYES_BLACK_DRAGON] =
	{
		.name = _("MaleficRedEye"),
		.itemId = ITEM_CARD_MALEFIC_RED_EYES_BLACK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALEVOLENT_CATASTROPHE] =
	{
		.name = _("MalevolentCat"),
		.itemId = ITEM_CARD_MALEVOLENT_CATASTROPHE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALISS_IN_UNDERGROUND] =
	{
		.name = _("MalissinUnder"),
		.itemId = ITEM_CARD_MALISS_IN_UNDERGROUND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALISS_P_DORMOUSE] =
	{
		.name = _("MalissPDormou"),
		.itemId = ITEM_CARD_MALISS_P_DORMOUSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MALISS_P_WHITE_RABBIT] =
	{
		.name = _("MalissPWhiteR"),
		.itemId = ITEM_CARD_MALISS_P_WHITE_RABBIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAN_EATER_BUG] =
	{
		.name = _("ManEaterBug"),
		.itemId = ITEM_CARD_MAN_EATER_BUG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MANJU_OF_THE_TEN_THOUSAND_HANDS] =
	{
		.name = _("ManjuoftheTen"),
		.itemId = ITEM_CARD_MANJU_OF_THE_TEN_THOUSAND_HANDS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MANTICORE_OF_DARKNESS] =
	{
		.name = _("ManticoreofDa"),
		.itemId = ITEM_CARD_MANTICORE_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MARAUDING_CAPTAIN] =
	{
		.name = _("MaraudingCapt"),
		.itemId = ITEM_CARD_MARAUDING_CAPTAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASK_OF_DARKNESS] =
	{
		.name = _("MaskofDarknes"),
		.itemId = ITEM_CARD_MASK_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASK_OF_RESTRICT] =
	{
		.name = _("MaskofRestric"),
		.itemId = ITEM_CARD_MASK_OF_RESTRICT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASKED_DRAGON] =
	{
		.name = _("MaskedDragon"),
		.itemId = ITEM_CARD_MASKED_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASKED_NINJA_EBISU] =
	{
		.name = _("MaskedNinjaEb"),
		.itemId = ITEM_CARD_MASKED_NINJA_EBISU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASKED_SORCERER] =
	{
		.name = _("MaskedSorcere"),
		.itemId = ITEM_CARD_MASKED_SORCERER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_HYPERION] =
	{
		.name = _("MasterHyperio"),
		.itemId = ITEM_CARD_MASTER_HYPERION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_OF_CHAOS] =
	{
		.name = _("MasterofChaos"),
		.itemId = ITEM_CARD_MASTER_OF_CHAOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_OF_OZ] =
	{
		.name = _("MasterofOz"),
		.itemId = ITEM_CARD_MASTER_OF_OZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_PEACE_THE_TRUE_DRACOSLAYING_KING] =
	{
		.name = _("MasterPeaceth"),
		.itemId = ITEM_CARD_MASTER_PEACE_THE_TRUE_DRACOSLAYING_KING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_PENDULUM_THE_DRACOSLAYER] =
	{
		.name = _("MasterPendulu"),
		.itemId = ITEM_CARD_MASTER_PENDULUM_THE_DRACOSLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MASTER_WITH_EYES_OF_BLUE] =
	{
		.name = _("MasterwithEye"),
		.itemId = ITEM_CARD_MASTER_WITH_EYES_OF_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MATAZA_THE_ZAPPER] =
	{
		.name = _("MatazatheZapp"),
		.itemId = ITEM_CARD_MATAZA_THE_ZAPPER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MATHEMATICIAN] =
	{
		.name = _("Mathematician"),
		.itemId = ITEM_CARD_MATHEMATICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MATRIARCH_OF_NEPHTHYS] =
	{
		.name = _("MatriarchofNe"),
		.itemId = ITEM_CARD_MATRIARCH_OF_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MAXX_C_] =
	{
		.name = _("MaxxC"),
		.itemId = ITEM_CARD_MAXX_C_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MECHA_PHANTOM_BEAST_DRACOSSACK] =
	{
		.name = _("MechaPhantomB"),
		.itemId = ITEM_CARD_MECHA_PHANTOM_BEAST_DRACOSSACK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MECHANICALCHASER] =
	{
		.name = _("Mechanicalcha"),
		.itemId = ITEM_CARD_MECHANICALCHASER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEGALOSMASHER_X] =
	{
		.name = _("Megalosmasher"),
		.itemId = ITEM_CARD_MEGALOSMASHER_X,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEGAMORPH] =
	{
		.name = _("Megamorph"),
		.itemId = ITEM_CARD_MEGAMORPH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEIZEN_THE_BATTLE_NINJA] =
	{
		.name = _("MeizentheBatt"),
		.itemId = ITEM_CARD_MEIZEN_THE_BATTLE_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEKK_KNIGHT_AVRAM] =
	{
		.name = _("MekkKnightAvr"),
		.itemId = ITEM_CARD_MEKK_KNIGHT_AVRAM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEREOLOGIC_AGGREGATOR] =
	{
		.name = _("MereologicAgg"),
		.itemId = ITEM_CARD_MEREOLOGIC_AGGREGATOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAID_KNIGHT] =
	{
		.name = _("MermaidKnight"),
		.itemId = ITEM_CARD_MERMAID_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSGAIOS] =
	{
		.name = _("MermailAbyssg"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSGAIOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSGUNDE] =
	{
		.name = _("MermailAbyssg"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSGUNDE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSLINDE] =
	{
		.name = _("MermailAbyssl"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSLINDE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSMEGALO] =
	{
		.name = _("MermailAbyssm"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSMEGALO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSPIKE] =
	{
		.name = _("MermailAbyssp"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSPIKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSTEUS] =
	{
		.name = _("MermailAbysst"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSTEUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSTRITE] =
	{
		.name = _("MermailAbysst"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSTRITE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MERMAIL_ABYSSTURGE] =
	{
		.name = _("MermailAbysst"),
		.itemId = ITEM_CARD_MERMAIL_ABYSSTURGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MESSENGER_OF_PEACE] =
	{
		.name = _("MessengerofPe"),
		.itemId = ITEM_CARD_MESSENGER_OF_PEACE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METAL_REFLECT_SLIME] =
	{
		.name = _("MetalReflectS"),
		.itemId = ITEM_CARD_METAL_REFLECT_SLIME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALFLAME_SWORDSMAN] =
	{
		.name = _("MetalflameSwo"),
		.itemId = ITEM_CARD_METALFLAME_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALFOES_GOLDRIVER] =
	{
		.name = _("MetalfoesGold"),
		.itemId = ITEM_CARD_METALFOES_GOLDRIVER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALFOES_SILVERD] =
	{
		.name = _("MetalfoesSilv"),
		.itemId = ITEM_CARD_METALFOES_SILVERD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALFOES_STEELEN] =
	{
		.name = _("MetalfoesStee"),
		.itemId = ITEM_CARD_METALFOES_STEELEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALFOES_VOLFLAME] =
	{
		.name = _("MetalfoesVolf"),
		.itemId = ITEM_CARD_METALFOES_VOLFLAME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METALTRONUS] =
	{
		.name = _("Metaltronus"),
		.itemId = ITEM_CARD_METALTRONUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METAMORPHOSIS] =
	{
		.name = _("Metamorphosis"),
		.itemId = ITEM_CARD_METAMORPHOSIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METEOR_BLACK_COMET_DRAGON] =
	{
		.name = _("MeteorBlackCo"),
		.itemId = ITEM_CARD_METEOR_BLACK_COMET_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_METEOR_DRAGON] =
	{
		.name = _("MeteorDragon"),
		.itemId = ITEM_CARD_METEOR_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MEZUKI] =
	{
		.name = _("Mezuki"),
		.itemId = ITEM_CARD_MEZUKI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MILUS_RADIANT] =
	{
		.name = _("MilusRadiant"),
		.itemId = ITEM_CARD_MILUS_RADIANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MINAR] =
	{
		.name = _("Minar"),
		.itemId = ITEM_CARD_MINAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIND_CONTROL] =
	{
		.name = _("MindControl"),
		.itemId = ITEM_CARD_MIND_CONTROL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIND_CRUSH] =
	{
		.name = _("MindCrush"),
		.itemId = ITEM_CARD_MIND_CRUSH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIND_PROTECTOR] =
	{
		.name = _("MindProtector"),
		.itemId = ITEM_CARD_MIND_PROTECTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MINE_GOLEM] =
	{
		.name = _("MineGolem"),
		.itemId = ITEM_CARD_MINE_GOLEM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRACLE_RESTORING] =
	{
		.name = _("MiracleRestor"),
		.itemId = ITEM_CARD_MIRACLE_RESTORING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRAGE_DRAGON] =
	{
		.name = _("MirageDragon"),
		.itemId = ITEM_CARD_MIRAGE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRAGE_KNIGHT] =
	{
		.name = _("MirageKnight"),
		.itemId = ITEM_CARD_MIRAGE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRAGE_OF_NIGHTMARE] =
	{
		.name = _("MirageofNight"),
		.itemId = ITEM_CARD_MIRAGE_OF_NIGHTMARE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRAGE_SWORDSMAN] =
	{
		.name = _("MirageSwordsm"),
		.itemId = ITEM_CARD_MIRAGE_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRROR_FORCE] =
	{
		.name = _("MirrorForce"),
		.itemId = ITEM_CARD_MIRROR_FORCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIRROR_OF_OATHS] =
	{
		.name = _("MirrorofOaths"),
		.itemId = ITEM_CARD_MIRROR_OF_OATHS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MISSUS_RADIANT] =
	{
		.name = _("MissusRadiant"),
		.itemId = ITEM_CARD_MISSUS_RADIANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MIST_WURM] =
	{
		.name = _("MistWurm"),
		.itemId = ITEM_CARD_MIST_WURM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MISTAKE] =
	{
		.name = _("Mistake"),
		.itemId = ITEM_CARD_MISTAKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MITSU_THE_INSECT_NINJA] =
	{
		.name = _("MitsutheInsec"),
		.itemId = ITEM_CARD_MITSU_THE_INSECT_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MOAI_INTERCEPTOR_CANNONS] =
	{
		.name = _("MoaiIntercept"),
		.itemId = ITEM_CARD_MOAI_INTERCEPTOR_CANNONS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MOBIUS_THE_FROST_MONARCH] =
	{
		.name = _("MobiustheFros"),
		.itemId = ITEM_CARD_MOBIUS_THE_FROST_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MOBIUS_THE_MEGA_MONARCH] =
	{
		.name = _("MobiustheMega"),
		.itemId = ITEM_CARD_MOBIUS_THE_MEGA_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MONK_OF_THE_TENYI] =
	{
		.name = _("MonkoftheTeny"),
		.itemId = ITEM_CARD_MONK_OF_THE_TENYI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MONSTER_GATE] =
	{
		.name = _("MonsterGate"),
		.itemId = ITEM_CARD_MONSTER_GATE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MONSTER_REBORN] =
	{
		.name = _("MonsterReborn"),
		.itemId = ITEM_CARD_MONSTER_REBORN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MONSTER_REINCARNATION] =
	{
		.name = _("MonsterReinca"),
		.itemId = ITEM_CARD_MONSTER_REINCARNATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MOON_OF_THE_CLOSED_HEAVEN] =
	{
		.name = _("MoonoftheClos"),
		.itemId = ITEM_CARD_MOON_OF_THE_CLOSED_HEAVEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MORPHING_JAR] =
	{
		.name = _("MorphingJar"),
		.itemId = ITEM_CARD_MORPHING_JAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MORPHING_JAR_2] =
	{
		.name = _("MorphingJar2"),
		.itemId = ITEM_CARD_MORPHING_JAR_2,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MOTHER_GRIZZLY] =
	{
		.name = _("MotherGrizzly"),
		.itemId = ITEM_CARD_MOTHER_GRIZZLY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MUDORA_THE_SWORD_ORACLE] =
	{
		.name = _("MudoratheSwor"),
		.itemId = ITEM_CARD_MUDORA_THE_SWORD_ORACLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MUDRAGON_OF_THE_SWAMP] =
	{
		.name = _("Mudragonofthe"),
		.itemId = ITEM_CARD_MUDRAGON_OF_THE_SWAMP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MUKA_MUKA] =
	{
		.name = _("MukaMuka"),
		.itemId = ITEM_CARD_MUKA_MUKA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MULCHARMY_FUWALOS] =
	{
		.name = _("MulcharmyFuwa"),
		.itemId = ITEM_CARD_MULCHARMY_FUWALOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MULCHARMY_MEOWLS] =
	{
		.name = _("MulcharmyMeow"),
		.itemId = ITEM_CARD_MULCHARMY_MEOWLS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MULCHARMY_PURULIA] =
	{
		.name = _("MulcharmyPuru"),
		.itemId = ITEM_CARD_MULCHARMY_PURULIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MY_BODY_AS_A_SHIELD] =
	{
		.name = _("MyBodyasaShie"),
		.itemId = ITEM_CARD_MY_BODY_AS_A_SHIELD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTERY_SHELL_DRAGON] =
	{
		.name = _("MysteryShellD"),
		.itemId = ITEM_CARD_MYSTERY_SHELL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTIC_MINE] =
	{
		.name = _("MysticMine"),
		.itemId = ITEM_CARD_MYSTIC_MINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTIC_SWORDSMAN_LV2] =
	{
		.name = _("MysticSwordsm"),
		.itemId = ITEM_CARD_MYSTIC_SWORDSMAN_LV2,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTIC_SWORDSMAN_LV4] =
	{
		.name = _("MysticSwordsm"),
		.itemId = ITEM_CARD_MYSTIC_SWORDSMAN_LV4,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTIC_TOMATO] =
	{
		.name = _("MysticTomato"),
		.itemId = ITEM_CARD_MYSTIC_TOMATO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTICAL_ELF] =
	{
		.name = _("MysticalElf"),
		.itemId = ITEM_CARD_MYSTICAL_ELF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTICAL_ELF_WHITE_LIGHTNING] =
	{
		.name = _("MysticalElfWh"),
		.itemId = ITEM_CARD_MYSTICAL_ELF_WHITE_LIGHTNING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTICAL_SPACE_TYPHOON] =
	{
		.name = _("MysticalSpace"),
		.itemId = ITEM_CARD_MYSTICAL_SPACE_TYPHOON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_MYSTIK_WOK] =
	{
		.name = _("MystikWok"),
		.itemId = ITEM_CARD_MYSTIK_WOK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NAELSHADDOLL_ARIEL] =
	{
		.name = _("NaelshaddollA"),
		.itemId = ITEM_CARD_NAELSHADDOLL_ARIEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NECRO_GARDNA] =
	{
		.name = _("NecroGardna"),
		.itemId = ITEM_CARD_NECRO_GARDNA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NECROVALLEY] =
	{
		.name = _("Necrovalley"),
		.itemId = ITEM_CARD_NECROVALLEY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEEDLE_CEILING] =
	{
		.name = _("NeedleCeiling"),
		.itemId = ITEM_CARD_NEEDLE_CEILING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKO_MANE_KING] =
	{
		.name = _("NekoManeKing"),
		.itemId = ITEM_CARD_NEKO_MANE_KING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_CYCLE] =
	{
		.name = _("NekrozCycle"),
		.itemId = ITEM_CARD_NEKROZ_CYCLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_KALEIDOSCOPE] =
	{
		.name = _("NekrozKaleido"),
		.itemId = ITEM_CARD_NEKROZ_KALEIDOSCOPE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_MIRROR] =
	{
		.name = _("NekrozMirror"),
		.itemId = ITEM_CARD_NEKROZ_MIRROR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_OF_BRIONAC] =
	{
		.name = _("NekrozofBrion"),
		.itemId = ITEM_CARD_NEKROZ_OF_BRIONAC,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_OF_CLAUSOLAS] =
	{
		.name = _("NekrozofClaus"),
		.itemId = ITEM_CARD_NEKROZ_OF_CLAUSOLAS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_OF_UNICORE] =
	{
		.name = _("NekrozofUnico"),
		.itemId = ITEM_CARD_NEKROZ_OF_UNICORE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEKROZ_OF_VALKYRUS] =
	{
		.name = _("NekrozofValky"),
		.itemId = ITEM_CARD_NEKROZ_OF_VALKYRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEO_BUG] =
	{
		.name = _("NeoBug"),
		.itemId = ITEM_CARD_NEO_BUG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEO_KAISER_SEA_HORSE] =
	{
		.name = _("NeoKaiserSeaH"),
		.itemId = ITEM_CARD_NEO_KAISER_SEA_HORSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEO_THE_MAGIC_SWORDSMAN] =
	{
		.name = _("NeotheMagicSw"),
		.itemId = ITEM_CARD_NEO_THE_MAGIC_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEO_SPACIAN_DARK_PANTHER] =
	{
		.name = _("NeoSpacianDar"),
		.itemId = ITEM_CARD_NEO_SPACIAN_DARK_PANTHER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NEWDORIA] =
	{
		.name = _("Newdoria"),
		.itemId = ITEM_CARD_NEWDORIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIBIRU_THE_PRIMAL_BEING] =
	{
		.name = _("NibiruthePrim"),
		.itemId = ITEM_CARD_NIBIRU_THE_PRIMAL_BEING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIGHT_ASSAILANT] =
	{
		.name = _("NightAssailan"),
		.itemId = ITEM_CARD_NIGHT_ASSAILANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIGHT_BEAM] =
	{
		.name = _("NightBeam"),
		.itemId = ITEM_CARD_NIGHT_BEAM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIGHTMARE_MAGICIAN] =
	{
		.name = _("NightmareMagi"),
		.itemId = ITEM_CARD_NIGHTMARE_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIGHTMARE_WHEEL] =
	{
		.name = _("NightmareWhee"),
		.itemId = ITEM_CARD_NIGHTMARE_WHEEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIGHTMARE_S_STEELCAGE] =
	{
		.name = _("NightmaresSte"),
		.itemId = ITEM_CARD_NIGHTMARE_S_STEELCAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIMBLE_ANGLER] =
	{
		.name = _("NimbleAngler"),
		.itemId = ITEM_CARD_NIMBLE_ANGLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIMBLE_BEAVER] =
	{
		.name = _("NimbleBeaver"),
		.itemId = ITEM_CARD_NIMBLE_BEAVER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIMBLE_MOMONGA] =
	{
		.name = _("NimbleMomonga"),
		.itemId = ITEM_CARD_NIMBLE_MOMONGA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NIN_KEN_DOG] =
	{
		.name = _("NinKenDog"),
		.itemId = ITEM_CARD_NIN_KEN_DOG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NINJA_GRANDMASTER_HANZO] =
	{
		.name = _("NinjaGrandmas"),
		.itemId = ITEM_CARD_NINJA_GRANDMASTER_HANZO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NINJA_GRANDMASTER_SASUKE] =
	{
		.name = _("NinjaGrandmas"),
		.itemId = ITEM_CARD_NINJA_GRANDMASTER_SASUKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NOBLEMAN_OF_CROSSOUT] =
	{
		.name = _("NoblemanofCro"),
		.itemId = ITEM_CARD_NOBLEMAN_OF_CROSSOUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NOBLEMAN_OF_EXTERMINATION] =
	{
		.name = _("NoblemanofExt"),
		.itemId = ITEM_CARD_NOBLEMAN_OF_EXTERMINATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_101_SILENT_HONOR_ARK] =
	{
		.name = _("Number101Sile"),
		.itemId = ITEM_CARD_NUMBER_101_SILENT_HONOR_ARK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_11_BIG_EYE] =
	{
		.name = _("Number11BigEy"),
		.itemId = ITEM_CARD_NUMBER_11_BIG_EYE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_17_LEVIATHAN_DRAGON] =
	{
		.name = _("Number17Levia"),
		.itemId = ITEM_CARD_NUMBER_17_LEVIATHAN_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_30_ACID_GOLEM_OF_DESTRUCTION] =
	{
		.name = _("Number30AcidG"),
		.itemId = ITEM_CARD_NUMBER_30_ACID_GOLEM_OF_DESTRUCTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_39_UTOPIA] =
	{
		.name = _("Number39Utopi"),
		.itemId = ITEM_CARD_NUMBER_39_UTOPIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_41_BAGOOSKA_THE_TERRIBLY_TIRED_TAPIR] =
	{
		.name = _("Number41Bagoo"),
		.itemId = ITEM_CARD_NUMBER_41_BAGOOSKA_THE_TERRIBLY_TIRED_TAPIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_NUMBER_66_MASTER_KEY_BEETLE] =
	{
		.name = _("Number66Maste"),
		.itemId = ITEM_CARD_NUMBER_66_MASTER_KEY_BEETLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OFFERINGS_TO_THE_DOOMED] =
	{
		.name = _("Offeringstoth"),
		.itemId = ITEM_CARD_OFFERINGS_TO_THE_DOOMED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OJAMA_KING] =
	{
		.name = _("OjamaKing"),
		.itemId = ITEM_CARD_OJAMA_KING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OJAMA_TRIO] =
	{
		.name = _("OjamaTrio"),
		.itemId = ITEM_CARD_OJAMA_TRIO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OOKAZI] =
	{
		.name = _("Ookazi"),
		.itemId = ITEM_CARD_OOKAZI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OPPRESSED_PEOPLE] =
	{
		.name = _("OppressedPeop"),
		.itemId = ITEM_CARD_OPPRESSED_PEOPLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OPTICLOPS] =
	{
		.name = _("Opticlops"),
		.itemId = ITEM_CARD_OPTICLOPS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ORCUST_CYMBAL_SKELETON] =
	{
		.name = _("OrcustCymbalS"),
		.itemId = ITEM_CARD_ORCUST_CYMBAL_SKELETON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ORCUST_HARP_HORROR] =
	{
		.name = _("OrcustHarpHor"),
		.itemId = ITEM_CARD_ORCUST_HARP_HORROR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ORCUST_KNIGHTMARE] =
	{
		.name = _("OrcustKnightm"),
		.itemId = ITEM_CARD_ORCUST_KNIGHTMARE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ORCUSTRATED_RETURN] =
	{
		.name = _("OrcustratedRe"),
		.itemId = ITEM_CARD_ORCUSTRATED_RETURN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ORIGINAL_SINFUL_SPOILS_SNAKE_EYE] =
	{
		.name = _("OriginalSinfu"),
		.itemId = ITEM_CARD_ORIGINAL_SINFUL_SPOILS_SNAKE_EYE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_OVERLOAD_FUSION] =
	{
		.name = _("OverloadFusio"),
		.itemId = ITEM_CARD_OVERLOAD_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PAINFUL_CHOICE] =
	{
		.name = _("PainfulChoice"),
		.itemId = ITEM_CARD_PAINFUL_CHOICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PAINFUL_DECISION] =
	{
		.name = _("PainfulDecisi"),
		.itemId = ITEM_CARD_PAINFUL_DECISION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALADIN_OF_WHITE_DRAGON] =
	{
		.name = _("PaladinofWhit"),
		.itemId = ITEM_CARD_PALADIN_OF_WHITE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_ANOMALOCARIS] =
	{
		.name = _("PaleozoicAnom"),
		.itemId = ITEM_CARD_PALEOZOIC_ANOMALOCARIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_CANADIA] =
	{
		.name = _("PaleozoicCana"),
		.itemId = ITEM_CARD_PALEOZOIC_CANADIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_DINOMISCHUS] =
	{
		.name = _("PaleozoicDino"),
		.itemId = ITEM_CARD_PALEOZOIC_DINOMISCHUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_MARRELLA] =
	{
		.name = _("PaleozoicMarr"),
		.itemId = ITEM_CARD_PALEOZOIC_MARRELLA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_OLENOIDES] =
	{
		.name = _("PaleozoicOlen"),
		.itemId = ITEM_CARD_PALEOZOIC_OLENOIDES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALEOZOIC_OPABINIA] =
	{
		.name = _("PaleozoicOpab"),
		.itemId = ITEM_CARD_PALEOZOIC_OPABINIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PALLADIUM_ORACLE_MAHAD] =
	{
		.name = _("PalladiumOrac"),
		.itemId = ITEM_CARD_PALLADIUM_ORACLE_MAHAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PANTHEISM_OF_THE_MONARCHS] =
	{
		.name = _("Pantheismofth"),
		.itemId = ITEM_CARD_PANTHEISM_OF_THE_MONARCHS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PARL_HERMIT_OF_DARK_WORLD] =
	{
		.name = _("ParlHermitofD"),
		.itemId = ITEM_CARD_PARL_HERMIT_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PENGUIN_KNIGHT] =
	{
		.name = _("PenguinKnight"),
		.itemId = ITEM_CARD_PENGUIN_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PENGUIN_NINJA] =
	{
		.name = _("PenguinNinja"),
		.itemId = ITEM_CARD_PENGUIN_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_DAMAGE_JUGGLER] =
	{
		.name = _("PerformageDam"),
		.itemId = ITEM_CARD_PERFORMAGE_DAMAGE_JUGGLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_HAT_TRICKER] =
	{
		.name = _("PerformageHat"),
		.itemId = ITEM_CARD_PERFORMAGE_HAT_TRICKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_MIRROR_CONDUCTOR] =
	{
		.name = _("PerformageMir"),
		.itemId = ITEM_CARD_PERFORMAGE_MIRROR_CONDUCTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_PLUSHFIRE] =
	{
		.name = _("PerformagePlu"),
		.itemId = ITEM_CARD_PERFORMAGE_PLUSHFIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_TRAPEZE_MAGICIAN] =
	{
		.name = _("PerformageTra"),
		.itemId = ITEM_CARD_PERFORMAGE_TRAPEZE_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAGE_TRICK_CLOWN] =
	{
		.name = _("PerformageTri"),
		.itemId = ITEM_CARD_PERFORMAGE_TRICK_CLOWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_GUITARTLE] =
	{
		.name = _("PerformapalGu"),
		.itemId = ITEM_CARD_PERFORMAPAL_GUITARTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_LIZARDRAW] =
	{
		.name = _("PerformapalLi"),
		.itemId = ITEM_CARD_PERFORMAPAL_LIZARDRAW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_MONKEYBOARD] =
	{
		.name = _("PerformapalMo"),
		.itemId = ITEM_CARD_PERFORMAPAL_MONKEYBOARD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_PENDULUM_SORCERER] =
	{
		.name = _("PerformapalPe"),
		.itemId = ITEM_CARD_PERFORMAPAL_PENDULUM_SORCERER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_SILVER_CLAW] =
	{
		.name = _("PerformapalSi"),
		.itemId = ITEM_CARD_PERFORMAPAL_SILVER_CLAW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PERFORMAPAL_SKULLCROBAT_JOKER] =
	{
		.name = _("PerformapalSk"),
		.itemId = ITEM_CARD_PERFORMAPAL_SKULLCROBAT_JOKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PHANTOM_GRYPHON] =
	{
		.name = _("PhantomGrypho"),
		.itemId = ITEM_CARD_PHANTOM_GRYPHON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PHANTOM_KNIGHTS_FOG_BLADE] =
	{
		.name = _("PhantomKnight"),
		.itemId = ITEM_CARD_PHANTOM_KNIGHTS_FOG_BLADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PHOENIX_WING_WIND_BLAST] =
	{
		.name = _("PhoenixWingWi"),
		.itemId = ITEM_CARD_PHOENIX_WING_WIND_BLAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PIKERU_S_CIRCLE_OF_ENCHANTMENT] =
	{
		.name = _("PikerusCircle"),
		.itemId = ITEM_CARD_PIKERU_S_CIRCLE_OF_ENCHANTMENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PINCH_HOPPER] =
	{
		.name = _("PinchHopper"),
		.itemId = ITEM_CARD_PINCH_HOPPER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PITCH_BLACK_POWER_STONE] =
	{
		.name = _("PitchBlackPow"),
		.itemId = ITEM_CARD_PITCH_BLACK_POWER_STONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PLAGUESPREADER_ZOMBIE] =
	{
		.name = _("Plaguespreade"),
		.itemId = ITEM_CARD_PLAGUESPREADER_ZOMBIE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POISON_OF_THE_OLD_MAN] =
	{
		.name = _("PoisonoftheOl"),
		.itemId = ITEM_CARD_POISON_OF_THE_OLD_MAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POLYMERIZATION] =
	{
		.name = _("Polymerizatio"),
		.itemId = ITEM_CARD_POLYMERIZATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_AVARICE] =
	{
		.name = _("PotofAvarice"),
		.itemId = ITEM_CARD_POT_OF_AVARICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_DESIRES] =
	{
		.name = _("PotofDesires"),
		.itemId = ITEM_CARD_POT_OF_DESIRES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_DUALITY] =
	{
		.name = _("PotofDuality"),
		.itemId = ITEM_CARD_POT_OF_DUALITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_GENEROSITY] =
	{
		.name = _("PotofGenerosi"),
		.itemId = ITEM_CARD_POT_OF_GENEROSITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_GREED] =
	{
		.name = _("PotofGreed"),
		.itemId = ITEM_CARD_POT_OF_GREED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_POT_OF_PROSPERITY] =
	{
		.name = _("PotofProsperi"),
		.itemId = ITEM_CARD_POT_OF_PROSPERITY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_DODO_DOODLE_DOO] =
	{
		.name = _("PrankKidsDodo"),
		.itemId = ITEM_CARD_PRANK_KIDS_DODO_DOODLE_DOO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_DROPSIES] =
	{
		.name = _("PrankKidsDrop"),
		.itemId = ITEM_CARD_PRANK_KIDS_DROPSIES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_FANSIES] =
	{
		.name = _("PrankKidsFans"),
		.itemId = ITEM_CARD_PRANK_KIDS_FANSIES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_LAMPSIES] =
	{
		.name = _("PrankKidsLamp"),
		.itemId = ITEM_CARD_PRANK_KIDS_LAMPSIES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_PLACE] =
	{
		.name = _("PrankKidsPlac"),
		.itemId = ITEM_CARD_PRANK_KIDS_PLACE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRANK_KIDS_ROCKSIES] =
	{
		.name = _("PrankKidsRock"),
		.itemId = ITEM_CARD_PRANK_KIDS_ROCKSIES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PREDAPLANT_DRAGOSTAPELIA] =
	{
		.name = _("PredaplantDra"),
		.itemId = ITEM_CARD_PREDAPLANT_DRAGOSTAPELIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PREDAPLANT_VERTE_ANACONDA] =
	{
		.name = _("PredaplantVer"),
		.itemId = ITEM_CARD_PREDAPLANT_VERTE_ANACONDA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PREMATURE_BURIAL] =
	{
		.name = _("PrematureBuri"),
		.itemId = ITEM_CARD_PREMATURE_BURIAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRESSURED_PLANET_WRAITSOTH] =
	{
		.name = _("PressuredPlan"),
		.itemId = ITEM_CARD_PRESSURED_PLANET_WRAITSOTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PREVENT_RAT] =
	{
		.name = _("PreventRat"),
		.itemId = ITEM_CARD_PREVENT_RAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRICKLE_FAIRY] =
	{
		.name = _("PrickleFairy"),
		.itemId = ITEM_CARD_PRICKLE_FAIRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRIESTESS_WITH_EYES_OF_BLUE] =
	{
		.name = _("Priestesswith"),
		.itemId = ITEM_CARD_PRIESTESS_WITH_EYES_OF_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRIMAL_DRAGON_THE_PRIMORDIAL] =
	{
		.name = _("PrimalDragont"),
		.itemId = ITEM_CARD_PRIMAL_DRAGON_THE_PRIMORDIAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRIMEVAL_PLANET_PERLEREINO] =
	{
		.name = _("PrimevalPlane"),
		.itemId = ITEM_CARD_PRIMEVAL_PLANET_PERLEREINO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PRINCESS_OF_TSURUGI] =
	{
		.name = _("PrincessofTsu"),
		.itemId = ITEM_CARD_PRINCESS_OF_TSURUGI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PROHIBITION] =
	{
		.name = _("Prohibition"),
		.itemId = ITEM_CARD_PROHIBITION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PROMETHEAN_PRINCESS_BESTOWER_OF_FLAMES] =
	{
		.name = _("PrometheanPri"),
		.itemId = ITEM_CARD_PROMETHEAN_PRINCESS_BESTOWER_OF_FLAMES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PROTECTOR_OF_THE_SANCTUARY] =
	{
		.name = _("Protectorofth"),
		.itemId = ITEM_CARD_PROTECTOR_OF_THE_SANCTUARY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PROTECTOR_WITH_EYES_OF_BLUE] =
	{
		.name = _("Protectorwith"),
		.itemId = ITEM_CARD_PROTECTOR_WITH_EYES_OF_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PSI_BLOCKER] =
	{
		.name = _("PsiBlocker"),
		.itemId = ITEM_CARD_PSI_BLOCKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PSY_FRAME_DRIVER] =
	{
		.name = _("PSYFrameDrive"),
		.itemId = ITEM_CARD_PSY_FRAME_DRIVER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PSY_FRAMEGEAR_GAMMA] =
	{
		.name = _("PSYFramegearG"),
		.itemId = ITEM_CARD_PSY_FRAMEGEAR_GAMMA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PULLING_THE_RUG] =
	{
		.name = _("PullingtheRug"),
		.itemId = ITEM_CARD_PULLING_THE_RUG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PUNISHED_EAGLE] =
	{
		.name = _("PunishedEagle"),
		.itemId = ITEM_CARD_PUNISHED_EAGLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PUPPET_PLANT] =
	{
		.name = _("PuppetPlant"),
		.itemId = ITEM_CARD_PUPPET_PLANT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_PYRAMID_TURTLE] =
	{
		.name = _("PyramidTurtle"),
		.itemId = ITEM_CARD_PYRAMID_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_QADSHADDOLL_KEIOS] =
	{
		.name = _("QadshaddollKe"),
		.itemId = ITEM_CARD_QADSHADDOLL_KEIOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_QLIPHORT_CARRIER] =
	{
		.name = _("QliphortCarri"),
		.itemId = ITEM_CARD_QLIPHORT_CARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_QLIPHORT_DISK] =
	{
		.name = _("QliphortDisk"),
		.itemId = ITEM_CARD_QLIPHORT_DISK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_QLIPHORT_HELIX] =
	{
		.name = _("QliphortHelix"),
		.itemId = ITEM_CARD_QLIPHORT_HELIX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_QLIPHORT_SCOUT] =
	{
		.name = _("QliphortScout"),
		.itemId = ITEM_CARD_QLIPHORT_SCOUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RAIGEKI] =
	{
		.name = _("Raigeki"),
		.itemId = ITEM_CARD_RAIGEKI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RAIGEKI_BREAK] =
	{
		.name = _("RaigekiBreak"),
		.itemId = ITEM_CARD_RAIGEKI_BREAK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RAIZA_THE_MEGA_MONARCH] =
	{
		.name = _("RaizatheMegaM"),
		.itemId = ITEM_CARD_RAIZA_THE_MEGA_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RAIZA_THE_STORM_MONARCH] =
	{
		.name = _("RaizatheStorm"),
		.itemId = ITEM_CARD_RAIZA_THE_STORM_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REACTAN_DRAGON_RULER_OF_PEBBLES] =
	{
		.name = _("ReactanDragon"),
		.itemId = ITEM_CARD_REACTAN_DRAGON_RULER_OF_PEBBLES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REAPER_ON_THE_NIGHTMARE] =
	{
		.name = _("ReaperontheNi"),
		.itemId = ITEM_CARD_REAPER_ON_THE_NIGHTMARE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REASONING] =
	{
		.name = _("Reasoning"),
		.itemId = ITEM_CARD_REASONING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REBORN_TENGU] =
	{
		.name = _("RebornTengu"),
		.itemId = ITEM_CARD_REBORN_TENGU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RECKLESS_GREED] =
	{
		.name = _("RecklessGreed"),
		.itemId = ITEM_CARD_RECKLESS_GREED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_DRAGON_ARCHFIEND] =
	{
		.name = _("RedDragonArch"),
		.itemId = ITEM_CARD_RED_DRAGON_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_DRAGON_NINJA] =
	{
		.name = _("RedDragonNinj"),
		.itemId = ITEM_CARD_RED_DRAGON_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_REBOOT] =
	{
		.name = _("RedReboot"),
		.itemId = ITEM_CARD_RED_REBOOT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_ALTERNATIVE_BLACK_DRAGON] =
	{
		.name = _("RedEyesAltern"),
		.itemId = ITEM_CARD_RED_EYES_ALTERNATIVE_BLACK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BABY_DRAGON] =
	{
		.name = _("RedEyesBabyDr"),
		.itemId = ITEM_CARD_RED_EYES_BABY_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BLACK_DRAGON] =
	{
		.name = _("RedEyesBlackD"),
		.itemId = ITEM_CARD_RED_EYES_BLACK_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BLACK_DRAGON_SWORD] =
	{
		.name = _("RedEyesBlackD"),
		.itemId = ITEM_CARD_RED_EYES_BLACK_DRAGON_SWORD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BLACK_FULLMETAL_DRAGON] =
	{
		.name = _("RedEyesBlackF"),
		.itemId = ITEM_CARD_RED_EYES_BLACK_FULLMETAL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BLACK_METAL_DRAGON] =
	{
		.name = _("RedEyesBlackM"),
		.itemId = ITEM_CARD_RED_EYES_BLACK_METAL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_BLACK_METEOR_DRAGON] =
	{
		.name = _("RedEyesBlackM"),
		.itemId = ITEM_CARD_RED_EYES_BLACK_METEOR_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_DARKNESS_METAL_DRAGON] =
	{
		.name = _("RedEyesDarkne"),
		.itemId = ITEM_CARD_RED_EYES_DARKNESS_METAL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_RETRO_DRAGON] =
	{
		.name = _("RedEyesRetroD"),
		.itemId = ITEM_CARD_RED_EYES_RETRO_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_SLASH_DRAGON] =
	{
		.name = _("RedEyesSlashD"),
		.itemId = ITEM_CARD_RED_EYES_SLASH_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_SOUL] =
	{
		.name = _("RedEyesSoul"),
		.itemId = ITEM_CARD_RED_EYES_SOUL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_TOON_DRAGON] =
	{
		.name = _("RedEyesToonDr"),
		.itemId = ITEM_CARD_RED_EYES_TOON_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_WYVERN] =
	{
		.name = _("RedEyesWyvern"),
		.itemId = ITEM_CARD_RED_EYES_WYVERN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RED_EYES_ZOMBIE_DRAGON] =
	{
		.name = _("RedEyesZombie"),
		.itemId = ITEM_CARD_RED_EYES_ZOMBIE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REDOX_DRAGON_RULER_OF_BOULDERS] =
	{
		.name = _("RedoxDragonRu"),
		.itemId = ITEM_CARD_REDOX_DRAGON_RULER_OF_BOULDERS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REESHADDOLL_WENDI] =
	{
		.name = _("ReeshaddollWe"),
		.itemId = ITEM_CARD_REESHADDOLL_WENDI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REFLECT_BOUNDER] =
	{
		.name = _("ReflectBounde"),
		.itemId = ITEM_CARD_REFLECT_BOUNDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REIGN_BEAUX_OVERKING_OF_DARK_WORLD] =
	{
		.name = _("ReignBeauxOve"),
		.itemId = ITEM_CARD_REIGN_BEAUX_OVERKING_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REIGN_BEAUX_OVERLORD_OF_DARK_WORLD] =
	{
		.name = _("ReignBeauxOve"),
		.itemId = ITEM_CARD_REIGN_BEAUX_OVERLORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REINFORCEMENT_OF_THE_ARMY] =
	{
		.name = _("Reinforcement"),
		.itemId = ITEM_CARD_REINFORCEMENT_OF_THE_ARMY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REINFORCEMENTS] =
	{
		.name = _("Reinforcement"),
		.itemId = ITEM_CARD_REINFORCEMENTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RELINKURIBOH] =
	{
		.name = _("Relinkuriboh"),
		.itemId = ITEM_CARD_RELINKURIBOH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RELINQUISHED] =
	{
		.name = _("Relinquished"),
		.itemId = ITEM_CARD_RELINQUISHED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RELINQUISHED_ANIMA] =
	{
		.name = _("RelinquishedA"),
		.itemId = ITEM_CARD_RELINQUISHED_ANIMA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RELOAD] =
	{
		.name = _("Reload"),
		.itemId = ITEM_CARD_RELOAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_REMOVE_TRAP] =
	{
		.name = _("RemoveTrap"),
		.itemId = ITEM_CARD_REMOVE_TRAP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RENGE_GATEKEEPER_OF_DARK_WORLD] =
	{
		.name = _("RengeGatekeep"),
		.itemId = ITEM_CARD_RENGE_GATEKEEPER_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RESCUE_CAT] =
	{
		.name = _("RescueCat"),
		.itemId = ITEM_CARD_RESCUE_CAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RESCUE_RABBIT] =
	{
		.name = _("RescueRabbit"),
		.itemId = ITEM_CARD_RESCUE_RABBIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RETALIATING_C_] =
	{
		.name = _("RetaliatingC"),
		.itemId = ITEM_CARD_RETALIATING_C_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RETURN_FROM_THE_DIFFERENT_DIMENSION] =
	{
		.name = _("Returnfromthe"),
		.itemId = ITEM_CARD_RETURN_FROM_THE_DIFFERENT_DIMENSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RIDER_OF_THE_STORM_WINDS] =
	{
		.name = _("RideroftheSto"),
		.itemId = ITEM_CARD_RIDER_OF_THE_STORM_WINDS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RIGHT_ARM_OF_THE_FORBIDDEN_ONE] =
	{
		.name = _("RightArmofthe"),
		.itemId = ITEM_CARD_RIGHT_ARM_OF_THE_FORBIDDEN_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RIGHT_LEG_OF_THE_FORBIDDEN_ONE] =
	{
		.name = _("RightLegofthe"),
		.itemId = ITEM_CARD_RIGHT_LEG_OF_THE_FORBIDDEN_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RING_OF_DESTRUCTION] =
	{
		.name = _("RingofDestruc"),
		.itemId = ITEM_CARD_RING_OF_DESTRUCTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RISING_AIR_CURRENT] =
	{
		.name = _("RisingAirCurr"),
		.itemId = ITEM_CARD_RISING_AIR_CURRENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RITE_OF_ARAMESIR] =
	{
		.name = _("RiteofAramesi"),
		.itemId = ITEM_CARD_RITE_OF_ARAMESIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RIVALRY_OF_WARLORDS] =
	{
		.name = _("RivalryofWarl"),
		.itemId = ITEM_CARD_RIVALRY_OF_WARLORDS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROARING_OCEAN_SNAKE] =
	{
		.name = _("RoaringOceanS"),
		.itemId = ITEM_CARD_ROARING_OCEAN_SNAKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROBBIN_GOBLIN] =
	{
		.name = _("RobbinGoblin"),
		.itemId = ITEM_CARD_ROBBIN_GOBLIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RONINTOADIN] =
	{
		.name = _("Ronintoadin"),
		.itemId = ITEM_CARD_RONINTOADIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROULETTE_BARREL] =
	{
		.name = _("RouletteBarre"),
		.itemId = ITEM_CARD_ROULETTE_BARREL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROYAL_DECREE] =
	{
		.name = _("RoyalDecree"),
		.itemId = ITEM_CARD_ROYAL_DECREE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROYAL_MAGICAL_LIBRARY] =
	{
		.name = _("RoyalMagicalL"),
		.itemId = ITEM_CARD_ROYAL_MAGICAL_LIBRARY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ROYAL_OPPRESSION] =
	{
		.name = _("RoyalOppressi"),
		.itemId = ITEM_CARD_ROYAL_OPPRESSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUBIC_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("RubicMalebran"),
		.itemId = ITEM_CARD_RUBIC_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUNICK_DESTRUCTION] =
	{
		.name = _("RunickDestruc"),
		.itemId = ITEM_CARD_RUNICK_DESTRUCTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUNICK_FLASHING_FIRE] =
	{
		.name = _("RunickFlashin"),
		.itemId = ITEM_CARD_RUNICK_FLASHING_FIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUNICK_FREEZING_CURSES] =
	{
		.name = _("RunickFreezin"),
		.itemId = ITEM_CARD_RUNICK_FREEZING_CURSES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUNICK_TIP] =
	{
		.name = _("RunickTip"),
		.itemId = ITEM_CARD_RUNICK_TIP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RUSH_RECKLESSLY] =
	{
		.name = _("RushRecklessl"),
		.itemId = ITEM_CARD_RUSH_RECKLESSLY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYKO_LIGHTSWORN_HUNTER] =
	{
		.name = _("RykoLightswor"),
		.itemId = ITEM_CARD_RYKO_LIGHTSWORN_HUNTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYU_KOKKI] =
	{
		.name = _("RyuKokki"),
		.itemId = ITEM_CARD_RYU_KOKKI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYU_SENSHI] =
	{
		.name = _("RyuSenshi"),
		.itemId = ITEM_CARD_RYU_SENSHI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYZEAL_CROSS] =
	{
		.name = _("RyzealCross"),
		.itemId = ITEM_CARD_RYZEAL_CROSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYZEAL_DETONATOR] =
	{
		.name = _("RyzealDetonat"),
		.itemId = ITEM_CARD_RYZEAL_DETONATOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_RYZEAL_DUO_DRIVE] =
	{
		.name = _("RyzealDuoDriv"),
		.itemId = ITEM_CARD_RYZEAL_DUO_DRIVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_S_P_LITTLE_KNIGHT] =
	{
		.name = _("SPLittleKnigh"),
		.itemId = ITEM_CARD_S_P_LITTLE_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SABER_BEETLE] =
	{
		.name = _("SaberBeetle"),
		.itemId = ITEM_CARD_SABER_BEETLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SABERSAURUS] =
	{
		.name = _("Sabersaurus"),
		.itemId = ITEM_CARD_SABERSAURUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SACRED_CRANE] =
	{
		.name = _("SacredCrane"),
		.itemId = ITEM_CARD_SACRED_CRANE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SACRED_PHOENIX_OF_NEPHTHYS] =
	{
		.name = _("SacredPhoenix"),
		.itemId = ITEM_CARD_SACRED_PHOENIX_OF_NEPHTHYS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SACRED_SWORD_OF_SEVEN_STARS] =
	{
		.name = _("SacredSwordof"),
		.itemId = ITEM_CARD_SACRED_SWORD_OF_SEVEN_STARS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SAGE_WITH_EYES_OF_BLUE] =
	{
		.name = _("SagewithEyeso"),
		.itemId = ITEM_CARD_SAGE_WITH_EYES_OF_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SAKURETSU_ARMOR] =
	{
		.name = _("SakuretsuArmo"),
		.itemId = ITEM_CARD_SAKURETSU_ARMOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANDRA_THE_FLYING_FLAME_DRAGON] =
	{
		.name = _("Salamandrathe"),
		.itemId = ITEM_CARD_SALAMANDRA_THE_FLYING_FLAME_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANGREAT_BALELYNX] =
	{
		.name = _("SalamangreatB"),
		.itemId = ITEM_CARD_SALAMANGREAT_BALELYNX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANGREAT_FOXY] =
	{
		.name = _("SalamangreatF"),
		.itemId = ITEM_CARD_SALAMANGREAT_FOXY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANGREAT_RAGING_PHOENIX] =
	{
		.name = _("SalamangreatR"),
		.itemId = ITEM_CARD_SALAMANGREAT_RAGING_PHOENIX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANGREAT_SPINNY] =
	{
		.name = _("SalamangreatS"),
		.itemId = ITEM_CARD_SALAMANGREAT_SPINNY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALAMANGREAT_SUNLIGHT_WOLF] =
	{
		.name = _("SalamangreatS"),
		.itemId = ITEM_CARD_SALAMANGREAT_SUNLIGHT_WOLF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SALVAGE] =
	{
		.name = _("Salvage"),
		.itemId = ITEM_CARD_SALVAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SAND_MOTH] =
	{
		.name = _("SandMoth"),
		.itemId = ITEM_CARD_SAND_MOTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SANGAN] =
	{
		.name = _("Sangan"),
		.itemId = ITEM_CARD_SANGAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SANGEN_KAIMEN] =
	{
		.name = _("SangenKaimen"),
		.itemId = ITEM_CARD_SANGEN_KAIMEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SANGEN_SUMMONING] =
	{
		.name = _("SangenSummoni"),
		.itemId = ITEM_CARD_SANGEN_SUMMONING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SAQLIFICE] =
	{
		.name = _("Saqlifice"),
		.itemId = ITEM_CARD_SAQLIFICE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SASUKE_SAMURAI] =
	{
		.name = _("SasukeSamurai"),
		.itemId = ITEM_CARD_SASUKE_SAMURAI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SASUKE_SAMURAI_4] =
	{
		.name = _("SasukeSamurai"),
		.itemId = ITEM_CARD_SASUKE_SAMURAI_4,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SCAPEGOAT] =
	{
		.name = _("Scapegoat"),
		.itemId = ITEM_CARD_SCAPEGOAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SCARM_MALEBRANCHE_OF_THE_BURNING_ABYSS] =
	{
		.name = _("ScarmMalebran"),
		.itemId = ITEM_CARD_SCARM_MALEBRANCHE_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SCARR_SCOUT_OF_DARK_WORLD] =
	{
		.name = _("ScarrScoutofD"),
		.itemId = ITEM_CARD_SCARR_SCOUT_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SCRAP_DRAGON] =
	{
		.name = _("ScrapDragon"),
		.itemId = ITEM_CARD_SCRAP_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SEA_SERPENT_WARRIOR_OF_DARKNESS] =
	{
		.name = _("SeaSerpentWar"),
		.itemId = ITEM_CARD_SEA_SERPENT_WARRIOR_OF_DARKNESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SECOND_COIN_TOSS] =
	{
		.name = _("SecondCoinTos"),
		.itemId = ITEM_CARD_SECOND_COIN_TOSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SECRET_BARREL] =
	{
		.name = _("SecretBarrel"),
		.itemId = ITEM_CARD_SECRET_BARREL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SELF_DESTRUCT_BUTTON] =
	{
		.name = _("SelfDestructB"),
		.itemId = ITEM_CARD_SELF_DESTRUCT_BUTTON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SENIOR_SILVER_NINJA] =
	{
		.name = _("SeniorSilverN"),
		.itemId = ITEM_CARD_SENIOR_SILVER_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SENJU_OF_THE_THOUSAND_HANDS] =
	{
		.name = _("SenjuoftheTho"),
		.itemId = ITEM_CARD_SENJU_OF_THE_THOUSAND_HANDS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SERIAL_SPELL] =
	{
		.name = _("SerialSpell"),
		.itemId = ITEM_CARD_SERIAL_SPELL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SERPENTINE_PRINCESS] =
	{
		.name = _("SerpentinePri"),
		.itemId = ITEM_CARD_SERPENTINE_PRINCESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SEVEN_TOOLS_OF_THE_BANDIT] =
	{
		.name = _("SevenToolsoft"),
		.itemId = ITEM_CARD_SEVEN_TOOLS_OF_THE_BANDIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_BEAST] =
	{
		.name = _("ShaddollBeast"),
		.itemId = ITEM_CARD_SHADDOLL_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_DRAGON] =
	{
		.name = _("ShaddollDrago"),
		.itemId = ITEM_CARD_SHADDOLL_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_FALCO] =
	{
		.name = _("ShaddollFalco"),
		.itemId = ITEM_CARD_SHADDOLL_FALCO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_FUSION] =
	{
		.name = _("ShaddollFusio"),
		.itemId = ITEM_CARD_SHADDOLL_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_HEDGEHOG] =
	{
		.name = _("ShaddollHedge"),
		.itemId = ITEM_CARD_SHADDOLL_HEDGEHOG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_HOUND] =
	{
		.name = _("ShaddollHound"),
		.itemId = ITEM_CARD_SHADDOLL_HOUND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADDOLL_SQUAMATA] =
	{
		.name = _("ShaddollSquam"),
		.itemId = ITEM_CARD_SHADDOLL_SQUAMATA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHADOW_IMPRISONING_MIRROR] =
	{
		.name = _("ShadowImpriso"),
		.itemId = ITEM_CARD_SHADOW_IMPRISONING_MIRROR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHARED_RIDE] =
	{
		.name = _("SharedRide"),
		.itemId = ITEM_CARD_SHARED_RIDE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHIEN_S_SMOKE_SIGNAL] =
	{
		.name = _("ShiensSmokeSi"),
		.itemId = ITEM_CARD_SHIEN_S_SMOKE_SIGNAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHINING_ANGEL] =
	{
		.name = _("ShiningAngel"),
		.itemId = ITEM_CARD_SHINING_ANGEL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHINY_BLACK_C_] =
	{
		.name = _("ShinyBlackC"),
		.itemId = ITEM_CARD_SHINY_BLACK_C_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHINY_BLACK_C_SQUADDER] =
	{
		.name = _("ShinyBlackCSq"),
		.itemId = ITEM_CARD_SHINY_BLACK_C_SQUADDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHRINK] =
	{
		.name = _("Shrink"),
		.itemId = ITEM_CARD_SHRINK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHUFFLE_REBORN] =
	{
		.name = _("ShuffleReborn"),
		.itemId = ITEM_CARD_SHUFFLE_REBORN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SHURIT_STRATEGIST_OF_THE_NEKROZ] =
	{
		.name = _("ShuritStrateg"),
		.itemId = ITEM_CARD_SHURIT_STRATEGIST_OF_THE_NEKROZ,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SILLVA_WARLORD_OF_DARK_WORLD] =
	{
		.name = _("SillvaWarlord"),
		.itemId = ITEM_CARD_SILLVA_WARLORD_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SILPHEED] =
	{
		.name = _("Silpheed"),
		.itemId = ITEM_CARD_SILPHEED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SINISTER_SERPENT] =
	{
		.name = _("SinisterSerpe"),
		.itemId = ITEM_CARD_SINISTER_SERPENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SINISTER_SHADOW_GAMES] =
	{
		.name = _("SinisterShado"),
		.itemId = ITEM_CARD_SINISTER_SHADOW_GAMES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SIX_SAMURAI_UNITED] =
	{
		.name = _("SixSamuraiUni"),
		.itemId = ITEM_CARD_SIX_SAMURAI_UNITED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKILL_DRAIN] =
	{
		.name = _("SkillDrain"),
		.itemId = ITEM_CARD_SKILL_DRAIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKILLED_DARK_MAGICIAN] =
	{
		.name = _("SkilledDarkMa"),
		.itemId = ITEM_CARD_SKILLED_DARK_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKILLED_RED_MAGICIAN] =
	{
		.name = _("SkilledRedMag"),
		.itemId = ITEM_CARD_SKILLED_RED_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKILLED_WHITE_MAGICIAN] =
	{
		.name = _("SkilledWhiteM"),
		.itemId = ITEM_CARD_SKILLED_WHITE_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKULL_DOG_MARRON] =
	{
		.name = _("SkullDogMarro"),
		.itemId = ITEM_CARD_SKULL_DOG_MARRON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKULL_LAIR] =
	{
		.name = _("SkullLair"),
		.itemId = ITEM_CARD_SKULL_LAIR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_IRIS] =
	{
		.name = _("SkyIris"),
		.itemId = ITEM_CARD_SKY_IRIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_SCOUT] =
	{
		.name = _("SkyScout"),
		.itemId = ITEM_CARD_SKY_SCOUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_ACE_KAGARI] =
	{
		.name = _("SkyStrikerAce"),
		.itemId = ITEM_CARD_SKY_STRIKER_ACE_KAGARI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_ACE_RAYE] =
	{
		.name = _("SkyStrikerAce"),
		.itemId = ITEM_CARD_SKY_STRIKER_ACE_RAYE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_ACE_ROZE] =
	{
		.name = _("SkyStrikerAce"),
		.itemId = ITEM_CARD_SKY_STRIKER_ACE_ROZE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_ACE_SHIZUKU] =
	{
		.name = _("SkyStrikerAce"),
		.itemId = ITEM_CARD_SKY_STRIKER_ACE_SHIZUKU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_MANEUVER_AFTERBURNERS_] =
	{
		.name = _("SkyStrikerMan"),
		.itemId = ITEM_CARD_SKY_STRIKER_MANEUVER_AFTERBURNERS_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_MECHA_HORNET_DRONES] =
	{
		.name = _("SkyStrikerMec"),
		.itemId = ITEM_CARD_SKY_STRIKER_MECHA_HORNET_DRONES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_MECHA_SHARK_CANNON] =
	{
		.name = _("SkyStrikerMec"),
		.itemId = ITEM_CARD_SKY_STRIKER_MECHA_SHARK_CANNON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_MECHA_WIDOW_ANCHOR] =
	{
		.name = _("SkyStrikerMec"),
		.itemId = ITEM_CARD_SKY_STRIKER_MECHA_WIDOW_ANCHOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SKY_STRIKER_MOBILIZE_ENGAGE_] =
	{
		.name = _("SkyStrikerMob"),
		.itemId = ITEM_CARD_SKY_STRIKER_MOBILIZE_ENGAGE_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SLATE_WARRIOR] =
	{
		.name = _("SlateWarrior"),
		.itemId = ITEM_CARD_SLATE_WARRIOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SMASHING_GROUND] =
	{
		.name = _("SmashingGroun"),
		.itemId = ITEM_CARD_SMASHING_GROUND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYE_ASH] =
	{
		.name = _("SnakeEyeAsh"),
		.itemId = ITEM_CARD_SNAKE_EYE_ASH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYE_BIRCH] =
	{
		.name = _("SnakeEyeBirch"),
		.itemId = ITEM_CARD_SNAKE_EYE_BIRCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYE_OAK] =
	{
		.name = _("SnakeEyeOak"),
		.itemId = ITEM_CARD_SNAKE_EYE_OAK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYES_DIABELLSTAR] =
	{
		.name = _("SnakeEyesDiab"),
		.itemId = ITEM_CARD_SNAKE_EYES_DIABELLSTAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYES_FLAMBERGE_DRAGON] =
	{
		.name = _("SnakeEyesFlam"),
		.itemId = ITEM_CARD_SNAKE_EYES_FLAMBERGE_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNAKE_EYES_POPLAR] =
	{
		.name = _("SnakeEyesPopl"),
		.itemId = ITEM_CARD_SNAKE_EYES_POPLAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNATCH_STEAL] =
	{
		.name = _("SnatchSteal"),
		.itemId = ITEM_CARD_SNATCH_STEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNIPE_HUNTER] =
	{
		.name = _("SnipeHunter"),
		.itemId = ITEM_CARD_SNIPE_HUNTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNOWMAN_EATER] =
	{
		.name = _("SnowmanEater"),
		.itemId = ITEM_CARD_SNOWMAN_EATER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SNOWW_UNLIGHT_OF_DARK_WORLD] =
	{
		.name = _("SnowwUnlighto"),
		.itemId = ITEM_CARD_SNOWW_UNLIGHT_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOLAR_RECHARGE] =
	{
		.name = _("SolarRecharge"),
		.itemId = ITEM_CARD_SOLAR_RECHARGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOLEMN_JUDGMENT] =
	{
		.name = _("SolemnJudgmen"),
		.itemId = ITEM_CARD_SOLEMN_JUDGMENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOLEMN_STRIKE] =
	{
		.name = _("SolemnStrike"),
		.itemId = ITEM_CARD_SOLEMN_STRIKE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOLEMN_WARNING] =
	{
		.name = _("SolemnWarning"),
		.itemId = ITEM_CARD_SOLEMN_WARNING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOLEMN_WISHES] =
	{
		.name = _("SolemnWishes"),
		.itemId = ITEM_CARD_SOLEMN_WISHES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SONIC_BIRD] =
	{
		.name = _("SonicBird"),
		.itemId = ITEM_CARD_SONIC_BIRD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOUL_CHARGE] =
	{
		.name = _("SoulCharge"),
		.itemId = ITEM_CARD_SOUL_CHARGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOUL_EXCHANGE] =
	{
		.name = _("SoulExchange"),
		.itemId = ITEM_CARD_SOUL_EXCHANGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOUL_TAKER] =
	{
		.name = _("SoulTaker"),
		.itemId = ITEM_CARD_SOUL_TAKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SOUL_TIGER] =
	{
		.name = _("SoulTiger"),
		.itemId = ITEM_CARD_SOUL_TIGER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPEAR_CRETIN] =
	{
		.name = _("SpearCretin"),
		.itemId = ITEM_CARD_SPEAR_CRETIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPEAR_DRAGON] =
	{
		.name = _("SpearDragon"),
		.itemId = ITEM_CARD_SPEAR_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPEEDROID_TAKETOMBORG] =
	{
		.name = _("SpeedroidTake"),
		.itemId = ITEM_CARD_SPEEDROID_TAKETOMBORG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPEEDROID_TERRORTOP] =
	{
		.name = _("SpeedroidTerr"),
		.itemId = ITEM_CARD_SPEEDROID_TERRORTOP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELL_CANCELLER] =
	{
		.name = _("SpellCancelle"),
		.itemId = ITEM_CARD_SPELL_CANCELLER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELL_REPRODUCTION] =
	{
		.name = _("SpellReproduc"),
		.itemId = ITEM_CARD_SPELL_REPRODUCTION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELL_SHATTERING_ARROW] =
	{
		.name = _("SpellShatteri"),
		.itemId = ITEM_CARD_SPELL_SHATTERING_ARROW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELLBOOK_MAGICIAN_OF_PROPHECY] =
	{
		.name = _("SpellbookMagi"),
		.itemId = ITEM_CARD_SPELLBOOK_MAGICIAN_OF_PROPHECY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELLBOOK_OF_JUDGMENT] =
	{
		.name = _("SpellbookofJu"),
		.itemId = ITEM_CARD_SPELLBOOK_OF_JUDGMENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPELLBOOK_OF_SECRETS] =
	{
		.name = _("SpellbookofSe"),
		.itemId = ITEM_CARD_SPELLBOOK_OF_SECRETS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPHERE_KURIBOH] =
	{
		.name = _("SphereKuriboh"),
		.itemId = ITEM_CARD_SPHERE_KURIBOH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRIT_OF_THE_HARP] =
	{
		.name = _("SpiritoftheHa"),
		.itemId = ITEM_CARD_SPIRIT_OF_THE_HARP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRIT_REAPER] =
	{
		.name = _("SpiritReaper"),
		.itemId = ITEM_CARD_SPIRIT_REAPER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRITUAL_EARTH_ART_KUROGANE] =
	{
		.name = _("SpiritualEart"),
		.itemId = ITEM_CARD_SPIRITUAL_EARTH_ART_KUROGANE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRITUAL_WATER_ART_AOI] =
	{
		.name = _("SpiritualWate"),
		.itemId = ITEM_CARD_SPIRITUAL_WATER_ART_AOI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRITUAL_WIND_ART_MIYABI] =
	{
		.name = _("SpiritualWind"),
		.itemId = ITEM_CARD_SPIRITUAL_WIND_ART_MIYABI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPIRITUALISM] =
	{
		.name = _("Spiritualism"),
		.itemId = ITEM_CARD_SPIRITUALISM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_BLUE] =
	{
		.name = _("SprightBlue"),
		.itemId = ITEM_CARD_SPRIGHT_BLUE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_CARROT] =
	{
		.name = _("SprightCarrot"),
		.itemId = ITEM_CARD_SPRIGHT_CARROT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_ELF] =
	{
		.name = _("SprightElf"),
		.itemId = ITEM_CARD_SPRIGHT_ELF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_JET] =
	{
		.name = _("SprightJet"),
		.itemId = ITEM_CARD_SPRIGHT_JET,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_RED] =
	{
		.name = _("SprightRed"),
		.itemId = ITEM_CARD_SPRIGHT_RED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_SMASHERS] =
	{
		.name = _("SprightSmashe"),
		.itemId = ITEM_CARD_SPRIGHT_SMASHERS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_SPRIND] =
	{
		.name = _("SprightSprind"),
		.itemId = ITEM_CARD_SPRIGHT_SPRIND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SPRIGHT_STARTER] =
	{
		.name = _("SprightStarte"),
		.itemId = ITEM_CARD_SPRIGHT_STARTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STARDUST_DRAGON] =
	{
		.name = _("StardustDrago"),
		.itemId = ITEM_CARD_STARDUST_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STARLIGHT_ROAD] =
	{
		.name = _("StarlightRoad"),
		.itemId = ITEM_CARD_STARLIGHT_ROAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STEALTH_BIRD] =
	{
		.name = _("StealthBird"),
		.itemId = ITEM_CARD_STEALTH_BIRD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STEELSWARM_ROACH] =
	{
		.name = _("SteelswarmRoa"),
		.itemId = ITEM_CARD_STEELSWARM_ROACH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STONE_STATUE_OF_THE_AZTECS] =
	{
		.name = _("StoneStatueof"),
		.itemId = ITEM_CARD_STONE_STATUE_OF_THE_AZTECS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STOP_DEFENSE] =
	{
		.name = _("StopDefense"),
		.itemId = ITEM_CARD_STOP_DEFENSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STREAM_DRAGON_RULER_OF_DROPLETS] =
	{
		.name = _("StreamDragonR"),
		.itemId = ITEM_CARD_STREAM_DRAGON_RULER_OF_DROPLETS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_STRIKE_NINJA] =
	{
		.name = _("StrikeNinja"),
		.itemId = ITEM_CARD_STRIKE_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUBSTITOAD] =
	{
		.name = _("Substitoad"),
		.itemId = ITEM_CARD_SUBSTITOAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUMMON_LIMIT] =
	{
		.name = _("SummonLimit"),
		.itemId = ITEM_CARD_SUMMON_LIMIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUMMONED_SKULL] =
	{
		.name = _("SummonedSkull"),
		.itemId = ITEM_CARD_SUMMONED_SKULL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUMMONER_MONK] =
	{
		.name = _("SummonerMonk"),
		.itemId = ITEM_CARD_SUMMONER_MONK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUMMONER_S_ART] =
	{
		.name = _("SummonersArt"),
		.itemId = ITEM_CARD_SUMMONER_S_ART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUPER_POLYMERIZATION] =
	{
		.name = _("SuperPolymeri"),
		.itemId = ITEM_CARD_SUPER_POLYMERIZATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUPER_REJUVENATION] =
	{
		.name = _("SuperRejuvena"),
		.itemId = ITEM_CARD_SUPER_REJUVENATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUPER_SOLDIER_SOUL] =
	{
		.name = _("SuperSoldierS"),
		.itemId = ITEM_CARD_SUPER_SOLDIER_SOUL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SUPER_STARSLAYER_TY_PHON_SKY_CRISIS] =
	{
		.name = _("SuperStarslay"),
		.itemId = ITEM_CARD_SUPER_STARSLAYER_TY_PHON_SKY_CRISIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWAP_FROG] =
	{
		.name = _("SwapFrog"),
		.itemId = ITEM_CARD_SWAP_FROG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWARM_OF_LOCUSTS] =
	{
		.name = _("SwarmofLocust"),
		.itemId = ITEM_CARD_SWARM_OF_LOCUSTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWARM_OF_SCARABS] =
	{
		.name = _("SwarmofScarab"),
		.itemId = ITEM_CARD_SWARM_OF_SCARABS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWIFT_SCARECROW] =
	{
		.name = _("SwiftScarecro"),
		.itemId = ITEM_CARD_SWIFT_SCARECROW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORD_RYZEAL] =
	{
		.name = _("SwordRyzeal"),
		.itemId = ITEM_CARD_SWORD_RYZEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDS_OF_REVEALING_LIGHT] =
	{
		.name = _("SwordsofRevea"),
		.itemId = ITEM_CARD_SWORDS_OF_REVEALING_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_BLACKOUT] =
	{
		.name = _("SwordsoulBlac"),
		.itemId = ITEM_CARD_SWORDSOUL_BLACKOUT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_EMERGENCE] =
	{
		.name = _("SwordsoulEmer"),
		.itemId = ITEM_CARD_SWORDSOUL_EMERGENCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_GRANDMASTER_CHIXIAO] =
	{
		.name = _("SwordsoulGran"),
		.itemId = ITEM_CARD_SWORDSOUL_GRANDMASTER_CHIXIAO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_OF_MO_YE] =
	{
		.name = _("SwordsoulofMo"),
		.itemId = ITEM_CARD_SWORDSOUL_OF_MO_YE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_OF_TAIA] =
	{
		.name = _("SwordsoulofTa"),
		.itemId = ITEM_CARD_SWORDSOUL_OF_TAIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SWORDSOUL_STRATEGIST_LONGYUAN] =
	{
		.name = _("SwordsoulStra"),
		.itemId = ITEM_CARD_SWORDSOUL_STRATEGIST_LONGYUAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_SYSTEM_DOWN] =
	{
		.name = _("SystemDown"),
		.itemId = ITEM_CARD_SYSTEM_DOWN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_T_A_D_P_O_L_E_] =
	{
		.name = _("TADPOLE"),
		.itemId = ITEM_CARD_T_A_D_P_O_L_E_,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_T_G_RUSH_RHINO] =
	{
		.name = _("TGRushRhino"),
		.itemId = ITEM_CARD_T_G_RUSH_RHINO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_T_G_STRIKER] =
	{
		.name = _("TGStriker"),
		.itemId = ITEM_CARD_T_G_STRIKER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_T_G_WARWOLF] =
	{
		.name = _("TGWarwolf"),
		.itemId = ITEM_CARD_T_G_WARWOLF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_CRYME] =
	{
		.name = _("TearlamentsCr"),
		.itemId = ITEM_CARD_TEARLAMENTS_CRYME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_HAVNIS] =
	{
		.name = _("TearlamentsHa"),
		.itemId = ITEM_CARD_TEARLAMENTS_HAVNIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_HEARTBEAT] =
	{
		.name = _("TearlamentsHe"),
		.itemId = ITEM_CARD_TEARLAMENTS_HEARTBEAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_KALEIDO_HEART] =
	{
		.name = _("TearlamentsKa"),
		.itemId = ITEM_CARD_TEARLAMENTS_KALEIDO_HEART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_KASHTIRA] =
	{
		.name = _("TearlamentsKa"),
		.itemId = ITEM_CARD_TEARLAMENTS_KASHTIRA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_KITKALLOS] =
	{
		.name = _("TearlamentsKi"),
		.itemId = ITEM_CARD_TEARLAMENTS_KITKALLOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_MERRLI] =
	{
		.name = _("TearlamentsMe"),
		.itemId = ITEM_CARD_TEARLAMENTS_MERRLI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_REINOHEART] =
	{
		.name = _("TearlamentsRe"),
		.itemId = ITEM_CARD_TEARLAMENTS_REINOHEART,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_RULKALLOS] =
	{
		.name = _("TearlamentsRu"),
		.itemId = ITEM_CARD_TEARLAMENTS_RULKALLOS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_SCHEIREN] =
	{
		.name = _("TearlamentsSc"),
		.itemId = ITEM_CARD_TEARLAMENTS_SCHEIREN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_SCREAM] =
	{
		.name = _("TearlamentsSc"),
		.itemId = ITEM_CARD_TEARLAMENTS_SCREAM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEARLAMENTS_SULLIEK] =
	{
		.name = _("TearlamentsSu"),
		.itemId = ITEM_CARD_TEARLAMENTS_SULLIEK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TELLARKNIGHT_PTOLEMAEUS] =
	{
		.name = _("TellarknightP"),
		.itemId = ITEM_CARD_TELLARKNIGHT_PTOLEMAEUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEMPEST_MAGICIAN] =
	{
		.name = _("TempestMagici"),
		.itemId = ITEM_CARD_TEMPEST_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEMPEST_DRAGON_RULER_OF_STORMS] =
	{
		.name = _("TempestDragon"),
		.itemId = ITEM_CARD_TEMPEST_DRAGON_RULER_OF_STORMS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEMTEMPO_THE_PERCUSSION_DJINN] =
	{
		.name = _("TemtempothePe"),
		.itemId = ITEM_CARD_TEMTEMPO_THE_PERCUSSION_DJINN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENACITY_OF_THE_MONARCHS] =
	{
		.name = _("Tenacityofthe"),
		.itemId = ITEM_CARD_TENACITY_OF_THE_MONARCHS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENMATAITEI] =
	{
		.name = _("Tenmataitei"),
		.itemId = ITEM_CARD_TENMATAITEI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENPAI_DRAGON_CHUNDRA] =
	{
		.name = _("TenpaiDragonC"),
		.itemId = ITEM_CARD_TENPAI_DRAGON_CHUNDRA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENPAI_DRAGON_FADRA] =
	{
		.name = _("TenpaiDragonF"),
		.itemId = ITEM_CARD_TENPAI_DRAGON_FADRA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENYI_SPIRIT_ADHARA] =
	{
		.name = _("TenyiSpiritAd"),
		.itemId = ITEM_CARD_TENYI_SPIRIT_ADHARA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENYI_SPIRIT_ASHUNA] =
	{
		.name = _("TenyiSpiritAs"),
		.itemId = ITEM_CARD_TENYI_SPIRIT_ASHUNA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TENYI_SPIRIT_VISHUDA] =
	{
		.name = _("TenyiSpiritVi"),
		.itemId = ITEM_CARD_TENYI_SPIRIT_VISHUDA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TERRAFORMING] =
	{
		.name = _("Terraforming"),
		.itemId = ITEM_CARD_TERRAFORMING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TERRORKING_SALMON] =
	{
		.name = _("TerrorkingSal"),
		.itemId = ITEM_CARD_TERRORKING_SALMON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TEST_TIGER] =
	{
		.name = _("TestTiger"),
		.itemId = ITEM_CARD_TEST_TIGER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TG1_EM1] =
	{
		.name = _("TG1EM1"),
		.itemId = ITEM_CARD_TG1_EM1,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THAT_GRASS_LOOKS_GREENER] =
	{
		.name = _("ThatGrassLook"),
		.itemId = ITEM_CARD_THAT_GRASS_LOOKS_GREENER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_AGENT_OF_MIRACLES_JUPITER] =
	{
		.name = _("TheAgentofMir"),
		.itemId = ITEM_CARD_THE_AGENT_OF_MIRACLES_JUPITER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_AGENT_OF_MYSTERY_EARTH] =
	{
		.name = _("TheAgentofMys"),
		.itemId = ITEM_CARD_THE_AGENT_OF_MYSTERY_EARTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_BIG_MARCH_OF_ANIMALS] =
	{
		.name = _("TheBigMarchof"),
		.itemId = ITEM_CARD_THE_BIG_MARCH_OF_ANIMALS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_BLACK_STONE_OF_LEGEND] =
	{
		.name = _("TheBlackStone"),
		.itemId = ITEM_CARD_THE_BLACK_STONE_OF_LEGEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_BYSTIAL_ALUBER] =
	{
		.name = _("TheBystialAlu"),
		.itemId = ITEM_CARD_THE_BYSTIAL_ALUBER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_BYSTIAL_LUBELLION] =
	{
		.name = _("TheBystialLub"),
		.itemId = ITEM_CARD_THE_BYSTIAL_LUBELLION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_DARK_HEX_SEALED_FUSION] =
	{
		.name = _("TheDarkHexSea"),
		.itemId = ITEM_CARD_THE_DARK_HEX_SEALED_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_DARK_MAGICIANS] =
	{
		.name = _("TheDarkMagici"),
		.itemId = ITEM_CARD_THE_DARK_MAGICIANS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_DRAGON_DWELLING_IN_THE_CAVE] =
	{
		.name = _("TheDragonDwel"),
		.itemId = ITEM_CARD_THE_DRAGON_DWELLING_IN_THE_CAVE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_EARTH_HEX_SEALED_FUSION] =
	{
		.name = _("TheEarthHexSe"),
		.itemId = ITEM_CARD_THE_EARTH_HEX_SEALED_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_FIEND_MEGACYBER] =
	{
		.name = _("TheFiendMegac"),
		.itemId = ITEM_CARD_THE_FIEND_MEGACYBER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_FORCEFUL_SENTRY] =
	{
		.name = _("TheForcefulSe"),
		.itemId = ITEM_CARD_THE_FORCEFUL_SENTRY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_FORGIVING_MAIDEN] =
	{
		.name = _("TheForgivingM"),
		.itemId = ITEM_CARD_THE_FORGIVING_MAIDEN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_GOLDEN_SWORDSOUL] =
	{
		.name = _("TheGoldenSwor"),
		.itemId = ITEM_CARD_THE_GOLDEN_SWORDSOUL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET] =
	{
		.name = _("TheLastWarrio"),
		.itemId = ITEM_CARD_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_LIGHT_HEX_SEALED_FUSION] =
	{
		.name = _("TheLightHexSe"),
		.itemId = ITEM_CARD_THE_LIGHT_HEX_SEALED_FUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_LITTLE_SWORDSMAN_OF_AILE] =
	{
		.name = _("TheLittleSwor"),
		.itemId = ITEM_CARD_THE_LITTLE_SWORDSMAN_OF_AILE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_MONARCHS_STORMFORTH] =
	{
		.name = _("TheMonarchsSt"),
		.itemId = ITEM_CARD_THE_MONARCHS_STORMFORTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_ANCIENT_CLOAK] =
	{
		.name = _("ThePhantomKni"),
		.itemId = ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_ANCIENT_CLOAK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_BREAK_SWORD] =
	{
		.name = _("ThePhantomKni"),
		.itemId = ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_BREAK_SWORD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_SILENT_BOOTS] =
	{
		.name = _("ThePhantomKni"),
		.itemId = ITEM_CARD_THE_PHANTOM_KNIGHTS_OF_SILENT_BOOTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_PRIME_MONARCH] =
	{
		.name = _("ThePrimeMonar"),
		.itemId = ITEM_CARD_THE_PRIME_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_TRICKY] =
	{
		.name = _("TheTricky"),
		.itemId = ITEM_CARD_THE_TRICKY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_WHITE_STONE_OF_ANCIENTS] =
	{
		.name = _("TheWhiteStone"),
		.itemId = ITEM_CARD_THE_WHITE_STONE_OF_ANCIENTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_WHITE_STONE_OF_LEGEND] =
	{
		.name = _("TheWhiteStone"),
		.itemId = ITEM_CARD_THE_WHITE_STONE_OF_LEGEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_WICKED_WORM_BEAST] =
	{
		.name = _("TheWickedWorm"),
		.itemId = ITEM_CARD_THE_WICKED_WORM_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THE_WINGED_DRAGON_OF_RA_SPHERE_MODE] =
	{
		.name = _("TheWingedDrag"),
		.itemId = ITEM_CARD_THE_WINGED_DRAGON_OF_RA_SPHERE_MODE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THERE_CAN_BE_ONLY_ONE] =
	{
		.name = _("ThereCanBeOnl"),
		.itemId = ITEM_CARD_THERE_CAN_BE_ONLY_ONE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THESTALOS_THE_FIRESTORM_MONARCH] =
	{
		.name = _("ThestalostheF"),
		.itemId = ITEM_CARD_THESTALOS_THE_FIRESTORM_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THESTALOS_THE_MEGA_MONARCH] =
	{
		.name = _("ThestalostheM"),
		.itemId = ITEM_CARD_THESTALOS_THE_MEGA_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THESTALOS_THE_SHADOWFIRE_MONARCH] =
	{
		.name = _("ThestalostheS"),
		.itemId = ITEM_CARD_THESTALOS_THE_SHADOWFIRE_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THOUGHT_RULER_ARCHFIEND] =
	{
		.name = _("ThoughtRulerA"),
		.itemId = ITEM_CARD_THOUGHT_RULER_ARCHFIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THOUSAND_EYES_RESTRICT] =
	{
		.name = _("ThousandEyesR"),
		.itemId = ITEM_CARD_THOUSAND_EYES_RESTRICT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THREATENING_ROAR] =
	{
		.name = _("ThreateningRo"),
		.itemId = ITEM_CARD_THREATENING_ROAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THROWSTONE_UNIT] =
	{
		.name = _("ThrowstoneUni"),
		.itemId = ITEM_CARD_THROWSTONE_UNIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGON] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGON_COLOSSUS] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGON_COLOSSUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGON_TITAN] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGON_TITAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONDARK] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONDARK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONDUO] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONDUO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONHAWK] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONHAWK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONLORD] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONLORD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONMATRIX] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONMATRIX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_DRAGONROAR] =
	{
		.name = _("ThunderDragon"),
		.itemId = ITEM_CARD_THUNDER_DRAGONROAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_KING_RAI_OH] =
	{
		.name = _("ThunderKingRa"),
		.itemId = ITEM_CARD_THUNDER_KING_RAI_OH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_NYAN_NYAN] =
	{
		.name = _("ThunderNyanNy"),
		.itemId = ITEM_CARD_THUNDER_NYAN_NYAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_THUNDER_SEA_HORSE] =
	{
		.name = _("ThunderSeaHor"),
		.itemId = ITEM_CARD_THUNDER_SEA_HORSE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TIDAL_DRAGON_RULER_OF_WATERFALLS] =
	{
		.name = _("TidalDragonRu"),
		.itemId = ITEM_CARD_TIDAL_DRAGON_RULER_OF_WATERFALLS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TIMAEUS_THE_UNITED_DRAGON] =
	{
		.name = _("TimaeustheUni"),
		.itemId = ITEM_CARD_TIMAEUS_THE_UNITED_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TIME_SEAL] =
	{
		.name = _("TimeSeal"),
		.itemId = ITEM_CARD_TIME_SEAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TIME_SPACE_TRAP_HOLE] =
	{
		.name = _("TimeSpaceTrap"),
		.itemId = ITEM_CARD_TIME_SPACE_TRAP_HOLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TITANIKLAD_THE_ASH_DRAGON] =
	{
		.name = _("Titanikladthe"),
		.itemId = ITEM_CARD_TITANIKLAD_THE_ASH_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TLAKALEL_HIS_MALEVOLENT_MAJESTY] =
	{
		.name = _("TlakalelHisMa"),
		.itemId = ITEM_CARD_TLAKALEL_HIS_MALEVOLENT_MAJESTY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOADALLY_AWESOME] =
	{
		.name = _("ToadallyAweso"),
		.itemId = ITEM_CARD_TOADALLY_AWESOME,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOBARI_THE_SKY_NINJA] =
	{
		.name = _("TobaritheSkyN"),
		.itemId = ITEM_CARD_TOBARI_THE_SKY_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOKEN_COLLECTOR] =
	{
		.name = _("TokenCollecto"),
		.itemId = ITEM_CARD_TOKEN_COLLECTOR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_CANNON_SOLDIER] =
	{
		.name = _("ToonCannonSol"),
		.itemId = ITEM_CARD_TOON_CANNON_SOLDIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_CYBER_DRAGON] =
	{
		.name = _("ToonCyberDrag"),
		.itemId = ITEM_CARD_TOON_CYBER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_DARK_MAGICIAN_GIRL] =
	{
		.name = _("ToonDarkMagic"),
		.itemId = ITEM_CARD_TOON_DARK_MAGICIAN_GIRL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_GEMINI_ELF] =
	{
		.name = _("ToonGeminiElf"),
		.itemId = ITEM_CARD_TOON_GEMINI_ELF,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_GOBLIN_ATTACK_FORCE] =
	{
		.name = _("ToonGoblinAtt"),
		.itemId = ITEM_CARD_TOON_GOBLIN_ATTACK_FORCE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_MASKED_SORCERER] =
	{
		.name = _("ToonMaskedSor"),
		.itemId = ITEM_CARD_TOON_MASKED_SORCERER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_SUMMONED_SKULL] =
	{
		.name = _("ToonSummonedS"),
		.itemId = ITEM_CARD_TOON_SUMMONED_SKULL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOON_TABLE_OF_CONTENTS] =
	{
		.name = _("ToonTableofCo"),
		.itemId = ITEM_CARD_TOON_TABLE_OF_CONTENTS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TORNADO_DRAGON] =
	{
		.name = _("TornadoDragon"),
		.itemId = ITEM_CARD_TORNADO_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TORRENTIAL_TRIBUTE] =
	{
		.name = _("TorrentialTri"),
		.itemId = ITEM_CARD_TORRENTIAL_TRIBUTE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOTEM_BIRD] =
	{
		.name = _("TotemBird"),
		.itemId = ITEM_CARD_TOTEM_BIRD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TOUR_GUIDE_FROM_THE_UNDERWORLD] =
	{
		.name = _("TourGuideFrom"),
		.itemId = ITEM_CARD_TOUR_GUIDE_FROM_THE_UNDERWORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRADETOAD] =
	{
		.name = _("Tradetoad"),
		.itemId = ITEM_CARD_TRADETOAD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAGOEDIA] =
	{
		.name = _("Tragoedia"),
		.itemId = ITEM_CARD_TRAGOEDIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAP_DUSTSHOOT] =
	{
		.name = _("TrapDustshoot"),
		.itemId = ITEM_CARD_TRAP_DUSTSHOOT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAP_EATER] =
	{
		.name = _("TrapEater"),
		.itemId = ITEM_CARD_TRAP_EATER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAP_HOLE] =
	{
		.name = _("TrapHole"),
		.itemId = ITEM_CARD_TRAP_HOLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAP_MASTER] =
	{
		.name = _("TrapMaster"),
		.itemId = ITEM_CARD_TRAP_MASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAP_STUN] =
	{
		.name = _("TrapStun"),
		.itemId = ITEM_CARD_TRAP_STUN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_ARACHNOCAMPA] =
	{
		.name = _("TraptrixArach"),
		.itemId = ITEM_CARD_TRAPTRIX_ARACHNOCAMPA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_ATRAX] =
	{
		.name = _("TraptrixAtrax"),
		.itemId = ITEM_CARD_TRAPTRIX_ATRAX,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_DIONAEA] =
	{
		.name = _("TraptrixDiona"),
		.itemId = ITEM_CARD_TRAPTRIX_DIONAEA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_GENLISEA] =
	{
		.name = _("TraptrixGenli"),
		.itemId = ITEM_CARD_TRAPTRIX_GENLISEA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_MANTIS] =
	{
		.name = _("TraptrixManti"),
		.itemId = ITEM_CARD_TRAPTRIX_MANTIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_MYRMELEO] =
	{
		.name = _("TraptrixMyrme"),
		.itemId = ITEM_CARD_TRAPTRIX_MYRMELEO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_NEPENTHES] =
	{
		.name = _("TraptrixNepen"),
		.itemId = ITEM_CARD_TRAPTRIX_NEPENTHES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_PUDICA] =
	{
		.name = _("TraptrixPudic"),
		.itemId = ITEM_CARD_TRAPTRIX_PUDICA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_RAFFLESIA] =
	{
		.name = _("TraptrixRaffl"),
		.itemId = ITEM_CARD_TRAPTRIX_RAFFLESIA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_TRAP_HOLE_NIGHTMARE] =
	{
		.name = _("TraptrixTrapH"),
		.itemId = ITEM_CARD_TRAPTRIX_TRAP_HOLE_NIGHTMARE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRAPTRIX_VESICULO] =
	{
		.name = _("TraptrixVesic"),
		.itemId = ITEM_CARD_TRAPTRIX_VESICULO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TREEBORN_FROG] =
	{
		.name = _("TreebornFrog"),
		.itemId = ITEM_CARD_TREEBORN_FROG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TREMENDOUS_FIRE] =
	{
		.name = _("TremendousFir"),
		.itemId = ITEM_CARD_TREMENDOUS_FIRE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRI_BRIGADE_FRAKTALL] =
	{
		.name = _("TriBrigadeFra"),
		.itemId = ITEM_CARD_TRI_BRIGADE_FRAKTALL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRI_BRIGADE_KITT] =
	{
		.name = _("TriBrigadeKit"),
		.itemId = ITEM_CARD_TRI_BRIGADE_KITT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRI_BRIGADE_NERVALL] =
	{
		.name = _("TriBrigadeNer"),
		.itemId = ITEM_CARD_TRI_BRIGADE_NERVALL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRI_BRIGADE_REVOLT] =
	{
		.name = _("TriBrigadeRev"),
		.itemId = ITEM_CARD_TRI_BRIGADE_REVOLT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRIBE_INFECTING_VIRUS] =
	{
		.name = _("TribeInfectin"),
		.itemId = ITEM_CARD_TRIBE_INFECTING_VIRUS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRIBUTE_TO_THE_DOOMED] =
	{
		.name = _("TributetotheD"),
		.itemId = ITEM_CARD_TRIBUTE_TO_THE_DOOMED,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRICKSTAR_CANDINA] =
	{
		.name = _("TrickstarCand"),
		.itemId = ITEM_CARD_TRICKSTAR_CANDINA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRICKSTAR_LIGHT_STAGE] =
	{
		.name = _("TrickstarLigh"),
		.itemId = ITEM_CARD_TRICKSTAR_LIGHT_STAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRICKSTAR_LYCORIS] =
	{
		.name = _("TrickstarLyco"),
		.itemId = ITEM_CARD_TRICKSTAR_LYCORIS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRICKSTAR_REINCARNATION] =
	{
		.name = _("TrickstarRein"),
		.itemId = ITEM_CARD_TRICKSTAR_REINCARNATION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRIPLE_TACTICS_TALENT] =
	{
		.name = _("TripleTactics"),
		.itemId = ITEM_CARD_TRIPLE_TACTICS_TALENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRIPLE_TACTICS_THRUST] =
	{
		.name = _("TripleTactics"),
		.itemId = ITEM_CARD_TRIPLE_TACTICS_THRUST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRISHULA_DRAGON_OF_THE_ICE_BARRIER] =
	{
		.name = _("TrishulaDrago"),
		.itemId = ITEM_CARD_TRISHULA_DRAGON_OF_THE_ICE_BARRIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRUE_DRACO_HERITAGE] =
	{
		.name = _("TrueDracoHeri"),
		.itemId = ITEM_CARD_TRUE_DRACO_HERITAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TRUE_KING_S_RETURN] =
	{
		.name = _("TrueKingsRetu"),
		.itemId = ITEM_CARD_TRUE_KING_S_RETURN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TSUKUYOMI] =
	{
		.name = _("Tsukuyomi"),
		.itemId = ITEM_CARD_TSUKUYOMI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWILIGHT_NINJA_GETSUGA_THE_SHOGUN] =
	{
		.name = _("TwilightNinja"),
		.itemId = ITEM_CARD_TWILIGHT_NINJA_GETSUGA_THE_SHOGUN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWILIGHT_NINJA_NICHIRIN_THE_CHUNIN] =
	{
		.name = _("TwilightNinja"),
		.itemId = ITEM_CARD_TWILIGHT_NINJA_NICHIRIN_THE_CHUNIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWILIGHT_NINJA_SHINGETSU] =
	{
		.name = _("TwilightNinja"),
		.itemId = ITEM_CARD_TWILIGHT_NINJA_SHINGETSU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWIN_TWISTERS] =
	{
		.name = _("TwinTwisters"),
		.itemId = ITEM_CARD_TWIN_TWISTERS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWIN_HEADED_BEHEMOTH] =
	{
		.name = _("TwinHeadedBeh"),
		.itemId = ITEM_CARD_TWIN_HEADED_BEHEMOTH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWIN_HEADED_THUNDER_DRAGON] =
	{
		.name = _("TwinHeadedThu"),
		.itemId = ITEM_CARD_TWIN_HEADED_THUNDER_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TWISTER] =
	{
		.name = _("Twister"),
		.itemId = ITEM_CARD_TWISTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_TYPHOON] =
	{
		.name = _("Typhoon"),
		.itemId = ITEM_CARD_TYPHOON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_UFO_TURTLE] =
	{
		.name = _("UFOTurtle"),
		.itemId = ITEM_CARD_UFO_TURTLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_FLAME_SWORDSMAN] =
	{
		.name = _("UltimateFlame"),
		.itemId = ITEM_CARD_ULTIMATE_FLAME_SWORDSMAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_INSECT_LV3] =
	{
		.name = _("UltimateInsec"),
		.itemId = ITEM_CARD_ULTIMATE_INSECT_LV3,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_INSECT_LV5] =
	{
		.name = _("UltimateInsec"),
		.itemId = ITEM_CARD_ULTIMATE_INSECT_LV5,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_INSECT_LV7] =
	{
		.name = _("UltimateInsec"),
		.itemId = ITEM_CARD_ULTIMATE_INSECT_LV7,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_OFFERING] =
	{
		.name = _("UltimateOffer"),
		.itemId = ITEM_CARD_ULTIMATE_OFFERING,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ULTIMATE_SLAYER] =
	{
		.name = _("UltimateSlaye"),
		.itemId = ITEM_CARD_ULTIMATE_SLAYER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_UNITED_WE_STAND] =
	{
		.name = _("UnitedWeStand"),
		.itemId = ITEM_CARD_UNITED_WE_STAND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_UPSTART_GOBLIN] =
	{
		.name = _("UpstartGoblin"),
		.itemId = ITEM_CARD_UPSTART_GOBLIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_UPSTART_GOLDEN_NINJA] =
	{
		.name = _("UpstartGolden"),
		.itemId = ITEM_CARD_UPSTART_GOLDEN_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VAMPIRE_LORD] =
	{
		.name = _("VampireLord"),
		.itemId = ITEM_CARD_VAMPIRE_LORD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VANITY_S_EMPTINESS] =
	{
		.name = _("VanitysEmptin"),
		.itemId = ITEM_CARD_VANITY_S_EMPTINESS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VANITY_S_FIEND] =
	{
		.name = _("VanitysFiend"),
		.itemId = ITEM_CARD_VANITY_S_FIEND,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VECTOR_PENDULUM_THE_DRACOVERLORD] =
	{
		.name = _("VectorPendulu"),
		.itemId = ITEM_CARD_VECTOR_PENDULUM_THE_DRACOVERLORD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VESSEL_FOR_THE_DRAGON_CYCLE] =
	{
		.name = _("VesselfortheD"),
		.itemId = ITEM_CARD_VESSEL_FOR_THE_DRAGON_CYCLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VIRGIL_ROCK_STAR_OF_THE_BURNING_ABYSS] =
	{
		.name = _("VirgilRockSta"),
		.itemId = ITEM_CARD_VIRGIL_ROCK_STAR_OF_THE_BURNING_ABYSS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VISION_HERO_VYON] =
	{
		.name = _("VisionHEROVyo"),
		.itemId = ITEM_CARD_VISION_HERO_VYON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VOID_FEAST] =
	{
		.name = _("VoidFeast"),
		.itemId = ITEM_CARD_VOID_FEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VOID_VANISHMENT] =
	{
		.name = _("VoidVanishmen"),
		.itemId = ITEM_CARD_VOID_VANISHMENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VOLCANIC_SCATTERSHOT] =
	{
		.name = _("VolcanicScatt"),
		.itemId = ITEM_CARD_VOLCANIC_SCATTERSHOT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_VORSE_RAIDER] =
	{
		.name = _("VorseRaider"),
		.itemId = ITEM_CARD_VORSE_RAIDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WABOKU] =
	{
		.name = _("Waboku"),
		.itemId = ITEM_CARD_WABOKU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WALL_OF_ILLUSION] =
	{
		.name = _("WallofIllusio"),
		.itemId = ITEM_CARD_WALL_OF_ILLUSION,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WALL_OF_REVEALING_LIGHT] =
	{
		.name = _("WallofReveali"),
		.itemId = ITEM_CARD_WALL_OF_REVEALING_LIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WANDERING_GRYPHON_RIDER] =
	{
		.name = _("WanderingGryp"),
		.itemId = ITEM_CARD_WANDERING_GRYPHON_RIDER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WANTED_SEEKER_OF_SINFUL_SPOILS] =
	{
		.name = _("WANTEDSeekero"),
		.itemId = ITEM_CARD_WANTED_SEEKER_OF_SINFUL_SPOILS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WATER_ENCHANTRESS_OF_THE_TEMPLE] =
	{
		.name = _("WaterEnchantr"),
		.itemId = ITEM_CARD_WATER_ENCHANTRESS_OF_THE_TEMPLE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WAVE_MOTION_CANNON] =
	{
		.name = _("WaveMotionCan"),
		.itemId = ITEM_CARD_WAVE_MOTION_CANNON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WAVERING_EYES] =
	{
		.name = _("WaveringEyes"),
		.itemId = ITEM_CARD_WAVERING_EYES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_DRAGON_NINJA] =
	{
		.name = _("WhiteDragonNi"),
		.itemId = ITEM_CARD_WHITE_DRAGON_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_DRAGON_RITUAL] =
	{
		.name = _("WhiteDragonRi"),
		.itemId = ITEM_CARD_WHITE_DRAGON_RITUAL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_DRAGON_WYVERBURSTER] =
	{
		.name = _("WhiteDragonWy"),
		.itemId = ITEM_CARD_WHITE_DRAGON_WYVERBURSTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_MAGICAL_HAT] =
	{
		.name = _("WhiteMagicalH"),
		.itemId = ITEM_CARD_WHITE_MAGICAL_HAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_NIGHT_DRAGON] =
	{
		.name = _("WhiteNightDra"),
		.itemId = ITEM_CARD_WHITE_NIGHT_DRAGON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WHITE_NINJA] =
	{
		.name = _("WhiteNinja"),
		.itemId = ITEM_CARD_WHITE_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIDESPREAD_RUIN] =
	{
		.name = _("WidespreadRui"),
		.itemId = ITEM_CARD_WIDESPREAD_RUIN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_FACTORY] =
	{
		.name = _("WindUpFactory"),
		.itemId = ITEM_CARD_WIND_UP_FACTORY,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_MAGICIAN] =
	{
		.name = _("WindUpMagicia"),
		.itemId = ITEM_CARD_WIND_UP_MAGICIAN,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_RABBIT] =
	{
		.name = _("WindUpRabbit"),
		.itemId = ITEM_CARD_WIND_UP_RABBIT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_RAT] =
	{
		.name = _("WindUpRat"),
		.itemId = ITEM_CARD_WIND_UP_RAT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_SHARK] =
	{
		.name = _("WindUpShark"),
		.itemId = ITEM_CARD_WIND_UP_SHARK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WIND_UP_ZENMAINES] =
	{
		.name = _("WindUpZenmain"),
		.itemId = ITEM_CARD_WIND_UP_ZENMAINES,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WITCH_OF_THE_BLACK_FOREST] =
	{
		.name = _("WitchoftheBla"),
		.itemId = ITEM_CARD_WITCH_OF_THE_BLACK_FOREST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WROUGHTWEILER] =
	{
		.name = _("Wroughtweiler"),
		.itemId = ITEM_CARD_WROUGHTWEILER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_WULF_LIGHTSWORN_BEAST] =
	{
		.name = _("WulfLightswor"),
		.itemId = ITEM_CARD_WULF_LIGHTSWORN_BEAST,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_X_HEAD_CANNON] =
	{
		.name = _("XHeadCannon"),
		.itemId = ITEM_CARD_X_HEAD_CANNON,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_X_SABER_AIRBELLUM] =
	{
		.name = _("XSaberAirbell"),
		.itemId = ITEM_CARD_X_SABER_AIRBELLUM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_X_SABER_URBELLUM] =
	{
		.name = _("XSaberUrbellu"),
		.itemId = ITEM_CARD_X_SABER_URBELLUM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XING_ZHEN_HU] =
	{
		.name = _("XingZhenHu"),
		.itemId = ITEM_CARD_XING_ZHEN_HU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_BOGGART_KNIGHT] =
	{
		.name = _("XXSaberBoggar"),
		.itemId = ITEM_CARD_XX_SABER_BOGGART_KNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_DARKSOUL] =
	{
		.name = _("XXSaberDarkso"),
		.itemId = ITEM_CARD_XX_SABER_DARKSOUL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_EMMERSBLADE] =
	{
		.name = _("XXSaberEmmers"),
		.itemId = ITEM_CARD_XX_SABER_EMMERSBLADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_FAULTROLL] =
	{
		.name = _("XXSaberFaultr"),
		.itemId = ITEM_CARD_XX_SABER_FAULTROLL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_FULHELMKNIGHT] =
	{
		.name = _("XXSaberFulhel"),
		.itemId = ITEM_CARD_XX_SABER_FULHELMKNIGHT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_GOTTOMS] =
	{
		.name = _("XXSaberGottom"),
		.itemId = ITEM_CARD_XX_SABER_GOTTOMS,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XX_SABER_HYUNLEI] =
	{
		.name = _("XXSaberHyunle"),
		.itemId = ITEM_CARD_XX_SABER_HYUNLEI,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_XYZ_ENCORE] =
	{
		.name = _("XyzEncore"),
		.itemId = ITEM_CARD_XYZ_ENCORE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_YATA_GARASU] =
	{
		.name = _("YataGarasu"),
		.itemId = ITEM_CARD_YATA_GARASU,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_YELLOW_DRAGON_NINJA] =
	{
		.name = _("YellowDragonN"),
		.itemId = ITEM_CARD_YELLOW_DRAGON_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_YELLOW_NINJA] =
	{
		.name = _("YellowNinja"),
		.itemId = ITEM_CARD_YELLOW_NINJA,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_YOMI_SHIP] =
	{
		.name = _("YomiShip"),
		.itemId = ITEM_CARD_YOMI_SHIP,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZABORG_THE_THUNDER_MONARCH] =
	{
		.name = _("ZaborgtheThun"),
		.itemId = ITEM_CARD_ZABORG_THE_THUNDER_MONARCH,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOMBIE_MASTER] =
	{
		.name = _("ZombieMaster"),
		.itemId = ITEM_CARD_ZOMBIE_MASTER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOMBIE_WORLD] =
	{
		.name = _("ZombieWorld"),
		.itemId = ITEM_CARD_ZOMBIE_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOMBINO] =
	{
		.name = _("Zombino"),
		.itemId = ITEM_CARD_ZOMBINO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOMBYRA_THE_DARK] =
	{
		.name = _("ZombyratheDar"),
		.itemId = ITEM_CARD_ZOMBYRA_THE_DARK,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_BARRAGE] =
	{
		.name = _("ZoodiacBarrag"),
		.itemId = ITEM_CARD_ZOODIAC_BARRAGE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_BOARBOW] =
	{
		.name = _("ZoodiacBoarbo"),
		.itemId = ITEM_CARD_ZOODIAC_BOARBOW,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_BROADBULL] =
	{
		.name = _("ZoodiacBroadb"),
		.itemId = ITEM_CARD_ZOODIAC_BROADBULL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_CHAKANINE] =
	{
		.name = _("ZoodiacChakan"),
		.itemId = ITEM_CARD_ZOODIAC_CHAKANINE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_COMBO] =
	{
		.name = _("ZoodiacCombo"),
		.itemId = ITEM_CARD_ZOODIAC_COMBO,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_DRIDENT] =
	{
		.name = _("ZoodiacDriden"),
		.itemId = ITEM_CARD_ZOODIAC_DRIDENT,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_HAMMERKONG] =
	{
		.name = _("ZoodiacHammer"),
		.itemId = ITEM_CARD_ZOODIAC_HAMMERKONG,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_RAMRAM] =
	{
		.name = _("ZoodiacRamram"),
		.itemId = ITEM_CARD_ZOODIAC_RAMRAM,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_RATPIER] =
	{
		.name = _("ZoodiacRatpie"),
		.itemId = ITEM_CARD_ZOODIAC_RATPIER,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_THOROUGHBLADE] =
	{
		.name = _("ZoodiacThorou"),
		.itemId = ITEM_CARD_ZOODIAC_THOROUGHBLADE,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_TIGERMORTAR] =
	{
		.name = _("ZoodiacTigerm"),
		.itemId = ITEM_CARD_ZOODIAC_TIGERMORTAR,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZOODIAC_WHIPTAIL] =
	{
		.name = _("ZoodiacWhipta"),
		.itemId = ITEM_CARD_ZOODIAC_WHIPTAIL,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_CARD_ZURE_KNIGHT_OF_DARK_WORLD] =
	{
		.name = _("ZureKnightofD"),
		.itemId = ITEM_CARD_ZURE_KNIGHT_OF_DARK_WORLD,
		.price = 0,
		.description = sDummyDesc,
		.pocket = POCKET_TRUNK,
		.type = ITEM_USE_FIELD,
		.fieldUseFunc = ItemUseOutOfBattle_Card,
	},

	[ITEM_PACK_TCG_2_PLAYER_STARTER_SET] =
    {
        .name = _("2-Player Star"),
        .itemId = ITEM_PACK_TCG_2_PLAYER_STARTER_SET,
        .price = 0,
        .description = sTCG2PlayerStarterSetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ABSOLUTE_POWERFORCE] =
    {
        .name = _("Absolute Powe"),
        .itemId = ITEM_PACK_TCG_ABSOLUTE_POWERFORCE,
        .price = 0,
        .description = sTCGAbsolutePowerforceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ABYSS_RISING] =
    {
        .name = _("Abyss Rising"),
        .itemId = ITEM_PACK_TCG_ABYSS_RISING,
        .price = 0,
        .description = sTCGAbyssRisingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_AGE_OF_OVERLORD] =
    {
        .name = _("Age of Overlo"),
        .itemId = ITEM_PACK_TCG_AGE_OF_OVERLORD,
        .price = 0,
        .description = sTCGAgeofOverlordDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ALLIANCE_INSIGHT] =
    {
        .name = _("Alliance Insi"),
        .itemId = ITEM_PACK_TCG_ALLIANCE_INSIGHT,
        .price = 0,
        .description = sTCGAllianceInsightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ANCIENT_PROPHECY] =
    {
        .name = _("Ancient Proph"),
        .itemId = ITEM_PACK_TCG_ANCIENT_PROPHECY,
        .price = 0,
        .description = sTCGAncientProphecyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ANCIENT_SANCTUARY] =
    {
        .name = _("Ancient Sanct"),
        .itemId = ITEM_PACK_TCG_ANCIENT_SANCTUARY,
        .price = 0,
        .description = sTCGAncientSanctuaryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_BATTLE_OF_CHAOS] =
    {
        .name = _("Battle of Cha"),
        .itemId = ITEM_PACK_TCG_BATTLE_OF_CHAOS,
        .price = 0,
        .description = sTCGBattleofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_BLAZING_VORTEX] =
    {
        .name = _("Blazing Vorte"),
        .itemId = ITEM_PACK_TCG_BLAZING_VORTEX,
        .price = 0,
        .description = sTCGBlazingVortexDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_BREAKERS_OF_SHADOW] =
    {
        .name = _("Breakers of S"),
        .itemId = ITEM_PACK_TCG_BREAKERS_OF_SHADOW,
        .price = 0,
        .description = sTCGBreakersofShadowDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_BURST_OF_DESTINY] =
    {
        .name = _("Burst of Dest"),
        .itemId = ITEM_PACK_TCG_BURST_OF_DESTINY,
        .price = 0,
        .description = sTCGBurstofDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CHAOS_IMPACT] =
    {
        .name = _("Chaos Impact"),
        .itemId = ITEM_PACK_TCG_CHAOS_IMPACT,
        .price = 0,
        .description = sTCGChaosImpactDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CIRCUIT_BREAK] =
    {
        .name = _("Circuit Break"),
        .itemId = ITEM_PACK_TCG_CIRCUIT_BREAK,
        .price = 0,
        .description = sTCGCircuitBreakDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CLASH_OF_REBELLIONS] =
    {
        .name = _("Clash of Rebe"),
        .itemId = ITEM_PACK_TCG_CLASH_OF_REBELLIONS,
        .price = 0,
        .description = sTCGClashofRebellionsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CODE_OF_THE_DUELIST] =
    {
        .name = _("Code of the D"),
        .itemId = ITEM_PACK_TCG_CODE_OF_THE_DUELIST,
        .price = 0,
        .description = sTCGCodeoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_COSMO_BLAZER] =
    {
        .name = _("Cosmo Blazer"),
        .itemId = ITEM_PACK_TCG_COSMO_BLAZER,
        .price = 0,
        .description = sTCGCosmoBlazerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CRIMSON_CRISIS] =
    {
        .name = _("Crimson Crisi"),
        .itemId = ITEM_PACK_TCG_CRIMSON_CRISIS,
        .price = 0,
        .description = sTCGCrimsonCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CROSSED_SOULS] =
    {
        .name = _("Crossed Souls"),
        .itemId = ITEM_PACK_TCG_CROSSED_SOULS,
        .price = 0,
        .description = sTCGCrossedSoulsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CROSSROADS_OF_CHAOS] =
    {
        .name = _("Crossroads of"),
        .itemId = ITEM_PACK_TCG_CROSSROADS_OF_CHAOS,
        .price = 0,
        .description = sTCGCrossroadsofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CYBER_DRAGON_REVOLUTION_STRUCTURE_DECK] =
    {
        .name = _("Cyber Dragon "),
        .itemId = ITEM_PACK_TCG_CYBER_DRAGON_REVOLUTION_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGCyberDragonRevolutionStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CYBERDARK_IMPACT] =
    {
        .name = _("Cyberdark Imp"),
        .itemId = ITEM_PACK_TCG_CYBERDARK_IMPACT,
        .price = 0,
        .description = sTCGCyberdarkImpactDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CYBERNETIC_HORIZON] =
    {
        .name = _("Cybernetic Ho"),
        .itemId = ITEM_PACK_TCG_CYBERNETIC_HORIZON,
        .price = 0,
        .description = sTCGCyberneticHorizonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CYBERNETIC_REVOLUTION] =
    {
        .name = _("Cybernetic Re"),
        .itemId = ITEM_PACK_TCG_CYBERNETIC_REVOLUTION,
        .price = 0,
        .description = sTCGCyberneticRevolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_CYBERSTORM_ACCESS] =
    {
        .name = _("Cyberstorm Ac"),
        .itemId = ITEM_PACK_TCG_CYBERSTORM_ACCESS,
        .price = 0,
        .description = sTCGCyberstormAccessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DARK_CRISIS] =
    {
        .name = _("Dark Crisis"),
        .itemId = ITEM_PACK_TCG_DARK_CRISIS,
        .price = 0,
        .description = sTCGDarkCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DARK_LEGION_STARTER_DECK] =
    {
        .name = _("Dark Legion S"),
        .itemId = ITEM_PACK_TCG_DARK_LEGION_STARTER_DECK,
        .price = 0,
        .description = sTCGDarkLegionStarterDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DARK_NEOSTORM] =
    {
        .name = _("Dark Neostorm"),
        .itemId = ITEM_PACK_TCG_DARK_NEOSTORM,
        .price = 0,
        .description = sTCGDarkNeostormDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DARKWING_BLAST] =
    {
        .name = _("Darkwing Blas"),
        .itemId = ITEM_PACK_TCG_DARKWING_BLAST,
        .price = 0,
        .description = sTCGDarkwingBlastDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DAWN_OF_MAJESTY] =
    {
        .name = _("Dawn of Majes"),
        .itemId = ITEM_PACK_TCG_DAWN_OF_MAJESTY,
        .price = 0,
        .description = sTCGDawnofMajestyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DIMENSION_FORCE] =
    {
        .name = _("Dimension For"),
        .itemId = ITEM_PACK_TCG_DIMENSION_FORCE,
        .price = 0,
        .description = sTCGDimensionForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DIMENSION_OF_CHAOS] =
    {
        .name = _("Dimension of "),
        .itemId = ITEM_PACK_TCG_DIMENSION_OF_CHAOS,
        .price = 0,
        .description = sTCGDimensionofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DINOSMASHER_S_FURY_STRUCTURE_DECK] =
    {
        .name = _("Dinosmasher's"),
        .itemId = ITEM_PACK_TCG_DINOSMASHER_S_FURY_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGDinosmashersFuryStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DRAGONS_COLLIDE_STRUCTURE_DECK] =
    {
        .name = _("Dragons Colli"),
        .itemId = ITEM_PACK_TCG_DRAGONS_COLLIDE_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGDragonsCollideStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DRAGUNITY_LEGION_STRUCTURE_DECK] =
    {
        .name = _("Dragunity Leg"),
        .itemId = ITEM_PACK_TCG_DRAGUNITY_LEGION_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGDragunityLegionStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DUELIST_ALLIANCE] =
    {
        .name = _("Duelist Allia"),
        .itemId = ITEM_PACK_TCG_DUELIST_ALLIANCE,
        .price = 0,
        .description = sTCGDuelistAllianceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DUELIST_NEXUS] =
    {
        .name = _("Duelist Nexus"),
        .itemId = ITEM_PACK_TCG_DUELIST_NEXUS,
        .price = 0,
        .description = sTCGDuelistNexusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DUELIST_REVOLUTION] =
    {
        .name = _("Duelist Revol"),
        .itemId = ITEM_PACK_TCG_DUELIST_REVOLUTION,
        .price = 0,
        .description = sTCGDuelistRevolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_DUELIST_S_ADVANCE] =
    {
        .name = _("Duelist's Adv"),
        .itemId = ITEM_PACK_TCG_DUELIST_S_ADVANCE,
        .price = 0,
        .description = sTCGDuelistsAdvanceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_EGYPTIAN_GOD_DECK_OBELISK_THE_TORMENTOR] =
    {
        .name = _("Egyptian God "),
        .itemId = ITEM_PACK_TCG_EGYPTIAN_GOD_DECK_OBELISK_THE_TORMENTOR,
        .price = 0,
        .description = sTCGEgyptianGodDeckObelisktheTormentorDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_EGYPTIAN_GOD_DECK_SLIFER_THE_SKY_DRAGON] =
    {
        .name = _("Egyptian God "),
        .itemId = ITEM_PACK_TCG_EGYPTIAN_GOD_DECK_SLIFER_THE_SKY_DRAGON,
        .price = 0,
        .description = sTCGEgyptianGodDeckSlifertheSkyDragonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ELEMENTAL_ENERGY] =
    {
        .name = _("Elemental Ene"),
        .itemId = ITEM_PACK_TCG_ELEMENTAL_ENERGY,
        .price = 0,
        .description = sTCGElementalEnergyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_EMPEROR_OF_DARKNESS_STRUCTURE_DECK] =
    {
        .name = _("Emperor of Da"),
        .itemId = ITEM_PACK_TCG_EMPEROR_OF_DARKNESS_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGEmperorofDarknessStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ENEMY_OF_JUSTICE] =
    {
        .name = _("Enemy of Just"),
        .itemId = ITEM_PACK_TCG_ENEMY_OF_JUSTICE,
        .price = 0,
        .description = sTCGEnemyofJusticeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ETERNITY_CODE] =
    {
        .name = _("Eternity Code"),
        .itemId = ITEM_PACK_TCG_ETERNITY_CODE,
        .price = 0,
        .description = sTCGEternityCodeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_EXTREME_FORCE] =
    {
        .name = _("Extreme Force"),
        .itemId = ITEM_PACK_TCG_EXTREME_FORCE,
        .price = 0,
        .description = sTCGExtremeForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_EXTREME_VICTORY] =
    {
        .name = _("Extreme Victo"),
        .itemId = ITEM_PACK_TCG_EXTREME_VICTORY,
        .price = 0,
        .description = sTCGExtremeVictoryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_FLAMES_OF_DESTRUCTION] =
    {
        .name = _("Flames of Des"),
        .itemId = ITEM_PACK_TCG_FLAMES_OF_DESTRUCTION,
        .price = 0,
        .description = sTCGFlamesofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_FLAMING_ETERNITY] =
    {
        .name = _("Flaming Etern"),
        .itemId = ITEM_PACK_TCG_FLAMING_ETERNITY,
        .price = 0,
        .description = sTCGFlamingEternityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_FORCE_OF_THE_BREAKER] =
    {
        .name = _("Force of the "),
        .itemId = ITEM_PACK_TCG_FORCE_OF_THE_BREAKER,
        .price = 0,
        .description = sTCGForceoftheBreakerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_GALACTIC_OVERLORD] =
    {
        .name = _("Galactic Over"),
        .itemId = ITEM_PACK_TCG_GALACTIC_OVERLORD,
        .price = 0,
        .description = sTCGGalacticOverlordDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_GATES_OF_THE_UNDERWORLD_STRUCTURE_DECK] =
    {
        .name = _("Gates of the "),
        .itemId = ITEM_PACK_TCG_GATES_OF_THE_UNDERWORLD_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGGatesoftheUnderworldStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_GEARGIA_RAMPAGE_STRUCTURE_DECK] =
    {
        .name = _("Geargia Rampa"),
        .itemId = ITEM_PACK_TCG_GEARGIA_RAMPAGE_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGGeargiaRampageStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_GENERATION_FORCE] =
    {
        .name = _("Generation Fo"),
        .itemId = ITEM_PACK_TCG_GENERATION_FORCE,
        .price = 0,
        .description = sTCGGenerationForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_GLADIATOR_S_ASSAULT] =
    {
        .name = _("Gladiator's A"),
        .itemId = ITEM_PACK_TCG_GLADIATOR_S_ASSAULT,
        .price = 0,
        .description = sTCGGladiatorsAssaultDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_HERO_STRIKE_STRUCTURE_DECK] =
    {
        .name = _("HERO Strike S"),
        .itemId = ITEM_PACK_TCG_HERO_STRIKE_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGHEROStrikeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_IGNITION_ASSAULT] =
    {
        .name = _("Ignition Assa"),
        .itemId = ITEM_PACK_TCG_IGNITION_ASSAULT,
        .price = 0,
        .description = sTCGIgnitionAssaultDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_INVASION_OF_CHAOS] =
    {
        .name = _("Invasion of C"),
        .itemId = ITEM_PACK_TCG_INVASION_OF_CHAOS,
        .price = 0,
        .description = sTCGInvasionofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_INVASION_VENGEANCE] =
    {
        .name = _("Invasion: Ven"),
        .itemId = ITEM_PACK_TCG_INVASION_VENGEANCE,
        .price = 0,
        .description = sTCGInvasionVengeanceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_JUDGMENT_OF_THE_LIGHT] =
    {
        .name = _("Judgment of t"),
        .itemId = ITEM_PACK_TCG_JUDGMENT_OF_THE_LIGHT,
        .price = 0,
        .description = sTCGJudgmentoftheLightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LABYRINTH_OF_NIGHTMARE] =
    {
        .name = _("Labyrinth of "),
        .itemId = ITEM_PACK_TCG_LABYRINTH_OF_NIGHTMARE,
        .price = 0,
        .description = sTCGLabyrinthofNightmareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LEGACY_OF_DARKNESS] =
    {
        .name = _("Legacy of Dar"),
        .itemId = ITEM_PACK_TCG_LEGACY_OF_DARKNESS,
        .price = 0,
        .description = sTCGLegacyofDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LEGACY_OF_DESTRUCTION] =
    {
        .name = _("Legacy of Des"),
        .itemId = ITEM_PACK_TCG_LEGACY_OF_DESTRUCTION,
        .price = 0,
        .description = sTCGLegacyofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LEGACY_OF_THE_VALIANT] =
    {
        .name = _("Legacy of the"),
        .itemId = ITEM_PACK_TCG_LEGACY_OF_THE_VALIANT,
        .price = 0,
        .description = sTCGLegacyoftheValiantDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LEGEND_OF_BLUE_EYES_WHITE_DRAGON] =
    {
        .name = _("Legend of Blu"),
        .itemId = ITEM_PACK_TCG_LEGEND_OF_BLUE_EYES_WHITE_DRAGON,
        .price = 0,
        .description = sTCGLegendofBlueEyesWhiteDragonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LIGHT_OF_DESTRUCTION] =
    {
        .name = _("Light of Dest"),
        .itemId = ITEM_PACK_TCG_LIGHT_OF_DESTRUCTION,
        .price = 0,
        .description = sTCGLightofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LIGHTNING_OVERDRIVE] =
    {
        .name = _("Lightning Ove"),
        .itemId = ITEM_PACK_TCG_LIGHTNING_OVERDRIVE,
        .price = 0,
        .description = sTCGLightningOverdriveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LORD_OF_THE_TACHYON_GALAXY] =
    {
        .name = _("Lord of the T"),
        .itemId = ITEM_PACK_TCG_LORD_OF_THE_TACHYON_GALAXY,
        .price = 0,
        .description = sTCGLordoftheTachyonGalaxyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_LOST_SANCTUARY_STRUCTURE_DECK] =
    {
        .name = _("Lost Sanctuar"),
        .itemId = ITEM_PACK_TCG_LOST_SANCTUARY_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGLostSanctuaryStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_MACHINA_MAYHEM_STRUCTURE_DECK] =
    {
        .name = _("Machina Mayhe"),
        .itemId = ITEM_PACK_TCG_MACHINA_MAYHEM_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGMachinaMayhemStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_MACHINE_REACTOR_STRUCTURE_DECK] =
    {
        .name = _("Machine React"),
        .itemId = ITEM_PACK_TCG_MACHINE_REACTOR_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGMachineReactorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_MAGICIAN_S_FORCE] =
    {
        .name = _("Magician's Fo"),
        .itemId = ITEM_PACK_TCG_MAGICIAN_S_FORCE,
        .price = 0,
        .description = sTCGMagiciansForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_MASTER_OF_PENDULUM_STRUCTURE_DECK] =
    {
        .name = _("Master of Pen"),
        .itemId = ITEM_PACK_TCG_MASTER_OF_PENDULUM_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGMasterofPendulumStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_MAXIMUM_CRISIS] =
    {
        .name = _("Maximum Crisi"),
        .itemId = ITEM_PACK_TCG_MAXIMUM_CRISIS,
        .price = 0,
        .description = sTCGMaximumCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_METAL_RAIDERS] =
    {
        .name = _("Metal Raiders"),
        .itemId = ITEM_PACK_TCG_METAL_RAIDERS,
        .price = 0,
        .description = sTCGMetalRaidersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ONSLAUGHT_OF_THE_FIRE_KINGS_STRUCTURE_DECK] =
    {
        .name = _("Onslaught of "),
        .itemId = ITEM_PACK_TCG_ONSLAUGHT_OF_THE_FIRE_KINGS_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGOnslaughtoftheFireKingsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ORDER_OF_CHAOS] =
    {
        .name = _("Order of Chao"),
        .itemId = ITEM_PACK_TCG_ORDER_OF_CHAOS,
        .price = 0,
        .description = sTCGOrderofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PENDULUM_DOMINATION_STRUCTURE_DECK] =
    {
        .name = _("Pendulum Domi"),
        .itemId = ITEM_PACK_TCG_PENDULUM_DOMINATION_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGPendulumDominationStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHANTOM_DARKNESS] =
    {
        .name = _("Phantom Darkn"),
        .itemId = ITEM_PACK_TCG_PHANTOM_DARKNESS,
        .price = 0,
        .description = sTCGPhantomDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHANTOM_NIGHTMARE] =
    {
        .name = _("Phantom Night"),
        .itemId = ITEM_PACK_TCG_PHANTOM_NIGHTMARE,
        .price = 0,
        .description = sTCGPhantomNightmareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHANTOM_RAGE] =
    {
        .name = _("Phantom Rage"),
        .itemId = ITEM_PACK_TCG_PHANTOM_RAGE,
        .price = 0,
        .description = sTCGPhantomRageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHARAOH_S_SERVANT] =
    {
        .name = _("Pharaoh's Ser"),
        .itemId = ITEM_PACK_TCG_PHARAOH_S_SERVANT,
        .price = 0,
        .description = sTCGPharaohsServantDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHARAONIC_GUARDIAN] =
    {
        .name = _("Pharaonic Gua"),
        .itemId = ITEM_PACK_TCG_PHARAONIC_GUARDIAN,
        .price = 0,
        .description = sTCGPharaonicGuardianDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHOTON_HYPERNOVA] =
    {
        .name = _("Photon Hypern"),
        .itemId = ITEM_PACK_TCG_PHOTON_HYPERNOVA,
        .price = 0,
        .description = sTCGPhotonHypernovaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PHOTON_SHOCKWAVE] =
    {
        .name = _("Photon Shockw"),
        .itemId = ITEM_PACK_TCG_PHOTON_SHOCKWAVE,
        .price = 0,
        .description = sTCGPhotonShockwaveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_POWER_OF_THE_DUELIST] =
    {
        .name = _("Power of the "),
        .itemId = ITEM_PACK_TCG_POWER_OF_THE_DUELIST,
        .price = 0,
        .description = sTCGPoweroftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_POWER_OF_THE_ELEMENTS] =
    {
        .name = _("Power of the "),
        .itemId = ITEM_PACK_TCG_POWER_OF_THE_ELEMENTS,
        .price = 0,
        .description = sTCGPoweroftheElementsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_PRIMAL_ORIGIN] =
    {
        .name = _("Primal Origin"),
        .itemId = ITEM_PACK_TCG_PRIMAL_ORIGIN,
        .price = 0,
        .description = sTCGPrimalOriginDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RAGE_OF_THE_ABYSS] =
    {
        .name = _("Rage of the A"),
        .itemId = ITEM_PACK_TCG_RAGE_OF_THE_ABYSS,
        .price = 0,
        .description = sTCGRageoftheAbyssDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RAGING_BATTLE] =
    {
        .name = _("Raging Battle"),
        .itemId = ITEM_PACK_TCG_RAGING_BATTLE,
        .price = 0,
        .description = sTCGRagingBattleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RAGING_TEMPEST] =
    {
        .name = _("Raging Tempes"),
        .itemId = ITEM_PACK_TCG_RAGING_TEMPEST,
        .price = 0,
        .description = sTCGRagingTempestDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_REALM_OF_LIGHT_STRUCTURE_DECK] =
    {
        .name = _("Realm of Ligh"),
        .itemId = ITEM_PACK_TCG_REALM_OF_LIGHT_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGRealmofLightStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_REALM_OF_THE_SEA_EMPEROR_STRUCTURE_DECK] =
    {
        .name = _("Realm of the "),
        .itemId = ITEM_PACK_TCG_REALM_OF_THE_SEA_EMPEROR_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGRealmoftheSeaEmperorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RETURN_OF_THE_DUELIST] =
    {
        .name = _("Return of the"),
        .itemId = ITEM_PACK_TCG_RETURN_OF_THE_DUELIST,
        .price = 0,
        .description = sTCGReturnoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RISE_OF_DESTINY] =
    {
        .name = _("Rise of Desti"),
        .itemId = ITEM_PACK_TCG_RISE_OF_DESTINY,
        .price = 0,
        .description = sTCGRiseofDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RISE_OF_THE_DRAGON_LORDS_STRUCTURE_DECK] =
    {
        .name = _("Rise of the D"),
        .itemId = ITEM_PACK_TCG_RISE_OF_THE_DRAGON_LORDS_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGRiseoftheDragonLordsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RISE_OF_THE_DUELIST] =
    {
        .name = _("Rise of the D"),
        .itemId = ITEM_PACK_TCG_RISE_OF_THE_DUELIST,
        .price = 0,
        .description = sTCGRiseoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RISE_OF_THE_TRUE_DRAGONS_STRUCTURE_DECK] =
    {
        .name = _("Rise of the T"),
        .itemId = ITEM_PACK_TCG_RISE_OF_THE_TRUE_DRAGONS_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGRiseoftheTrueDragonsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_RISING_RAMPAGE] =
    {
        .name = _("Rising Rampag"),
        .itemId = ITEM_PACK_TCG_RISING_RAMPAGE,
        .price = 0,
        .description = sTCGRisingRampageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SABER_FORCE_STARTER_DECK] =
    {
        .name = _("Saber Force S"),
        .itemId = ITEM_PACK_TCG_SABER_FORCE_STARTER_DECK,
        .price = 0,
        .description = sTCGSaberForceStarterDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SAGA_OF_BLUE_EYES_WHITE_DRAGON_STRUCTURE_DECK] =
    {
        .name = _("Saga of Blue-"),
        .itemId = ITEM_PACK_TCG_SAGA_OF_BLUE_EYES_WHITE_DRAGON_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGSagaofBlueEyesWhiteDragonStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SAMURAI_WARLORDS_STRUCTURE_DECK] =
    {
        .name = _("Samurai Warlo"),
        .itemId = ITEM_PACK_TCG_SAMURAI_WARLORDS_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGSamuraiWarlordsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SAVAGE_STRIKE] =
    {
        .name = _("Savage Strike"),
        .itemId = ITEM_PACK_TCG_SAVAGE_STRIKE,
        .price = 0,
        .description = sTCGSavageStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SECRETS_OF_ETERNITY] =
    {
        .name = _("Secrets of Et"),
        .itemId = ITEM_PACK_TCG_SECRETS_OF_ETERNITY,
        .price = 0,
        .description = sTCGSecretsofEternityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SHADOW_SPECTERS] =
    {
        .name = _("Shadow Specte"),
        .itemId = ITEM_PACK_TCG_SHADOW_SPECTERS,
        .price = 0,
        .description = sTCGShadowSpectersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SHADOW_OF_INFINITY] =
    {
        .name = _("Shadow of Inf"),
        .itemId = ITEM_PACK_TCG_SHADOW_OF_INFINITY,
        .price = 0,
        .description = sTCGShadowofInfinityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SHINING_VICTORIES] =
    {
        .name = _("Shining Victo"),
        .itemId = ITEM_PACK_TCG_SHINING_VICTORIES,
        .price = 0,
        .description = sTCGShiningVictoriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SOUL_FUSION] =
    {
        .name = _("Soul Fusion"),
        .itemId = ITEM_PACK_TCG_SOUL_FUSION,
        .price = 0,
        .description = sTCGSoulFusionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SOUL_OF_THE_DUELIST] =
    {
        .name = _("Soul of the D"),
        .itemId = ITEM_PACK_TCG_SOUL_OF_THE_DUELIST,
        .price = 0,
        .description = sTCGSouloftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SPELL_RULER] =
    {
        .name = _("Spell Ruler"),
        .itemId = ITEM_PACK_TCG_SPELL_RULER,
        .price = 0,
        .description = sTCGSpellRulerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SPELLCASTER_S_COMMAND_STRUCTURE_DECK] =
    {
        .name = _("Spellcaster's"),
        .itemId = ITEM_PACK_TCG_SPELLCASTER_S_COMMAND_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGSpellcastersCommandStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARDUST_OVERDRIVE] =
    {
        .name = _("Stardust Over"),
        .itemId = ITEM_PACK_TCG_STARDUST_OVERDRIVE,
        .price = 0,
        .description = sTCGStardustOverdriveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARSTRIKE_BLAST] =
    {
        .name = _("Starstrike Bl"),
        .itemId = ITEM_PACK_TCG_STARSTRIKE_BLAST,
        .price = 0,
        .description = sTCGStarstrikeBlastDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_2006] =
    {
        .name = _("Starter Deck "),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_2006,
        .price = 0,
        .description = sTCGStarterDeck2006Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_CODEBREAKER] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_CODEBREAKER,
        .price = 0,
        .description = sTCGStarterDeckCodebreakerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_DAWN_OF_THE_XYZ] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_DAWN_OF_THE_XYZ,
        .price = 0,
        .description = sTCGStarterDeckDawnoftheXyzDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_DUELIST_TOOLBOX] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_DUELIST_TOOLBOX,
        .price = 0,
        .description = sTCGStarterDeckDuelistToolboxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_JADEN_YUKI] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_JADEN_YUKI,
        .price = 0,
        .description = sTCGStarterDeckJadenYukiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_JOEY] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_JOEY,
        .price = 0,
        .description = sTCGStarterDeckJoeyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_KAIBA] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_KAIBA,
        .price = 0,
        .description = sTCGStarterDeckKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_KAIBA_EVOLUTION] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_KAIBA_EVOLUTION,
        .price = 0,
        .description = sTCGStarterDeckKaibaEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_KAIBA_RELOADED] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_KAIBA_RELOADED,
        .price = 0,
        .description = sTCGStarterDeckKaibaReloadedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_LINK_STRIKE] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_LINK_STRIKE,
        .price = 0,
        .description = sTCGStarterDeckLinkStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_PEGASUS] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_PEGASUS,
        .price = 0,
        .description = sTCGStarterDeckPegasusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_SYRUS_TRUESDALE] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_SYRUS_TRUESDALE,
        .price = 0,
        .description = sTCGStarterDeckSyrusTruesdaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_XYZ_SYMPHONY] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_XYZ_SYMPHONY,
        .price = 0,
        .description = sTCGStarterDeckXyzSymphonyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YU_GI_OH_5D_S] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YU_GI_OH_5D_S,
        .price = 0,
        .description = sTCGStarterDeckYuGiOh5DsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YU_GI_OH_5D_S_2009] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YU_GI_OH_5D_S_2009,
        .price = 0,
        .description = sTCGStarterDeckYuGiOh5Ds2009Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YUGI] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YUGI,
        .price = 0,
        .description = sTCGStarterDeckYugiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YUGI_EVOLUTION] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YUGI_EVOLUTION,
        .price = 0,
        .description = sTCGStarterDeckYugiEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YUGI_RELOADED] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YUGI_RELOADED,
        .price = 0,
        .description = sTCGStarterDeckYugiReloadedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STARTER_DECK_YUYA] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_TCG_STARTER_DECK_YUYA,
        .price = 0,
        .description = sTCGStarterDeckYuyaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STORM_OF_RAGNAROK] =
    {
        .name = _("Storm of Ragn"),
        .itemId = ITEM_PACK_TCG_STORM_OF_RAGNAROK,
        .price = 0,
        .description = sTCGStormofRagnarokDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRIKE_OF_NEOS] =
    {
        .name = _("Strike of Neo"),
        .itemId = ITEM_PACK_TCG_STRIKE_OF_NEOS,
        .price = 0,
        .description = sTCGStrikeofNeosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_ALBAZ_STRIKE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_ALBAZ_STRIKE,
        .price = 0,
        .description = sTCGStructureDeckAlbazStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_BEWARE_OF_TRAPTRIX] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_BEWARE_OF_TRAPTRIX,
        .price = 0,
        .description = sTCGStructureDeckBewareofTraptrixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_BLAZE_OF_DESTRUCTION] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_BLAZE_OF_DESTRUCTION,
        .price = 0,
        .description = sTCGStructureDeckBlazeofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_BLUE_EYES_WHITE_DESTINY] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_BLUE_EYES_WHITE_DESTINY,
        .price = 0,
        .description = sTCGStructureDeckBlueEyesWhiteDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_CYBER_STRIKE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_CYBER_STRIKE,
        .price = 0,
        .description = sTCGStructureDeckCyberStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_CYBERSE_LINK] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_CYBERSE_LINK,
        .price = 0,
        .description = sTCGStructureDeckCyberseLinkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_DARK_WORLD] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_DARK_WORLD,
        .price = 0,
        .description = sTCGStructureDeckDarkWorldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_DINOSAUR_S_RAGE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_DINOSAUR_S_RAGE,
        .price = 0,
        .description = sTCGStructureDeckDinosaursRageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_DRAGON_S_ROAR] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_DRAGON_S_ROAR,
        .price = 0,
        .description = sTCGStructureDeckDragonsRoarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_FIRE_KINGS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_FIRE_KINGS,
        .price = 0,
        .description = sTCGStructureDeckFireKingsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_FREEZING_CHAINS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_FREEZING_CHAINS,
        .price = 0,
        .description = sTCGStructureDeckFreezingChainsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_FURY_FROM_THE_DEEP] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_FURY_FROM_THE_DEEP,
        .price = 0,
        .description = sTCGStructureDeckFuryfromtheDeepDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_INVINCIBLE_FORTRESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_INVINCIBLE_FORTRESS,
        .price = 0,
        .description = sTCGStructureDeckInvincibleFortressDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_LAIR_OF_DARKNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_LAIR_OF_DARKNESS,
        .price = 0,
        .description = sTCGStructureDeckLairofDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_LEGEND_OF_THE_CRYSTAL_BEASTS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_LEGEND_OF_THE_CRYSTAL_BEASTS,
        .price = 0,
        .description = sTCGStructureDeckLegendoftheCrystalBeastsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_LORD_OF_THE_STORM] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_LORD_OF_THE_STORM,
        .price = 0,
        .description = sTCGStructureDeckLordoftheStormDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_MACHINE_RE_VOLT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_MACHINE_RE_VOLT,
        .price = 0,
        .description = sTCGStructureDeckMachineReVoltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_MECHANIZED_MADNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_MECHANIZED_MADNESS,
        .price = 0,
        .description = sTCGStructureDeckMechanizedMadnessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_ORDER_OF_THE_SPELLCASTERS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_ORDER_OF_THE_SPELLCASTERS,
        .price = 0,
        .description = sTCGStructureDeckOrderoftheSpellcastersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_POWERCODE_LINK] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_POWERCODE_LINK,
        .price = 0,
        .description = sTCGStructureDeckPowercodeLinkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_ROKKET_REVOLT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_ROKKET_REVOLT,
        .price = 0,
        .description = sTCGStructureDeckRokketRevoltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SACRED_BEASTS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SACRED_BEASTS,
        .price = 0,
        .description = sTCGStructureDeckSacredBeastsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SETO_KAIBA] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SETO_KAIBA,
        .price = 0,
        .description = sTCGStructureDeckSetoKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SHADDOLL_SHOWDOWN] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SHADDOLL_SHOWDOWN,
        .price = 0,
        .description = sTCGStructureDeckShaddollShowdownDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SOULBURNER] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SOULBURNER,
        .price = 0,
        .description = sTCGStructureDeckSoulburnerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SPELLCASTER_S_JUDGMENT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SPELLCASTER_S_JUDGMENT,
        .price = 0,
        .description = sTCGStructureDeckSpellcastersJudgmentDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_SPIRIT_CHARMERS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_SPIRIT_CHARMERS,
        .price = 0,
        .description = sTCGStructureDeckSpiritCharmersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_THE_CRIMSON_KING] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_THE_CRIMSON_KING,
        .price = 0,
        .description = sTCGStructureDeckTheCrimsonKingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_WARRIOR_S_TRIUMPH] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_WARRIOR_S_TRIUMPH,
        .price = 0,
        .description = sTCGStructureDeckWarriorsTriumphDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_WAVE_OF_LIGHT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_WAVE_OF_LIGHT,
        .price = 0,
        .description = sTCGStructureDeckWaveofLightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_YUGI_MUTO] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_YUGI_MUTO,
        .price = 0,
        .description = sTCGStructureDeckYugiMutoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_ZOMBIE_HORDE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_ZOMBIE_HORDE,
        .price = 0,
        .description = sTCGStructureDeckZombieHordeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_STRUCTURE_DECK_ZOMBIE_MADNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_TCG_STRUCTURE_DECK_ZOMBIE_MADNESS,
        .price = 0,
        .description = sTCGStructureDeckZombieMadnessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SUPER_STARTER_SPACE_TIME_SHOWDOWN] =
    {
        .name = _("Super Starter"),
        .itemId = ITEM_PACK_TCG_SUPER_STARTER_SPACE_TIME_SHOWDOWN,
        .price = 0,
        .description = sTCGSuperStarterSpaceTimeShowdownDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SUPER_STARTER_V_FOR_VICTORY] =
    {
        .name = _("Super Starter"),
        .itemId = ITEM_PACK_TCG_SUPER_STARTER_V_FOR_VICTORY,
        .price = 0,
        .description = sTCGSuperStarterVforVictoryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SUPREME_DARKNESS] =
    {
        .name = _("Supreme Darkn"),
        .itemId = ITEM_PACK_TCG_SUPREME_DARKNESS,
        .price = 0,
        .description = sTCGSupremeDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_SYNCHRON_EXTREME_STRUCTURE_DECK] =
    {
        .name = _("Synchron Extr"),
        .itemId = ITEM_PACK_TCG_SYNCHRON_EXTREME_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGSynchronExtremeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_TACTICAL_EVOLUTION] =
    {
        .name = _("Tactical Evol"),
        .itemId = ITEM_PACK_TCG_TACTICAL_EVOLUTION,
        .price = 0,
        .description = sTCGTacticalEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_DARK_EMPEROR_STRUCTURE_DECK] =
    {
        .name = _("The Dark Empe"),
        .itemId = ITEM_PACK_TCG_THE_DARK_EMPEROR_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGTheDarkEmperorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_DARK_ILLUSION] =
    {
        .name = _("The Dark Illu"),
        .itemId = ITEM_PACK_TCG_THE_DARK_ILLUSION,
        .price = 0,
        .description = sTCGTheDarkIllusionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_DUELIST_GENESIS] =
    {
        .name = _("The Duelist G"),
        .itemId = ITEM_PACK_TCG_THE_DUELIST_GENESIS,
        .price = 0,
        .description = sTCGTheDuelistGenesisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_INFINITE_FORBIDDEN] =
    {
        .name = _("The Infinite "),
        .itemId = ITEM_PACK_TCG_THE_INFINITE_FORBIDDEN,
        .price = 0,
        .description = sTCGTheInfiniteForbiddenDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_LOST_MILLENNIUM] =
    {
        .name = _("The Lost Mill"),
        .itemId = ITEM_PACK_TCG_THE_LOST_MILLENNIUM,
        .price = 0,
        .description = sTCGTheLostMillenniumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_NEW_CHALLENGERS] =
    {
        .name = _("The New Chall"),
        .itemId = ITEM_PACK_TCG_THE_NEW_CHALLENGERS,
        .price = 0,
        .description = sTCGTheNewChallengersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_THE_SHINING_DARKNESS] =
    {
        .name = _("The Shining D"),
        .itemId = ITEM_PACK_TCG_THE_SHINING_DARKNESS,
        .price = 0,
        .description = sTCGTheShiningDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_WARRIORS_STRIKE_STRUCTURE_DECK] =
    {
        .name = _("Warriors' Str"),
        .itemId = ITEM_PACK_TCG_WARRIORS_STRIKE_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGWarriorsStrikeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TCG_ZOMBIE_WORLD_STRUCTURE_DECK] =
    {
        .name = _("Zombie World "),
        .itemId = ITEM_PACK_TCG_ZOMBIE_WORLD_STRUCTURE_DECK,
        .price = 0,
        .description = sTCGZombieWorldStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },


	[ITEM_PACK_YUGI_KAIBA] =
    {
        .name = _("Yugi-Kaiba"),
        .itemId = ITEM_PACK_YUGI_KAIBA,
        .price = 0,
        .description = sYugiKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CRITTER] =
    {
        .name = _("Critter"),
        .itemId = ITEM_PACK_CRITTER,
        .price = 0,
        .description = sCritterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TREASURE] =
    {
        .name = _("Treasure"),
        .itemId = ITEM_PACK_TREASURE,
        .price = 0,
        .description = sTreasureDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_IMPERIAL] =
    {
        .name = _("Imperial"),
        .itemId = ITEM_PACK_IMPERIAL,
        .price = 0,
        .description = sImperialDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANDROID] =
    {
        .name = _("Android"),
        .itemId = ITEM_PACK_ANDROID,
        .price = 0,
        .description = sAndroidDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_JOEY_PEGASUS] =
    {
        .name = _("Joey-Pegasus"),
        .itemId = ITEM_PACK_JOEY_PEGASUS,
        .price = 0,
        .description = sJoeyPegasusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FIBER] =
    {
        .name = _("Fiber"),
        .itemId = ITEM_PACK_FIBER,
        .price = 0,
        .description = sFiberDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YATA] =
    {
        .name = _("Yata"),
        .itemId = ITEM_PACK_YATA,
        .price = 0,
        .description = sYataDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SCIENTIST] =
    {
        .name = _("Scientist"),
        .itemId = ITEM_PACK_SCIENTIST,
        .price = 0,
        .description = sScientistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_VAMPIRE] =
    {
        .name = _("Vampire"),
        .itemId = ITEM_PACK_VAMPIRE,
        .price = 0,
        .description = sVampireDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAOS] =
    {
        .name = _("Chaos"),
        .itemId = ITEM_PACK_CHAOS,
        .price = 0,
        .description = sChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WARRIOR] =
    {
        .name = _("Warrior"),
        .itemId = ITEM_PACK_WARRIOR,
        .price = 0,
        .description = sWarriorDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOAT] =
    {
        .name = _("Goat"),
        .itemId = ITEM_PACK_GOAT,
        .price = 0,
        .description = sGoatDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBER] =
    {
        .name = _("Cyber"),
        .itemId = ITEM_PACK_CYBER,
        .price = 0,
        .description = sCyberDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_REAPER] =
    {
        .name = _("Reaper"),
        .itemId = ITEM_PACK_REAPER,
        .price = 0,
        .description = sReaperDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAOS_RETURN] =
    {
        .name = _("Chaos Return"),
        .itemId = ITEM_PACK_CHAOS_RETURN,
        .price = 0,
        .description = sChaosReturnDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DEMISE] =
    {
        .name = _("Demise"),
        .itemId = ITEM_PACK_DEMISE,
        .price = 0,
        .description = sDemiseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TROOPER] =
    {
        .name = _("Trooper"),
        .itemId = ITEM_PACK_TROOPER,
        .price = 0,
        .description = sTrooperDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ZOMBIE] =
    {
        .name = _("Zombie"),
        .itemId = ITEM_PACK_ZOMBIE,
        .price = 0,
        .description = sZombieDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PERFECT_CIRCLE] =
    {
        .name = _("Perfect Circl"),
        .itemId = ITEM_PACK_PERFECT_CIRCLE,
        .price = 0,
        .description = sPerfectCircleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DAD_RETURN] =
    {
        .name = _("DAD Return"),
        .itemId = ITEM_PACK_DAD_RETURN,
        .price = 0,
        .description = sDADReturnDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GLADIATOR] =
    {
        .name = _("Gladiator"),
        .itemId = ITEM_PACK_GLADIATOR,
        .price = 0,
        .description = sGladiatorDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TELEDAD] =
    {
        .name = _("TeleDAD"),
        .itemId = ITEM_PACK_TELEDAD,
        .price = 0,
        .description = sTeleDADDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CAT] =
    {
        .name = _("Cat"),
        .itemId = ITEM_PACK_CAT,
        .price = 0,
        .description = sCatDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EDISON] =
    {
        .name = _("Edison"),
        .itemId = ITEM_PACK_EDISON,
        .price = 0,
        .description = sEdisonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FROG] =
    {
        .name = _("Frog"),
        .itemId = ITEM_PACK_FROG,
        .price = 0,
        .description = sFrogDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARSTRIKE] =
    {
        .name = _("Starstrike"),
        .itemId = ITEM_PACK_STARSTRIKE,
        .price = 0,
        .description = sStarstrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TENGU] =
    {
        .name = _("Tengu"),
        .itemId = ITEM_PACK_TENGU,
        .price = 0,
        .description = sTenguDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DINO_RABBIT] =
    {
        .name = _("Dino Rabbit"),
        .itemId = ITEM_PACK_DINO_RABBIT,
        .price = 0,
        .description = sDinoRabbitDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WIND_UP] =
    {
        .name = _("Wind-Up"),
        .itemId = ITEM_PACK_WIND_UP,
        .price = 0,
        .description = sWindUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MIAMI] =
    {
        .name = _("Miami"),
        .itemId = ITEM_PACK_MIAMI,
        .price = 0,
        .description = sMiamiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MEADOWLANDS] =
    {
        .name = _("Meadowlands"),
        .itemId = ITEM_PACK_MEADOWLANDS,
        .price = 0,
        .description = sMeadowlandsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BABY_RULER] =
    {
        .name = _("Baby Ruler"),
        .itemId = ITEM_PACK_BABY_RULER,
        .price = 0,
        .description = sBabyRulerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAVINE_RULER] =
    {
        .name = _("Ravine Ruler"),
        .itemId = ITEM_PACK_RAVINE_RULER,
        .price = 0,
        .description = sRavineRulerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FIRE_WATER] =
    {
        .name = _("Fire-Water"),
        .itemId = ITEM_PACK_FIRE_WATER,
        .price = 0,
        .description = sFireWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HAT] =
    {
        .name = _("HAT"),
        .itemId = ITEM_PACK_HAT,
        .price = 0,
        .description = sHATDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_VEGAS] =
    {
        .name = _("Vegas"),
        .itemId = ITEM_PACK_VEGAS,
        .price = 0,
        .description = sVegasDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },
};

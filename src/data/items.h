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

	[ITEM_PACK_2_PLAYER_STARTER_DECK_YUYA_DECLAN] =
    {
        .name = _("2-Player Star"),
        .itemId = ITEM_PACK_2_PLAYER_STARTER_DECK_YUYA_DECLAN,
        .price = 0,
        .description = s2PlayerStarterDeckYuyaDeclanDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2_PLAYER_STARTER_SET] =
    {
        .name = _("2-Player Star"),
        .itemId = ITEM_PACK_2_PLAYER_STARTER_SET,
        .price = 0,
        .description = s2PlayerStarterSetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2013_COLLECTIBLE_TINS_WAVE_1] =
    {
        .name = _("2013 Collecti"),
        .itemId = ITEM_PACK_2013_COLLECTIBLE_TINS_WAVE_1,
        .price = 0,
        .description = s2013CollectibleTinsWave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2013_COLLECTIBLE_TINS_WAVE_2] =
    {
        .name = _("2013 Collecti"),
        .itemId = ITEM_PACK_2013_COLLECTIBLE_TINS_WAVE_2,
        .price = 0,
        .description = s2013CollectibleTinsWave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2014_MEGA_TIN_MEGA_PACK] =
    {
        .name = _("2014 Mega-Tin"),
        .itemId = ITEM_PACK_2014_MEGA_TIN_MEGA_PACK,
        .price = 0,
        .description = s2014MegaTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2014_MEGA_TINS] =
    {
        .name = _("2014 Mega-Tin"),
        .itemId = ITEM_PACK_2014_MEGA_TINS,
        .price = 0,
        .description = s2014MegaTinsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2015_MEGA_TIN_MEGA_PACK] =
    {
        .name = _("2015 Mega-Tin"),
        .itemId = ITEM_PACK_2015_MEGA_TIN_MEGA_PACK,
        .price = 0,
        .description = s2015MegaTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2015_MEGA_TINS] =
    {
        .name = _("2015 Mega-Tin"),
        .itemId = ITEM_PACK_2015_MEGA_TINS,
        .price = 0,
        .description = s2015MegaTinsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2016_MEGA_TIN_MEGA_PACK] =
    {
        .name = _("2016 Mega-Tin"),
        .itemId = ITEM_PACK_2016_MEGA_TIN_MEGA_PACK,
        .price = 0,
        .description = s2016MegaTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2016_MEGA_TINS] =
    {
        .name = _("2016 Mega-Tin"),
        .itemId = ITEM_PACK_2016_MEGA_TINS,
        .price = 0,
        .description = s2016MegaTinsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2017_MEGA_TIN_MEGA_PACK] =
    {
        .name = _("2017 Mega-Tin"),
        .itemId = ITEM_PACK_2017_MEGA_TIN_MEGA_PACK,
        .price = 0,
        .description = s2017MegaTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2017_MEGA_TINS] =
    {
        .name = _("2017 Mega-Tin"),
        .itemId = ITEM_PACK_2017_MEGA_TINS,
        .price = 0,
        .description = s2017MegaTinsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2018_MEGA_TIN_MEGA_PACK] =
    {
        .name = _("2018 Mega-Tin"),
        .itemId = ITEM_PACK_2018_MEGA_TIN_MEGA_PACK,
        .price = 0,
        .description = s2018MegaTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2018_MEGA_TINS] =
    {
        .name = _("2018 Mega-Tin"),
        .itemId = ITEM_PACK_2018_MEGA_TINS,
        .price = 0,
        .description = s2018MegaTinsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2019_GOLD_SARCOPHAGUS_TIN] =
    {
        .name = _("2019 Gold Sar"),
        .itemId = ITEM_PACK_2019_GOLD_SARCOPHAGUS_TIN,
        .price = 0,
        .description = s2019GoldSarcophagusTinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2019_GOLD_SARCOPHAGUS_TIN_MEGA_PACK] =
    {
        .name = _("2019 Gold Sar"),
        .itemId = ITEM_PACK_2019_GOLD_SARCOPHAGUS_TIN_MEGA_PACK,
        .price = 0,
        .description = s2019GoldSarcophagusTinMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2020_TIN_OF_LOST_MEMORIES] =
    {
        .name = _("2020 Tin of L"),
        .itemId = ITEM_PACK_2020_TIN_OF_LOST_MEMORIES,
        .price = 0,
        .description = s2020TinofLostMemoriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2020_TIN_OF_LOST_MEMORIES_MEGA_PACK] =
    {
        .name = _("2020 Tin of L"),
        .itemId = ITEM_PACK_2020_TIN_OF_LOST_MEMORIES_MEGA_PACK,
        .price = 0,
        .description = s2020TinofLostMemoriesMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2021_TIN_OF_ANCIENT_BATTLES] =
    {
        .name = _("2021 Tin of A"),
        .itemId = ITEM_PACK_2021_TIN_OF_ANCIENT_BATTLES,
        .price = 0,
        .description = s2021TinofAncientBattlesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_2022_TIN_OF_THE_PHARAOH_S_GODS] =
    {
        .name = _("2022 Tin of t"),
        .itemId = ITEM_PACK_2022_TIN_OF_THE_PHARAOH_S_GODS,
        .price = 0,
        .description = s2022TinofthePharaohsGodsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_RARITY_COLLECTION] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_RARITY_COLLECTION,
        .price = 0,
        .description = s25thAnniversaryRarityCollectionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_RARITY_COLLECTION_II] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_RARITY_COLLECTION_II,
        .price = 0,
        .description = s25thAnniversaryRarityCollectionIIDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_HEROES] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_HEROES,
        .price = 0,
        .description = s25thAnniversaryTinDuelingHeroesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_HEROES_MEGA_PACK] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_HEROES_MEGA_PACK,
        .price = 0,
        .description = s25thAnniversaryTinDuelingHeroesMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_MIRRORS] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_TIN_DUELING_MIRRORS,
        .price = 0,
        .description = s25thAnniversaryTinDuelingMirrorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_25TH_ANNIVERSARY_ULTIMATE_KAIBA_SET] =
    {
        .name = _("25th Annivers"),
        .itemId = ITEM_PACK_25TH_ANNIVERSARY_ULTIMATE_KAIBA_SET,
        .price = 0,
        .description = s25thAnniversaryUltimateKaibaSetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABSOLUTE_POWERFORCE] =
    {
        .name = _("Absolute Powe"),
        .itemId = ITEM_PACK_ABSOLUTE_POWERFORCE,
        .price = 0,
        .description = sAbsolutePowerforceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABSOLUTE_POWERFORCE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Absolute Powe"),
        .itemId = ITEM_PACK_ABSOLUTE_POWERFORCE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sAbsolutePowerforceSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABSOLUTE_POWERFORCE_SPECIAL_EDITION] =
    {
        .name = _("Absolute Powe"),
        .itemId = ITEM_PACK_ABSOLUTE_POWERFORCE_SPECIAL_EDITION,
        .price = 0,
        .description = sAbsolutePowerforceSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABYSS_RISING] =
    {
        .name = _("Abyss Rising"),
        .itemId = ITEM_PACK_ABYSS_RISING,
        .price = 0,
        .description = sAbyssRisingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABYSS_RISING_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Abyss Rising "),
        .itemId = ITEM_PACK_ABYSS_RISING_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sAbyssRisingSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ABYSS_RISING_SPECIAL_EDITION] =
    {
        .name = _("Abyss Rising:"),
        .itemId = ITEM_PACK_ABYSS_RISING_SPECIAL_EDITION,
        .price = 0,
        .description = sAbyssRisingSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ADVANCED_DEMO_DECK_EXTRA_PACK] =
    {
        .name = _("Advanced Demo"),
        .itemId = ITEM_PACK_ADVANCED_DEMO_DECK_EXTRA_PACK,
        .price = 0,
        .description = sAdvancedDemoDeckExtraPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_AGE_OF_OVERLORD] =
    {
        .name = _("Age of Overlo"),
        .itemId = ITEM_PACK_AGE_OF_OVERLORD,
        .price = 0,
        .description = sAgeofOverlordDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ALLIANCE_INSIGHT] =
    {
        .name = _("Alliance Insi"),
        .itemId = ITEM_PACK_ALLIANCE_INSIGHT,
        .price = 0,
        .description = sAllianceInsightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_AMAZING_DEFENDERS] =
    {
        .name = _("Amazing Defen"),
        .itemId = ITEM_PACK_AMAZING_DEFENDERS,
        .price = 0,
        .description = sAmazingDefendersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANCIENT_GUARDIANS] =
    {
        .name = _("Ancient Guard"),
        .itemId = ITEM_PACK_ANCIENT_GUARDIANS,
        .price = 0,
        .description = sAncientGuardiansDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANCIENT_PROPHECY] =
    {
        .name = _("Ancient Proph"),
        .itemId = ITEM_PACK_ANCIENT_PROPHECY,
        .price = 0,
        .description = sAncientProphecyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANCIENT_PROPHECY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Ancient Proph"),
        .itemId = ITEM_PACK_ANCIENT_PROPHECY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sAncientProphecySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANCIENT_PROPHECY_SPECIAL_EDITION] =
    {
        .name = _("Ancient Proph"),
        .itemId = ITEM_PACK_ANCIENT_PROPHECY_SPECIAL_EDITION,
        .price = 0,
        .description = sAncientProphecySpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANCIENT_SANCTUARY] =
    {
        .name = _("Ancient Sanct"),
        .itemId = ITEM_PACK_ANCIENT_SANCTUARY,
        .price = 0,
        .description = sAncientSanctuaryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ANNIVERSARY_PACK] =
    {
        .name = _("Anniversary P"),
        .itemId = ITEM_PACK_ANNIVERSARY_PACK,
        .price = 0,
        .description = sAnniversaryPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_EIGHT] =
    {
        .name = _("Astral Pack E"),
        .itemId = ITEM_PACK_ASTRAL_PACK_EIGHT,
        .price = 0,
        .description = sAstralPackEightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_FIVE] =
    {
        .name = _("Astral Pack F"),
        .itemId = ITEM_PACK_ASTRAL_PACK_FIVE,
        .price = 0,
        .description = sAstralPackFiveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_FOUR] =
    {
        .name = _("Astral Pack F"),
        .itemId = ITEM_PACK_ASTRAL_PACK_FOUR,
        .price = 0,
        .description = sAstralPackFourDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_ONE] =
    {
        .name = _("Astral Pack O"),
        .itemId = ITEM_PACK_ASTRAL_PACK_ONE,
        .price = 0,
        .description = sAstralPackOneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_SEVEN] =
    {
        .name = _("Astral Pack S"),
        .itemId = ITEM_PACK_ASTRAL_PACK_SEVEN,
        .price = 0,
        .description = sAstralPackSevenDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_SIX] =
    {
        .name = _("Astral Pack S"),
        .itemId = ITEM_PACK_ASTRAL_PACK_SIX,
        .price = 0,
        .description = sAstralPackSixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_THREE] =
    {
        .name = _("Astral Pack T"),
        .itemId = ITEM_PACK_ASTRAL_PACK_THREE,
        .price = 0,
        .description = sAstralPackThreeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ASTRAL_PACK_TWO] =
    {
        .name = _("Astral Pack T"),
        .itemId = ITEM_PACK_ASTRAL_PACK_TWO,
        .price = 0,
        .description = sAstralPackTwoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLE_PACK_2_WAR_OF_THE_GIANTS] =
    {
        .name = _("Battle Pack 2"),
        .itemId = ITEM_PACK_BATTLE_PACK_2_WAR_OF_THE_GIANTS,
        .price = 0,
        .description = sBattlePack2WaroftheGiantsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLE_PACK_3_MONSTER_LEAGUE] =
    {
        .name = _("Battle Pack 3"),
        .itemId = ITEM_PACK_BATTLE_PACK_3_MONSTER_LEAGUE,
        .price = 0,
        .description = sBattlePack3MonsterLeagueDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLE_PACK_TOURNAMENT_PRIZE_CARDS] =
    {
        .name = _("Battle Pack T"),
        .itemId = ITEM_PACK_BATTLE_PACK_TOURNAMENT_PRIZE_CARDS,
        .price = 0,
        .description = sBattlePackTournamentPrizeCardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLE_PACK_EPIC_DAWN] =
    {
        .name = _("Battle Pack: "),
        .itemId = ITEM_PACK_BATTLE_PACK_EPIC_DAWN,
        .price = 0,
        .description = sBattlePackEpicDawnDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLE_OF_CHAOS] =
    {
        .name = _("Battle of Cha"),
        .itemId = ITEM_PACK_BATTLE_OF_CHAOS,
        .price = 0,
        .description = sBattleofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_ARMAGEDDON] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_ARMAGEDDON,
        .price = 0,
        .description = sBattlesofLegendArmageddonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_CHAPTER_1] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_CHAPTER_1,
        .price = 0,
        .description = sBattlesofLegendChapter1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_CRYSTAL_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_CRYSTAL_REVENGE,
        .price = 0,
        .description = sBattlesofLegendCrystalRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_HERO_S_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_HERO_S_REVENGE,
        .price = 0,
        .description = sBattlesofLegendHerosRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_LIGHT_S_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_LIGHT_S_REVENGE,
        .price = 0,
        .description = sBattlesofLegendLightsRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_MONSTER_MAYHEM] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_MONSTER_MAYHEM,
        .price = 0,
        .description = sBattlesofLegendMonsterMayhemDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_MONSTROUS_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_MONSTROUS_REVENGE,
        .price = 0,
        .description = sBattlesofLegendMonstrousRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_RELENTLESS_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_RELENTLESS_REVENGE,
        .price = 0,
        .description = sBattlesofLegendRelentlessRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BATTLES_OF_LEGEND_TERMINAL_REVENGE] =
    {
        .name = _("Battles of Le"),
        .itemId = ITEM_PACK_BATTLES_OF_LEGEND_TERMINAL_REVENGE,
        .price = 0,
        .description = sBattlesofLegendTerminalRevengeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BLAZING_VORTEX] =
    {
        .name = _("Blazing Vorte"),
        .itemId = ITEM_PACK_BLAZING_VORTEX,
        .price = 0,
        .description = sBlazingVortexDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BLAZING_VORTEX_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Blazing Vorte"),
        .itemId = ITEM_PACK_BLAZING_VORTEX_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sBlazingVortexPremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BLUE_EYES_ALTERNATIVE_WHITE_DRAGON_SWEEPSTAKES] =
    {
        .name = _("Blue-Eyes Alt"),
        .itemId = ITEM_PACK_BLUE_EYES_ALTERNATIVE_WHITE_DRAGON_SWEEPSTAKES,
        .price = 0,
        .description = sBlueEyesAlternativeWhiteDragonSweepstakesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BOOSTER_PACK_COLLECTORS_TINS_2002] =
    {
        .name = _("Booster Pack "),
        .itemId = ITEM_PACK_BOOSTER_PACK_COLLECTORS_TINS_2002,
        .price = 0,
        .description = sBoosterPackCollectorsTins2002Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BREAKERS_OF_SHADOW] =
    {
        .name = _("Breakers of S"),
        .itemId = ITEM_PACK_BREAKERS_OF_SHADOW,
        .price = 0,
        .description = sBreakersofShadowDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BREAKERS_OF_SHADOW_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Breakers of S"),
        .itemId = ITEM_PACK_BREAKERS_OF_SHADOW_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sBreakersofShadowSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BREAKERS_OF_SHADOW_SPECIAL_EDITION] =
    {
        .name = _("Breakers of S"),
        .itemId = ITEM_PACK_BREAKERS_OF_SHADOW_SPECIAL_EDITION,
        .price = 0,
        .description = sBreakersofShadowSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BROTHERS_OF_LEGEND] =
    {
        .name = _("Brothers of L"),
        .itemId = ITEM_PACK_BROTHERS_OF_LEGEND,
        .price = 0,
        .description = sBrothersofLegendDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_BURST_OF_DESTINY] =
    {
        .name = _("Burst of Dest"),
        .itemId = ITEM_PACK_BURST_OF_DESTINY,
        .price = 0,
        .description = sBurstofDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_EIGHT] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_EIGHT,
        .price = 0,
        .description = sChampionPackGameEightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_FIVE] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_FIVE,
        .price = 0,
        .description = sChampionPackGameFiveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_FOUR] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_FOUR,
        .price = 0,
        .description = sChampionPackGameFourDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_ONE] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_ONE,
        .price = 0,
        .description = sChampionPackGameOneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_SEVEN] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_SEVEN,
        .price = 0,
        .description = sChampionPackGameSevenDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_SIX] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_SIX,
        .price = 0,
        .description = sChampionPackGameSixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_THREE] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_THREE,
        .price = 0,
        .description = sChampionPackGameThreeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAMPION_PACK_GAME_TWO] =
    {
        .name = _("Champion Pack"),
        .itemId = ITEM_PACK_CHAMPION_PACK_GAME_TWO,
        .price = 0,
        .description = sChampionPackGameTwoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAOS_IMPACT] =
    {
        .name = _("Chaos Impact"),
        .itemId = ITEM_PACK_CHAOS_IMPACT,
        .price = 0,
        .description = sChaosImpactDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAOS_IMPACT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Chaos Impact "),
        .itemId = ITEM_PACK_CHAOS_IMPACT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sChaosImpactSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CHAOS_IMPACT_SPECIAL_EDITION] =
    {
        .name = _("Chaos Impact "),
        .itemId = ITEM_PACK_CHAOS_IMPACT_SPECIAL_EDITION,
        .price = 0,
        .description = sChaosImpactSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CIRCUIT_BREAK] =
    {
        .name = _("Circuit Break"),
        .itemId = ITEM_PACK_CIRCUIT_BREAK,
        .price = 0,
        .description = sCircuitBreakDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CIRCUIT_BREAK_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Circuit Break"),
        .itemId = ITEM_PACK_CIRCUIT_BREAK_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCircuitBreakSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CIRCUIT_BREAK_SPECIAL_EDITION] =
    {
        .name = _("Circuit Break"),
        .itemId = ITEM_PACK_CIRCUIT_BREAK_SPECIAL_EDITION,
        .price = 0,
        .description = sCircuitBreakSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CLASH_OF_REBELLIONS] =
    {
        .name = _("Clash of Rebe"),
        .itemId = ITEM_PACK_CLASH_OF_REBELLIONS,
        .price = 0,
        .description = sClashofRebellionsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CLASH_OF_REBELLIONS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Clash of Rebe"),
        .itemId = ITEM_PACK_CLASH_OF_REBELLIONS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sClashofRebellionsSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CLASH_OF_REBELLIONS_SPECIAL_EDITION] =
    {
        .name = _("Clash of Rebe"),
        .itemId = ITEM_PACK_CLASH_OF_REBELLIONS_SPECIAL_EDITION,
        .price = 0,
        .description = sClashofRebellionsSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CODE_OF_THE_DUELIST] =
    {
        .name = _("Code of the D"),
        .itemId = ITEM_PACK_CODE_OF_THE_DUELIST,
        .price = 0,
        .description = sCodeoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CODE_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Code of the D"),
        .itemId = ITEM_PACK_CODE_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCodeoftheDuelistSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CODE_OF_THE_DUELIST_SPECIAL_EDITION] =
    {
        .name = _("Code of the D"),
        .itemId = ITEM_PACK_CODE_OF_THE_DUELIST_SPECIAL_EDITION,
        .price = 0,
        .description = sCodeoftheDuelistSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2003] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2003,
        .price = 0,
        .description = sCollectibleTins2003Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2004] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2004,
        .price = 0,
        .description = sCollectibleTins2004Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2005] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2005,
        .price = 0,
        .description = sCollectibleTins2005Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2006_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2006_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2006Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2006_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2006_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2006Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2007_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2007_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2007Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2007_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2007_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2007Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2008_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2008_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2008Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2008_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2008_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2008Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2009_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2009_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2009Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2009_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2009_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2009Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2010_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2010_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2010Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2010_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2010_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2010Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2011_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2011_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2011Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2011_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2011_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2011Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_1] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_1,
        .price = 0,
        .description = sCollectibleTins2012Wave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_2] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_2,
        .price = 0,
        .description = sCollectibleTins2012Wave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_2_5] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_2012_WAVE_2_5,
        .price = 0,
        .description = sCollectibleTins2012Wave25Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_EXCLUSIVE_2008] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_EXCLUSIVE_2008,
        .price = 0,
        .description = sCollectibleTinsExclusive2008Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COLLECTIBLE_TINS_EXCLUSIVE_2009] =
    {
        .name = _("Collectible T"),
        .itemId = ITEM_PACK_COLLECTIBLE_TINS_EXCLUSIVE_2009,
        .price = 0,
        .description = sCollectibleTinsExclusive2009Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COSMO_BLAZER] =
    {
        .name = _("Cosmo Blazer"),
        .itemId = ITEM_PACK_COSMO_BLAZER,
        .price = 0,
        .description = sCosmoBlazerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COSMO_BLAZER_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Cosmo Blazer "),
        .itemId = ITEM_PACK_COSMO_BLAZER_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCosmoBlazerSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_COSMO_BLAZER_SPECIAL_EDITION] =
    {
        .name = _("Cosmo Blazer:"),
        .itemId = ITEM_PACK_COSMO_BLAZER_SPECIAL_EDITION,
        .price = 0,
        .description = sCosmoBlazerSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CRIMSON_CRISIS] =
    {
        .name = _("Crimson Crisi"),
        .itemId = ITEM_PACK_CRIMSON_CRISIS,
        .price = 0,
        .description = sCrimsonCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CRIMSON_CRISIS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Crimson Crisi"),
        .itemId = ITEM_PACK_CRIMSON_CRISIS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCrimsonCrisisSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CRIMSON_CRISIS_SPECIAL_EDITION] =
    {
        .name = _("Crimson Crisi"),
        .itemId = ITEM_PACK_CRIMSON_CRISIS_SPECIAL_EDITION,
        .price = 0,
        .description = sCrimsonCrisisSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSED_SOULS] =
    {
        .name = _("Crossed Souls"),
        .itemId = ITEM_PACK_CROSSED_SOULS,
        .price = 0,
        .description = sCrossedSoulsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSED_SOULS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Crossed Souls"),
        .itemId = ITEM_PACK_CROSSED_SOULS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCrossedSoulsSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSED_SOULS_ADVANCE_EDITION] =
    {
        .name = _("Crossed Souls"),
        .itemId = ITEM_PACK_CROSSED_SOULS_ADVANCE_EDITION,
        .price = 0,
        .description = sCrossedSoulsAdvanceEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSOVER_BREAKERS] =
    {
        .name = _("Crossover Bre"),
        .itemId = ITEM_PACK_CROSSOVER_BREAKERS,
        .price = 0,
        .description = sCrossoverBreakersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSROADS_OF_CHAOS] =
    {
        .name = _("Crossroads of"),
        .itemId = ITEM_PACK_CROSSROADS_OF_CHAOS,
        .price = 0,
        .description = sCrossroadsofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSROADS_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Crossroads of"),
        .itemId = ITEM_PACK_CROSSROADS_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCrossroadsofChaosSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CROSSROADS_OF_CHAOS_SPECIAL_EDITION] =
    {
        .name = _("Crossroads of"),
        .itemId = ITEM_PACK_CROSSROADS_OF_CHAOS_SPECIAL_EDITION,
        .price = 0,
        .description = sCrossroadsofChaosSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBER_DRAGON_REVOLUTION_STRUCTURE_DECK] =
    {
        .name = _("Cyber Dragon "),
        .itemId = ITEM_PACK_CYBER_DRAGON_REVOLUTION_STRUCTURE_DECK,
        .price = 0,
        .description = sCyberDragonRevolutionStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERDARK_IMPACT] =
    {
        .name = _("Cyberdark Imp"),
        .itemId = ITEM_PACK_CYBERDARK_IMPACT,
        .price = 0,
        .description = sCyberdarkImpactDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERDARK_IMPACT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Cyberdark Imp"),
        .itemId = ITEM_PACK_CYBERDARK_IMPACT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCyberdarkImpactSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERNETIC_HORIZON] =
    {
        .name = _("Cybernetic Ho"),
        .itemId = ITEM_PACK_CYBERNETIC_HORIZON,
        .price = 0,
        .description = sCyberneticHorizonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERNETIC_HORIZON_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Cybernetic Ho"),
        .itemId = ITEM_PACK_CYBERNETIC_HORIZON_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCyberneticHorizonSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERNETIC_HORIZON_SPECIAL_EDITION] =
    {
        .name = _("Cybernetic Ho"),
        .itemId = ITEM_PACK_CYBERNETIC_HORIZON_SPECIAL_EDITION,
        .price = 0,
        .description = sCyberneticHorizonSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERNETIC_REVOLUTION] =
    {
        .name = _("Cybernetic Re"),
        .itemId = ITEM_PACK_CYBERNETIC_REVOLUTION,
        .price = 0,
        .description = sCyberneticRevolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERNETIC_REVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Cybernetic Re"),
        .itemId = ITEM_PACK_CYBERNETIC_REVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sCyberneticRevolutionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_CYBERSTORM_ACCESS] =
    {
        .name = _("Cyberstorm Ac"),
        .itemId = ITEM_PACK_CYBERSTORM_ACCESS,
        .price = 0,
        .description = sCyberstormAccessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_BEGINNING_1] =
    {
        .name = _("Dark Beginnin"),
        .itemId = ITEM_PACK_DARK_BEGINNING_1,
        .price = 0,
        .description = sDarkBeginning1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_BEGINNING_2] =
    {
        .name = _("Dark Beginnin"),
        .itemId = ITEM_PACK_DARK_BEGINNING_2,
        .price = 0,
        .description = sDarkBeginning2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_CRISIS] =
    {
        .name = _("Dark Crisis"),
        .itemId = ITEM_PACK_DARK_CRISIS,
        .price = 0,
        .description = sDarkCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_LEGENDS] =
    {
        .name = _("Dark Legends"),
        .itemId = ITEM_PACK_DARK_LEGENDS,
        .price = 0,
        .description = sDarkLegendsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_LEGION_STARTER_DECK] =
    {
        .name = _("Dark Legion S"),
        .itemId = ITEM_PACK_DARK_LEGION_STARTER_DECK,
        .price = 0,
        .description = sDarkLegionStarterDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_NEOSTORM] =
    {
        .name = _("Dark Neostorm"),
        .itemId = ITEM_PACK_DARK_NEOSTORM,
        .price = 0,
        .description = sDarkNeostormDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_NEOSTORM_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Dark Neostorm"),
        .itemId = ITEM_PACK_DARK_NEOSTORM_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sDarkNeostormSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_NEOSTORM_SPECIAL_EDITION] =
    {
        .name = _("Dark Neostorm"),
        .itemId = ITEM_PACK_DARK_NEOSTORM_SPECIAL_EDITION,
        .price = 0,
        .description = sDarkNeostormSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_REVELATION_VOLUME_1] =
    {
        .name = _("Dark Revelati"),
        .itemId = ITEM_PACK_DARK_REVELATION_VOLUME_1,
        .price = 0,
        .description = sDarkRevelationVolume1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_REVELATION_VOLUME_2] =
    {
        .name = _("Dark Revelati"),
        .itemId = ITEM_PACK_DARK_REVELATION_VOLUME_2,
        .price = 0,
        .description = sDarkRevelationVolume2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_REVELATION_VOLUME_3] =
    {
        .name = _("Dark Revelati"),
        .itemId = ITEM_PACK_DARK_REVELATION_VOLUME_3,
        .price = 0,
        .description = sDarkRevelationVolume3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_REVELATION_VOLUME_4] =
    {
        .name = _("Dark Revelati"),
        .itemId = ITEM_PACK_DARK_REVELATION_VOLUME_4,
        .price = 0,
        .description = sDarkRevelationVolume4Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARK_SAVIORS] =
    {
        .name = _("Dark Saviors"),
        .itemId = ITEM_PACK_DARK_SAVIORS,
        .price = 0,
        .description = sDarkSaviorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DARKWING_BLAST] =
    {
        .name = _("Darkwing Blas"),
        .itemId = ITEM_PACK_DARKWING_BLAST,
        .price = 0,
        .description = sDarkwingBlastDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DAWN_OF_MAJESTY] =
    {
        .name = _("Dawn of Majes"),
        .itemId = ITEM_PACK_DAWN_OF_MAJESTY,
        .price = 0,
        .description = sDawnofMajestyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DAWN_OF_MAJESTY_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Dawn of Majes"),
        .itemId = ITEM_PACK_DAWN_OF_MAJESTY_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sDawnofMajestyPremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DEMO_DECK_2015] =
    {
        .name = _("Demo Deck 201"),
        .itemId = ITEM_PACK_DEMO_DECK_2015,
        .price = 0,
        .description = sDemoDeck2015Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DEMO_DECK_2016] =
    {
        .name = _("Demo Deck 201"),
        .itemId = ITEM_PACK_DEMO_DECK_2016,
        .price = 0,
        .description = sDemoDeck2016Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DEMO_PACK] =
    {
        .name = _("Demo Pack"),
        .itemId = ITEM_PACK_DEMO_PACK,
        .price = 0,
        .description = sDemoPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DESTINY_SOLDIERS] =
    {
        .name = _("Destiny Soldi"),
        .itemId = ITEM_PACK_DESTINY_SOLDIERS,
        .price = 0,
        .description = sDestinySoldiersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DIMENSION_FORCE] =
    {
        .name = _("Dimension For"),
        .itemId = ITEM_PACK_DIMENSION_FORCE,
        .price = 0,
        .description = sDimensionForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DIMENSION_OF_CHAOS] =
    {
        .name = _("Dimension of "),
        .itemId = ITEM_PACK_DIMENSION_OF_CHAOS,
        .price = 0,
        .description = sDimensionofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DIMENSION_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Dimension of "),
        .itemId = ITEM_PACK_DIMENSION_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sDimensionofChaosSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DIMENSION_OF_CHAOS_SPECIAL_EDITION] =
    {
        .name = _("Dimension of "),
        .itemId = ITEM_PACK_DIMENSION_OF_CHAOS_SPECIAL_EDITION,
        .price = 0,
        .description = sDimensionofChaosSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DINOSMASHER_S_FURY_STRUCTURE_DECK] =
    {
        .name = _("Dinosmasher's"),
        .itemId = ITEM_PACK_DINOSMASHER_S_FURY_STRUCTURE_DECK,
        .price = 0,
        .description = sDinosmashersFuryStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGONS_COLLIDE_STRUCTURE_DECK] =
    {
        .name = _("Dragons Colli"),
        .itemId = ITEM_PACK_DRAGONS_COLLIDE_STRUCTURE_DECK,
        .price = 0,
        .description = sDragonsCollideStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGONS_OF_LEGEND] =
    {
        .name = _("Dragons of Le"),
        .itemId = ITEM_PACK_DRAGONS_OF_LEGEND,
        .price = 0,
        .description = sDragonsofLegendDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGONS_OF_LEGEND_2] =
    {
        .name = _("Dragons of Le"),
        .itemId = ITEM_PACK_DRAGONS_OF_LEGEND_2,
        .price = 0,
        .description = sDragonsofLegend2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGONS_OF_LEGEND_THE_COMPLETE_SERIES] =
    {
        .name = _("Dragons of Le"),
        .itemId = ITEM_PACK_DRAGONS_OF_LEGEND_THE_COMPLETE_SERIES,
        .price = 0,
        .description = sDragonsofLegendTheCompleteSeriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGONS_OF_LEGEND_UNLEASHED] =
    {
        .name = _("Dragons of Le"),
        .itemId = ITEM_PACK_DRAGONS_OF_LEGEND_UNLEASHED,
        .price = 0,
        .description = sDragonsofLegendUnleashedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DRAGUNITY_LEGION_STRUCTURE_DECK] =
    {
        .name = _("Dragunity Leg"),
        .itemId = ITEM_PACK_DRAGUNITY_LEGION_STRUCTURE_DECK,
        .price = 0,
        .description = sDragunityLegionStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_DEVASTATOR] =
    {
        .name = _("Duel Devastat"),
        .itemId = ITEM_PACK_DUEL_DEVASTATOR,
        .price = 0,
        .description = sDuelDevastatorDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_DISK_YUSEI_VERSION] =
    {
        .name = _("Duel Disk - Y"),
        .itemId = ITEM_PACK_DUEL_DISK_YUSEI_VERSION,
        .price = 0,
        .description = sDuelDiskYuseiVersionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_MASTER_S_GUIDE_PROMOTIONAL_CARDS] =
    {
        .name = _("Duel Master's"),
        .itemId = ITEM_PACK_DUEL_MASTER_S_GUIDE_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sDuelMastersGuidepromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_OVERLOAD] =
    {
        .name = _("Duel Overload"),
        .itemId = ITEM_PACK_DUEL_OVERLOAD,
        .price = 0,
        .description = sDuelOverloadDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_POWER] =
    {
        .name = _("Duel Power"),
        .itemId = ITEM_PACK_DUEL_POWER,
        .price = 0,
        .description = sDuelPowerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_PREVIEW_WAVE_1] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_PREVIEW_WAVE_1,
        .price = 0,
        .description = sDuelTerminalPreviewWave1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_PREVIEW_WAVE_2] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_PREVIEW_WAVE_2,
        .price = 0,
        .description = sDuelTerminalPreviewWave2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_1] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_1,
        .price = 0,
        .description = sDuelTerminal1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_2] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_2,
        .price = 0,
        .description = sDuelTerminal2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_3] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_3,
        .price = 0,
        .description = sDuelTerminal3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_4] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_4,
        .price = 0,
        .description = sDuelTerminal4Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_5] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_5,
        .price = 0,
        .description = sDuelTerminal5Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_5A] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_5A,
        .price = 0,
        .description = sDuelTerminal5aDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_5B] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_5B,
        .price = 0,
        .description = sDuelTerminal5bDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_6] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_6,
        .price = 0,
        .description = sDuelTerminal6Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_6A] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_6A,
        .price = 0,
        .description = sDuelTerminal6aDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_6B] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_6B,
        .price = 0,
        .description = sDuelTerminal6bDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_7] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_7,
        .price = 0,
        .description = sDuelTerminal7Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_7A] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_7A,
        .price = 0,
        .description = sDuelTerminal7aDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUEL_TERMINAL_7B] =
    {
        .name = _("Duel Terminal"),
        .itemId = ITEM_PACK_DUEL_TERMINAL_7B,
        .price = 0,
        .description = sDuelTerminal7bDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_ALLIANCE] =
    {
        .name = _("Duelist Allia"),
        .itemId = ITEM_PACK_DUELIST_ALLIANCE,
        .price = 0,
        .description = sDuelistAllianceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_ALLIANCE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Allia"),
        .itemId = ITEM_PACK_DUELIST_ALLIANCE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistAllianceSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_ALLIANCE_DELUXE_EDITION] =
    {
        .name = _("Duelist Allia"),
        .itemId = ITEM_PACK_DUELIST_ALLIANCE_DELUXE_EDITION,
        .price = 0,
        .description = sDuelistAllianceDeluxeEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_13_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_13_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague13participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_14_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_14_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague14participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_15_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_15_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague15participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_16_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_16_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague16participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_17_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_17_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague17participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_18_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_18_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague18participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_2_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_2_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague2participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_2010_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_2010_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague2010participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_3_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_3_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeague3participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_DEMO_2010] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_DEMO_2010,
        .price = 0,
        .description = sDuelistLeagueDemo2010Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_1_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_1_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeagueSeries1participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_10_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_10_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries10participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_2_PARTICIPATION_CARDS] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_2_PARTICIPATION_CARDS,
        .price = 0,
        .description = sDuelistLeagueSeries2participationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_3_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_3_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries3participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_4_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_4_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries4participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_5_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_5_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries5participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_6_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_6_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries6participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_7_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_7_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries7participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_8_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_8_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries8participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_LEAGUE_SERIES_9_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Leagu"),
        .itemId = ITEM_PACK_DUELIST_LEAGUE_SERIES_9_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistLeagueSeries9participationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_NEXUS] =
    {
        .name = _("Duelist Nexus"),
        .itemId = ITEM_PACK_DUELIST_NEXUS,
        .price = 0,
        .description = sDuelistNexusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2008] =
    {
        .name = _("Duelist Pack "),
        .itemId = ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2008,
        .price = 0,
        .description = sDuelistPackCollectionTin2008Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2009] =
    {
        .name = _("Duelist Pack "),
        .itemId = ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2009,
        .price = 0,
        .description = sDuelistPackCollectionTin2009Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2010] =
    {
        .name = _("Duelist Pack "),
        .itemId = ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2010,
        .price = 0,
        .description = sDuelistPackCollectionTin2010Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2011] =
    {
        .name = _("Duelist Pack "),
        .itemId = ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_2011,
        .price = 0,
        .description = sDuelistPackCollectionTin2011Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_JADEN_YUKI] =
    {
        .name = _("Duelist Pack "),
        .itemId = ITEM_PACK_DUELIST_PACK_COLLECTION_TIN_JADEN_YUKI,
        .price = 0,
        .description = sDuelistPackCollectionTinJadenYukiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_ASTER_PHOENIX] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_ASTER_PHOENIX,
        .price = 0,
        .description = sDuelistPackAsterPhoenixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_BATTLE_CITY] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_BATTLE_CITY,
        .price = 0,
        .description = sDuelistPackBattleCityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_CHAZZ_PRINCETON] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_CHAZZ_PRINCETON,
        .price = 0,
        .description = sDuelistPackChazzPrincetonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_CROW] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_CROW,
        .price = 0,
        .description = sDuelistPackCrowDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_DIMENSIONAL_GUARDIANS] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_DIMENSIONAL_GUARDIANS,
        .price = 0,
        .description = sDuelistPackDimensionalGuardiansDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_JADEN_YUKI] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_JADEN_YUKI,
        .price = 0,
        .description = sDuelistPackJadenYukiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_JADEN_YUKI_2] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_JADEN_YUKI_2,
        .price = 0,
        .description = sDuelistPackJadenYuki2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_JADEN_YUKI_3] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_JADEN_YUKI_3,
        .price = 0,
        .description = sDuelistPackJadenYuki3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_JESSE_ANDERSON] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_JESSE_ANDERSON,
        .price = 0,
        .description = sDuelistPackJesseAndersonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_KAIBA] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_KAIBA,
        .price = 0,
        .description = sDuelistPackKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_RIVALS_OF_THE_PHARAOH] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_RIVALS_OF_THE_PHARAOH,
        .price = 0,
        .description = sDuelistPackRivalsofthePharaohDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_SPECIAL_EDITION] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_SPECIAL_EDITION,
        .price = 0,
        .description = sDuelistPackSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_YUGI] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_YUGI,
        .price = 0,
        .description = sDuelistPackYugiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_YUSEI] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_YUSEI,
        .price = 0,
        .description = sDuelistPackYuseiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_YUSEI_2] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_YUSEI_2,
        .price = 0,
        .description = sDuelistPackYusei2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_YUSEI_3] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_YUSEI_3,
        .price = 0,
        .description = sDuelistPackYusei3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_PACK_ZANE_TRUESDALE] =
    {
        .name = _("Duelist Pack:"),
        .itemId = ITEM_PACK_DUELIST_PACK_ZANE_TRUESDALE,
        .price = 0,
        .description = sDuelistPackZaneTruesdaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_REVOLUTION] =
    {
        .name = _("Duelist Revol"),
        .itemId = ITEM_PACK_DUELIST_REVOLUTION,
        .price = 0,
        .description = sDuelistRevolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_REVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Duelist Revol"),
        .itemId = ITEM_PACK_DUELIST_REVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sDuelistRevolutionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_REVOLUTION_SPECIAL_EDITION] =
    {
        .name = _("Duelist Revol"),
        .itemId = ITEM_PACK_DUELIST_REVOLUTION_SPECIAL_EDITION,
        .price = 0,
        .description = sDuelistRevolutionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_SAGA] =
    {
        .name = _("Duelist Saga"),
        .itemId = ITEM_PACK_DUELIST_SAGA,
        .price = 0,
        .description = sDuelistSagaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_DUELIST_S_ADVANCE] =
    {
        .name = _("Duelist's Adv"),
        .itemId = ITEM_PACK_DUELIST_S_ADVANCE,
        .price = 0,
        .description = sDuelistsAdvanceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EGYPTIAN_GOD_DECK_OBELISK_THE_TORMENTOR] =
    {
        .name = _("Egyptian God "),
        .itemId = ITEM_PACK_EGYPTIAN_GOD_DECK_OBELISK_THE_TORMENTOR,
        .price = 0,
        .description = sEgyptianGodDeckObelisktheTormentorDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EGYPTIAN_GOD_DECK_SLIFER_THE_SKY_DRAGON] =
    {
        .name = _("Egyptian God "),
        .itemId = ITEM_PACK_EGYPTIAN_GOD_DECK_SLIFER_THE_SKY_DRAGON,
        .price = 0,
        .description = sEgyptianGodDeckSlifertheSkyDragonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ELEMENTAL_ENERGY] =
    {
        .name = _("Elemental Ene"),
        .itemId = ITEM_PACK_ELEMENTAL_ENERGY,
        .price = 0,
        .description = sElementalEnergyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ELEMENTAL_ENERGY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Elemental Ene"),
        .itemId = ITEM_PACK_ELEMENTAL_ENERGY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sElementalEnergySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ELEMENTAL_ENERGY_SPECIAL_EDITION] =
    {
        .name = _("Elemental Ene"),
        .itemId = ITEM_PACK_ELEMENTAL_ENERGY_SPECIAL_EDITION,
        .price = 0,
        .description = sElementalEnergySpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EMPEROR_OF_DARKNESS_STRUCTURE_DECK] =
    {
        .name = _("Emperor of Da"),
        .itemId = ITEM_PACK_EMPEROR_OF_DARKNESS_STRUCTURE_DECK,
        .price = 0,
        .description = sEmperorofDarknessStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ENEMY_OF_JUSTICE] =
    {
        .name = _("Enemy of Just"),
        .itemId = ITEM_PACK_ENEMY_OF_JUSTICE,
        .price = 0,
        .description = sEnemyofJusticeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ENEMY_OF_JUSTICE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Enemy of Just"),
        .itemId = ITEM_PACK_ENEMY_OF_JUSTICE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sEnemyofJusticeSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ETERNITY_CODE] =
    {
        .name = _("Eternity Code"),
        .itemId = ITEM_PACK_ETERNITY_CODE,
        .price = 0,
        .description = sEternityCodeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ETERNITY_CODE_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Eternity Code"),
        .itemId = ITEM_PACK_ETERNITY_CODE_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sEternityCodePremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EVENT_PACK_SPEED_DUEL] =
    {
        .name = _("Event Pack Sp"),
        .itemId = ITEM_PACK_EVENT_PACK_SPEED_DUEL,
        .price = 0,
        .description = sEventPackSpeedDuelDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXCLUSIVE_PACK] =
    {
        .name = _("Exclusive Pac"),
        .itemId = ITEM_PACK_EXCLUSIVE_PACK,
        .price = 0,
        .description = sExclusivePackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXTREME_FORCE] =
    {
        .name = _("Extreme Force"),
        .itemId = ITEM_PACK_EXTREME_FORCE,
        .price = 0,
        .description = sExtremeForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXTREME_FORCE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Extreme Force"),
        .itemId = ITEM_PACK_EXTREME_FORCE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sExtremeForceSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXTREME_FORCE_SPECIAL_EDITION] =
    {
        .name = _("Extreme Force"),
        .itemId = ITEM_PACK_EXTREME_FORCE_SPECIAL_EDITION,
        .price = 0,
        .description = sExtremeForceSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXTREME_VICTORY] =
    {
        .name = _("Extreme Victo"),
        .itemId = ITEM_PACK_EXTREME_VICTORY,
        .price = 0,
        .description = sExtremeVictoryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_EXTREME_VICTORY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Extreme Victo"),
        .itemId = ITEM_PACK_EXTREME_VICTORY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sExtremeVictorySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FIRE_FISTS_SPECIAL_EDITION] =
    {
        .name = _("Fire Fists: S"),
        .itemId = ITEM_PACK_FIRE_FISTS_SPECIAL_EDITION,
        .price = 0,
        .description = sFireFistsSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FISTS_OF_THE_GADGETS] =
    {
        .name = _("Fists of the "),
        .itemId = ITEM_PACK_FISTS_OF_THE_GADGETS,
        .price = 0,
        .description = sFistsoftheGadgetsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FLAMES_OF_DESTRUCTION] =
    {
        .name = _("Flames of Des"),
        .itemId = ITEM_PACK_FLAMES_OF_DESTRUCTION,
        .price = 0,
        .description = sFlamesofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FLAMES_OF_DESTRUCTION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Flames of Des"),
        .itemId = ITEM_PACK_FLAMES_OF_DESTRUCTION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sFlamesofDestructionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FLAMES_OF_DESTRUCTION_SPECIAL_EDITION] =
    {
        .name = _("Flames of Des"),
        .itemId = ITEM_PACK_FLAMES_OF_DESTRUCTION_SPECIAL_EDITION,
        .price = 0,
        .description = sFlamesofDestructionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FLAMING_ETERNITY] =
    {
        .name = _("Flaming Etern"),
        .itemId = ITEM_PACK_FLAMING_ETERNITY,
        .price = 0,
        .description = sFlamingEternityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FLAMING_ETERNITY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Flaming Etern"),
        .itemId = ITEM_PACK_FLAMING_ETERNITY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sFlamingEternitySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FORBIDDEN_LEGACY] =
    {
        .name = _("Forbidden Leg"),
        .itemId = ITEM_PACK_FORBIDDEN_LEGACY,
        .price = 0,
        .description = sForbiddenLegacyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FORCE_OF_THE_BREAKER] =
    {
        .name = _("Force of the "),
        .itemId = ITEM_PACK_FORCE_OF_THE_BREAKER,
        .price = 0,
        .description = sForceoftheBreakerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FORCE_OF_THE_BREAKER_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Force of the "),
        .itemId = ITEM_PACK_FORCE_OF_THE_BREAKER_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sForceoftheBreakerSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FORCE_OF_THE_BREAKER_SPECIAL_EDITION] =
    {
        .name = _("Force of the "),
        .itemId = ITEM_PACK_FORCE_OF_THE_BREAKER_SPECIAL_EDITION,
        .price = 0,
        .description = sForceoftheBreakerSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_FUSION_ENFORCERS] =
    {
        .name = _("Fusion Enforc"),
        .itemId = ITEM_PACK_FUSION_ENFORCERS,
        .price = 0,
        .description = sFusionEnforcersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GX_NEXT_GENERATION] =
    {
        .name = _("GX Next Gener"),
        .itemId = ITEM_PACK_GX_NEXT_GENERATION,
        .price = 0,
        .description = sGXNextGenerationDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GALACTIC_OVERLORD] =
    {
        .name = _("Galactic Over"),
        .itemId = ITEM_PACK_GALACTIC_OVERLORD,
        .price = 0,
        .description = sGalacticOverlordDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GALACTIC_OVERLORD_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Galactic Over"),
        .itemId = ITEM_PACK_GALACTIC_OVERLORD_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sGalacticOverlordSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GATES_OF_THE_UNDERWORLD_STRUCTURE_DECK] =
    {
        .name = _("Gates of the "),
        .itemId = ITEM_PACK_GATES_OF_THE_UNDERWORLD_STRUCTURE_DECK,
        .price = 0,
        .description = sGatesoftheUnderworldStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GEARGIA_RAMPAGE_STRUCTURE_DECK] =
    {
        .name = _("Geargia Rampa"),
        .itemId = ITEM_PACK_GEARGIA_RAMPAGE_STRUCTURE_DECK,
        .price = 0,
        .description = sGeargiaRampageStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GENERATION_FORCE] =
    {
        .name = _("Generation Fo"),
        .itemId = ITEM_PACK_GENERATION_FORCE,
        .price = 0,
        .description = sGenerationForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GENERATION_FORCE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Generation Fo"),
        .itemId = ITEM_PACK_GENERATION_FORCE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sGenerationForceSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GENERATION_FORCE_SPECIAL_EDITION] =
    {
        .name = _("Generation Fo"),
        .itemId = ITEM_PACK_GENERATION_FORCE_SPECIAL_EDITION,
        .price = 0,
        .description = sGenerationForceSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GENESIS_IMPACT] =
    {
        .name = _("Genesis Impac"),
        .itemId = ITEM_PACK_GENESIS_IMPACT,
        .price = 0,
        .description = sGenesisImpactDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GHOSTS_FROM_THE_PAST] =
    {
        .name = _("Ghosts From t"),
        .itemId = ITEM_PACK_GHOSTS_FROM_THE_PAST,
        .price = 0,
        .description = sGhostsFromthePastDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GHOSTS_FROM_THE_PAST_THE_2ND_HAUNTING] =
    {
        .name = _("Ghosts From t"),
        .itemId = ITEM_PACK_GHOSTS_FROM_THE_PAST_THE_2ND_HAUNTING,
        .price = 0,
        .description = sGhostsFromthePastThe2ndHauntingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GLADIATOR_S_ASSAULT] =
    {
        .name = _("Gladiator's A"),
        .itemId = ITEM_PACK_GLADIATOR_S_ASSAULT,
        .price = 0,
        .description = sGladiatorsAssaultDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GLADIATOR_S_ASSAULT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Gladiator's A"),
        .itemId = ITEM_PACK_GLADIATOR_S_ASSAULT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sGladiatorsAssaultSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GLADIATOR_S_ASSAULT_SPECIAL_EDITION] =
    {
        .name = _("Gladiator's A"),
        .itemId = ITEM_PACK_GLADIATOR_S_ASSAULT_SPECIAL_EDITION,
        .price = 0,
        .description = sGladiatorsAssaultSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOLD_SERIES] =
    {
        .name = _("Gold Series"),
        .itemId = ITEM_PACK_GOLD_SERIES,
        .price = 0,
        .description = sGoldSeriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOLD_SERIES_2009] =
    {
        .name = _("Gold Series 2"),
        .itemId = ITEM_PACK_GOLD_SERIES_2009,
        .price = 0,
        .description = sGoldSeries2009Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOLD_SERIES_3] =
    {
        .name = _("Gold Series 3"),
        .itemId = ITEM_PACK_GOLD_SERIES_3,
        .price = 0,
        .description = sGoldSeries3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOLD_SERIES_4_PYRAMIDS_EDITION] =
    {
        .name = _("Gold Series 4"),
        .itemId = ITEM_PACK_GOLD_SERIES_4_PYRAMIDS_EDITION,
        .price = 0,
        .description = sGoldSeries4PyramidsEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_GOLD_SERIES_HAUNTED_MINE] =
    {
        .name = _("Gold Series: "),
        .itemId = ITEM_PACK_GOLD_SERIES_HAUNTED_MINE,
        .price = 0,
        .description = sGoldSeriesHauntedMineDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HERO_STRIKE_STRUCTURE_DECK] =
    {
        .name = _("HERO Strike S"),
        .itemId = ITEM_PACK_HERO_STRIKE_STRUCTURE_DECK,
        .price = 0,
        .description = sHEROStrikeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL,
        .price = 0,
        .description = sHiddenArsenalDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_2] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_2,
        .price = 0,
        .description = sHiddenArsenal2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_3] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_3,
        .price = 0,
        .description = sHiddenArsenal3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_4_TRISHULA_S_TRIUMPH] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_4_TRISHULA_S_TRIUMPH,
        .price = 0,
        .description = sHiddenArsenal4TrishulasTriumphDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_5_STEELSWARM_INVASION] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_5_STEELSWARM_INVASION,
        .price = 0,
        .description = sHiddenArsenal5SteelswarmInvasionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_5_STEELSWARM_INVASION_SPECIAL_EDITION] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_5_STEELSWARM_INVASION_SPECIAL_EDITION,
        .price = 0,
        .description = sHiddenArsenal5SteelswarmInvasionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_6_OMEGA_XYZ] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_6_OMEGA_XYZ,
        .price = 0,
        .description = sHiddenArsenal6OmegaXyzDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_7_KNIGHT_OF_STARS] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_7_KNIGHT_OF_STARS,
        .price = 0,
        .description = sHiddenArsenal7KnightofStarsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_CHAPTER_1] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_CHAPTER_1,
        .price = 0,
        .description = sHiddenArsenalChapter1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_ARSENAL_SPECIAL_EDITION] =
    {
        .name = _("Hidden Arsena"),
        .itemId = ITEM_PACK_HIDDEN_ARSENAL_SPECIAL_EDITION,
        .price = 0,
        .description = sHiddenArsenalSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIDDEN_SUMMONERS] =
    {
        .name = _("Hidden Summon"),
        .itemId = ITEM_PACK_HIDDEN_SUMMONERS,
        .price = 0,
        .description = sHiddenSummonersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HIGH_SPEED_RIDERS] =
    {
        .name = _("High-Speed Ri"),
        .itemId = ITEM_PACK_HIGH_SPEED_RIDERS,
        .price = 0,
        .description = sHighSpeedRidersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_A,
        .price = 0,
        .description = sHobbyLeague1participationcardsADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_B,
        .price = 0,
        .description = sHobbyLeague1participationcardsBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_1_PARTICIPATION_CARDS_C,
        .price = 0,
        .description = sHobbyLeague1participationcardsCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague2participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague2participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague2participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague2participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague2participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_2_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague2participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague3participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague3participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague3participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague3participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague3participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague3participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_G] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_3_PARTICIPATION_CARD_G,
        .price = 0,
        .description = sHobbyLeague3participationcardGDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague4participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague4participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague4participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague4participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague4participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_4_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague4participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague5participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague5participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague5participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague5participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague5participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_5_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague5participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague6participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague6participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague6participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague6participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague6participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_6_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague6participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_A] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_A,
        .price = 0,
        .description = sHobbyLeague7participationcardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_B] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_B,
        .price = 0,
        .description = sHobbyLeague7participationcardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_C] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_C,
        .price = 0,
        .description = sHobbyLeague7participationcardCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_D] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_D,
        .price = 0,
        .description = sHobbyLeague7participationcardDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_E] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_E,
        .price = 0,
        .description = sHobbyLeague7participationcardEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_F] =
    {
        .name = _("Hobby League "),
        .itemId = ITEM_PACK_HOBBY_LEAGUE_7_PARTICIPATION_CARD_F,
        .price = 0,
        .description = sHobbyLeague7participationcardFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_IGNITION_ASSAULT] =
    {
        .name = _("Ignition Assa"),
        .itemId = ITEM_PACK_IGNITION_ASSAULT,
        .price = 0,
        .description = sIgnitionAssaultDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_IGNITION_ASSAULT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Ignition Assa"),
        .itemId = ITEM_PACK_IGNITION_ASSAULT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sIgnitionAssaultSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_IGNITION_ASSAULT_SPECIAL_EDITION] =
    {
        .name = _("Ignition Assa"),
        .itemId = ITEM_PACK_IGNITION_ASSAULT_SPECIAL_EDITION,
        .price = 0,
        .description = sIgnitionAssaultSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_INVASION_OF_CHAOS] =
    {
        .name = _("Invasion of C"),
        .itemId = ITEM_PACK_INVASION_OF_CHAOS,
        .price = 0,
        .description = sInvasionofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_INVASION_OF_CHAOS_SPECIAL_EDITION] =
    {
        .name = _("Invasion of C"),
        .itemId = ITEM_PACK_INVASION_OF_CHAOS_SPECIAL_EDITION,
        .price = 0,
        .description = sInvasionofChaosSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_INVASION_VENGEANCE] =
    {
        .name = _("Invasion: Ven"),
        .itemId = ITEM_PACK_INVASION_VENGEANCE,
        .price = 0,
        .description = sInvasionVengeanceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_INVASION_VENGEANCE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Invasion: Ven"),
        .itemId = ITEM_PACK_INVASION_VENGEANCE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sInvasionVengeanceSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_INVASION_VENGEANCE_SPECIAL_EDITION] =
    {
        .name = _("Invasion: Ven"),
        .itemId = ITEM_PACK_INVASION_VENGEANCE_SPECIAL_EDITION,
        .price = 0,
        .description = sInvasionVengeanceSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_JUDGMENT_OF_THE_LIGHT] =
    {
        .name = _("Judgment of t"),
        .itemId = ITEM_PACK_JUDGMENT_OF_THE_LIGHT,
        .price = 0,
        .description = sJudgmentoftheLightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_JUDGMENT_OF_THE_LIGHT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Judgment of t"),
        .itemId = ITEM_PACK_JUDGMENT_OF_THE_LIGHT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sJudgmentoftheLightSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_JUDGMENT_OF_THE_LIGHT_DELUXE_EDITION] =
    {
        .name = _("Judgment of t"),
        .itemId = ITEM_PACK_JUDGMENT_OF_THE_LIGHT_DELUXE_EDITION,
        .price = 0,
        .description = sJudgmentoftheLightDeluxeEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_KC_GRAND_TOURNAMENT_2021_PRIZE_CARD] =
    {
        .name = _("KC Grand Tour"),
        .itemId = ITEM_PACK_KC_GRAND_TOURNAMENT_2021_PRIZE_CARD,
        .price = 0,
        .description = sKCGrandTournament2021prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_KC_GRAND_TOURNAMENT_PRIZE_CARD] =
    {
        .name = _("KC Grand Tour"),
        .itemId = ITEM_PACK_KC_GRAND_TOURNAMENT_PRIZE_CARD,
        .price = 0,
        .description = sKCGrandTournamentprizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_KIDS_WB_DUEL_OF_DESTINY_PROMOTIONAL_CARD] =
    {
        .name = _("Kids WB Duel "),
        .itemId = ITEM_PACK_KIDS_WB_DUEL_OF_DESTINY_PROMOTIONAL_CARD,
        .price = 0,
        .description = sKidsWBDuelofDestinypromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_KING_S_COURT] =
    {
        .name = _("King's Court"),
        .itemId = ITEM_PACK_KING_S_COURT,
        .price = 0,
        .description = sKingsCourtDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LABYRINTH_OF_NIGHTMARE] =
    {
        .name = _("Labyrinth of "),
        .itemId = ITEM_PACK_LABYRINTH_OF_NIGHTMARE,
        .price = 0,
        .description = sLabyrinthofNightmareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGACY_OF_DARKNESS] =
    {
        .name = _("Legacy of Dar"),
        .itemId = ITEM_PACK_LEGACY_OF_DARKNESS,
        .price = 0,
        .description = sLegacyofDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGACY_OF_DESTRUCTION] =
    {
        .name = _("Legacy of Des"),
        .itemId = ITEM_PACK_LEGACY_OF_DESTRUCTION,
        .price = 0,
        .description = sLegacyofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGACY_OF_THE_VALIANT] =
    {
        .name = _("Legacy of the"),
        .itemId = ITEM_PACK_LEGACY_OF_THE_VALIANT,
        .price = 0,
        .description = sLegacyoftheValiantDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGACY_OF_THE_VALIANT_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Legacy of the"),
        .itemId = ITEM_PACK_LEGACY_OF_THE_VALIANT_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sLegacyoftheValiantSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGACY_OF_THE_VALIANT_DELUXE_EDITION] =
    {
        .name = _("Legacy of the"),
        .itemId = ITEM_PACK_LEGACY_OF_THE_VALIANT_DELUXE_EDITION,
        .price = 0,
        .description = sLegacyoftheValiantDeluxeEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGEND_OF_BLUE_EYES_WHITE_DRAGON] =
    {
        .name = _("Legend of Blu"),
        .itemId = ITEM_PACK_LEGEND_OF_BLUE_EYES_WHITE_DRAGON,
        .price = 0,
        .description = sLegendofBlueEyesWhiteDragonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION,
        .price = 0,
        .description = sLegendaryCollectionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_2_THE_DUEL_ACADEMY_YEARS] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_2_THE_DUEL_ACADEMY_YEARS,
        .price = 0,
        .description = sLegendaryCollection2TheDuelAcademyYearsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_2_THE_DUEL_ACADEMY_YEARS_MEGA_PACK] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_2_THE_DUEL_ACADEMY_YEARS_MEGA_PACK,
        .price = 0,
        .description = sLegendaryCollection2TheDuelAcademyYearsMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_3_YUGI_S_WORLD] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_3_YUGI_S_WORLD,
        .price = 0,
        .description = sLegendaryCollection3YugisWorldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_3_YUGI_S_WORLD_MEGA_PACK] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_3_YUGI_S_WORLD_MEGA_PACK,
        .price = 0,
        .description = sLegendaryCollection3YugisWorldMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_4_JOEY_S_WORLD] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_4_JOEY_S_WORLD,
        .price = 0,
        .description = sLegendaryCollection4JoeysWorldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_4_JOEY_S_WORLD_MEGA_PACK] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_4_JOEY_S_WORLD_MEGA_PACK,
        .price = 0,
        .description = sLegendaryCollection4JoeysWorldMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_5D_S] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_5D_S,
        .price = 0,
        .description = sLegendaryCollection5DsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_5D_S_MEGA_PACK] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_5D_S_MEGA_PACK,
        .price = 0,
        .description = sLegendaryCollection5DsMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_KAIBA] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_KAIBA,
        .price = 0,
        .description = sLegendaryCollectionKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_KAIBA_MEGA_PACK] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_KAIBA_MEGA_PACK,
        .price = 0,
        .description = sLegendaryCollectionKaibaMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_COLLECTION_25TH_ANNIVERSARY_EDITION] =
    {
        .name = _("Legendary Col"),
        .itemId = ITEM_PACK_LEGENDARY_COLLECTION_25TH_ANNIVERSARY_EDITION,
        .price = 0,
        .description = sLegendaryCollection25thAnniversaryEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DECKS_II] =
    {
        .name = _("Legendary Dec"),
        .itemId = ITEM_PACK_LEGENDARY_DECKS_II,
        .price = 0,
        .description = sLegendaryDecksIIDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DRAGON_DECKS] =
    {
        .name = _("Legendary Dra"),
        .itemId = ITEM_PACK_LEGENDARY_DRAGON_DECKS,
        .price = 0,
        .description = sLegendaryDragonDecksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS,
        .price = 0,
        .description = sLegendaryDuelistsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_ANCIENT_MILLENNIUM] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_ANCIENT_MILLENNIUM,
        .price = 0,
        .description = sLegendaryDuelistsAncientMillenniumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_DUELS_FROM_THE_DEEP] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_DUELS_FROM_THE_DEEP,
        .price = 0,
        .description = sLegendaryDuelistsDuelsFromtheDeepDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_IMMORTAL_DESTINY] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_IMMORTAL_DESTINY,
        .price = 0,
        .description = sLegendaryDuelistsImmortalDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_MAGICAL_HERO] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_MAGICAL_HERO,
        .price = 0,
        .description = sLegendaryDuelistsMagicalHeroDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_RAGE_OF_RA] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_RAGE_OF_RA,
        .price = 0,
        .description = sLegendaryDuelistsRageofRaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SEASON_1] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SEASON_1,
        .price = 0,
        .description = sLegendaryDuelistsSeason1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SEASON_2] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SEASON_2,
        .price = 0,
        .description = sLegendaryDuelistsSeason2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SEASON_3] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SEASON_3,
        .price = 0,
        .description = sLegendaryDuelistsSeason3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SISTERS_OF_THE_ROSE] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SISTERS_OF_THE_ROSE,
        .price = 0,
        .description = sLegendaryDuelistsSistersoftheRoseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SOULBURNING_VOLCANO] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SOULBURNING_VOLCANO,
        .price = 0,
        .description = sLegendaryDuelistsSoulburningVolcanoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_SYNCHRO_STORM] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_SYNCHRO_STORM,
        .price = 0,
        .description = sLegendaryDuelistsSynchroStormDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_DUELISTS_WHITE_DRAGON_ABYSS] =
    {
        .name = _("Legendary Due"),
        .itemId = ITEM_PACK_LEGENDARY_DUELISTS_WHITE_DRAGON_ABYSS,
        .price = 0,
        .description = sLegendaryDuelistsWhiteDragonAbyssDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LEGENDARY_HERO_DECKS] =
    {
        .name = _("Legendary Her"),
        .itemId = ITEM_PACK_LEGENDARY_HERO_DECKS,
        .price = 0,
        .description = sLegendaryHeroDecksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHT_AND_DARKNESS_POWER_PACK] =
    {
        .name = _("Light and Dar"),
        .itemId = ITEM_PACK_LIGHT_AND_DARKNESS_POWER_PACK,
        .price = 0,
        .description = sLightandDarknessPowerPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHT_OF_DESTRUCTION] =
    {
        .name = _("Light of Dest"),
        .itemId = ITEM_PACK_LIGHT_OF_DESTRUCTION,
        .price = 0,
        .description = sLightofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHT_OF_DESTRUCTION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Light of Dest"),
        .itemId = ITEM_PACK_LIGHT_OF_DESTRUCTION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sLightofDestructionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHT_OF_DESTRUCTION_SPECIAL_EDITION] =
    {
        .name = _("Light of Dest"),
        .itemId = ITEM_PACK_LIGHT_OF_DESTRUCTION_SPECIAL_EDITION,
        .price = 0,
        .description = sLightofDestructionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHTNING_OVERDRIVE] =
    {
        .name = _("Lightning Ove"),
        .itemId = ITEM_PACK_LIGHTNING_OVERDRIVE,
        .price = 0,
        .description = sLightningOverdriveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIGHTNING_OVERDRIVE_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Lightning Ove"),
        .itemId = ITEM_PACK_LIGHTNING_OVERDRIVE_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sLightningOverdrivePremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LIMITED_EDITION_1] =
    {
        .name = _("Limited Editi"),
        .itemId = ITEM_PACK_LIMITED_EDITION_1,
        .price = 0,
        .description = sLimitedEdition1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LORD_OF_THE_TACHYON_GALAXY] =
    {
        .name = _("Lord of the T"),
        .itemId = ITEM_PACK_LORD_OF_THE_TACHYON_GALAXY,
        .price = 0,
        .description = sLordoftheTachyonGalaxyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LORD_OF_THE_TACHYON_GALAXY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Lord of the T"),
        .itemId = ITEM_PACK_LORD_OF_THE_TACHYON_GALAXY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sLordoftheTachyonGalaxySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_LOST_SANCTUARY_STRUCTURE_DECK] =
    {
        .name = _("Lost Sanctuar"),
        .itemId = ITEM_PACK_LOST_SANCTUARY_STRUCTURE_DECK,
        .price = 0,
        .description = sLostSanctuaryStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MACHINA_MAYHEM_STRUCTURE_DECK] =
    {
        .name = _("Machina Mayhe"),
        .itemId = ITEM_PACK_MACHINA_MAYHEM_STRUCTURE_DECK,
        .price = 0,
        .description = sMachinaMayhemStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MACHINE_REACTOR_STRUCTURE_DECK] =
    {
        .name = _("Machine React"),
        .itemId = ITEM_PACK_MACHINE_REACTOR_STRUCTURE_DECK,
        .price = 0,
        .description = sMachineReactorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAGIC_RULER] =
    {
        .name = _("Magic Ruler"),
        .itemId = ITEM_PACK_MAGIC_RULER,
        .price = 0,
        .description = sMagicRulerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAGICIAN_S_FORCE] =
    {
        .name = _("Magician's Fo"),
        .itemId = ITEM_PACK_MAGICIAN_S_FORCE,
        .price = 0,
        .description = sMagiciansForceDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAGNIFICENT_MAVENS] =
    {
        .name = _("Magnificent M"),
        .itemId = ITEM_PACK_MAGNIFICENT_MAVENS,
        .price = 0,
        .description = sMagnificentMavensDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAKE_A_WISH_FOUNDATION_PROMOTIONAL_CARD] =
    {
        .name = _("Make-A-Wish F"),
        .itemId = ITEM_PACK_MAKE_A_WISH_FOUNDATION_PROMOTIONAL_CARD,
        .price = 0,
        .description = sMakeAWishFoundationpromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MASTER_COLLECTION_VOLUME_1] =
    {
        .name = _("Master Collec"),
        .itemId = ITEM_PACK_MASTER_COLLECTION_VOLUME_1,
        .price = 0,
        .description = sMasterCollectionVolume1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MASTER_COLLECTION_VOLUME_2] =
    {
        .name = _("Master Collec"),
        .itemId = ITEM_PACK_MASTER_COLLECTION_VOLUME_2,
        .price = 0,
        .description = sMasterCollectionVolume2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MASTER_OF_PENDULUM_STRUCTURE_DECK] =
    {
        .name = _("Master of Pen"),
        .itemId = ITEM_PACK_MASTER_OF_PENDULUM_STRUCTURE_DECK,
        .price = 0,
        .description = sMasterofPendulumStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_1] =
    {
        .name = _("Mattel Action"),
        .itemId = ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_1,
        .price = 0,
        .description = sMattelActionFigurepromotionalcardsSeries1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_2] =
    {
        .name = _("Mattel Action"),
        .itemId = ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_2,
        .price = 0,
        .description = sMattelActionFigurepromotionalcardsSeries2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_3] =
    {
        .name = _("Mattel Action"),
        .itemId = ITEM_PACK_MATTEL_ACTION_FIGURE_PROMOTIONAL_CARDS_SERIES_3,
        .price = 0,
        .description = sMattelActionFigurepromotionalcardsSeries3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAXIMUM_CRISIS] =
    {
        .name = _("Maximum Crisi"),
        .itemId = ITEM_PACK_MAXIMUM_CRISIS,
        .price = 0,
        .description = sMaximumCrisisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAXIMUM_CRISIS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Maximum Crisi"),
        .itemId = ITEM_PACK_MAXIMUM_CRISIS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sMaximumCrisisSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAXIMUM_CRISIS_SPECIAL_EDITION] =
    {
        .name = _("Maximum Crisi"),
        .itemId = ITEM_PACK_MAXIMUM_CRISIS_SPECIAL_EDITION,
        .price = 0,
        .description = sMaximumCrisisSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAXIMUM_GOLD] =
    {
        .name = _("Maximum Gold"),
        .itemId = ITEM_PACK_MAXIMUM_GOLD,
        .price = 0,
        .description = sMaximumGoldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAXIMUM_GOLD_EL_DORADO] =
    {
        .name = _("Maximum Gold:"),
        .itemId = ITEM_PACK_MAXIMUM_GOLD_EL_DORADO,
        .price = 0,
        .description = sMaximumGoldElDoradoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAZE_OF_MEMORIES] =
    {
        .name = _("Maze of Memor"),
        .itemId = ITEM_PACK_MAZE_OF_MEMORIES,
        .price = 0,
        .description = sMazeofMemoriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAZE_OF_MILLENNIA] =
    {
        .name = _("Maze of Mille"),
        .itemId = ITEM_PACK_MAZE_OF_MILLENNIA,
        .price = 0,
        .description = sMazeofMillenniaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MAZE_OF_THE_MASTER] =
    {
        .name = _("Maze of the M"),
        .itemId = ITEM_PACK_MAZE_OF_THE_MASTER,
        .price = 0,
        .description = sMazeoftheMasterDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MCDONALD_S_PROMOTIONAL_CARDS] =
    {
        .name = _("McDonald's Pr"),
        .itemId = ITEM_PACK_MCDONALD_S_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sMcDonaldsPromotionalCardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MCDONALD_S_PROMOTIONAL_CARDS_2] =
    {
        .name = _("McDonald's Pr"),
        .itemId = ITEM_PACK_MCDONALD_S_PROMOTIONAL_CARDS_2,
        .price = 0,
        .description = sMcDonaldsPromotionalCards2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_METAL_RAIDERS] =
    {
        .name = _("Metal Raiders"),
        .itemId = ITEM_PACK_METAL_RAIDERS,
        .price = 0,
        .description = sMetalRaidersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MILLENNIUM_PACK] =
    {
        .name = _("Millennium Pa"),
        .itemId = ITEM_PACK_MILLENNIUM_PACK,
        .price = 0,
        .description = sMillenniumPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MOVIE_PACK] =
    {
        .name = _("Movie Pack"),
        .itemId = ITEM_PACK_MOVIE_PACK,
        .price = 0,
        .description = sMoviePackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_MYSTIC_FIGHTERS] =
    {
        .name = _("Mystic Fighte"),
        .itemId = ITEM_PACK_MYSTIC_FIGHTERS,
        .price = 0,
        .description = sMysticFightersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_NOBLE_KNIGHTS_OF_THE_ROUND_TABLE_BOX_SET] =
    {
        .name = _("Noble Knights"),
        .itemId = ITEM_PACK_NOBLE_KNIGHTS_OF_THE_ROUND_TABLE_BOX_SET,
        .price = 0,
        .description = sNobleKnightsoftheRoundTableBoxSetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_NOBLE_KNIGHTS_OF_THE_ROUND_TABLE_POWER_UP_PACK] =
    {
        .name = _("Noble Knights"),
        .itemId = ITEM_PACK_NOBLE_KNIGHTS_OF_THE_ROUND_TABLE_POWER_UP_PACK,
        .price = 0,
        .description = sNobleKnightsoftheRoundTablePowerUpPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_NUMBER_HUNTERS] =
    {
        .name = _("Number Hunter"),
        .itemId = ITEM_PACK_NUMBER_HUNTERS,
        .price = 0,
        .description = sNumberHuntersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_1] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_1,
        .price = 0,
        .description = sOTSTournamentPack1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_10] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_10,
        .price = 0,
        .description = sOTSTournamentPack10Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_10_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_10_POR_,
        .price = 0,
        .description = sOTSTournamentPack10PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_11] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_11,
        .price = 0,
        .description = sOTSTournamentPack11Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_11_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_11_POR_,
        .price = 0,
        .description = sOTSTournamentPack11PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_12] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_12,
        .price = 0,
        .description = sOTSTournamentPack12Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_12_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_12_POR_,
        .price = 0,
        .description = sOTSTournamentPack12PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_13] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_13,
        .price = 0,
        .description = sOTSTournamentPack13Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_13_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_13_POR_,
        .price = 0,
        .description = sOTSTournamentPack13PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_14] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_14,
        .price = 0,
        .description = sOTSTournamentPack14Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_14_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_14_POR_,
        .price = 0,
        .description = sOTSTournamentPack14PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_15] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_15,
        .price = 0,
        .description = sOTSTournamentPack15Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_15_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_15_POR_,
        .price = 0,
        .description = sOTSTournamentPack15PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_16] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_16,
        .price = 0,
        .description = sOTSTournamentPack16Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_16_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_16_POR_,
        .price = 0,
        .description = sOTSTournamentPack16PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_17] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_17,
        .price = 0,
        .description = sOTSTournamentPack17Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_17_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_17_POR_,
        .price = 0,
        .description = sOTSTournamentPack17PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_18] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_18,
        .price = 0,
        .description = sOTSTournamentPack18Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_18_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_18_POR_,
        .price = 0,
        .description = sOTSTournamentPack18PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_19] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_19,
        .price = 0,
        .description = sOTSTournamentPack19Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_19_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_19_POR_,
        .price = 0,
        .description = sOTSTournamentPack19PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_2] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_2,
        .price = 0,
        .description = sOTSTournamentPack2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_20] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_20,
        .price = 0,
        .description = sOTSTournamentPack20Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_21] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_21,
        .price = 0,
        .description = sOTSTournamentPack21Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_22] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_22,
        .price = 0,
        .description = sOTSTournamentPack22Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_23] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_23,
        .price = 0,
        .description = sOTSTournamentPack23Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_24] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_24,
        .price = 0,
        .description = sOTSTournamentPack24Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_25] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_25,
        .price = 0,
        .description = sOTSTournamentPack25Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_26] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_26,
        .price = 0,
        .description = sOTSTournamentPack26Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_27] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_27,
        .price = 0,
        .description = sOTSTournamentPack27Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_28] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_28,
        .price = 0,
        .description = sOTSTournamentPack28Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_3] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_3,
        .price = 0,
        .description = sOTSTournamentPack3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_4] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_4,
        .price = 0,
        .description = sOTSTournamentPack4Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_5] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_5,
        .price = 0,
        .description = sOTSTournamentPack5Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_6] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_6,
        .price = 0,
        .description = sOTSTournamentPack6Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_7] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_7,
        .price = 0,
        .description = sOTSTournamentPack7Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_7_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_7_POR_,
        .price = 0,
        .description = sOTSTournamentPack7PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_8] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_8,
        .price = 0,
        .description = sOTSTournamentPack8Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_8_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_8_POR_,
        .price = 0,
        .description = sOTSTournamentPack8PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_9] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_9,
        .price = 0,
        .description = sOTSTournamentPack9Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_OTS_TOURNAMENT_PACK_9_POR_] =
    {
        .name = _("OTS Tournamen"),
        .itemId = ITEM_PACK_OTS_TOURNAMENT_PACK_9_POR_,
        .price = 0,
        .description = sOTSTournamentPack9PORDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ONSLAUGHT_OF_THE_FIRE_KINGS_STRUCTURE_DECK] =
    {
        .name = _("Onslaught of "),
        .itemId = ITEM_PACK_ONSLAUGHT_OF_THE_FIRE_KINGS_STRUCTURE_DECK,
        .price = 0,
        .description = sOnslaughtoftheFireKingsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ORDER_OF_CHAOS] =
    {
        .name = _("Order of Chao"),
        .itemId = ITEM_PACK_ORDER_OF_CHAOS,
        .price = 0,
        .description = sOrderofChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ORDER_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Order of Chao"),
        .itemId = ITEM_PACK_ORDER_OF_CHAOS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sOrderofChaosSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ORDER_OF_CHAOS_SPECIAL_EDITION] =
    {
        .name = _("Order of Chao"),
        .itemId = ITEM_PACK_ORDER_OF_CHAOS_SPECIAL_EDITION,
        .price = 0,
        .description = sOrderofChaosSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PALLADIUM_ORACLE_MAHAD_SWEEPSTAKES] =
    {
        .name = _("Palladium Ora"),
        .itemId = ITEM_PACK_PALLADIUM_ORACLE_MAHAD_SWEEPSTAKES,
        .price = 0,
        .description = sPalladiumOracleMahadSweepstakesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PENDULUM_DOMINATION_STRUCTURE_DECK] =
    {
        .name = _("Pendulum Domi"),
        .itemId = ITEM_PACK_PENDULUM_DOMINATION_STRUCTURE_DECK,
        .price = 0,
        .description = sPendulumDominationStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PENDULUM_EVOLUTION] =
    {
        .name = _("Pendulum Evol"),
        .itemId = ITEM_PACK_PENDULUM_EVOLUTION,
        .price = 0,
        .description = sPendulumEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_DARKNESS] =
    {
        .name = _("Phantom Darkn"),
        .itemId = ITEM_PACK_PHANTOM_DARKNESS,
        .price = 0,
        .description = sPhantomDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_DARKNESS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Phantom Darkn"),
        .itemId = ITEM_PACK_PHANTOM_DARKNESS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sPhantomDarknessSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_DARKNESS_SPECIAL_EDITION] =
    {
        .name = _("Phantom Darkn"),
        .itemId = ITEM_PACK_PHANTOM_DARKNESS_SPECIAL_EDITION,
        .price = 0,
        .description = sPhantomDarknessSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_NIGHTMARE] =
    {
        .name = _("Phantom Night"),
        .itemId = ITEM_PACK_PHANTOM_NIGHTMARE,
        .price = 0,
        .description = sPhantomNightmareDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_RAGE] =
    {
        .name = _("Phantom Rage"),
        .itemId = ITEM_PACK_PHANTOM_RAGE,
        .price = 0,
        .description = sPhantomRageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHANTOM_RAGE_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Phantom Rage "),
        .itemId = ITEM_PACK_PHANTOM_RAGE_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sPhantomRagePremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHARAOH_TOUR_2005_PROMOTIONAL_CARDS] =
    {
        .name = _("Pharaoh Tour "),
        .itemId = ITEM_PACK_PHARAOH_TOUR_2005_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sPharaohTour2005promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHARAOH_TOUR_2006_PROMOTIONAL_CARDS] =
    {
        .name = _("Pharaoh Tour "),
        .itemId = ITEM_PACK_PHARAOH_TOUR_2006_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sPharaohTour2006promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHARAOH_TOUR_2007_PROMOTIONAL_CARDS] =
    {
        .name = _("Pharaoh Tour "),
        .itemId = ITEM_PACK_PHARAOH_TOUR_2007_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sPharaohTour2007promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHARAOH_S_SERVANT] =
    {
        .name = _("Pharaoh's Ser"),
        .itemId = ITEM_PACK_PHARAOH_S_SERVANT,
        .price = 0,
        .description = sPharaohsServantDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHARAONIC_GUARDIAN] =
    {
        .name = _("Pharaonic Gua"),
        .itemId = ITEM_PACK_PHARAONIC_GUARDIAN,
        .price = 0,
        .description = sPharaonicGuardianDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHOTON_HYPERNOVA] =
    {
        .name = _("Photon Hypern"),
        .itemId = ITEM_PACK_PHOTON_HYPERNOVA,
        .price = 0,
        .description = sPhotonHypernovaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHOTON_SHOCKWAVE] =
    {
        .name = _("Photon Shockw"),
        .itemId = ITEM_PACK_PHOTON_SHOCKWAVE,
        .price = 0,
        .description = sPhotonShockwaveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PHOTON_SHOCKWAVE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Photon Shockw"),
        .itemId = ITEM_PACK_PHOTON_SHOCKWAVE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sPhotonShockwaveSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_POWER_OF_THE_DUELIST] =
    {
        .name = _("Power of the "),
        .itemId = ITEM_PACK_POWER_OF_THE_DUELIST,
        .price = 0,
        .description = sPoweroftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_POWER_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Power of the "),
        .itemId = ITEM_PACK_POWER_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sPoweroftheDuelistSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_POWER_OF_THE_ELEMENTS] =
    {
        .name = _("Power of the "),
        .itemId = ITEM_PACK_POWER_OF_THE_ELEMENTS,
        .price = 0,
        .description = sPoweroftheElementsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_COLLECTION_TIN] =
    {
        .name = _("Premium Colle"),
        .itemId = ITEM_PACK_PREMIUM_COLLECTION_TIN,
        .price = 0,
        .description = sPremiumCollectionTinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_GOLD] =
    {
        .name = _("Premium Gold"),
        .itemId = ITEM_PACK_PREMIUM_GOLD,
        .price = 0,
        .description = sPremiumGoldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_GOLD_INFINITE_GOLD] =
    {
        .name = _("Premium Gold:"),
        .itemId = ITEM_PACK_PREMIUM_GOLD_INFINITE_GOLD,
        .price = 0,
        .description = sPremiumGoldInfiniteGoldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_GOLD_RETURN_OF_THE_BLING] =
    {
        .name = _("Premium Gold:"),
        .itemId = ITEM_PACK_PREMIUM_GOLD_RETURN_OF_THE_BLING,
        .price = 0,
        .description = sPremiumGoldReturnoftheBlingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_PACK_TCG_] =
    {
        .name = _("Premium Pack "),
        .itemId = ITEM_PACK_PREMIUM_PACK_TCG_,
        .price = 0,
        .description = sPremiumPackTCGDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PREMIUM_PACK_2_TCG_] =
    {
        .name = _("Premium Pack "),
        .itemId = ITEM_PACK_PREMIUM_PACK_2_TCG_,
        .price = 0,
        .description = sPremiumPack2TCGDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PRIMAL_ORIGIN] =
    {
        .name = _("Primal Origin"),
        .itemId = ITEM_PACK_PRIMAL_ORIGIN,
        .price = 0,
        .description = sPrimalOriginDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PRIMAL_ORIGIN_PLUS] =
    {
        .name = _("Primal Origin"),
        .itemId = ITEM_PACK_PRIMAL_ORIGIN_PLUS,
        .price = 0,
        .description = sPrimalOriginPlusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PRIMAL_ORIGIN_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Primal Origin"),
        .itemId = ITEM_PACK_PRIMAL_ORIGIN_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sPrimalOriginSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_PRIMAL_ORIGIN_DELUXE_EDITION] =
    {
        .name = _("Primal Origin"),
        .itemId = ITEM_PACK_PRIMAL_ORIGIN_DELUXE_EDITION,
        .price = 0,
        .description = sPrimalOriginDeluxeEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_QUARTER_CENTURY_BONANZA] =
    {
        .name = _("Quarter Centu"),
        .itemId = ITEM_PACK_QUARTER_CENTURY_BONANZA,
        .price = 0,
        .description = sQuarterCenturyBonanzaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_QUARTER_CENTURY_STAMPEDE] =
    {
        .name = _("Quarter Centu"),
        .itemId = ITEM_PACK_QUARTER_CENTURY_STAMPEDE,
        .price = 0,
        .description = sQuarterCenturyStampedeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RA_YELLOW_MEGA_PACK] =
    {
        .name = _("Ra Yellow Meg"),
        .itemId = ITEM_PACK_RA_YELLOW_MEGA_PACK,
        .price = 0,
        .description = sRaYellowMegaPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RA_YELLOW_MEGA_PACK_SPECIAL_EDITION] =
    {
        .name = _("Ra Yellow Meg"),
        .itemId = ITEM_PACK_RA_YELLOW_MEGA_PACK_SPECIAL_EDITION,
        .price = 0,
        .description = sRaYellowMegaPackSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGE_OF_THE_ABYSS] =
    {
        .name = _("Rage of the A"),
        .itemId = ITEM_PACK_RAGE_OF_THE_ABYSS,
        .price = 0,
        .description = sRageoftheAbyssDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_BATTLE] =
    {
        .name = _("Raging Battle"),
        .itemId = ITEM_PACK_RAGING_BATTLE,
        .price = 0,
        .description = sRagingBattleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_BATTLE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Raging Battle"),
        .itemId = ITEM_PACK_RAGING_BATTLE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sRagingBattleSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_BATTLE_SPECIAL_EDITION] =
    {
        .name = _("Raging Battle"),
        .itemId = ITEM_PACK_RAGING_BATTLE_SPECIAL_EDITION,
        .price = 0,
        .description = sRagingBattleSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_TEMPEST] =
    {
        .name = _("Raging Tempes"),
        .itemId = ITEM_PACK_RAGING_TEMPEST,
        .price = 0,
        .description = sRagingTempestDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_TEMPEST_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Raging Tempes"),
        .itemId = ITEM_PACK_RAGING_TEMPEST_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sRagingTempestSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RAGING_TEMPEST_SPECIAL_EDITION] =
    {
        .name = _("Raging Tempes"),
        .itemId = ITEM_PACK_RAGING_TEMPEST_SPECIAL_EDITION,
        .price = 0,
        .description = sRagingTempestSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_REALM_OF_LIGHT_STRUCTURE_DECK] =
    {
        .name = _("Realm of Ligh"),
        .itemId = ITEM_PACK_REALM_OF_LIGHT_STRUCTURE_DECK,
        .price = 0,
        .description = sRealmofLightStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_REALM_OF_THE_SEA_EMPEROR_STRUCTURE_DECK] =
    {
        .name = _("Realm of the "),
        .itemId = ITEM_PACK_REALM_OF_THE_SEA_EMPEROR_STRUCTURE_DECK,
        .price = 0,
        .description = sRealmoftheSeaEmperorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_REMOTE_DUEL_AT_HOME_SWEEPSTAKES] =
    {
        .name = _("Remote Duel a"),
        .itemId = ITEM_PACK_REMOTE_DUEL_AT_HOME_SWEEPSTAKES,
        .price = 0,
        .description = sRemoteDuelatHomeSweepstakesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RETRO_PACK] =
    {
        .name = _("Retro Pack"),
        .itemId = ITEM_PACK_RETRO_PACK,
        .price = 0,
        .description = sRetroPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RETRO_PACK_2] =
    {
        .name = _("Retro Pack 2"),
        .itemId = ITEM_PACK_RETRO_PACK_2,
        .price = 0,
        .description = sRetroPack2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RETURN_OF_THE_DUELIST] =
    {
        .name = _("Return of the"),
        .itemId = ITEM_PACK_RETURN_OF_THE_DUELIST,
        .price = 0,
        .description = sReturnoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RETURN_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Return of the"),
        .itemId = ITEM_PACK_RETURN_OF_THE_DUELIST_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sReturnoftheDuelistSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RETURN_OF_THE_DUELIST_SPECIAL_EDITION] =
    {
        .name = _("Return of the"),
        .itemId = ITEM_PACK_RETURN_OF_THE_DUELIST_SPECIAL_EDITION,
        .price = 0,
        .description = sReturnoftheDuelistSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_DESTINY] =
    {
        .name = _("Rise of Desti"),
        .itemId = ITEM_PACK_RISE_OF_DESTINY,
        .price = 0,
        .description = sRiseofDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_DESTINY_SPECIAL_EDITION] =
    {
        .name = _("Rise of Desti"),
        .itemId = ITEM_PACK_RISE_OF_DESTINY_SPECIAL_EDITION,
        .price = 0,
        .description = sRiseofDestinySpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_THE_DRAGON_LORDS_STRUCTURE_DECK] =
    {
        .name = _("Rise of the D"),
        .itemId = ITEM_PACK_RISE_OF_THE_DRAGON_LORDS_STRUCTURE_DECK,
        .price = 0,
        .description = sRiseoftheDragonLordsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_THE_DUELIST] =
    {
        .name = _("Rise of the D"),
        .itemId = ITEM_PACK_RISE_OF_THE_DUELIST,
        .price = 0,
        .description = sRiseoftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_THE_DUELIST_PREMIERE_PROMOTIONAL_CARD] =
    {
        .name = _("Rise of the D"),
        .itemId = ITEM_PACK_RISE_OF_THE_DUELIST_PREMIERE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sRiseoftheDuelistPremierepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISE_OF_THE_TRUE_DRAGONS_STRUCTURE_DECK] =
    {
        .name = _("Rise of the T"),
        .itemId = ITEM_PACK_RISE_OF_THE_TRUE_DRAGONS_STRUCTURE_DECK,
        .price = 0,
        .description = sRiseoftheTrueDragonsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISING_RAMPAGE] =
    {
        .name = _("Rising Rampag"),
        .itemId = ITEM_PACK_RISING_RAMPAGE,
        .price = 0,
        .description = sRisingRampageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISING_RAMPAGE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Rising Rampag"),
        .itemId = ITEM_PACK_RISING_RAMPAGE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sRisingRampageSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_RISING_RAMPAGE_SPECIAL_EDITION] =
    {
        .name = _("Rising Rampag"),
        .itemId = ITEM_PACK_RISING_RAMPAGE_SPECIAL_EDITION,
        .price = 0,
        .description = sRisingRampageSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SJ_JUMP_PACK_SPRING_2020_PROMOTIONAL_CARD] =
    {
        .name = _("SJ Jump Pack "),
        .itemId = ITEM_PACK_SJ_JUMP_PACK_SPRING_2020_PROMOTIONAL_CARD,
        .price = 0,
        .description = sSJJumpPackSpring2020promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SABER_FORCE_STARTER_DECK] =
    {
        .name = _("Saber Force S"),
        .itemId = ITEM_PACK_SABER_FORCE_STARTER_DECK,
        .price = 0,
        .description = sSaberForceStarterDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAGA_OF_BLUE_EYES_WHITE_DRAGON_STRUCTURE_DECK] =
    {
        .name = _("Saga of Blue-"),
        .itemId = ITEM_PACK_SAGA_OF_BLUE_EYES_WHITE_DRAGON_STRUCTURE_DECK,
        .price = 0,
        .description = sSagaofBlueEyesWhiteDragonStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAMURAI_ASSAULT] =
    {
        .name = _("Samurai Assau"),
        .itemId = ITEM_PACK_SAMURAI_ASSAULT,
        .price = 0,
        .description = sSamuraiAssaultDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAMURAI_WARLORDS_STRUCTURE_DECK] =
    {
        .name = _("Samurai Warlo"),
        .itemId = ITEM_PACK_SAMURAI_WARLORDS_STRUCTURE_DECK,
        .price = 0,
        .description = sSamuraiWarlordsStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAN_DIEGO_COMIC_CON_PROMOTIONAL_CARDS] =
    {
        .name = _("San Diego Com"),
        .itemId = ITEM_PACK_SAN_DIEGO_COMIC_CON_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sSanDiegoComicConpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAVAGE_STRIKE] =
    {
        .name = _("Savage Strike"),
        .itemId = ITEM_PACK_SAVAGE_STRIKE,
        .price = 0,
        .description = sSavageStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAVAGE_STRIKE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Savage Strike"),
        .itemId = ITEM_PACK_SAVAGE_STRIKE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sSavageStrikeSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SAVAGE_STRIKE_SPECIAL_EDITION] =
    {
        .name = _("Savage Strike"),
        .itemId = ITEM_PACK_SAVAGE_STRIKE_SPECIAL_EDITION,
        .price = 0,
        .description = sSavageStrikeSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SECRET_SLAYERS] =
    {
        .name = _("Secret Slayer"),
        .itemId = ITEM_PACK_SECRET_SLAYERS,
        .price = 0,
        .description = sSecretSlayersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SECRETS_OF_ETERNITY] =
    {
        .name = _("Secrets of Et"),
        .itemId = ITEM_PACK_SECRETS_OF_ETERNITY,
        .price = 0,
        .description = sSecretsofEternityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SECRETS_OF_ETERNITY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Secrets of Et"),
        .itemId = ITEM_PACK_SECRETS_OF_ETERNITY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sSecretsofEternitySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SECRETS_OF_ETERNITY_SUPER_EDITION] =
    {
        .name = _("Secrets of Et"),
        .itemId = ITEM_PACK_SECRETS_OF_ETERNITY_SUPER_EDITION,
        .price = 0,
        .description = sSecretsofEternitySuperEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_SPECTERS] =
    {
        .name = _("Shadow Specte"),
        .itemId = ITEM_PACK_SHADOW_SPECTERS,
        .price = 0,
        .description = sShadowSpectersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_SPECTERS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Shadow Specte"),
        .itemId = ITEM_PACK_SHADOW_SPECTERS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sShadowSpectersSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_SPECTERS_SPECIAL_EDITION] =
    {
        .name = _("Shadow Specte"),
        .itemId = ITEM_PACK_SHADOW_SPECTERS_SPECIAL_EDITION,
        .price = 0,
        .description = sShadowSpectersSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_OF_INFINITY] =
    {
        .name = _("Shadow of Inf"),
        .itemId = ITEM_PACK_SHADOW_OF_INFINITY,
        .price = 0,
        .description = sShadowofInfinityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_OF_INFINITY_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Shadow of Inf"),
        .itemId = ITEM_PACK_SHADOW_OF_INFINITY_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sShadowofInfinitySneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOW_OF_INFINITY_SPECIAL_EDITION] =
    {
        .name = _("Shadow of Inf"),
        .itemId = ITEM_PACK_SHADOW_OF_INFINITY_SPECIAL_EDITION,
        .price = 0,
        .description = sShadowofInfinitySpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHADOWS_IN_VALHALLA] =
    {
        .name = _("Shadows in Va"),
        .itemId = ITEM_PACK_SHADOWS_IN_VALHALLA,
        .price = 0,
        .description = sShadowsinValhallaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHINING_VICTORIES] =
    {
        .name = _("Shining Victo"),
        .itemId = ITEM_PACK_SHINING_VICTORIES,
        .price = 0,
        .description = sShiningVictoriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHINING_VICTORIES_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Shining Victo"),
        .itemId = ITEM_PACK_SHINING_VICTORIES_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sShiningVictoriesSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHINING_VICTORIES_SPECIAL_EDITION] =
    {
        .name = _("Shining Victo"),
        .itemId = ITEM_PACK_SHINING_VICTORIES_SPECIAL_EDITION,
        .price = 0,
        .description = sShiningVictoriesSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_2007_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump 2"),
        .itemId = ITEM_PACK_SHONEN_JUMP_2007_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJump2007subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2004_PRIZE_CARD] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2004_PRIZE_CARD,
        .price = 0,
        .description = sShonenJumpChampionship2004PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2005_PRIZE_CARD] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2005_PRIZE_CARD,
        .price = 0,
        .description = sShonenJumpChampionship2005PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2006_PRIZE_CARD] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2006_PRIZE_CARD,
        .price = 0,
        .description = sShonenJumpChampionship2006PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2007_PRIZE_CARD_A] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2007_PRIZE_CARD_A,
        .price = 0,
        .description = sShonenJumpChampionship2007PrizeCardADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2007_PRIZE_CARD_B] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2007_PRIZE_CARD_B,
        .price = 0,
        .description = sShonenJumpChampionship2007PrizeCardBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2008_PRIZE_CARD] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2008_PRIZE_CARD,
        .price = 0,
        .description = sShonenJumpChampionship2008PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2009_PRIZE_CARD] =
    {
        .name = _("Shonen Jump C"),
        .itemId = ITEM_PACK_SHONEN_JUMP_CHAMPIONSHIP_2009_PRIZE_CARD,
        .price = 0,
        .description = sShonenJumpChampionship2009PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_DECEMBER_2010_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump D"),
        .itemId = ITEM_PACK_SHONEN_JUMP_DECEMBER_2010_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpDecember2010subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_DECEMBER_2011_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump D"),
        .itemId = ITEM_PACK_SHONEN_JUMP_DECEMBER_2011_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpDecember2011subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_FEBRUARY_2009_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump F"),
        .itemId = ITEM_PACK_SHONEN_JUMP_FEBRUARY_2009_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpFebruary2009subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_JUNE_JULY_2011_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump J"),
        .itemId = ITEM_PACK_SHONEN_JUMP_JUNE_JULY_2011_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpJuneJuly2011subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_MARCH_2010_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump M"),
        .itemId = ITEM_PACK_SHONEN_JUMP_MARCH_2010_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpMarch2010subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_MAY_2006_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump M"),
        .itemId = ITEM_PACK_SHONEN_JUMP_MAY_2006_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpMay2006subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_MAY_2008_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump M"),
        .itemId = ITEM_PACK_SHONEN_JUMP_MAY_2008_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpMay2008subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_MAY_2010_SUBSCRIPTION_BONUS] =
    {
        .name = _("Shonen Jump M"),
        .itemId = ITEM_PACK_SHONEN_JUMP_MAY_2010_SUBSCRIPTION_BONUS,
        .price = 0,
        .description = sShonenJumpMay2010subscriptionbonusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_SCHOLASTIC_EDITION_VOL_9_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump S"),
        .itemId = ITEM_PACK_SHONEN_JUMP_SCHOLASTIC_EDITION_VOL_9_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpScholasticEditionVol9Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_1_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_1_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol1Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol10Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_3_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol10Issue3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_4_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_10_ISSUE_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol10Issue4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_2_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_2_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol2Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_3_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_3_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol3Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol4Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_11_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_11_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol4Issue11promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_12_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_4_ISSUE_12_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol4Issue12promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol5Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_11_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_11_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol5Issue11promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_4_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol5Issue4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_6_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol5Issue6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_9_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_5_ISSUE_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol5Issue9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol6Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_12_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_12_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol6Issue12promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_3_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol6Issue3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_5_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol6Issue5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_9_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_6_ISSUE_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol6Issue9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol7Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_11_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_11_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol7Issue11promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_3_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol7Issue3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_6_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol7Issue6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_9_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_7_ISSUE_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol7Issue9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_11_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_11_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue11promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_3_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_5_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_7_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_7_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue7promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_9_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_8_ISSUE_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol8Issue9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_1_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_10_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_10_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue10promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_3_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_4_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_6_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_8_PROMOTIONAL_CARD] =
    {
        .name = _("Shonen Jump V"),
        .itemId = ITEM_PACK_SHONEN_JUMP_VOL_9_ISSUE_8_PROMOTIONAL_CARD,
        .price = 0,
        .description = sShonenJumpVol9Issue8promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SOUL_FUSION] =
    {
        .name = _("Soul Fusion"),
        .itemId = ITEM_PACK_SOUL_FUSION,
        .price = 0,
        .description = sSoulFusionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SOUL_FUSION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Soul Fusion S"),
        .itemId = ITEM_PACK_SOUL_FUSION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sSoulFusionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SOUL_FUSION_SPECIAL_EDITION] =
    {
        .name = _("Soul Fusion S"),
        .itemId = ITEM_PACK_SOUL_FUSION_SPECIAL_EDITION,
        .price = 0,
        .description = sSoulFusionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SOUL_OF_THE_DUELIST] =
    {
        .name = _("Soul of the D"),
        .itemId = ITEM_PACK_SOUL_OF_THE_DUELIST,
        .price = 0,
        .description = sSouloftheDuelistDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPACE_TIME_SHOWDOWN_POWER_UP_PACK] =
    {
        .name = _("Space-Time Sh"),
        .itemId = ITEM_PACK_SPACE_TIME_SHOWDOWN_POWER_UP_PACK,
        .price = 0,
        .description = sSpaceTimeShowdownPowerUpPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_DEMO_DECK] =
    {
        .name = _("Speed Duel De"),
        .itemId = ITEM_PACK_SPEED_DUEL_DEMO_DECK,
        .price = 0,
        .description = sSpeedDuelDemoDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_DEMO_DECK_2020] =
    {
        .name = _("Speed Duel De"),
        .itemId = ITEM_PACK_SPEED_DUEL_DEMO_DECK_2020,
        .price = 0,
        .description = sSpeedDuelDemoDeck2020Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_GX_DUEL_ACADEMY_BOX] =
    {
        .name = _("Speed Duel GX"),
        .itemId = ITEM_PACK_SPEED_DUEL_GX_DUEL_ACADEMY_BOX,
        .price = 0,
        .description = sSpeedDuelGXDuelAcademyBoxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_GX_DUELISTS_OF_SHADOWS] =
    {
        .name = _("Speed Duel GX"),
        .itemId = ITEM_PACK_SPEED_DUEL_GX_DUELISTS_OF_SHADOWS,
        .price = 0,
        .description = sSpeedDuelGXDuelistsofShadowsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_GX_MIDTERM_PARADOX] =
    {
        .name = _("Speed Duel GX"),
        .itemId = ITEM_PACK_SPEED_DUEL_GX_MIDTERM_PARADOX,
        .price = 0,
        .description = sSpeedDuelGXMidtermParadoxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STARTER_DECKS_DESTINY_MASTERS] =
    {
        .name = _("Speed Duel St"),
        .itemId = ITEM_PACK_SPEED_DUEL_STARTER_DECKS_DESTINY_MASTERS,
        .price = 0,
        .description = sSpeedDuelStarterDecksDestinyMastersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STARTER_DECKS_DUELISTS_OF_TOMORROW] =
    {
        .name = _("Speed Duel St"),
        .itemId = ITEM_PACK_SPEED_DUEL_STARTER_DECKS_DUELISTS_OF_TOMORROW,
        .price = 0,
        .description = sSpeedDuelStarterDecksDuelistsofTomorrowDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STARTER_DECKS_MATCH_OF_THE_MILLENNIUM] =
    {
        .name = _("Speed Duel St"),
        .itemId = ITEM_PACK_SPEED_DUEL_STARTER_DECKS_MATCH_OF_THE_MILLENNIUM,
        .price = 0,
        .description = sSpeedDuelStarterDecksMatchoftheMillenniumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STARTER_DECKS_TWISTED_NIGHTMARES] =
    {
        .name = _("Speed Duel St"),
        .itemId = ITEM_PACK_SPEED_DUEL_STARTER_DECKS_TWISTED_NIGHTMARES,
        .price = 0,
        .description = sSpeedDuelStarterDecksTwistedNightmaresDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STARTER_DECKS_ULTIMATE_PREDATORS] =
    {
        .name = _("Speed Duel St"),
        .itemId = ITEM_PACK_SPEED_DUEL_STARTER_DECKS_ULTIMATE_PREDATORS,
        .price = 0,
        .description = sSpeedDuelStarterDecksUltimatePredatorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_1] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_1,
        .price = 0,
        .description = sSpeedDuelTournamentPack1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_2] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_2,
        .price = 0,
        .description = sSpeedDuelTournamentPack2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_3] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_3,
        .price = 0,
        .description = sSpeedDuelTournamentPack3Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_4] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_4,
        .price = 0,
        .description = sSpeedDuelTournamentPack4Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_5] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_5,
        .price = 0,
        .description = sSpeedDuelTournamentPack5Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_6] =
    {
        .name = _("Speed Duel To"),
        .itemId = ITEM_PACK_SPEED_DUEL_TOURNAMENT_PACK_6,
        .price = 0,
        .description = sSpeedDuelTournamentPack6Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_ARENA_OF_LOST_SOULS] =
    {
        .name = _("Speed Duel: A"),
        .itemId = ITEM_PACK_SPEED_DUEL_ARENA_OF_LOST_SOULS,
        .price = 0,
        .description = sSpeedDuelArenaofLostSoulsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_ATTACK_FROM_THE_DEEP] =
    {
        .name = _("Speed Duel: A"),
        .itemId = ITEM_PACK_SPEED_DUEL_ATTACK_FROM_THE_DEEP,
        .price = 0,
        .description = sSpeedDuelAttackfromtheDeepDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_BATTLE_CITY_BOX] =
    {
        .name = _("Speed Duel: B"),
        .itemId = ITEM_PACK_SPEED_DUEL_BATTLE_CITY_BOX,
        .price = 0,
        .description = sSpeedDuelBattleCityBoxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_SCARS_OF_BATTLE] =
    {
        .name = _("Speed Duel: S"),
        .itemId = ITEM_PACK_SPEED_DUEL_SCARS_OF_BATTLE,
        .price = 0,
        .description = sSpeedDuelScarsofBattleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_SCARS_OF_BATTLE_LAUNCH_EVENT_PARTICIPATION_CARD] =
    {
        .name = _("Speed Duel: S"),
        .itemId = ITEM_PACK_SPEED_DUEL_SCARS_OF_BATTLE_LAUNCH_EVENT_PARTICIPATION_CARD,
        .price = 0,
        .description = sSpeedDuelScarsofBattleLaunchEventparticipationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_STREETS_OF_BATTLE_CITY] =
    {
        .name = _("Speed Duel: S"),
        .itemId = ITEM_PACK_SPEED_DUEL_STREETS_OF_BATTLE_CITY,
        .price = 0,
        .description = sSpeedDuelStreetsofBattleCityDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TRIALS_OF_THE_KINGDOM] =
    {
        .name = _("Speed Duel: T"),
        .itemId = ITEM_PACK_SPEED_DUEL_TRIALS_OF_THE_KINGDOM,
        .price = 0,
        .description = sSpeedDuelTrialsoftheKingdomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPEED_DUEL_TRIALS_OF_THE_KINGDOM_SNEAK_PEEK_PARTICIPATION_CARDS] =
    {
        .name = _("Speed Duel: T"),
        .itemId = ITEM_PACK_SPEED_DUEL_TRIALS_OF_THE_KINGDOM_SNEAK_PEEK_PARTICIPATION_CARDS,
        .price = 0,
        .description = sSpeedDuelTrialsoftheKingdomSneakPeekparticipationcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPELL_RULER] =
    {
        .name = _("Spell Ruler"),
        .itemId = ITEM_PACK_SPELL_RULER,
        .price = 0,
        .description = sSpellRulerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPELLCASTER_S_COMMAND_STRUCTURE_DECK] =
    {
        .name = _("Spellcaster's"),
        .itemId = ITEM_PACK_SPELLCASTER_S_COMMAND_STRUCTURE_DECK,
        .price = 0,
        .description = sSpellcastersCommandStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPELLCASTER_S_COMMAND_STRUCTURE_DECK_SPECIAL_EDITION] =
    {
        .name = _("Spellcaster's"),
        .itemId = ITEM_PACK_SPELLCASTER_S_COMMAND_STRUCTURE_DECK_SPECIAL_EDITION,
        .price = 0,
        .description = sSpellcastersCommandStructureDeckSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SPIRIT_WARRIORS] =
    {
        .name = _("Spirit Warrio"),
        .itemId = ITEM_PACK_SPIRIT_WARRIORS,
        .price = 0,
        .description = sSpiritWarriorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STAR_PACK_2013] =
    {
        .name = _("Star Pack 201"),
        .itemId = ITEM_PACK_STAR_PACK_2013,
        .price = 0,
        .description = sStarPack2013Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STAR_PACK_2014] =
    {
        .name = _("Star Pack 201"),
        .itemId = ITEM_PACK_STAR_PACK_2014,
        .price = 0,
        .description = sStarPack2014Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STAR_PACK_ARC_V] =
    {
        .name = _("Star Pack ARC"),
        .itemId = ITEM_PACK_STAR_PACK_ARC_V,
        .price = 0,
        .description = sStarPackARCVDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STAR_PACK_BATTLE_ROYAL] =
    {
        .name = _("Star Pack Bat"),
        .itemId = ITEM_PACK_STAR_PACK_BATTLE_ROYAL,
        .price = 0,
        .description = sStarPackBattleRoyalDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STAR_PACK_VRAINS] =
    {
        .name = _("Star Pack VRA"),
        .itemId = ITEM_PACK_STAR_PACK_VRAINS,
        .price = 0,
        .description = sStarPackVRAINSDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARDUST_OVERDRIVE] =
    {
        .name = _("Stardust Over"),
        .itemId = ITEM_PACK_STARDUST_OVERDRIVE,
        .price = 0,
        .description = sStardustOverdriveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARDUST_OVERDRIVE_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Stardust Over"),
        .itemId = ITEM_PACK_STARDUST_OVERDRIVE_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sStardustOverdriveSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARDUST_OVERDRIVE_SPECIAL_EDITION] =
    {
        .name = _("Stardust Over"),
        .itemId = ITEM_PACK_STARDUST_OVERDRIVE_SPECIAL_EDITION,
        .price = 0,
        .description = sStardustOverdriveSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARSTRIKE_BLAST] =
    {
        .name = _("Starstrike Bl"),
        .itemId = ITEM_PACK_STARSTRIKE_BLAST,
        .price = 0,
        .description = sStarstrikeBlastDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARSTRIKE_BLAST_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Starstrike Bl"),
        .itemId = ITEM_PACK_STARSTRIKE_BLAST_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sStarstrikeBlastSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_2006] =
    {
        .name = _("Starter Deck "),
        .itemId = ITEM_PACK_STARTER_DECK_2006,
        .price = 0,
        .description = sStarterDeck2006Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_2006_SPECIAL_EDITION] =
    {
        .name = _("Starter Deck "),
        .itemId = ITEM_PACK_STARTER_DECK_2006_SPECIAL_EDITION,
        .price = 0,
        .description = sStarterDeck2006SpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_CODEBREAKER] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_CODEBREAKER,
        .price = 0,
        .description = sStarterDeckCodebreakerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_DAWN_OF_THE_XYZ] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_DAWN_OF_THE_XYZ,
        .price = 0,
        .description = sStarterDeckDawnoftheXyzDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_DUELIST_TOOLBOX] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_DUELIST_TOOLBOX,
        .price = 0,
        .description = sStarterDeckDuelistToolboxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_JADEN_YUKI] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_JADEN_YUKI,
        .price = 0,
        .description = sStarterDeckJadenYukiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_JOEY] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_JOEY,
        .price = 0,
        .description = sStarterDeckJoeyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_KAIBA] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_KAIBA,
        .price = 0,
        .description = sStarterDeckKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_KAIBA_EVOLUTION] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_KAIBA_EVOLUTION,
        .price = 0,
        .description = sStarterDeckKaibaEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_KAIBA_RELOADED] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_KAIBA_RELOADED,
        .price = 0,
        .description = sStarterDeckKaibaReloadedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_LINK_STRIKE] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_LINK_STRIKE,
        .price = 0,
        .description = sStarterDeckLinkStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_PEGASUS] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_PEGASUS,
        .price = 0,
        .description = sStarterDeckPegasusDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_SYRUS_TRUESDALE] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_SYRUS_TRUESDALE,
        .price = 0,
        .description = sStarterDeckSyrusTruesdaleDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_XYZ_SYMPHONY] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_XYZ_SYMPHONY,
        .price = 0,
        .description = sStarterDeckXyzSymphonyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YU_GI_OH_5D_S] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YU_GI_OH_5D_S,
        .price = 0,
        .description = sStarterDeckYuGiOh5DsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YU_GI_OH_5D_S_2009] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YU_GI_OH_5D_S_2009,
        .price = 0,
        .description = sStarterDeckYuGiOh5Ds2009Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YUGI] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YUGI,
        .price = 0,
        .description = sStarterDeckYugiDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YUGI_EVOLUTION] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YUGI_EVOLUTION,
        .price = 0,
        .description = sStarterDeckYugiEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YUGI_RELOADED] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YUGI_RELOADED,
        .price = 0,
        .description = sStarterDeckYugiReloadedDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STARTER_DECK_YUYA] =
    {
        .name = _("Starter Deck:"),
        .itemId = ITEM_PACK_STARTER_DECK_YUYA,
        .price = 0,
        .description = sStarterDeckYuyaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STORM_OF_RAGNAROK] =
    {
        .name = _("Storm of Ragn"),
        .itemId = ITEM_PACK_STORM_OF_RAGNAROK,
        .price = 0,
        .description = sStormofRagnarokDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STORM_OF_RAGNAROK_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Storm of Ragn"),
        .itemId = ITEM_PACK_STORM_OF_RAGNAROK_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sStormofRagnarokSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STORM_OF_RAGNAROK_SPECIAL_EDITION] =
    {
        .name = _("Storm of Ragn"),
        .itemId = ITEM_PACK_STORM_OF_RAGNAROK_SPECIAL_EDITION,
        .price = 0,
        .description = sStormofRagnarokSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRIKE_OF_NEOS] =
    {
        .name = _("Strike of Neo"),
        .itemId = ITEM_PACK_STRIKE_OF_NEOS,
        .price = 0,
        .description = sStrikeofNeosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRIKE_OF_NEOS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Strike of Neo"),
        .itemId = ITEM_PACK_STRIKE_OF_NEOS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sStrikeofNeosSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRIKE_OF_NEOS_SPECIAL_EDITION] =
    {
        .name = _("Strike of Neo"),
        .itemId = ITEM_PACK_STRIKE_OF_NEOS_SPECIAL_EDITION,
        .price = 0,
        .description = sStrikeofNeosSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_ALBAZ_STRIKE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_ALBAZ_STRIKE,
        .price = 0,
        .description = sStructureDeckAlbazStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_BEWARE_OF_TRAPTRIX] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_BEWARE_OF_TRAPTRIX,
        .price = 0,
        .description = sStructureDeckBewareofTraptrixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_BLAZE_OF_DESTRUCTION] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_BLAZE_OF_DESTRUCTION,
        .price = 0,
        .description = sStructureDeckBlazeofDestructionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_BLUE_EYES_WHITE_DESTINY] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_BLUE_EYES_WHITE_DESTINY,
        .price = 0,
        .description = sStructureDeckBlueEyesWhiteDestinyDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_CYBER_STRIKE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_CYBER_STRIKE,
        .price = 0,
        .description = sStructureDeckCyberStrikeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_CYBERSE_LINK] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_CYBERSE_LINK,
        .price = 0,
        .description = sStructureDeckCyberseLinkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_DARK_WORLD] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_DARK_WORLD,
        .price = 0,
        .description = sStructureDeckDarkWorldDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_DELUXE_EDITION] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_DELUXE_EDITION,
        .price = 0,
        .description = sStructureDeckDeluxeEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_DINOSAUR_S_RAGE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_DINOSAUR_S_RAGE,
        .price = 0,
        .description = sStructureDeckDinosaursRageDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_DINOSAUR_S_RAGE_SPECIAL_SET] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_DINOSAUR_S_RAGE_SPECIAL_SET,
        .price = 0,
        .description = sStructureDeckDinosaursRageSpecialSetDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_DRAGON_S_ROAR] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_DRAGON_S_ROAR,
        .price = 0,
        .description = sStructureDeckDragonsRoarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_FIRE_KINGS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_FIRE_KINGS,
        .price = 0,
        .description = sStructureDeckFireKingsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_FREEZING_CHAINS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_FREEZING_CHAINS,
        .price = 0,
        .description = sStructureDeckFreezingChainsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_FURY_FROM_THE_DEEP] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_FURY_FROM_THE_DEEP,
        .price = 0,
        .description = sStructureDeckFuryfromtheDeepDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_INVINCIBLE_FORTRESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_INVINCIBLE_FORTRESS,
        .price = 0,
        .description = sStructureDeckInvincibleFortressDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_LAIR_OF_DARKNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_LAIR_OF_DARKNESS,
        .price = 0,
        .description = sStructureDeckLairofDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_LEGEND_OF_THE_CRYSTAL_BEASTS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_LEGEND_OF_THE_CRYSTAL_BEASTS,
        .price = 0,
        .description = sStructureDeckLegendoftheCrystalBeastsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_LORD_OF_THE_STORM] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_LORD_OF_THE_STORM,
        .price = 0,
        .description = sStructureDeckLordoftheStormDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_MACHINE_RE_VOLT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_MACHINE_RE_VOLT,
        .price = 0,
        .description = sStructureDeckMachineReVoltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_MARIK_TCG_] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_MARIK_TCG_,
        .price = 0,
        .description = sStructureDeckMarikTCGDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_MECHANIZED_MADNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_MECHANIZED_MADNESS,
        .price = 0,
        .description = sStructureDeckMechanizedMadnessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_ORDER_OF_THE_SPELLCASTERS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_ORDER_OF_THE_SPELLCASTERS,
        .price = 0,
        .description = sStructureDeckOrderoftheSpellcastersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_POWERCODE_LINK] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_POWERCODE_LINK,
        .price = 0,
        .description = sStructureDeckPowercodeLinkDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_ROKKET_REVOLT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_ROKKET_REVOLT,
        .price = 0,
        .description = sStructureDeckRokketRevoltDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SACRED_BEASTS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SACRED_BEASTS,
        .price = 0,
        .description = sStructureDeckSacredBeastsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SETO_KAIBA] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SETO_KAIBA,
        .price = 0,
        .description = sStructureDeckSetoKaibaDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SHADDOLL_SHOWDOWN] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SHADDOLL_SHOWDOWN,
        .price = 0,
        .description = sStructureDeckShaddollShowdownDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SOULBURNER] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SOULBURNER,
        .price = 0,
        .description = sStructureDeckSoulburnerDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SPELLCASTER_S_JUDGMENT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SPELLCASTER_S_JUDGMENT,
        .price = 0,
        .description = sStructureDeckSpellcastersJudgmentDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_SPIRIT_CHARMERS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_SPIRIT_CHARMERS,
        .price = 0,
        .description = sStructureDeckSpiritCharmersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_THE_CRIMSON_KING] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_THE_CRIMSON_KING,
        .price = 0,
        .description = sStructureDeckTheCrimsonKingDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_WARRIOR_S_TRIUMPH] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_WARRIOR_S_TRIUMPH,
        .price = 0,
        .description = sStructureDeckWarriorsTriumphDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_WAVE_OF_LIGHT] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_WAVE_OF_LIGHT,
        .price = 0,
        .description = sStructureDeckWaveofLightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_YUGI_MUTO] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_YUGI_MUTO,
        .price = 0,
        .description = sStructureDeckYugiMutoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_ZOMBIE_HORDE] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_ZOMBIE_HORDE,
        .price = 0,
        .description = sStructureDeckZombieHordeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_STRUCTURE_DECK_ZOMBIE_MADNESS] =
    {
        .name = _("Structure Dec"),
        .itemId = ITEM_PACK_STRUCTURE_DECK_ZOMBIE_MADNESS,
        .price = 0,
        .description = sStructureDeckZombieMadnessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SUMMONED_SKULL_SAMPLE_PROMOTIONAL_CARD] =
    {
        .name = _("Summoned Skul"),
        .itemId = ITEM_PACK_SUMMONED_SKULL_SAMPLE_PROMOTIONAL_CARD,
        .price = 0,
        .description = sSummonedSkullSamplepromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SUPER_STARTER_POWER_UP_PACK] =
    {
        .name = _("Super Starter"),
        .itemId = ITEM_PACK_SUPER_STARTER_POWER_UP_PACK,
        .price = 0,
        .description = sSuperStarterPowerUpPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SUPER_STARTER_SPACE_TIME_SHOWDOWN] =
    {
        .name = _("Super Starter"),
        .itemId = ITEM_PACK_SUPER_STARTER_SPACE_TIME_SHOWDOWN,
        .price = 0,
        .description = sSuperStarterSpaceTimeShowdownDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SUPER_STARTER_V_FOR_VICTORY] =
    {
        .name = _("Super Starter"),
        .itemId = ITEM_PACK_SUPER_STARTER_V_FOR_VICTORY,
        .price = 0,
        .description = sSuperStarterVforVictoryDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SUPREME_DARKNESS] =
    {
        .name = _("Supreme Darkn"),
        .itemId = ITEM_PACK_SUPREME_DARKNESS,
        .price = 0,
        .description = sSupremeDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SWEDISH_SHONEN_JUMP_2004_ISSUE_2_PROMOTIONAL_CARD] =
    {
        .name = _("Swedish Shone"),
        .itemId = ITEM_PACK_SWEDISH_SHONEN_JUMP_2004_ISSUE_2_PROMOTIONAL_CARD,
        .price = 0,
        .description = sSwedishShonenJump2004Issue2promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SWEDISH_SHONEN_JUMP_2005_ISSUE_12_PROMOTIONAL_CARD] =
    {
        .name = _("Swedish Shone"),
        .itemId = ITEM_PACK_SWEDISH_SHONEN_JUMP_2005_ISSUE_12_PROMOTIONAL_CARD,
        .price = 0,
        .description = sSwedishShonenJump2005Issue12promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_SYNCHRON_EXTREME_STRUCTURE_DECK] =
    {
        .name = _("Synchron Extr"),
        .itemId = ITEM_PACK_SYNCHRON_EXTREME_STRUCTURE_DECK,
        .price = 0,
        .description = sSynchronExtremeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TACTICAL_EVOLUTION] =
    {
        .name = _("Tactical Evol"),
        .itemId = ITEM_PACK_TACTICAL_EVOLUTION,
        .price = 0,
        .description = sTacticalEvolutionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TACTICAL_EVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("Tactical Evol"),
        .itemId = ITEM_PACK_TACTICAL_EVOLUTION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTacticalEvolutionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TACTICAL_EVOLUTION_SPECIAL_EDITION] =
    {
        .name = _("Tactical Evol"),
        .itemId = ITEM_PACK_TACTICAL_EVOLUTION_SPECIAL_EDITION,
        .price = 0,
        .description = sTacticalEvolutionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TACTICAL_MASTERS] =
    {
        .name = _("Tactical Mast"),
        .itemId = ITEM_PACK_TACTICAL_MASTERS,
        .price = 0,
        .description = sTacticalMastersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DARK_EMPEROR_STRUCTURE_DECK] =
    {
        .name = _("The Dark Empe"),
        .itemId = ITEM_PACK_THE_DARK_EMPEROR_STRUCTURE_DECK,
        .price = 0,
        .description = sTheDarkEmperorStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DARK_ILLUSION] =
    {
        .name = _("The Dark Illu"),
        .itemId = ITEM_PACK_THE_DARK_ILLUSION,
        .price = 0,
        .description = sTheDarkIllusionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DARK_ILLUSION_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("The Dark Illu"),
        .itemId = ITEM_PACK_THE_DARK_ILLUSION_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTheDarkIllusionSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DARK_ILLUSION_SPECIAL_EDITION] =
    {
        .name = _("The Dark Illu"),
        .itemId = ITEM_PACK_THE_DARK_ILLUSION_SPECIAL_EDITION,
        .price = 0,
        .description = sTheDarkIllusionSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DUELIST_GENESIS] =
    {
        .name = _("The Duelist G"),
        .itemId = ITEM_PACK_THE_DUELIST_GENESIS,
        .price = 0,
        .description = sTheDuelistGenesisDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DUELIST_GENESIS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("The Duelist G"),
        .itemId = ITEM_PACK_THE_DUELIST_GENESIS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTheDuelistGenesisSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_DUELIST_GENESIS_SPECIAL_EDITION] =
    {
        .name = _("The Duelist G"),
        .itemId = ITEM_PACK_THE_DUELIST_GENESIS_SPECIAL_EDITION,
        .price = 0,
        .description = sTheDuelistGenesisSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_GRAND_CREATORS] =
    {
        .name = _("The Grand Cre"),
        .itemId = ITEM_PACK_THE_GRAND_CREATORS,
        .price = 0,
        .description = sTheGrandCreatorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_INFINITE_FORBIDDEN] =
    {
        .name = _("The Infinite "),
        .itemId = ITEM_PACK_THE_INFINITE_FORBIDDEN,
        .price = 0,
        .description = sTheInfiniteForbiddenDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_INFINITY_CHASERS] =
    {
        .name = _("The Infinity "),
        .itemId = ITEM_PACK_THE_INFINITY_CHASERS,
        .price = 0,
        .description = sTheInfinityChasersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_SERIES_] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_SERIES_,
        .price = 0,
        .description = sTheLostArtPromotionseriesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_D] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_D,
        .price = 0,
        .description = sTheLostArtPromotion2020DDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_E] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_E,
        .price = 0,
        .description = sTheLostArtPromotion2020EDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_F] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_F,
        .price = 0,
        .description = sTheLostArtPromotion2020FDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_G] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_G,
        .price = 0,
        .description = sTheLostArtPromotion2020GDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_H] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_H,
        .price = 0,
        .description = sTheLostArtPromotion2020HDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_I] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_I,
        .price = 0,
        .description = sTheLostArtPromotion2020IDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_J] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_J,
        .price = 0,
        .description = sTheLostArtPromotion2020JDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_K] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_K,
        .price = 0,
        .description = sTheLostArtPromotion2020KDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_L] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_L,
        .price = 0,
        .description = sTheLostArtPromotion2020LDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_M] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_M,
        .price = 0,
        .description = sTheLostArtPromotion2020MDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_N] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_N,
        .price = 0,
        .description = sTheLostArtPromotion2020NDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_O] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_O,
        .price = 0,
        .description = sTheLostArtPromotion2020ODesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_P] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_P,
        .price = 0,
        .description = sTheLostArtPromotion2020PDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_Q] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_Q,
        .price = 0,
        .description = sTheLostArtPromotion2020QDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2020_R] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2020_R,
        .price = 0,
        .description = sTheLostArtPromotion2020RDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_A] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_A,
        .price = 0,
        .description = sTheLostArtPromotion2021ADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_B] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_B,
        .price = 0,
        .description = sTheLostArtPromotion2021BDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_C] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_C,
        .price = 0,
        .description = sTheLostArtPromotion2021CDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_D] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_D,
        .price = 0,
        .description = sTheLostArtPromotion2021DDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_E] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_E,
        .price = 0,
        .description = sTheLostArtPromotion2021EDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_F] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_F,
        .price = 0,
        .description = sTheLostArtPromotion2021FDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_G] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_G,
        .price = 0,
        .description = sTheLostArtPromotion2021GDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_H] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_H,
        .price = 0,
        .description = sTheLostArtPromotion2021HDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_I] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_I,
        .price = 0,
        .description = sTheLostArtPromotion2021IDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_J] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_J,
        .price = 0,
        .description = sTheLostArtPromotion2021JDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_K] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_K,
        .price = 0,
        .description = sTheLostArtPromotion2021KDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2021_L] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2021_L,
        .price = 0,
        .description = sTheLostArtPromotion2021LDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2022] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2022,
        .price = 0,
        .description = sTheLostArtPromotion2022Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2022_G] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2022_G,
        .price = 0,
        .description = sTheLostArtPromotion2022GDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2022_K] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2022_K,
        .price = 0,
        .description = sTheLostArtPromotion2022KDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023,
        .price = 0,
        .description = sTheLostArtPromotion2023Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023_E] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023_E,
        .price = 0,
        .description = sTheLostArtPromotion2023EDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023_F] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023_F,
        .price = 0,
        .description = sTheLostArtPromotion2023FDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023_G] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023_G,
        .price = 0,
        .description = sTheLostArtPromotion2023GDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023_H] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023_H,
        .price = 0,
        .description = sTheLostArtPromotion2023HDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2023_I] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2023_I,
        .price = 0,
        .description = sTheLostArtPromotion2023IDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2024] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2024,
        .price = 0,
        .description = sTheLostArtPromotion2024Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2024_A] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2024_A,
        .price = 0,
        .description = sTheLostArtPromotion2024ADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2024_B] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2024_B,
        .price = 0,
        .description = sTheLostArtPromotion2024BDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2024_C] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2024_C,
        .price = 0,
        .description = sTheLostArtPromotion2024CDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_2024_H] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_2024_H,
        .price = 0,
        .description = sTheLostArtPromotion2024HDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_A] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_A,
        .price = 0,
        .description = sTheLostArtPromotionADesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_B] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_B,
        .price = 0,
        .description = sTheLostArtPromotionBDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_C] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_C,
        .price = 0,
        .description = sTheLostArtPromotionCDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_D] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_D,
        .price = 0,
        .description = sTheLostArtPromotionDDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_E] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_E,
        .price = 0,
        .description = sTheLostArtPromotionEDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_F] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_F,
        .price = 0,
        .description = sTheLostArtPromotionFDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_G] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_G,
        .price = 0,
        .description = sTheLostArtPromotionGDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_H] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_H,
        .price = 0,
        .description = sTheLostArtPromotionHDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_I] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_I,
        .price = 0,
        .description = sTheLostArtPromotionIDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_J] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_J,
        .price = 0,
        .description = sTheLostArtPromotionJDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_K] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_K,
        .price = 0,
        .description = sTheLostArtPromotionKDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_L] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_L,
        .price = 0,
        .description = sTheLostArtPromotionLDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_M] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_M,
        .price = 0,
        .description = sTheLostArtPromotionMDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_N] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_N,
        .price = 0,
        .description = sTheLostArtPromotionNDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_ART_PROMOTION_O] =
    {
        .name = _("The Lost Art "),
        .itemId = ITEM_PACK_THE_LOST_ART_PROMOTION_O,
        .price = 0,
        .description = sTheLostArtPromotionODesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_MILLENNIUM] =
    {
        .name = _("The Lost Mill"),
        .itemId = ITEM_PACK_THE_LOST_MILLENNIUM,
        .price = 0,
        .description = sTheLostMillenniumDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_MILLENNIUM_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("The Lost Mill"),
        .itemId = ITEM_PACK_THE_LOST_MILLENNIUM_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTheLostMillenniumSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_LOST_MILLENNIUM_SPECIAL_EDITION] =
    {
        .name = _("The Lost Mill"),
        .itemId = ITEM_PACK_THE_LOST_MILLENNIUM_SPECIAL_EDITION,
        .price = 0,
        .description = sTheLostMillenniumSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_NEW_CHALLENGERS] =
    {
        .name = _("The New Chall"),
        .itemId = ITEM_PACK_THE_NEW_CHALLENGERS,
        .price = 0,
        .description = sTheNewChallengersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_NEW_CHALLENGERS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("The New Chall"),
        .itemId = ITEM_PACK_THE_NEW_CHALLENGERS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTheNewChallengersSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_NEW_CHALLENGERS_SUPER_EDITION] =
    {
        .name = _("The New Chall"),
        .itemId = ITEM_PACK_THE_NEW_CHALLENGERS_SUPER_EDITION,
        .price = 0,
        .description = sTheNewChallengersSuperEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_POT_COLLECTION] =
    {
        .name = _("The Pot Colle"),
        .itemId = ITEM_PACK_THE_POT_COLLECTION,
        .price = 0,
        .description = sThePotCollectionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_SECRET_FORCES] =
    {
        .name = _("The Secret Fo"),
        .itemId = ITEM_PACK_THE_SECRET_FORCES,
        .price = 0,
        .description = sTheSecretForcesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_SHINING_DARKNESS] =
    {
        .name = _("The Shining D"),
        .itemId = ITEM_PACK_THE_SHINING_DARKNESS,
        .price = 0,
        .description = sTheShiningDarknessDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_THE_SHINING_DARKNESS_SNEAK_PEEK_PARTICIPATION_CARD] =
    {
        .name = _("The Shining D"),
        .itemId = ITEM_PACK_THE_SHINING_DARKNESS_SNEAK_PEEK_PARTICIPATION_CARD,
        .price = 0,
        .description = sTheShiningDarknessSneakPeekParticipationCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOON_CHAOS] =
    {
        .name = _("Toon Chaos"),
        .itemId = ITEM_PACK_TOON_CHAOS,
        .price = 0,
        .description = sToonChaosDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_4] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_4,
        .price = 0,
        .description = sTournamentPack4Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_5] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_5,
        .price = 0,
        .description = sTournamentPack5Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_6] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_6,
        .price = 0,
        .description = sTournamentPack6Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_7] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_7,
        .price = 0,
        .description = sTournamentPack7Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_8] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_8,
        .price = 0,
        .description = sTournamentPack8Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_1ST_SEASON] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_1ST_SEASON,
        .price = 0,
        .description = sTournamentPack1stSeasonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_2ND_SEASON] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_2ND_SEASON,
        .price = 0,
        .description = sTournamentPack2ndSeasonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TOURNAMENT_PACK_3RD_SEASON] =
    {
        .name = _("Tournament Pa"),
        .itemId = ITEM_PACK_TOURNAMENT_PACK_3RD_SEASON,
        .price = 0,
        .description = sTournamentPack3rdSeasonDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TRIALS_OF_THE_PHARAOH_MATCH_OF_THE_MILLENNIUM_TWISTED_NIGHTMARES_PROMOTIONAL_CARD] =
    {
        .name = _("Trials of the"),
        .itemId = ITEM_PACK_TRIALS_OF_THE_PHARAOH_MATCH_OF_THE_MILLENNIUM_TWISTED_NIGHTMARES_PROMOTIONAL_CARD,
        .price = 0,
        .description = sTrialsofthePharaohMatchoftheMillenniumTwistedNightmarespromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TRIALS_OF_THE_PHARAOH_SPEED_DUEL_BATTLE_CITY_BOX_PROMOTIONAL_CARD] =
    {
        .name = _("Trials of the"),
        .itemId = ITEM_PACK_TRIALS_OF_THE_PHARAOH_SPEED_DUEL_BATTLE_CITY_BOX_PROMOTIONAL_CARD,
        .price = 0,
        .description = sTrialsofthePharaohSpeedDuelBattleCityBoxpromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TRIALS_OF_THE_PHARAOH_TRIALS_OF_THE_KINGDOM_PROMOTIONAL_CARD] =
    {
        .name = _("Trials of the"),
        .itemId = ITEM_PACK_TRIALS_OF_THE_PHARAOH_TRIALS_OF_THE_KINGDOM_PROMOTIONAL_CARD,
        .price = 0,
        .description = sTrialsofthePharaohTrialsoftheKingdompromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_EIGHT] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_EIGHT,
        .price = 0,
        .description = sTurboPackBoosterEightDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_FIVE] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_FIVE,
        .price = 0,
        .description = sTurboPackBoosterFiveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_FOUR] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_FOUR,
        .price = 0,
        .description = sTurboPackBoosterFourDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_ONE] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_ONE,
        .price = 0,
        .description = sTurboPackBoosterOneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_SEVEN] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_SEVEN,
        .price = 0,
        .description = sTurboPackBoosterSevenDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_SIX] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_SIX,
        .price = 0,
        .description = sTurboPackBoosterSixDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_THREE] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_THREE,
        .price = 0,
        .description = sTurboPackBoosterThreeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TURBO_PACK_BOOSTER_TWO] =
    {
        .name = _("Turbo Pack: B"),
        .itemId = ITEM_PACK_TURBO_PACK_BOOSTER_TWO,
        .price = 0,
        .description = sTurboPackBoosterTwoDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_TWILIGHT_EDITION] =
    {
        .name = _("Twilight Edit"),
        .itemId = ITEM_PACK_TWILIGHT_EDITION,
        .price = 0,
        .description = sTwilightEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ULTIMATE_EDITION] =
    {
        .name = _("Ultimate Edit"),
        .itemId = ITEM_PACK_ULTIMATE_EDITION,
        .price = 0,
        .description = sUltimateEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ULTIMATE_EDITION_2] =
    {
        .name = _("Ultimate Edit"),
        .itemId = ITEM_PACK_ULTIMATE_EDITION_2,
        .price = 0,
        .description = sUltimateEdition2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_VALIANT_SMASHERS] =
    {
        .name = _("Valiant Smash"),
        .itemId = ITEM_PACK_VALIANT_SMASHERS,
        .price = 0,
        .description = sValiantSmashersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WCS_2025_LIMITED_PACK] =
    {
        .name = _("WCS 2025 Limi"),
        .itemId = ITEM_PACK_WCS_2025_LIMITED_PACK,
        .price = 0,
        .description = sWCS2025LimitedPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_FALL_2016_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_FALL_2016_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackFall2016promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_FALL_2017_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_FALL_2017_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackFall2017promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_FALL_2018_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_FALL_2018_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackFall2018promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_SPRING_2016_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_SPRING_2016_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackSpring2016promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_SPRING_2017_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_SPRING_2017_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackSpring2017promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_SPRING_2018_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_SPRING_2018_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackSpring2018promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WSJ_JUMP_PACK_SPRING_2019_PROMOTIONAL_CARD] =
    {
        .name = _("WSJ Jump Pack"),
        .itemId = ITEM_PACK_WSJ_JUMP_PACK_SPRING_2019_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWSJJumpPackSpring2019promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WAR_OF_THE_GIANTS_REINFORCEMENTS] =
    {
        .name = _("War of the Gi"),
        .itemId = ITEM_PACK_WAR_OF_THE_GIANTS_REINFORCEMENTS,
        .price = 0,
        .description = sWaroftheGiantsReinforcementsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WAR_OF_THE_GIANTS_ROUND_2] =
    {
        .name = _("War of the Gi"),
        .itemId = ITEM_PACK_WAR_OF_THE_GIANTS_ROUND_2,
        .price = 0,
        .description = sWaroftheGiantsRound2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WARRIORS_STRIKE_STRUCTURE_DECK] =
    {
        .name = _("Warriors' Str"),
        .itemId = ITEM_PACK_WARRIORS_STRIKE_STRUCTURE_DECK,
        .price = 0,
        .description = sWarriorsStrikeStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_APRIL_2012_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_APRIL_2012_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpAlphaApril2012membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_DECEMBER_2012_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_DECEMBER_2012_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpAlphaDecember2012membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_JULY_2012_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_JULY_2012_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpAlphaJuly2012membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_SEPTEMBER_2012_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_ALPHA_SEPTEMBER_2012_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpAlphaSeptember2012membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2015_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2015_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpApril2015membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2016_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2016_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpApril2016membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2017_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2017_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpApril2017membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2018_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_APRIL_2018_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpApril2018membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_AUGUST_2014_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_AUGUST_2014_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpAugust2014membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_DECEMBER_2013_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_DECEMBER_2013_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpDecember2013membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_DECEMBER_2018_MEMBERSHIP_PROMOTIONAL_CARDS] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_DECEMBER_2018_MEMBERSHIP_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sWeeklyShonenJumpDecember2018membershippromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_FEBRUARY_2015_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_FEBRUARY_2015_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpFebruary2015membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2016_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2016_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJanuary2016membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2017_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2017_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJanuary2017membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2018_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JANUARY_2018_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJanuary2018membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2013_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2013_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJuly2013membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2015_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2015_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJuly2015membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2016_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2016_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJuly2016membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2017_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2017_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJuly2017membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2018_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_JULY_2018_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpJuly2018membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_MARCH_2013_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_MARCH_2013_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpMarch2013membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_MARCH_2014_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_MARCH_2014_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpMarch2014membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2014_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2014_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpNovember2014membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2017_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2017_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpNovember2017membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2018_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_NOVEMBER_2018_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpNovember2018membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_OCTOBER_2015_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_OCTOBER_2015_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpOctober2015membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_OCTOBER_2016_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_OCTOBER_2016_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpOctober2016membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WEEKLY_SHONEN_JUMP_SEPTEMBER_2013_MEMBERSHIP_PROMOTIONAL_CARD] =
    {
        .name = _("Weekly Shonen"),
        .itemId = ITEM_PACK_WEEKLY_SHONEN_JUMP_SEPTEMBER_2013_MEMBERSHIP_PROMOTIONAL_CARD,
        .price = 0,
        .description = sWeeklyShonenJumpSeptember2013membershippromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WILD_SURVIVORS] =
    {
        .name = _("Wild Survivor"),
        .itemId = ITEM_PACK_WILD_SURVIVORS,
        .price = 0,
        .description = sWildSurvivorsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WING_RAIDERS] =
    {
        .name = _("Wing Raiders"),
        .itemId = ITEM_PACK_WING_RAIDERS,
        .price = 0,
        .description = sWingRaidersDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WORLD_CHAMPIONSHIP_2010_CARD_PACK] =
    {
        .name = _("World Champio"),
        .itemId = ITEM_PACK_WORLD_CHAMPIONSHIP_2010_CARD_PACK,
        .price = 0,
        .description = sWorldChampionship2010CardPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WORLD_CHAMPIONSHIP_2011_CARD_PACK] =
    {
        .name = _("World Champio"),
        .itemId = ITEM_PACK_WORLD_CHAMPIONSHIP_2011_CARD_PACK,
        .price = 0,
        .description = sWorldChampionship2011CardPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_WORLD_SUPERSTARS] =
    {
        .name = _("World Superst"),
        .itemId = ITEM_PACK_WORLD_SUPERSTARS,
        .price = 0,
        .description = sWorldSuperstarsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_X_SABER_POWER_UP] =
    {
        .name = _("X-Saber Power"),
        .itemId = ITEM_PACK_X_SABER_POWER_UP,
        .price = 0,
        .description = sXSaberPowerUpDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_DVD_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 3D "),
        .itemId = ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_DVD_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh3DBondsBeyondTimeDVDpromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_MOVIE_PACK] =
    {
        .name = _("Yu-Gi-Oh! 3D "),
        .itemId = ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_MOVIE_PACK,
        .price = 0,
        .description = sYuGiOh3DBondsBeyondTimeMoviePackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_THEATER_DISTRIBUTION_CARD] =
    {
        .name = _("Yu-Gi-Oh! 3D "),
        .itemId = ITEM_PACK_YU_GI_OH_3D_BONDS_BEYOND_TIME_THEATER_DISTRIBUTION_CARD,
        .price = 0,
        .description = sYuGiOh3DBondsBeyondTimeTheaterdistributioncardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_DUEL_TRANSER_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_DUEL_TRANSER_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsDuelTranserpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_STARDUST_ACCELERATOR_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_STARDUST_ACCELERATOR_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsStardustAcceleratorpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_4_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_4_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsTagForce4promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_5_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_5_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsTagForce5PromotionalCardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_5_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_TAG_FORCE_5_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsTagForce5promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_1_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_2_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_2_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume2promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_3_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_4_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_5_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_6_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_7_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_7_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume7promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_9_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5DsVolume9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_WHEELIE_BREAKERS_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_WHEELIE_BREAKERS_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsWheelieBreakersPromotionalCardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2009_STARDUST_ACCELERATOR_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2009_STARDUST_ACCELERATOR_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsWorldChampionship2009StardustAcceleratorpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2010_REVERSE_OF_ARCADIA_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2010_REVERSE_OF_ARCADIA_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsWorldChampionship2010ReverseofArcadiapromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2011_OVER_THE_NEXUS_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_WORLD_CHAMPIONSHIP_2011_OVER_THE_NEXUS_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh5DsWorldChampionship2011OvertheNexuspromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_5D_S_VOLUME_8_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! 5D'"),
        .itemId = ITEM_PACK_YU_GI_OH_5D_S_VOLUME_8_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOh5Dsvolume8promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_7_TRIALS_TO_GLORY_WORLD_CHAMPIONSHIP_TOURNAMENT_2005_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! 7 T"),
        .itemId = ITEM_PACK_YU_GI_OH_7_TRIALS_TO_GLORY_WORLD_CHAMPIONSHIP_TOURNAMENT_2005_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOh7TrialstoGloryWorldChampionshipTournament2005promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_1_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_2_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_2_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume2promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_3_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_4_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_5_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_6_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_7_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ARC"),
        .itemId = ITEM_PACK_YU_GI_OH_ARC_V_VOLUME_7_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhARCVVolume7promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR] =
    {
        .name = _("Yu-Gi-Oh! Adv"),
        .itemId = ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR,
        .price = 0,
        .description = sYuGiOhAdventCalendarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR_2018_] =
    {
        .name = _("Yu-Gi-Oh! Adv"),
        .itemId = ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR_2018_,
        .price = 0,
        .description = sYuGiOhAdventCalendar2018Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR_2019_] =
    {
        .name = _("Yu-Gi-Oh! Adv"),
        .itemId = ITEM_PACK_YU_GI_OH_ADVENT_CALENDAR_2019_,
        .price = 0,
        .description = sYuGiOhAdventCalendar2019Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CAPSULE_MONSTER_COLISEUM_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Cap"),
        .itemId = ITEM_PACK_YU_GI_OH_CAPSULE_MONSTER_COLISEUM_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhCapsuleMonsterColiseumpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2010_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2010_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2010PrizeCardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2011_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2011_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2011PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2012_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2012_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2012PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2013_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2013_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2013PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2014_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2014_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2014PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2015_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2015_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2015PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2016_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2016_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2016PrizeCardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2017_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2017_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2017prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2018_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2018_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2018prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2019_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2019_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2019prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2022_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2022_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2022prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2023_PRIZE_CARD] =
    {
        .name = _("Yu-Gi-Oh! Cha"),
        .itemId = ITEM_PACK_YU_GI_OH_CHAMPIONSHIP_SERIES_2023_PRIZE_CARD,
        .price = 0,
        .description = sYuGiOhChampionshipSeries2023prizecardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_DARK_DUEL_STORIES_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Dar"),
        .itemId = ITEM_PACK_YU_GI_OH_DARK_DUEL_STORIES_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhDarkDuelStoriespromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_DAY_APRIL_2019_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! Day"),
        .itemId = ITEM_PACK_YU_GI_OH_DAY_APRIL_2019_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhDayApril2019promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_DESTINY_BOARD_TRAVELER_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Des"),
        .itemId = ITEM_PACK_YU_GI_OH_DESTINY_BOARD_TRAVELER_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhDestinyBoardTravelerpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_DOUBLE_PACK_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Dou"),
        .itemId = ITEM_PACK_YU_GI_OH_DOUBLE_PACK_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhDoublePackpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ELEMENTAL_HERO_COLLECTION_1] =
    {
        .name = _("Yu-Gi-Oh! Ele"),
        .itemId = ITEM_PACK_YU_GI_OH_ELEMENTAL_HERO_COLLECTION_1,
        .price = 0,
        .description = sYuGiOhElementalHeroCollection1Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ELEMENTAL_HERO_COLLECTION_2] =
    {
        .name = _("Yu-Gi-Oh! Ele"),
        .itemId = ITEM_PACK_YU_GI_OH_ELEMENTAL_HERO_COLLECTION_2,
        .price = 0,
        .description = sYuGiOhElementalHeroCollection2Desc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_FORBIDDEN_MEMORIES_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! For"),
        .itemId = ITEM_PACK_YU_GI_OH_FORBIDDEN_MEMORIES_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhForbiddenMemoriespromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_CARD_ALMANAC_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_CARD_ALMANAC_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXCardAlmanacpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_DUEL_ACADEMY_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_DUEL_ACADEMY_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXDuelAcademypromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_SPECIAL_EDITION] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_SPECIAL_EDITION,
        .price = 0,
        .description = sYuGiOhGXSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_SPIRIT_CALLER_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_SPIRIT_CALLER_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXSpiritCallerpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_2_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_2_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXTagForce2promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_3_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_3_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXTagForce3promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_EVOLUTION_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_EVOLUTION_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXTagForceEvolutionpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_TAG_FORCE_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhGXTagForcepromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_ULTIMATE_BEGINNER_S_PACK] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_ULTIMATE_BEGINNER_S_PACK,
        .price = 0,
        .description = sYuGiOhGXUltimateBeginnersPackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_1_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_2_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_2_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume2promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_3_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_4_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_5_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_6_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_7_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_7_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume7promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_8_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_8_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume8promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_GX_VOLUME_9_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! GX "),
        .itemId = ITEM_PACK_YU_GI_OH_GX_VOLUME_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhGXVolume9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_LEGACY_OF_THE_DUELIST_LINK_EVOLUTION_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Leg"),
        .itemId = ITEM_PACK_YU_GI_OH_LEGACY_OF_THE_DUELIST_LINK_EVOLUTION_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhLegacyoftheDuelistLinkEvolutionpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_NIGHTMARE_TROUBADOUR_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Nig"),
        .itemId = ITEM_PACK_YU_GI_OH_NIGHTMARE_TROUBADOUR_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhNightmareTroubadourpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_JOEY_THE_PASSION_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Pow"),
        .itemId = ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_JOEY_THE_PASSION_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhPowerofChaosJoeythePassionpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_KAIBA_THE_REVENGE_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Pow"),
        .itemId = ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_KAIBA_THE_REVENGE_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhPowerofChaosKaibatheRevengepromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_YUGI_THE_DESTINY_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Pow"),
        .itemId = ITEM_PACK_YU_GI_OH_POWER_OF_CHAOS_YUGI_THE_DESTINY_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhPowerofChaosYugitheDestinypromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_R_VOLUME_1_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! R V"),
        .itemId = ITEM_PACK_YU_GI_OH_R_VOLUME_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhRVolume1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_R_VOLUME_3_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! R V"),
        .itemId = ITEM_PACK_YU_GI_OH_R_VOLUME_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhRVolume3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_R_VOLUME_4_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! R V"),
        .itemId = ITEM_PACK_YU_GI_OH_R_VOLUME_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhRVolume4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_R_VOLUME_5_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! R V"),
        .itemId = ITEM_PACK_YU_GI_OH_R_VOLUME_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhRVolume5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_RESHEF_OF_DESTRUCTION_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Res"),
        .itemId = ITEM_PACK_YU_GI_OH_RESHEF_OF_DESTRUCTION_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhReshefofDestructionpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_TCG_REMOTE_DUEL_EXTRAVAGANZA_PARTICIPATION_CARD] =
    {
        .name = _("Yu-Gi-Oh! TCG"),
        .itemId = ITEM_PACK_YU_GI_OH_TCG_REMOTE_DUEL_EXTRAVAGANZA_PARTICIPATION_CARD,
        .price = 0,
        .description = sYuGiOhTCGRemoteDuelExtravaganzaparticipationcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_BLU_RAY_DVD_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_BLU_RAY_DVD_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsBlurayDVDpromotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsMoviePackDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_SECRET_EDITION] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_SECRET_EDITION,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsMoviePackSecretEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_SPECIAL_EDITION] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_SPECIAL_EDITION,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsMoviePackSpecialEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_GOLD_EDITION] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_MOVIE_PACK_GOLD_EDITION,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsMoviePackGoldEditionDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_THEATER_DISTRIBUTION_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DARK_SIDE_OF_DIMENSIONS_THEATER_DISTRIBUTION_CARDS,
        .price = 0,
        .description = sYuGiOhTheDarkSideofDimensionsTheaterdistributioncardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DAWN_OF_DESTINY_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DAWN_OF_DESTINY_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhTheDawnofDestinypromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_DUELISTS_OF_THE_ROSES_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_DUELISTS_OF_THE_ROSES_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhTheDuelistsoftheRosespromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_ETERNAL_DUELIST_SOUL_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_ETERNAL_DUELIST_SOUL_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhTheEternalDuelistSoulpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_FALSEBOUND_KINGDOM_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_FALSEBOUND_KINGDOM_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhTheFalseboundKingdompromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_THE_SACRED_CARDS_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! The"),
        .itemId = ITEM_PACK_YU_GI_OH_THE_SACRED_CARDS_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhTheSacredCardspromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_TRADING_CARD_GAME_TOUR_2004_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! Tra"),
        .itemId = ITEM_PACK_YU_GI_OH_TRADING_CARD_GAME_TOUR_2004_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhTradingCardGameTour2004promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ULTIMATE_MASTERS_WORLD_CHAMPIONSHIP_TOURNAMENT_2006_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Ult"),
        .itemId = ITEM_PACK_YU_GI_OH_ULTIMATE_MASTERS_WORLD_CHAMPIONSHIP_TOURNAMENT_2006_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhUltimateMastersWorldChampionshipTournament2006promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2004_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2004_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2004prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2005_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2005_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2005prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2006_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2006_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2006prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2007_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2007_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2007prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2007_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2007_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2007promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2008_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2008_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2008promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2017_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2017_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2017prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2018_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2018_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2018prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2019_JAPANESE_NATIONAL_QUALIFIERS_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_2019_JAPANESE_NATIONAL_QUALIFIERS_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionship2019JapaneseNationalQualifiersprizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_QUALIFIER_NATIONAL_CHAMPIONSHIPS_2011_PRIZE_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_QUALIFIER_NATIONAL_CHAMPIONSHIPS_2011_PRIZE_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionshipQualifierNationalChampionships2011prizecardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_TOURNAMENT_2004_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLD_CHAMPIONSHIP_TOURNAMENT_2004_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhWorldChampionshipTournament2004promotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_WORLDWIDE_EDITION_STAIRWAY_TO_THE_DESTINED_DUEL_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! Wor"),
        .itemId = ITEM_PACK_YU_GI_OH_WORLDWIDE_EDITION_STAIRWAY_TO_THE_DESTINED_DUEL_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhWorldwideEditionStairwaytotheDestinedDuelpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_1_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_1_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume1promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_2_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_2_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume2promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_3_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_3_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume3promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_4_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_4_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume4promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_5_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_5_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume5promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_6_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_6_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume6promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_7_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_7_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume7promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_8_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_8_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume8promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_9_PROMOTIONAL_CARD] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_VOLUME_9_PROMOTIONAL_CARD,
        .price = 0,
        .description = sYuGiOhZEXALVolume9promotionalcardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_ZEXAL_WORLD_DUEL_CARNIVAL_PROMOTIONAL_CARDS] =
    {
        .name = _("Yu-Gi-Oh! ZEX"),
        .itemId = ITEM_PACK_YU_GI_OH_ZEXAL_WORLD_DUEL_CARNIVAL_PROMOTIONAL_CARDS,
        .price = 0,
        .description = sYuGiOhZEXALWorldDuelCarnivalpromotionalcardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YU_GI_OH_AT_HOME_SWEEPSTAKES] =
    {
        .name = _("Yu-Gi-Oh! at "),
        .itemId = ITEM_PACK_YU_GI_OH_AT_HOME_SWEEPSTAKES,
        .price = 0,
        .description = sYuGiOhatHomeSweepstakesDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YUGI_KAIBA_COLLECTOR_BOX] =
    {
        .name = _("Yugi & Kaiba "),
        .itemId = ITEM_PACK_YUGI_KAIBA_COLLECTOR_BOX,
        .price = 0,
        .description = sYugiKaibaCollectorBoxDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_YUGI_S_LEGENDARY_DECKS] =
    {
        .name = _("Yugi's Legend"),
        .itemId = ITEM_PACK_YUGI_S_LEGENDARY_DECKS,
        .price = 0,
        .description = sYugisLegendaryDecksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ZEXAL_COLLECTION_TIN] =
    {
        .name = _("Zexal Collect"),
        .itemId = ITEM_PACK_ZEXAL_COLLECTION_TIN,
        .price = 0,
        .description = sZexalCollectionTinDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },

	[ITEM_PACK_ZOMBIE_WORLD_STRUCTURE_DECK] =
    {
        .name = _("Zombie World "),
        .itemId = ITEM_PACK_ZOMBIE_WORLD_STRUCTURE_DECK,
        .price = 0,
        .description = sZombieWorldStructureDeckDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Pack,
    },
};

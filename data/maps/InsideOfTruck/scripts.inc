InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	@ msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	additem ITEM_4_STARRED_LADYBUG_OF_DOOM
	additem ITEM_7_COLORED_FISH
	additem ITEM_A_LEGENDARY_OCEAN
	additem ITEM_ABYSS_SOLDIER
	additem ITEM_AIRKNIGHT_PARSHATH
	additem ITEM_AMAZONESS_ARCHER
	additem ITEM_AMPHIBIOUS_BUGROTH_MK_3
	additem ITEM_ANTI_SPELL_FRAGRANCE
	additem ITEM_AQUA_MADOOR
	additem ITEM_AQUA_SPIRIT
	additem ITEM_ARCHFIEND_SOLDIER
	additem ITEM_ARSENAL_BUG
	additem ITEM_ARSENAL_SUMMONER
	additem ITEM_ASURA_PRIEST
	additem ITEM_AXE_OF_DESPAIR
	additem ITEM_BANISHER_OF_THE_LIGHT
	additem ITEM_BARREL_BEHIND_THE_DOOR
	additem ITEM_BATTLE_FOOTBALLER
	additem ITEM_BATTLE_OX
	additem ITEM_BAZOO_THE_SOUL_EATER
	additem ITEM_BERSERK_GORILLA
	additem ITEM_BICKURIBOX
	additem ITEM_BIG_BANG_SHOT
	additem ITEM_BIG_SHIELD_GARDNA
	additem ITEM_BIG_TUSKED_MAMMOTH
	additem ITEM_BLACK_ILLUSION_RITUAL
	additem ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	additem ITEM_BLACK_PENDANT
	additem ITEM_BLACK_SKULL_DRAGON
	additem ITEM_BLADE_KNIGHT
	additem ITEM_BLAST_WITH_CHAIN
	additem ITEM_BLAZING_INPACHI
	additem ITEM_BLINDLY_LOYAL_GOBLIN
	additem ITEM_BLOCK_ATTACK
	additem ITEM_BLOWBACK_DRAGON
	additem ITEM_BLUE_EYES_ULTIMATE_DRAGON
	additem ITEM_BLUE_EYES_WHITE_DRAGON
	additem ITEM_BOOK_OF_LIFE
	additem ITEM_BOOK_OF_MOON
	additem ITEM_BOOK_OF_TAIYOU
	additem ITEM_BOTTOMLESS_TRAP_HOLE
	additem ITEM_BOWGANIAN
	additem ITEM_BRAIN_CONTROL
	additem ITEM_BREAKER_THE_MAGICAL_WARRIOR
	additem ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	additem ITEM_BRRON_MAD_KING_OF_DARK_WORLD
	additem ITEM_BUSTER_BLADER
	additem ITEM_BYSER_SHOCK
	additem ITEM_CALL_OF_THE_HAUNTED
	additem ITEM_CANNON_SOLDIER
	additem ITEM_CARD_DESTRUCTION
	additem ITEM_CASTLE_OF_DARK_ILLUSIONS
	additem ITEM_CASTLE_WALLS
	additem ITEM_CATAPULT_TURTLE
	additem ITEM_CEASEFIRE
	additem ITEM_CHAIN_DISAPPEARANCE
	additem ITEM_CHAIN_ENERGY
	additem ITEM_CHAINSAW_INSECT
	additem ITEM_CHANGE_OF_HEART
	additem ITEM_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END
	additem ITEM_CHAOS_SORCERER
	additem ITEM_CHARCOAL_INPACHI
	additem ITEM_CHIRON_THE_MAGE
	additem ITEM_CIPHER_SOLDIER
	additem ITEM_COLD_WAVE
	additem ITEM_COMMAND_KNIGHT
	additem ITEM_COMPULSORY_EVACUATION_DEVICE
	additem ITEM_CONFISCATION
	additem ITEM_CRASS_CLOWN
	additem ITEM_CREATURE_SWAP
	additem ITEM_CRUSH_CARD_VIRUS
	additem ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	additem ITEM_CYBER_DRAGON
	additem ITEM_CYBER_END_DRAGON
	additem ITEM_CYBER_HARPIE_LADY
	additem ITEM_CYBER_JAR
	additem ITEM_CYBER_TWIN_DRAGON
	additem ITEM_CYBER_STEIN
	additem ITEM_D_D_ASSAILANT
	additem ITEM_D_D_CRAZY_BEAST
	additem ITEM_D_D_SURVIVOR
	additem ITEM_D_D_TRAINER
	additem ITEM_D_D_WARRIOR_LADY
	additem ITEM_DARK_BLADE
	additem ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	additem ITEM_DARK_DEAL
	additem ITEM_DARK_ELF
	additem ITEM_DARK_HOLE
	additem ITEM_DARK_MAGIC_CURTAIN
	additem ITEM_DARK_MAGICIAN
	additem ITEM_DARK_MAGICIAN_OF_CHAOS
	additem ITEM_DARK_MIMIC_LV1
	additem ITEM_DARK_MIMIC_LV3
	additem ITEM_DARK_PALADIN
	additem ITEM_DARK_RULER_HA_DES
	additem ITEM_DARK_SCORPION_CHICK_THE_YELLOW
	additem ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	additem ITEM_DARK_WORLD_LIGHTNING
	additem ITEM_DE_SPELL
	additem ITEM_DECK_DEVASTATION_VIRUS
	additem ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	additem ITEM_DELINQUENT_DUO
	additem ITEM_DES_DENDLE
	additem ITEM_DES_KOALA
	additem ITEM_DES_LACOODA
	additem ITEM_DES_WOMBAT
	additem ITEM_DESERT_SUNLIGHT
	additem ITEM_DIAN_KETO_THE_CURE_MASTER
	additem ITEM_DIMENSION_FUSION
	additem ITEM_DON_ZALOOG
	additem ITEM_DOOM_DOZER
	additem ITEM_DOOMCALIBER_KNIGHT
	additem ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	additem ITEM_DRAGON_S_MIRROR
	additem ITEM_DRAGON_S_RAGE
	additem ITEM_DREAM_CLOWN
	additem ITEM_DRILLROID
	additem ITEM_DROP_OFF
	additem ITEM_DUNAMES_DARK_WITCH
	additem ITEM_DUST_TORNADO
	additem ITEM_EARTHBOUND_SPIRIT
	additem ITEM_ELECTRIC_SNAKE
	additem ITEM_ELEMENTAL_HERO_CLAYMAN
	additem ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	additem ITEM_ELEMENTAL_HERO_WILDHEART
	additem ITEM_EMERGENCY_PROVISIONS
	additem ITEM_EMISSARY_OF_THE_AFTERLIFE
	additem ITEM_ENEMY_CONTROLLER
	additem ITEM_EXARION_UNIVERSE
	additem ITEM_EXCHANGE
	additem ITEM_EXCHANGE_OF_THE_SPIRIT
	additem ITEM_EXILED_FORCE
	additem ITEM_EXODIA_THE_FORBIDDEN_ONE
	additem ITEM_FAKE_TRAP
	additem ITEM_FAMILIAR_POSSESSED_AUSSA
	additem ITEM_FAMILIAR_POSSESSED_ERIA
	additem ITEM_FAMILIAR_POSSESSED_HIITA
	additem ITEM_FAMILIAR_POSSESSED_WYNN
	additem ITEM_FIBER_JAR
	additem ITEM_FINAL_FLAME
	additem ITEM_FISSURE
	additem ITEM_FLAME_SWORDSMAN
	additem ITEM_FLYING_KAMAKIRI_1
	additem ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	additem ITEM_GAGAGIGO
	additem ITEM_GAIA_POWER
	additem ITEM_GAIA_THE_DRAGON_CHAMPION
	additem ITEM_GATLING_DRAGON
	additem ITEM_GEAR_GOLEM_THE_MOVING_FORTRESS
	additem ITEM_GEARFRIED_THE_IRON_KNIGHT
	additem ITEM_GEMINI_ELF
	additem ITEM_GIANT_GERM
	additem ITEM_GIANT_ORC
	additem ITEM_GIANT_RAT
	additem ITEM_GIANT_RED_SEASNAKE
	additem ITEM_GIANT_SOLDIER_OF_STONE
	additem ITEM_GIANT_TRUNADE
	additem ITEM_GIGA_TECH_WOLF
	additem ITEM_GIGANTES
	additem ITEM_GIL_GARTH
	additem ITEM_GILASAURUS
	additem ITEM_GOBLIN_ATTACK_FORCE
	additem ITEM_GOBLIN_ELITE_ATTACK_FORCE
	additem ITEM_GOKIPON
	additem ITEM_GOLEM_SENTRY
	additem ITEM_GORA_TURTLE
	additem ITEM_GRACEFUL_CHARITY
	additem ITEM_GRAVEKEEPER_S_ASSAILANT
	additem ITEM_GRAVEKEEPER_S_GUARD
	additem ITEM_GRAVEKEEPER_S_SPEAR_SOLDIER
	additem ITEM_GRAVEKEEPER_S_SPY
	additem ITEM_GRAVEKEEPER_S_WATCHER
	additem ITEM_GRAVITY_BIND
	additem ITEM_GREAT_WHITE
	additem ITEM_GUARDIAN_SPHINX
	additem ITEM_GYAKU_GIRE_PANDA
	additem ITEM_GYAKUTENNO_MEGAMI
	additem ITEM_HALLOWED_LIFE_BARRIER
	additem ITEM_HANE_HANE
	additem ITEM_HARPIE_S_FEATHER_DUSTER
	additem ITEM_HEAVY_STORM
	additem ITEM_HIERACOSPHINX
	additem ITEM_HORN_OF_HEAVEN
	additem ITEM_HOWLING_INSECT
	additem ITEM_HUMANOID_SLIME
	additem ITEM_HYDROGEDDON
	additem ITEM_HYPER_HAMMERHEAD
	additem ITEM_IMPERIAL_ORDER
	additem ITEM_INABA_WHITE_RABBIT
	additem ITEM_INDOMITABLE_FIGHTER_LEI_LEI
	additem ITEM_INJECTION_FAIRY_LILY
	additem ITEM_INPACHI
	additem ITEM_INSECT_KNIGHT
	additem ITEM_ISLAND_TURTLE
	additem ITEM_JAR_OF_GREED
	additem ITEM_JINZO
	additem ITEM_JIRAI_GUMO
	additem ITEM_JOWGEN_THE_SPIRITUALIST
	additem ITEM_JUDGE_MAN
	additem ITEM_JUST_DESSERTS
	additem ITEM_KAISER_SEA_HORSE
	additem ITEM_KARMA_CUT
	additem ITEM_KING_DRAGUN
	additem ITEM_KING_OF_THE_SWAMP
	additem ITEM_KING_TIGER_WANGHU
	additem ITEM_KURIBOH
	additem ITEM_KYCOO_THE_GHOST_DESTROYER
	additem ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	additem ITEM_LABYRINTH_TANK
	additem ITEM_LADY_NINJA_YAE
	additem ITEM_LAST_WILL
	additem ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	additem ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	additem ITEM_LEGENDARY_JUJITSU_MASTER
	additem ITEM_LEVEL_LIMIT_AREA_B
	additem ITEM_LEVIA_DRAGON_DAEDALUS
	additem ITEM_LIGHT_OF_INTERVENTION
	additem ITEM_LIGHTNING_VORTEX
	additem ITEM_LIMITER_REMOVAL
	additem ITEM_LUSTER_DRAGON
	additem ITEM_MAD_DOG_OF_DARKNESS
	additem ITEM_MAGE_POWER
	additem ITEM_MAGIC_CYLINDER
	additem ITEM_MAGIC_JAMMER
	additem ITEM_MAGICAL_DIMENSION
	additem ITEM_MAGICAL_MERCHANT
	additem ITEM_MAGICAL_SCIENTIST
	additem ITEM_MAGICIAN_OF_FAITH
	additem ITEM_MAGICIAN_S_CIRCLE
	additem ITEM_MAGICIAN_S_VALKYRIA
	additem ITEM_MAIDEN_OF_THE_AQUA
	additem ITEM_MAKYURA_THE_DESTRUCTOR
	additem ITEM_MAN_EATER_BUG
	additem ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	additem ITEM_MANTICORE_OF_DARKNESS
	additem ITEM_MARAUDING_CAPTAIN
	additem ITEM_MASK_OF_DARKNESS
	additem ITEM_MASK_OF_RESTRICT
	additem ITEM_MASKED_DRAGON
	additem ITEM_MASKED_SORCERER
	additem ITEM_MATAZA_THE_ZAPPER
	additem ITEM_MECHANICALCHASER
	additem ITEM_MEGAMORPH
	additem ITEM_MERMAID_KNIGHT
	additem ITEM_MESSENGER_OF_PEACE
	additem ITEM_METAL_REFLECT_SLIME
	additem ITEM_METAMORPHOSIS
	additem ITEM_MILUS_RADIANT
	additem ITEM_MINAR
	additem ITEM_MIND_CONTROL
	additem ITEM_MINE_GOLEM
	additem ITEM_MIRACLE_RESTORING
	additem ITEM_MIRAGE_DRAGON
	additem ITEM_MIRAGE_OF_NIGHTMARE
	additem ITEM_MIRROR_FORCE
	additem ITEM_MOAI_INTERCEPTOR_CANNONS
	additem ITEM_MOBIUS_THE_FROST_MONARCH
	additem ITEM_MONSTER_GATE
	additem ITEM_MONSTER_REBORN
	additem ITEM_MONSTER_REINCARNATION
	additem ITEM_MORPHING_JAR
	additem ITEM_MOTHER_GRIZZLY
	additem ITEM_MUKA_MUKA
	additem ITEM_MYSTIC_SWORDSMAN_LV2
	additem ITEM_MYSTIC_SWORDSMAN_LV4
	additem ITEM_MYSTIC_TOMATO
	additem ITEM_MYSTICAL_ELF
	additem ITEM_MYSTICAL_SPACE_TYPHOON
	additem ITEM_MYSTIK_WOK
	additem ITEM_NECROVALLEY
	additem ITEM_NEEDLE_CEILING
	additem ITEM_NEKO_MANE_KING
	additem ITEM_NEO_BUG
	additem ITEM_NEO_THE_MAGIC_SWORDSMAN
	additem ITEM_NEWDORIA
	additem ITEM_NIGHT_ASSAILANT
	additem ITEM_NIGHTMARE_WHEEL
	additem ITEM_NIGHTMARE_S_STEELCAGE
	additem ITEM_NIMBLE_MOMONGA
	additem ITEM_NIN_KEN_DOG
	additem ITEM_NINJA_GRANDMASTER_SASUKE
	additem ITEM_NOBLEMAN_OF_CROSSOUT
	additem ITEM_NOBLEMAN_OF_EXTERMINATION
	additem ITEM_OFFERINGS_TO_THE_DOOMED
	additem ITEM_OJAMA_KING
	additem ITEM_OJAMA_TRIO
	additem ITEM_OOKAZI
	additem ITEM_OPPRESSED_PEOPLE
	additem ITEM_OPTICLOPS
	additem ITEM_PAINFUL_CHOICE
	additem ITEM_PALADIN_OF_WHITE_DRAGON
	additem ITEM_PENGUIN_KNIGHT
	additem ITEM_PHOENIX_WING_WIND_BLAST
	additem ITEM_PIKERU_S_CIRCLE_OF_ENCHANTMENT
	additem ITEM_PINCH_HOPPER
	additem ITEM_PITCH_BLACK_POWER_STONE
	additem ITEM_POISON_OF_THE_OLD_MAN
	additem ITEM_POLYMERIZATION
	additem ITEM_POT_OF_AVARICE
	additem ITEM_POT_OF_GENEROSITY
	additem ITEM_POT_OF_GREED
	additem ITEM_PREMATURE_BURIAL
	additem ITEM_PREVENT_RAT
	additem ITEM_PRICKLE_FAIRY
	additem ITEM_PRINCESS_OF_TSURUGI
	additem ITEM_PROTECTOR_OF_THE_SANCTUARY
	additem ITEM_PYRAMID_TURTLE
	additem ITEM_RAIGEKI
	additem ITEM_RAIGEKI_BREAK
	additem ITEM_REAPER_ON_THE_NIGHTMARE
	additem ITEM_REASONING
	additem ITEM_RECKLESS_GREED
	additem ITEM_REFLECT_BOUNDER
	additem ITEM_REINFORCEMENT_OF_THE_ARMY
	additem ITEM_REINFORCEMENTS
	additem ITEM_RELINQUISHED
	additem ITEM_RELOAD
	additem ITEM_REMOVE_TRAP
	additem ITEM_RESCUE_CAT
	additem ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	additem ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	additem ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	additem ITEM_RING_OF_DESTRUCTION
	additem ITEM_RISING_AIR_CURRENT
	additem ITEM_ROBBIN_GOBLIN
	additem ITEM_ROULETTE_BARREL
	additem ITEM_ROYAL_DECREE
	additem ITEM_ROYAL_MAGICAL_LIBRARY
	additem ITEM_ROYAL_OPPRESSION
	additem ITEM_RUSH_RECKLESSLY
	additem ITEM_RYU_KOKKI
	additem ITEM_SABER_BEETLE
	additem ITEM_SACRED_CRANE
	additem ITEM_SACRED_PHOENIX_OF_NEPHTHYS
	additem ITEM_SAKURETSU_ARMOR
	additem ITEM_SALVAGE
	additem ITEM_SAND_MOTH
	additem ITEM_SANGAN
	additem ITEM_SASUKE_SAMURAI
	additem ITEM_SASUKE_SAMURAI_4
	additem ITEM_SCAPEGOAT
	additem ITEM_SEA_SERPENT_WARRIOR_OF_DARKNESS
	additem ITEM_SECOND_COIN_TOSS
	additem ITEM_SECRET_BARREL
	additem ITEM_SELF_DESTRUCT_BUTTON
	additem ITEM_SERIAL_SPELL
	additem ITEM_SERPENTINE_PRINCESS
	additem ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	additem ITEM_SHINING_ANGEL
	additem ITEM_SHRINK
	additem ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	additem ITEM_SILPHEED
	additem ITEM_SINISTER_SERPENT
	additem ITEM_SKILL_DRAIN
	additem ITEM_SKILLED_DARK_MAGICIAN
	additem ITEM_SKILLED_WHITE_MAGICIAN
	additem ITEM_SKULL_DOG_MARRON
	additem ITEM_SKULL_LAIR
	additem ITEM_SKY_SCOUT
	additem ITEM_SLATE_WARRIOR
	additem ITEM_SMASHING_GROUND
	additem ITEM_SNATCH_STEAL
	additem ITEM_SOLEMN_JUDGMENT
	additem ITEM_SOLEMN_WISHES
	additem ITEM_SOUL_EXCHANGE
	additem ITEM_SOUL_TIGER
	additem ITEM_SPEAR_CRETIN
	additem ITEM_SPEAR_DRAGON
	additem ITEM_SPELL_CANCELLER
	additem ITEM_SPELL_REPRODUCTION
	additem ITEM_SPIRIT_OF_THE_HARP
	additem ITEM_SPIRIT_REAPER
	additem ITEM_SPIRITUAL_EARTH_ART_KUROGANE
	additem ITEM_SPIRITUAL_WATER_ART_AOI
	additem ITEM_SPIRITUAL_WIND_ART_MIYABI
	additem ITEM_SPIRITUALISM
	additem ITEM_STEALTH_BIRD
	additem ITEM_STONE_STATUE_OF_THE_AZTECS
	additem ITEM_STOP_DEFENSE
	additem ITEM_SUMMONED_SKULL
	additem ITEM_SWARM_OF_LOCUSTS
	additem ITEM_SWARM_OF_SCARABS
	additem ITEM_SWORDS_OF_REVEALING_LIGHT
	additem ITEM_TERRAFORMING
	additem ITEM_THE_BIG_MARCH_OF_ANIMALS
	additem ITEM_THE_DRAGON_DWELLING_IN_THE_CAVE
	additem ITEM_THE_FIEND_MEGACYBER
	additem ITEM_THE_FORCEFUL_SENTRY
	additem ITEM_THE_FORGIVING_MAIDEN
	additem ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	additem ITEM_THE_LITTLE_SWORDSMAN_OF_AILE
	additem ITEM_THE_WICKED_WORM_BEAST
	additem ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	additem ITEM_THOUSAND_EYES_RESTRICT
	additem ITEM_THREATENING_ROAR
	additem ITEM_THROWSTONE_UNIT
	additem ITEM_THUNDER_DRAGON
	additem ITEM_THUNDER_NYAN_NYAN
	additem ITEM_TIME_SEAL
	additem ITEM_TOON_CANNON_SOLDIER
	additem ITEM_TOON_DARK_MAGICIAN_GIRL
	additem ITEM_TOON_GEMINI_ELF
	additem ITEM_TOON_GOBLIN_ATTACK_FORCE
	additem ITEM_TOON_MASKED_SORCERER
	additem ITEM_TOON_TABLE_OF_CONTENTS
	additem ITEM_TORRENTIAL_TRIBUTE
	additem ITEM_TRAP_DUSTSHOOT
	additem ITEM_TRAP_HOLE
	additem ITEM_TRAP_MASTER
	additem ITEM_TREEBORN_FROG
	additem ITEM_TREMENDOUS_FIRE
	additem ITEM_TRIBE_INFECTING_VIRUS
	additem ITEM_TRIBUTE_TO_THE_DOOMED
	additem ITEM_TSUKUYOMI
	additem ITEM_TWIN_HEADED_BEHEMOTH
	additem ITEM_TWIN_HEADED_THUNDER_DRAGON
	additem ITEM_ULTIMATE_INSECT_LV3
	additem ITEM_ULTIMATE_INSECT_LV5
	additem ITEM_ULTIMATE_INSECT_LV7
	additem ITEM_ULTIMATE_OFFERING
	additem ITEM_UNITED_WE_STAND
	additem ITEM_UPSTART_GOBLIN
	additem ITEM_VAMPIRE_LORD
	additem ITEM_VORSE_RAIDER
	additem ITEM_WABOKU
	additem ITEM_WALL_OF_ILLUSION
	additem ITEM_WALL_OF_REVEALING_LIGHT
	additem ITEM_WAVE_MOTION_CANNON
	additem ITEM_WHITE_DRAGON_RITUAL
	additem ITEM_WHITE_MAGICAL_HAT
	additem ITEM_WIDESPREAD_RUIN
	additem ITEM_WITCH_OF_THE_BLACK_FOREST
	additem ITEM_X_HEAD_CANNON
	additem ITEM_XING_ZHEN_HU
	additem ITEM_YATA_GARASU
	additem ITEM_YOMI_SHIP
	additem ITEM_ZABORG_THE_THUNDER_MONARCH
	additem ITEM_ZOMBYRA_THE_DARK
	additem ITEM_ZURE_KNIGHT_OF_DARK_WORLD
	additem ITEM_AMAZONESS_SPIRITUALIST
	additem ITEM_ARCHFIEND_CAVALRY
	additem ITEM_ARCHFIEND_HEIRESS
	additem ITEM_ARCHFIEND_INTERCEPTOR
	additem ITEM_BAKU_THE_BEAST_NINJA
	additem ITEM_BEGINNING_KNIGHT
	additem ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	additem ITEM_BERLINETH_THE_FIRESTORM_VASSAL
	additem ITEM_BLACK_DRAGON_S_CHICK
	additem ITEM_BLACK_METAL_DRAGON
	additem ITEM_BLUE_FLAME_SWORDSMAN
	additem ITEM_BONE_ARCHFIEND
	additem ITEM_CHRONICLE_SORCERESS
	additem ITEM_CYBER_DRAGON_DREI
	additem ITEM_CYBER_DRAGON_VIER
	additem ITEM_CYBER_DRAGON_ZWEI
	additem ITEM_CYBER_LARVA
	additem ITEM_DEFENDER_OF_NEPHTHYS
	additem ITEM_DICTATOR_OF_D_
	additem ITEM_DIMENSION_CONJURER
	additem ITEM_DISCIPLE_OF_NEPHTHYS
	additem ITEM_DUPE_FROG
	additem ITEM_EIDOS_THE_UNDERWORLD_SQUIRE
	additem ITEM_ELEMENTAL_HERO_BLAZEMAN
	additem ITEM_ELEMENTAL_HERO_WOODSMAN
	additem ITEM_ENVOY_OF_CHAOS
	additem ITEM_EVENING_TWILIGHT_KNIGHT
	additem ITEM_FIGHTING_FLAME_SWORDSMAN
	additem ITEM_FLIP_FLOP_FROG
	additem ITEM_FUSION_DEVOURER
	additem ITEM_GEARFRIED_THE_RED_EYES_IRON_KNIGHT
	additem ITEM_GEM_KNIGHT_QUARTZ
	additem ITEM_GENTA_GATEMAN_OF_DARK_WORLD
	additem ITEM_GOBLIN_POTHOLE_SQUAD
	additem ITEM_GREEN_NINJA
	additem ITEM_GREN_TACTICIAN_OF_DARK_WORLD
	additem ITEM_HAND_OF_NEPHTHYS
	additem ITEM_ICE_KNIGHT
	additem ITEM_KAGERO_THE_CANNON_NINJA
	additem ITEM_KAIBAMAN
	additem ITEM_KEEPER_OF_DRAGON_MAGIC
	additem ITEM_KEEPER_OF_THE_SHRINE
	additem ITEM_LANCER_ARCHFIEND
	additem ITEM_LORD_OF_D_
	additem ITEM_LUCIUS_THE_SHADOW_VASSAL
	additem ITEM_MAD_ARCHFIEND
	additem ITEM_MAGICIAN_S_ROBE
	additem ITEM_MAGICIAN_S_ROD
	additem ITEM_MAGICIANS_SOULS
	additem ITEM_MAGIKURIBOH
	additem ITEM_MASKED_NINJA_EBISU
	additem ITEM_MATRIARCH_OF_NEPHTHYS
	additem ITEM_MITSU_THE_INSECT_NINJA
	additem ITEM_MYSTICAL_ELF_WHITE_LIGHTNING
	additem ITEM_NINJA_GRANDMASTER_HANZO
	additem ITEM_PARL_HERMIT_OF_DARK_WORLD
	additem ITEM_RED_EYES_BABY_DRAGON
	additem ITEM_RED_EYES_RETRO_DRAGON
	additem ITEM_RED_EYES_WYVERN
	additem ITEM_RELINKURIBOH
	additem ITEM_RONINTOADIN
	additem ITEM_SALAMANDRA_THE_FLYING_FLAME_DRAGON
	additem ITEM_SCARR_SCOUT_OF_DARK_WORLD
	additem ITEM_SENJU_OF_THE_THOUSAND_HANDS
	additem ITEM_SKILLED_RED_MAGICIAN
	additem ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	additem ITEM_SONIC_BIRD
	additem ITEM_SPHERE_KURIBOH
	additem ITEM_SUBSTITOAD
	additem ITEM_SUPER_SOLDIER_SOUL
	additem ITEM_SWAP_FROG
	additem ITEM_T_A_D_P_O_L_E_
	additem ITEM_THE_BLACK_STONE_OF_LEGEND
	additem ITEM_THE_DARK_HEX_SEALED_FUSION
	additem ITEM_THE_EARTH_HEX_SEALED_FUSION
	additem ITEM_THE_LIGHT_HEX_SEALED_FUSION
	additem ITEM_THUNDER_DRAGONMATRIX
	additem ITEM_THUNDER_SEA_HORSE
	additem ITEM_TOBARI_THE_SKY_NINJA
	additem ITEM_TRADETOAD
	additem ITEM_TRAPTRIX_ARACHNOCAMPA
	additem ITEM_TRAPTRIX_ATRAX
	additem ITEM_TRAPTRIX_DIONAEA
	additem ITEM_TRAPTRIX_GENLISEA
	additem ITEM_TRAPTRIX_MANTIS
	additem ITEM_TRAPTRIX_MYRMELEO
	additem ITEM_TRAPTRIX_NEPENTHES
	additem ITEM_TRAPTRIX_PUDICA
	additem ITEM_TRAPTRIX_VESICULO
	additem ITEM_TWILIGHT_NINJA_SHINGETSU
	additem ITEM_UPSTART_GOLDEN_NINJA
	additem ITEM_VISION_HERO_VYON
	additem ITEM_WROUGHTWEILER
	additem ITEM_YELLOW_NINJA
	end

InsideOfTruck_EventScript_MovingBox2::
	additem ITEM_PACK_LEGEND_OF_BLUE_EYES_WHITE_DRAGON, 10
	additem ITEM_PACK_STARTER_DECKYUGI, 10
	additem ITEM_PACK_STARTER_DECKKAIBA, 10
	additem ITEM_PACK_METAL_RAIDERS, 10
	additem ITEM_PACK_SPELL_RULER, 10
	additem ITEM_PACK_LABYRINTH_OF_NIGHTMARE, 10
	additem ITEM_PACK_STARTER_DECKJOEY, 10
	additem ITEM_PACK_STARTER_DECKPEGASUS, 10
	additem ITEM_PACK_YUGI_KAIBA, 10
	additem ITEM_PACK_CRITTER, 10
	additem ITEM_PACK_TREASURE, 10
	end

InsideOfTruck_EventScript_MovingBox3::
	setvar VAR_YGO_BATTLE, 1
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	end

InsideOfTruck_EventScript_MovingBox4::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_DEFAULT
	dynmultichoice 0, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, InsideOfTruck_Text_CardShop, InsideOfTruck_Text_CardBanlists
	switch VAR_RESULT
	case 0, InsideOfTruck_EventScript_CardShops
	case 1, InsideOfTruck_EventScript_CardBanlists
	case MULTI_B_PRESSED, InsideOfTruck_EventScript_End

InsideOfTruck_EventScript_CardShops::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_DEFAULT
	dynmultichoice 0, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, InsideOfTruck_Text_YugiKaiba, InsideOfTruck_Text_Critter, InsideOfTruck_Text_Treasure, InsideOfTruck_Text_Imperial, InsideOfTruck_Text_Android, InsideOfTruck_Text_JoeyPegasus, InsideOfTruck_Text_Fiber, InsideOfTruck_Text_Yata, InsideOfTruck_Text_Scientist, InsideOfTruck_Text_Vampire, InsideOfTruck_Text_Chaos, InsideOfTruck_Text_Warrior, InsideOfTruck_Text_Goat, InsideOfTruck_Text_Cyber, InsideOfTruck_Text_Reaper, InsideOfTruck_Text_ChaosReturn, InsideOfTruck_Text_Demise, InsideOfTruck_Text_Trooper, InsideOfTruck_Text_Zombie, InsideOfTruck_Text_PerfectCircle, InsideOfTruck_Text_DADReturn, InsideOfTruck_Text_Gladiator, InsideOfTruck_Text_TeleDAD, InsideOfTruck_Text_Cat, InsideOfTruck_Text_Edison, InsideOfTruck_Text_Frog, InsideOfTruck_Text_Starstrike, InsideOfTruck_Text_Tengu, InsideOfTruck_Text_DinoRabbit, InsideOfTruck_Text_WindUp, InsideOfTruck_Text_Miami, InsideOfTruck_Text_Meadowlands, InsideOfTruck_Text_BabyRuler, InsideOfTruck_Text_RavineRuler, InsideOfTruck_Text_FireWater, InsideOfTruck_Text_HAT, InsideOfTruck_Text_Vegas
	switch VAR_RESULT
	case 0, BattleFrontier_Mart_EventScript_Clerk_YugiKaiba
	case 1, BattleFrontier_Mart_EventScript_Clerk_Critter
	case 2, BattleFrontier_Mart_EventScript_Clerk_Treasure
	case 3, BattleFrontier_Mart_EventScript_Clerk_Imperial
	case 4, BattleFrontier_Mart_EventScript_Clerk_Android
	case 5, BattleFrontier_Mart_EventScript_Clerk_JoeyPegasus
	case 6, BattleFrontier_Mart_EventScript_Clerk_Fiber
	case 7, BattleFrontier_Mart_EventScript_Clerk_Yata
	case 8, BattleFrontier_Mart_EventScript_Clerk_Scientist
	case 9, BattleFrontier_Mart_EventScript_Clerk_Vampire
	case 10, BattleFrontier_Mart_EventScript_Clerk_Chaos
	case 11, BattleFrontier_Mart_EventScript_Clerk_Warrior
	case 12, BattleFrontier_Mart_EventScript_Clerk_Goat
	case 13, BattleFrontier_Mart_EventScript_Clerk_Cyber
	case 14, BattleFrontier_Mart_EventScript_Clerk_Reaper
	case 15, BattleFrontier_Mart_EventScript_Clerk_ChaosReturn
	case 16, BattleFrontier_Mart_EventScript_Clerk_Demise
	case 17, BattleFrontier_Mart_EventScript_Clerk_Trooper
	case 18, BattleFrontier_Mart_EventScript_Clerk_Zombie
	case 19, BattleFrontier_Mart_EventScript_Clerk_PerfectCircle
	case 20, BattleFrontier_Mart_EventScript_Clerk_DADReturn
	case 21, BattleFrontier_Mart_EventScript_Clerk_Gladiator
	case 22, BattleFrontier_Mart_EventScript_Clerk_TeleDAD
	case 23, BattleFrontier_Mart_EventScript_Clerk_Cat
	case 24, BattleFrontier_Mart_EventScript_Clerk_Edison
	case 25, BattleFrontier_Mart_EventScript_Clerk_Frog
	case 26, BattleFrontier_Mart_EventScript_Clerk_Starstrike
	case 27, BattleFrontier_Mart_EventScript_Clerk_Tengu
	case 28, BattleFrontier_Mart_EventScript_Clerk_DinoRabbit
	case 29, BattleFrontier_Mart_EventScript_Clerk_WindUp
	case 30, BattleFrontier_Mart_EventScript_Clerk_Miami
	case 31, BattleFrontier_Mart_EventScript_Clerk_Meadowlands
	case 32, BattleFrontier_Mart_EventScript_Clerk_BabyRuler
	case 33, BattleFrontier_Mart_EventScript_Clerk_RavineRuler
	case 34, BattleFrontier_Mart_EventScript_Clerk_FireWater
	case 35, BattleFrontier_Mart_EventScript_Clerk_HAT
	case 36, BattleFrontier_Mart_EventScript_Clerk_Vegas
	case MULTI_B_PRESSED, InsideOfTruck_EventScript_End

InsideOfTruck_EventScript_CardBanlists::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_DEFAULT
	dynmultichoice 0, 0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, InsideOfTruck_Text_YugiKaibaBanlist, InsideOfTruck_Text_CritterBanlist, InsideOfTruck_Text_TreasureBanlist, InsideOfTruck_Text_ImperialBanlist, InsideOfTruck_Text_AndroidBanlist, InsideOfTruck_Text_JoeyPegasusBanlist, InsideOfTruck_Text_FiberBanlist, InsideOfTruck_Text_YataBanlist, InsideOfTruck_Text_ScientistBanlist, InsideOfTruck_Text_VampireBanlist, InsideOfTruck_Text_ChaosBanlist, InsideOfTruck_Text_WarriorBanlist, InsideOfTruck_Text_GoatBanlist, InsideOfTruck_Text_CyberBanlist, InsideOfTruck_Text_ReaperBanlist, InsideOfTruck_Text_ChaosReturnBanlist, InsideOfTruck_Text_DemiseBanlist, InsideOfTruck_Text_TrooperBanlist, InsideOfTruck_Text_ZombieBanlist, InsideOfTruck_Text_PerfectCircleBanlist, InsideOfTruck_Text_DADReturnBanlist, InsideOfTruck_Text_GladiatorBanlist, InsideOfTruck_Text_TeleDADBanlist, InsideOfTruck_Text_CatBanlist, InsideOfTruck_Text_EdisonBanlist, InsideOfTruck_Text_FrogBanlist, InsideOfTruck_Text_StarstrikeBanlist, InsideOfTruck_Text_TenguBanlist, InsideOfTruck_Text_DinoRabbitBanlist, InsideOfTruck_Text_WindUpBanlist, InsideOfTruck_Text_MiamiBanlist, InsideOfTruck_Text_MeadowlandsBanlist, InsideOfTruck_Text_BabyRulerBanlist, InsideOfTruck_Text_RavineRulerBanlist, InsideOfTruck_Text_FireWaterBanlist, InsideOfTruck_Text_HATBanlist, InsideOfTruck_Text_VegasBanlist
	switch VAR_RESULT
	case 0, BattleFrontier_Mart_EventScript_Clerk_YugiKaibaBanlist
	case 1, BattleFrontier_Mart_EventScript_Clerk_CritterBanlist
	case 2, BattleFrontier_Mart_EventScript_Clerk_TreasureBanlist
	case 3, BattleFrontier_Mart_EventScript_Clerk_ImperialBanlist
	case 4, BattleFrontier_Mart_EventScript_Clerk_AndroidBanlist
	case 5, BattleFrontier_Mart_EventScript_Clerk_JoeyPegasusBanlist
	case 6, BattleFrontier_Mart_EventScript_Clerk_FiberBanlist
	case 7, BattleFrontier_Mart_EventScript_Clerk_YataBanlist
	case 8, BattleFrontier_Mart_EventScript_Clerk_ScientistBanlist
	case 9, BattleFrontier_Mart_EventScript_Clerk_VampireBanlist
	case 10, BattleFrontier_Mart_EventScript_Clerk_ChaosBanlist
	case 11, BattleFrontier_Mart_EventScript_Clerk_WarriorBanlist
	case 12, BattleFrontier_Mart_EventScript_Clerk_GoatBanlist
	case 13, BattleFrontier_Mart_EventScript_Clerk_CyberBanlist
	case 14, BattleFrontier_Mart_EventScript_Clerk_ReaperBanlist
	case 15, BattleFrontier_Mart_EventScript_Clerk_ChaosReturnBanlist
	case 16, BattleFrontier_Mart_EventScript_Clerk_DemiseBanlist
	case 17, BattleFrontier_Mart_EventScript_Clerk_TrooperBanlist
	case 18, BattleFrontier_Mart_EventScript_Clerk_ZombieBanlist
	case 19, BattleFrontier_Mart_EventScript_Clerk_PerfectCircleBanlist
	case 20, BattleFrontier_Mart_EventScript_Clerk_DADReturnBanlist
	case 21, BattleFrontier_Mart_EventScript_Clerk_GladiatorBanlist
	case 22, BattleFrontier_Mart_EventScript_Clerk_TeleDADBanlist
	case 23, BattleFrontier_Mart_EventScript_Clerk_CatBanlist
	case 24, BattleFrontier_Mart_EventScript_Clerk_EdisonBanlist
	case 25, BattleFrontier_Mart_EventScript_Clerk_FrogBanlist
	case 26, BattleFrontier_Mart_EventScript_Clerk_StarstrikeBanlist
	case 27, BattleFrontier_Mart_EventScript_Clerk_TenguBanlist
	case 28, BattleFrontier_Mart_EventScript_Clerk_DinoRabbitBanlist
	case 29, BattleFrontier_Mart_EventScript_Clerk_WindUpBanlist
	case 30, BattleFrontier_Mart_EventScript_Clerk_MiamiBanlist
	case 31, BattleFrontier_Mart_EventScript_Clerk_MeadowlandsBanlist
	case 32, BattleFrontier_Mart_EventScript_Clerk_BabyRulerBanlist
	case 33, BattleFrontier_Mart_EventScript_Clerk_RavineRulerBanlist
	case 34, BattleFrontier_Mart_EventScript_Clerk_FireWaterBanlist
	case 35, BattleFrontier_Mart_EventScript_Clerk_HATBanlist
	case 36, BattleFrontier_Mart_EventScript_Clerk_VegasBanlist
	case MULTI_B_PRESSED, InsideOfTruck_EventScript_End

InsideOfTruck_EventScript_End::
	releaseall
	end

InsideOfTruck_Text_CardShop:
	.string "Card shop$"
	
InsideOfTruck_Text_CardBanlists:
	.string "Card banlists$"

InsideOfTruck_Text_YugiKaibaBanlist:
	.string "Yugi-Kaiba banlist$"

InsideOfTruck_Text_CritterBanlist:
	.string "Critter banlist$"

InsideOfTruck_Text_TreasureBanlist:
	.string "Treasure banlist$"

InsideOfTruck_Text_ImperialBanlist:
	.string "Imperial banlist$"

InsideOfTruck_Text_AndroidBanlist:
	.string "Android banlist$"

InsideOfTruck_Text_JoeyPegasusBanlist:
	.string "Joey-Pegasus banlist$"

InsideOfTruck_Text_FiberBanlist:
	.string "Fiber banlist$"

InsideOfTruck_Text_YataBanlist:
	.string "Yata banlist$"

InsideOfTruck_Text_ScientistBanlist:
	.string "Scientist banlist$"

InsideOfTruck_Text_VampireBanlist:
	.string "Vampire banlist$"

InsideOfTruck_Text_ChaosBanlist:
	.string "Chaos banlist$"

InsideOfTruck_Text_WarriorBanlist:
	.string "Warrior banlist$"

InsideOfTruck_Text_GoatBanlist:
	.string "Goat banlist$"

InsideOfTruck_Text_CyberBanlist:
	.string "Cyber banlist$"

InsideOfTruck_Text_ReaperBanlist:
	.string "Reaper banlist$"

InsideOfTruck_Text_ChaosReturnBanlist:
	.string "Chaos Return banlist$"

InsideOfTruck_Text_DemiseBanlist:
	.string "Demise banlist$"

InsideOfTruck_Text_TrooperBanlist:
	.string "Trooper banlist$"

InsideOfTruck_Text_ZombieBanlist:
	.string "Zombie banlist$"

InsideOfTruck_Text_PerfectCircleBanlist:
	.string "Perfect Circle banlist$"

InsideOfTruck_Text_DADReturnBanlist:
	.string "DAD Return banlist$"

InsideOfTruck_Text_GladiatorBanlist:
	.string "Gladiator banlist$"

InsideOfTruck_Text_TeleDADBanlist:
	.string "TeleDAD banlist$"

InsideOfTruck_Text_CatBanlist:
	.string "Cat banlist$"

InsideOfTruck_Text_EdisonBanlist:
	.string "Edison banlist$"

InsideOfTruck_Text_FrogBanlist:
	.string "Frog banlist$"

InsideOfTruck_Text_StarstrikeBanlist:
	.string "Starstrike banlist$"

InsideOfTruck_Text_TenguBanlist:
	.string "Tengu banlist$"

InsideOfTruck_Text_DinoRabbitBanlist:
	.string "Dino Rabbit banlist$"

InsideOfTruck_Text_WindUpBanlist:
	.string "Wind-Up banlist$"

InsideOfTruck_Text_MiamiBanlist:
	.string "Miami banlist$"

InsideOfTruck_Text_MeadowlandsBanlist:
	.string "Meadowlands banlist$"

InsideOfTruck_Text_BabyRulerBanlist:
	.string "Baby Ruler banlist$"

InsideOfTruck_Text_RavineRulerBanlist:
	.string "Ravine Ruler banlist$"

InsideOfTruck_Text_FireWaterBanlist:
	.string "Fire-Water banlist$"

InsideOfTruck_Text_HATBanlist:
	.string "HAT banlist$"

InsideOfTruck_Text_VegasBanlist:
	.string "Vegas banlist$"

InsideOfTruck_Text_YugiKaiba:
	.string "Yugi-Kaiba$"

InsideOfTruck_Text_Critter:
	.string "Critter$"

InsideOfTruck_Text_Treasure:
	.string "Treasure$"

InsideOfTruck_Text_Imperial:
	.string "Imperial$"

InsideOfTruck_Text_Android:
	.string "Android$"

InsideOfTruck_Text_JoeyPegasus:
	.string "Joey-Pegasus$"

InsideOfTruck_Text_Fiber:
	.string "Fiber$"

InsideOfTruck_Text_Yata:
	.string "Yata$"

InsideOfTruck_Text_Scientist:
	.string "Scientist$"

InsideOfTruck_Text_Vampire:
	.string "Vampire$"

InsideOfTruck_Text_Chaos:
	.string "Chaos$"

InsideOfTruck_Text_Warrior:
	.string "Warrior$"

InsideOfTruck_Text_Goat:
	.string "Goat$"

InsideOfTruck_Text_Cyber:
	.string "Cyber$"

InsideOfTruck_Text_Reaper:
	.string "Reaper$"

InsideOfTruck_Text_ChaosReturn:
	.string "Chaos Return$"

InsideOfTruck_Text_Demise:
	.string "Demise$"

InsideOfTruck_Text_Trooper:
	.string "Trooper$"

InsideOfTruck_Text_Zombie:
	.string "Zombie$"

InsideOfTruck_Text_PerfectCircle:
	.string "Perfect Circle$"

InsideOfTruck_Text_DADReturn:
	.string "DAD Return$"

InsideOfTruck_Text_Gladiator:
	.string "Gladiator$"

InsideOfTruck_Text_TeleDAD:
	.string "TeleDAD$"

InsideOfTruck_Text_Cat:
	.string "Cat$"

InsideOfTruck_Text_Edison:
	.string "Edison$"

InsideOfTruck_Text_Frog:
	.string "Frog$"

InsideOfTruck_Text_Starstrike:
	.string "Starstrike$"

InsideOfTruck_Text_Tengu:
	.string "Tengu$"

InsideOfTruck_Text_DinoRabbit:
	.string "Dino Rabbit$"

InsideOfTruck_Text_WindUp:
	.string "Wind-Up$"

InsideOfTruck_Text_Miami:
	.string "Miami$"

InsideOfTruck_Text_Meadowlands:
	.string "Meadowlands$"

InsideOfTruck_Text_BabyRuler:
	.string "Baby Ruler$"

InsideOfTruck_Text_RavineRuler:
	.string "Ravine Ruler$"

InsideOfTruck_Text_FireWater:
	.string "Fire-Water$"

InsideOfTruck_Text_HAT:
	.string "HAT$"

InsideOfTruck_Text_Vegas:
	.string "Vegas$"

gText_YugiKaibaClerk::
	.string "Welcome!\p"
	.string "I'm the YugiKaiba clerk.\n"
	.string "How may I serve you?$"

gText_CritterClerk::
	.string "Welcome!\p"
	.string "I'm the Critter clerk.\n"
	.string "How may I serve you?$"

gText_TreasureClerk::
	.string "Welcome!\p"
	.string "I'm the Treasure clerk.\n"
	.string "How may I serve you?$"

gText_ImperialClerk::
	.string "Welcome!\p"
	.string "I'm the Imperial clerk.\n"
	.string "How may I serve you?$"

gText_AndroidClerk::
	.string "Welcome!\p"
	.string "I'm the Android clerk.\n"
	.string "How may I serve you?$"

gText_JoeyPegasusClerk::
	.string "Welcome!\p"
	.string "I'm the JoeyPegasus clerk.\n"
	.string "How may I serve you?$"

gText_FiberClerk::
	.string "Welcome!\p"
	.string "I'm the Fiber clerk.\n"
	.string "How may I serve you?$"

gText_YataClerk::
	.string "Welcome!\p"
	.string "I'm the Yata clerk.\n"
	.string "How may I serve you?$"

gText_ScientistClerk::
	.string "Welcome!\p"
	.string "I'm the Scientist clerk.\n"
	.string "How may I serve you?$"

gText_VampireClerk::
	.string "Welcome!\p"
	.string "I'm the Vampire clerk.\n"
	.string "How may I serve you?$"

gText_ChaosClerk::
	.string "Welcome!\p"
	.string "I'm the Chaos clerk.\n"
	.string "How may I serve you?$"

gText_WarriorClerk::
	.string "Welcome!\p"
	.string "I'm the Warrior clerk.\n"
	.string "How may I serve you?$"

gText_GoatClerk::
	.string "Welcome!\p"
	.string "I'm the Goat clerk.\n"
	.string "How may I serve you?$"

gText_CyberClerk::
	.string "Welcome!\p"
	.string "I'm the Cyber clerk.\n"
	.string "How may I serve you?$"

gText_ReaperClerk::
	.string "Welcome!\p"
	.string "I'm the Reaper clerk.\n"
	.string "How may I serve you?$"

gText_ChaosReturnClerk::
	.string "Welcome!\p"
	.string "I'm the ChaosReturn clerk.\n"
	.string "How may I serve you?$"

gText_DemiseClerk::
	.string "Welcome!\p"
	.string "I'm the Demise clerk.\n"
	.string "How may I serve you?$"

gText_TrooperClerk::
	.string "Welcome!\p"
	.string "I'm the Trooper clerk.\n"
	.string "How may I serve you?$"

gText_ZombieClerk::
	.string "Welcome!\p"
	.string "I'm the Zombie clerk.\n"
	.string "How may I serve you?$"

gText_PerfectCircleClerk::
	.string "Welcome!\p"
	.string "I'm the PerfectCircle clerk.\n"
	.string "How may I serve you?$"

gText_DADReturnClerk::
	.string "Welcome!\p"
	.string "I'm the DADReturn clerk.\n"
	.string "How may I serve you?$"

gText_GladiatorClerk::
	.string "Welcome!\p"
	.string "I'm the Gladiator clerk.\n"
	.string "How may I serve you?$"

gText_TeleDADClerk::
	.string "Welcome!\p"
	.string "I'm the TeleDAD clerk.\n"
	.string "How may I serve you?$"

gText_CatClerk::
	.string "Welcome!\p"
	.string "I'm the Cat clerk.\n"
	.string "How may I serve you?$"

gText_EdisonClerk::
	.string "Welcome!\p"
	.string "I'm the Edison clerk.\n"
	.string "How may I serve you?$"

gText_FrogClerk::
	.string "Welcome!\p"
	.string "I'm the Frog clerk.\n"
	.string "How may I serve you?$"

gText_StarstrikeClerk::
	.string "Welcome!\p"
	.string "I'm the Starstrike clerk.\n"
	.string "How may I serve you?$"

gText_TenguClerk::
	.string "Welcome!\p"
	.string "I'm the Tengu clerk.\n"
	.string "How may I serve you?$"

gText_DinoRabbitClerk::
	.string "Welcome!\p"
	.string "I'm the DinoRabbit clerk.\n"
	.string "How may I serve you?$"

gText_WindUpClerk::
	.string "Welcome!\p"
	.string "I'm the WindUp clerk.\n"
	.string "How may I serve you?$"

gText_MiamiClerk::
	.string "Welcome!\p"
	.string "I'm the Miami clerk.\n"
	.string "How may I serve you?$"

gText_MeadowlandsClerk::
	.string "Welcome!\p"
	.string "I'm the Meadowlands clerk.\n"
	.string "How may I serve you?$"

gText_BabyRulerClerk::
	.string "Welcome!\p"
	.string "I'm the BabyRuler clerk.\n"
	.string "How may I serve you?$"

gText_RavineRulerClerk::
	.string "Welcome!\p"
	.string "I'm the RavineRuler clerk.\n"
	.string "How may I serve you?$"

gText_FireWaterClerk::
	.string "Welcome!\p"
	.string "I'm the FireWater clerk.\n"
	.string "How may I serve you?$"

gText_HATClerk::
	.string "Welcome!\p"
	.string "I'm the HAT clerk.\n"
	.string "How may I serve you?$"

gText_VegasClerk::
	.string "Welcome!\p"
	.string "I'm the Vegas clerk.\n"
	.string "How may I serve you?$"

gText_YugiKaibaBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the YugiKaiba banlist clerk.\n"
	.string "How may I serve you?$"

gText_CritterBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Critter banlist clerk.\n"
	.string "How may I serve you?$"

gText_TreasureBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Treasure banlist clerk.\n"
	.string "How may I serve you?$"

gText_ImperialBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Imperial banlist clerk.\n"
	.string "How may I serve you?$"

gText_AndroidBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Android banlist clerk.\n"
	.string "How may I serve you?$"

gText_JoeyPegasusBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the JoeyPegasus banlist clerk.\n"
	.string "How may I serve you?$"

gText_FiberBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Fiber banlist clerk.\n"
	.string "How may I serve you?$"

gText_YataBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Yata banlist clerk.\n"
	.string "How may I serve you?$"

gText_ScientistBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Scientist banlist clerk.\n"
	.string "How may I serve you?$"

gText_VampireBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Vampire banlist clerk.\n"
	.string "How may I serve you?$"

gText_ChaosBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Chaos banlist clerk.\n"
	.string "How may I serve you?$"

gText_WarriorBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Warrior banlist clerk.\n"
	.string "How may I serve you?$"

gText_GoatBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Goat banlist clerk.\n"
	.string "How may I serve you?$"

gText_CyberBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Cyber banlist clerk.\n"
	.string "How may I serve you?$"

gText_ReaperBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Reaper banlist clerk.\n"
	.string "How may I serve you?$"

gText_ChaosReturnBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the ChaosReturn banlist clerk.\n"
	.string "How may I serve you?$"

gText_DemiseBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Demise banlist clerk.\n"
	.string "How may I serve you?$"

gText_TrooperBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Trooper banlist clerk.\n"
	.string "How may I serve you?$"

gText_ZombieBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Zombie banlist clerk.\n"
	.string "How may I serve you?$"

gText_PerfectCircleBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the PerfectCircle banlist clerk.\n"
	.string "How may I serve you?$"

gText_DADReturnBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the DADReturn banlist clerk.\n"
	.string "How may I serve you?$"

gText_GladiatorBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Gladiator banlist clerk.\n"
	.string "How may I serve you?$"

gText_TeleDADBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the TeleDAD banlist clerk.\n"
	.string "How may I serve you?$"

gText_CatBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Cat banlist clerk.\n"
	.string "How may I serve you?$"

gText_EdisonBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Edison banlist clerk.\n"
	.string "How may I serve you?$"

gText_FrogBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Frog banlist clerk.\n"
	.string "How may I serve you?$"

gText_StarstrikeBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Starstrike banlist clerk.\n"
	.string "How may I serve you?$"

gText_TenguBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Tengu banlist clerk.\n"
	.string "How may I serve you?$"

gText_DinoRabbitBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the DinoRabbit banlist clerk.\n"
	.string "How may I serve you?$"

gText_WindUpBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the WindUp banlist clerk.\n"
	.string "How may I serve you?$"

gText_MiamiBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Miami banlist clerk.\n"
	.string "How may I serve you?$"

gText_MeadowlandsBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Meadowlands banlist clerk.\n"
	.string "How may I serve you?$"

gText_BabyRulerBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the BabyRuler banlist clerk.\n"
	.string "How may I serve you?$"

gText_RavineRulerBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the RavineRuler banlist clerk.\n"
	.string "How may I serve you?$"

gText_FireWaterBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the FireWater banlist clerk.\n"
	.string "How may I serve you?$"

gText_HATBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the HAT banlist clerk.\n"
	.string "How may I serve you?$"

gText_VegasBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Vegas banlist clerk.\n"
	.string "How may I serve you?$"

BattleFrontier_Mart_EventScript_Clerk_YugiKaiba::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_YUGI_KAIBA
	message gText_YugiKaibaClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartYugiKaiba
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartYugiKaiba:
	.2byte  ITEM_AQUA_MADOOR
	.2byte  ITEM_BATTLE_OX
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CASTLE_WALLS
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DE_SPELL
	.2byte  ITEM_DIAN_KETO_THE_CURE_MASTER
	.2byte  ITEM_FINAL_FLAME
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GREAT_WHITE
	.2byte  ITEM_GYAKUTENNO_MEGAMI
	.2byte  ITEM_HANE_HANE
	.2byte  ITEM_JUDGE_MAN
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_ELF
	.2byte  ITEM_NEO_THE_MAGIC_SWORDSMAN
	.2byte  ITEM_OOKAZI
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_REINFORCEMENTS
	.2byte  ITEM_REMOVE_TRAP
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_OF_THE_HARP
	.2byte  ITEM_STOP_DEFENSE
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_WICKED_WORM_BEAST
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Critter::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CRITTER
	message gText_CritterClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCritter
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCritter:
	.2byte  ITEM_7_COLORED_FISH
	.2byte  ITEM_AQUA_MADOOR
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CRASS_CLOWN
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DE_SPELL
	.2byte  ITEM_DREAM_CLOWN
	.2byte  ITEM_EXODIA_THE_FORBIDDEN_ONE
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIGA_TECH_WOLF
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MUKA_MUKA
	.2byte  ITEM_POLYMERIZATION
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_REINFORCEMENTS
	.2byte  ITEM_REMOVE_TRAP
	.2byte  ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_ROBBIN_GOBLIN
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_STOP_DEFENSE
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Treasure::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_TREASURE
	message gText_TreasureClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTreasure
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTreasure:
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CRASS_CLOWN
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_POWER
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MECHANICALCHASER
	.2byte  ITEM_MINAR
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_ROBBIN_GOBLIN
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_CRETIN
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Imperial::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_IMPERIAL
	message gText_ImperialClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartImperial
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartImperial:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JINZO
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MECHANICALCHASER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Android::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_ANDROID
	message gText_AndroidClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartAndroid
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartAndroid:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AXE_OF_DESPAIR
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CASTLE_OF_DARK_ILLUSIONS
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EARTHBOUND_SPIRIT
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_PENGUIN_KNIGHT
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_JoeyPegasus::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_JOEY_PEGASUS
	message gText_JoeyPegasusClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartJoeyPegasus
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartJoeyPegasus:
	.2byte  ITEM_AXE_OF_DESPAIR
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_EXODIA_THE_FORBIDDEN_ONE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_PENGUIN_KNIGHT
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Fiber::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_FIBER
	message gText_FiberClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFiber
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFiber:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Yata::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_YATA
	message gText_YataClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartYata
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartYata:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DROP_OFF
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELECTRIC_SNAKE
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_ASSAILANT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPEAR_SOLDIER
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GUARDIAN_SPHINX
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Scientist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_SCIENTIST
	message gText_ScientistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartScientist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartScientist:
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_BLADE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_MAGICIAN
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GILASAURUS
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Vampire::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_VAMPIRE
	message gText_VampireClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartVampire
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartVampire:
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOOK_OF_TAIYOU
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MARAUDING_CAPTAIN
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SLATE_WARRIOR
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THE_LITTLE_SWORDSMAN_OF_AILE
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Chaos::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CHAOS
	message gText_ChaosClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartChaos
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartChaos:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOOK_OF_TAIYOU
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REFLECT_BOUNDER
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RELOAD
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROULETTE_BARREL
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_THUNDER_NYAN_NYAN
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Warrior::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_WARRIOR
	message gText_WarriorClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartWarrior
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartWarrior:
	.2byte  ITEM_A_LEGENDARY_OCEAN
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_BUSTER_BLADER
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GILASAURUS
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_PIKERU_S_CIRCLE_OF_ENCHANTMENT
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RELOAD
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SACRED_CRANE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SELF_DESTRUCT_BUTTON
	.2byte  ITEM_SERIAL_SPELL
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SKILLED_WHITE_MAGICIAN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPELL_REPRODUCTION
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_YOMI_SHIP
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Goat::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_GOAT
	message gText_GoatClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartGoat
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartGoat:
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BIG_BANG_SHOT
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_BYSER_SHOCK
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DESERT_SUNLIGHT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DROP_OFF
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_ORC
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GOLEM_SENTRY
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHT_OF_INTERVENTION
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MATAZA_THE_ZAPPER
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MILUS_RADIANT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROULETTE_BARREL
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SACRED_CRANE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TOON_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_TOON_TABLE_OF_CONTENTS
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Cyber::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CYBER
	message gText_CyberClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCyber
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCyber:
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_EMISSARY_OF_THE_AFTERLIFE
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXARION_UNIVERSE
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REFLECT_BOUNDER
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Reaper::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_REAPER
	message gText_ReaperClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartReaper
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartReaper:
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_MIMIC_LV1
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HAND_OF_NEPHTHYS
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MILUS_RADIANT
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SACRED_PHOENIX_OF_NEPHTHYS
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SASUKE_SAMURAI_4
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILPHEED
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SLATE_WARRIOR
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUAL_WIND_ART_MIYABI
	.2byte  ITEM_STEALTH_BIRD
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_BIG_MARCH_OF_ANIMALS
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_ULTIMATE_INSECT_LV3
	.2byte  ITEM_ULTIMATE_INSECT_LV5
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ChaosReturn::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CHAOS_RETURN
	message gText_ChaosReturnClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartChaosReturn
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartChaosReturn:
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CHIRON_THE_MAGE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Demise::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_DEMISE
	message gText_DemiseClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDemise
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDemise:
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHIRON_THE_MAGE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_TRAINER
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INABA_WHITE_RABBIT
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_INSECT_KNIGHT
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NEO_BUG
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_S_STEELCAGE
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SONIC_BIRD
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_STEALTH_BIRD
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Trooper::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_TROOPER
	message gText_TrooperClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTrooper
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTrooper:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THE_LIGHT_HEX_SEALED_FUSION
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Zombie::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_ZOMBIE
	message gText_ZombieClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartZombie
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartZombie:
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_INSECT_KNIGHT
	.2byte  ITEM_JINZO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIRAGE_DRAGON
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEO_BUG
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_S_STEELCAGE
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SASUKE_SAMURAI_4
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SONIC_BIRD
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LIGHT_HEX_SEALED_FUSION
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_PerfectCircle::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_PERFECT_CIRCLE
	message gText_PerfectCircleClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartPerfectCircle
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartPerfectCircle:
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOLEM_SENTRY
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_RISING_AIR_CURRENT
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_DADReturn::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_DAD_RETURN
	message gText_DADReturnClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDADReturn
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDADReturn:
	.2byte  ITEM_7_COLORED_FISH
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_MAGICAL_LIBRARY
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TOON_CANNON_SOLDIER
	.2byte  ITEM_TOON_TABLE_OF_CONTENTS
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Gladiator::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_GLADIATOR
	message gText_GladiatorClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartGladiator
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartGladiator:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JINZO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_XING_ZHEN_HU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_TeleDAD::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_TELEDAD
	message gText_TeleDADClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTeleDAD
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTeleDAD:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Cat::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CAT
	message gText_CatClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCat
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCat:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_DEAL
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_ORC
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_METAL_REFLECT_SLIME
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Edison::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_EDISON
	message gText_EdisonClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartEdison
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartEdison:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLIP_FLOP_FROG
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUAL_WATER_ART_AOI
	.2byte  ITEM_SUBSTITOAD
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Frog::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_FROG
	message gText_FrogClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFrog
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFrog:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLIP_FLOP_FROG
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUAL_WATER_ART_AOI
	.2byte  ITEM_SUBSTITOAD
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Starstrike::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_STARSTRIKE
	message gText_StarstrikeClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartStarstrike
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartStarstrike:
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_ASSAILANT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MASKED_DRAGON
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RED_EYES_WYVERN
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Tengu::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_TENGU
	message gText_TenguClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTengu
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTengu:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JINZO
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_DinoRabbit::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_DINO_RABBIT
	message gText_DinoRabbitClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDinoRabbit
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDinoRabbit:
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JINZO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_WindUp::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_WIND_UP
	message gText_WindUpClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartWindUp
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartWindUp:
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_CLAYMAN
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NINJA_GRANDMASTER_HANZO
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_REASONING
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_UPSTART_GOLDEN_NINJA
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Miami::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_MIAMI
	message gText_MiamiClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartMiami
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartMiami:
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_VORSE_RAIDER
	.2byte  ITEM_XING_ZHEN_HU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Meadowlands::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_MEADOWLANDS
	message gText_MeadowlandsClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartMeadowlands
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartMeadowlands:
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_BabyRuler::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_BABY_RULER
	message gText_BabyRulerClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartBabyRuler
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartBabyRuler:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RELOAD
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_RavineRuler::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_RAVINE_RULER
	message gText_RavineRulerClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartRavineRuler
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartRavineRuler:
	.2byte  ITEM_ARCHFIEND_HEIRESS
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_FireWater::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_FIRE_WATER
	message gText_FireWaterClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFireWater
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFireWater:
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SACRED_PHOENIX_OF_NEPHTHYS
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_HAT::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_HAT
	message gText_HATClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartHAT
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartHAT:
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_REASONING
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAPTRIX_DIONAEA
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_Vegas::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_VEGAS
	message gText_VegasClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartVegas
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartVegas:
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_ARCHFIEND_HEIRESS
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_HARPIE_LADY
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_THUNDER_SEA_HORSE
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_YugiKaibaBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_YUGI_KAIBA
	message gText_YugiKaibaBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartYugiKaibaBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartYugiKaibaBanlist:
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_AQUA_MADOOR
	.2byte  ITEM_BATTLE_OX
	.2byte  ITEM_CASTLE_WALLS
	.2byte  ITEM_DE_SPELL
	.2byte  ITEM_DIAN_KETO_THE_CURE_MASTER
	.2byte  ITEM_FINAL_FLAME
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GREAT_WHITE
	.2byte  ITEM_GYAKUTENNO_MEGAMI
	.2byte  ITEM_HANE_HANE
	.2byte  ITEM_JUDGE_MAN
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MYSTICAL_ELF
	.2byte  ITEM_NEO_THE_MAGIC_SWORDSMAN
	.2byte  ITEM_OOKAZI
	.2byte  ITEM_REINFORCEMENTS
	.2byte  ITEM_REMOVE_TRAP
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_OF_THE_HARP
	.2byte  ITEM_STOP_DEFENSE
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_THE_WICKED_WORM_BEAST
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_CritterBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_CRITTER
	message gText_CritterBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCritterBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCritterBanlist:
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_EXODIA_THE_FORBIDDEN_ONE
	.2byte  ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_7_COLORED_FISH
	.2byte  ITEM_AQUA_MADOOR
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CRASS_CLOWN
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DE_SPELL
	.2byte  ITEM_DREAM_CLOWN
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIGA_TECH_WOLF
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MUKA_MUKA
	.2byte  ITEM_POLYMERIZATION
	.2byte  ITEM_REINFORCEMENTS
	.2byte  ITEM_REMOVE_TRAP
	.2byte  ITEM_ROBBIN_GOBLIN
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_STOP_DEFENSE
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	.2byte  ITEM_WHITE_MAGICAL_HAT
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_TreasureBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_TREASURE
	message gText_TreasureBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTreasureBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTreasureBanlist:
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CRASS_CLOWN
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_POWER
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MECHANICALCHASER
	.2byte  ITEM_MINAR
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_ROBBIN_GOBLIN
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_CRETIN
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WALL_OF_ILLUSION
	.2byte  ITEM_WHITE_MAGICAL_HAT
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ImperialBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_IMPERIAL
	message gText_ImperialBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartImperialBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartImperialBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JINZO
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_SANGAN
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_SOLDIER_OF_STONE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MECHANICALCHASER
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_AndroidBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_ANDROID
	message gText_AndroidBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartAndroidBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartAndroidBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JINZO
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AXE_OF_DESPAIR
	.2byte  ITEM_BANISHER_OF_THE_LIGHT
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CASTLE_OF_DARK_ILLUSIONS
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EARTHBOUND_SPIRIT
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PENGUIN_KNIGHT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_JoeyPegasusBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_JOEY_PEGASUS
	message gText_JoeyPegasusBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartJoeyPegasusBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartJoeyPegasusBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXODIA_THE_FORBIDDEN_ONE
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_JINZO
	.2byte  ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_AXE_OF_DESPAIR
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MAN_EATER_BUG
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PENGUIN_KNIGHT
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_FiberBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_FIBER
	message gText_FiberBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFiberBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFiberBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRIBUTE_TO_THE_DOOMED
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_YataBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_YATA
	message gText_YataBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartYataBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartYataBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DROP_OFF
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELECTRIC_SNAKE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GEMINI_ELF
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_ASSAILANT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPEAR_SOLDIER
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GUARDIAN_SPHINX
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_PRINCESS_OF_TSURUGI
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOLEMN_WISHES
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WHITE_MAGICAL_HAT
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ScientistBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_SCIENTIST
	message gText_ScientistBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartScientistBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartScientistBanlist:
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_DARK_BLADE
	.2byte  ITEM_DARK_MAGICIAN
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GILASAURUS
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_VampireBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_VAMPIRE
	message gText_VampireBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartVampireBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartVampireBanlist:
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_MARAUDING_CAPTAIN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOOK_OF_TAIYOU
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SLATE_WARRIOR
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SUMMONED_SKULL
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THE_LITTLE_SWORDSMAN_OF_AILE
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ChaosBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_CHAOS
	message gText_ChaosBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartChaosBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartChaosBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CHAOS_EMPEROR_DRAGON_ENVOY_OF_THE_END
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HARPIE_S_FEATHER_DUSTER
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_IMPERIAL_ORDER
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RAIGEKI
	.2byte  ITEM_REFLECT_BOUNDER
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WITCH_OF_THE_BLACK_FOREST
	.2byte  ITEM_YATA_GARASU
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOOK_OF_TAIYOU
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RELOAD
	.2byte  ITEM_ROULETTE_BARREL
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_THUNDER_NYAN_NYAN
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_WarriorBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_WARRIOR
	message gText_WarriorBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartWarriorBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartWarriorBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHANGE_OF_HEART
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FIBER_JAR
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICAL_SCIENTIST
	.2byte  ITEM_MIRAGE_OF_NIGHTMARE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_PAINFUL_CHOICE
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THE_FORCEFUL_SENTRY
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_A_LEGENDARY_OCEAN
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLAST_WITH_CHAIN
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BUSTER_BLADER
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MAGICIAN
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_GEARFRIED_THE_IRON_KNIGHT
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GILASAURUS
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASKED_SORCERER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PIKERU_S_CIRCLE_OF_ENCHANTMENT
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RELOAD
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SACRED_CRANE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SELF_DESTRUCT_BUTTON
	.2byte  ITEM_SERIAL_SPELL
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SKILLED_WHITE_MAGICIAN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPELL_REPRODUCTION
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_FIEND_MEGACYBER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_YOMI_SHIP
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_GoatBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_GOAT
	message gText_GoatBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartGoatBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartGoatBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_AIRKNIGHT_PARSHATH
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BARREL_BEHIND_THE_DOOR
	.2byte  ITEM_BERSERK_GORILLA
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BIG_BANG_SHOT
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BYSER_SHOCK
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAIN_ENERGY
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DESERT_SUNLIGHT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DROP_OFF
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_ORC
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GOLEM_SENTRY
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JIRAI_GUMO
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LIGHT_OF_INTERVENTION
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MATAZA_THE_ZAPPER
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MILUS_RADIANT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROULETTE_BARREL
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SACRED_CRANE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPEAR_DRAGON
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TIME_SEAL
	.2byte  ITEM_TOON_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_TOON_TABLE_OF_CONTENTS
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_MASTER
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_CyberBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_CYBER
	message gText_CyberBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCyberBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCyberBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DELINQUENT_DUO
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_POT_OF_GREED
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_REFLECT_BOUNDER
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SINISTER_SERPENT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRIBE_INFECTING_VIRUS
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_ABYSS_SOLDIER
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLADE_KNIGHT
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_EMISSARY_OF_THE_AFTERLIFE
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXARION_UNIVERSE
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ReaperBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_REAPER
	message gText_ReaperBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartReaperBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartReaperBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CYBER_JAR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_SACRED_PHOENIX_OF_NEPHTHYS
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MIMIC_LV1
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_RULER_HA_DES
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_GERM
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GOBLIN_ATTACK_FORCE
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HAND_OF_NEPHTHYS
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MILUS_RADIANT
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_WHEEL
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SASUKE_SAMURAI
	.2byte  ITEM_SASUKE_SAMURAI_4
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILPHEED
	.2byte  ITEM_SKILLED_DARK_MAGICIAN
	.2byte  ITEM_SLATE_WARRIOR
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SPIRITUAL_WIND_ART_MIYABI
	.2byte  ITEM_STEALTH_BIRD
	.2byte  ITEM_THE_BIG_MARCH_OF_ANIMALS
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_ULTIMATE_INSECT_LV3
	.2byte  ITEM_ULTIMATE_INSECT_LV5
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ChaosReturnBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_CHAOS_RETURN
	message gText_ChaosReturnBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartChaosReturnBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartChaosReturnBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GRACEFUL_CHARITY
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_LAST_WILL
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_THOUSAND_EYES_RESTRICT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ARCHFIEND_SOLDIER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CHIRON_THE_MAGE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_CYBER_STEIN
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SHINING_ANGEL
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_DemiseBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_DEMISE
	message gText_DemiseBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDemiseBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDemiseBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JINZO
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_TWIN_HEADED_BEHEMOTH
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BLACK_ILLUSION_RITUAL
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHIRON_THE_MAGE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_TRAINER
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INABA_WHITE_RABBIT
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_INSECT_KNIGHT
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NEO_BUG
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_S_STEELCAGE
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RELINQUISHED
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKULL_LAIR
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SONIC_BIRD
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_STEALTH_BIRD
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_TrooperBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_TROOPER
	message gText_TrooperBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTrooperBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTrooperBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CONFISCATION
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_JINZO
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RING_OF_DESTRUCTION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SNATCH_STEAL
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_METAMORPHOSIS
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DARK_WORLD_LIGHTNING
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THE_LIGHT_HEX_SEALED_FUSION
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TWIN_HEADED_THUNDER_DRAGON
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_ZombieBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_ZOMBIE
	message gText_ZombieBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartZombieBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartZombieBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_WALL_OF_REVEALING_LIGHT
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_JINZO
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_ASURA_PRIEST
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLOWBACK_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_WOMBAT
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOM_DOZER
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_INSECT_KNIGHT
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KURIBOH
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGICAL_MERCHANT
	.2byte  ITEM_MANJU_OF_THE_TEN_THOUSAND_HANDS
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIRAGE_DRAGON
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEO_BUG
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIGHTMARE_S_STEELCAGE
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RUSH_RECKLESSLY
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SASUKE_SAMURAI_4
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SENJU_OF_THE_THOUSAND_HANDS
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SONIC_BIRD
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_THE_LIGHT_HEX_SEALED_FUSION
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREMENDOUS_FIRE
	.2byte  ITEM_VAMPIRE_LORD
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_WIDESPREAD_RUIN
	.2byte  ITEM_XING_ZHEN_HU
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_PerfectCircleBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_PERFECT_CIRCLE
	message gText_PerfectCircleBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartPerfectCircleBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartPerfectCircleBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MAGICIAN_OF_FAITH
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_JINZO
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_4_STARRED_LADYBUG_OF_DOOM
	.2byte  ITEM_AMAZONESS_ARCHER
	.2byte  ITEM_BAZOO_THE_SOUL_EATER
	.2byte  ITEM_BICKURIBOX
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_PALADIN
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ELEMENTAL_HERO_WILDHEART
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FLYING_KAMAKIRI_1
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GOLEM_SENTRY
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_GYAKU_GIRE_PANDA
	.2byte  ITEM_HYDROGEDDON
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LABYRINTH_TANK
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEWDORIA
	.2byte  ITEM_NIMBLE_MOMONGA
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_RISING_AIR_CURRENT
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_DADReturnBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_DAD_RETURN
	message gText_DADReturnBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDADReturnBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDADReturnBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_DIMENSION_FUSION
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_GRAVITY_BIND
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_7_COLORED_FISH
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BIG_SHIELD_GARDNA
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DON_ZALOOG
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DRILLROID
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HALLOWED_LIFE_BARRIER
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_DRAGUN
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_GATE
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_REASONING
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_ROYAL_MAGICAL_LIBRARY
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_RYU_KOKKI
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_THUNDER_DRAGON
	.2byte  ITEM_TOON_CANNON_SOLDIER
	.2byte  ITEM_TOON_TABLE_OF_CONTENTS
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_WAVE_MOTION_CANNON
	.2byte  ITEM_ZABORG_THE_THUNDER_MONARCH
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_GladiatorBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_GLADIATOR
	message gText_GladiatorBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartGladiatorBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartGladiatorBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_MAGICIAN_OF_CHAOS
	.2byte  ITEM_FISSURE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PREMATURE_BURIAL
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_MASK_OF_DARKNESS
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_DARK_BLADE_THE_DRAGON_KNIGHT
	.2byte  ITEM_DARK_SCORPION_CLIFF_THE_TRAP_REMOVER
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXILED_FORCE
	.2byte  ITEM_FLAME_SWORDSMAN
	.2byte  ITEM_GAIA_THE_DRAGON_CHAMPION
	.2byte  ITEM_GATLING_DRAGON
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_JINZO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTIC_SWORDSMAN_LV2
	.2byte  ITEM_NINJA_GRANDMASTER_SASUKE
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	.2byte  ITEM_XING_ZHEN_HU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_TeleDADBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_TELEDAD
	message gText_TeleDADBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTeleDADBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTeleDADBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_UNITED_WE_STAND
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CIPHER_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_CatBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_CAT
	message gText_CatBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartCatBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartCatBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_CRUSH_CARD_VIRUS
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CANNON_SOLDIER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_DEAL
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DEKOICHI_THE_BATTLECHANTED_LOCOMOTIVE
	.2byte  ITEM_DES_KOALA
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_GIANT_ORC
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGIC_JAMMER
	.2byte  ITEM_METAL_REFLECT_SLIME
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTIC_TOMATO
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_WABOKU
	.2byte  ITEM_ZOMBYRA_THE_DARK
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_EdisonBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_EDISON
	message gText_EdisonBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartEdisonBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartEdisonBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MEGAMORPH
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_D_D_ASSAILANT
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DARK_ELF
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLIP_FLOP_FROG
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JINZO
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_REAPER_ON_THE_NIGHTMARE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRITUAL_WATER_ART_AOI
	.2byte  ITEM_SUBSTITOAD
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_FrogBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_FROG
	message gText_FrogBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFrogBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFrogBanlist:
	.2byte  ITEM_BRAIN_CONTROL
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RESCUE_CAT
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLUE_EYES_ULTIMATE_DRAGON
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_TWIN_DRAGON
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_FLIP_FLOP_FROG
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_INJECTION_FAIRY_LILY
	.2byte  ITEM_JINZO
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MOTHER_GRIZZLY
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRITUAL_WATER_ART_AOI
	.2byte  ITEM_SUBSTITOAD
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_StarstrikeBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_STARSTRIKE
	message gText_StarstrikeBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartStarstrikeBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartStarstrikeBanlist:
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_COLD_WAVE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_GIANT_TRUNADE
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_ROYAL_OPPRESSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_D_D_WARRIOR_LADY
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUPE_FROG
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FISSURE
	.2byte  ITEM_GRAVEKEEPER_S_ASSAILANT
	.2byte  ITEM_GRAVEKEEPER_S_GUARD
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_LEGENDARY_JUJITSU_MASTER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MASK_OF_RESTRICT
	.2byte  ITEM_MASKED_DRAGON
	.2byte  ITEM_MOBIUS_THE_FROST_MONARCH
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_NOBLEMAN_OF_EXTERMINATION
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RED_EYES_WYVERN
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_THESTALOS_THE_FIRESTORM_MONARCH
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_TenguBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_TENGU
	message gText_TenguBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartTenguBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartTenguBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TRAP_DUSTSHOOT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BOOK_OF_LIFE
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DARK_MIMIC_LV3
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_GRAVEKEEPER_S_SPY
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JINZO
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MONSTER_REINCARNATION
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_PYRAMID_TURTLE
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_DinoRabbitBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_DINO_RABBIT
	message gText_DinoRabbitBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartDinoRabbitBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartDinoRabbitBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CATAPULT_TURTLE
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_FAKE_TRAP
	.2byte  ITEM_JINZO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_RONINTOADIN
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SOUL_EXCHANGE
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_SWAP_FROG
	.2byte  ITEM_TREEBORN_FROG
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_WindUpBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_WIND_UP
	message gText_WindUpBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartWindUpBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartWindUpBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_MORPHING_JAR
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_REASONING
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_END_DRAGON
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ELEMENTAL_HERO_CLAYMAN
	.2byte  ITEM_GIANT_RAT
	.2byte  ITEM_GIGANTES
	.2byte  ITEM_GRAVEKEEPER_S_WATCHER
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NECROVALLEY
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NINJA_GRANDMASTER_HANZO
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PROTECTOR_OF_THE_SANCTUARY
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_UPSTART_GOLDEN_NINJA
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_MiamiBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_MIAMI
	message gText_MiamiBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartMiamiBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartMiamiBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SANGAN
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_REASONING
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CREATURE_SWAP
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_EMERGENCY_PROVISIONS
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_KING_TIGER_WANGHU
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LEVEL_LIMIT_AREA_B
	.2byte  ITEM_MESSENGER_OF_PEACE
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NEKO_MANE_KING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SILLVA_WARLORD_OF_DARK_WORLD
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_SPIRIT_REAPER
	.2byte  ITEM_THREATENING_ROAR
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_VORSE_RAIDER
	.2byte  ITEM_XING_ZHEN_HU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_MeadowlandsBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_MEADOWLANDS
	message gText_MeadowlandsBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartMeadowlandsBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartMeadowlandsBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LIMITER_REMOVAL
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_NIGHT_ASSAILANT
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_D_D_SURVIVOR
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_SHRINK
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SPIRITUALISM
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_BabyRulerBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_BABY_RULER
	message gText_BabyRulerBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartBabyRulerBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartBabyRulerBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_CARD_DESTRUCTION
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_HEAVY_STORM
	.2byte  ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_MONSTER_REBORN
	.2byte  ITEM_POT_OF_AVARICE
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_SOLEMN_JUDGMENT
	.2byte  ITEM_ULTIMATE_OFFERING
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_TSUKUYOMI
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_BLACK_SKULL_DRAGON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_ELEMENTAL_HERO_FLAME_WINGMAN
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_EXCHANGE
	.2byte  ITEM_FUSILIER_DRAGON_THE_DUAL_MODE_BEAST
	.2byte  ITEM_HORN_OF_HEAVEN
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_LIGHTNING_VORTEX
	.2byte  ITEM_MAGE_POWER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_OJAMA_KING
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RELOAD
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SAKURETSU_ARMOR
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SPELL_CANCELLER
	.2byte  ITEM_SWORDS_OF_REVEALING_LIGHT
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_THE_LAST_WARRIOR_FROM_ANOTHER_PLANET
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_RavineRulerBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_RAVINE_RULER
	message gText_RavineRulerBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartRavineRulerBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartRavineRulerBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_CEASEFIRE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_RETURN_FROM_THE_DIFFERENT_DIMENSION
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_OJAMA_TRIO
	.2byte  ITEM_ARCHFIEND_HEIRESS
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BREAKER_THE_MAGICAL_WARRIOR
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CHAIN_DISAPPEARANCE
	.2byte  ITEM_CURSED_SEAL_OF_THE_FORBIDDEN_SPELL
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_ENEMY_CONTROLLER
	.2byte  ITEM_JOWGEN_THE_SPIRITUALIST
	.2byte  ITEM_JUST_DESSERTS
	.2byte  ITEM_KARMA_CUT
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MAGIC_CYLINDER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_MYSTIK_WOK
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_POISON_OF_THE_OLD_MAN
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SCAPEGOAT
	.2byte  ITEM_SECRET_BARREL
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SMASHING_GROUND
	.2byte  ITEM_TERRAFORMING
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_UPSTART_GOBLIN
	.2byte  ITEM_WABOKU
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_FireWaterBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_FIRE_WATER
	message gText_FireWaterBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartFireWaterBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartFireWaterBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_BEIIGE_VANGUARD_OF_DARK_WORLD
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_BROWW_HUNTSMAN_OF_DARK_WORLD
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_DECK_DEVASTATION_VIRUS
	.2byte  ITEM_DRAGGED_DOWN_INTO_THE_GRAVE
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_ROYAL_DECREE
	.2byte  ITEM_SACRED_PHOENIX_OF_NEPHTHYS
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_SNOWW_UNLIGHT_OF_DARK_WORLD
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_HATBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_HAT
	message gText_HATBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartHATBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartHATBanlist:
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_REASONING
	.2byte  ITEM_BLUE_EYES_WHITE_DRAGON
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SKILL_DRAIN
	.2byte  ITEM_TRAPTRIX_DIONAEA
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend

BattleFrontier_Mart_EventScript_Clerk_VegasBanlist::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, BANLIST_VEGAS
	message gText_VegasBanlistClerk
	waitmessage
	pokemart BattleFrontier_Mart_PokemartVegasBanlist
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_PokemartVegasBanlist:
	.2byte  ITEM_BLACK_LUSTER_SOLDIER_ENVOY_OF_THE_BEGINNING
	.2byte  ITEM_BOOK_OF_MOON
	.2byte  ITEM_BOTTOMLESS_TRAP_HOLE
	.2byte  ITEM_COMPULSORY_EVACUATION_DEVICE
	.2byte  ITEM_DARK_HOLE
	.2byte  ITEM_MIND_CONTROL
	.2byte  ITEM_REINFORCEMENT_OF_THE_ARMY
	.2byte  ITEM_TORRENTIAL_TRIBUTE
	.2byte  ITEM_CHAOS_SORCERER
	.2byte  ITEM_MIRROR_FORCE
	.2byte  ITEM_ANTI_SPELL_FRAGRANCE
	.2byte  ITEM_AQUA_SPIRIT
	.2byte  ITEM_ARCHFIEND_HEIRESS
	.2byte  ITEM_CALL_OF_THE_HAUNTED
	.2byte  ITEM_CYBER_DRAGON
	.2byte  ITEM_CYBER_HARPIE_LADY
	.2byte  ITEM_DOOMCALIBER_KNIGHT
	.2byte  ITEM_DUST_TORNADO
	.2byte  ITEM_JAR_OF_GREED
	.2byte  ITEM_KYCOO_THE_GHOST_DESTROYER
	.2byte  ITEM_MYSTICAL_SPACE_TYPHOON
	.2byte  ITEM_NEEDLE_CEILING
	.2byte  ITEM_NOBLEMAN_OF_CROSSOUT
	.2byte  ITEM_OFFERINGS_TO_THE_DOOMED
	.2byte  ITEM_PHOENIX_WING_WIND_BLAST
	.2byte  ITEM_RAIGEKI_BREAK
	.2byte  ITEM_RECKLESS_GREED
	.2byte  ITEM_SALVAGE
	.2byte  ITEM_SEVEN_TOOLS_OF_THE_BANDIT
	.2byte  ITEM_THUNDER_SEA_HORSE
	.2byte  ITEM_TRAP_HOLE
	.2byte  ITEM_TRAPTRIX_MYRMELEO
	.2byte  ITEM_UPSTART_GOBLIN
	pokemartlistend


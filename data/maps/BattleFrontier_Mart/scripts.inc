BattleFrontier_Mart_MapScripts::
	.byte 0

gText_YugiKaibaBanlistClerk::
	.string "Welcome!\p"
	.string "I'm the Yugi-Kaiba banlist clerk.\n"
	.string "How may I serve you?$"

gText_YugiKaibaClerk::
	.string "Welcome!\p"
	.string "I'm the Yugi-Kaiba clerk.\n"
	.string "How may I serve you?$"

gText_CritterClerk::
	.string "Welcome!\p"
	.string "I'm the Critter clerk.\n"
	.string "How may I serve you?$"
	
gText_TreasureClerk::
	.string "Welcome!\p"
	.string "I'm the Treasure clerk.\n"
	.string "How may I serve you?$"

BattleFrontier_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

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

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

BattleFrontier_Mart_EventScript_OldMan::
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
	end

BattleFrontier_Mart_EventScript_OldWoman::
	lock
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
	waitmovement 0
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Boy::
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
	end

BattleFrontier_Mart_Text_ChaperonGrandson:
	.string "We came here to chaperon our\n"
	.string "grandson.\p"
	.string "But since we're here, we thought\n"
	.string "we should get some souvenirs.$"

BattleFrontier_Mart_Text_ProteinMakeNiceGift:
	.string "Dear, what do you think of this?\n"
	.string "Wouldn't this make a nice gift?\p"
	.string "It's…PRO…TE…IN?\n"
	.string "It sounds delicious, doesn't it?$"

BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
	.string "A lot of the BATTLE FRONTIER's\n"
	.string "facilities don't allow the use of items\l"
	.string "during battles.\p"
	.string "That rule makes things tougher than\n"
	.string "they already are!$"


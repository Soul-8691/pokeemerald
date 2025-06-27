BattleFrontier_Mart_MapScripts::
	.byte 0

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

BattleFrontier_Mart_EventScript_Clerk_YugiKaiba::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_YUGI_KAIBA
	message gText_YugiKaibaClerk
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Clerk_Critter::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_CRITTER
	message gText_CritterClerk
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Mart_EventScript_Clerk_Treasure::
	lock
	faceplayer
	setvar VAR_YGO_SHOP, FORMAT_TREASURE
	message gText_TreasureClerk
	waitmessage
	pokemart BattleFrontier_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_Mart_Pokemart:
	.2byte ITEM_LA_JINN_THE_MYSTICAL_GENIE_OF_THE_LAMP
	.2byte ITEM_GIANT_SOLDIER_OF_STONE
	.2byte ITEM_TRAP_HOLE
	.2byte ITEM_SANGAN
	.2byte ITEM_CONFISCATION
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


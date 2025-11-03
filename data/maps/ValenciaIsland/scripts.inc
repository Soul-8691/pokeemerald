ValenciaIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ValenciaIsland_OnTransition
	.byte 0

ValenciaIsland_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end

ValenciaIsland_Text_TownSign:
	.string "VALENCIA ISLAND$"

ValenciaIsland_EventScript_TownSign::
	msgbox ValenciaIsland_Text_TownSign, MSGBOX_SIGN
	end

ValenciaIsland_Text_ParkSign:
	.string "{RIGHT_ARROW} VALENCIA PARK$"

ValenciaIsland_EventScript_ParkSign::
	msgbox ValenciaIsland_Text_ParkSign, MSGBOX_SIGN
	end

ValenciaIsland_Text_TrainerTipsSign:
	.string "TRAINER TIPS\p"
	.string "Catch POKéMON and expand your\n"
	.string "collection.\p"
	.string "The more you have, the easier it\n"
	.string "is to battle.$"

ValenciaIsland_EventScript_TrainerTipsSign::
	msgbox ValenciaIsland_Text_TrainerTipsSign, MSGBOX_SIGN
	end

ValenciaIsland_EventScript_Wingull1::
	lock
	faceplayer
	setwildbattle SPECIES_WINGULL, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_WINGULL_ANGRY
	callnative DrawMugshot
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
	msgbox ValenciaIsland_Text_Wingull, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaIsland_EventScript_DefeatedWingull1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaIsland_EventScript_DefeatedWingull1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaIsland_EventScript_DefeatedWingull1
	setflag FLAG_VALENCIA_ISLAND_WINGULL_1
	release
	end

ValenciaIsland_EventScript_DefeatedWingull1::
	setflag FLAG_VALENCIA_ISLAND_WINGULL_1
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaIsland_EventScript_Wingull2::
	lock
	faceplayer
	setwildbattle SPECIES_WINGULL, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_WINGULL_ANGRY
	callnative DrawMugshot
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
	msgbox ValenciaIsland_Text_Wingull, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaIsland_EventScript_DefeatedWingull2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaIsland_EventScript_DefeatedWingull2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaIsland_EventScript_DefeatedWingull2
	setflag FLAG_VALENCIA_ISLAND_WINGULL_2
	release
	end

ValenciaIsland_EventScript_DefeatedWingull2::
	setflag FLAG_VALENCIA_ISLAND_WINGULL_2
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaIsland_EventScript_Wingull3::
	lock
	faceplayer
	setwildbattle SPECIES_WINGULL, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_WINGULL_ANGRY
	callnative DrawMugshot
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
	msgbox ValenciaIsland_Text_Wingull, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaIsland_EventScript_DefeatedWingull3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaIsland_EventScript_DefeatedWingull3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaIsland_EventScript_DefeatedWingull3
	setflag FLAG_VALENCIA_ISLAND_WINGULL_3
	release
	end

ValenciaIsland_EventScript_DefeatedWingull3::
	setflag FLAG_VALENCIA_ISLAND_WINGULL_3
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaIsland_Text_Wingull:
	.string "GULL!$"

ValenciaIsland_EventScript_Fisherman::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, ValenciaIsland_EventScript_Fisherman2
	msgbox ValenciaIsland_Text_Fisherman, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD 1
	msgbox ValenciaIsland_Text_Fisherman2, MSGBOX_DEFAULT
	release
	end

ValenciaIsland_Text_Fisherman:
	.string "Well hello there,\n"
	.string "...\p"
	.string "What I'm doing at the moment?\p"
	.string "I'm trying to catch POKéMON by\n"
	.string "using a fishing rod.\p"
	.string "Some water POKéMON live deeper\n"
	.string "below the surface of the water.\p"
	.string "In that case you will need a rod\n"
	.string "to get them to the surface.\p"
	.string "You know what, I'm in a generous\n"
	.string "mood.\p"
	.string "You can have one of my older rods\n"
	.string "to try fishing yourself.$"

ValenciaIsland_Text_Fisherman2:
	.string "You can use that rod at any\n"
	.string "type of water.\p"
	.string "Try using it at many different\n"
	.string "locations.$"

ValenciaIsland_EventScript_Fisherman2::
	msgbox ValenciaIsland_Text_Fisherman3, MSGBOX_DEFAULT
	release
	end

ValenciaIsland_Text_Fisherman3:
	.string "How are the fish biting?$"

ValenciaIsland_EventScript_LabTriggerRight::
	lockall
	msgbox ValenciaIsland_Text_Lab, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ValenciaIsland_Movement_StepLeft
	waitmovement 0
	releaseall
	end

ValenciaIsland_EventScript_LabTriggerDown::
	lockall
	msgbox ValenciaIsland_Text_Lab, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ValenciaIsland_Movement_StepUp
	waitmovement 0
	releaseall
	end

ValenciaIsland_EventScript_LabTriggerLeft::
	lockall
	msgbox ValenciaIsland_Text_Lab, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ValenciaIsland_Movement_StepRight
	waitmovement 0
	releaseall
	end

ValenciaIsland_Text_Lab:
	.string "I should go see Professor Ivy in her\n"
	.string "lab.$"

ValenciaIsland_Movement_StepRight:
	walk_right
	step_end

ValenciaIsland_Movement_StepLeft:
	walk_left
	step_end

ValenciaIsland_Movement_StepUp:
	walk_up
	step_end

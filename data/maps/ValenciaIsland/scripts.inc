ValenciaIsland_MapScripts::
	.byte 0

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

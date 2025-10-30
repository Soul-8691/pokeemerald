ValenciaIsland_MapScripts::
	.byte 0

ValenciaIsland_Text_Fisherman:
	.string "Something something here's an OLD\n"
	.string "ROD.$"

ValenciaIsland_Text_Fisherman2:
	.string "Something something enjoy.$"

ValenciaIsland_EventScript_Fisherman::
	lock
	faceplayer
	msgbox ValenciaIsland_Text_Fisherman, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	msgbox ValenciaIsland_Text_Fisherman2, MSGBOX_DEFAULT
	release
	end

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

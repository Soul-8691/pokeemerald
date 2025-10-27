ValenciaIsland_MapScripts::
	.byte 0

ValenciaIsland_EventScript_Debug::
	givemon SPECIES_TENTACOOL, 5
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE07_GET
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

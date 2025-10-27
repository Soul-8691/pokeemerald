ValenciaIsland_ProfessorIvysLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ValenciaIsland_ProfessorIvysLab_OnFrame
	.byte 0

ValenciaIsland_ProfessorIvysLab_OnFrame:
	map_script_2 VAR_PROFESSOR_IVY, 0, ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvy
	.2byte 0

ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvyAide::
	lock
	faceplayer
	msgbox ValenciaIsland_ProfessorIvysLab_Text_Aide, MSGBOX_DEFAULT
	release
	end

ValenciaIsland_ProfessorIvysLab_Text_Aide:
	.string "We are currently conducting lab tests,\n"
	.string "coming up with chemical compounds to\p"
	.string "enable POKéMON that evolve by trade to\n"
	.string "evolve without being traded.$"

ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvy::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ValenciaIsland_ProfessorIvysLab_Movement_WalkToProfIvy
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy, MSGBOX_DEFAULT
	giveitem ITEM_SURF_TOOL
	giveitem ITEM_FLY_TOOL
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy2, MSGBOX_DEFAULT
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy3, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 10
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy4, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	warpsilent MAP_SHAMOUTI_ISLAND, 255, 30, 39
	waitstate
	releaseall
	end

ValenciaIsland_ProfessorIvysLab_Movement_WalkToProfIvy:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy:
	.string "PROF. IVY: {PLAYER}{KUN}! Welcome back!\p"
	.string "I hope you're ready for your first\n"
	.string "task!\p"
	.string "Before you begin, I want you to have\n"
	.string "these.$"

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy2:
	.string "They are the Lapras Paddle and the\n"
	.string "Pidgeot Courier. To get around, you'll\p"
	.string "need items like these to Surf and to\n"
	.string "avoid backtracking.$"

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy3:
	.string "Also, here are some Poké Balls.$"

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy4:
	.string "My missions always involve the\n"
	.string "capture of POKéMON species native\p"
	.string "to the Orange Islands. I'm too busy\n"
	.string "with my lab work to go out in the\p"
	.string "field most of the time.\p"
	.string "Every time you bring the species back\n"
	.string "to me, I will give you a reward, rest\p"
	.string "assured; whether it be an item or Poké-\n"
	.string "Dollars.\p"
	.string "Be careful out there. Let me tell you\n"
	.string "a story.$"

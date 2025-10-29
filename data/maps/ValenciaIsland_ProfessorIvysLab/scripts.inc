ValenciaIsland_ProfessorIvysLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ValenciaIsland_ProfessorIvysLab_OnFrame
	.byte 0

ValenciaIsland_ProfessorIvysLab_OnFrame:
	map_script_2 VAR_PROFESSOR_IVY, 0, ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvy
	map_script_2 VAR_PROFESSOR_IVY, 1, ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvy2
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

ValenciaIsland_ProfessorIvysLab_EventScript_ProfIvy2::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy5, MSGBOX_DEFAULT
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST QUEST_1
	startquest QUEST_1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox ValenciaIsland_ProfessorIvysLab_Text_Quest1Unlocked, MSGBOX_SIGN
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ValenciaIsland_ProfessorIvysLab_Text_ProfIvy6, MSGBOX_DEFAULT
	setvar VAR_PROFESSOR_IVY, 2
	releaseall
	end

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

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy5:
	.string "Giovanni is waiting in his offshore\n"
	.string "base for somebody to challenge him.\p"
	.string "Who can challenge his might, besides\n"
	.string "Drake, Champion of the Orange Islands?\p"
	.string "Nobody can enter or leave the Orange\n"
	.string "Islands until this situation is taken\p"
	.string "care of.\p"
	.string "But enough with that, you've got work\n"
	.string "to do!\p"
	.string "Your first task is to capture a Slakoth\n"
	.string "for me. They are found in Valencia Park.\p"
	.string "Once you've captured the POKéMON, you\n"
	.string "will not be able to progress to an\p"
	.string "unvisited map until you bring me back\n"
	.string "the POKéMON for reward!\p"
	.string "Here is a Quest Log.$"

ValenciaIsland_ProfessorIvysLab_Text_Quest1Unlocked:
	.string "LAZY LOAFER unlocked.$"

ValenciaIsland_ProfessorIvysLab_Text_ProfIvy6:
	.string "Good luck out there! Feel free to\n"
	.string "Surf out to Route E and battle some\p"
	.string "trainers, but I will guilt trip you\n"
	.string "into returning to my employment if\p"
	.string "you go too far!$"

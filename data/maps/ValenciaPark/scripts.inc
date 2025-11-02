ValenciaPark_MapScripts::
	.byte 0

ValenciaPark_Text_TrainerTipsSign:
	.string "TRAINER TIPS\p"
	.string "Shiny POKéMON are rarer than\n"
	.string "regular POKéMON.\p"
	.string "It's a misconception they are\n"
	.string "generally stronger.$"

ValenciaPark_EventScript_TrainerTipsSign::
	msgbox ValenciaPark_Text_TrainerTipsSign, MSGBOX_SIGN
	end

ValenciaPark_Text_TrainerTipsSign2:
	.string "TRAINER TIPS\p"
	.string "You can't catch a POKéMON that\n"
	.string "belongs to someone else.\p"
	.string "Throw POKé BALLS only at wild\n"
	.string "POKéMON to catch them!$"

ValenciaPark_EventScript_TrainerTipsSign2::
	msgbox ValenciaPark_Text_TrainerTipsSign2, MSGBOX_SIGN
	end

ValenciaIsland_EventScript_Beautifly::
	lock
	faceplayer
	setwildbattle SPECIES_BEAUTIFLY, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_BEAUTIFLY_NORMAL
	callnative DrawMugshot
	playmoncry SPECIES_BEAUTIFLY, CRY_MODE_ENCOUNTER
	msgbox ValenciaIsland_Text_Beautifly, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaIsland_EventScript_DefeatedBeautifly
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaIsland_EventScript_DefeatedBeautifly
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaIsland_EventScript_DefeatedBeautifly
	setflag FLAG_VALENCIA_PARK_BEAUTIFLY
	release
	end

ValenciaIsland_EventScript_DefeatedBeautifly::
	setflag FLAG_VALENCIA_PARK_BEAUTIFLY
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaIsland_Text_Beautifly:
	.string "BEAUT!$"

ValenciaIsland_EventScript_Dustox::
	lock
	faceplayer
	setwildbattle SPECIES_DUSTOX, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_DUSTOX_NORMAL
	callnative DrawMugshot
	playmoncry SPECIES_DUSTOX, CRY_MODE_ENCOUNTER
	msgbox ValenciaIsland_Text_Dustox, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaIsland_EventScript_DefeatedDustox
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaIsland_EventScript_DefeatedDustox
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaIsland_EventScript_DefeatedDustox
	setflag FLAG_VALENCIA_PARK_DUSTOX
	release
	end

ValenciaIsland_EventScript_DefeatedDustox::
	setflag FLAG_VALENCIA_PARK_DUSTOX
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaIsland_Text_Dustox:
	.string "DUST!$"

.set LOCALID_BEAUTIFLY, 1
.set LOCALID_DUSTOX, 2

ValenciaPark_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ValenciaPark_OnTransition
	.byte 0

ValenciaPark_OnTransition:
	gettime
	call_if_ne VAR_RESULT, TIME_NIGHT, ValenciaPark_EventScript_HideDustox
	call_if_ne VAR_RESULT, TIME_MORNING, ValenciaPark_EventScript_HideBeautifly
	call_if_eq VAR_RESULT, TIME_NIGHT, ValenciaPark_EventScript_Dustox2
	call_if_eq VAR_RESULT, TIME_MORNING, ValenciaPark_EventScript_Beautifly2
	end

ValenciaPark_Text_BiteTutor1:
	.string "Ahaha... You wish to learn the\n"
	.string "art of sinking fangs into the\p"
	.string "weak, yes? The thrill of darkness,\n"
	.string "the taste of fear...\p"
	.string "I can show your Pokémon how\n"
	.string "to make their foes tremble...\p"
	.string "with a single, sharp-BITE!$"

ValenciaPark_Text_BiteTutor2:
	.string "This move can be learned only\n"
	.string "once. Is that okay?$"

ValenciaPark_Text_BiteTutor3:
	.string "Which POKéMON wants to learn\n"
	.string "the move?$"

ValenciaPark_EventScript_BiteTutor1::
	lock
	faceplayer
	goto_if_set FLAG_BITE_TUTOR, ValenciaPark_EventScript_BiteTutor3
	msgbox ValenciaPark_Text_BiteTutor1, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, ValenciaPark_EventScript_BiteTutor2
	special DisableMsgBoxWalkaway
	signmsg
	msgbox ValenciaPark_Text_BiteTutor2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, ValenciaPark_EventScript_BiteTutor2
	msgbox ValenciaPark_Text_BiteTutor3, MSGBOX_DEFAULT
	setvar 0x8005 TUTOR_MOVE_BITE
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	switch VAR_RESULT
	case NO, ValenciaPark_EventScript_BiteTutor2
	setflag FLAG_BITE_TUTOR

ValenciaPark_EventScript_BiteTutor3::
	msgbox ValenciaPark_Text_BiteTutor5, MSGBOX_DEFAULT
	release
	end

ValenciaPark_EventScript_BiteTutor2::
	msgbox ValenciaPark_Text_BiteTutor4, MSGBOX_DEFAULT
	release
	end

ValenciaPark_Text_BiteTutor4:
	.string "Must not be ready for BITE,\n"
	.string "then.$"

ValenciaPark_Text_BiteTutor5:
	.string "Yesss... the lesson is complete.\p"
	.string "Your Pokémon now knows the hunger,\n"
	.string "the thrill...\p"
	.string "the fangs that pierce the night!$"

ValenciaPark_EventScript_Dustox2::
	call_if_set FLAG_VALENCIA_PARK_DUSTOX, ValenciaPark_EventScript_HideDustoxPerma
	return

ValenciaPark_EventScript_HideDustoxPerma::
	setflag FLAG_TEMP_2
	return

ValenciaPark_EventScript_Beautifly2::
	call_if_set FLAG_VALENCIA_PARK_BEAUTIFLY, ValenciaPark_EventScript_HideBeautiflyPerma
	return

ValenciaPark_EventScript_HideBeautiflyPerma::
	setflag FLAG_TEMP_1
	return

ValenciaPark_EventScript_HideDustox::
	setflag FLAG_TEMP_2
	return

ValenciaPark_EventScript_HideBeautifly::
	setflag FLAG_TEMP_1
	return

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

ValenciaPark_EventScript_Beautifly::
	lock
	faceplayer
	setwildbattle SPECIES_BEAUTIFLY, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_BEAUTIFLY_NORMAL
	callnative DrawMugshot
	playmoncry SPECIES_BEAUTIFLY, CRY_MODE_ENCOUNTER
	msgbox ValenciaPark_Text_Beautifly, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaPark_EventScript_DefeatedBeautifly
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaPark_EventScript_DefeatedBeautifly
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaPark_EventScript_DefeatedBeautifly
	setflag FLAG_VALENCIA_PARK_BEAUTIFLY
	release
	end

ValenciaPark_EventScript_DefeatedBeautifly::
	setflag FLAG_VALENCIA_PARK_BEAUTIFLY
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaPark_Text_Beautifly:
	.string "BEAUT!$"

ValenciaPark_EventScript_Dustox::
	lock
	faceplayer
	setwildbattle SPECIES_DUSTOX, 10
	waitse
	setvar VAR_0x8000, MUGSHOT_DUSTOX_NORMAL
	callnative DrawMugshot
	playmoncry SPECIES_DUSTOX, CRY_MODE_ENCOUNTER
	msgbox ValenciaPark_Text_Dustox, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ValenciaPark_EventScript_DefeatedDustox
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ValenciaPark_EventScript_DefeatedDustox
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ValenciaPark_EventScript_DefeatedDustox
	setflag FLAG_VALENCIA_PARK_DUSTOX
	release
	end

ValenciaPark_EventScript_DefeatedDustox::
	setflag FLAG_VALENCIA_PARK_DUSTOX
	goto Common_EventScript_RemoveStaticPokemon
	end

ValenciaPark_Text_Dustox:
	.string "DUST!$"

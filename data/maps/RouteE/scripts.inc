RouteE_MapScripts::
	.byte 0

RouteE_EventScript_Seadra::
	lock
	faceplayer
	setwildbattle SPECIES_SEADRA, 15
	waitse
	setvar VAR_0x8000, MUGSHOT_SEADRA_NORMAL
	callnative DrawMugshot
	playmoncry SPECIES_SEADRA, CRY_MODE_ENCOUNTER
	msgbox RouteE_Text_Seadra, MSGBOX_NPC
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RouteE_EventScript_DefeatedSeadra
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RouteE_EventScript_DefeatedSeadra
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RouteE_EventScript_DefeatedSeadra
	setflag FLAG_ROUTE_E_SEADRA
	release
	end

RouteE_EventScript_DefeatedSeadra::
	setflag FLAG_ROUTE_E_SEADRA
	goto Common_EventScript_RemoveStaticPokemon
	end

RouteE_Text_Seadra:
	.string "DRA!$"

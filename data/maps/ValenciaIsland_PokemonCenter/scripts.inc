.set LOCALID_NURSE, 1

ValenciaIsland_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ValenciaIsland_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ValenciaIsland_PokemonCenter_OnTransition:
	setrespawn SPAWN_VALENCIA_ISLAND
	end

ValenciaIsland_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

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

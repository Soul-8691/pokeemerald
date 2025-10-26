.set LOCALID_RHYDON, 3

ShamoutiIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShamoutiIsland_OnFrame
	.byte 0

ShamoutiIsland_OnFrame:
	map_script_2 VAR_TEAM_ROCKET, 0, ShamoutiIsland_EventScript_Giovanni
	.2byte 0

ShamoutiIsland_EventScript_Giovanni::
	setobjectxy 0xFF, 30, 29
	removeobject LOCALID_RHYDON
	msgbox ShamoutiIsland_Text_Giovanni, MSGBOX_DEFAULT
	addobject LOCALID_RHYDON
	setvar VAR_TEAM_ROCKET, 1
	end

ShamoutiIsland_Text_Giovanni:
	.string "LUGIA! I have come here to test your\n"
	.string "power!\p"
	.string "Go, Rhydon!$"

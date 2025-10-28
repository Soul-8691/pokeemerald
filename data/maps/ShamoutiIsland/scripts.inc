.set LOCALID_HOUNDOOM, 3

ShamoutiIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShamoutiIsland_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ShamoutiIsland_OnWarp
	.byte 0

ShamoutiIsland_OnWarp:
	map_script_2 VAR_TEAM_ROCKET, 0, ShamoutiIsland_EventScript_HidePlayer
	.2byte 0

ShamoutiIsland_EventScript_HidePlayer::
	removeobject LOCALID_HOUNDOOM
	setobjectxy OBJ_EVENT_ID_PLAYER, 30, 29
	end

ShamoutiIsland_OnFrame:
	map_script_2 VAR_TEAM_ROCKET, 0, ShamoutiIsland_EventScript_Archer
	.2byte 0

ShamoutiIsland_EventScript_Archer::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ShamoutiIsland_Text_Archer, MSGBOX_DEFAULT
	addobject LOCALID_HOUNDOOM
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	setvar VAR_TEAM_ROCKET, 1
	end

ShamoutiIsland_Text_Archer:
	.string "ARCHER: Lugia! I have come here to test\n"
	.string "your power!\p"
	.string "Go, Houndoom!$"

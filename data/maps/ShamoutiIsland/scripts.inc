.set LOCALID_LUGIA, 1
.set LOCALID_HOUNDOOM, 3

ShamoutiIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShamoutiIsland_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ShamoutiIsland_OnWarp
	.byte 0

ShamoutiIsland_OnWarp:
	map_script_2 VAR_TEAM_ROCKET, 0, ShamoutiIsland_EventScript_HidePlayer
	.2byte 0

ShamoutiIsland_EventScript_HidePlayer::
	removeobject LOCALID_LUGIA
	removeobject LOCALID_HOUNDOOM
	setobjectxy OBJ_EVENT_ID_PLAYER, 30, 29
	end

ShamoutiIsland_OnFrame:
	map_script_2 VAR_TEAM_ROCKET, 0, ShamoutiIsland_EventScript_Archer
	.2byte 0

ShamoutiIsland_EventScript_Archer::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ShamoutiIsland_Text_Archer, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_OAKS_PARCEL
	setvar VAR_0x8005, 124
	setvar VAR_0x8006, 48
	setflag FLAG_CUTSCENE
	showitemdesc
	msgbox ShamoutiIsland_Text_Archer2, MSGBOX_DEFAULT
	addobject LOCALID_LUGIA
	playmoncry SPECIES_LUGIA, CRY_MODE_NORMAL
	waitmoncry
	hideitemdesc
	msgbox ShamoutiIsland_Text_Archer3, MSGBOX_DEFAULT
	addobject LOCALID_HOUNDOOM
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	waitmoncry
	setvar VAR_TEAM_ROCKET, 1
	end

ShamoutiIsland_Text_Archer:
	.string "ARCHER: Lugia! I have come here to test\n"
	.string "your power!\p"
	.string "Behold! The Silver Wing!$"

ShamoutiIsland_Text_Archer2:
	.string "Little did the people of Shamouti Island\n"
	.string "know that this whole time, I've been\p"
	.string "searching for this feather while posing\n"
	.string "as a philanthropist scientist curing\p"
	.string "the ailments of the POKéMON of the Fire,\n"
	.string "Ice, and Lightning Islands!$"

ShamoutiIsland_Text_Archer3:
	.string "There you are! Prepare for battle!\p"
	.string "Go, Houndoom!$"

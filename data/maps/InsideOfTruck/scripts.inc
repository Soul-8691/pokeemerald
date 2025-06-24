InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	@ msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	additem ITEM_AQUA_MADOOR
	additem ITEM_BLUE_EYES_WHITE_DRAGON
	additem ITEM_CHANGE_OF_HEART
	additem ITEM_DARK_HOLE
	additem ITEM_DARK_MAGICIAN
	additem ITEM_EXODIA_THE_FORBIDDEN_ONE
	additem ITEM_FISSURE
	additem ITEM_FLAME_SWORDSMAN
	additem ITEM_GAIA_THE_DRAGON_CHAMPION
	additem ITEM_GAIA_THE_FIERCE_KNIGHT
	additem ITEM_GIANT_SOLDIER_OF_STONE
	additem ITEM_JUST_DESSERTS
	additem ITEM_LEFT_ARM_OF_THE_FORBIDDEN_ONE
	additem ITEM_LEFT_LEG_OF_THE_FORBIDDEN_ONE
	additem ITEM_MONSTER_REBORN
	additem ITEM_MYSTICAL_ELF
	additem ITEM_POLYMERIZATION
	additem ITEM_POT_OF_GREED
	additem ITEM_RAIGEKI
	additem ITEM_RED_EYES_BLACK_DRAGON
	additem ITEM_RIGHT_ARM_OF_THE_FORBIDDEN_ONE
	additem ITEM_RIGHT_LEG_OF_THE_FORBIDDEN_ONE
	additem ITEM_SOUL_EXCHANGE
	additem ITEM_SUMMONED_SKULL
	additem ITEM_SWORDS_OF_REVEALING_LIGHT
	additem ITEM_TRAP_HOLE
	additem ITEM_ULTIMATE_OFFERING
	additem ITEM_WALL_OF_ILLUSION
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"


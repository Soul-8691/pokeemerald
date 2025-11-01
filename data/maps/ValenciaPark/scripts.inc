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

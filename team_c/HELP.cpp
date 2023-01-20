#include"HELP.h"
#include"GAMEMAIN.h"
#include"Common.h"

HELP help;

HELP::HELP() {
	Help_image = 0;
}

void HELP::DrawHelp() {
	DrawGraph(0, 0, Help_image, FALSE);

	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	DrawGraph(880, 640, gamemain.ATitle_image, TRUE);


	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 0;
	}
}
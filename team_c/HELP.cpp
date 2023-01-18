#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

}

void HELP::DrawHelp() {
	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}
	DrawCircle(640, 360, 50, 0xffffff, true);

	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 0;
	}
}
#include"HELP.h"
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

	SetFontSize(25);
	DrawString(450, 690, "--- A‚ð‰Ÿ‚µ‚Äƒ^ƒCƒgƒ‹‚É–ß‚é ---", 0xffffff, 0);


	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 0;
	}
}
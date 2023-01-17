#include"TITLE.h"
#include"Common.h"

TITLE title;

TITLE::TITLE() {
	x = 0;
}

void TITLE::DrawTitle() {
	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}
	DrawCircle(640, 360, 100, 0xffffff, true);
	
	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 1;
	}
}
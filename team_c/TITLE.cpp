#include"TITLE.h"
#include"Common.h"

TITLE title;

TITLE::TITLE() {
	x = 0;
}

void TITLE::DrawTitle() {
	DrawCircle(640, 360, 100, 0xffffff, true);
	
	if (input.Buttons[12] == 1) {
		g_GameState = 1;
	}
}
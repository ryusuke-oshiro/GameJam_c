#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

}

void HELP::DrawHelp() {
	DrawCircle(640, 360, 50, 0xffffff, true);
	if (input.Buttons[12] == 1) {
		g_GameState = 3;
	}
}
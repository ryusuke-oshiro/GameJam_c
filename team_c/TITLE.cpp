#include"TITLE.h"
#include"Common.h"

TITLE title;

TITLE::TITLE() {
	x = 0;
	Title_bgm = 0;
}

void TITLE::DrawTitle() {

	// ƒ^ƒCƒgƒ‹BGM
	PlaySoundMem(Title_bgm, DX_PLAYTYPE_BACK, FALSE);

	DrawCircle(640, 360, 100, 0xffffff, true);
	DrawFormatString(50, 10, 0x000000, "TITLE");
	
	if (input.Buttons[12] == 1) {
		StopSoundMem(Title_bgm);
		g_GameState = 2;
	}
}
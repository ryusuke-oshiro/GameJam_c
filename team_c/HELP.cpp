#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

}

void HELP::DrawHelp() {
	
	SetFontSize(70);
	DrawString(20, 40, "ヘルプ", 0xffffff, 0);
	SetFontSize(40);
	DrawString(30, 150, "これは対象のターゲットがいくつ画面上にあるのかを\n見つけるゲームです", 0xffffff, 0);

	DrawString(20, 400, "操作説明", 0xffffff, 0);	

	SetFontSize(30);
	DrawString(430, 650, "--- Aを押してタイトルへ戻る ---", 0xffffff, 0);

	if (input.Buttons[12] == 1) {
		g_GameState = 0;
	}
}
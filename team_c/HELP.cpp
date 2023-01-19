#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

}

void HELP::DrawHelp() {
	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	SetFontSize(70);
	DrawString(20, 40, "ヘルプ", 0xffffff, 0);
	SetFontSize(40);
	DrawString(30, 150, "これは対象のターゲットがいくつ画面上にあるのかを\n見つけるゲームです", 0xffffff, 0);
	DrawString(30, 235, "正解すると次のレベルに進みます", 0xffffff, 0);
	DrawString(30, 280, "間違えるとゲームオーバーです", 0xff0000, 0);

	DrawString(20, 400, "操作説明", 0xffffff, 0);

	SetFontSize(30);
	DrawString(430, 680, "--- Aを押してタイトルに戻る ---", 0xffffff, 0);


	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 0;
	}
}
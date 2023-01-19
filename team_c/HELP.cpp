#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

	helpWaitTime = 0;
	helpImages = 0;
}

void HELP::DrawHelp() {

	DrawGraph(0, 0, helpImages, FALSE);


	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	SetFontSize(70);
	DrawString(20, 40, "ヘルプ", 0xffff00, 0);
	SetFontSize(40);
	DrawString(30, 150, "これは対象のターゲットがいくつ画面上にあるのかを\n見つけるゲームです", 0xf, 0);
	DrawString(30, 235, "正解すると次のレベルに進みます", 0xf, 0);
	DrawString(30, 280, "間違えるとゲームオーバーです", 0xff0000, 0);

	DrawString(20, 400, "操作説明", 0x9932cc, 0);
	DrawString(25, 450, "A", 0x008000, 0);
	DrawString(45, 450, "ボタンで決定", 0x00bfff, 0);
	DrawString(15, 490, "↑十字キー,↓十字キーで操作", 0x00bfff, 0);
	DrawString(30, 535, "BACKボタンで終了", 0x00bfff, 0);

	//文字の点滅
	if (++helpWaitTime < 30) {
		SetFontSize(30);
		DrawString(430, 680, "--- Aを押してタイトルに戻る ---", 0x0000ff, 0);
	}

	else if (helpWaitTime > 60) {
		helpWaitTime = 0;

	}

		if (input.Buttons[12] == 1 && Button_flg == FALSE) {
			Button_flg = TRUE;
			g_GameState = 0;
		}
}
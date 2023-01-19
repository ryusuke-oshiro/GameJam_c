#include"TITLE.h"
#include"Common.h"

TITLE title;

TITLE::TITLE() {
	x = 0;
	Title_image = 0;
	Title_bgm = 0;
	SE1 = 0;
}

void TITLE::DrawTitle() {
	// タイトルBGM
	PlaySoundMem(Title_bgm, DX_PLAYTYPE_BACK, FALSE);
	DrawGraph(0, 0, Title_image, FALSE);

	static int menuNo = 0;
	int posY;


	if (input.Buttons[1] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (++menuNo > 2) menuNo = 0;
	}
	if (input.Buttons[0] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (--menuNo < 0) menuNo = 2;
	}
	if (input.Buttons[1] == 0 && input.Buttons[0] == 0 && input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		StopSoundMem(Title_bgm);
		// タイトルSE
		PlaySoundMem(SE1, DX_PLAYTYPE_BACK);
		Button_flg = TRUE;
		switch (menuNo) {
		case 0:
			g_GameState = 2;
			break;
		case 1:
			g_GameState = 1;
			break;
		case 2:
			g_GameState = 3;
			break;
		}

	}


	posY = menuNo * 100;
	DrawTriangle(810, 310 + posY, 840, 330 + posY, 810, 350 + posY, 0xffffff, TRUE);

	SetFontSize(150);
	DrawString(725, 50, "TITLE", 0xffffff, 0);

	SetFontSize(60);
	DrawString(850, 300, "START", 0xffffff, 0);
	DrawString(850, 400, "HELP", 0xffffff, 0);
	DrawString(850, 500, "END", 0xffffff, 0);

	/*DrawFormatString(300, 600, 0xffffff, "HIGH SCORE:%d", menuNo);*/

	SetFontSize(20); //FPSの表示がでかくなるので修正
}
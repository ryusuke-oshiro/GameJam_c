#include"TITLE.h"
#include"Common.h"
#include"select_number.h"
TITLE title;

TITLE::TITLE() {
	x = 0;
	Title_image = 0;
	Title_bgm = 0;
	SE1 = 0;
	Chicken_se2 = 0;
}

void TITLE::DrawTitle() {

	// タイトルBGM
	if (CheckSoundMem(Title_bgm) == 0) {
		PlaySoundMem(Title_bgm, DX_PLAYTYPE_LOOP);
	}

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
		// タイトルSE
		PlaySoundMem(SE1, DX_PLAYTYPE_BACK,TRUE);

		Button_flg = TRUE;
		switch (menuNo) {
		case 0:
			StopSoundMem(Title_bgm);
			if (CheckSoundMem(hs.Chicken_se2) == 0) {
				PlaySoundMem(hs.Chicken_se2, DX_PLAYTYPE_BACK, TRUE);
			}
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
}
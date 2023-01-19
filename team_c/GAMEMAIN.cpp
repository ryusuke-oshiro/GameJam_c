#include"GAMEMAIN.h"

GAMEMAIN gamemain;

GAMEMAIN::GAMEMAIN() {
	phase = 0;
	UpDownCount = 0;
	CPos_x = 0;
	CPos_y = 0;
	Curtain_flg = FALSE;
	Curtain_image = 0;
	Game_bgm = 0;
	GameClear_se = 0;
	GameOver_se = 0;
}

void GAMEMAIN::Init() {
	phase = 0;
	UpDownCount = 0;
	CPos_x = 0;
	CPos_y = 0;
	Curtain_flg = FALSE;
}

void GAMEMAIN::GameMain() {
	CPos_y = UpDownCount * 24;
	switch(phase) {
		case 0:
			hs.DrawCurtain();	//垂れ幕
			break;
		case 1:
			si.DrawImage();		//表示
			break;
		case 2:
			sn.DrawSN();		//数字選択
			break;
		case 3:
			g_GameState = 0;
		default:
			break;
	}
	//CPos_y = UpDownCount * 24;
	DrawGraph(0, -720 + CPos_y, Curtain_image, TRUE);

	if (hs.Get_DispLevelflg() == TRUE && si.Get_Level() <= 10) {
		DrawFormatString(600, 400, 0xff0000, "レベル[ %d ]", si.Get_Level());
		DrawFormatString(600, 430, 0xff0000, "Aでスタート！");
	}
	SetFontSize(64);
	if (si.Get_TLtex() == TRUE) {
		DrawFormatString(600, 100, 0xffffff, "のこり　%.2f秒！", si.Get_TL());
	}
	SetFontSize(24);
	if (sn.Get_sn_flg() == TRUE) {
		DrawFormatString(600, 360, 0xff0000, "GameMain::数を選ぶ");
		DrawFormatString(600, 400, 0xff0000, "%d", sn.Get_number());
	}


	if (sn.Get_sntext_flg() == TRUE) {
		if (sn.Get_answer() == TRUE) {
				DrawFormatString(600, 360 - 200, 0xffffff, "レベルアップ！");	//白文字
		}
		if (sn.Get_answer() == FALSE) {
			DrawFormatString(600, 360 - 200, 0xffffff, "GAME OVER\nAボタンでタイトルに戻る");	//白文字
		}
	}
	if (hs.Get_clear_flg() == TRUE) {
		DrawFormatString(600, 360 - 200, 0xffffff, "全レベルクリア！Aボタンでタイトルに戻ります");	//白文字
	}
}

int GAMEMAIN::DownCurtain() {
	UpDownCount++;
	if (30 <= UpDownCount) {
		UpDownCount = 30;
		return true;
	}
}
int GAMEMAIN::UpCurtain() {
	UpDownCount--;
	if (UpDownCount <= 0) {
		UpDownCount = 0;
		return true;
	}
}

void GAMEMAIN::Set_phase(int n) {
	phase = n;
}

int GAMEMAIN::Get_phase() {
	return phase;
}


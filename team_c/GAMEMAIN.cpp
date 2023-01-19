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

	DrawGraph(0, -744 + CPos_y, Curtain_image, TRUE);

	if (hs.Get_DispLevelflg() == TRUE && si.Get_Level() <= 10) {

		// ゲームBGM
		//PlaySoundMem(Game_bgm, DX_PLAYTYPE_LOOP, FALSE);

		DrawFormatString(640, 400, 0xff0000, "レベル[ %d ]", si.Get_Level());
		DrawFormatString(640, 430, 0xff0000, "Aでスタート！");
	}
	if (sn.Get_sn_flg() == TRUE) {
		DrawFormatString(640, 360, 0xff0000, "GameMain::数を選ぶ");
		DrawFormatString(640, 400, 0xff0000, "%d", sn.Get_number());
	}
	if (sn.Get_sntext_flg() == TRUE) {
		if (sn.Get_answer() == TRUE) {
			if (si.Get_Level() <= 10) {

				DrawFormatString(640, 360 - 200, 0xffffff, "レベルアップ！");	//白文字

				// ゲームクリアBGM
				PlaySoundMem(GameClear_se, DX_PLAYTYPE_BACK, FALSE);
			}
		}
		if (sn.Get_answer() == FALSE) {

			DrawFormatString(640, 360 - 200, 0xffffff, "失敗、、、正解は%d", si.Get_Answer());	//白文字

			// ゲームオーバーBGM
			PlaySoundMem(GameOver_se, DX_PLAYTYPE_BACK, FALSE);
		}
	}
	if (hs.Get_clear_flg() == TRUE) {
		DrawFormatString(640, 360 - 200, 0xffffff, "全レベルクリア！Aボタンでタイトルに戻ります");	//白文字
	}
}

int GAMEMAIN::DownCurtain() {
	UpDownCount++;
	CPos_y = UpDownCount * 24;
	if (30 < UpDownCount) {
		UpDownCount = 30;
		return true;
	}
}
int GAMEMAIN::UpCurtain() {
	UpDownCount--;
	CPos_y = UpDownCount * 24;
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


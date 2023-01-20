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
	Good_image = 0;
	GameOver_image = 0;
	ATitle_image = 0;
	AStart_image = 0;
	Clear_image = 0;
	Button_image1 = 0;
	Button_image2 = 0;
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
			StopSoundMem(Game_bgm);
			g_GameState = 0;
		default:
			break;
	}
	//CPos_y = UpDownCount * 24;

	DrawGraph(0, -720 + CPos_y, Curtain_image, TRUE);

	if (hs.Get_DispLevelflg() == TRUE && si.Get_Level() <= 10) {
		// ゲームBGM
		if (CheckSoundMem(Game_bgm) == 0) {
			PlaySoundMem(Game_bgm, DX_PLAYTYPE_LOOP);
		}

		DrawFormatString(500, 300, 0xffffff, "レベル  %d  ", si.Get_Level());
		DrawGraph(510, 370, AStart_image, TRUE);
	}
	SetFontSize(64);
	if (si.Get_TLtex() == TRUE) {
		DrawFormatString(420, 100, 0xffffff, "のこり %.2f 秒！", si.Get_TL());
	}
	/*SetFontSize(64);*/
	if (sn.Get_sn_flg() == TRUE) {
		DrawFormatString(400, 220, 0xffffff, "見つけたニワトリ");
		DrawFormatString(580, 380, 0xffffff, "%d  羽", sn.Get_number());
	}


	if (sn.Get_sntext_flg() == TRUE) {
		if (sn.Get_answer() == TRUE) {
			DrawGraph(0, 0, Good_image, TRUE);
				//DrawFormatString(600, 360 - 200, 0xffffff, "レベルアップ！");	//白文字
		}
		if (sn.Get_answer() == FALSE) {
			DrawGraph(0, 0, GameOver_image, TRUE);
			
			//DrawFormatString(600, 360 - 200, 0xffffff, "GAME OVER\nAボタンでタイトルに戻る");	//白文字
		}
	}
	if (hs.Get_clear_flg() == TRUE) {
		
		/*if (CheckSoundMem(hs.Chicken_se1) == 1) {
			StopSoundMem(hs.Chicken_se1);
		}*/
		DrawGraph(0, 0, Clear_image, TRUE);
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


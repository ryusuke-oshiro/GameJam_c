#include"GAMEMAIN.h"

GAMEMAIN gamemain;

GAMEMAIN::GAMEMAIN() {
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
			g_GameState = 3;
		default:
			break;
	}
	DrawBox(0, 0, 1280, CPos_y, 0xffffff, true);
	//DrawFormatString(640, 360, 0x000000, "Curtain");	//白壁　黒文字
	if (hs.Get_DispLevelflg() == TRUE) {
		DrawFormatString(640, 400, 0xff0000, "レベル[ %d ]", si.Get_Level());
		DrawFormatString(640, 430, 0xff0000, "Aでスタート！");
	}
}

int GAMEMAIN::DownCurtain() {
	UpDownCount++;
	CPos_y = UpDownCount * 6;
	if (120 < UpDownCount) {
		UpDownCount = 120;
		return true;
	}
}
int GAMEMAIN::UpCurtain() {
	UpDownCount--;
	CPos_y = UpDownCount * 6;
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


#include"GAMEMAIN.h"

GAMEMAIN gamemain;

GAMEMAIN::GAMEMAIN() {
	level = 0;
	phase = 0;
	CPos_x = 0;
	CPos_y = 0;
}

void GAMEMAIN::GameMain() {
	switch(phase) {
		case 0:
			hs.DrawCurtain();	//‚‚ê–‹
			break;
		case 1:
			UpCurtain();
			si.DrawImage();		//•\¦
			break;
		case 2:
			sn.DrawSN();		//”š‘I‘ğ
			break;
		case 3:
			g_GameState = 3;
		default:
			break;
	}
	DrawBox(0, 0, 1280, CPos_y, 0xffffff, true);
	DrawFormatString(640, 360, 0x000000, "GameMain::phase0");	//”’•Ç@••¶š
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

void GAMEMAIN::Set_level(int n) {
	level = n;
}

int GAMEMAIN::Get_level() {
	return level;
}
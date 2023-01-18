#pragma once
#include"DxLib.h"
#include"hanging_screen.h"
#include"still_image.h"
#include"select_number.h"

class GAMEMAIN {
public:
	int phase;
	int CPos_x;
	int CPos_y;
	int UpDownCount;
	int Curtain_flg;
public:
	GAMEMAIN();
	int UpCurtain();
	int DownCurtain();
	void Set_phase(int n);
	int Get_phase();
	void Set_Cflg(int n) {
		Curtain_flg = n;
	}
	int Get_Cflg() {
		return Curtain_flg;
	}
	void GameMain();
};
extern GAMEMAIN gamemain;
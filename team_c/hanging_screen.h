#pragma once
#include"DxLib.h"
#include"Common.h"
#include"GAMEMAIN.h"

class hanging_screen {
public:
	int Pos_x;
	int Pos_y;
	int fhase_flg;
	int Count;
	int DispLevelflg;
	int levelup_count;
	int Circle_flg;
	int flg;
	int Clear_flg;
	int GameStart_image;
	int Chicken_se1;
	int Chicken_se2;
	int Chicken_se3;
public:
	hanging_screen();
	void Init();
	void DrawCurtain();
	int Get_DispLevelflg() {
		return DispLevelflg;
	}
	int Get_clear_flg() {
		return Clear_flg;
	}
};
extern hanging_screen hs;
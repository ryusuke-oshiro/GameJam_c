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
	int flg;
public:
	hanging_screen();
	void DrawCurtain();
	int Get_DispLevelflg() {
		return DispLevelflg;
	}
};
extern hanging_screen hs;
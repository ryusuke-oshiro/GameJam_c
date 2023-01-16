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
	
public:
	hanging_screen();
	void DrawCurtain();
};
extern hanging_screen hs;
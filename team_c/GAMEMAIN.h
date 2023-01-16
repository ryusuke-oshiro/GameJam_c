#pragma once
#include"DxLib.h"
#include"hanging_screen.h"
#include"still_image.h"
#include"select_number.h"

class GAMEMAIN {
public:
	int phase;
	int level;
	int CPos_x;
	int CPos_y;
	int UpDownCount;
public:
	GAMEMAIN();
	int UpCurtain();
	int DownCurtain();
	void Set_phase(int n);
	int Get_phase();
	void Set_level(int n);
	int Get_level();
	void GameMain();
};
extern GAMEMAIN gamemain;
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
	int Curtain_image;
	int Game_bgm;
	int GameClear_se;
	int GameOver_se;
	int Chicken_se2;
	int Good_image;
	int GameOver_image;
	int ATitle_image;
	int AStart_image;
	int Clear_image;
	int Button_image1;
	int Button_image2;
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
	int Get_CPos_y() {
		return CPos_y;
	}
	void GameMain();
	void Init();
};
extern GAMEMAIN gamemain;
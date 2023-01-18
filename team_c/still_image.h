#pragma once
#include"DxLib.h"
#include"GAMEMAIN.h"
#include"time.h"

class still_image {
public:
	int Count;
	int Answer;
	int Level;
	int DispAllCount;	//表示個数
	int DispTargetCount;//探す対象の個数
	int DispImage[6];	//各イメージ
	int DispTargetPos[5][3];	//ターゲットのｘ座標、ｙ座標、反転フラグ
	int DispElsePos[29][4];		//その他	のｘ座標、ｙ座標、反転フラグ、DispImageの要素数
	int BackGround_img;
public:
	still_image();
	void DrawImage();
	void Set_DispCount(int n);
	void InitPos();
	int Get_Answer() {
		return Answer;
	}
	void Set_Level(int n) {
		Level = n;
	}
	int Get_Level() {
		return Level;
	}
};
extern still_image si;
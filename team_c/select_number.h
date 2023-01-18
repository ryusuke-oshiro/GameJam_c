#pragma once
#include"DxLib.h"
#include"GAMEMAIN.h"
#include"still_image.h"
class select_number {
public:
	int Count;
	int number;
	int answer;
	int B_flg;
	int left;
	int right;
	int up;
	int down;
	int sn_flg;
public:
	select_number();
	void DrawSN();
	int Get_answer() {
		return answer;
	}
	int Get_number() {
		return number;
	}
	int Get_sn_flg() {
		return sn_flg;
	}
};
extern select_number sn;
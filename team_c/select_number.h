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
	int sn_text_flg;
	int SE2;
public:
	select_number();
	void Init();
	void DrawSN();
	int Get_answer() {
		return answer;
	}
	void Set_answer(int n) {
		answer = n;
	}
	int Get_number() {
		return number;
	}
	void Reset_number() {
		number = 0;
	}
	int Get_sn_flg() {
		return sn_flg;
	}
	int Get_sntext_flg() {
		return  sn_text_flg;
	}
	void Set_st_flg(int n) {
		sn_text_flg = n;
	}
};
extern select_number sn;
#pragma once
#include"DxLib.h"
#include"GAMEMAIN.h"

class still_image {
public:
	int Count;
	int Answer;
	int Level;
public:
	still_image();
	void DrawImage();
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
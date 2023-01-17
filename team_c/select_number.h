#pragma once
#include"DxLib.h"
#include"GAMEMAIN.h"
#include"still_image.h"
class select_number {
public:
	int Count;
	int number;
	int answer;
public:
	select_number();
	void DrawSN();
};
extern select_number sn;
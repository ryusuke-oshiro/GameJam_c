#pragma once
#include<DxLib.h>
class TITLE {
public:
	int x;
	int Title_image;
	int Title_bgm;
	int SE1;
	int Chicken_se2;
public:
	TITLE();
	void DrawTitle();
};
extern TITLE title;
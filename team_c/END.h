#pragma once
#include"DxLib.h"
class END {
public:
	int count;
	int endWaitTime;
	int endPosY;
	int endImages;
	
public:
	END();
	void DrawEnd();
};
extern END end;
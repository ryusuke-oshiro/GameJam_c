#pragma once
#include"DxLib.h"
#include"GAMEMAIN.h"
#include"time.h"

class still_image {
public:
	int Count;
	int Answer;
	int Level;
	int DispAllCount;	//�\����
	int DispTargetCount;//�T���Ώۂ̌�
	int DispImage[6];	//�e�C���[�W
	int DispTargetPos[5][3];	//�^�[�Q�b�g�̂����W�A�����W�A���]�t���O
public:
	still_image();
	void DrawImage();
	void Set_DispCount(int n);
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
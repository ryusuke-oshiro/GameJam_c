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
	int DispElsePos[29][4];		//���̑�	�̂����W�A�����W�A���]�t���O�ADispImage�̗v�f��
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
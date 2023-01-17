#include"still_image.h"

#define MAX_TARGET_COUNT 4
#define TARGET 0

still_image si;

still_image::still_image() {
	Count = 0;
	Answer = 0;
	Level = 1;
	DispAllCount = 0;
	DispTargetCount = 0;
	/*--------ここに画像をロードする-------*/
	/*LoadImage()*/
	DispImage[TARGET] = 0;
	DispImage[1] = 1;
	DispImage[2] = 2;
	DispImage[3] = 3;
	DispImage[4] = 4;
	DispImage[5] = 5;
	/*--------ここに画像をロードする-------*/
	InitPos();
}

void still_image::DrawImage() {
	Count++;

	/*srand(time(NULL));
	DispAllCount = rand() % 3;*/
	
	if (Count < 120) {
		gamemain.UpCurtain();
	}
	if (240 < Count) {
		gamemain.DownCurtain();
	}
	DrawBox(170, 270, 1110, 700, 0xffffff, false);
	//SetFontSize(50);
	//DrawFormatString(640, 360, 0xffffff, "GameMain::探す画像");	//ここにランダムな数の対象を配置した画像を置く
	for (int i = 0; i < DispTargetCount; i++) {
		DrawFormatString(DispTargetPos[i][0], DispTargetPos[i][1], 0xff0000, "%d", DispImage[0]);
	}
	for (int j = 0; j < DispAllCount - DispTargetCount; j++) {
		DrawFormatString(DispElsePos[j][0], DispElsePos[j][1], 0x00ff00, "%d", DispImage[DispElsePos[j][3]]);
	}
	
	if (360 < Count) {
		Count = 0;
		//Answer = DispTargetCount;
		gamemain.Set_phase(2);
	}
}

void still_image::Set_DispCount(int n) {
	InitPos();
	srand((unsigned)time(NULL));
	switch (n) {		//全表示個数、探す対象の個数をきめる
	case 1:
		DispAllCount = 4;
		DispTargetCount= rand() % 2 + 1;	//1～3
		break;
	case 2:
		DispAllCount = 7;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 3:
		DispAllCount = 9;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 4:
		DispAllCount = 12;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 5:
		DispAllCount = 15;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 6:
		DispAllCount = 18;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 7:
		DispAllCount = 20;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 8:
		DispAllCount = 22;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 9:
		DispAllCount = 25;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	case 10:
		DispAllCount = 30;
		DispTargetCount = rand() % MAX_TARGET_COUNT+1;
		break;
	default:
		break;
	}

	for (int i = 0; i < DispTargetCount; i++) {		//探す対象の表示座標をきめる
		DispTargetPos[i][0] = rand() % 880 + 200;	//X::200～1080
		DispTargetPos[i][1] = rand() % 370 + 300;	//Y::300～670
		int a = rand() % 2;
		if (a == 0) {
			DispTargetPos[i][2] = true;
		}
		else {
			DispTargetPos[i][2] = false;
		}
	}
	for (int i = 0; i < DispAllCount - DispTargetCount; i++) {	//その他の座標をきめる
		DispElsePos[i][0] = rand() % 880 + 200;	//200～1080
		DispElsePos[i][1] = rand() % 370 + 300;	//300～670
		int a = rand() % 2;
		if (a == 0) {
			DispElsePos[i][2] = true;
		}
		else {
			DispElsePos[i][2] = false;
		}
		DispElsePos[i][3] = rand() % 5 + 1;
	}
}

void still_image::InitPos() {
	for (int i = 0; i < 5; i++) {
		DispTargetPos[i][0] = 0;
		DispTargetPos[i][1] = 0;
		DispTargetPos[i][2] = 0;
	}
	for (int j = 0; j < 29; j++) {
		DispElsePos[j][0] = 0;
		DispElsePos[j][1] = 0;
		DispElsePos[j][2] = 0;
	}
}
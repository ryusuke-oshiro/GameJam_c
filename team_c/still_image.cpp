#include"still_image.h"

#define MAX_TARGET_COUNT 5
#define TARGET 0

still_image si;

still_image::still_image() {
	Count = 0;
	Answer = 0;
	Level = 0;
	DispAllCount = 0;
	DispTargetCount = 0;
	/*LoadImage()*/
	DispImage[TARGET] = 0;
	DispImage[1] = 1;
	DispImage[2] = 2;
	DispImage[3] = 3;
	DispImage[4] = 4;
	DispImage[5] = 5;
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

	//SetFontSize(50);
	//DrawFormatString(640, 360, 0xffffff, "GameMain::探す画像");	//ここにランダムな数の対象を配置した画像を置く

	
	
	if (360 < Count) {
		Count = 0;
		gamemain.Set_phase(2);
	}
}

void still_image::Set_DispCount(int n) {
	srand(time(NULL));
	switch (n) {		//全表示個数、探す対象の個数をきめる
	case 1:
		DispAllCount = 4;
		DispTargetCount= rand() % 3;
		break;
	case 2:
		DispAllCount = 7;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 3:
		DispAllCount = 9;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 4:
		DispAllCount = 12;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 5:
		DispAllCount = 15;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 6:
		DispAllCount = 18;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 7:
		DispAllCount = 20;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 8:
		DispAllCount = 22;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 9:
		DispAllCount = 25;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	case 10:
		DispAllCount = 30;
		DispTargetCount = rand() % MAX_TARGET_COUNT;
		break;
	}

	for (int i = 0; i < DispTargetCount; i++) {		//探す対象の表示座標をきめる
		DispTargetPos[i][0] = rand() % 880 + 200;
	}
	for (int i = 0; i < DispAllCount - DispTargetCount; i++) {	//その他の座標をきめる

	}
}
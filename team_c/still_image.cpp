#include"still_image.h"

still_image si;

still_image::still_image() {
	Count = 0;
	Answer = 0;
	Level = 0;
}

void still_image::DrawImage() {
	Count++;

	if (Count < 120) {
		gamemain.UpCurtain();
	}
	if (240 < Count) {
		gamemain.DownCurtain();
	}


	//SetFontSize(50);
	DrawFormatString(640, 360, 0xffffff, "GameMain::�T���摜");	//�����Ƀ����_���Ȑ��̑Ώۂ�z�u�����摜��u��

	
	
	if (360 < Count) {
		Count = 0;
		gamemain.Set_phase(2);
	}
}
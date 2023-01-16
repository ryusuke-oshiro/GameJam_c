#include"still_image.h"

still_image si;

still_image::still_image() {
	Count = 0;
}

void still_image::DrawImage() {
	Count++;

	SetFontSize(50);
	DrawFormatString(640, 360, 0xffffff, "GameMain::pahse1");

	if (180 < Count) {
		gamemain.Set_phase(2);
	}
}
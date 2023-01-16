#include"select_number.h"

select_number sn;

select_number::select_number() {
	Count = 0;
}

void select_number::DrawSN() {
	Count++;

	SetFontSize(50);
	DrawFormatString(640, 360, 0xffffff, "GameMain::phase3");

	if (60 < Count) {
		gamemain.Set_phase(3);
	}
}
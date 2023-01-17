#include"select_number.h"

select_number sn;

select_number::select_number() {
	Count = 0;
	number = 0;
	answer = 0;
}

void select_number::DrawSN() {
	Count++;

	//SetFontSize(50);
	DrawFormatString(640, 360, 0x00ff00, "GameMain::”‚ğ‘I‚Ô");


	if (300 < Count || input.Buttons[12] == 1) {
		if (number == si.Get_Answer()) {		//³‰ğ‚¾‚Á‚½ê‡
			si.Set_Level(si.Get_Level() + 1);
			Count = 0;
			gamemain.Set_phase(0);
		}
		else {									//ŠÔˆá‚¢‚¾‚Á‚½ê‡
			Count = 0;
			gamemain.Set_phase(3);
		}
	}
}
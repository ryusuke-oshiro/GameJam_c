#include"hanging_screen.h"

hanging_screen hs;

hanging_screen::hanging_screen() {
	Pos_x = 640;
	Pos_y = 360;
	fhase_flg = FALSE;
	Count = 0;
}

void hanging_screen::DrawCurtain() {
	if (gamemain.Get_level() == 0) {
		Count++;
		SetFontSize(24);
		DrawFormatString(Pos_x, Pos_y, 0xffffff, "›‚ğ’T‚»‚¤ phase:1");	//”’•¶š

		if (120 < Count) {
			if (gamemain.DownCurtain() == true) {
				fhase_flg = true;
			}
		}
		if (input.Buttons[12] == 1 && fhase_flg == true) {
			Count = 0;
			fhase_flg = FALSE;
			gamemain.Set_phase(1);
		}
	}
	else {

	}
	
}

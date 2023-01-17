#include"hanging_screen.h"

hanging_screen hs;

hanging_screen::hanging_screen() {
	Pos_x = 640;
	Pos_y = 360;
	fhase_flg = FALSE;
	DispLevelflg = FALSE;
	Count = 0;
}

void hanging_screen::DrawCurtain() {
	if (gamemain.Get_level() == 1) {
		Count++;
		SetFontSize(24);
		DrawFormatString(Pos_x, Pos_y, 0xffffff, "[0]を探そう phase:1");	//白文字

		if (120 < Count) {
			if (gamemain.DownCurtain() == true) {
				DispLevelflg = TRUE;
				fhase_flg = true;
			}
		}
		if (input.Buttons[12] == 1 && fhase_flg == true) {
			Count = 0;
			DispLevelflg = FALSE;
			fhase_flg = FALSE;
			si.Set_DispCount(gamemain.Get_level());	//ステージレベルから表示個数をきめる
			gamemain.Set_phase(1);
		}
	}
	else {

	}
	
}

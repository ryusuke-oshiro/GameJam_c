#include"select_number.h"

select_number sn;

select_number::select_number() {
	Count = 0;
	number = 0;
	answer = TRUE;
	sn_flg = FALSE;
	sn_text_flg = FALSE;
	B_flg = TRUE;

	left = FALSE;
	right = TRUE;
	up = FALSE;
	down = FALSE;
}

void select_number::DrawSN() {
	Count++;
	sn_flg = TRUE;
	//SetFontSize(50);
	//DrawFormatString(640, 360, 0xff0000, "GameMain::êîÇëIÇ‘");
	if (input.Buttons[2] == 1 && B_flg == TRUE) {	//ç∂
		B_flg = FALSE;
		left = TRUE;
		right = FALSE;
	}

	if (input.Buttons[3] == 1 && B_flg == TRUE) {	//âE
		B_flg = FALSE;
		left = FALSE;
		right = TRUE;
	}

	if (input.Buttons[0] == 1 && B_flg == TRUE) {	//è„
		B_flg = FALSE;
		if (left == TRUE) {
			number += 10;
		}
		if (right == TRUE) {
			number += 1;
		}
	}
	if (input.Buttons[1] == 1 && B_flg == TRUE) {	//â∫
		B_flg = FALSE;
		if (left == TRUE) {
			number -= 10;
		}
		if (right == TRUE) {
			number -= 1;
		}
	}

	if (input.Buttons[0] == 0 && input.Buttons[1] == 0 && input.Buttons[2] == 0 && input.Buttons[3] == 0) {
		B_flg = TRUE;
	}

	//DrawFormatString(640, 360, 0x000000, "%d", number);

	if (300 < Count || input.Buttons[12] == 1) {
		if (number == si.Get_Answer()) {		//ê≥âÇæÇ¡ÇΩèÍçá
			si.Set_Level(si.Get_Level() + 1);
			Count = 0;
			answer = TRUE;
			sn_text_flg = TRUE;
			sn_flg = FALSE;
			gamemain.Set_phase(0);
		}
		if(number != si.Get_Answer()) {									//ä‘à·Ç¢ÇæÇ¡ÇΩèÍçá
			Count = 0;
			answer = FALSE;
			sn_flg = FALSE;
			sn_text_flg = TRUE;
			gamemain.Set_phase(0);
		}
	}
}
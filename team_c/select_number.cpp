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
	GameClear_se = 0;
	GameOver_se = 0;
	SE2 = 0;
}

void select_number::Init() {
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

	if (input.Buttons[0] == 1 && B_flg == TRUE) {	//上
		B_flg = FALSE;
			number += 1;
			PlaySoundMem(SE2, DX_PLAYTYPE_BACK);	// SEの追加
			if (number > 5) {
				number = 5;
			}
	}
	if (input.Buttons[1] == 1 && B_flg == TRUE) {	//下
		B_flg = FALSE;
			number -= 1;
			PlaySoundMem(SE2, DX_PLAYTYPE_BACK);	// SEの追加
			if (number < 1) {
				number = 1;
			}
	}

	if (input.Buttons[0] == 0 && input.Buttons[1] == 0 && input.Buttons[2] == 0 && input.Buttons[3] == 0) {
		B_flg = TRUE;
	}

	if (input.Buttons[12] == 1 && number != 0) {
		if (number == si.Get_Answer()) {		//正解だった場合
			// ゲームクリアSE
			PlaySoundMem(GameClear_se, DX_PLAYTYPE_BACK, TRUE);
			si.Set_Level(si.Get_Level() + 1);
			answer = TRUE;
			sn_text_flg = TRUE;
			sn_flg = FALSE;
			gamemain.Set_phase(0);
		}
		if(number != si.Get_Answer()) {			//間違いだった場合
			// ゲームオーバーSE
			PlaySoundMem(GameOver_se, DX_PLAYTYPE_BACK, TRUE);
			answer = FALSE;
			sn_flg = FALSE;
			sn_text_flg = TRUE;
			gamemain.Set_phase(0);
		}
	}
}
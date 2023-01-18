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
	DrawFormatString(640, 360, 0xfff, "GameMain::数を選ぶ");	//ここ
	//printf("%d\n", number % 10);//1の位
	SetFontSize(30);
	DrawFormatString(640, 460, 0xfff, "00", number);

	if (input.Buttons[12] == 8 ) { //コントローラー上十字

		number++;
		if (5 < number) {
			number = 5;
			number--;
		}
		
	}

	if (input.Buttons[12] == 5) { //コントローラー下十字

		number--;
		if (0 > number) {
			number = 0;
			number++;
		}

	}

	//決定



	if (300 < Count || input.Buttons[12] == 1) {
		if (number == si.Get_Answer()) {		//正解だった場合
			si.Set_Level(si.Get_Level() + 1);
			gamemain.Set_phase(0);
		}
		else {									//間違いだった場合
			gamemain.Set_phase(3);
		}
	}
}
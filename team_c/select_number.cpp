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
	DrawFormatString(640, 360, 0xffffff, "GameMain::”‚ğ‘I‚Ô");	//‚±‚±
	//printf("%d\n", number % 10);//1‚ÌˆÊ
	SetFontSize(30);
	DrawFormatString(640, 460, 0xfff, "00", number);

	if (input.Buttons[12] == 8 ) {

		number++;
		if (5 <= number%10) {
			number--;
		}
		
	}

	if (input.Buttons[12] == 5) {

		number--;
		if (0 <= number % 10) {
			number++;
		}

	}

	if (300 < Count || input.Buttons[12] == 1) {
		if (number == si.Get_Answer()) {		//³‰ğ‚¾‚Á‚½ê‡
			si.Set_Level(si.Get_Level() + 1);
			gamemain.Set_phase(0);
		}
		else {									//ŠÔˆá‚¢‚¾‚Á‚½ê‡
			gamemain.Set_phase(3);
		}
	}
}
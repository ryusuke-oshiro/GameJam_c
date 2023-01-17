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

	int Count = 00;
	printf("%d", Count);

	if (input.Buttons[12] == 8) {

		Count++;
		if (29 < Count) {
			Count = 0;
		}

	}
	if (input.Buttons[12] == 5) {

		Count--;
		if (29 < Count) {
			Count = 0;
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
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
	DrawFormatString(640, 360, 0xfff, "GameMain::����I��");	//����
	//printf("%d\n", number % 10);//1�̈�
	SetFontSize(30);
	DrawFormatString(640, 460, 0xfff, "00", number);

	if (input.Buttons[12] == 8 ) { //�R���g���[���[��\��

		number++;
		if (5 < number) {
			number = 5;
			number--;
		}
		
	}

	if (input.Buttons[12] == 5) { //�R���g���[���[���\��

		number--;
		if (0 > number) {
			number = 0;
			number++;
		}

	}

	//����



	if (300 < Count || input.Buttons[12] == 1) {
		if (number == si.Get_Answer()) {		//�����������ꍇ
			si.Set_Level(si.Get_Level() + 1);
			gamemain.Set_phase(0);
		}
		else {									//�ԈႢ�������ꍇ
			gamemain.Set_phase(3);
		}
	}
}
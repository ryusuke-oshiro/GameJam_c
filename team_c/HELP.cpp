#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {
	
}

void HELP::DrawHelp() {
	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	SetFontSize(70);
	DrawString(20, 40, "�w���v", 0xffffff, 0);
	SetFontSize(40);
	DrawString(30, 150, "����͑Ώۂ̃^�[�Q�b�g��������ʏ�ɂ���̂���\n������Q�[���ł�", 0xffffff, 0);
	DrawString(30, 235, "�����Ǝ��̃X�e�[�W�ɐi�߂܂�", 0xffffff, 0);
	DrawString(30, 280, "�ԈႦ��ƃQ�[���I�[�o�[�ł�", 0xff0000, 0);

	DrawString(20, 400, "�����", 0xffffff, 0);	

	SetFontSize(30);
	DrawString(430, 680, "--- A����ă^�C�g���֖߂� ---", 0xffffff, 0);


	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		g_GameState = 0;
	}
}
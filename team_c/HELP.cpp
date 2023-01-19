#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

	helpWaitTime = 0;
	helpImages = 0;
}

void HELP::DrawHelp() {

	DrawGraph(0, 0, helpImages, FALSE);


	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	SetFontSize(70);
	DrawString(20, 40, "�w���v", 0xffff00, 0);
	SetFontSize(40);
	DrawString(30, 150, "����͑Ώۂ̃^�[�Q�b�g��������ʏ�ɂ���̂���\n������Q�[���ł�", 0xf, 0);
	DrawString(30, 235, "��������Ǝ��̃��x���ɐi�݂܂�", 0xf, 0);
	DrawString(30, 280, "�ԈႦ��ƃQ�[���I�[�o�[�ł�", 0xff0000, 0);

	DrawString(20, 400, "�������", 0x9932cc, 0);
	DrawString(25, 450, "A", 0x008000, 0);
	DrawString(45, 450, "�{�^���Ō���", 0x00bfff, 0);
	DrawString(15, 490, "���\���L�[,���\���L�[�ő���", 0x00bfff, 0);
	DrawString(30, 535, "BACK�{�^���ŏI��", 0x00bfff, 0);

	//�����̓_��
	if (++helpWaitTime < 30) {
		SetFontSize(30);
		DrawString(430, 680, "--- A�������ă^�C�g���ɖ߂� ---", 0x0000ff, 0);
	}

	else if (helpWaitTime > 60) {
		helpWaitTime = 0;

	}

		if (input.Buttons[12] == 1 && Button_flg == FALSE) {
			Button_flg = TRUE;
			g_GameState = 0;
		}
}
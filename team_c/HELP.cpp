#include"HELP.h"
#include"Common.h"

HELP help;

HELP::HELP() {

}

void HELP::DrawHelp() {
	
	SetFontSize(70);
	DrawString(20, 40, "�w���v", 0xffffff, 0);
	SetFontSize(40);
	DrawString(30, 150, "����͑Ώۂ̃^�[�Q�b�g��������ʏ�ɂ���̂���\n������Q�[���ł�", 0xffffff, 0);

	DrawString(20, 400, "�������", 0xffffff, 0);	

	SetFontSize(30);
	DrawString(430, 650, "--- A�������ă^�C�g���֖߂� ---", 0xffffff, 0);

	if (input.Buttons[12] == 1) {
		g_GameState = 0;
	}
}
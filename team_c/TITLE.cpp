#include"TITLE.h"
#include"Common.h"

TITLE title;

TITLE::TITLE() {
	x = 0;
}

void TITLE::DrawTitle() {


	static int menuNo = 0;
	int posY;
	 
	// ���j���[�J�[�\���̈ړ�����
	if (input.Buttons[1] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (++menuNo > 2) menuNo = 0;
	}
	if (input.Buttons[0] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (--menuNo < 0) menuNo = 2;
	}
	if (input.Buttons[1] == 0 && input.Buttons[0] == 0 && input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		switch(menuNo){
		case 0:
			g_GameState = 4;		// ���C����ʂ�
			break;
		case 1:
			g_GameState = 1;		// �w���v��ʂ�
			break;
		case 2:
			g_GameState = 3;		// �G���h��ʂ�
			break;
		}

	}

	// ���j���[�J�[�\���i�O�p�`�j�̕\��
	posY = menuNo * 100;
	DrawTriangle(510, 310 + posY, 540, 330 + posY, 510, 350 + posY, 0xffffff, TRUE);

	SetFontSize(150);
	DrawString(500, 50, "TITLE", 0xffffff, 0);

	SetFontSize(60);
	DrawString(600, 300, "START", 0xffffff, 0);
	DrawString(600, 400, "HELP", 0xffffff, 0);
	DrawString(600, 500, "END", 0xffffff, 0);

	DrawFormatString(300, 600, 0xffffff, "HIGH SCORE:%d", menuNo);

	//DrawCircle(640, 360, 100, 0xffffff, true);
}
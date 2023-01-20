#include"END.h"

END end;

END::END() {
	count = 0;
	endWaitTime = 0;
	endPosY = 0;
	endImages = 0;
}

void END::DrawEnd() {
	DrawGraph(0, 0, endImages, FALSE);
	//�G���f�B���O�\��
	if (++endWaitTime < 2300) endPosY = 300 - endWaitTime / 2;

	SetFontSize(80);
	DrawFormatString(140, 5 + endPosY, 0xff0000, "Thank you for playing!!!");
	SetFontSize(40);
	DrawFormatString(540, 140 + endPosY, 0xffff00, "C�`�[�������o�[");
	SetFontSize(30);
	DrawFormatString(430, 220 + endPosY, 0xf, "���[�_�[ :  ���@����");
	DrawFormatString(620, 280 + endPosY, 0xf, "�{��@�W���X�e�B��");
	DrawFormatString(620, 350 + endPosY, 0xf, "�약�@��");
	DrawFormatString(620, 420 + endPosY, 0xf, "�I���@��T");
	DrawFormatString(620, 480 + endPosY, 0xf, "�ɏW  �B��");
	DrawFormatString(620, 550 + endPosY, 0xf, "�K�n�@����");


	//�^�C�����Z����&�I��
	if (++endWaitTime > 2300)g_GameState = 99;

	if (endWaitTime > 2000) {
		SetFontSize(200);
		DrawFormatString(520, 260, 0xff0000, "END");
	}

}
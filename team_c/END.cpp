#include"END.h"
#include "common.h"
END end;

END::END() {
	count = 0;
	endwaittime = 0;
	endPosY = 0;
	
}

void END::DrawEnd() {
	
	//�G���f�B���O�\��
	if (++endwaittime < 600) endPosY = 300 - endwaittime / 2;

	SetFontSize(80);
	DrawFormatString(140, 5 + endPosY, 0xfffff, "Thank you for playing!!!");
    SetFontSize(50);
	DrawFormatString(640, 170 + endPosY, 0xffffff, "C�`�[�������o�[");
	DrawFormatString(540, 220 + endPosY, 0xffffff, "�����[�_�[�@���@����");
	DrawFormatString(640, 280 + endPosY, 0xffffff, "�{��@�W���X�e�B��");
	DrawFormatString(640, 360 + endPosY, 0xffffff, "�약�@��");
	DrawFormatString(640, 420 + endPosY, 0xffffff, "�I���@��T");
	DrawFormatString(640, 470 + endPosY, 0xffffff, "�ɏW �B��");
	DrawFormatString(640, 520 + endPosY, 0xffffff, "�K�n�@����");

	//�^�C�����Z����&�I��
	if (++endwaittime > 900)g_GameState = 99;

}
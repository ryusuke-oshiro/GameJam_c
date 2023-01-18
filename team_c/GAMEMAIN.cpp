#include"GAMEMAIN.h"

GAMEMAIN gamemain;

GAMEMAIN::GAMEMAIN() {
	phase = 0;
	UpDownCount = 0;
	CPos_x = 0;
	CPos_y = 0;
	Curtain_flg = FALSE;
	Curtain_image = 0;
}

void GAMEMAIN::Init() {
	phase = 0;
	UpDownCount = 0;
	CPos_x = 0;
	CPos_y = 0;
	Curtain_flg = FALSE;
}

void GAMEMAIN::GameMain() {
	switch(phase) {
		case 0:
			hs.DrawCurtain();	//���ꖋ
			break;
		case 1:
			si.DrawImage();		//�\��
			break;
		case 2:
			sn.DrawSN();		//�����I��
			break;
		case 3:
			g_GameState = 0;
		default:
			break;
	}

	DrawGraph(0, -744 + CPos_y, Curtain_image, TRUE);

	if (hs.Get_DispLevelflg() == TRUE && si.Get_Level() <= 10) {
		DrawFormatString(640, 400, 0xff0000, "���x��[ %d ]", si.Get_Level());
		DrawFormatString(640, 430, 0xff0000, "A�ŃX�^�[�g�I");
	}
	if (sn.Get_sn_flg() == TRUE) {
		DrawFormatString(640, 360, 0xff0000, "GameMain::����I��");
		DrawFormatString(640, 400, 0xff0000, "%d", sn.Get_number());
	}
	if (sn.Get_sntext_flg() == TRUE) {
		if (sn.Get_answer() == TRUE) {
			if (si.Get_Level() <= 10) {
				DrawFormatString(640, 360 - 200, 0xffffff, "���x���A�b�v�I");	//������
			}
		}
		if (sn.Get_answer() == FALSE) {
			DrawFormatString(640, 360 - 200, 0xffffff, "���s�A�A�A������%d", si.Get_Answer());	//������
		}
	}
	if (hs.Get_clear_flg() == TRUE) {
		DrawFormatString(640, 360 - 200, 0xffffff, "�S���x���N���A�IA�{�^���Ń^�C�g���ɖ߂�܂�");	//������
	}
}

int GAMEMAIN::DownCurtain() {
	UpDownCount++;
	CPos_y = UpDownCount * 24;
	if (30 < UpDownCount) {
		UpDownCount = 30;
		return true;
	}
}
int GAMEMAIN::UpCurtain() {
	UpDownCount--;
	CPos_y = UpDownCount * 24;
	if (UpDownCount <= 0) {
		UpDownCount = 0;
		return true;
	}
}

void GAMEMAIN::Set_phase(int n) {
	phase = n;
}

int GAMEMAIN::Get_phase() {
	return phase;
}

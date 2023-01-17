#include "DxLib.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"
#define _USE_MATH_DEFINES
#include<math.h>
/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int g_GameState = 1;	//�Q�[�����[�h

int Button_flg = FALSE;
int Time = 0;     //�҂�����
int StartTime;
int NowTime = 0;
int RefreshTime;
double Fps = 0.0;
int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
int color_white;

void FpsTimeFanction();
void SetColor();
/****************************************************
*�v���O�����̊J�n
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{

	SetMainWindowText("Mitukeru");		//�^�C�g����ݒ�

	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1)return -1;		//DX���C�u�����̏���������
	
	SetWindowText("Mitukeru");
	//SetWindowInitPosition(480, 600);
	SetGraphMode(1280, 720, 32);
	
	SetDrawScreen(DX_SCREEN_BACK);			//�`����ʂ𗠂ɂ���
	SetColor();
	while (ProcessMessage() == 0 && g_GameState != 99 && !input.Buttons[XINPUT_BUTTON_BACK]) {
		RefreshTime = GetNowCount();

		GetJoypadXInputState(DX_INPUT_PAD1, &input);

		ClearDrawScreen();			//��ʂ̏�����
		FpsTimeFanction();

		switch (g_GameState) {
		case 0:
			title.DrawTitle();		//�Q�[���^�C�g���`�揈��
			break;
		case 1:
			help.DrawHelp();				//�Q�[���w���v�`�揈��
			break;
		case 2:
			//GameInit();				//�Q�[����������
			break;
		case 3:
			end.DrawEnd();				//�Q�[���G���h�`�揈��
			break;
		case 4:
			//GameMain();				//�Q�[�����C������
			break;
		}
		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f
		while (GetNowCount() - RefreshTime < 17);
	}
	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;	//�\�t�g�̏I��
}

void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g
	if (Fps != 0)
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fps��\��
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //���F�n���h�����擾
	return;
}

//void GameInit(void) {}

/******************************************
*�Q�[�����C��
******************************************/
//void GameMain(void){}
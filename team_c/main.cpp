#include "DxLib.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"
#include"GAMEMAIN.h"
#define _USE_MATH_DEFINES
#include<math.h>
/******************************************************
*�ϐ��錾
*******************************************************/
XINPUT_STATE input;
int g_GameState = 0;	//�Q�[�����[�h

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
void GameInit();
int LoadImages();
int LoadSounds();
/****************************************************
*�v���O�����̊J�n
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{

	SetMainWindowText("�j���g��������");		//�^�C�g����ݒ�

	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1)return -1;		//DX���C�u�����̏���������
	
	SetWindowText("�j���g��������");
	//SetWindowInitPosition(480, 600);
	SetGraphMode(1280, 720, 32);
	
	SetDrawScreen(DX_SCREEN_BACK);			//�`����ʂ𗠂ɂ���
	SetColor();

	if (LoadImages() == -1)return -1;		//�摜�ǂݍ��݊֐����Ăяo��

	if (LoadSounds() == -1)return -1;		//�T�E���h�ǂݍ��݊֐����Ăяo��
	
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
			GameInit();				//�Q�[����������
			break;
		case 3:
			end.DrawEnd();				//�Q�[���G���h�`�揈��
			break;
		case 4:
			gamemain.GameMain();				//�Q�[�����C������
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
		DrawFormatString(1150, 700, color_white, "FPS %.1f", Fps); //fps��\��
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //���F�n���h�����擾
	return;
}

void GameInit(void) {
	gamemain.Init();
	hs.Init();
	si.Init();
	sn.Init();
	g_GameState = 4;
}

int LoadImages()
{
	if ((si.BackGround_image = LoadGraph("images/BackGround01.png")) == -1)return -1;
	if ((si.DispImage[0] = LoadGraph("images/chara01.png")) == -1) return -1;
	if ((si.DispImage[1] = LoadGraph("images/chara02.png")) == -1) return -1;
	if ((si.DispImage[2] = LoadGraph("images/chara03.png")) == -1) return -1;
	if ((si.DispImage[3] = LoadGraph("images/chara04.png")) == -1) return -1;
	if ((si.DispImage[4] = LoadGraph("images/chara05.png")) == -1) return -1;
	if ((si.DispImage[5] = LoadGraph("images/chara06.png")) == -1) return -1;
	if ((gamemain.Curtain_image = LoadGraph("images/Curtain.png")) == -1)return -1;
	if ((gamemain.Good_image = LoadGraph("images/good.png")) == -1)return -1;
	if ((gamemain.GameOver_image = LoadGraph("images/gameover.png")) == -1)return -1;
	if ((gamemain.Clear_image = LoadGraph("images/Clear.png")) == -1)return -1;
	if ((gamemain.ATitle_image = LoadGraph("images/A_Title.png")) == -1)return -1;
	if ((gamemain.Button_image1 = LoadGraph("images/Button1.png")) == -1)return -1;
	if ((gamemain.Button_image2 = LoadGraph("images/Button2.png")) == -1)return -1;
	if ((title.Title_image = LoadGraph("images/Title.png")) == -1) return -1;
	if ((end.endImages = LoadGraph("images/BackGround02.png")) == -1) return -1;
	if ((hs.GameStart_image = LoadGraph("images/GameStart.png")) == -1) return -1;
	if ((help.Help_image = LoadGraph("images/Help.png")) == -1) return -1;
	return 0;
}

int LoadSounds()
{
	// �^�C�g��BGM�̓Ǎ�
	if ((title.Title_bgm = LoadSoundMem("sounds/BGM/Title_BGM.wav")) == -1) return -1;
	// �Q�[��BGM�̓Ǎ�
	if ((gamemain.Game_bgm = LoadSoundMem("sounds/BGM/Main_BGM.wav")) == -1) return -1;
	// �Q�[���N���ASE�̓Ǎ�
	if ((sn.GameClear_se = LoadSoundMem("sounds/SE/clear.wav")) == -1) return -1;
	// �Q�[���I�[�o�[SE�̓Ǎ�
	if ((sn.GameOver_se = LoadSoundMem("sounds/SE/gameover03.wav")) == -1) return -1;

	//�j���g���̖����̓ǂݍ���
	if ((hs.Chicken_se1 = LoadSoundMem("sounds/SE/chicken1.wav")) == -1) return -1; //�R�P�R�b�R�[
	if ((hs.Chicken_se2 = LoadSoundMem("sounds/SE/chicken2.wav")) == -1) return -1; //�R�b�R
	if ((hs.Chicken_se3 = LoadSoundMem("sounds/SE/chicken3.wav")) == -1) return -1; //�R�P�[

	// �^�C�g��SE�̓Ǎ�
	if ((title.SE1 = LoadSoundMem("sounds/SE/button_a.wav")) == -1) return -1;
	// SE1�̓Ǎ�
	if ((sn.SE2 = LoadSoundMem("sounds/SE/sn.wav")) == -1) return -1;

	//BGM�̉��ʒ���
	ChangeVolumeSoundMem(150, title.Title_bgm);
	ChangeVolumeSoundMem(130, gamemain.Game_bgm);

	// SE�̉��ʒ���
	ChangeVolumeSoundMem(240, sn.GameClear_se);
	ChangeVolumeSoundMem(240, sn.GameOver_se);
	ChangeVolumeSoundMem(200, title.SE1);
	ChangeVolumeSoundMem(500, sn.SE2);
	return 0;
}
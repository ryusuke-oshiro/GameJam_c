#include "DxLib.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"
#include"GAMEMAIN.h"
#define _USE_MATH_DEFINES
#include<math.h>
/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int g_GameState = 0;	//ゲームモード

int Button_flg = FALSE;
int Time = 0;     //待ち時間
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
*プログラムの開始
******************************************************/
int WINAPI WinMain(_In_ HINSTANCE hInssance, _In_opt_ HINSTANCE
	hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nCmdShow)
{

	SetMainWindowText("Mitukeru");		//タイトルを設定

	ChangeWindowMode(TRUE);					//ウィンドウモードで起動

	if (DxLib_Init() == -1)return -1;		//DXライブラリの初期化処理
	
	SetWindowText("Mitukeru");
	//SetWindowInitPosition(480, 600);
	SetGraphMode(1280, 720, 32);
	
	SetDrawScreen(DX_SCREEN_BACK);			//描画先画面を裏にする
	SetColor();

	if (LoadImages() == -1)return -1;		//画像読み込み関数を呼び出し

	if (LoadSounds() == -1)return -1;		//サウンド読み込み関数を呼び出し
	
	while (ProcessMessage() == 0 && g_GameState != 99 && !input.Buttons[XINPUT_BUTTON_BACK]) {
		RefreshTime = GetNowCount();

		GetJoypadXInputState(DX_INPUT_PAD1, &input);

		ClearDrawScreen();			//画面の初期化
		FpsTimeFanction();

		switch (g_GameState) {
		case 0:
			title.DrawTitle();		//ゲームタイトル描画処理
			break;
		case 1:
			help.DrawHelp();				//ゲームヘルプ描画処理
			break;
		case 2:
			GameInit();				//ゲーム初期処理
			break;
		case 3:
			end.DrawEnd();				//ゲームエンド描画処理
			break;
		case 4:
			gamemain.GameMain();				//ゲームメイン処理
			break;
		}
		ScreenFlip();	//裏画面の内容を表画面に反映
		while (GetNowCount() - RefreshTime < 17);
	}
	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;	//ソフトの終了
}

void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(1150, 700, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //白色ハンドルを取得
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
	if ((title.Title_image = LoadGraph("images/Title.png")) == -1) return -1;
	if ((end.endImages = LoadGraph("images/BackGround02.png")) == -1) return -1;
	if ((hs.GameStart_image = LoadGraph("images/GameStart.png")) == -1) return -1;
	return 0;
}

int LoadSounds()
{
	// タイトルBGMの読込
	if ((title.Title_bgm = LoadSoundMem("sounds/BGM/逃げろ!ひつじの大群だ!_2.mp3")) == -1) return -1;
	// ゲームBGMの読込
	if ((gamemain.Game_bgm = LoadSoundMem("sounds/BGM/どた☆ばたコミック！.mp3")) == -1) return -1;
	// ゲームクリアSEの読込
	if ((sn.GameClear_se = LoadSoundMem("sounds/SE/clear.mp3")) == -1) return -1;
	// ゲームオーバーSEの読込
	if ((sn.GameOver_se = LoadSoundMem("sounds/SE/gameover03.mp3")) == -1) return -1;

	// タイトルSEの読込
	if ((title.SE1 = LoadSoundMem("sounds/SE/button_a.mp3")) == -1) return -1;
	// SE1の読込
	if ((sn.SE2 = LoadSoundMem("sounds/SE/sn.mp3")) == -1) return -1;

	// SEの音量調整
	ChangeVolumeSoundMem(1000, sn.GameClear_se);
	ChangeVolumeSoundMem(1000, sn.GameOver_se);
	ChangeVolumeSoundMem(1000, title.SE1);
	ChangeVolumeSoundMem(1000, sn.SE2);
	return 0;
}
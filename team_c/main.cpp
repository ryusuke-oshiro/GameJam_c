#include "DxLib.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"
#define _USE_MATH_DEFINES
#include<math.h>
/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int g_GameState = 1;	//ゲームモード

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
			//GameInit();				//ゲーム初期処理
			break;
		case 3:
			end.DrawEnd();				//ゲームエンド描画処理
			break;
		case 4:
			//GameMain();				//ゲームメイン処理
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
		DrawFormatString(565, 460, color_white, "FPS %.1f", Fps); //fpsを表示
	return;
}

void SetColor() {
	color_white = GetColor(255, 255, 255);            //白色ハンドルを取得
	return;
}

//void GameInit(void) {}

/******************************************
*ゲームメイン
******************************************/
//void GameMain(void){}
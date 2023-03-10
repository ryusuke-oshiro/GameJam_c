#include"hanging_screen.h"

#define CHARA_SIZE 100

hanging_screen hs;

hanging_screen::hanging_screen() {
	Pos_x = 640;
	Pos_y = 360;
	fhase_flg = FALSE;
	DispLevelflg = FALSE;
	Count = 0;
	levelup_count = 0;
	flg = FALSE;
	Circle_flg = TRUE;
	Clear_flg = FALSE;
	GameStart_image = 0;
	Chicken_se1 = 0;
	Chicken_se2 = 0;
	Chicken_se3 = 0;
	soundflg = FALSE;
}

void hanging_screen::Init() {
	Pos_x = 640;
	Pos_y = 360;
	fhase_flg = FALSE;
	DispLevelflg = FALSE;
	Count = 0;
	levelup_count = 0;
	flg = FALSE;
	Circle_flg = TRUE;
	soundflg = FALSE;
}

void hanging_screen::DrawCurtain() {
	if (si.Get_Level() == 1) {

		DrawGraph(0, 0, GameStart_image, FALSE);
		if (sn.Get_answer() == TRUE) {		//タイトルからレベル１で来た時
			Count++;

			if (180 < Count) {
				if (gamemain.DownCurtain() == true) {
					StopSoundMem(hs.Chicken_se2);
					DispLevelflg = TRUE;
					fhase_flg = TRUE;
				}
			}
			if (input.Buttons[12] == 1 && fhase_flg == true) {
				Count = 0;
				DispLevelflg = FALSE;
				fhase_flg = FALSE;
				si.Set_DispCount(si.Get_Level());	//ステージレベルから表示個数をきめる
				gamemain.Set_phase(1);
			}
		}

		if (sn.Get_answer() == FALSE) {		//レベル１で失敗して来た時
			DrawGraph(0, 0 + gamemain.Get_CPos_y(), si.BackGround_image, FALSE);
			for (int i = 0; i < si.DispTargetCount; i++) {
				DrawExtendGraph(si.DispTargetPos[i][0] - (CHARA_SIZE / 2), si.DispTargetPos[i][1] - (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
					si.DispTargetPos[i][0] + (CHARA_SIZE / 2), si.DispTargetPos[i][1] + (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
					si.DispImage[0], TRUE);
			}
			for (int j = 0; j < si.DispAllCount - si.DispTargetCount; j++) {
				DrawExtendGraph(si.DispElsePos[j][0] - (CHARA_SIZE / 2), si.DispElsePos[j][1] - (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
					si.DispElsePos[j][0] + (CHARA_SIZE / 2), si.DispElsePos[j][1] + (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
					si.DispImage[si.DispElsePos[j][3]], TRUE);
			}
			if (Circle_flg == TRUE) {
				for (int i = 0; i < si.DispTargetCount; i++) {
					DrawCircle(si.DispTargetPos[i][0] - 5, si.DispTargetPos[i][1] + gamemain.Get_CPos_y() + 3 ,
						CHARA_SIZE / 2, 0xff0000, FALSE,TRUE);
				}
			}

			if (flg == FALSE) {
				if (gamemain.UpCurtain() == true) {
					levelup_count++;
					if (levelup_count % 20 == 0) {
						Circle_flg = !Circle_flg;
					}
					if (120 < levelup_count) {
						levelup_count = 0;
						flg = TRUE;
					}
				}
			}
			if (flg == TRUE) {
				fhase_flg = true;
				DrawGraph(880, 178, gamemain.ATitle_image, TRUE);
				if (input.Buttons[12] == 1 && fhase_flg == true) {
					fhase_flg = FALSE;
					flg = FALSE;
					gamemain.Set_phase(3);
				}
			}
		}
	}

	if(si.Get_Level() != 1){	//レベル１以外できた時
		/*SetFontSize(24);*/
		
		
		DrawGraph(0, 0 + gamemain.Get_CPos_y(), si.BackGround_image, FALSE);

		for (int i = 0; i < si.DispTargetCount; i++) {
			DrawExtendGraph(si.DispTargetPos[i][0] - (CHARA_SIZE / 2), si.DispTargetPos[i][1] - (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
				si.DispTargetPos[i][0] + (CHARA_SIZE / 2), si.DispTargetPos[i][1] + (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
				si.DispImage[0], TRUE);
		}
		for (int j = 0; j < si.DispAllCount - si.DispTargetCount; j++) {
			DrawExtendGraph(si.DispElsePos[j][0] - (CHARA_SIZE / 2), si.DispElsePos[j][1] - (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
				si.DispElsePos[j][0] + (CHARA_SIZE / 2), si.DispElsePos[j][1] + (CHARA_SIZE / 2) + gamemain.Get_CPos_y(),
				si.DispImage[si.DispElsePos[j][3]], TRUE);
		}
		if (Circle_flg == TRUE) {
			for (int i = 0; i < si.DispTargetCount; i++) {
				DrawCircle(si.DispTargetPos[i][0] - 5, si.DispTargetPos[i][1] + gamemain.Get_CPos_y() + 3 ,
					CHARA_SIZE / 2, 0xff0000, FALSE, TRUE);
			}
		}

		if (flg == FALSE) {
			if (gamemain.UpCurtain() == true) {
				levelup_count++;
				if (levelup_count % 20 == 0) {
					Circle_flg = !Circle_flg;
				}
				if (120 < levelup_count) {
					levelup_count = 0;
					flg = TRUE;
				}
			}
		}

		if (sn.Get_answer() == TRUE) {		//成功してたら
			if (flg == TRUE) {
				sn.Set_st_flg(FALSE);
				if (gamemain.DownCurtain() == true) {
					DispLevelflg = TRUE;
					fhase_flg = true;
				}
				if (10 >= si.Get_Level()) {
					if (input.Buttons[12] == 1 && fhase_flg == true) {
						DispLevelflg = FALSE;
						fhase_flg = FALSE;
						flg = FALSE;
						si.Set_DispCount(si.Get_Level());	//ステージレベルから表示個数をきめる
						gamemain.Set_phase(1);
					}
				}
				if (10 < si.Get_Level()) {
					Clear_flg = TRUE;
					if (CheckSoundMem(hs.Chicken_se1) == 0 && soundflg == FALSE) {
						PlaySoundMem(hs.Chicken_se1, DX_PLAYTYPE_BACK, TRUE);
						soundflg = TRUE;
					}
					if (input.Buttons[12] == 1 && fhase_flg == true) {
						Clear_flg = FALSE;
						gamemain.Set_phase(3);
					}
				}
			}
		}
		if(sn.Get_answer()==FALSE){			//失敗してたら
			if (flg == TRUE) {
				fhase_flg = true;
				DrawGraph(880, 178, gamemain.ATitle_image, TRUE);
				if (input.Buttons[12] == 1 && fhase_flg == true) {	//ボタン待ち
					fhase_flg = FALSE;
					flg = FALSE;
					gamemain.Set_phase(3);
				}
			}
		}
	}
}

#include"END.h"
#include "common.h"
END end;

END::END() {
	count = 0;
	endwaittime = 0;
	endPosY = 0;

}

void END::DrawEnd() {

	//エンディング表示
	if (++endwaittime < 2300) endPosY = 300 - endwaittime / 2;

	SetFontSize(80);
	DrawFormatString(140, 5 + endPosY, 0xfffff, "Thank you for playing!!!");
	SetFontSize(40);
	DrawFormatString(580, 160 + endPosY, 0xffd700, "Cチームメンバー");
	SetFontSize(30);
	DrawFormatString(430, 220 + endPosY, 0xffffff, "リーダー :  大城　竜輔");
	DrawFormatString(620, 280 + endPosY, 0xffffff, "宮城　ジャスティン");
	DrawFormatString(620, 350 + endPosY, 0xffffff, "川平　花");
	DrawFormatString(620, 420 + endPosY, 0xffffff, "棚原　千裕");
	DrawFormatString(620, 480 + endPosY, 0xffffff, "伊集  唯華");
	DrawFormatString(620, 550 + endPosY, 0xffffff, "幸地　涼耶");


	//タイム加算処理&終了
	if (++endwaittime > 2300)g_GameState = 99;

	if (endwaittime > 2000) {
		SetFontSize(200);
		DrawFormatString(520, 260, 0xffd700, "END");
	}



}
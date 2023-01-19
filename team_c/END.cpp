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
	if (++endwaittime < 600) endPosY = 300 - endwaittime / 2;

	SetFontSize(80);
	DrawFormatString(140, 5 + endPosY, 0xfffff, "Thank you for playing!!!");
    SetFontSize(50);
	DrawFormatString(640, 170 + endPosY, 0xffffff, "Cチームメンバー");
	DrawFormatString(540, 220 + endPosY, 0xffffff, "☆リーダー　大城　竜輔");
	DrawFormatString(640, 280 + endPosY, 0xffffff, "宮城　ジャスティン");
	DrawFormatString(640, 360 + endPosY, 0xffffff, "川平　花");
	DrawFormatString(640, 420 + endPosY, 0xffffff, "棚原　千裕");
	DrawFormatString(640, 470 + endPosY, 0xffffff, "伊集 唯華");
	DrawFormatString(640, 520 + endPosY, 0xffffff, "幸地　涼耶");

	//タイム加算処理&終了
	if (++endwaittime > 900)g_GameState = 99;

}
#include"END.h"

END end;

END::END() {
	count = 0;
}

void END::DrawEnd() {
	count++;
	SetFontSize(100);
	DrawFormatString(640, 360, 0xffffff, "E N D");
	if (180 < count) {
		g_GameState = 99;
	}
}
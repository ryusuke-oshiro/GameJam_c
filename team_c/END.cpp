#include"END.h"
END end;

END::END() {

}

void END::DrawEnd() {
	SetFontSize(100);
	DrawFormatString(640, 360, 0xffffff, "E N D");
}
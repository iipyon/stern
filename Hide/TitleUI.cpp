#include "TitleUI.h"

TitleUI::TitleUI()
{
	text[0].str = "Game Start";
	text[1].str = "Exit";
	for (int i = 0; i < 2; ++i) {
		text[i].text_width = get_width(text[i]);
		text[i].x = 300 - text[i].text_width / 2;
		text[i].y = 340 + 50 * i;
	}
}

void TitleUI::update()
{
	for (int i = 0; i < 2; ++i) {
		update_txt(text[i]);
	}
}

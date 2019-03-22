#include "TitleStartButton.h"

TitleStartButton::TitleStartButton()
{
	y = 400;
	get_width((char*)"Game Start");
}

void TitleStartButton::update()
{
	update_txt("Game Start");
}

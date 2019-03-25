#include "TitleExitButton.h"

TitleExitButton::TitleExitButton()
{
	y = 450;
	get_width("Exit");
}

void TitleExitButton::update()
{
	update_txt("Exit");
}
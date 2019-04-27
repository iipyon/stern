#include "TitleSelecter.h"
#include"Audio.h"
#include"DxLib.h"
#include"Keyboard.h"

TitleSelecter::TitleSelecter()
{
	x = 0;
	y = 0;
	button = Button::start;
	graph = LoadGraph("img/title/selecter.png");
}

void TitleSelecter::update(int start_x,int exit_x,bool deg)
{
	switch_button(deg);
	move(start_x, exit_x);
	draw();
}

void TitleSelecter::draw()
{
	DrawGraph(x, y, graph, TRUE);
}

void TitleSelecter::switch_button(bool deg)
{
	if (!deg) {
		//集成必要な気がする-----------------------------------
		if (Keyboard::key_down(KEY_INPUT_DOWN)) {
			Audio::play("cursol");
			if (button == Button::start) button = Button::exit;
			else button = Button::start;
		}
		if (Keyboard::key_down(KEY_INPUT_UP)) {
			Audio::play("cursol");
			if (button == Button::start) button = Button::exit;
			else button = Button::start;
		}
		//-----------------------------------------------------
	}
}

void TitleSelecter::move(int start_x, int exit_x)
{
	switch (button) {
	case Button::start:
		x = start_x;
		y = 340 - 10;
		break;
	case Button::exit:
		x = exit_x;
		y = 390 - 10;
		break;
	}
}

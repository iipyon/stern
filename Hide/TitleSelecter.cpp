﻿#include "TitleSelecter.h"
#include "CoreTask.h"

TitleSelecter::TitleSelecter()
{
	x = 0;
	y = 0;
	button = Button::start;
	graph = LoadGraph("img/title/selecter.png");
}

void TitleSelecter::update(int start_x,int exit_x)
{
	switch_button();
	move(start_x, exit_x);
	draw();
}

void TitleSelecter::draw()
{
	DrawGraph(x, y, graph, TRUE);
}

void TitleSelecter::switch_button()
{
	//集成必要な気がする-----------------------------------
	if (ct->keyboard->key_down(KEY_INPUT_DOWN)) {
		if (button == Button::start) button = Button::exit;
		else button = Button::start;
	}
	if (ct->keyboard->key_down(KEY_INPUT_UP)) {
		if (button == Button::start) button = Button::exit;
		else button = Button::start;
	}
	//-----------------------------------------------------
}

void TitleSelecter::move(int start_x, int exit_x)
{
	switch (button) {
	case Button::start:
		x = start_x;
		y = 390;
		break;
	case Button::exit:
		x = exit_x;
		y = 440;
		break;
	}
}
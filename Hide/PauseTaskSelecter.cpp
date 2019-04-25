#include "PauseTaskSelecter.h"
#include "CoreTask.h"

PauseSelecter::PauseSelecter()
{
	x = 0;
	y = 0;
	button = PauseButton::returngame;
	graph = LoadGraph("img/pause/selecter.png");
}

void PauseSelecter::update(int return_x, int exit_x, int backssts_x)
{
	switch_button();
	move(return_x, exit_x,backssts_x);
	draw();
}

void PauseSelecter::draw()
{
	DrawGraph(x, y, graph, TRUE);
}

void PauseSelecter::switch_button()
{
	//集成必要な気がする-----------------------------------
	if (ct->keyboard->key_down(KEY_INPUT_DOWN)) {
		ct->audio->play("cursol");
		if (button == PauseButton::returngame) button = PauseButton::backssts;
		else if (button == PauseButton::exit) button = PauseButton::returngame;
		else button = PauseButton::exit;
	}
	if (ct->keyboard->key_down(KEY_INPUT_UP)) {
		ct->audio->play("cursol");
		if (button == PauseButton::returngame) button = PauseButton::exit;
		else if (button == PauseButton::exit) button = PauseButton::backssts;
		else button = PauseButton::returngame;
	}
	//-----------------------------------------------------
}

void PauseSelecter::move(int returngame_x, int exit_x,int backssts_x)
{
	switch (button) {
	case PauseButton::returngame:
		x = returngame_x;
		y = 340 - 10;
		break;
	case PauseButton::backssts:
		x = exit_x;
		y = 390 - 10;
		break;
	case PauseButton::exit:
		x = backssts_x;
		y = 440 - 10;
		break;
	}
}

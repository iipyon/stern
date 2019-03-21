#include "TitleTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	startbutton = std::make_unique<TitleStartButton>();
	exitbutton = std::make_unique<TitleExitButton>();
	selecter = std::make_unique<TitleSelecter>();
	backgraph = LoadGraph("img/title/title.png");
}

void TitleTaskSystem::update()
{
	if (ct->keyboard->key_down(KEY_INPUT_Z)) {
		switch (selecter->button) {
		case Button::start:
			ct->scene = Scene::stageselect;
			break;
		case Button::exit:
			//exeを閉じる
			break;
		}
	}

	draw();
	startbutton->update();
	exitbutton->update();
	//カーソルの大きさが40のため余裕をもってあけておく
	selecter->update(startbutton->get_lextx() - 50, exitbutton->get_lextx() - 50);
	DrawString(0, 0, "現在タイトルタスクです", GetColor(255, 0, 0));
}

void TitleTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}

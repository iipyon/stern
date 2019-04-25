#include "TitleTaskSystem.h"
#include"DxLib.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	title_ui = std::make_unique<TitleUI>();
	selecter = std::make_unique<TitleSelecter>();
	backgraph = LoadGraph("img/title/title.png");
	deg_flag = false;
	feedcnt = 255;
}

void TitleTaskSystem::update()
{
	if (deg_flag) {
		feedcnt -= 12;
		SetDrawBright(feedcnt, feedcnt, feedcnt);
	}
	if (Keyboard::key_down(KEY_INPUT_Z)) {
		deg_flag = true;
		Audio::play("decision");
	}
	if (feedcnt <= 0) {
		feedcnt = 255;
		deg_flag = false;
		SetDrawBright(feedcnt, feedcnt, feedcnt);
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
	title_ui->update();
	//カーソルの大きさが40のため余裕をもってあけておく
	selecter->update(title_ui->get_lextx(title_ui->text[0]) - 50, title_ui->get_lextx(title_ui->text[1]) - 50);
}

void TitleTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}

#include "TitleTaskSystem.h"
#include"CoreTask.h"
#include"System.h"
#include"DxLib.h"
#include"Screen_helper.h"

int TitleTaskSystem::backgraph;
bool TitleTaskSystem::deg_flag;
int TitleTaskSystem::feedcnt;
std::unique_ptr<TitleUI> TitleTaskSystem::title_ui;

void TitleTaskSystem::init()
{
	title_ui = std::make_unique<TitleUI>();
	backgraph = LoadGraph("img/title/title.png");
	deg_flag = false;
	feedcnt = 255;
	title_ui->init();
}

void TitleTaskSystem::update()
{
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	if (deg_flag) {
		if(ScreenFunc::FeedOut(deg_flag, feedcnt)){
			change_scene();
		}
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && !deg_flag) {
		deg_flag = true;
		Audio::play("decision");
	}

	draw();
	selecter_move();
	title_ui->update();
	//カーソルの大きさが40のため余裕をもってあけておく
}

void TitleTaskSystem::finalize()
{
	DeleteGraph(backgraph);
}

void TitleTaskSystem::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	//DrawGraph(0, 0, backgraph, FALSE);
}



void TitleTaskSystem::selecter_move()
{
	if (Keyboard::key_down(KEY_INPUT_DOWN)) {
		switch (title_ui->getter()) {
		case Button::start:
			title_ui->change_Select(Button::exit);
			break;
		case Button::exit:
			title_ui->change_Select(Button::start);
			break;
		}
	}
	if (Keyboard::key_down(KEY_INPUT_UP)) {
		switch (title_ui->getter()) {
		case Button::start:
			title_ui->change_Select(Button::exit);
			break;
		case Button::exit:
			title_ui->change_Select(Button::start);
			break;
		}
	}
}

void TitleTaskSystem::change_scene()
{
	switch (title_ui->getter()) {
	case Button::start:
		ct->change_scene(Scene::stageselect);
		break;
	case Button::exit:
		//exe終了
		break;
	}
}

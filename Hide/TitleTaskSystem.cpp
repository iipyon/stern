#include "TitleTaskSystem.h"
#include"CoreTask.h"
#include"System.h"
#include"DxLib.h"
#include"Screen_helper.h"
#include"screenhelper_config.h"

int TitleTaskSystem::backgraph;
bool TitleTaskSystem::feed_flag;
std::unique_ptr<TitleUI> TitleTaskSystem::title_ui;

void TitleTaskSystem::init()
{
	title_ui = std::make_unique<TitleUI>();
	backgraph = LoadGraph("img/title/title.png");
	feed_flag = false;
	title_ui->init();
}

void TitleTaskSystem::init_member()
{
	feed_flag = false;
	title_ui->init();
}

void TitleTaskSystem::update()
{
	draw();
	//フェードアウト開始していないなら動かせる
	if (feed_flag == false) {
		selecter_move();
	}
	title_ui->update();

	if (feed_flag) {//フェードアウトの指示が来たら
		//暗くしていく(黒)
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			feed_flag = false;
			change_scene();
		}
	}
	else {//指示が来ていないなら
		//黒を透明にする
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && !feed_flag) {
		feed_flag = true;
		Audio::play("decision");
	}
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

#include "PauseTaskSystem.h"
#include"CoreTask.h"
#include"System.h"
#include"Screen_helper.h"
#include"DxLib.h"

//UIクラス
std::unique_ptr<PauseUI> PauseTask::p_ui;

int PauseTask::backgraph;//背景
int PauseTask::feedcnt;
bool PauseTask::deg_flag;

void PauseTask::initialize()
{
	p_ui = std::make_unique<PauseUI>();
	backgraph = LoadGraph("img/pause/pause.png");
	feedcnt = 0;
	deg_flag = false;
}

void PauseTask::update()
{
	ScreenFunc::FeedIn(deg_flag,feedcnt);
	if (Keyboard::key_down(KEY_INPUT_Z) && !deg_flag) {
		Audio::play("decision");
		deg_flag = true;
	}
	if (deg_flag) {
		if (ScreenFunc::FeedOut(deg_flag, feedcnt)) {
			change_scene();
		}
	}
	draw();
	selecter_move();
	p_ui->update();
}

void PauseTask::finalize()
{
	DeleteGraph(backgraph);
}

void PauseTask::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	//DrawGraph(0, 0, backgraph, FALSE);//背景
}

void PauseTask::change_scene()
{
	//ゲームに戻る
	switch (p_ui->getter()) {
	case PauseButton::returngame:
		ct->change_scene(Scene::game);//ゲームシーンに遷移
		break;
	case PauseButton::exit:
		//アプリケーション終了
		break;
	case PauseButton::backssts:
		ct->gts->finalize();
		ct->change_scene(Scene::stageselect);
		break;
	}
	
}

void PauseTask::selecter_undermove()
{
	switch (p_ui->getter()) {
	case PauseButton::returngame:
		p_ui->change_Select(PauseButton::backssts);
		break;
	case PauseButton::backssts:
		p_ui->change_Select(PauseButton::exit);
		break;
	case PauseButton::exit:
		p_ui->change_Select(PauseButton::returngame);
		break;
	}
}

void PauseTask::selecter_upmove()
{
	switch (p_ui->getter()) {
	case PauseButton::returngame:
		p_ui->change_Select(PauseButton::exit);
		break;
	case PauseButton::backssts:
		p_ui->change_Select(PauseButton::returngame);
		break;
	case PauseButton::exit:
		p_ui->change_Select(PauseButton::backssts);
		break;
	}
}

void PauseTask::selecter_move()
{
	if (Keyboard::key_down(KEY_INPUT_DOWN)) {
		selecter_undermove();
	}
	if (Keyboard::key_down(KEY_INPUT_UP)) {
		selecter_upmove();
	}
}

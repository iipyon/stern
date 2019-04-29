#include "PauseTaskSystem.h"
#include"CoreTask.h"

PauseTask::PauseTask()
{
	p_selecter = std::make_unique<PauseSelecter>();
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
	p_selecter->update(p_ui->get_lextx(p_ui->text[0]) - 50,
					   p_ui->get_lextx(p_ui->text[1]) - 50,
					   p_ui->get_lextx(p_ui->text[2]) - 50,
					   deg_flag);
	p_ui->update();
}

void PauseTask::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);//背景
}

void PauseTask::change_scene()
{
	//ゲームに戻る
	switch (p_selecter->button) {
	case PauseButton::returngame:
		ct->scene = Scene::game;//ゲームシーンに遷移
		break;
	case PauseButton::exit:
		//アプリケーション終了
		break;
	case PauseButton::backssts:
		ct->gts->finalize();
		ct->scene = Scene::stageselect;
		break;
	}
	
}

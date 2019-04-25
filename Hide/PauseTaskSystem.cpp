#include "PauseTaskSystem.h"
#include"DxLib.h"
#include"Keyboard.h"
#include"CoreTask.h"
#include"Audio.h"

PauseTask::PauseTask()
{
	p_selecter = std::make_unique<PauseSelecter>();
	p_ui = std::make_unique<PauseUI>();
	feedcnt = 255;
	backgraph = LoadGraph("img/pause/pause.png");
	deg_flag = false;
}

void PauseTask::update()
{
	if (Keyboard::key_down(KEY_INPUT_X)) {

		Audio::play("decision");

		deg_flag = true;
	}
	if (deg_flag) {
		feedcnt -= 12;
		SetDrawBright(feedcnt, feedcnt, feedcnt);
		if (feedcnt <= 0) {
			feedcnt = 255;
			deg_flag = false;
			SetDrawBright(feedcnt, feedcnt, feedcnt);
			change_scene();
		}
	}
	draw();
	p_selecter->update(p_ui->get_lextx(p_ui->text[0]) - 50,
					   p_ui->get_lextx(p_ui->text[1]) - 50,
					   p_ui->get_lextx(p_ui->text[2]) - 50);
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
		ct->scene = Scene::stageselect;
		break;
	}
	
}

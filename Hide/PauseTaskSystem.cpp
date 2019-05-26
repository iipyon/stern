#include "PauseTaskSystem.h"
#include"CoreTask.h"
#include"System.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include"DxLib.h"
#include "Scene.h"
#include "Keyboard.h"
#include "Audio.h"

//UIクラス
std::unique_ptr<PauseUI> PauseTask::p_ui;

int PauseTask::backgraph;//背景
bool PauseTask::feed_flag;

void PauseTask::initialize()
{
	p_ui = std::make_unique<PauseUI>();
	backgraph = LoadGraph("img/pause/pause.png");
}

void PauseTask::init_member()
{
	feed_flag = false;
}

void PauseTask::update()
{
	draw();
	selecter_move();
	p_ui->update();
	if (Keyboard::key_down(KEY_INPUT_Z) && !feed_flag) {
		Audio::play("decision");
		feed_flag = true;
	}
	if (feed_flag) {
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			change_scene();
		}
	}
	else {
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}
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
		Scene::set_scene(SceneType::game); // ゲームシーンに遷移
		break;
	case PauseButton::exit:
		PauseTask::finalize();
		break;
		//アプリケーション終了
		break;
	case PauseButton::backssts:
		ct->gts->finalize();
		Scene::set_scene(SceneType::stageselect);
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

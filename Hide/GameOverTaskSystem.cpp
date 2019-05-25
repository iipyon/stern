#include "CoreTask.h"
#include "GameOverTaskSystem.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include"Keyboard.h"
#include"System.h"

int GameOverTaskSystem::backGraph;//背景

bool GameOverTaskSystem::feed_flag;

std::unique_ptr<GameOverUI> GameOverTaskSystem::gameover_ui;

void GameOverTaskSystem::init_member()
{
	feed_flag = false;
}

void GameOverTaskSystem::initialize()
{
	gameover_ui = std::make_unique<GameOverUI>();
	backGraph = LoadGraph("./img/gameover/gameover.png");
	feed_flag = false;
}

void GameOverTaskSystem::update()
{
	//コンテニュー時敵の生成、アイテムの生成、ステージセレクトのupdateで行っている処理のほとんどを行うため
	//spawnをCoreに移す必要がある？
	if (Keyboard::key_down(KEY_INPUT_Z) && !feed_flag) {
		feed_flag = true;
		Audio::play("decision");
	}
	draw();
	selecter_move();
	gameover_ui->update();
	if (feed_flag) {
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			change_scene();
		}
	}
	else {
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}
}

void GameOverTaskSystem::finalize()
{
	DeleteGraph(backGraph);
}

void GameOverTaskSystem::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, backGraph, FALSE);
	//DrawGraph(0, 0, backGraph, FALSE);
}

void GameOverTaskSystem::selecter_move()
{
	if (Keyboard::key_down(KEY_INPUT_DOWN)) {
		selecter_undermove();
	}
	if (Keyboard::key_down(KEY_INPUT_UP)) {
		selecter_upmove();
	}
}


//もっと効率化できるかも知れない--------------------------------
void GameOverTaskSystem::selecter_undermove()
{
	switch (gameover_ui->getter()) {
	case SelectMode::Continue:
		gameover_ui->change_Select(SelectMode::StageSelect);
		break;
	case SelectMode::StageSelect:
		gameover_ui->change_Select(SelectMode::Title);
		break;
	case SelectMode::Title:
		gameover_ui->change_Select(SelectMode::Continue);
		break;
	}
}

void GameOverTaskSystem::selecter_upmove()
{
	switch (gameover_ui->getter()) {
	case SelectMode::Continue:
		gameover_ui->change_Select(SelectMode::Title);
		break;
	case SelectMode::StageSelect:
		gameover_ui->change_Select(SelectMode::Continue);
		break;
	case SelectMode::Title:
		gameover_ui->change_Select(SelectMode::StageSelect);
		break;
	}
}
void GameOverTaskSystem::change_scene()
{
	switch (gameover_ui->getter()) {
	case SelectMode::Continue:
		ct->change_scene(Scene::game);
		break;
	case SelectMode::StageSelect:
		ct->change_scene(Scene::stageselect);
		break;
	case SelectMode::Title:
		ct->change_scene(Scene::title);
		break;
	}
}
//-------------------------------------------------------------------------
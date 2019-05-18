#include "CoreTask.h"
#include "GameOverTaskSystem.h"
#include"Keyboard.h"

GameOverTaskSystem::GameOverTaskSystem()
{
	gameover_ui = std::make_unique<GameOverUI>();
	backGraph = LoadGraph("./img/gameover/gameover.png");
	deg_flag = false;
	feedcnt = 255;
}

void GameOverTaskSystem::init()
{
	feedcnt = 255;
	deg_flag = false;
}

void GameOverTaskSystem::update()
{
	//コンテニュー時敵の生成、アイテムの生成、ステージセレクトのupdateで行っている処理のほとんどを行うため
	//spawnをCoreに移す必要がある？
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	if (deg_flag) {
		if (ScreenFunc::FeedOut(deg_flag, feedcnt)) {
			change_scene();
		}
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && !deg_flag) {
		deg_flag = true;
		Audio::play("decision");
	}
	draw();
	selecter_move();
	gameover_ui->update();
}

void GameOverTaskSystem::draw()
{
	DrawGraph(0, 0, backGraph, FALSE);
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
		ct->scene = Scene::game;
		break;
	case SelectMode::StageSelect:
		ct->scene = Scene::stageselect;
		break;
	case SelectMode::Title:
		ct->scene = Scene::title;
		break;
	}
}
//-------------------------------------------------------------------------
﻿#include "CoreTask.h"
#include "Rendering.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	graph = std::make_shared<GraphicResource>();
	scene = Scene::title;//–{“–‚Í^Cg‹
	tts = std::make_shared<TitleTaskSystem>();
	gts = std::make_shared<GameTaskSystem>();
	ssts = std::make_shared<StageSelectTaskSystem>();
	keyboard = std::make_shared<Keyboard>();
	cts = std::make_shared<ClearTaskSystem>();
	gots = std::make_shared<GameOverTaskSystem>();
	audio = std::make_shared<Audio>();
}

void CoreTask::update()
{
	keyboard->update();
	switch (scene) {
	case Scene::title:
		tts->update();
		break;
	case Scene::stageselect:
		ssts->update();
		break;
	case Scene::game:
		//graph->load("player");
		gts->update();
		break;
	case Scene::gameover:
		gots->update();
		break;
	case Scene::clear:
		cts->update();
		break;
	}
}

void CoreTask::init()
{
	//静的メンバの初期化
	Rendering::camera = gts->camera;
	Rendering::resource = graph;

	//音
	audio->load("action");
	//画像
	graph->load("item");
	graph->load("goal");
	graph->load("player");	//resource.jsonのscopeにplayerが含まれている画像を全てロード
	graph->load("enemy");   //scope:enemyの画像をすべて読み込む
	//ct->graph->load("star");    //starの画像をロード(現在スコープにplayerがあるためコメントアウト)
	gts->player->init();	//init_render("player"); を実行。resource.jsonのnameが"player"の画像をセットする
}
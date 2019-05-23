#include "CoreTask.h"
#include "Rendering.h"

GameTaskSystem *gts;

void CoreTask::change_scene(Scene nextscene_)
{
	switch (scene)
	{
	case Scene::title:
		TitleTaskSystem::init();
		break;
	case Scene::stageselect:
		break;
	case Scene::game:
		break;
	case Scene::gameover:
		GameOverTaskSystem::initialize();
		break;
	case Scene::clear:
		ct->cts->init();
		break;
	case Scene::pause:
		PauseTask::initialize();
		break;
	}
	scene = nextscene_;
}

CoreTask::CoreTask()
{
	gts = std::make_shared<GameTaskSystem>();
	cts = std::make_shared<ClearTaskSystem>();
	scene = Scene::title;
}

void CoreTask::update()
{
	Keyboard::update();
	switch (scene) {
	case Scene::title:
		TitleTaskSystem::update();
		break;
	case Scene::stageselect:
		ssts->update();
		break;
	case Scene::game:
		//graph->load("player");
		gts->update();
		break;
	case Scene::gameover:
		GameOverTaskSystem::update();
		break;
	case Scene::clear:
		cts->update();
		break;
	case Scene::pause:
		PauseTask::update();
		break;
	}
}

void CoreTask::init()
{
	//静的メンバの初期化
	GraphicResource::init();
	Keyboard::initialize();
	Audio::init();
	Item::player = gts->player;
	Enemy::player = gts->player;
	//メンバ生成
	ssts = std::make_shared<StageSelectTaskSystem>();

	//音
	Audio::load("action");
	Audio::load("system");
	Audio::load("stage");
	//画像
	GraphicResource::load("item");
	GraphicResource::load("goal");
	GraphicResource::load("player");
	GraphicResource::load("enemy");
	//タイトル
	TitleTaskSystem::init();
	//ポーズ
	PauseTask::initialize();
	//ゲームオーバー
	GameOverTaskSystem::initialize();
	//ct->graph->load("star");    //starの画像をロード(現在スコープにplayerがあるためコメントアウト)
	gts->player->init();	//init_render("player"); を実行。resource.jsonのnameが"player"の画像をセットする
}

void CoreTask::finalize()
{
	Keyboard::finalize();
}
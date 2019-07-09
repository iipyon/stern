#include "CoreTask.h"
#include "Rendering.h"
#include "GameOverTaskSystem.h"
#include "TitleTaskSystem.h"
#include "PauseTaskSystem.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Audio.h"
#include "Scene.h"
#include"screen_helper.h"
#include"Demo.h"

GameTaskSystem *gts;


CoreTask::CoreTask()
{
	gts = std::make_shared<GameTaskSystem>();
	demo = std::make_unique<Demo>();
	Scene::set_scene(SceneType::title);
}

void CoreTask::update()
{
	Keyboard::update();
	Mouse::update();
	switch (Scene::get_scene()) {
	case SceneType::title:
		TitleTaskSystem::update();
		break;
	case SceneType::stageselect:
		ssts->update();
		break;
	case SceneType::game:
		//graph->load("player");
		gts->update();
		break;
	case SceneType::gameover:
		GameOverTaskSystem::update();
		break;
	case SceneType::clear:
		ClearTaskSystem::update();
		break;
	case SceneType::pause:
		PauseTask::update();
		break;
	case SceneType::demo:
		demo->update();
		break;
	}
}

void CoreTask::init()
{
	//静的メンバの初期化
	GraphicResource::init();
	Keyboard::initialize();
	Audio::init();
	ScreenFunc::initialize();

	Item::player = gts->player;
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
	//タイトル
	TitleTaskSystem::init();
	//ポーズ
	PauseTask::initialize();
	//ゲームオーバー
	GameOverTaskSystem::initialize();
	//クリア
	ClearTaskSystem::init();
	gts->player->init();	//init_render("player"); を実行。resource.jsonのnameが"player"の画像をセットする
}

void CoreTask::finalize()
{
	Keyboard::finalize();
}
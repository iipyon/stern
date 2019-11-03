#include "CoreTask.h"
#include "Rendering.h"
#include "GameOverTaskSystem.h"
#include "TitleTaskSystem.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Audio.h"
#include "Scene.h"
#include"screen_helper.h"

GameTaskSystem *gts;


CoreTask::CoreTask()
{
	gts = std::make_shared<GameTaskSystem>();
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
	case SceneType::game:
		//graph->load("player");
		gts->update();
		break;
	case SceneType::gameover:
		GameOverTaskSystem::update();
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
	

	//音
	Audio::load("action");
	Audio::load("system");
	Audio::load("stage");
	//画像
	GraphicResource::load("item");
	GraphicResource::load("player");
	//タイトル
	TitleTaskSystem::init();
	//ゲームオーバー
	GameOverTaskSystem::initialize();
	gts->player->init();	//init_render("player"); を実行。resource.jsonのnameが"player"の画像をセットする
}

void CoreTask::finalize()
{
	Keyboard::finalize();
}
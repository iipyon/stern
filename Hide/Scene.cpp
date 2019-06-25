#include "Scene.h"
#include "TitleTaskSystem.h"
#include "GameOverTaskSystem.h"
#include "PauseTaskSystem.h"
#include "CoreTask.h"	//削除予定
#include"Demo.h"

SceneType Scene::scene;

void Scene::set_scene(SceneType type)
{
	scene = type;
	switch (scene)
	{
	case SceneType::title:
		TitleTaskSystem::init_member();
		break;
	case SceneType::stageselect:
		StageSelectTaskSystem::init_member();
		break;
	case SceneType::game:
		//GameTaskSystem::init_member();
		ct->gts->init_member();
		break;
	case SceneType::gameover:
		GameOverTaskSystem::init_member();
		break;
	case SceneType::clear:
		//ClearTaskSystem::init_member();
		ClearTaskSystem::init_member();
		break;
	case SceneType::pause:
		PauseTask::init_member();
		break;
	case SceneType::demo:
		ct->demo->initialize();
		break;
	}
}

SceneType Scene::get_scene() {
	return scene;
}
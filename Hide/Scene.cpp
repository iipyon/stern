#include "Scene.h"
#include "TitleTaskSystem.h"
#include "GameOverTaskSystem.h"
#include "PauseTaskSystem.h"
#include "CoreTask.h"	//íœ—\’è

SceneType Scene::scene;

void Scene::set_scene(SceneType type)
{
	scene = type;
	switch (scene)
	{
	case SceneType::title:
		TitleTaskSystem::init();
		break;
	case SceneType::stageselect:
		break;
	case SceneType::game:
		break;
	case SceneType::gameover:
		GameOverTaskSystem::initialize();
		break;
	case SceneType::clear:
		ct->cts->init();
		break;
	case SceneType::pause:
		PauseTask::initialize();
		break;
	}
}

SceneType Scene::get_scene() {
	return scene;
}
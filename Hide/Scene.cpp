#include "Scene.h"
#include "TitleTaskSystem.h"
#include "GameOverTaskSystem.h"
#include "CoreTask.h"

SceneType Scene::scene;

void Scene::set_scene(SceneType type)
{
	scene = type;
	switch (scene)
	{
	case SceneType::title:
		TitleTaskSystem::init_member();
		break;
	case SceneType::game:
		
		ct->gts->init_member();
		break;
	case SceneType::gameover:
		GameOverTaskSystem::init_member();
		break;
	}
}

SceneType Scene::get_scene() {
	return scene;
}
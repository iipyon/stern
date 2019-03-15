#include "CoreTask.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	scene = Scene::game;//本当はタイトル
	tts = std::make_unique<TitleTaskSystem>();
	gts = std::make_unique<GameTaskSystem>();
	keyboard = std::make_unique<Keyboard>();
}

void CoreTask::update()
{
	keyboard->update();
	switch (scene) {
	case Scene::title:
		tts->update();
		break;
	case Scene::stageselect:
		break;
	case Scene::game:
		gts->update();
		break;
	case Scene::gameover:
		break;
	case Scene::clear:
		break;
	}
}

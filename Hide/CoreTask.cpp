#include "CoreTask.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	scene = Scene::title;//–{“–‚Í^Cg‹
	tts = std::make_unique<TitleTaskSystem>();
	gts = std::make_unique<GameTaskSystem>();
	ssts = std::make_unique<StageSelectTaskSystem>();
	keyboard = std::make_unique<Keyboard>();
	cts = std::make_unique<ClearTaskSystem>();
	graph = std::make_unique<GraphicResource>();
	gots = std::make_unique<GameOverTaskSystem>();
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
		gts->update();
		break;
	case Scene::gameover:
		break;
	case Scene::clear:
		break;
	}
}

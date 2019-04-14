#include "CoreTask.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	graph = std::shared_ptr<GraphicResource>();
	scene = Scene::title;//–{“–‚Í^Cg‹
	tts = std::shared_ptr<TitleTaskSystem>();
	gts = std::shared_ptr<GameTaskSystem>();
	ssts = std::shared_ptr<StageSelectTaskSystem>();
	keyboard = std::shared_ptr<Keyboard>();
	cts = std::shared_ptr<ClearTaskSystem>();
	gots = std::shared_ptr<GameOverTaskSystem>();
	audio = std::shared_ptr<Audio>();
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

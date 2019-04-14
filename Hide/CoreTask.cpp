#include "CoreTask.h"
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
}
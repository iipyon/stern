#include "CoreTask.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	scene = title;//本当はタイトル
	tts = std::make_unique<TitleTaskSystem>();
	gts = std::make_unique<GameTaskSystem>();
	keyboard = std::make_unique<Keyboard>();
}

void CoreTask::update()
{
	keyboard->update();
	switch (scene) {
	case title:
		tts->update();
		break;
	case stageselect:
		break;
	case game:
		gts->update();
		break;
	case gameover:
		break;
	case clear:
		break;
	}
}

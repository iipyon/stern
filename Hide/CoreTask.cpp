#include "CoreTask.h"

GameTaskSystem *gts;

CoreTask::CoreTask()
{
	gts = std::make_unique<GameTaskSystem>();
}

void CoreTask::update()
{
}

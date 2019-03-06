#include "GameTaskSystem.h"



GameTaskSystem::GameTaskSystem()
{
	player = new Player;
}

void GameTaskSystem::update()
{
	player->update();
}

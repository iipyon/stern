#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
}

GameTaskSystem::~GameTaskSystem()
{
	player.reset();
	map.reset();
}

void GameTaskSystem::update()
{
	map->update();
	player->update();
}

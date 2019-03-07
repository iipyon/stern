#include "GameTaskSystem.h"



GameTaskSystem::GameTaskSystem()
{
	player = new Player;
	map = new Map((char*)("img/data.txt"));
}

void GameTaskSystem::update()
{
	map->update();
	player->update();
}

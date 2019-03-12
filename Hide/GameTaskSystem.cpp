#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	normalstar = std::make_shared<BasicList<NormalStar>>();
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::update()
{
	map->update();
	//normalstar->get()->update();
	player->update();
}

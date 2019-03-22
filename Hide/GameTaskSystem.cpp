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
	//リストを先頭に戻す
	normalstar->lead();

	map->update();
	while (normalstar->exist()) {
		normalstar->get()->update();
		normalstar->proceed();
	}
	player->update();
}

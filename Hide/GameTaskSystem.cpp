#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	normalstar = std::make_shared<BasicList<NormalStar>>();
	map = std::make_unique<Map>();
	player = std::make_unique<Player>();
	walking_enemy = std::make_shared<BasicList<WalkingEnemy>>();
	boss = std::make_shared<BasicList<Boss>>();
	flying_enemy = std::make_shared<BasicList<FlyingEnemy>>();
	throwing_enemy = std::make_shared<BasicList<ThrowingEnemy>>();
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

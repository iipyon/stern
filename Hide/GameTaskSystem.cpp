#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point point = {100,300,30,30};
	struct PhysicState physic_state = { 1,0,0 };//gra,rep,wei
	struct PlayerState player_state = { 3,2 };//life,hp

	map = std::make_unique<Map>();
	player = std::make_unique<Player>(point,physic_state,player_state);

	normalstar = std::make_shared<BasicList<NormalStar>>();
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
	walking_enemy->lead();

	map->update();
	//☆------------------------------
	normalstar->lead();
	while (normalstar->exist()) {
		normalstar->get()->update();
		normalstar->proceed();
	}
	//--------------------------------
	//敵------------------------------
	walking_enemy->lead();
	while (walking_enemy->exist()) {
		walking_enemy->get()->update();
		walking_enemy->proceed();
	}
	//--------------------------------

	player->update();
}

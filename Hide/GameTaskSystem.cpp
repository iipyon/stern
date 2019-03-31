#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point = {100,300,30,30};
	class Point g_point = { 30,510,30,30 };
	struct PhysicState p_physic_state = { 1,0,0 };//gra,rep,wei
	struct PlayerState player_state = { 3,2 };//life,hp

	goal = std::make_unique<Goal>(g_point);
	map = std::make_unique<Map>();
	player = std::make_unique<Player>(p_point,p_physic_state,player_state);

	//normalstar = std::make_shared<BasicList<NormalStar>>();
	walking_enemy = std::make_shared<BasicList<WalkingEnemy>>();
	boss = std::make_shared<BasicList<Boss>>();
	flying_enemy = std::make_shared<BasicList<FlyingEnemy>>();
	throwing_enemy = std::make_shared<BasicList<ThrowingEnemy>>();
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::init()
{
	player->init();
	goal->init();
}


void GameTaskSystem::update()
{
	//リストを先頭に戻す
	walking_enemy->lead();
	map->update();
	goal->update();
	//☆------------------------------
	for (auto itr = normalstar.begin(); itr != normalstar.end(); itr++) {
		itr->update();
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

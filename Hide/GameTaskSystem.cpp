#include "GameTaskSystem.h"
#include <vector> 
#include <memory>

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point = { 100,300,30,30 };
	class Point g_point = { 30,510,30,30 };
	struct PhysicState p_physic_state = { 1,0,0 };//gra,rep,wei
	struct PlayerState player_state = { 3,2 };//life,hp

	goal = std::make_unique<Goal>(g_point);
	map = std::make_unique<Map>();
	camera = std::make_unique<Camera>();
	player = std::make_unique<Player>(p_point, p_physic_state, player_state);
	enemys = std::make_shared<std::vector<std::unique_ptr<Enemy>>>();
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::init()
{
	camera->init();
	player->init();
	goal->init();
}


void GameTaskSystem::update()
{
	
	map->update();
	goal->update();
	//☆------------------------------
	for (auto itr = normalstar.begin(); itr != normalstar.end(); itr++) {
		itr->update();
	}
	//--------------------------------
	//敵------------------------------先頭から終端まで
	for (auto itr = enemys->begin(); itr != enemys->end(); ++itr){
		(*itr)->update();
	}
	//--------------------------------
	player->update();
	camera->update();
}

void GameTaskSystem::finalize()
{
	while (!normalstar.empty()) {//空でないなら
		normalstar.pop_back();//消し去る
	}
	while (!enemys->empty()) {
		enemys->pop_back();
	}
}

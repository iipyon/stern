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
	camera = std::make_shared<Camera>();
	player = std::make_shared<Player>(p_point, p_physic_state, player_state);
	enemys = std::make_shared<std::vector<std::unique_ptr<Enemy>>>();
	enemy_transaction = std::make_shared<std::vector<std::unique_ptr<Enemy>>>();
	item = std::make_shared<std::vector<std::shared_ptr<Item>>>();
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
	//アイテム-----------------------------
	for (auto itr = item->begin(); itr != item->end(); ++itr) {
		(*itr)->update();
	}
	player->update();
	camera->update();

	//トランザクションの実行
	for (auto itr = enemy_transaction->begin(); itr != enemy_transaction->end(); ++itr) {
		enemys->push_back(std::move((*itr)));	//トランザクションから実体へ所有権を移動する
	}
	enemy_transaction->clear();	//enemy_transactionを空にする
}

void GameTaskSystem::finalize()
{
	normalstar.clear();
	enemys->clear();
	item->clear();
}

﻿#include "GameTaskSystem.h"
#include <vector> 

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
	map->update();
	goal->update();
	//☆------------------------------
	for (auto itr = normalstar.begin(); itr != normalstar.end(); itr++) {
		itr->update();
	}
	//--------------------------------
	//敵------------------------------先頭から終端まで
	for (auto itr = walking_enemy.begin(); itr != walking_enemy.end(); ++itr) {
		itr->update();//歩行敵のupdateを呼ぶ
	}
	for (auto itr = flying_enemy.begin(); itr != flying_enemy.end(); ++itr) {
		itr->update();
	}
	for (auto itr = throwing_enemy.begin(); itr != throwing_enemy.end(); ++itr) {
		itr->update();
	}
	for (auto itr = enemy_bullet.begin(); itr != enemy_bullet.end(); ++itr) {
		itr->update();
	}
	//--------------------------------

	player->update();
}

void GameTaskSystem::finalize()
{
	while (!normalstar.empty()) {//空でないなら
		normalstar.pop_back();//消し去る
	}
	while (!walking_enemy.empty()) {
		walking_enemy.pop_back();
	}
	while (!flying_enemy.empty()) {
		flying_enemy.pop_back();
	}
	while (!throwing_enemy.empty()) {
		throwing_enemy.pop_back();
	}
	while (!enemy_bullet.empty()) {
		enemy_bullet.pop_back();
	}
}

﻿#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"
#include"WalkingEnemy.h"
#include"ThrowingEnemy.h"
#include"FlyingEnemy.h"
#include"BossEnemy.h"
#include"Goal.h"

class GameTaskSystem
{
private:
protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void init();
	void update();
	void finalize();
	//~GameTaskSystem();
	std::unique_ptr<Player> player;
	std::unique_ptr<Map> map;
	std::unique_ptr<Goal> goal;
	//☆
	std::vector<NormalStar> normalstar;
	//敵
	std::shared_ptr<BasicList<WalkingEnemy>> walking_enemy;
	std::shared_ptr<BasicList<FlyingEnemy>>  flying_enemy;
	std::shared_ptr<BasicList<Boss>> boss;
	std::shared_ptr<BasicList<ThrowingEnemy>> throwing_enemy;
};


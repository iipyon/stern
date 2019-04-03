#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"
#include"WalkingEnemy.h"
#include"ThrowingEnemy.h"
#include"EnemyShot00.h"
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
	std::vector<WalkingEnemy> walking_enemy;
	std::vector<FlyingEnemy>  flying_enemy;
	std::vector<Boss> boss;
	std::vector<ThrowingEnemy> throwing_enemy;
	std::vector<EnemyShot00> enemy_shot00;
};


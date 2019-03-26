#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"
#include"WalkingEnemy.h"
#include"ThrowingEnemy.h"
#include"FlyingEnemy.h"
#include"BossEnemy.h"

class GameTaskSystem
{
private:
protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void update();
	//~GameTaskSystem();
	std::unique_ptr<Player> player;
	std::unique_ptr<Map> map;
	//Åô
	std::shared_ptr<BasicList<NormalStar>> normalstar;
	//ìG
	std::shared_ptr<BasicList<WalkingEnemy>> walking_enemy;
	std::shared_ptr<BasicList<FlyingEnemy>>  flying_enemy;
	std::shared_ptr<BasicList<Boss>> boss;
	std::shared_ptr<BasicList<ThrowingEnemy>> throwing_enemy;
};


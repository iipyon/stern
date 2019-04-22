#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"
#include"WalkingEnemy.h"
#include"ThrowingEnemy.h"
#include"EnemyShot00.h"//どこにあるかわからない
#include"BulletEnemy.h"
#include"FlyingEnemy.h"
#include"BossEnemy.h"
#include"Goal.h"
#include"Camera.h"
#include"RecoveryItem.h"

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
	std::shared_ptr<Player> player;
	std::unique_ptr<Map> map;
	std::unique_ptr<Goal> goal;
	std::shared_ptr<Camera> camera;
	//☆
	std::vector<NormalStar> normalstar;
	//敵
	std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemys;
	std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemy_transaction;
	//アイテム
	std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
};


#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
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
#include"GravityStar.h"

class GameTaskSystem
{
private:
	bool feed_flag;

	void attack_star_enemy();
	void attack_player_enemy();
	void attack_player_item();
	void deleted_bullet_enemy();

protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void init();
	void init_member();
	void update();
	void finalize();
	//~GameTaskSystem();
	std::shared_ptr<Player> player;
	std::unique_ptr<Map> map;
	std::unique_ptr<Goal> goal;
	//☆
	std::vector<NormalStar> normalstar;
	std::vector<GravityStar> gravityStar;
	//敵
	std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemys;
	std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemy_transaction;
	//アイテム
	std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
};


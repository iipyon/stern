#pragma once
#include "Player.h"
#include "Goal.h"
#include "NormalStar.h"
#include "GravityStar.h"
#include "Enemy.h"
#include "Item.h"

//オブジェクトの保存方法に関する記述をするファイル
//独立させ、低依存

namespace mdl {
	extern std::shared_ptr<Player> player;
	extern std::unique_ptr<Goal> goal;
	//☆
	extern std::vector<NormalStar> normalstar;
	extern std::vector<GravityStar> gravityStar;
	//敵
	extern std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemys;
	extern std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemy_transaction;
	//アイテム
	extern std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
}
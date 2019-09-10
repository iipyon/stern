#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"Goal.h"
#include"Camera.h"
#include"RecoveryItem.h"
#include"Fook.h"
#include"GravityStar.h"

class GameTaskSystem
{
private:
	bool feed_flag;
	void attack_player_item();

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

	std::vector<Fook> fook;

	//アイテム
	std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
	//setter
	void set_feed_flag(bool);
	
};


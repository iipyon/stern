#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"NormalStar.h"
#include "Enemy.h"


class GameTaskSystem
{
private:
	bool deg_flag;
	int feedcnt;

	void attack_star_enemy();
	void attack_player_enemy();
	void attack_player_item();

protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void init();
	void update();
	void finalize();
	std::unique_ptr<Map> map;
	//~GameTaskSystem();

};




#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>

class GameTaskSystem
{
private:
	std::unique_ptr<Player> player = std::make_unique<Player>();
	std::unique_ptr<Map> map = std::make_unique<Map>((char*)("img/data.txt"));
public:
	GameTaskSystem();
	~GameTaskSystem();
	void update();
	//~GameTaskSystem();
};

extern GameTaskSystem *gts;


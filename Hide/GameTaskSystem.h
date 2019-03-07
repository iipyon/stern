#pragma once
#include "Player.h"
#include"Map.h"

class GameTaskSystem
{
private:
	Player *player;
	Map *map;
public:
	GameTaskSystem();
	void update();
	//~GameTaskSystem();
};

extern GameTaskSystem *gts;


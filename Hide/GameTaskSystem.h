#pragma once
#include "Player.h"

class GameTaskSystem
{
private:
	Player *player;
public:
	GameTaskSystem();
	void update();
	//~GameTaskSystem();
};

extern GameTaskSystem *gts;


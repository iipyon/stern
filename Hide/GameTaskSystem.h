#pragma once
#include "Player.h"
class GameTaskSystem
{
private:
	Player *player = new Player;
public:
	GameTaskSystem();
	void update();
	//~GameTaskSystem();
};


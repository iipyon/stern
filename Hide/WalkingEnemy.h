#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
public:
	enum class WalkingState
	{
		walk,
		stay,
		run,
	};
	WalkingState walkingstate;
	void move();
	void update();
private:
	//敵が行動するカウンター
	int WalkingEnemycnt = 0;
protected:
};
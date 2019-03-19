#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
	enum WakingState
	{
		walk,
		stay,
		run,
	};
public:
	WakingState wakingstate;
	void move();
	void update();
private:
protected:
};
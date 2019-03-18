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
	void move();
	void update();
private:
protected:
};
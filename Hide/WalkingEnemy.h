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
	void move();
	void update();
private:
	WalkingState wakingstate;
protected:
};
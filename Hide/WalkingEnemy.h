#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
	enum class WalkingState
	{
		walk,
		stay,
		run,
	};
	WalkingState wakingstate;
public:
	void move();
	void update();
private:
protected:
};
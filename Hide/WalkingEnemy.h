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
	WalkingState wakingstate;
	void move();
	void update();
private:
protected:
};
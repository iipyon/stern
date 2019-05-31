#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
	
public:
	enum class WalkingState
	{
		walk,
		stay,
		run
	};
	WalkingState walkingstate;
	AngleState anglestate;
  
	WalkingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move() override;
	void check_left();
	void check_right();
		
private:
	AngleState beforeangle;
protected:
};
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
  
	WalkingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
	void check_left();
	void check_right();
		
private:
	//敵が行動するカウンター
	int WalkingEnemycnt = 0;
	bool left_status;
	bool right_status;

protected:
};
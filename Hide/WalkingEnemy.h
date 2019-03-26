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
	WalkingEnemy();
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
 #pragma once
#include"Enemy.h"

//---------------------------------
//---------------------------------

class FlyingEnemy : public Enemy{
	
public:
	enum class FlyingState
	{
		fly,
		stay
	};
	FlyingState flyingstate;

	FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
private:
	int FlyingEnemycnt = 0;
protected:
};

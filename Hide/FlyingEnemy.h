 #pragma once
#include"Enemy.h"

//---------------------------------
//---------------------------------

class FlyingEnemy : public Enemy{
	
public:
	enum class FlyingState
	{
		up,
		down,
		stay
	};
	FlyingState flyingstate;

	FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void change_state();
	void update();
private:
	int movecnt;//ブロックに当たっている間とり誤差をなくしたかった
protected:
};

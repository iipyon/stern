#pragma once
#include"Enemy.h"

class ThrowingEnemy :public Enemy {
public:
	ThrowingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
protected:

};
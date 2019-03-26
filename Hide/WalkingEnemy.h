#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
public:
	//using Enemy::Enemy;
	WalkingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
private:
protected:
};
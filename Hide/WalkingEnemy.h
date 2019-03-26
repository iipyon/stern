#pragma once
#include"Enemy.h"

class WalkingEnemy : public Enemy {
public:
	//using Enemy::Enemy;
	WalkingEnemy();
	void move();
	void update();
private:
protected:
};
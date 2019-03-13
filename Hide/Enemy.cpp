#include "Enemy.h"

//----------------------------------
//“G‘S”Ê
//----------------------------------

void Enemy::move()
{
	velocityX;
	velocityY;
}

bool Enemy::attack()
{
	return false;
}

void Enemy::update()
{
	Physic::exercise();
	Enemy::attack();
}

bool Enemy::damage(int d_)
{
	hp -= d_;
	if (hp <= 0) {
		return true;
	}
	return false;
}

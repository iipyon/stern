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
	extern float exercise;
	extern bool attack;
}

bool Enemy::damage(int)
{
	if (hp <= 0) {
		return true;
	}
	return false;
}

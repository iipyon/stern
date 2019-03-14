#include "Enemy.h"
//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy()
{
	life = 0;
	damaged = 0;
	gravity = 0;
}
Enemy::Enemy(int E_life, int E_damaged, int E_gravity)
{
	life = E_life;
	damaged = E_damaged;
	gravity = E_gravity;
}
void Enemy::move()
{
	
}

bool Enemy::attack()
{
	return false;
}

void Enemy::update()
{
	this->exercise();
	this->attack();
}

bool Enemy::damage(int d_)
{
	hp -= d_;
	if (hp <= 0) {
		return true;
	}
	return false;
}

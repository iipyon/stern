#include "Enemy.h"
//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy(int life, int damage, int gravity)
{
	life = 0;
	damage = 0;
	gravity = 0;
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

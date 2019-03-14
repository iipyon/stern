#include "Enemy.h"
//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy()
{

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

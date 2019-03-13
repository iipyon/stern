#include "Enemy.h"

//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy()
{
	hp = 0;
	power = 0;
	knock_back = 0;
	Enmyupdate = new Enemy();
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
	
	Enmyupdate->exercise();
	Enmyupdate->attack();
}

bool Enemy::damage(int d_)
{
	hp -= d_;
	if (hp <= 0) {
		return true;
	}
	return false;
}

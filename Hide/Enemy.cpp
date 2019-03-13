#include "Enemy.h"

//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy()
{
	hp = 0;
	power = 0;
	knock_back = 0;
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
	Enemy *Enmyupdate;
	Enmyupdate = new Enemy();
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

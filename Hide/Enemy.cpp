#include "Enemy.h"
//----------------------------------
//“G‘S”Ê
//----------------------------------
Enemy::Enemy(Point point, PhysicState physic_state, EnemyState enemy_state) : Physic(point,physic_state)
{
	life = enemy_state.life;
	damaged = enemy_state.damage;
	anglestate = enemy_state.anglestate;
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

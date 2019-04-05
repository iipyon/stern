#include "Enemy.h"
#include "CoreTask.h"
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
	Point player_point = ct->gts->player->get_point();

	if(player_point.x <= point.x + point.w && point.x <= player_point.x + player_point.w ){
		if (player_point.y <= point.y + point.h && point.y <= player_point.y + player_point.h) {
			return true;
		}
	}
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

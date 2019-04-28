#include "Enemy.h"
#include "CoreTask.h"
std::shared_ptr<Player> Enemy::player;	//静的メンバの実体化

//----------------------------------
//敵全般
//----------------------------------
Enemy::Enemy(Point point, PhysicState physic_state, EnemyState enemy_state):BasicObject(point)
{
	life = enemy_state.life;
	damaged = enemy_state.damage;
	anglestate = enemy_state.anglestate;
}

bool Enemy::attack()
{

	Point player_point = ct->gts->player->get_point();
	if(CheckHit(point,player_point)){
			return true;
	}
	return false;
}

void Enemy::update()
{
	move();
	exercise();
	if (attack()) {
		if (player->damage()) {
			//ここに死んだときの処理かきたい
		}
	}
	shape->draw(point);
}

bool Enemy::damage(int d_)
{
	hp -= d_;
	if (hp <= 0) {
		return true;
	}
	return false;
}

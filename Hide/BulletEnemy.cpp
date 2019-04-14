#include "BulletEnemy.h"
#include"DxLib.h"

BulletEnemy::BulletEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	shape->set("bullet");
	switch (enemy_state_.anglestate) {
	case AngleState::left:
		angle = 1;
		break;
	case AngleState::right:
		angle = -1;
		break;
	}
}

void BulletEnemy::move()
{
	velocityX = (float)angle;
	point.x += (int)velocityX;
}

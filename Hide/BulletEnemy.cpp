#include "BulletEnemy.h"
#include"DxLib.h"

BulletEnemy::BulletEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	
	switch (enemy_state_.anglestate) {
	case AngleState::left:
		angle = 1;
		shape->set("seed_Left");
		break;
	case AngleState::right:
		angle = -1;
		shape->set("seed_Right");
		break;
	}
}

void BulletEnemy::move()
{
	point.x += physicshape->Movement_X(point, angle);
}

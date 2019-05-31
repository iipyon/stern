#include "BulletEnemy.h"
#include"DxLib.h"
#include"CoreTask.h"
#include"EnemyConfig.h"

BulletEnemy::BulletEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	shape->set("bullet");

	hp = BulletHP;
	active = true;

	switch (enemy_state_.anglestate) {
	case AngleState::left:
		shape->set("seed_Left");

		angle = -BulletMoveSpeed;
		break;
	case AngleState::right:
		shape->set("seed_Right");
		angle = BulletMoveSpeed;

		break;
	}
}

void BulletEnemy::move()
{
	hp--;
	if (map_checkhit(point) || hp < 0) {//hpが0または生存時間が過ぎたら
		active = false;//死ゾ
	}
	point.x += physicshape->Movement_X(point, angle);
}

bool BulletEnemy::map_checkhit(Point point_)
{
	bool check = false;
	Point Left = { point_.x - 1,point_.y,1,point_.h };
	Point Right = { point_.x + point_.w,point_.y,1,point_.h };
	switch (this->anglestate) {
	case AngleState::left:
		if (ct->gts->map->get_bottom(Left) ||
			ct->gts->map->get_left(Left) ||
			ct->gts->map->get_right(Left) ||
			ct->gts->map->get_top(Left)) {
			check = true;
		}
		break;
	case AngleState::right:
		if (ct->gts->map->get_bottom(Right) ||
			ct->gts->map->get_left(Right) ||
			ct->gts->map->get_right(Right) ||
			ct->gts->map->get_top(Right)) {
			check = true;
		}
		break;
	}
	return check;
}

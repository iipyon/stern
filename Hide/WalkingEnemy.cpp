#include "WalkingEnemy.h"
#include"CoreTask.h"
#include"WalkingEnemyConfig.h"

WalkingEnemy::WalkingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	anglestate = AngleState::right;
	walkingstate = WalkingState::walk;
}

void WalkingEnemy::move()
{
	point.y += physicshape->fall(point);
	check_left();
	check_right();

	switch (walkingstate)
	{
	//歩行
	case WalkingState::walk:
		switch (anglestate) {
		case AngleState::right:
			//init_renderで右向きにする
			point.x += physicshape->Movement_X(point, WalkingSpeed);
			break;
		case AngleState::left:
			//init_renderで左向きにする
			point.x += physicshape->Movement_X(point, -WalkingSpeed);
			break;
		}
		break;
	//待機
	case WalkingState::stay:
		point.x += physicshape->Movement_X(point, 0);//
		break;
	}
	if (beforeangle != anglestate) {
		if (anglestate == AngleState::left) {
			shape->set("slime_walk_Left");
		}
		else {
			shape->set("slime_walk_Right");
		}
	}
	beforeangle = anglestate;
}

void WalkingEnemy::check_left()
{
	//今の画像の大きさが64*64のため
	Point extendpoint = point;
	extendpoint.x -= 1;
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_left(extendpoint) != 0) {
		anglestate = AngleState::right;
	}
}

void WalkingEnemy::check_right()
{
	//今の画像の大きさが64*64のため
	Point extendpoint=point;
	extendpoint.w += 1;
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_right(extendpoint) != 0) {
		anglestate = AngleState::left;
	}
}

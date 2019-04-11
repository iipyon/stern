#include "WalkingEnemy.h"
#include"CoreTask.h"

WalkingEnemy::WalkingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	anglestate = AngleState::right;
	walkingstate = WalkingState::walk;
	init_render("walking");
}

void WalkingEnemy::move()
{
	check_left();
	check_right();

	switch (walkingstate)
	{
	//歩行
	case WalkingState::walk:
		switch (anglestate) {
		case AngleState::right:
			//init_renderで右向きにする
			velocityX = 1;
			break;
		case AngleState::left:
			//init_renderで左向きにする
			velocityX = -1;
			break;
		}
		break;
	//待機
	case WalkingState::stay:
		velocityX = 0;
		break;
	//走行
	/*case WalkingState::run:
		switch (anglestate) {
		case AngleState::right:
			//init_renderで右向きにする
			velocityX = 2;
			break;
		case AngleState::left:
			//init_renderで左向きにする
			velocityX = -2;
			break;
		}
		break;*/
	}
	point.x += (int)velocityX;
}

void WalkingEnemy::check_left()
{
	//今の画像の大きさが30*30のため
	Point left{ point.x,point.y,-1,30 };
	DrawBox(left.x, left.y, left.x + left.w, left.y + left.h, GetColor(0, 255, 0), TRUE);
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_left(left) != 0) {
		anglestate = AngleState::right;
	}
}

void WalkingEnemy::check_right()
{
	//今の画像の大きさが30*30のため
	Point right{ point.x + 30,point.y,1,30 };
	DrawBox(right.x, right.y, right.x + right.w, right.y + right.h, GetColor(255, 0, 0), TRUE);
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_right(right) != 0) {
		anglestate = AngleState::left;
	}
}

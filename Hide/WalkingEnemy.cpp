#include "WalkingEnemy.h"
#include"CoreTask.h"

//----------------------------------
//雑魚敵(歩行)
//----------------------------------
WalkingEnemy::WalkingEnemy()
{
	left_status = false;
	right_status = false;
}
void WalkingEnemy::move()
{
	switch (walkingstate)
	{
	case WalkingState::walk:
		//
		if (WalkingEnemycnt < 300) {
			velocityX = 1;
			if (left_status == true) {
				//方向転換
				WalkingEnemycnt = 300;
			}
		}
		else {
			velocityX = -1;
			if(right_status == true) {
			//方向転換
			WalkingEnemycnt = 0;
			}
		}
		break;
	case WalkingState::stay:
		velocityX = 0;
		//誤差を消すため
		WalkingEnemycnt--;
		break;
	case WalkingState::run:
		if (WalkingEnemycnt < 300) {
			velocityX = 2;
			if (left_status == true) {
				//方向転換
				WalkingEnemycnt = 300;
			}
		}
		else {
			velocityX = -2;
			if (right_status == true) {
				//方向転換
				WalkingEnemycnt = 0;
			}
		}
		break;
	}
}

void WalkingEnemy::check_left()
{
	//今の画像の大きさが30*30のため
	Point left{ point.x + 30,point.y,1,30 };
	DrawBox(left.x, left.y, left.x + left.w, left.y + left.h, GetColor(255, 0, 0), TRUE);
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_left(left) != 0) {
		left_status = true;
	}
	else {
		left_status = false;
	}

}

void WalkingEnemy::check_right()
{
	//今の画像の大きさが30*30のため
	Point right{ point.x,point.y,-1,30 };
	DrawBox(right.x, right.y, right.x + right.w, right.y + right.h, GetColor(255, 0, 0), TRUE);
	//仮の当たり判定
	//MapのGet_leftを呼ぶ?
	if (ct->gts->map->get_right(right) != 0) {
		left_status = true;
	}
	else {
		left_status = false;
	}

}
void WalkingEnemy::update()
{
	//WalkingEnemyをカウントする
	WalkingEnemycnt++;
	//仮　300(10マス) + 300(10マス)分
	if (WalkingEnemycnt > 600) {
		WalkingEnemycnt = 0;
	}
	check_left();
	check_right();
}

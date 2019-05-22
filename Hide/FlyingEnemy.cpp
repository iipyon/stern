#include "FlyingEnemy.h"
#include "CoreTask.h"
#include "FlyingEnemyConfig.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

FlyingEnemy::FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	flyingstate = FlyingState::down;
	movecnt = 0;
	shape->set("flying");
}

void FlyingEnemy::move()
{
	change_state();
	switch (flyingstate)
	{
		//飛行
	case FlyingState::down:
		point.y += physicshape->Movement_Y(point,1);
		break;
	case FlyingState::up:
		point.y += physicshape->Movement_Y(point, -1);
		break;
	case FlyingState::stay:
		point.y += physicshape->Movement_Y(point, 0);
		break;
	}

}

void FlyingEnemy::change_state()
{
	//   
	movecnt++;// 
	if (movecnt <= FlyingDown) {
		flyingstate = FlyingState::down;
		if (ct->gts->map->get_bottom(point)) {
			flyingstate = FlyingState::stay;
		}
	}
	else if (movecnt <= FlyingUp) {
		flyingstate = FlyingState::up;
		if (ct->gts->map->get_top(point)) {
			flyingstate = FlyingState::stay;
		}
	}
	if (movecnt >= 384) {
		movecnt = 0;
	}
}


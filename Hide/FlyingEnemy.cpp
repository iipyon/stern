#include "FlyingEnemy.h"
#include "CoreTask.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

FlyingEnemy::FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	flyingstate = FlyingState::down;
	preY = point.y;
	destinationY = preY + 120;
	movecnt = 0;
	init_render("flying");
}

void FlyingEnemy::move()
{
	switch (flyingstate)
	{
	//飛行
	case FlyingState::down:
		velocityY = 1;
		break;
	case FlyingState::up:
		velocityY = -1;
		break;
	case FlyingState::stay:
		velocityY = 0;
		break;
	}
	point.y += (int)velocityY;
}

void FlyingEnemy::change_state() {
	if (ct->gts->map->get_bottom(point) || ct->gts->map->get_top(point)) movecnt++;
	if (point.y > destinationY || point.y + movecnt > destinationY) { flyingstate = FlyingState::up; movecnt = 0; }
	if (point.y < preY || point.y - movecnt < preY) { flyingstate = FlyingState::down; movecnt = 0; }
}

void FlyingEnemy::update()
{
	//exercise();;
	change_state();
	move();
	draw(true);
}

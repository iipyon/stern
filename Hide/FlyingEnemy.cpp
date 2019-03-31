#include "FlyingEnemy.h"
#include "CoreTask.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

FlyingEnemy::FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{

	//必要か判断ができない初期化処理
	flyingstate = FlyingState::fly;
	init_render("flying");
}

void FlyingEnemy::move()
{
	switch (flyingstate)
	{
	//飛行
	case FlyingState::fly:
		//2マス分
		if (FlyingEnemycnt < 60) {
			velocityY = 1;
		}
		else {
			velocityY = -1;
		}
		break;
	case FlyingState::stay:
		velocityY = 0;
		//誤差を消すため
		FlyingEnemycnt--;
		break;
	}
	point.y += (int)velocityY;

	//FlyingEnemyをカウントする
	FlyingEnemycnt++;
	//120以上になったらリセット
	if (FlyingEnemycnt > 120) {
		FlyingEnemycnt = 0;
	}
}

void FlyingEnemy::update()
{
	exercise();
	move();
	DrawFormatString(400, 0, GetColor(0, 0, 0), "%d", velocityY);
	draw(true);
}

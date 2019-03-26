#include "FlyingEnemy.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

FlyingEnemy::FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
}

void FlyingEnemy::move()
{
	switch(flyingstate)
	{
	case FlyingState::fly:
		//2マス分
		if (FlyingEnemycnt < 60) {
			velocityY = 1;
		}
		else{
			velocityY = -1;
		}
		break;
	case FlyingState::stay:
		velocityY = 0;
		//誤差を消すため
		FlyingEnemycnt--;
		break;
	}
}

void FlyingEnemy::update()
{
	//FlyingEnemyをカウントする
	FlyingEnemycnt++;
	//120以上になったらリセット
	if (FlyingEnemycnt > 120) {
		FlyingEnemycnt = 0;
	}
}

#include "FlyingEnemy.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

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

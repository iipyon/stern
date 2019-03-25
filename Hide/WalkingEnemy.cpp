#include "WalkingEnemy.h"

//----------------------------------
//雑魚敵(歩行)
//----------------------------------
void WalkingEnemy::move()
{
	switch(walkingstate)
	{
	case WalkingState::walk:
		//3マス行って3マス戻る
		if (WalkingEnemycnt < 3) {
			velocityX = 1;
		}
		else{
			velocityX = -1;
		}
		break;
	case WalkingState::stay:
		velocityX = 0;
		//誤差を消すため
		WalkingEnemycnt--;
		break;
	case WalkingState::run:
		if (WalkingEnemycnt < 3) {
			velocityX = 2;
		}
		else{
			velocityX = -2;
		}
		break;
	}
}

void WalkingEnemy::update()
{
	//WalkingEnemyをカウントする
	WalkingEnemycnt++;
	//6以上になったらリセット
	if (WalkingEnemycnt > 6) {
		WalkingEnemycnt = 0;
	}
}

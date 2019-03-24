#include "FlyingEnemy.h"

//----------------------------------
//雑魚敵(飛行)
//----------------------------------

void FlyingEnemy::move()
{
	switch(flyingstate)
	{
	case FlyingState::fly:
		velocityY = 1;
		break;
	case FlyingState::stay:
		velocityY = 0;
		break;
	}
}

void FlyingEnemy::update()
{
}

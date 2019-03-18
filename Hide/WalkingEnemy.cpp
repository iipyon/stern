#include "WalkingEnemy.h"

void WalkingEnemy::move()
{
	switch(WakingState())
	{
	case walk:
		velocityX += 1;
		break;
	case stay:
		velocityX += 0;
		break;
	case run:
		velocityX += 2;
		break;
	}
}

void WalkingEnemy::update()
{
}

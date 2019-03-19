#include "WalkingEnemy.h"

void WalkingEnemy::move()
{
	switch(wakingstate)
	{
	case WakingState::walk:
		velocityX = 1;
		break;
	case WakingState::stay:
		velocityX = 0;
		break;
	case WakingState::run:
		velocityX = 2;
		break;
	}
}

void WalkingEnemy::update()
{
}

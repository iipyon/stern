#include "WalkingEnemy.h"

void WalkingEnemy::move()
{
	switch(wakingstate)
	{
	case WalkingState::walk:
		velocityX = 1;
		break;
	case WalkingState::stay:
		velocityX = 0;
		break;
	case WalkingState::run:
		velocityX = 2;
		break;
	}
}

void WalkingEnemy::update()
{
}

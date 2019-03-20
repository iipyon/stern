#include "FlyingEnemy.h"

//----------------------------------
//G‹›“G(”òs)
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

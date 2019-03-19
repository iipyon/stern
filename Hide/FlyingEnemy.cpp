#include "FlyingEnemy.h"

//----------------------------------
//G‹›“G(”òs)
//----------------------------------

void FlyingEnemy::move()
{
	switch(flayingstate)
	{
	case FlyingEnemy::fly:
		velocityY = 1;
		break;
	case FlyingEnemy::stay:
		velocityY = 0;
		break;
	}
}

void FlyingEnemy::update()
{
}

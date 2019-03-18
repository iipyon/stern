#include "FlyingEnemy.h"

//----------------------------------
//G‹›“G(”òs)
//----------------------------------

void FlyingEnemy::move()
{
	switch(FlyingState())
	{
	case fly:
		velocityY += 1;
		break;
	case stay:
		velocityY += 0;
		break;
	}
}

void FlyingEnemy::update()
{
}

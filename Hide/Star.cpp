#include"Star.h"

//---------------------------------
//¯‘S”Ê
//---------------------------------

Star::Star(Point point_, PhysicState physic_state_, StarState star_state) : Physic(point_, physic_state_)
{

}

bool Star::attack()
{
	return false;
}

bool Star::damage(int)
{
	return false;
}



#include"Star.h"

//---------------------------------
//¯‘S”Ê
//---------------------------------

Star::Star(int power_, int life_, int weight_)
{
	power = power_;
	weight = weight_;
	life = life_;
}

bool Star::attack()
{
	return false;
}

bool Star::damage(int)
{
	return false;
}


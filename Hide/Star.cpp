#include"Star.h"

//---------------------------------
//¯‘S”Ê
//---------------------------------

Star::Star(int power_, int life_, int weight_,int x_,double angle_)
{
	point.x = x_;
	angle = angle_;
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



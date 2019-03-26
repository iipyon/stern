#include"Star.h"

//---------------------------------
//¯‘S”Ê
//---------------------------------

Star::Star(Point point_, PhysicState physic_state_, StarState star_state) : Physic(point_, physic_state_)
{
	bright = star_state.bright;
	radius = star_state.radius;
	power = star_state.power;
	life = star_state.life;
	angle = star_state.angle;
  contact = false;
}

bool Star::attack()
{
	//‰~‚Æ‹éŒ`‚Ì“–‚½‚è”»’è
	return false;
}

bool Star::damage(int damage_)
{
	life -= damage_;
	if (life <= 0) {
		return true;
	}
	return false;
}



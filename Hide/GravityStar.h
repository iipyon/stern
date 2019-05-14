#pragma once
#include"Star.h"

//---------------------------------
//‘æ‚R‚Ì¯iˆø—Í‚Ì‚ ‚é¯j
//---------------------------------

class GravityStar :public Star {
public:
	GravityStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
	void setposition(Point);
private:


protected:
};
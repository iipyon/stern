#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//ïÅí ÇÃêØ
//--------------------------------

class NormalStar : public Star {
	friend class GravityStar;
public:
	NormalStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
	void inhale();

private:

};
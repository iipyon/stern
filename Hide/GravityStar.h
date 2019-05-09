#pragma once
#include"Star.h"

//---------------------------------
//第３の星（引力のある星）
//---------------------------------

class GravityStar :public Star {
public:
	GravityStar(Point point_, PhysicState physic_state_, StarState star_state);
	void update();
private:
protected:
	//GravityStar *gravitystar;//リスト用?
};
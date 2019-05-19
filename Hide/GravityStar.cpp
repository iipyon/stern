#include"GravityStar.h"
#include "CoreTask.h" //map
//
#include "DxLib.h"
//---------------------------------
//‘æ‚R‚Ì¯iˆø—Í‚Ì‚ ‚é¯j
//---------------------------------

GravityStar::GravityStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	point = point_;
	shape->set("star");
}


void GravityStar::update()
{
	Point sizeup{ point.x - 1,point.y - 1,point.w + 2,point.h + 2 };
	if (!contact) {
		point.x += physicshape->Movement_X(point, (int)(-sin(angle) * 20));
		point.y += physicshape->Movement_Y(point, (int)(cos(angle) * 20));
		if (ct->gts->map->get_bottom(sizeup) ||
			ct->gts->map->get_left(sizeup) ||
			ct->gts->map->get_right(sizeup) ||
			ct->gts->map->get_top(sizeup)) {
			gravitypoint = point;
			contact = true;
		}
	}
	else {
	}
	attack();
	shape->draw(point);
}

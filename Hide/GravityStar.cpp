#include"GravityStar.h"
#include"CoreTask.h"
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
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", point);
	if (!contact) {
		point.x += physicshape->Movement_X(point, (int)(-sin(angle) * 20));
		point.y += physicshape->Movement_Y(point, (int)(cos(angle) * 20));
		if (ct->gts->map->get_bottom(point) ||
			ct->gts->map->get_left(point) ||
			ct->gts->map->get_right(point) ||
			ct->gts->map->get_top(point)) {
			GravityStar::gravitypoint = point;
			contact = true;
		}
	}
	else {
	}
	attack();
	shape->draw(point);
}

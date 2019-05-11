#include"NormalStar.h"
#include"DxLib.h"
#include"CoreTask.h"

//--------------------------------
//
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	point = point_;
	shape->set("star");
}

void NormalStar::update()
{
	gravitypoint = GravityStar::point;
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", point);
	if (!contact) {
		point.x += physicshape->Movement_X(point, (int)(-sin(angle) * 20));
		point.y += physicshape->Movement_Y(point, (int)(cos(angle) * 20));
		if (ct->gts->map->get_bottom(point) ||
			ct->gts->map->get_left(point) ||
			ct->gts->map->get_right(point) ||
			ct->gts->map->get_top(point)) {
			contact = true;
		}
	}
	else {
		inhale();
	}
	attack();
	shape->draw(point);
}

void NormalStar::inhale()
{
	
	point.x += (GravityStar::gravitypoint.x -point.x) / 100;///100は近づかせるのを減衰させるため
	point.y += (Star::gravitypoint.y - point.y)/100;
}

#include"NormalStar.h"
#include"DxLib.h"
#include"CoreTask.h"

//--------------------------------
//
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	point = point_;
	shape->set("NormalStar");
	life = 180;
	gravitypoint = { 0,0,0,0 };
}

void NormalStar::update()
{
	Point sizeup{ point.x - 1,point.y - 1,point.w + 2,point.h + 2 };
	if (!contact) {
		point.x += physicshape->Movement_X(point, (int)(-sin(angle) * 20));
		point.y += physicshape->Movement_Y(point, (int)(cos(angle) * 20));
		if (ct->gts->map->get_bottom(sizeup) ||
			ct->gts->map->get_left(sizeup) ||
			ct->gts->map->get_right(sizeup) ||
			ct->gts->map->get_top(sizeup)) {
			contact = true;
		}
	}
	else {

		for (auto itr = ct->gts->gravityStar.begin(); itr != ct->gts->gravityStar.end(); ++itr) {
			gravitypoint = itr->gravitypoint;
		}
		if (((gravitypoint.x + gravitypoint.w / 2) - (point.x + point.w/2)) * ((gravitypoint.x + gravitypoint.w / 2) - (point.x + point.w/2)) +//gravitystarとの距離を測って90000以内なら引き寄せられる
			((gravitypoint.y + gravitypoint.h / 2) - (point.y + point.h/2)) * ((gravitypoint.y + gravitypoint.h / 2) - (point.y + point.h/2)) <=90000) {//90000は大体今の画面内の範囲
			inhale();
		}
	}
	attack();
	if (life > 60) {
		shape->draw(point);
	}
	else if (life % 4 >= 2) {
		shape->draw(point);
	}

}

void NormalStar::inhale()
{

	point.x += physicshape->Movement_X(point,(gravitypoint.x - point.x) / 10);///10は近づかせるのを減衰させるため
	point.y += physicshape->Movement_Y(point,(gravitypoint.y - point.y)/10);
}

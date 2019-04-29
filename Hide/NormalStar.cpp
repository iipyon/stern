#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	point = point_;
	shape->set("star");
}

void NormalStar::update()
{
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
		/*int prevelX = int(-sin(angle) * velocityX);
		int prevelY = int(cos(angle) * velocityY);
		while (prevelX != 0) {
			int preX = point.x;
			if (-sin(angle) *velocityX >= 1) { point.x += 1; prevelX -= 1; }
			else if (-sin(angle) *velocityX <= -1) { point.x -= 1; prevelX += 1; }
			Point hit = point;
			if (ct->gts->map->get_circle(point, radius)) {
				contact = true;
				break;
			}
		}
		while (prevelY != 0) {
			int preY = point.y;
			if (cos(angle) *velocityY >= 1) { point.y += 1; prevelY -= 1; }
			else if (cos(angle) *velocityY <= -1) { point.y -= 1; prevelY += 1; }
			Point hit = point;
			if (ct->gts->map->get_circle(point, radius)) {
				contact = true;
				break;
			}
		}*/
	}
	else {
		//exercise();
	}
	attack();
	shape->draw(point);
	/*if (damage(1)) {
		//ct->gts->normalstar->destroy();
	}*/
}

void NormalStar::inhale(int, int, float)
{
	/*gravity_point = ct->gts->gravitystar->get()->get_point();
	velocityX += (gravity_point.x - point.x) * 5;
	velocityY += (gravity_point.x - point.x) * 5;*/
}

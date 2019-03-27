#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	init_render("star");
}

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", angle);
	if (!contact) {
		point.x += (int)(-sin(angle) * velocityX);
		point.y += (int)(cos(angle) * velocityY);
		/*if (ct->gts->map->get_bottom(Point{ point.x,point.y,point.w,point.h }) &&
			ct->gts->map->get_top(Point{ point.x,point.y,point.w,point.h }) &&
			ct->gts->map->get_left(Point{ point.x,point.y,point.w,point.h }) &&
			ct->gts->map->get_right(Point{ point.x,point.y,point.w,point.h })) {
			contact = true;
		}*/
	}
	else {
		this->exercise();
	}
	if (attack()) {
	}

	draw(true);
	if (damage(1)) {
		//ct->gts->normalstar->destroy();
	}
}

void NormalStar::inhale(int, int, float)
{
}


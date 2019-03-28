#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

NormalStar::NormalStar(Point point_, PhysicState physic_state_, StarState star_state) : Star(point_, physic_state_, star_state)
{
	velocityX = 3;
	velocityY = 3;
	init_render("star");
}

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", angle);
	if (!contact) {
		point.x += (int)(-sin(angle) * velocityX);
		point.y += (int)(cos(angle) * velocityY);
		if (ct->gts->map->get_circle(point,radius)){
			contact = true;
		}
	}
	else {
		exercise();
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
	/*gravity_point = ct->gts->gravitystar->get()->get_point();
	velocityX += (gravity_point.x - point.x) * 5;
	velocityY += (gravity_point.x - point.x) * 5;*/
}

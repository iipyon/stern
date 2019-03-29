#include"Goal.h"
#include"CoreTask.h"


Goal::Goal(Point point_): Rendering(point_)
{

}

void Goal::init()
{
	init_render("goal");
}

void Goal::update()
{
	if (hit(ct->gts->player->get_point())) {
		ct->cts->init();
		to_cleartask();
	}
}

bool Goal::hit(Point player_)
{
	if (player_.x < point.x + point.w &&
		player_.x + player_.w > point.x &&
		player_.y < point.y + point.h &&
		player_.y + player_.h > point.y)
	{
		to_cleartask();
	}
	draw(true);
	return false;
}

void Goal::to_cleartask()
{
	//クリアシーンに遷移
	ct->scene = Scene::clear;
}

#include"Goal.h"
#include"CoreTask.h"
#include "BasicObject.h"

Goal::Goal(Point point_):  BasicObject(point)
{
}

void Goal::spawn(int x_,int y_,int w_,int h_)
{
	g_point = { x_,y_,w_,h_ };
}
void Goal::init()
{
	point = g_point;
	shape->set("goal");
}

void Goal::update()
{
	if (hit(ct->gts->player->get_point())) {
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
	shape->draw(point);
	return false;
}

void Goal::to_cleartask()
{
	//クリアシーンに遷移
	ct->gts->finalize();
	ct->cts->init();
	ct->scene = Scene::clear;
}

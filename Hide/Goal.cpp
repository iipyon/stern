#include"Goal.h"
#include"CoreTask.h"
#include "BasicObject.h"

bool Goal::get_clear_flag()
{
	return clear_flag;
}

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
	DrawString(0, 0, "ゴールは現在仮処理です,これが消えたらゴールの完成です", GetColor(255, 0, 0));
	if (hit(ct->gts->player->get_point())) {
		clear_flag = true;//プレイヤーと触れたらクリア（仮処理）
	}

	shape->draw(point);
}

bool Goal::hit(Point player_)
{
	if (player_.x < point.x + point.w &&
		player_.x + player_.w > point.x &&
		player_.y < point.y + point.h &&
		player_.y + player_.h > point.y)
	{
		return true;
	}
	
	return false;
}

#include"Goal.h"
#include"CoreTask.h"
#include "BasicObject.h"
#include "Scene.h"

bool Goal::get_clear_flag()
{
	return clear_flag;
}

void Goal::set_clearflag(bool clear_)
{
	clear_flag = clear_;
}

Goal::Goal(Point point_):  BasicObject(point)
{
}

//生成場所
void Goal::spawn(int x_,int y_)
{
	//StageSelectTaskの方で呼んで座標を決定
	//ヒットベース設定
	g_point = { x_,y_,128,128};
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

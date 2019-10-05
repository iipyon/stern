#include "Camera.h"
#include "CoreTask.h"
#include "System.h"

Point Camera::range;
bool Camera::mode;//enumで用意する可能性あり
int Camera::preX;//移動前の座標
int Camera::preY;

void Camera::init()
{
	//初期値を設定
	range.x = 0;
	range.y = 300;
	range.w = System::width;
	range.h = System::height;
}
void Camera::update()
{
	//カメラの位置を再調整
	{
		//プレイヤを画面の何処に置くか
		int px = System::width / 4;
		int py = System::height / 8;
		//プレイヤを画面中央の置いた時のカメラの左上座標を求める
		int cpx = ct->gts->player->get_point().x - px+ ct->gts->player->get_point().w/2;//player.wの半分だけたす
		int cpy = ct->gts->player->get_point().y - py + ct->gts->player->get_point().h / 2;
		//カメラの座標を更新
		range.x = cpx;
		range.y = cpy;
	}
}
void Camera::move(int, int)
{
}

bool Camera::get()
{
	return false;
}

Point Camera::get_range()
{
	return range;
}
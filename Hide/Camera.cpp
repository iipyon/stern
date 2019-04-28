#include "Camera.h"
#include "CoreTask.h"

Point Camera::range;
bool Camera::mode;//enumで用意する可能性あり
int Camera::preX;//移動前の座標
int Camera::preY;

void Camera::init()
{
	//初期値を設定
	range.x = 0;
	range.y = 300;
	range.w = 600;
	range.h = 600;
}
void Camera::update()
{
	//矩形の座標を文字で表示
	DrawFormatString(0, 300, GetColor(255, 255, 255), "range.x : %d", range.x);
	DrawFormatString(0, 320, GetColor(255, 255, 255), "range.y : %d", range.y);

	//カメラの位置を再調整
	{
		//プレイヤを画面の何処に置くか(今回は画面中央)
		int px = range.w / 2;
		int py = range.h / 2;
		//プレイヤを画面中央の置いた時のカメラの左上座標を求める
		int cpx = int(ct->gts->player->get_point().x) - px;
		int cpy = int(ct->gts->player->get_point().y) - py;
		//カメラの座標を更新
		range.x = cpx;
		range.y = cpy;
	}
	////プレイヤ中心としてX,Y座標を取り続ける
	//range.x = ct->gts->player->get_point().x;
	//range.y = ct->gts->player->get_point().y;


	////プレイヤを画面の中央に置く
	//int px = range.w / 2;
	//int py = range.h / 2;
	////プレイヤを画面中央に置いた時カメラの左上座標を求める
	//int cpx = range.x - px;
	//int cpy = range.y - py;
	////カメラ座標を更新
	//range.x = cpx;
	//range.y = cpy;
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
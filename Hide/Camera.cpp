#include "Camera.h"
#include "CoreTask.h"


void Camera::update()
{
	//プレイヤ中心としてX,Y座標を取り続ける
	range.x = ct->gts->player->get_point().x;
	range.y = ct->gts->player->get_point().y;
	
}

void Camera::move(int, int)
{
}

bool Camera::get()
{
	return false;
}

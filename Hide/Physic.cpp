#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//物理運動
//----------------------------------


void Physic::exercise(Point Chara)
{
	//重力による落下
	velocityY += ((gravity / 60) / 60) * 32;  //32のところは１メートルが32ピクセル

	if (velocityX <= 0.5f && velocityY <= 0.5f) {
		repulsion = 0.0f;
	}
	if (ct->gts->map->get_bottom(Chara)) {
		rebound_Y();
	}
	if (ct->gts->map->get_left(Chara) || ct->gts->map->get_right(Chara)) {
		rebound_X();
	}
}

void Physic::rebound_X()
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}
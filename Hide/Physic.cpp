#include "Physic.h"
#include "CoreTask.h"
//----------------------------------
//物理運動
//----------------------------------

Physic::Physic(Point point, PhysicState physic_state) : Rendering(point)
{
	gravity = physic_state.gravity;
	repulsion = physic_state.repulsion;
	weight = physic_state.weight;
}


void Physic::exercise()
{
	//重力による落下
	velocityY += gravity;  

	if (velocityX <= 0.5f && velocityY <= 0.5f) {
		repulsion = 0.0f;
	}
	if (ct->gts->map->get_bottom(point)==1) {//＝＝1の部分はマップ変更時に要変更
		rebound_Y();
	}
	if (ct->gts->map->get_left(point)==1 || ct->gts->map->get_right(point)==1) {
		rebound_X();
	}
	point.x += (int)velocityX;
	point.y += (int)velocityY;
}

void Physic::rebound_X()
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}
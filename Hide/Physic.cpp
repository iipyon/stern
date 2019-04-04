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
	int prevelX = int(velocityX);
	while (velocityX != 0) {
		int preX = point.x;
		if (velocityX >= 1) { point.x += 1; velocityX -= 1; }
		else if (velocityX <= -1) { point.x -= 1; velocityX += 1; }
		Point hit = point;
		if (ct->gts->map->get_left(hit) == 1 || ct->gts->map->get_right(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			point.x = preX;
			velocityX = 0;
			//rebound_X();
			break;
		}
	}
	int prevelY = int(velocityY);
	while (prevelY != 0) {
		int preY = point.y;

		if (velocityY >= 1) { point.y += 1; prevelY -= 1; }
		else if (velocityY <= -1) { point.y -= 1; prevelY += 1; }
		Point hit = point;
		if (ct->gts->map->get_bottom(hit) == 1 || ct->gts->map->get_top(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			point.y = preY;
			velocityY = 0;
			//rebound_Y();
			break;
		}
	
	}

}

/*void Physic::rebound_X()
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}*/


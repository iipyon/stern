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


	while (velocityX != 0) {
		int preX = point.x;
		if (velocityX >= 1) { point.x += 1; velocityX -= 1; }
		else if (velocityX <= -1) { point.x -= 1; velocityX += 1; }
		else { velocityX = 0; }
		Point hit = point;
		if (ct->gts->map->get_hit(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			point.x = preX;
			velocityX = 0;
			//rebound_X();
			break;
		}
	}
	int prevelY = velocityY;
   	while (prevelY != 0) {
		int preY = point.y;
		if (velocityY >= 1) {point.y += 1; prevelY -= 1; }
		else if (velocityY <= -1) {point.y -= 1; prevelY += 1; }

		Point hit = point;
		if (ct->gts->map->get_hit(hit) == 1) {//＝＝1の部分はマップ変更時に要変更
			point.y = preY;
			velocityY = 0;
			//rebound_Y();
			break;
		}
	
	}

}

/*void Physic::rebound_X()//バウンドの処理が必要になったら書くよ
{
	velocityX *= -repulsion;
}

void Physic::rebound_Y()
{
	velocityY *= -repulsion;
}*/


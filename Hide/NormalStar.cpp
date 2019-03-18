#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"CoreTask.h"


//--------------------------------
//普通の星
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//仮の移動//move（）作らね？
	if (contact) {
		x += (int)(-sin(angle) * velocityX);
		y += (int)(cos(angle) * velocityY);
		if (ct->gts->map->get_bottom&&ct->gts->map->get_top&&ct->gts->map->get_left&&ct->gts->map->get_right) {
			contact = true;

		}
	}
	else {
		this->exercise();
	}
	if (attack()) {
		//enemyのダメージを呼ぶ
	}

	draw();
	if (damage(1)) {
		ct->gts->normalstar->destroy();
	}
	//if(gravitystarがあるかどうか)｛//重力がかかる範囲を決めて近くになかったらfalseでもいいかも
	//gravitystarの座標を取り続ける
	//inhale(gravitystarの座標);
	//｝
}

void NormalStar::inhale(int, int, float)
{
	//移動量にgravitystarの座標との差を出して足し続ける
}


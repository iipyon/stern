#include "EnemyShot00.h"
#include"DxLib.h"
#include<math.h>
#include "CoreTask.h"

EnemyShot00::EnemyShot00(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	velocityY = 1;
	init_render("shot");
}

void EnemyShot00::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", velocityX);
	point.x += (int)velocityX;
	if (attack()) {
	}
	draw(true);
	if (damage(1)) {
		//ct->gts->enemy_shot00->destroy();
	}
}



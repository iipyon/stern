#include "BulletEnemy.h"
#include"DxLib.h"

BulletEnemy::BulletEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	init_render("bullet");
	switch (enemy_state_.anglestate) {
	case AngleState::left:
		angle = 1;
		break;
	case AngleState::right:
		angle = -1;
		break;
	}
}

void BulletEnemy::move()
{
	velocityX = (float)angle;
	point.x += (int)velocityX;
}

void BulletEnemy::update()
{
	DrawFormatString(300, 100, GetColor(255, 0, 0), "%d", velocityX);
	move();
	exercise();
	draw(true);
}

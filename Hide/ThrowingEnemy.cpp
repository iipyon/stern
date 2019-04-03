#include "ThrowingEnemy.h"
#include "CoreTask.h"


ThrowingEnemy::ThrowingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	anglestate = AngleState::right;
	x = -1;
	cnt = 180;
	init_render("thro");
}

void ThrowingEnemy::move()
{
	switch (anglestate)
	{
	case AngleState::right:
		//向き
		x = -1;
		break;
	case AngleState::left:
		x = 1;
		break;
	}
	//5秒間隔で弾を発射
	++cnt;
	if (cnt > 300) {
		class Point point = { x,0,0,0 };
		struct PhysicState physic_state = { 0,0,0 };//	float gravity; float repulsion;int weight;
		struct EnemyState Enemy_state = { 1,1 };//	int life, int damage, int power, int life, double angle;

		ct->gts->enemy_shot00.push_back(EnemyShot00{ point,physic_state,Enemy_state });	//新規インスタンスを生成して最後尾へ登録する
		cnt = 0;
	}
}

void ThrowingEnemy::playercheck_right()
{
	//プレイヤーの座標が敵より小さかったら左に向く
	if (ct->gts->player->get_point().x < point.x) {
		anglestate = AngleState::right;
	}
}

void ThrowingEnemy::playercheck_left()
{
	//プレイヤーの座標が敵より大きかったら右に向く
	if (ct->gts->player->get_point().x > point.x) {
		anglestate = AngleState::left;
	}
}

void ThrowingEnemy::update()
{
	exercise();
	move();
	DrawFormatString(400, 0, GetColor(0, 0, 0), "%d");
	//draw(true);
}



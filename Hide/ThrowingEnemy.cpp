#include "ThrowingEnemy.h"
#include "CoreTask.h"

ThrowingEnemy::ThrowingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_) : Enemy(point_, physic_state_, enemy_state_)
{
	//必要か判断ができない初期化処理
	anglestate = AngleState::right;
	x = -1;
	cnt = 0;
	shape->set("throwing");
}

void ThrowingEnemy::move()
{
	cnt++;
	change_angle();
	point.y+= physicshape->fall(point);
	appear_shot();
}

void ThrowingEnemy::appear_shot()
{
	if (cnt > 180) {
		class Point b_point = { point.x,point.y,0,0 };
		struct PhysicState physic_state = { 0};//	float gravity; float repulsion;int weight;
		struct EnemyState Enemy_state = { 1,1,anglestate };//	int life, int damage, int power, int life, double angle;

		ct->gts->enemy_transaction->push_back(std::make_unique<BulletEnemy>(b_point,physic_state,Enemy_state ));	//新規インスタンスを生成して最後尾へ登録する
		cnt = 0;
	}
}

void ThrowingEnemy::change_angle()
{
	//プレイヤーの座標が敵より小さかったら左に向く
	if (ct->gts->player->get_point().x < point.x) {
		anglestate = AngleState::right;
		//右向きアニメに変える
	}
	else {
		anglestate = AngleState::left;
	}
}

AngleState ThrowingEnemy::get_anglestate()
{
	return anglestate;
}




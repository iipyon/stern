#pragma once
#include"Enemy.h"

//---------------------------------
//雑魚敵(飛行)
//---------------------------------

class FlyingEnemy : public Enemy{
public:
	FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	//NormalEnemy* list;//リスト構造のため一応記述
	//メソッド
	void move();
	void update();
protected:

};
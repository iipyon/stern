#pragma once
#include"Enemy.h"

//--------------------------------
//ボス敵
//--------------------------------

class Boss : public Enemy {
public:
	Boss(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	//メソッド
	void move();

protected:
private:
};
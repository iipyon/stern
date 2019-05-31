#pragma once
#include"Enemy.h"

class ThrowingEnemy :public Enemy {
public:
	ThrowingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move() override;//移動
	void appear_shot();
	void change_angle();
	AngleState get_anglestate();

private:
	int x;
	int cnt;
	AngleState beforeangle;
protected:
};
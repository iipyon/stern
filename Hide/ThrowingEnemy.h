#pragma once
#include"Enemy.h"

class ThrowingEnemy :public Enemy {
public:
	//Enemyに共通するためEnemyClassにいれてもいいかもしれない
	enum class AngleState {
		left,
		right
	};
	AngleState anglestate;

	ThrowingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	void move();
	void update();
	void playercheck_left();
	void playercheck_right();

private:
	int x;
	int cnt;
protected:
};
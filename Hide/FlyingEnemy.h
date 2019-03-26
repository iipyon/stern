#pragma once
#include"Enemy.h"

//---------------------------------
//---------------------------------

class FlyingEnemy : public Enemy{
	
public:
	enum class FlyingState
	{
		fly,
		stay
	};
	FlyingState flyingstate;
	FlyingEnemy(Point point_, PhysicState physic_state_, EnemyState enemy_state_);
	//NormalEnemy* list;//リスト構造のため一応記述
	void move();
	void update();
private:
	int FlyingEnemycnt = 0;
protected:
};

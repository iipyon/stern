#pragma once
#include"Enemy.h"

//--------------------------------
//ボス敵
//--------------------------------

class Boss : public Enemy {
public:
	enum class BossState
	{
		walk,
		jump,
		stay
	};
	BossState bossstate;
	Boss(Point point_, PhysicState physic_state_, EnemyState enemy_state_);

	void move() override;
	void change_angle();
	void change_state();
	AngleState get_anglestate();
protected:
	int movecnt;
	float preY; //前のフレームのvelocityYを保持 
private:
};
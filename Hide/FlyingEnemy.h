�ｿ#pragma once
#include"Enemy.h"

//---------------------------------
//髮鷹ｭ壽雰(鬟幄｡)
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
	//謨ｵ縺瑚｡悟虚縺吶ｋ繧ｫ繧ｦ繝ｳ繧ｿ繝ｼ
	int FlyingEnemycnt = 0;
protected:
};
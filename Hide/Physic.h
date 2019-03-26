#pragma once
#include"Rendering.h"

//---------------------------------
//物理運動
//---------------------------------

struct PhysicState {
	float gravity;
	float repulsion;
	int weight;
};

class Physic : public Rendering {
public:
	Physic(Point point,PhysicState physic_state);
	//メソッド
	void exercise();//物理運動を行うものだけ処理を行う
protected:
	//変数
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)

	void rebound_X();
	void rebound_Y();
};

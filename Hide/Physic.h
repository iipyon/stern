#pragma once
#include"BasicObject.h"

//---------------------------------
//物理運動
//---------------------------------

struct PhysicState {
	float gravity;
	float repulsion;
	int weight;
};

class Physic : public BasicObject {
public:
	Physic(Point point,PhysicState physic_state);
	//メソッド
	virtual void exercise();//物理運動を行うものだけ処理を行う
	/*virtual void rebound_X();
	virtual void rebound_Y();*/
protected:
	//変数
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)


};

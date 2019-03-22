#pragma once
#include"Rendering.h"

//---------------------------------
//物理運動
//---------------------------------

class Physic : public Rendering {
public:
	Physic() {

		gravity = 0.5f;
		repulsion = 0;
		weight = 0;
	}
	//メソッド
	//float Gravity(float gra_);
	void exercise();//物理運動を行うものだけ処理を行う

protected:
	//変数
	Point point;
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)

	void rebound_X();
	void rebound_Y();
};

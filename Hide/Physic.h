#pragma once
#include"Rendering.h"
#include "Point.h"

//---------------------------------
//物理運動
//---------------------------------

class Physic : public Rendering {
public:
	Physic() {
		gravity = 9.8f;	//仮の数値
		repulsion = 0;
		weight = 0;
	}
	//メソッド
	//float Gravity(float gra_);
	void exercise(Point Chara);//物理運動を行うものだけ処理を行う
	void rebound_X();	//Xに対する反発係数
	void rebound_Y();	//Yに対する反発係数
protected:
	//変数
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)

};

#pragma once
#include"Animater.h"

//---------------------------------
//物理運動
//---------------------------------

class Physical : public Animater {
public:
	Physical() {
		gravity = 0;
		repulsion = 0;
		weight = 0;
	}
	//メソッド
	//float Gravity(float gra_);
	void exercise(bool judge);//物理運動を行うものだけ処理を行う
protected:
	//変数
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)

};

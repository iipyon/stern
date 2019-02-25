#pragma once
#include"BasicObject.h"

//---------------------------------
//物理運動
//---------------------------------

class Physical : public BasicObject {
public:
	Physical() :
		gravity(0),
		repulsion(0),
		weight(0)
	{}
	//メソッド
	//float Gravity(float gra_);
private:
	//変数
	float gravity;//重力
	float repulsion;//反発係数
	int weight;//重さ(物体)

};

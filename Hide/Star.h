#pragma once
#include"Physical.h"

//---------------------------------
//星全般
//---------------------------------

class Star : public Physical {
public:
	Star() {
		bright = 0;
		radius = 0;
	}
	//メソッド
	bool Attack();
private:
	//変数
	int bright;//輝度
	float radius;//半径(size)（円で判定を行うため）
};
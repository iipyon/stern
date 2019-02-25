#pragma once
#include"Physical.h"

//---------------------------------
//星全般
//---------------------------------

class Star : public Physical {
public:
	Star():
		bright(0),
		radius(0)
	{}
	//メソッド
private:
	//変数
	int bright;//輝度
	float radius;//半径（円で判定を行うため）
};
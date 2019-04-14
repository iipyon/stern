#pragma once
#include"BasicObject.h"

class Effect : public BasicObject {
public:
	Effect(Point);
	//追加メソッドがあれば記述
	void update();
private:
	double angle;
};
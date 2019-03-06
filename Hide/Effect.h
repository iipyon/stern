#pragma once
#include"Rendering.h"

class Effect : public Rendering {
public:
	Effect() {
		angle = 0;
	}
	//追加メソッドがあれば記述
	void update();
private:
	double angle;
};
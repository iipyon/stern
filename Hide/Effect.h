#pragma once
#include"Animater.h"

class Effect : public Animater {
public:
	Effect() {
		angle = 0;
	}
	//追加メソッドがあれば記述
private:
	double angle;
};
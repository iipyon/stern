#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

class NormalStar : public Star {
public:
	NormalStar(int power_, int life_, int weight_) : Star(power_, life_, weight_) {
		contact = false;
		bright = 0;
		radius = 0;
		graph = LoadGraph("img/star.png");
	};
	void update();
	void inhale(int, int, float);

private:
};
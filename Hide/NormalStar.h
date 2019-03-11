#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//ïÅí ÇÃêØ
//--------------------------------

class NormalStar : public Star {
public:
	NormalStar(int power_, int life_, int weight_) : Star(power_, life_, weight_) {
		x = 300;
		y = 100;
		contact = false;
		bright = 0;
		radius = 0;
		velocityX = 2;
		velocityY = 2;
		graph = LoadGraph("img/star.png");
	};
	void update();
	void inhale(int, int, float);

private:
};
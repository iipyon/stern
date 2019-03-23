#pragma once
#include"Star.h"
#include"DxLib.h"

//--------------------------------
//ïÅí ÇÃêØ
//--------------------------------

class NormalStar : public Star {
public:
	NormalStar(int power_, int life_, int weight_,int x_,double angle_) : Star(power_, life_, weight_,x_,angle_) {
		point.x = x_;
		point.y = 0;
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
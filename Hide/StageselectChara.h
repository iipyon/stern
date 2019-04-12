#pragma once
#include"BasicObject.h"

//キャラクター
class StageSelectChara{
private:
	Point point;
	float velocityX;
	int graph;
public:
	StageSelectChara(Point);
	void update(int&);
	void draw();
	void select_stage(int&);
	void move();
	int get_velocity();
};
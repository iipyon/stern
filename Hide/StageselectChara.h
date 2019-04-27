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
	void update(int&,bool);
	void draw();
	void select_stage(int&,bool);
	void move();
	int get_velocity();
};
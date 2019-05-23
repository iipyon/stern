#pragma once
#include"BasicObject.h"

//キャラクター
class StageSelectChara {
private:
	Point point;
	float velocityX;
	int graph;
public:
	StageSelectChara(Point);
	void initialize(Point);
	void update(int&, bool,int);
	void draw();
	void select_stage(int&, bool,int);
	void move();
	int get_velocity();
};
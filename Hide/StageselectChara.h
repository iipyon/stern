#pragma once
#include"BasicObject.h"

//キャラクター
class StageSelectChara : public BasicObject {
private:
	int graph;
public:
	StageSelectChara();
	void update(int&);
	void draw();
	void select_stage(int&);
	void move();
	int get_velocity();
};
#pragma once

class StageSelectTaskMass {
private:
	//座標
	int x;
	int y;
	//画像
	int graph;
public:
	StageSelectTaskMass();
	void update();
	void draw();
};
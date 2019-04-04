#pragma once
#include"DxLib.h"
#include"Point.h"

class Camera {
public:
	//Camera();
	void update();
	void move(int, int);
	Point get_range(); //rangeの情報を送る
	//void change();
	bool get();
private:
	Point range;
	bool mode;//enumで用意する可能性あり
	int preX;//移動前の座標
	int preY;
};
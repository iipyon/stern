#pragma once
#include"DxLib.h"
#include"Point.h"

class Camera {
public:
	//Camera();
	static void init();
	static void update();
	static void move(int, int);
	static Point get_range(); //rangeの情報を送る
	//void change();
	static bool get();
private:
	Camera();
	static Point range;
	static bool mode;//enumで用意する可能性あり
	static int preX;//移動前の座標
	static int preY;
};
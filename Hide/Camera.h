#pragma once
#include"DxLib.h"

class Camera {
public:
	//Camera();
	void update();
	void move(int, int);
	void change();
	bool get();
private:
	RECT range;
	bool mode;//enumで用意する可能性あり
	int prex;//移動前の座標
	int prey;
};
#pragma once
#include"Point.h"
//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject() {
		velocityX = 0;
		velocityY = 0;
		x = 0;
		y = 0;
		width;
		height;
	}

	//メソッド（関数）
	virtual void update();
	void get_point();

protected:
	int x;
	int y;
	int width;
	int height;
	Point point;
	//移動量
	float velocityX;
	float velocityY;
};
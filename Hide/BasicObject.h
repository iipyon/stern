#pragma once
#include"Point.h"
#include "Rendering.h"
#include <memory>

//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject(Point);
	//メソッド（関数）
	virtual void update() = 0;
	Point get_point();

protected:
	std::unique_ptr<Rendering> shape;	//姿・形
	Point point;
	//移動量
	float velocityX;
	float velocityY;
};
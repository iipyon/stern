#pragma once
#include"Point.h"
#include "Rendering.h"
#include <memory>
#include"Physic.h"

//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject(Point);
	//メソッド（関数）
	virtual void update() = 0;

	//accessor
	Point get_point();	//非推奨 廃止予定
	int get_x();
	void set_x(int);
	int get_y();
	void set_y(int);
	int get_width();
	void set_width(int);
	int get_height();
	void set_height(int);



protected:
	std::unique_ptr<Rendering> shape;	//姿・形
	std::shared_ptr<Physic> physicshape;
	Point point;
	//移動量
	/*float velocityX;//多分いらない
	float velocityY*/
};
#pragma once
#include"BasicObject.h"
#include"Player.h"

class Door :public BasicObject {
public:
	void act();
	void update();
protected:
	bool check_contact(Point);//星との当たり判定
private:
	//int id;
	bool status;//状態
};
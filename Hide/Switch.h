#pragma once
#include"BasicObject.h"
#include"Player.h"

class Switch :public BasicObject {
public:
	void act();
	void update();
protected:
	bool check_contact(Point);//敵との当たり判定
private:
	//int id;
};


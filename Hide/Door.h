#pragma once
#include"BasicObject.h"
#include"Player.h"

class Door :public BasicObject {
public:
	void act();
	void update();
protected:
	bool check_contact(Point);//¯‚Æ‚Ì“–‚½‚è”»’è
private:
	//int id;
	bool status;//ó‘Ô
};
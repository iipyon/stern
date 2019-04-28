#pragma once
#include"Point.h"

//---------------------------------
//物理運動
//---------------------------------

struct PhysicState {
	float gravity;

};

class Physic {
public:
	Physic() ;
	//メソッド
	int fall(Point);//物理運動を行うものだけ処理を行う
	int Movement_X(Point, int);
	int Movement_Y(Point, int);
protected:
	//変数
	float gravity;//重力
private:
	int velocity;


};

#pragma once
#include"Physical.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physical {
public :
	Enemy():
		life(0)
	{}
	//メソッド
	void Move();
private:
	//変数
	int life;
};
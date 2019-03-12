#pragma once
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physic {
public :
	//メソッド
	Enemy(int, int, int) {

	}
	virtual void move();
	bool attack();
	void update();
	void damage(int);
protected:
	//変数
	int hp;//残り体力
	int power;
	int knock_back;

	enum state {

	};

};
#pragma once
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physic {
public :
	//メソッド
	Enemy();
	Enemy *Enmyupdate;
	
	virtual void move();
	bool attack();
	void update();
	bool damage(int);

protected:
	//変数
	int hp;//残り体力
	int power;
	int knock_back;

	enum state {

	};

};
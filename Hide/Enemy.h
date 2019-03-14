#pragma once
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physic {
public :
	int life;
	int damaged;
	int gravity;
	//メソッド
	//コンストラクタ
	Enemy();
	Enemy(int E_life, int E_damaged, int E_gravity);
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
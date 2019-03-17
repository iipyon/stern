#pragma once
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physic {
	//メンバー関数
	int life;
	int damaged;
	int gravity;
public :
	//メソッド
	//コンストラクタ
	Enemy();
	Enemy(int E_life, int E_damaged, int E_gravity);
	//仮想関数
	virtual void move() {

	}
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
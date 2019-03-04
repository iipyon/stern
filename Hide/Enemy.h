#pragma once
#include"Physical.h"

//----------------------------------
//敵全般
//----------------------------------

class Enemy :public Physical {
public :
	Enemy() {
		hp = 0;
		damage = 0;
	}
	//メソッド
	virtual void Move();
	bool Attack();
protected:
	//変数
	int hp;//残り体力
	int damage;
};
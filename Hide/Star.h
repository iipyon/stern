#pragma once
#include"Physic.h"

//---------------------------------
//星全般
//---------------------------------

class Star : public Physic {
public:
	Star(int, int, int);
	//メソッド
	bool attack();
	bool damage(int);

private:
	//変数
	int bright;//輝度
	int radius;//半径(size)（円で判定を行うため）
	bool contact;
	int power;
	int life;
};
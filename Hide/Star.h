#pragma once
#include"Physic.h"

//---------------------------------
//星全般
//---------------------------------

struct StarState {
	int bright;
	int radius;
	int power;
	int life;
	double angle;
};

class Star : public Physic {
public:
	Star(Point point_, PhysicState physic_state_, StarState star_state);
	//Star();//これを抜くとNormalStarコンストラクタでエラーが起こる
	//メソッド
	bool attack();
	bool damage(int);


protected:
	//変数
	double angle;
	int bright;//輝度
	int radius;//半径(size)（円で判定を行うため）
	bool contact;
	int power;
	int life;

	void exercise();
	bool check_hit(Point);
private:
	void rebound_X();
	void rebound_Y();
};
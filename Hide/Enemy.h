#pragma once
#include"Physic.h"

//----------------------------------
//敵全般
//----------------------------------

//Enemyに共通するためEnemyClassにいれてもいいかもしれない
enum class AngleState {
	left,
	right
};

struct EnemyState {
	int life;
	int damage;
	AngleState anglestate;
};

class Enemy :public Physic {
private:
	//プロパティ
	int life;
	int damaged;
	int gravity;


public :
	Enemy(Point point, PhysicState physic_state, EnemyState enemy_state);
	//メソッド
	virtual void update();
	virtual bool damage(int);

protected:
	//プロパティ
	int hp;//残り体力
	int power;
	int knock_back;
	AngleState anglestate;
	//メソッド
	virtual void move();
	virtual bool attack();

};
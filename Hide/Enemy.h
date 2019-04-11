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
	//メンバー関数
	int life;
	int damaged;
	int gravity;
public :
	//メソッド
	//コンストラクタ
	Enemy(Point point, PhysicState physic_state,EnemyState enemy_state);
	//仮想関数
	virtual void move() {

	}
	virtual bool attack();
	virtual void update();
	virtual bool damage(int);

protected:
	//変数
	int hp;//残り体力
	int power;
	int knock_back;
	AngleState anglestate;

};
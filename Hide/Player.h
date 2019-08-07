#pragma once
#include"BasicObject.h"
#include"Physic.h"
#include"DxLib.h"
#include<memory>
//#include "Item.h"
//#include "RecoveryItem.h"
#include"application_helper.h"


//---------------------------------
//プレイヤー
//---------------------------------

class Player :public BasicObject {

	friend class RecoveryItem;
public:
	Player(Point point_, PhysicState physic_state_);
	void init();
	//メソッド
	void update();//更新処理
	bool damage();//ダメージを受ける処理

	//void anim();

	void move();//移動処理

	void spawn(int, int, int, int);

	void createfook(Point);

	void think();

	enum Motion {
		Stop,
		Dash,
		Jump,
		Fall,
		Jump2,
		Fall2,
	};

	Motion motion;


public:	//アクセサメソッド

	void set_angle(double);
	double get_angle();
	void set_invincible(int);
	int get_invincible();


	
protected:
	//変数
	float speed;
	double angle;//カーソルの傾き
	int invincible;//無敵時間
	enum Angle_LR{Left,Right};
	Angle_LR angle_LR;
	

	int preY; //前のフレームのvelocityYを保持
	int interval;//星の発射間隔

private:
	//void anim(); 
	//bool damageanim;
	int moveCnt;

	class Point p_point;
};

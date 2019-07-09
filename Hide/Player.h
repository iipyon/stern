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
	bool recover();

	void draw_interface(int);//UI描画
	void move();//移動処理

	bool knockback(int);//ノックバック
	void jump(int);
	void spawn(int, int, int, int);

	void createfook(Point);

public:	//アクセサメソッド
	void set_hp(int);
	int get_hp();
	void set_angle(double);
	double get_angle();
	void set_invincible(int);
	int get_invincible();
	void set_life(int);
	int get_life();


	//プレイヤーインターフェイス
	class PlayerInterface {
	public:
		PlayerInterface();

		//メソッド
		void draw();
		void update(int ,int);
	private:

		int hp;
		int life;
		int hpgraph;
		int hpfreamgraph;
		int lifegraph;

	
	};

	
	int hp;//HP
protected:
	//変数
	int life;//残機
	double angle;//カーソルの傾き
	int invincible;//無敵時間
	enum Angle_LR{Left,Right};
	Angle_LR angle_LR;
	

	int preY; //前のフレームのvelocityYを保持
	int interval;//星の発射間隔
	bool knockback_status;//ノックバック中か
	std::unique_ptr<PlayerInterface> playerinterface;

private:
	void anim(); 
	bool damageanim;
	int jumpCnt;
	class Point p_point;
};

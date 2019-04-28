#pragma once
#include"BasicObject.h"
#include"Physic.h"
#include"DxLib.h"
#include<memory>
//#include "Item.h"
//#include "RecoveryItem.h"
#include"Function.h"


//---------------------------------
//プレイヤー
//---------------------------------

struct PlayerState {
	int life;
	int hp;
};

class Player :public BasicObject {

	friend class RecoveryItem;
	friend class Enemy;
public:
	Player(Point point_, PhysicState physic_state_,PlayerState player_state);
	void init();
	//メソッド
	double get_angle();//星の移動のために角度情報が必要
	void update();//更新処理
	bool damage();//ダメージを受ける処理
	void draw_interface(int);//UI描画
	void move();//移動処理
	bool knockback(int);//ノックバック
	void jump(int);

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

	//星を出すカーソル
	class StarManager {
	public:
		StarManager();
		//メソッド
		void draw(double st, int x);
		void update(double ang,int x);
	private:
		int life;
		int graph;
	};
	int hp;//HP
protected:
	//変数
	int life;//残機
	double angle;//カーソルの傾き
	int invincible;//無敵時間

	int preY; //前のフレームのvelocityYを保持
	int interval;//星の発射間隔
	bool knockback_status;//ノックバック中か
	std::unique_ptr<StarManager> starmanager;
	std::unique_ptr<PlayerInterface> playerinterface;

private:
	int jumpCnt;
};

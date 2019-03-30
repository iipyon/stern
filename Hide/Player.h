#pragma once
#include"Physic.h"
#include"DxLib.h"
#include<memory>


//---------------------------------
//プレイヤー
//---------------------------------

struct PlayerState {
	int life;
	int hp;
};

class Player :public Physic {
public:
	Player(Point point_, PhysicState physic_state_,PlayerState player_state);
	void init();
	void initialize();
	//メソッド
	double get_angle();//星の移動のために角度情報が必要
	void update();//更新処理
	bool damage(void);//ダメージを受ける処理
	void draw_interface(int);//UI描画
	void move();//移動処理
	bool knockback(int);//ノックバック

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

protected:
	//変数
	int life;//残機
	double angle;//カーソルの傾き
	int invincible;//無敵時間
	int hp;//HP
	float preY; //前のフレームのvelocityYを保持
	int interval;//星の発射間隔
	bool knockback_status;//ノックバック中か
	std::unique_ptr<StarManager> starmanager;
	std::unique_ptr<PlayerInterface> playerinterface;
};

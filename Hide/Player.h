#pragma once
#include"Physic.h"
#include"DxLib.h"
#include<memory>


//---------------------------------
//プレイヤー
//---------------------------------

class Player :public Physic {
public:
	Player();
	//メソッド
	double get_angle();//星の移動のために角度情報が必要
	void update();//更新処理
	bool damage(void);//ダメージを受ける処理
	void draw_interface(int);//UI描画
	void move();//移動処理
	void check_foot();//足元判定
	bool knockback(int);//ノックバック

	//プレイヤーインターフェイス
	class PlayerInterface {
	public:
		PlayerInterface() {
		}
		//メソッド
		void Draw(int st);
	private:
		int life;
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
	int interval;//星の発射間隔
	bool foot_status;//設置しているか
	bool knockback_status;//ノックバック中か
	std::unique_ptr<StarManager> starmanager;
};

#pragma once
#include"Physic.h"
#include"DxLib.h"

//---------------------------------
//プレイヤー
//---------------------------------

class Player :public Physic {
public:
	Player()
	{
		life = 0;
		angle = 0;
		invincible = 0;
		hp = 0;
		interval = 0;
		graph = LoadGraph("img/player.png");
	}
	//メソッド
	void update();//更新処理
	bool damage(void);//ダメージを受ける処理
	void draw_interface(int);//UI描画
	void move();//移動処理
	void check_foot();//足元判定
	bool knockback(int);//ノックバック

protected:
	//変数
	int life;//残機
	double angle;//カーソルの傾き
	int invincible;//無敵時間
	int hp;//HP
	int interval;//星の発射間隔
	bool foot_status;//設置しているか
	bool knockback_status;//ノックバック中か

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
	class Cursor {
	public:
		Cursor(){}
		//メソッド
		void Draw(double st);
	private:
		int life;
	};

};
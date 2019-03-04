#pragma once
#include"Physical.h"

//---------------------------------
//プレイヤー
//---------------------------------

class Player :public Physical {
public:
	Player()
	{
		life = 0;
		angle = 0;
		invincible = 0;
		hp = 0;
		interval = 0;
	}
	//メソッド
	void Update();//更新処理
	bool Damage(void);//ダメージを受ける処理
protected:
	//変数
	double angle;//星を出す角度
	int invincible;//無敵時間
	int hp;//残り体力
	int interval;//星のクールタイム
	int life;//残機

	//プレイヤーインターフェイス
	class PlayerInterface {
	public:
		PlayerInterface() {
			//life = Player::life;
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
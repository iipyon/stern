#pragma once
#include"Physical.h"

//---------------------------------
//プレイヤー
//---------------------------------

class Player :public Physical {
public:
	Player():
		life(0)
	{}
	//メソッド
	bool Damage(void);//ダメージを受ける処理
private:
	//変数
	int life;//体力(HP)
};
#pragma once
#include"Enemy.h"

//---------------------------------
//雑魚敵(飛行)
//---------------------------------

class FlyingEnemy : public Enemy{
	enum FlyingState
	{
		fly,
		stay,
	};
public:
	//NormalEnemy* list;//リスト構造のため一応記述
	//メソッド
	void move();
	void update();
protected:

};
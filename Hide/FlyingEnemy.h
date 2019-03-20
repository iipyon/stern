#pragma once
#include"Enemy.h"

//---------------------------------
//雑魚敵(飛行)
//---------------------------------

class FlyingEnemy : public Enemy{
	enum class FlyingState
	{
		fly,
		stay,
	};
	FlyingState flyingstate;
public:
	//NormalEnemy* list;//リスト構造のため一応記述
	//メソッド
	void move();
	void update();
protected:

};
#pragma once
#include"Enemy.h"

//---------------------------------
//雑魚敵(飛行)
//---------------------------------

class FlyingEnemy : public Enemy{
	
	
	//NormalEnemy* list;//リスト構造のため一応記述
	//メソッド
	enum class FlyingState
	{
		fly,
		stay,
	};
	FlyingState flyingstate;
	void move();
	void update();
private:
protected:
};
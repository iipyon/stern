﻿#pragma once
#include"Enemy.h"

//---------------------------------
//雑魚敵(飛行)
//---------------------------------

class FlyingEnemy : public Enemy{
public:
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
#pragma once
#include"Star.h"

//--------------------------------
//普通の星
//--------------------------------

class NormalStar : public Star {
public:

	void update();
	void inhale(int,int,float);

private:
	//SmallStar *smallstar;//リスト用?
};
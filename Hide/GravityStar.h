#pragma once
#include"Star.h"

//---------------------------------
//第３の星（引力のある星）
//---------------------------------

class GravityStar :public Star {
public:
	void Inhale();//吸引
private:
protected:
	//GravityStar *gravitystar;//リスト用?
};
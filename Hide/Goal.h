#pragma once
#include"BasicObject.h"

class Goal : public BasicObject{
public:
	Goal(Point point_);
	void init();//Init_Renderを呼ぶ
	void update();
	bool hit(Point);
	void to_cleartask();
};
#pragma once
#include"BasicObject.h"

class Goal : public BasicObject{
public:
	bool get_clear_flag();
	void set_clearflag(bool);
	Goal(Point point_);
	void init();//Init_Renderを呼ぶ
	void update();
	bool hit(Point);
	void spawn(int, int);
private:
	class Point g_point;
	bool clear_flag;
};
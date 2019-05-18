//アプリケーション全体で利用する機能を記述するファイル
#include "ApplicationHelper.h"
bool CheckHit(Point attack_, Point defense_) {
	if (attack_.x <= defense_.x + defense_.w
		&&defense_.x <= attack_.x + attack_.w
		&&attack_.y <= defense_.y + defense_.h
		&&defense_.y <= attack_.y + attack_.h) {
		return true;
	}
	else {
		return false;
	}
}

bool CheckHit(BasicObject& obj1, BasicObject& obj2)
{
	Point p1, p2;
	p1.x = obj1.get_x();
	p1.y = obj1.get_y();
	p1.w = obj1.get_width();
	p1.h = obj1.get_height();

	p2.x = obj2.get_x();
	p2.y = obj2.get_y();
	p2.w = obj2.get_width();
	p2.h = obj2.get_height();
	return CheckHit(p1, p2);
}

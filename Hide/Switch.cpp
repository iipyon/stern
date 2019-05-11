#include "Switch.h"
void Switch::act()
{
	this->check_contact(point);

	//スイッチが押された状態
	if (true) {
		shape->set("switch02");
	}
	//スイッチが押されていない状態
	else { shape->set("switch01"); }
	
}
void Switch::update()
{
	this->act();
}
bool Switch::check_contact(Point e_)
{
	//敵との当たり判定
	if (e_.x < point.x + point.w &&
		e_.x + e_.w > point.x &&
		e_.y < point.y + point.h &&
		e_.y + e_.h > point.y)
	{
		return true;
	}
	else{ return false; }
}
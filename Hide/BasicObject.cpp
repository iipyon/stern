#include "BasicObject.h"

//-----------------------------------
//Šî–{‚Æ‚È‚éƒNƒ‰ƒX
//-----------------------------------

BasicObject::BasicObject(Point point_) {
	shape = std::make_unique<Rendering>();
	physicshape= std::make_shared<Physic>();
	/*velocityX = 0;
	velocityY = 0;*/
	point.x = point_.x;
	point.y = point_.y;
	point.w = point_.w;
	point.h = point_.h;
}

Point BasicObject::get_point()
{
	return point;
}

int BasicObject::get_x()
{
	return point.x;
}

void BasicObject::set_x(int x)
{
	point.x = x;
}

int BasicObject::get_y()
{
	return point.y;
}

void BasicObject::set_y(int y)
{
	point.y = y;
}

int BasicObject::get_width()
{
	return point.w;
}

void BasicObject::set_width(int w)
{
	point.w;
}

int BasicObject::get_height()
{
	return point.h;
}

void BasicObject::set_height(int h)
{
	point.h = h;
}
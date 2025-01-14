#include "BasicObject.h"

//-----------------------------------
//基本となるクラス
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

#include "Fook.h"

Fook::Fook(Point point_) : BasicObject(point_)
{
}

void Fook::update()
{

	shape->draw(point);
}

bool Fook::check_hit(Point pl)
{
	bool check = false;
	if (point.x < pl.x + pl.w &&
		point.x + point.w > pl.x &&
		point.y < pl.y + pl.h &&
		point.y + point.h > pl.y) {
		check = true;
	}
	return check;
}

#include "Item.h"
#include"CoreTask.h"

std::shared_ptr<Player> Item::player;	//静的メンバの実体化


Item::Item(Point point_) : BasicObject(point_)
{
}

void Item::update()
{
	if (check_hit(player->get_point())) {
		affect();
	}
	shape->draw(point);
}

bool Item::check_hit(Point pl)
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

#include "Item.h"
#include"CoreTask.h"
#include"application_helper.h"
std::shared_ptr<Player> Item::player;	//静的メンバの実体化


Item::Item(Point point_) : BasicObject(point_)
{
}

void Item::update()
{
	if (CheckHit(this->point,player->get_point())) {
		affect();
	}
	shape->draw(point);
}

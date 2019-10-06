#include "RecoveryItem.h"
#include"CoreTask.h"

RecoveryItem::RecoveryItem(Point point_) : Item(point_)
{
	shape->set("recovery");//画像
}

void RecoveryItem::affect()
{
	if (player->speed < 30 - 5) {
		player->speed += 5;
	}
	else {
		player->speed = 30;
	}
}

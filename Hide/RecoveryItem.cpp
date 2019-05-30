#include "RecoveryItem.h"
#include"CoreTask.h"

RecoveryItem::RecoveryItem(Point point_) : Item(point_)
{
	shape->set("recovery");//画像
}

void RecoveryItem::affect()
{
	if(player->hp<2)
	player->hp++;
	//回復
}

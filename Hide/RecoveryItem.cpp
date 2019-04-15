#include "RecoveryItem.h"
#include"CoreTask.h"

RecoveryItem::RecoveryItem(Point point_) : Item(point_)
{
	shape->set("recovery");//画像
}

void RecoveryItem::work()
{
	//回復
}

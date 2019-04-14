#include "RecoveryItem.h"
#include"CoreTask.h"

RecoveryItem::RecoveryItem(Point point_) : Item(point_)
{
	shape->set("recovery");//画像
}

void RecoveryItem::efficacy()
{
	//回復
	DrawString(300, 300, "呼ばれてるよ", GetColor(0, 255, 255));
	if (checkhit(ct->gts->player->get_point())) {
	}
}

#include"NormalStar.h"
#include"DxLib.h"

//--------------------------------
//普通の星
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//仮の移動
	y += (int)velocity;
	x += (int)velocity;

	draw();
}

void NormalStar::inhale(int, int, float)
{
}


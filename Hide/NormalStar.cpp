#include"NormalStar.h"
#include"DxLib.h"
#include<math.h>
#include"GameTaskSystem.h"

//--------------------------------
//普通の星
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//仮の移動
	x += (int)(-sin(angle) * velocityX);
	y += (int)(cos(angle) * velocityY);

	draw();
}

void NormalStar::inhale(int, int, float)
{
}


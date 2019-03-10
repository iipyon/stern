#include"NormalStar.h"
#include"DxLib.h"

//--------------------------------
//•’Ê‚Ì¯
//--------------------------------

void NormalStar::update()
{
	DrawFormatString(300, 0, GetColor(255, 0, 0), "%d", power);
	//‰¼‚ÌˆÚ“®
	y += (int)velocityY;
	x += (int)velocityX;

	draw();
}

void NormalStar::inhale(int, int, float)
{
}


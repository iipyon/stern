#include "Rendering.h"
#include"DxLib.h"

bool Rendering::switch_anime()
{
	return false;
}

void Rendering::draw()
{
	DrawGraph(point.x, point.y, graph, 1);
}

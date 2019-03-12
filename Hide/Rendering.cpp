#include "Rendering.h"
#include"DxLib.h"

bool Rendering::switch_anime()
{
	return false;
}

void Rendering::draw()
{
	DrawGraph(x, y, graph, 1);
}

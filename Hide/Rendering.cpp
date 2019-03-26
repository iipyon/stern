#include "Rendering.h"
#include"DxLib.h"
#include "CoreTask.h"

bool Rendering::switch_anime()
{
	return false;
}

void Rendering::draw(bool new_gen)
{
	if (new_gen == false) {
		//旧世代のhandleがintのタイプ、アニメーション不可
		//廃止予定の処理！！
		DrawGraph(point.x, point.y, graph, 1);
	}
	else {
		//新世代のhandleがint*タイプ、可変長のアニメーション可
		DrawGraph(point.x, point.y, *(handle_graph + cnt), 1);
	}
}

Rendering::Rendering(Point point) : BasicObject(point)
{
}

void Rendering::init_render(std::string scope)
{
	GraphicObject obj = ct->graph->get(scope);
	if (obj.exist == false) throw "存在しない画像スコープ";
	cnt = 0;
	max = obj.max;
	rate = obj.rate;
	loop = obj.loop;
	handle_graph = obj.handle;
}
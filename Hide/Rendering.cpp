#include "Rendering.h"
#include"DxLib.h"
#include "CoreTask.h"

void Rendering::switch_anime()
{
	cnt++;
	if (cnt >= max) {
		if (loop == false)cnt--;
		else cnt = 0;
	}
}

void Rendering::draw()
{
	DrawGraph(point.x - ct->gts->camera->get_range().x , point.y , *(handle_graph + cnt), 1);
	current_rate++;	//毎フレーム増える
	if (rate != 0 && rate % current_rate == 0) {
		switch_anime();
	}
}

Rendering::Rendering(Point point) : BasicObject(point)
{
}

void Rendering::init_render(std::string scope)
{
	GraphicObject obj = ct->graph->get(scope);
	if (obj.exist == false) throw std::runtime_error("The scope is not exist.");
	cnt = 0;
	max = obj.max;
	rate = obj.rate;
	loop = obj.loop;
	handle_graph = obj.handle;
	current_rate = 0;
}
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

void Rendering::draw(Point dist, int camera_x)
{
	DrawGraph(dist.x - camera_x , dist.y , *(handle_graph + cnt), 1);
	current_rate++;	//毎フレーム増える
	if (rate != 0 && rate % current_rate == 0) {
		switch_anime();
	}
}

Rendering::Rendering(std::shared_ptr<GraphicResource> _resource)
{
	resource = _resource;
}

void Rendering::set(std::string scope)
{
	GraphicObject obj = resource->get(scope);	//GraphicObjectを共有するように改善予定
	if (obj.exist == false) throw std::runtime_error("The scope is not exist.");
	cnt = 0;
	max = obj.max;
	rate = obj.rate;
	loop = obj.loop;
	handle_graph = obj.handle;
	current_rate = 0;
}
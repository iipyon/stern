#include "Rendering.h"
#include"DxLib.h"
#include "CoreTask.h"


Rendering::Rendering()
{
	current_anime = 0;
	current_rate = 0;
}

void Rendering::switch_anime()
{
	current_anime++;
	if (current_anime >= object->sheets) {
		if (object->loop == false)current_anime = object->sheets-1;
		else current_anime = 0;
	}
}

void Rendering::draw(Point dist)
{
	if (object != nullptr) {
		DrawGraph(dist.x - Map::get_camera().x, dist.y - Map::get_camera().y, *(object->handle + current_anime), 1);
		current_rate++;
		if (object->interval != 0 && current_rate % object->interval == 0) {
			current_rate = 0;
			switch_anime();
		}
	}
}

void Rendering::set(std::string name)
{
	object = GraphicResource::get(name);
	//if (object == nullptr) throw std::runtime_error("The scope is not exist.");
	current_rate = 0;
	current_anime = 0;
}
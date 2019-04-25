#include "Rendering.h"
#include"DxLib.h"
#include "CoreTask.h"

std::shared_ptr<Camera> Rendering::camera;

Rendering::Rendering()
{
	current_anime = 0;
	current_rate = 0;
}

void Rendering::switch_anime()
{
	current_anime++;
	if (current_anime >= object->sheets) {
		if (object->loop == false)current_anime = object->sheets;
		else current_anime = 0;
	}
}

void Rendering::draw(Point dist)
{
	if (object != nullptr) {
		DrawGraph(dist.x - camera->get_range().x, dist.y, *(object->handle + current_anime), 1);
		current_rate++;
		if (object->interval != 0 && object->interval % current_rate == 0) {
			switch_anime();
		}
	}
}

void Rendering::set(std::string name)
{
	object = GraphicResource::get(name);
	//if (object == nullptr) throw std::runtime_error("The scope is not exist.");
	current_rate = 0;
}
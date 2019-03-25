#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#include "json11.hpp"

struct GraphicObject {
	GraphicObject() {
		exist = false;
		loop = false;
		max = 1;
		rate = 0;
	}
	bool exist;
	bool loop;	//ループの有無
	std::string name;
	int* handle;
	int max;	//最大枚数
	int rate;	//切替速度
};

class GraphicResource
{
public:

	GraphicResource();
	~GraphicResource();
	bool load(std::string _scope);
	GraphicObject get(std::string name);
private:
	int get_index(std::string);
	bool exist_name(std::string);
	void register_graph(json11::Json);

	json11::Json json;
	int count_of_graph;	//画像枚数
	std::unique_ptr<GraphicObject[]> graph;
};
#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"

struct GraphicObject {
	std::string name;
	int* handle;
	int max;
};

class GraphicResource
{
public:

	GraphicResource();
	~GraphicResource();
	bool load(std::string);
	GraphicObject get(std::string);
private:
	int count_of_graph;	//画像枚数
	int get_index(std::string);
	std::unique_ptr<GraphicObject[]> graph;
};
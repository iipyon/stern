#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#define HANDLE_MAX 10	//10種類のアニメーション画像

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
	bool load(char* FileName, int AllNum,int XNum, int YNum,
		      int XSize, int YSize, int** G_handl);
	int get(int);
private:
	std::unique_ptr<GraphicObject[]> graph;
};
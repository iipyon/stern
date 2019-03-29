#pragma once
#include <iostream>
#include <memory>
#include "GraphicState.h"
#include "json11.hpp"

struct GraphicJsonFormat {
	std::string name;
	int width;
	int height;
};

struct GraphicObject {
	//画像の実体を管理する
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
	//メソッド
	GraphicResource();
	~GraphicResource();
	bool load(std::string _scope);
	GraphicObject get(std::string name);
private:
	//メソッド
	int get_index(std::string);
	bool exist_name(std::string);
	void register_graph(json11::Json);
	//構造体
	struct datum{
		std::string name, path;
		int width, height, line, column, speed, sheets;
		bool loop;
		//scopeは下層で利用するためなし。
		void set_default_to_empty();
	};

	//プロパティ
	json11::Json json;
	int count_of_graph;	//画像枚数
	std::unique_ptr<GraphicObject[]> graph;
};
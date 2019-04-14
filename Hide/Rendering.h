#pragma once
#include <memory>
#include "GraphicResource.h"

class Rendering {
private:
	static std::shared_ptr<GraphicResource> resource;
	std::shared_ptr<GraphicObject> object;

	//下記objectに置き換え予定
	int max;	//最大枚数
	int rate; //切替速度
	int current_rate;
	int cnt;//何枚目にいるか
	bool loop;//ループするか
	int *handle_graph;

	void switch_anime();

public:
	Rendering() {};
	Rendering(std::shared_ptr<GraphicResource>);
	void draw(Point, int camera_x);
	void set(std::string);
};
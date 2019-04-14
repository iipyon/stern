#pragma once
#include <memory>
#include "GraphicResource.h"
#include "Camera.h"


class Rendering {
private:
	friend class CoreTask;
	static  std::shared_ptr<GraphicResource> resource;
	static std::shared_ptr<Camera> camera;
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
	void draw(Point);
	void set(std::string);
};


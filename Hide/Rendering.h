#pragma once
#include"BasicObject.h"
#include "GraphicResource.h"

class Rendering : public BasicObject {
private:
	int max;	//最大枚数
	int rate; //切替速度
	int current_rate;
	int cnt;//何枚目にいるか
	bool loop;//ループするか
	int *handle_graph;

	void switch_anime();

protected:
	int graph;	//これは*handle_graphに移行する廃止予定のプロパティ

	//アニメーションを切り替える
	void init_render(std::string scope);

	void draw(bool new_gen=false);

public:
	Rendering(Point point);
};
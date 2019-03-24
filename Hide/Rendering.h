#pragma once
#include"BasicObject.h"
#include "GraphicResource.h"

class Rendering : public BasicObject {
private:
	int max;	//最大枚数
	int rate; //切替速度
	int cnt;//何枚目にいるか
	bool loop;//ループするか

protected:
	int graph;	//これは*handle_graphに移行する廃止予定のプロパティ
	int *handle_graph;

	//アニメーションを切り替える
	void init_render(std::string scope);
	bool switch_anime();
	void draw(bool new_gen=false);

};
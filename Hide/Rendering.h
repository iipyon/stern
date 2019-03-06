#pragma once
#include"BasicObject.h"

class Rendering : public BasicObject {
public:
	Rendering() {
		
	}
	//アニメーションを切り替える
	bool switch_anime();
	void draw();
protected:
	int cnt;//何枚目にいるか
	bool loop;//ループするか
	int graph;
};
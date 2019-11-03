#pragma once
#include <memory>
#include "GraphicResource.h"
#include "Camera.h"


class Rendering {
private:
	friend class CoreTask;
	std::shared_ptr<GraphicObject> object;

	int current_rate;	//現在のレート
	int current_anime;//何枚目にいるか

	void switch_anime();
public:
	Rendering();
	void draw(Point);
	void set(std::string);
};


#pragma once
#include"BasicObject.h"

class Item : public BasicObject {
private:
	virtual void work() = 0;//抽象となる
protected:
	bool checkhit(Point);
public:
	void update() final;//これ以上の継承をさせない
	Item(Point);
};
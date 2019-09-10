#pragma once
#include"BasicObject.h"
#include "Player.h"

class Fook : public BasicObject {
private:
	virtual void affect() = 0;//抽象となる
protected:

	virtual bool check_hit(Point) final;
public:
	void update() final;//これ以上の継承をさせない
	Fook(Point);
};

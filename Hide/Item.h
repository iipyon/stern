#pragma once
#include"BasicObject.h"

enum class Kind {
	recovery,
	powerup
};

class Item : public BasicObject {
private:
	Kind kind;
	virtual void efficacy() = 0;//抽象となる
protected:
	bool checkhit(Point);
public:
	void update() final;//これ以上の継承をさせない
	Item(Point);
};
#pragma once
#include"BasicObject.h"
#include "Player.h"

class Item : public BasicObject {
private:
	virtual void affect() = 0;//抽象となる
protected:
	friend class CoreTask;	//CoreTask::init が利用するため
	static std::shared_ptr<Player> player;
public:
	void update() final;//これ以上の継承をさせない
	Item(Point);
};


#pragma once
#include"BasicObject.h"
#include "Player.h"

class Fook : public BasicObject {
private:
	virtual void affect() = 0;//���ۂƂȂ�
protected:

	virtual bool check_hit(Point) final;
public:
	void update() final;//����ȏ�̌p���������Ȃ�
	Fook(Point);
};

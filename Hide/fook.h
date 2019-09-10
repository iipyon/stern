#pragma once
#include"BasicObject.h"
#include "Player.h"

class Fook : public BasicObject {
private:
	virtual void affect() = 0;//’ŠÛ‚Æ‚È‚é
protected:

	virtual bool check_hit(Point) final;
public:
	void update() final;//‚±‚êˆÈã‚ÌŒp³‚ğ‚³‚¹‚È‚¢
	Fook(Point);
};

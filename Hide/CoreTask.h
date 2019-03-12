#pragma once
#include<memory>
#include"GameTaskSystem.h"

class CoreTask {
private:
	int scene;
public:
	CoreTask();
	void update();
	std::unique_ptr<GameTaskSystem> gts;
};

extern CoreTask *ct;
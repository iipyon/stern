#pragma once
#include<memory>
#include"GameTaskSystem.h"



class CoreTask {
private:
public:
	CoreTask();
	void update();
	void init();
	void finalize();
	std::shared_ptr<GameTaskSystem> gts;
	int score;
};

extern CoreTask *ct;
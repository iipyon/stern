#pragma once
#include<memory>
#include"GameTaskSystem.h"
#include"StageSelectTaskSystem.h"
#include "ClearTaskSystem.h"



class CoreTask {
private:
public:
	CoreTask();
	void update();
	void init();
	void finalize();
	std::shared_ptr<GameTaskSystem> gts;
	std::shared_ptr<StageSelectTaskSystem> ssts;
};

extern CoreTask *ct;
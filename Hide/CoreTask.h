#pragma once
#include<memory>
#include"GameTaskSystem.h"
#include"StageSelectTaskSystem.h"
#include "ClearTaskSystem.h"
#include"Demo.h"



class CoreTask {
private:
public:
	CoreTask();
	void update();
	void init();
	void finalize();
	std::shared_ptr<GameTaskSystem> gts;
	std::shared_ptr<StageSelectTaskSystem> ssts;
	std::unique_ptr<Demo> demo;
	int score;
};

extern CoreTask *ct;
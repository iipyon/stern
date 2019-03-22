#pragma once
#include"TitleExitButton.h"
#include"TitleSelecter.h"
#include"TitleStartButton.h"
#include<memory>

class TitleTaskSystem {
private:
	int backgraph;
public:
	std::unique_ptr<TitleExitButton> exitbutton;
	std::unique_ptr<TitleSelecter> selecter;
	std::unique_ptr<TitleStartButton> startbutton;
	TitleTaskSystem();
	void update();
	void draw();
};
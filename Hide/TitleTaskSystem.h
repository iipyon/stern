#pragma once
#include"TitleUI.h"
#include"TitleSelecter.h"
#include<memory>

class TitleTaskSystem {
private:
	int backgraph;
public:
	std::unique_ptr<TitleUI> title_ui;
	std::unique_ptr<TitleSelecter> selecter;
	TitleTaskSystem();
	void update();
	void draw();
};
#pragma once
#include"TitleUI.h"
#include"TitleSelecter.h"
#include<memory>
#include"Screen_helper.h"
#include"DxLib.h"

class TitleTaskSystem {
private:
	int backgraph;
	bool deg_flag;
	int feedcnt;
public:
	std::unique_ptr<TitleUI> title_ui;
	std::unique_ptr<TitleSelecter> selecter;
	TitleTaskSystem();
	void update();
	void draw();
};
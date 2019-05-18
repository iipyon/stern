#pragma once
#include"TitleUI.h"
#include<memory>
#include"Screen_helper.h"
#include"DxLib.h"

class TitleTaskSystem {
private:
	int backgraph;
	bool deg_flag;
	int feedcnt;

	void selecter_move();
	void change_scene();
public:
	std::unique_ptr<TitleUI> title_ui;
	TitleTaskSystem();
	void init();
	void update();
	void draw();
};
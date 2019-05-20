#pragma once
#include"TitleUI.h"
#include<memory>


class TitleTaskSystem {
private:
	static int backgraph;
	static bool deg_flag;
	static int feedcnt;

	TitleTaskSystem();
	static void selecter_move();
	static void change_scene();
	static std::unique_ptr<TitleUI> title_ui;
public:
	static void init();
	static void update();
	static void finalize();
	static void draw();
};
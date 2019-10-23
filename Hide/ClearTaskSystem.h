#pragma once
#include"ClearUI.h"
#include<memory>

class ClearTaskSystem {
private:
	ClearTaskSystem();
	static bool feed_flag;
	static int backgraph;
	static void draw();
	static std::unique_ptr<ClearUI> c_ui;
public:
	static void init();
	static void init_member();//ui増加の見込みがあるため
	static void update();	
};
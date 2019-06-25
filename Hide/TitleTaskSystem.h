#pragma once
#include"TitleUI.h"
#include<memory>


class TitleTaskSystem {
private:
	static int backgraph;
	static bool feed_flag;
	static int demo_cnt;//ƒfƒ‚‚É‘JˆÚ‚·‚é‚Ü‚Å‚ÌŽžŠÔ

	TitleTaskSystem();
	static void selecter_move();
	static void change_scene();
	static std::unique_ptr<TitleUI> title_ui;
public:
	static void init();
	static void init_member();
	static void update();
	static void finalize();
	static void draw();
};
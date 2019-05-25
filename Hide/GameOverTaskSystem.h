#pragma once
#include"GameOverTaskUI.h"
#include<memory>

class GameOverTaskSystem {
private:
	static int backGraph;//背景
	static void draw();
	
	static bool feed_flag;


	static std::unique_ptr<GameOverUI> gameover_ui;

	static void selecter_move();
	static void selecter_undermove();
	static void selecter_upmove();
	static void change_scene();

	GameOverTaskSystem();
public:
	static void init_member();
	static void initialize();
	static void update();
	static void finalize();
};
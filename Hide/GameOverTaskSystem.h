#pragma once
#include"GameOverTaskUI.h"
#include<memory>

class GameOverTaskSystem {
private:
	int backGraph;//背景
	void draw();
	
	bool deg_flag;
	int feedcnt;

	std::unique_ptr<GameOverUI> gameover_ui;

	void selecter_move();
	void selecter_undermove();
	void selecter_upmove();
	void change_scene();
public:
	GameOverTaskSystem();
	void init();
	void update();
};
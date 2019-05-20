#pragma once
#include"PauseTaskUI.h"
#include<memory>


class PauseTask{
private:
	PauseTask();
	//UIクラス
	static std::unique_ptr<PauseUI> p_ui;

	static int backgraph;//背景
	static int feedcnt;
	static void draw();//背景、UIの描画
	static void change_scene();//シーンを切り替えるメソッド
	static bool deg_flag;

	static void selecter_undermove();
	static void selecter_upmove();
	static void selecter_move();
public:
	static void initialize();
	static void update();
	static void finalize();
};
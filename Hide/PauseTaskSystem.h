#pragma once
#include<iostream>
#include"PauseTaskUI.h"
#include<memory>
#include"Screen_helper.h"
#include"DxLib.h"

class PauseTask{
private:
	//UIクラス
	std::unique_ptr<PauseUI> p_ui;

	int backgraph;//背景
	int feedcnt;
	void draw();//背景、UIの描画
	void change_scene();//シーンを切り替えるメソッド
	bool deg_flag;

	void selecter_undermove();
	void selecter_upmove();
	void selecter_move();
public:
	PauseTask();
	void update();
};
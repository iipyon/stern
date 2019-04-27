#pragma once
#include<iostream>
#include"PauseTaskUI.h"
#include"PauseTaskSelecter.h"
#include<memory>
#include"Screen.h"
#include"DxLib.h"

class PauseTask{
private:
	//セレクタークラス
	std::unique_ptr<PauseSelecter> p_selecter;
	//UIクラス
	std::unique_ptr<PauseUI> p_ui;

	int backgraph;//背景
	int feedcnt;
	void draw();//背景、UIの描画
	void change_scene();//シーンを切り替えるメソッド
	bool deg_flag;
public:
	PauseTask();
	void update();
};
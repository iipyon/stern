#pragma once
#include<iostream>

class StageSelectTextBox {
private:
	int boxgraph;//テキストボックスの画像
	//座標は固定のためプロパティは必要なしと判断
	int start_x, start_y, end_x, end_y;
public:
	StageSelectTextBox();
	void update();
	void draw();
};
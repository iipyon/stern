#pragma once
#include<iostream>

class StageSelectTextBox {
private:
	int boxgraph;//テキストボックスの画像
	//座標は固定のためプロパティは必要なしと判断
	//テキストをStringにするかDrawString()にするか検討中
public:
	StageSelectTextBox();
	void update(int);
	void draw(int);
};
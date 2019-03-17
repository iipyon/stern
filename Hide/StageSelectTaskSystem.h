#pragma once
#include<iostream>

class StageSelectTaskSystem {
private:
	int stage;//ステージ識別番号
	bool state[4];//クリアフラグ（ステージ総数によって変える）
	int backgraph;//背景画像
public:
	StageSelectTaskSystem();
	void update();//Map_Initをステージ番号に基づき中身を変えて呼ぶ
	void draw();
	int get_stage();
	void clear(int);
};
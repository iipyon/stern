#pragma once
#include"DxLib.h"

class Keyboard {
public:
	Keyboard() {
		
	}
	//メソッド
	void update();
	bool key_down(int);
	bool key_up(int);
	bool key_press(int);
	//bool Get(KEY_INPUT *key);
private:
	int current[256];//キーボード対応させる
	int previous[256];//１フレーム前の配列を記憶
};
#pragma once
#include"DxLib.h"
#include <memory>
#define KEY_BOARD_BUF_SIZE 256


class Keyboard {
public:
	Keyboard();
	~Keyboard();
	void update();
	bool key_down(int);
	bool key_up(int);
	bool key_press(int);
	//bool Get(KEY_INPUT *key);
private:
	//DXライブラリの仕様上スマートポインタにできない
	char* current;	//キーボード対応させる
	char* previous;	//１フレーム前の配列を記憶
	char* work;	//作業領域
};
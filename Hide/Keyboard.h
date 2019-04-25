#pragma once
#include"DxLib.h"
#include <memory>
#define KEY_BOARD_BUF_SIZE 256


class Keyboard {
public:
	static void initialize();
	static void finalize();
	static void update();
	static bool key_down(int);
	static bool key_up(int);
	static bool key_press(int);
	//bool Get(KEY_INPUT *key);
private:
	Keyboard();
	static char* current;	//キーボード対応させる
	static char* previous;	//１フレーム前の配列を記憶
	static char* work;	//作業領域
};
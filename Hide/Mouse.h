#pragma once
#include"DxLib.h"
#include <memory>


class Mouse {
public:
	static void initialize();
	static void update();
	static bool Mouse_down();//押した瞬間
	static bool Mouse_up();//離した瞬間
	static bool Mouse_press();//押しているか（離している状態は！やelseで検出）
private:
	Mouse();
	static bool current;	//今のマウスの状態
	static bool previous;	//１フレーム前のマウスの状態
	static bool work;	//作業領域
};
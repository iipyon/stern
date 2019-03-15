#pragma once
class ClearTaskSystem {
private:
	int timer;	//クリア画面を表示する時間
public:
	ClearTaskSystem();
	void update();
	void draw();
};
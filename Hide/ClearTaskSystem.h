#pragma once
class ClearTaskSystem {
private:
	int timer;	//クリア画面を表示する時間
	void draw();
public:
	ClearTaskSystem();
	void init();
	void update();	
};
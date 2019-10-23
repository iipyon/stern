#pragma once
#include"BasicUI.h"

class ClearUI : public BasicUI {
private:
	Text text;
	enum BrightState {
		Reduce,//減少
		Increase//増加
	};
	bool deg_flag;
	int ui_brend;
	BrightState b_state;
public:
	ClearUI();
	void init();
	void update();
	void draw();
};
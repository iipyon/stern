#pragma once
#include"BasicUI.h"

enum class Button {
	start,
	exit
};

class TitleUI : public BasicUI {
private:
	bool deg_flag;
	int ui_brend;
	Button button;

	void draw_selecter();
public:
	Text text[2];
	TitleUI();
	void init();
	void update();
	void change_Select(Button);
	Button getter();
};
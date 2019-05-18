#pragma once
#include"BasicUI.h"

enum class PauseButton {
	returngame,
	exit,
	backssts
};


class PauseUI : public BasicUI {
private:
	bool deg_flag;
	int ui_brend;
	PauseButton pausebutton;

	void draw_selecter();
public:
	Text text[3];
	PauseUI();
	void update();
	void change_Select(PauseButton);
	PauseButton getter();
};
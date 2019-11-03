#pragma once
#include"BasicUI.h"

enum class SelectMode {
	Continue,
	StageSelect,
	Title
};

class GameOverUI : public BasicUI {
private:
	bool deg_flag;
	int ui_brend;
	SelectMode select;
	void draw_selecter();
public:
	Text text[2];
	GameOverUI();
	void update();
	void change_Select(SelectMode);
	SelectMode getter();
};
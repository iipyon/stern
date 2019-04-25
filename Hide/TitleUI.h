#pragma once
#include"BasicUI.h"

class TitleUI : public BasicUI {
public:
	Text text[2];
	TitleUI();
	void update();
};
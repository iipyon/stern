#pragma once
#include"BasicUI.h"

class PauseUI : public BasicUI {
private:
public:
	Text text[3];
	PauseUI();
	void update();
};
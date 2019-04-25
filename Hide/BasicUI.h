#pragma once
#include<iostream>

class BasicUI {
protected:
	struct Text {
		const char* str;
		int text_width;
		int x;
		int y;
	};
	int get_width(Text);
	void update_txt(Text);
	void draw_txt(Text);
public:
	BasicUI();
	int get_lextx(Text);
	int get_y(Text);
};
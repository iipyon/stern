#pragma once
#include<iostream>

class BasicUI {
protected:
	struct Text {
		const char* str;
		int text_width;
		int x;
		int y;
		int font;
		int color;
	};
	int get_width(Text);
	void update_txt(Text);
	void draw_txt(Text);
public:
	BasicUI();
	int get_left(Text, int);
	int get_y(Text);
};
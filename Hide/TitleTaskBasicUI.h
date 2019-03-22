#pragma once

class TitleTaskBasicUI {
protected:
	int x;
	int y;
	int strwidth;//文字列の幅を格納
public:
	TitleTaskBasicUI();
	void get_width(const char*);
	void update_txt(const char*);
	void draw_txt(const char*);
	int get_lextx();
	int get_y();
};
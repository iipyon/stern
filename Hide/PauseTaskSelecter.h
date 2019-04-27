#pragma once

enum class PauseButton {
	returngame,
	exit,
	backssts
};

class PauseSelecter {
private:
	int x;
	int y;
	int graph;
	void draw();
	void switch_button(bool deg);
	void move(int, int, int);
public:
	PauseButton button;
	PauseSelecter();
	void update(int, int, int,bool);
};
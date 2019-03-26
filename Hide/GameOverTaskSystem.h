#pragma once
class GameOverTaskSystem {
private:
	int timer;
	void draw();
public:
	GameOverTaskSystem();
	void init();
	void update();
};
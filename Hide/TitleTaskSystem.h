#pragma once
#include<memory>

class TitleTaskSystem {
private:
	class TitleStar {
	private:
		int graph;
		int x;
		int y;
		//輝度を変更する
		bool switchbright;
		int bright;//RGB全て同じ値で動かす
	public:
		TitleStar();
		void draw();
		void update();
		void bright_switch();
	};
	int graph;
public:
	TitleTaskSystem();
	void update();
	void draw();
	std::unique_ptr<TitleStar> titlestar;
};
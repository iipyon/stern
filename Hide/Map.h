#pragma once
#include"Point.h"

//---------------------------------
//マップデータ
//---------------------------------

class Map {
public:
	
	Map(char*);
	void draw();
	void update();
	int get_left(Point);
	int get_right(Point);
	int get_top(Point);
	int get_bottom(Point);

private:
	int data[20][20];//仮の数値
	int graph;//絵
	int mapsizex;
	int mapsizey;
	int chipsize;//チップの大きさ
};
#pragma once
#include"Point.h"
#include "json11.hpp"

//---------------------------------
//マップデータ
//---------------------------------

class Map {
public:
	Map();
	void init(char*);
	void draw();
	void update();
	int get_left(Point);
	int get_right(Point);
	int get_top(Point);
	int get_bottom(Point);
	int get_circle(Point, int);
	static Point get_camera(); //加工済みのget_rangeを送る
private:
	std::string chipmap;
	int graph;//絵
	int backgraph;
	int data[100][100];//最大100*100のマップを作成可能
	int chipsize;
	int chipwidth;
	int mapsizex;
	int mapsizey;
	int sx, sy, ex, ey;  //ループ範囲
	static Point camera;
	json11::Json mapdata;
	json11::Json map;
	json11::Json chipdata;
};
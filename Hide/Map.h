﻿#pragma once
#include"Point.h"
#include "json11.hpp"
#include "MapConfig.h"

//---------------------------------
//マップデータ
//---------------------------------

class Map {
public:
	Map();
	void Create(const char*,int);
	void draw();
	void update();
	int get_left(Point);
	int get_right(Point);
	int get_top(Point);
	int get_bottom(Point);
	void Set_createflag();
	static Point get_camera(); //加工済みのget_rangeを送る
	int mapsizex;
	int mapsizey;

	int total_mapsizex;
private:
	std::string chipmap;
	int graph;//絵
	int backgraph;
	int data[MAP_DATA_Y_SIZE][MAP_DATA_X_SIZE];
	int chipsize;
	int chipwidth;
	bool createflag;
	const char*  mapnum;

	int sx, sy, ex, ey;  //ループ範囲
	static Point camera;
	json11::Json mapdata;
	json11::Json map;
	json11::Json chipdata;
};
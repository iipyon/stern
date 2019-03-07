#include"Map.h"
#include"DxLib.h"
#include<fstream>

//----------------------------------
//マップデータ
//----------------------------------

Map::Map(char *mapfp)
{
	//1津のチップの大きさを30と考える(勝手)
	mapsizex = 600;
	mapsizey = 600;
	//使う画像決定
	graph = LoadGraph("img/chip.png");
	//ファイル読み込み
	std::ifstream mapdata(mapfp);
	if (!mapdata) { return; }
	for (int y = 0; y < mapsizey / 30; ++y) {
		for (int x = 0; x < mapsizex / 30; ++x) {
			mapdata >> data[y][x];
		}
	}
	//ファイル閉じ
	mapdata.close();
}

void Map::draw()
{
	for (int y = 0; y < mapsizey / 20; ++y) {
		for (int x = 0; x < mapsizex / 20; ++x) {
			DrawRectGraph(x * 30, y * 30, data[y][x] * 30, 0, 30, 30, graph, FALSE);
		}
	}
}

void Map::update()
{
	draw();
}

int Map::get_left(Point)
{
	return 0;
}

int Map::get_right(Point)
{
	return 0;
}

int Map::get_top(Point)
{
	return 0;
}

int Map::get_bottom(Point)
{
	return 0;
}

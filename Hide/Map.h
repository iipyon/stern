#pragma once

//---------------------------------
//マップデータ
//---------------------------------

class Map {
public:
	/*
	Map():
	{}
	*/
	void Init();
	void Draw();

private:
	int data[1][1];//仮の数値
	int graph;//絵
	int maxsizex;
	int maxsizey;
	int chip;//マップチップ
};
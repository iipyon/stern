﻿#include"Map.h"
#include"DxLib.h"
#include"CoreTask.h"
#include"System.h"
#include<fstream>
#include <string>
#include <sstream>
#include<algorithm>
#include "json11.hpp"
Point Map::camera;
//----------------------------------
//マップデータ
//----------------------------------

Map::Map()
{
	//可変
	//チップファイル一つの大きさと横のマス
	chipsize = 64;
	chipwidth = 6;
	//初期化
	mapsizex = 0;
	mapsizey = 0;
	total_mapsizex = 0;
	camera.x = 0;
	camera.y = 0;
	camera.w = 0;
	camera.h = 0;
	createflag = false;
	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < MAP_DATA_X_SIZE; ++x) {
			data[y][x] = 0;
		}
	}
}

void Map::Create(char* map_,int primaryx_)
{
	//jsonの読み込み
	std::ifstream mappath("img/json/mappath.json");
	if (mappath.fail())
	{
		throw std::runtime_error("mappath.json is not found.");	//ファイルが読み込めないと例外を返す
	}
	std::istreambuf_iterator<char> it(mappath);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	mapdata = json11::Json::parse(json_str, err);	//json11で利用できる形式に変換
	map = mapdata[map_];


	//マップのサイズの読み込み
	mapsizex = map["sizex"].int_value();
	mapsizey = map["sizey"].int_value();

	//マップサイズを足す
	total_mapsizex += mapsizex;

	//画像の読み込み
	graph = LoadGraph(map["chippath"].string_value().c_str());
	backgraph = LoadGraph(map["background"].string_value().c_str());

	//txtの読み込み
	/*std::ifstream fin(map["txtpath"].string_value().c_str());
	if (!fin) { return; }
	for (int y = 0; y < mapsizey / chipsize; ++y) {
		for (int x = 0; x < mapsizex / chipsize; ++x) {
			fin >> data[y][x];
		}
	}*/

	//csvの読み込む
	chipmap = map["csvpath"].string_value().c_str();

	std::ifstream fin(chipmap);

	for (int y = 0; y < mapsizey / chipsize; ++y) {
		std::string lineText;
		getline(fin, lineText);
		std::istringstream ss_lt(lineText);
		for (int x = primaryx_ / chipsize; x < total_mapsizex / chipsize; ++x) {
			std::string  tc;
			getline(ss_lt, tc, ',');
			std::stringstream ss;
			ss << tc;
			ss >> data[y][x]; //データを入れる
		}
	}
	//ファイルを閉じる
	mappath.close();	
	fin.close();
}
void Map::draw()
{
	//カメラが完全にマップ外を指しているか調べる
	Point maphitbase = { 0,0,total_mapsizex,mapsizey };
	if (false == CheckHit(maphitbase, camera)){
		return;//完全に外に出ていたらその時点で描画処理を取りやめる
	}

	//カメラとマップが重なっている範囲だけの矩形を作る
	RECT c = {
		camera.x,
		camera.y,
		camera.x + camera.w,
		camera.y + camera.h
	};
	RECT m = {
			0,
			0,
			0 + total_mapsizex,
			0 + mapsizey 
	};

	//カメラの位置を調整
	if (c.right > m.right) { camera.x = m.right - camera.w; }
	if (c.bottom > m.bottom) { camera.y = m.bottom - camera.h; }
	if (c.left < m.left) { camera.x = m.left;}
	if (c.top < m.top) { camera.y = m.top; }
	/*//マップがカメラより小さい場合
	if (mapsizex < camera.w) { camera.x = m.left; }
	if (mapsizey < camera.h) { camera.y = m.top; }*/

	//ループの範囲を決定
	//全体を描画することで処理は増えるが成功した
	sx = 0;		
	sy = 0;	
	ex = total_mapsizex / chipsize;	
	ey = mapsizey / chipsize;	

	//画面のサイズに合わせて調整可能
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	if (ex < 0)ex = 0;
	else if (ex >= MAP_DATA_X_SIZE)ex = MAP_DATA_X_SIZE - 1;
	if (ey < 0) ey = 0;
	else if (ey >= MAP_DATA_Y_SIZE)ey = MAP_DATA_Y_SIZE - 1;

	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			DrawRectGraph((x * chipsize) - camera.x , (y * chipsize) - camera.y,
				(data[y][x] % chipwidth) * chipsize ,(data[y][x] / chipwidth) * chipsize ,
				chipsize, chipsize,
				graph,TRUE, FALSE);
			
		}
	}
}

void Map::update()
{
	//カメラの座標更新
	camera.x = Camera::get_range().x;
	camera.y = Camera::get_range().y;
	camera.w = Camera::get_range().w;
	camera.h = Camera::get_range().h;
	draw();
	if (createflag) {
		Create((char*)"2", total_mapsizex);//動作確認済　バグあり
		createflag = false;
	}
}
//-----------------------------------------------------------------------------------------------------------
//問題点　charaが二つのマップチップをまたいでいるとき左（または上)のチップのみリターンされ、ほかのチップが無視される
//-----------------------------------------------------------------------------------------------------------
/*int Map::get_left(Point chara_)
{
	int sx = (chara_.x-1 )/ chipsize;
	int sy = chara_.y / chipsize;
	int ex = chara_.x / chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_right(Point chara_)
{
	int sx = (chara_.x + chara_.w) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = ((chara_.x + chara_.w) +1)/ chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_top(Point chara_)
{
	int sx = chara_.x/ chipsize;
	int sy = (chara_.y-1) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = chara_.y / chipsize;
	for (int y = sy; y < ey; ++y) {
		for (int x = sx; sx < ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}

int Map::get_bottom(Point chara_)
{
	//マップタイル１つが30*30のため
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = ((chara_.y + chara_.h)+1) / chipsize;
	//範囲内の障害物を探す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; sx <= ex; ++x) {
			return data[y][x];
		}
	}
	return 0;
}*/
//-----------------------------------------------------------------------------------------------------------
//仮処理　チップが当たり判定を持っているときのみ1を返す　今後ダメージ床は2を返すなどの拡張が可能
//-----------------------------------------------------------------------------------------------------------
int Map::get_left(Point chara_)
{
	int sx = (chara_.x-1) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x-1) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は１のチップのみに当たり判定を持たせる
				return 1;
			}
			
		}
	}
	return 0;
}

int Map::get_right(Point chara_)
{
	int sx = (chara_.x + chara_.w) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

int Map::get_top(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = (chara_.y-1) / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y-1) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

int Map::get_bottom(Point chara_)
{
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y + chara_.h)  / chipsize;
	//範囲内の障害物を探す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}
		}
	}
	return 0;
}

Point Map::get_camera()
{
	return camera;
}

void Map::Set_createflag() {
	createflag = true;
}
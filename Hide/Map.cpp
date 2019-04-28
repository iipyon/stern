#include"Map.h"
#include"DxLib.h"
#include"CoreTask.h"
#include<fstream>
#include <string>
#include <sstream>
#include<algorithm>
#include "json11.hpp"
//1津のチップの大きさを30と考える(勝手)//チップサイズは32が妥当

//----------------------------------
//マップデータ
//----------------------------------

Map::Map()
{
	//可変
	//チップファイル一つの大きさと横のマス
	chipsize = 64;
	chipwidth = 6;
	//マップのサイズ
	mapsizex = 1280;
	mapsizey = 1280;
}

void Map::init(char* map_)
{
	//jsonの読み込み
	std::ifstream mappath("img/mappath.json");
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

	//画像の読み込み
	graph = LoadGraph(map["chippath"].string_value().c_str());

	//txtの読み込み
	std::ifstream fin(map["txtpath"].string_value().c_str());
	if (!fin) { return; }
	for (int y = 0; y < mapsizey / chipsize; ++y) {
		for (int x = 0; x < mapsizex / chipsize; ++x) {
			fin >> data[y][x];
		}
	}

	//csvの読み込む
	//chipmap = map["csvpath"].string_value().c_str();

	//std::ifstream fin(chipmap);

	//for (int y = 0; y < mapsizey / chipsize; ++y) {
	//	std::string lineText;
	//	getline(fin, lineText);
	//	std::istringstream ss_lt(lineText);
	//	for (int x = 0; x < mapsizex / chipsize; ++x) {
	//		std::string  tc;
	//		getline(ss_lt, tc, ',');
	//		std::stringstream ss;
	//		ss << tc;
	//		ss >> data[y][x]; //データを入れる
	//	}
	//}
	//ファイルを閉じる
	mappath.close();	
	fin.close();
}

void Map::draw()
{
	/*for (int y = 0; y < mapsizey / (mapsizey / chipsize); ++y) {
		for (int x = 0; x < mapsizex / (mapsizex / chipsize); ++x) {
		if (ct->gts->camera->get_range().x > x * chipsize ||
			ct->gts->camera->get_range().x + ct->gts->camera->get_range().w < x * chipsize + chipsize ||
			ct->gts->camera->get_range().y > y * chipsize ||
			ct->gts->camera->get_range().y + ct->gts->camera->get_range().h < y * chipsize + chipsize) {
			return;
			}
		}
	}*/
	//カメラが完全にマップ外を指しているか調べる
	Point maphitbase = { 0,0,mapsizex,mapsizey };
	if (false == CheckHit(maphitbase, Camera::get_range())){
		return;//完全に外に出ていたらその時点で描画処理を取りやめる
	}

	//カメラとマップが重なっている範囲だけの矩形を作る
	RECT c = {
		Camera::get_range().x,
		Camera::get_range().y,
		Camera::get_range().x + Camera::get_range().w,
		Camera::get_range().y + Camera::get_range().h
	};
	RECT m = {
			0,
			0,
			0 + mapsizex,
			0 + mapsizey 
	};

	//2つの矩形の重なっている範囲だけの矩形を求める
	RECT isr;
	isr.left = max(c.left, m.left);
	isr.top = max(c.top, m.top);
	isr.right = min(c.right, m.right);
	isr.bottom = min(c.bottom, m.bottom);

	//ループの範囲を決定
	sx = isr.left / chipsize;
	sy = isr.top / chipsize;
	ex = (isr.right - 1) / chipsize;
	ey = (isr.bottom - 1) / chipsize;

	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			DrawRectGraph((x * chipsize) - Camera::get_range().x, (y * chipsize) /*- Camera::get_range().y*/,
				(data[y][x] % chipwidth) * chipsize ,(data[y][x] / chipwidth) * chipsize ,
				chipsize, chipsize,
				graph,FALSE, FALSE);
		}
	}
}

void Map::update()
{
	draw();
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
	int sx = chara_.x / chipsize;
	int sy = chara_.y / chipsize;
	int ex = chara_.x / chipsize;
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
	int sx = (chara_.x + chara_.w-1) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
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
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = chara_.y / chipsize;
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
	int sy = (chara_.y + chara_.h-1) / chipsize;
	int ex = (chara_.x + chara_.w-1) / chipsize;
	int ey = (chara_.y + chara_.h-1) / chipsize;
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
int Map::get_circle(Point star_,int r_)
{
	/*int sx = (star_.x-r_) / chipsize;//本来はこのはずだが描画と当たり判定がずれている
	int sy = (star_.y-r_) / chipsize;
	int ex = (star_.x + r_ ) / chipsize;
	int ey = (star_.y + r_ ) / chipsize;*/
	int sx = (star_.x-1 ) / chipsize;
	int sy = (star_.y-1 ) / chipsize;
	int ex = (star_.x + r_*3) / chipsize;
	int ey = (star_.y + r_*3) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は7のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

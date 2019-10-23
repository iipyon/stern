#include"Map.h"
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
	
}

void Map::init() {
	//初期化
	mapsizex = 0;
	mapsizey = 0;
	total_mapsizex = 0;
	camera.x = 0;
	camera.y = 0;
	camera.w = 0;
	camera.h = 0;
	createflag = false;
	for (int y = 0; y < MAP_DATA_Y_SIZE; ++y) {
		for (int x = 0; x < MAP_DATA_X_SIZE; ++x) {
			data[y][x] = 0;
		}
	}
}

int Map::Create(const char* map_,int primaryx_)
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

	//マップサイズを足して戻り値を作る
	total_mapsizex += mapsizex;

	//画像の読み込み
	graph = LoadGraph(map["chippath"].string_value().c_str());
	backgraph = LoadGraph(map["background"].string_value().c_str());

	//csvの読み込む
	chipmap = map["csvpath"].string_value().c_str();

	std::ifstream fin(chipmap);

	for (int y = 0; y < mapsizey / chipsize; ++y) {
		std::string lineText;
		getline(fin, lineText);
		std::istringstream ss_lt(lineText);
		for (int x = primaryx_ / chipsize; x < total_mapsizex / chipsize; ++x) {//最後に生成されたマップの次のX座標から開始
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
	return total_mapsizex;//マップサイズを返して次の生成時の引数にする
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

}

//-----------------------------------------------------------------------------------------------------------
//　チップが当たり判定を持っているときのみ1を返す　今後ダメージ床は2を返すなどの拡張が可能
//-----------------------------------------------------------------------------------------------------------
int Map::get_left(Point chara_)
{
	chara_ = outer_CheckHit(chara_);
	int sx = (chara_.x-1) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x-1) / chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	return Check_hit(sx, sy, ex, ey);
}

int Map::get_right(Point chara_)
{
	chara_ = outer_CheckHit(chara_);
	int sx = (chara_.x + chara_.w) / chipsize;
	int sy = chara_.y / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = (chara_.y + chara_.h) / chipsize;
	return Check_hit(sx, sy, ex, ey);
}

int Map::get_top(Point chara_)
{
	chara_ = outer_CheckHit(chara_);
	int sx = chara_.x / chipsize;
	int sy = (chara_.y-1) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = (chara_.y-1) / chipsize;
	return Check_hit(sx, sy, ex, ey);
}

int Map::get_bottom(Point chara_)
{
	chara_ = outer_CheckHit(chara_);
	int sx = chara_.x / chipsize;
	int sy = (chara_.y + chara_.h) / chipsize;
	int ex = (chara_.x + chara_.w) / chipsize;
	int ey = (chara_.y + chara_.h)  / chipsize;
	return Check_hit(sx, sy, ex, ey);

}
int Map::get_floar_bottom(Point chara_)//足元の矩形をもらう(x,y+h-1,w,1)
{
	chara_ = outer_CheckHit(chara_);
	int sx = chara_.x / chipsize;//足
	int ex = (chara_.x + chara_.w) / chipsize;
	int y = (chara_.y) / chipsize;
	//範囲内の障害物を探す
	if (data[y][sx] <= 5 && data[y][ex] <= 5) {//足は空気か？		
		y = (chara_.y + 1) / chipsize; // 足元
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//足元はブロックか？
				return 1;
			}
		}

	}

	return 0;
}

int Map::Check_hit(int sx,int sy,int ex,int ey) {

	//範囲内の障害物を探す
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 6) {//今回の場合は6以降のチップに当たり判定を持たせる
				return 1;
			}
		}
	}
	return 0;
}

Point Map::outer_CheckHit(Point chara_) {//マップ外を検知してプレイヤーの矩形を削る
	RECT p = {
		chara_.x,
		chara_.y,
		chara_.x + chara_.w,
		chara_.y + chara_.h
	};
	RECT m = {
		0,
		0,
		0 + total_mapsizex,
		0 + mapsizey
	};
	if (p.left < m.left) { p.left = m.left; }
	if (p.top < m.top) { p.top = m.top; }
	if (p.right > m.right) { p.right = m.right; }
	if (p.bottom > m.bottom) { p.bottom = m.bottom; }
	return Point{ p.left,p.top,p.right - p.left,p.bottom - p.top };
}

Point Map::get_camera()
{
	return camera;
}

void Map::Set_createflag() {
	createflag = true;
}
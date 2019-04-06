#include"Map.h"
#include"DxLib.h"
#include<fstream>
//1津のチップの大きさを30と考える(勝手)//チップサイズは32が妥当
#define chipsize 30

//----------------------------------
//マップデータ
//----------------------------------

Map::Map()
{
	//可変
	mapsizex = 600;
	mapsizey = 600;
}

void Map::init(char* mapfp, char* chipfp)
{
	//使う画像決定
	graph = LoadGraph(chipfp);
	//ファイル読み込み
	std::ifstream mapdata(mapfp);
	if (!mapdata) { return; }
	for (int y = 0; y < mapsizey / chipsize; ++y) {
		for (int x = 0; x < mapsizex / chipsize; ++x) {
			mapdata >> data[y][x];
		}
	}
	//ファイル閉じ
	mapdata.close();
}

void Map::draw()
{
	for (int y = 0; y < mapsizey / (mapsizey/chipsize); ++y) {
		for (int x = 0; x < mapsizex / (mapsizex / chipsize); ++x) {
			DrawRectGraph(x * chipsize, y *chipsize, data[y][x] * chipsize, 0, chipsize, chipsize, graph, FALSE);
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
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
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
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
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
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
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
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
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
	int sx = (star_.x- 1) / chipsize;//10以上にすると反応しなくなる
	int sy = (star_.y -1) / chipsize;
	int ex = (star_.x + r_*3) / chipsize;
	int ey = (star_.y + r_*3) / chipsize;
	for (int y = sy; y <= ey; ++y) {
		for (int x = sx; x <= ex; ++x) {
			if (data[y][x] >= 1) {//今回の場合は１のチップのみに当たり判定を持たせる
				return 1;
			}

		}
	}
	return 0;
}

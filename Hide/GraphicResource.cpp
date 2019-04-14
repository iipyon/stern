#include"GraphicResource.h" 
#include"DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

void GraphicResource::datum::set_default_to_empty()
{
	//未定義の項目に対していデフォルト値を設定する
	if (column == 0) column = 1;
	if (line == 0) line = 1;
	if (width == 0) width = 32;
	if (height == 0) height = 32;
	//if (speed == 0) speed = 0;
	//if (loop == false) loop = false;
	if (sheets == 0) sheets = line * column;

}

GraphicResource::GraphicResource()
{
	std::ifstream ifs("img/resource.json");
	if (ifs.fail())
	{
		throw std::runtime_error("resource.json is not found.");	//ファイルが読み込めないと例外を返す
	}
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	json = json11::Json::parse(json_str,err);	//json11で利用できる形式に変換
	count_of_graph = 0;
	for (auto &item : json["graph"].array_items()) {
		//画像の枚数を数える
		count_of_graph++;
	}
	graph = std::make_unique<GraphicObject[]>(count_of_graph);	//画像の枚数分の領域を確保する
	for (int i = 0; i < count_of_graph; i++) graph[i].exist = false;
}
//デストラクタ
GraphicResource::~GraphicResource()
{
	for (int i = 0; i < count_of_graph; i++) {
		delete graph[i].handle;	//画像は消さずにハンドル領域を削除する
	}
}
bool GraphicResource::load(std::string _scope)
{
	//scopeの文字列の画像をjsonから検索し、読み込む
	//失敗すれば0、成功すれば0以外を返す
	bool ret = false;
	for (auto &item : json["graph"].array_items()) {
		//scopeの配列をitemに格納する
		for(auto &scope : item["scope"].array_items()) {
			//scopeの文字列を順に比較する
			if ( _scope == scope.string_value()) {
				if (exist_name(item["name"].string_value()) == false) {
					//同一の名前のファイルが読み込まれていない場合
					register_graph(item);	//graphにitemを登録する
					ret = true;
					break;
				}
			}
		}
	}
	return ret;
}

GraphicObject GraphicResource::get(std::string name)
{
	int index = get_index(name);
	GraphicObject ret;
	if (index != -1) ret = graph[index];
	return ret;
}

void GraphicResource::register_graph(json11::Json item)
{
	for (int i = 0; i < count_of_graph; i++) {
		if (graph[i].exist == false) {
			struct datum dat;
			dat.name = item["name"].string_value();
			dat.path = item["path"].string_value();
			dat.column = item["column"].int_value();
			dat.line = item["line"].int_value();
			dat.width = item["width"].int_value();
			dat.height = item["height"].int_value();
			dat.loop = item["loop"].bool_value();
			dat.speed = item["speed"].int_value();
			dat.sheets = item["sheets"].int_value();
			dat.set_default_to_empty();

			graph[i].handle = new int[dat.sheets];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
			graph[i].exist = true;	//存在フラグを立てる
			graph[i].name = dat.name;
			graph[i].max = dat.sheets;	//最大枚数を求める
			LoadDivGraph(
				dat.path.c_str() ,
				dat.sheets,
				dat.column,
				dat.line,
				dat.width,
				dat.height,
				graph[i].handle
			);		//JSONに書かれた情報をLoadDivGraphから読み込む
			break;
		}
	}
}


bool GraphicResource::exist_name(std::string name)
{
	//nameが存在しているか調べるメソッド
	bool ret = false;
	for (int i = 0; i < count_of_graph; i++) {
		if (graph[i].name == name) {
			//存在していたら
			ret = true;
			break;
		}
	}
	return ret;
}

int GraphicResource::get_index(std::string name)
{
	for (int i = 0; i < count_of_graph; i++) {
		if (graph[i].name == name) return i;
	}
	return -1;
}
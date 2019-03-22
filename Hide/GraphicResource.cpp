#include"GraphicResource.h" 
#include"DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

GraphicResource::GraphicResource()
{
	std::ifstream ifs("img/resource.json");
	if (ifs.fail())
	{
		throw "resource.json is not found.";	//ファイルが読み込めないと例外を返す
	}
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	json = json11::Json::parse(json_str,err);	//json11で利用できる形式に変換
	int count_of_graph = 0;
	for (auto &item : json["graph"].array_items()) {
		//画像の枚数を数える
		count_of_graph++;
	}

	//下記の処理はload()へ移動予定
	graph = std::make_unique<GraphicObject[]>(count_of_graph);	//画像の枚数分の領域を確保する
	int i = 0;
	for (auto &item : json["graph"].array_items()) {
		graph[i].handle = new int[count_of_graph];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
		LoadDivGraph(
			item["path"].string_value().c_str(),
			item["column"].int_value() * item["line"].int_value(),
			item["column"].int_value(),
			item["line"].int_value(), 
			item["width"].int_value(), 
			item["height"].int_value(),
			graph[i].handle
		);		//JSONに書かれた情報をLoadDivGraphから読み込む
		graph[i].name = item["name"].string_value();	//JSONで指定された"name"はget()の引数に文字列として指定が可能
		graph[i].max = item["line"].int_value()*item["column"].int_value();
//		slide = item["max"].number_value();
		i++;
	}

}
//デストラクタ
GraphicResource::~GraphicResource()
{
	for (int i = 0; i < count_of_graph; i++) {
		delete graph[i].handle;	//画像は消さずにハンドル領域を削除する
	}
}
bool GraphicResource::load(std::string scope)
{
	//scopeの文字列の画像をjsonから検索し、読み込む
	//失敗すれば0、成功すれば0以外を返す
	//処理は未実装
	for (auto &item : json["graph"].array_items()) {
	}
	return true;
}

GraphicObject GraphicResource::get(std::string name)
{
	return graph[get_index(name)];
}

int GraphicResource::get_index(std::string name)
{
	for (int i = 0; i < count_of_graph; i++) {
		if (graph[i].name == name) return i;
	}
	return -1;
}
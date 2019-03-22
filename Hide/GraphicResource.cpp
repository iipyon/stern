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
	for (auto &item : json["graph"].array_items()) {
		//画像の枚数を数える
		count_of_graph++;
	}
	graph = std::make_unique<GraphicObject[]>(count_of_graph);	//画像の枚数分の領域を確保する
	for (int i = 0; i < count_of_graph; i++) graph[i].exist = false;

//	//下記の処理はload()へ移動予定  <- 済み

//	int i = 0;
//	for (auto &item : json["graph"].array_items()) {
//		graph[i].handle = new int[count_of_graph];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
//		LoadDivGraph(
//			item["path"].string_value().c_str(),
//			item["column"].int_value() * item["line"].int_value(),
//			item["column"].int_value(),
//			item["line"].int_value(), 
//			item["width"].int_value(), 
//			item["height"].int_value(),
//			graph[i].handle
//		);		//JSONに書かれた情報をLoadDivGraphから読み込む
//		graph[i].name = item["name"].string_value();	//JSONで指定された"name"はget()の引数に文字列として指定が可能
//		graph[i].max = item["line"].int_value()*item["column"].int_value();
////		slide = item["max"].number_value();
//		i++;
//	}
	//load("player");	//試験用

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
	return graph[get_index(name)];
}

void GraphicResource::register_graph(json11::Json item)
{
	for (int i = 0; i < count_of_graph; i++) {
		if (graph[i].exist == false) {
			graph[i].handle = new int[count_of_graph];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
			graph[i].exist = true;	//存在フラグを立てる
			graph[i].name = item["name"].string_value();
			graph[i].max = item["line"].int_value()*item["column"].int_value();	//最大枚数を求める
			LoadDivGraph(
				item["path"].string_value().c_str(),
				item["column"].int_value() * item["line"].int_value(),
				item["column"].int_value(),
				item["line"].int_value(),
				item["width"].int_value(),
				item["height"].int_value(),
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
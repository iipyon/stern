#include"GraphicResource.h" 
#include"DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

std::vector<std::shared_ptr<GraphicObject>> GraphicResource::graph;

void GraphicObject::set_default_to_empty()
{
	//未定義の項目に対していデフォルト値を設定する
	if (column == 0) column = 1;
	if (line == 0) line = 1;
	if (width == 0) width = 32;
	if (height == 0) height = 32;
	//if (speed == 0) speed = 0;
	if (loop == false) loop = false;
	if (column != 1) {
		if (interval == 0) interval = 60;
	}
	if (sheets == 0) sheets = line * column;
}

bool GraphicObject::exits_scope(std::string _scope)
{
	bool ret = false;
	for (auto&& scope : scopes) {
		if (scope == _scope) {
			ret = true;
			break;
		}
	}
	return ret;
}

void GraphicResource::init()
{
	std::ifstream ifs("img/resource.json");
	if (ifs.fail())
	{
		throw std::runtime_error("resource.json is not found.");	//ファイルが読み込めないと例外を返す
	}
	json11::Json json;
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);		//string形式のjson
	std::string err;
	json = json11::Json::parse(json_str,err);	//json11で利用できる形式に変換
	for (auto &item : json["graph"].array_items()) {	//名前登録とfalse初期化
		std::shared_ptr<GraphicObject> obj = std::make_shared<GraphicObject>();
		obj->exist = false;
		obj->name = item["name"].string_value();
		obj->path = item["path"].string_value();
		obj->column = item["column"].int_value();
		obj->line = item["line"].int_value();
		obj->width = item["width"].int_value();
		obj->height = item["height"].int_value();
		obj->loop = item["loop"].bool_value();
		obj->interval = item["interval"].int_value();
		obj->sheets = item["sheets"].int_value();
		for (auto &scope : item["scope"].array_items()) {
			obj->scopes.push_back(scope.string_value());
		}
		obj->set_default_to_empty();
		graph.push_back(std::move(obj));
	}
}

int GraphicResource::load(std::string _scope)
{
	//scopeの文字列の画像をjsonから検索し、読み込む
	//読み込んだ枚数を返す
	int ret = 0;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->exist == false) {	//オブジェクトが未登録
			if ((*itr)->exits_scope(_scope)) {		//scopeが存在している
				register_graph(*(*itr));
				ret++;
			}
		}
	}
	return ret;
}

int GraphicResource::unload(std::string _scope)
{
	int ret = 0;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->exist == true) {	//オブジェクトが登録済み
			if ((*itr)->exits_scope(_scope)) {		//scopeが存在している
				unregister_graph(*(*itr));
				ret++;
			}
		}
	}
	return ret;
}

void GraphicResource::unregister_graph(GraphicObject& obj)
{
	obj.exist = false;
	for(int i = 0; i < obj.sheets; i++) {
		DeleteGraph(*(obj.handle + i));
	}
	delete obj.handle;
}

std::shared_ptr<GraphicObject> GraphicResource::get(std::string name)
{
	std::shared_ptr<GraphicObject> ret = nullptr;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->name == name) {
			ret = (*itr);
		}
	}
	return ret;
}

void GraphicResource::register_graph(GraphicObject& obj)
{
	
	if(obj.exist == false){
		obj.handle = new int[obj.sheets];	//アニメーション画像のフレーム枚数分のハンドル領域を確保する
		obj.exist = true;
		LoadDivGraph(
			obj.path.c_str(),
			obj.sheets,
			obj.column,
			obj.line,
			obj.width,
			obj.height,
			obj.handle
		);		//JSONに書かれた情報をLoadDivGraphから読み込む
	}
}


bool GraphicResource::exist_name(std::string name)
{
	//nameが存在しているか調べるメソッド
	bool ret = false;
	for (auto itr = graph.begin(); itr != graph.end(); ++itr) {
		if ((*itr)->name == name) {
			ret = true;
			break;
		}
	}
	return ret;
}



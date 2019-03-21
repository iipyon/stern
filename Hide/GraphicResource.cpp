#include"GraphicResource.h" 
#include"DxLib.h" 
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "json11.hpp"

//インストラクタ
GraphicResource::GraphicResource()
{
	std::ifstream ifs("img/resource.json");
	if (ifs.fail())
	{
		throw "resource.json is not found.";	//ファイルが読み込めないと例外を返す
	}
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string json_str(it, last);
	std::string err, path;
	int slide;
	auto json = json11::Json::parse(json_str,err);	//json11で利用できる形式に変換
	auto foo = json["graph"];
	for (auto &item : json["graph"].array_items()) {
		path = item["path"].string_value();
		slide = item["slide"].number_value();
	}


	//std::string obj = json5[0]["string"].string_value();
	//*handle = new int[256];
	json11::Json json2 = json11::Json::array{
		json11::Json::object { { "k", "v" } }
	};
	std::string str2 = json2[0]["k"].string_value();
}
//デストラクタ
GraphicResource::~GraphicResource()
{
	for (int c = 0; c < 256; ++c)
	{
		//DeleteGraph(*handle[c]);
	}
}
bool GraphicResource::load(char* FileName, int AllNum, int XNum, int YNum, 
						   int XSize, int YSize, int **G_handle)
{
	//ファイル読み込み
	std::ifstream Graphic_R(FileName);
	//読み込み失敗したら返す
	if (!Graphic_R) { return false; }
	switch (graphicstate)
	{
	case GraphicState::player_stay_right:
		//*handle = *G_handle;
		break;
	case GraphicState::player_stay_left:
		//*handle = *G_handle;
		break;
	}
	//LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, *handle);

	//ファイルを閉じる
	Graphic_R.close();

	return true;
}

int GraphicResource::get(int kg_)
{
	//ハンドルを返す
	//return *handle[kg_];
	return 0;
}
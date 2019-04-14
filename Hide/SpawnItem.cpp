#include "SpawnItem.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>

SpawnItem::SpawnItem()
{
	std::ifstream itempath("img/item.json");
	if (itempath.fail()) throw "item.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(itempath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string形式のjson
	std::string err;
	item_data = json11::Json::parse(str_json, err);//Jsonで使えるようにする
}

void SpawnItem::create(std::string stg)
{
	for (auto &item : item_data[stg].array_items())
	{
		//初期値制御---------------------------------------------------------------------------------------------------------
		class Point i_point = { item["x"].int_value(),item["y"].int_value(), item["w"].int_value(), item["h"].int_value() };
		//---------------------------------------------------------------------------------------------------------
		//回復
		if (item["kind"].string_value() == "recovery") {
			//生成して現在の最後尾に登録
			ct->gts->item->push_back(std::make_unique <RecoveryItem>(i_point));
		}
	}
}

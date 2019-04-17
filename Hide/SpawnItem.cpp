#include "SpawnItem.h"
#include"DxLib.h" 
#include"GameTaskSystem.h"
#include <fstream>
#include <string>
#include <iterator>

SpawnItem::SpawnItem(std::string path_, std::shared_ptr<std::vector<std::shared_ptr<Item>>> _item) : Spawn(path_)
{
	item = _item;
}

void SpawnItem::create(std::string stg)
{
	for (auto &item_d : data[stg].array_items())
	{
		//初期値制御---------------------------------------------------------------------------------------------------------
		class Point i_point = { item_d["x"].int_value(),item_d["y"].int_value(), item_d["w"].int_value(), item_d["h"].int_value() };
		//---------------------------------------------------------------------------------------------------------
		//回復
		if (item_d["kind"].string_value() == "recovery") {
			//生成して現在の最後尾に登録
			item->push_back(std::make_unique <RecoveryItem>(i_point));
		}
	}
}

#include "SpawnEnemy.h"
#include"DxLib.h" 
#include"CoreTask.h"
#include <fstream>
#include <string>
#include <iterator>
#include"CoreTask.h"
#include "json11.hpp"

SpawnEnemy::SpawnEnemy()
{
	std::ifstream epath("img/epath.json");
	if (epath.fail()) throw "resource.json is not found.";//例外処理
	std::istreambuf_iterator<char> it(epath);
	std::istreambuf_iterator<char> last;
	std::string str_json(it, last);		//string形式のjson
	std::string err;
	data = json11::Json::parse(str_json, err);//Jsonで使えるようにする
}

void SpawnEnemy::create(std::string stg)
{
	//enemyコンストラクタにKind,X,Yが必要な可能性
	for (auto &enemy : data[stg].array_items())
	{	//int型にする
		//型変換
		//String型にする、そのあとchar型に変換
		//graph = item["graph"].string_value().c_str();    //"img/f.png";
		if(enemy["kind"].string_value().c_str() == "walking") {
			//歩行(コンストラクタ引数にx,y,graph,kindを追加する)
		    ct->gts->walking_enemy->lead();//リストを先頭に戻す
			std::shared_ptr<WalkingEnemy> new_instance = std::make_shared<WalkingEnemy>();
			ct->gts->walking_enemy->create(new_instance);//新規オブジェクトをリスト管理対象とする
			break;
		}	

		//switch文で敵の種類を識別し、リストを構築する
		//Create();//敵のリスト
	}
}

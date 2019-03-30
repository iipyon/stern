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
	{	
		//初期値制御---------------------------------------------------------------------------------------------------------
			//(Point point_, PhysicState physic_state_, EnemyState enemy_state_)
		class Point point = { enemy["x"].int_value(),enemy["y"].int_value(), enemy["w"].int_value(), enemy["h"].int_value() };
		struct PhysicState physic_state = { (float)enemy["gravity"].number_value(),(float)enemy["repulsion"].number_value(),enemy["weight"].int_value() };//float gravity, float repulsion, int weight;
		struct EnemyState enemy_state = { enemy["life"].int_value(),enemy["damage"].int_value() };//life,damage
		//---------------------------------------------------------------------------------------------------------
		//歩行
		if(enemy["kind"].string_value() == "walk") {
			//歩行(コンストラクタ引数にx,y,graph,kindを追加する)
		    ct->gts->walking_enemy->lead();//リストを先頭に戻す
			std::shared_ptr<WalkingEnemy> new_instance = std::make_shared<WalkingEnemy>(point,physic_state,enemy_state);
			ct->gts->walking_enemy->create(new_instance);//新規オブジェクトをリスト管理対象とする
		}	
		//飛行
		if (enemy["kind"].string_value() == "fly") {
			//歩行(コンストラクタ引数にx,y,graph,kindを追加する)
			ct->gts->flying_enemy->lead();//リストを先頭に戻す
			std::shared_ptr<FlyingEnemy> new_instance = std::make_shared<FlyingEnemy>(point, physic_state, enemy_state);
			ct->gts->flying_enemy->create(new_instance);//新規オブジェクトをリスト管理対象とする
		}
		//投げつける奴
		if (enemy["kind"].string_value() == "throw") {
			//歩行(コンストラクタ引数にx,y,graph,kindを追加する)
			ct->gts->throwing_enemy->lead();//リストを先頭に戻す
			std::shared_ptr<ThrowingEnemy> new_instance = std::make_shared<ThrowingEnemy>(point, physic_state, enemy_state);
			ct->gts->throwing_enemy->create(new_instance);//新規オブジェクトをリスト管理対象とする
		}
	}
}

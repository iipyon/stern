#include "GameTaskSystem.h"
#include <vector> 
#include <memory>
#include "CoreTask.h"
#include "Audio.h"
#include "Keyboard.h"
#include "screen_helper.h"
#include "screenhelper_config.h"
#include"Scene.h"
#include"GameTaskController.h"
#include"System.h"
#include "time.h"

std::unique_ptr<SpawnItem> GameTaskSystem::spawnitem;

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point;
	class Point g_point;
	struct PhysicState p_physic_state = { 1 };//gra,過去の遺物(rep,wei)
	//メモリ確保
	map = std::make_unique<Map>();
	player = std::make_shared<Player>(p_point, p_physic_state);
	item = std::make_shared<std::vector<std::shared_ptr<Item>>>();
	//スクリーン関係
	feed_flag = false;

	spawnitem = std::make_unique<SpawnItem>("img/json/item.json", item);
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::init()
{
	Audio::play("stage1");
	Camera::init();
	map->init();
	player->init();
	feed_flag = false;
	ct->score = 0;
	//map
	srand((unsigned int)time(NULL));
	map_createflag = false;
	mapsize=map->Create((char*)"1", 0);
	spawnitem->create("1", 0);
}

void GameTaskSystem::init_member()
{
	feed_flag = false;
	GameOverController::set_gameover(false);
}


void GameTaskSystem::update()
{
	map->update();


	player->update();
	Camera::update();

	//--------------------------------
	//アイテム-----------------------------
	for (auto itr = item->begin(); itr != item->end(); ++itr) {
		(*itr)->update();
	}
	attack_player_item();

	//ポーズへの遷移---------------------------------------------
	if (Keyboard::key_down(KEY_INPUT_BACK)) {
		Audio::play("decision");
		feed_flag = true;
	}

	else if (feed_flag) {//ゴールしてなくてフェードフラグが起動したら
		//ポーズ遷移
		//プレイヤーの死亡フラグ分が追加になるかもしれない
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			if (GameOverController::get_gameover_flag()) 
			{//trueなら
				Scene::set_scene(SceneType::gameover);
			}
		}
	}
	else {//フェードフラグさえ起動していないならとにかく薄くする
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}

	if (map_createflag) {
		int rand_mapnum = rand() % 4+1;
		switch (rand_mapnum) {
		case 1:
			mapnum = "1";
			break;
		case 2:
			mapnum = "2";
			break;
		case 3:
			mapnum = "3";
			break;
		case 4:
			mapnum = "4";
			break;
		}
		spawnitem->create(mapnum, mapsize);//アイテムの生成
		mapsize=map->Create(mapnum, mapsize);
		map_createflag = false;
	}

	//スコアの表示
	DrawFormatString(System::width-100, 0, GetColor(255, 255, 255), "%d点", ct->score);
	//速度の表示
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%fkm", ct->gts->player->speed);
}

void GameTaskSystem::finalize()
{
	Audio::stop("stage1");

	item->clear();
}

void GameTaskSystem::set_feed_flag(bool set)
{
	feed_flag = set;
}

void GameTaskSystem::Set_createflag() {
	map_createflag = true;
}



void GameTaskSystem::attack_player_item()
{
	for (auto itr = item->begin(); itr != item->end(); itr++) {
		if (CheckHit(player->get_point(), (*itr)->get_point())) {
			item->erase(itr);
			break;
		}
	}
}

void GameTaskSystem::callGameOver()
{
	Audio::stop("stage1");
		item->clear();
	Scene::set_scene(SceneType::gameover);
}


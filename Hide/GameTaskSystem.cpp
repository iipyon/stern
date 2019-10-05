#include "GameTaskSystem.h"
#include <vector> 
#include <memory>
#include "CoreTask.h"
#include "Audio.h"
#include "Keyboard.h"
#include "screen_helper.h"
#include "screenhelper_config.h"
#include"Scene.h"
#include"PlayerController.h"
#include"GameTaskController.h"

std::unique_ptr<SpawnItem> GameTaskSystem::spawnitem;

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point;
	class Point g_point;
	struct PhysicState p_physic_state = { 1 };//gra,過去の遺物(rep,wei)
	//メモリ確保
	goal = std::make_unique<Goal>(g_point);
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
	//ステージごとに音楽を入れ替える
	switch (StageSelectTaskSystem::get_stage()) {
	case 1:
		Audio::play("stage1");
		break;
	case 2:
		Audio::play("stage2");
		break;
	case 3:
		Audio::play("stage3");
		break;
	case 4:
		Audio::play("stage4");
		break;
	}
	Camera::init();
	player->init();
	goal->init();
	feed_flag = false;

	//map
	map_createflag = false;
	mapsize=map->Create((char*)"1", 0);
	spawnitem->create("1", 0);
}

void GameTaskSystem::init_member()
{
	feed_flag = false;
	GameOverController::set_gameover(false);
	goal->set_clearflag(false);
}


void GameTaskSystem::update()
{
	map->update();
	goal->update();


	//--------------------------------
	//アイテム-----------------------------
	for (auto itr = item->begin(); itr != item->end(); ++itr) {
		(*itr)->update();
	}
	player->update();
	Camera::update();
	/*attack_player_item();*/

	//ポーズへの遷移---------------------------------------------
	if (Keyboard::key_down(KEY_INPUT_BACK)) {
		Audio::play("decision");
		feed_flag = true;
	}
	if (goal->get_clear_flag()) {//ゴール時

		if (ScreenFunc::FeedOut(ScreenHelperGraph::white_graph)) {
			finalize();
			Scene::set_scene(SceneType::clear);
		}
	}
	else if (feed_flag) {//ゴールしてなくてフェードフラグが起動したら
		//ポーズ遷移
		//プレイヤーの死亡フラグ分が追加になるかもしれない
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			if (GameOverController::get_gameover_flag()) 
			{//trueなら
				Scene::set_scene(SceneType::gameover);
			}
			else {
				Scene::set_scene(SceneType::pause);
			}
		}
	}
	else {//フェードフラグさえ起動していないならとにかく薄くすrurururururururu
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}

	if (map_createflag) {
		int rand_mapnum = rand() % 4;
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
		spawnitem->create("1", mapsize);//アイテムの生成
		mapsize=map->Create(mapnum, mapsize);
		map_createflag = false;
	}
}

void GameTaskSystem::finalize()
{
	//ステージごとに音楽を入れ替える
	switch (ct->ssts->get_stage()) {
	case 1:
		Audio::stop("stage1");
		break;
	case 2:
		Audio::stop("stage2");
		break;
	case 3:
		Audio::stop("stage3");
		break;
	case 4:
		Audio::stop("stage4");
		break;

	}

	item->clear();
}

void GameTaskSystem::set_feed_flag(bool set)
{
	feed_flag = set;
}

void GameTaskSystem::Set_createflag() {
	map_createflag = true;
}



/*void GameTaskSystem::attack_player_item()
{
	for (auto itr = item->begin(); itr != item->end(); itr++) {
		if (CheckHit(player->get_point(), (*itr)->get_point())) {
			item->erase(itr);
			break;
		}
	}
}*/

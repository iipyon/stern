#include "GameTaskSystem.h"
#include <vector> 
#include <memory>
#include"CoreTask.h"
#include"Audio.h"

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point = { 100,300,30,30 };
	class Point g_point = { 30,510,30,30 };
	struct PhysicState p_physic_state = { 1};//gra,過去の遺物(rep,wei)
	struct PlayerState player_state = { 3,2 };//life,hp

	goal = std::make_unique<Goal>(g_point);
	map = std::make_unique<Map>();
	player = std::make_shared<Player>(p_point, p_physic_state, player_state);
	enemys = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	enemy_transaction = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	item = std::make_shared<std::vector<std::shared_ptr<Item>>>();
	feedcnt = 0;
	deg_flag = false;
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::init()
{
	//ステージごとに音楽を入れ替える
	switch (ct->ssts->get_stage()) {
	case 1:
		Audio::play("stage1");
		break;
	}
	Camera::init();
	player->init();
	goal->init();
}


void GameTaskSystem::update()
{
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	//ポーズへの遷移
	if (Keyboard::key_down(KEY_INPUT_BACK)) {
		Audio::play("decision");
		deg_flag = true;
	}
	if (deg_flag) {
		if (ScreenFunc::FeedOut(deg_flag, feedcnt)) {
			ct->scene = Scene::pause;
		}
	}
	map->update();
	goal->update();
	//☆------------------------------
	for (auto itr = normalstar.begin(); itr != normalstar.end(); itr++) {
		itr->update();
	}
	//--------------------------------
	//敵------------------------------先頭から終端まで
	for (auto itr = enemys->begin(); itr != enemys->end(); ++itr) {
		(*itr)->update();
	}
	//--------------------------------
	//アイテム-----------------------------
	for (auto itr = item->begin(); itr != item->end(); ++itr) {
		(*itr)->update();
	}
	player->update();
	Camera::update();
	attack_player_enemy();
	attack_player_item();
	attack_star_enemy();
	//トランザクションの実行
	for (auto itr = enemy_transaction->begin(); itr != enemy_transaction->end(); ++itr) {
		enemys->push_back(std::move((*itr)));	//トランザクションから実体へ所有権を移動する
	}
	enemy_transaction->clear();	//enemy_transactionを空にする
}

void GameTaskSystem::finalize()
{
	//ステージごとに音楽を入れ替える
	switch (ct->ssts->get_stage()) {
	case 1:
		Audio::stop("stage1");
		break;
	}
	normalstar.clear();
	enemys->clear();
	item->clear();
}

void GameTaskSystem::attack_player_enemy()
{
	for (auto itr = enemys->begin(); itr != enemys->end(); itr++) {
		if (CheckHit(ct->gts->player->get_point(), (*itr)->get_point())) {
			if (!(ct->gts->player->damage())) {
				//PlayerのLifeが0になったら
				//処理未定
				enemys->erase(itr);
				break;
			}
			
		}
	}
}

void GameTaskSystem::attack_player_item()
{
	for (auto itr = item->begin(); itr != item->end(); itr++) {
		if (CheckHit(player->get_point(), (*itr)->get_point())) {
			//アイテムの識別手段が未確定
			break;
		}
	}
}

void GameTaskSystem::attack_star_enemy()
{
	bool deleted = false;
	for (auto enemy_itr = enemys->begin(); enemy_itr != enemys->end(); enemy_itr++) {
		for (auto star_itr = normalstar.begin(); star_itr != normalstar.end(); star_itr++) {
			if (CheckHit((*enemy_itr)->get_point(), (*star_itr).get_point())) {
				enemys->erase(enemy_itr);
				normalstar.erase(star_itr);
				deleted = true;
				break;
			}
			
		}
		if (deleted == true)break;
	}
}
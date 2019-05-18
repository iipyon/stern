#include "GameTaskSystem.h"
#include <vector> 
#include <memory>
#include"Audio.h"
#include"screen_helper.h"
#include "RecoveryItem.h"
#include "WalkingEnemy.h"
#include "BulletEnemy.h"
#include "FlyingEnemy.h"
#include "CoreTask.h"
//
#include "Keyboard.h"
#include "model.h"
#include "Controller.h"


GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point;
	class Point g_point;
	struct PhysicState p_physic_state = { 1};//gra,過去の遺物(rep,wei)
	struct PlayerState player_state = { 3,2 };//life,hp

	mdl::goal = std::make_unique<Goal>(g_point);
	ctl::map = std::make_unique<Map>();
	mdl::gravityStar = std::vector<GravityStar>();
	mdl::player = std::make_shared<Player>(p_point, p_physic_state, player_state);
	mdl::enemys = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	mdl::enemy_transaction = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	mdl::item = std::make_shared<std::vector<std::shared_ptr<Item>>>();
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
	mdl::player->init();
	mdl::goal->init();
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
			ct->change_scene(Scene::pause);
		}
	}
	ctl::map->update();
	mdl::goal->update();
	//☆------------------------------
	for (auto itr = normalstar.begin(); itr != normalstar.end(); itr++) {
		if (itr->damage(1)) {
			normalstar.erase(itr);
			break;
		}
		itr->update();
	}
	for (auto itr = gravityStar.begin(); itr != gravityStar.end(); itr++) {

		itr->update();
	}
	//--------------------------------
	//敵------------------------------先頭から終端まで
	for (auto itr = mdl::enemys->begin(); itr != mdl::enemys->end(); ++itr) {
		(*itr)->update();
	}
	//--------------------------------
	//アイテム-----------------------------
	for (auto itr = mdl::item->begin(); itr != mdl::item->end(); ++itr) {
		(*itr)->update();
	}
	mdl::player->update();
	Camera::update();
	attack_player_enemy();
	attack_player_item();
	attack_star_enemy();
	//トランザクションの実行
	for (auto itr = mdl::enemy_transaction->begin(); itr != mdl::enemy_transaction->end(); ++itr) {
		mdl::enemys->push_back(std::move((*itr)));	//トランザクションから実体へ所有権を移動する
	}
	mdl::enemy_transaction->clear();	//enemy_transactionを空にする
}

void GameTaskSystem::finalize()
{
	//ステージごとに音楽を入れ替える
	switch (ct->ssts->get_stage()) {
	case 1:
		Audio::stop("stage1");
		break;
	}
	mdl::normalstar.clear();
	mdl::enemys->clear();
	mdl::item->clear();
}

void GameTaskSystem::attack_player_enemy()
{
	for (auto itr = mdl::enemys->begin(); itr != mdl::enemys->end(); itr++) {
		if (CheckHit(mdl::player->get_point(), (*itr)->get_point())) {
			if (!(mdl::player->damage())) {
				//PlayerのLifeが0になったら
				//処理未定
				//mdl::enemys->erase(itr);
				break;
			}
			
		}
	}
}

void GameTaskSystem::attack_player_item()
{
	for (auto itr = item->begin(); itr != item->end(); itr++) {
		if (CheckHit(player->get_point(), (*itr)->get_point())) {
			ct->gts->player->recover();
			item->erase(itr);
			break;
		}
	}
}

void GameTaskSystem::attack_star_enemy()
{
	bool deleted = false;
	for (auto enemy_itr = mdl::enemys->begin(); enemy_itr != mdl::enemys->end(); enemy_itr++) {
		for (auto star_itr = mdl::normalstar.begin(); star_itr != mdl::normalstar.end(); star_itr++) {
			if (CheckHit((*enemy_itr)->get_point(), (*star_itr).get_point())) {
				mdl::enemys->erase(enemy_itr);
				mdl::normalstar.erase(star_itr);
				deleted = true;
				break;
			}
			
		}
		if (deleted == true)break;
	}
}
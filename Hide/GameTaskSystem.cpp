#include "GameTaskSystem.h"
#include <vector> 
#include <memory>
#include"CoreTask.h"
#include"Audio.h"
#include "Keyboard.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include "Scene.h"
#include"PlayerController.h"

GameTaskSystem::GameTaskSystem()
{
	//Point point_, PhysicState physic_state_, PlayerState player_state
	class Point p_point;
	class Point g_point;
	struct PhysicState p_physic_state = { 1 };//gra,過去の遺物(rep,wei)
	//メモリ確保
	goal = std::make_unique<Goal>(g_point);
	map = std::make_unique<Map>();
	gravityStar = std::vector<GravityStar>();
	player = std::make_shared<Player>(p_point, p_physic_state);
	enemys = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	enemy_transaction = std::make_shared<std::vector<std::shared_ptr<Enemy>>>();
	item = std::make_shared<std::vector<std::shared_ptr<Item>>>();
	//スクリーン関係
	feed_flag = false;
	gameover = false;
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
	}
	Camera::init();
	player->init();
	goal->init();
	feed_flag = false;
}

void GameTaskSystem::init_member()
{
	feed_flag = false;
	gameover = false;
	goal->set_clearflag(false);
}


void GameTaskSystem::update()
{
	map->update();
	goal->update();
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
	deleted_bullet_enemy();//存在フラグを用意してhp0またはマップヒットで死亡する（bulletのみ）
	//トランザクションの実行
	for (auto itr = enemy_transaction->begin(); itr != enemy_transaction->end(); ++itr) {
		enemys->push_back(std::move((*itr)));	//トランザクションから実体へ所有権を移動する
	}
	enemy_transaction->clear();	//enemy_transactionを空にする

	//ポーズへの遷移---------------------------------------------
	if (Keyboard::key_down(KEY_INPUT_BACK)) {
		Audio::play("decision");
		feed_flag = true;
	}
	if (goal->get_clear_flag()) {//ゴール時
		if (ScreenFunc::FeedOut(ScreenHelperGraph::white_graph)) {
			Scene::set_scene(SceneType::clear);
		}
	}
	else if (feed_flag) {//ゴールしてなくてフェードフラグが起動したら
		//ポーズ遷移
		//プレイヤーの死亡フラグ分が追加になるかもしれない
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			if (gameover) {
				Scene::set_scene(SceneType::gameover);
			}
			else{
				Scene::set_scene(SceneType::pause);
			}
		}
	}
	else {//フェードフラグさえ起動していないならとにかく薄くすrurururururururu
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}
	//------------------------------------------------------------
	//ゲームオーバーへの遷移
	//プレイヤーが死んだらの中に記述予定
	//feed_flag = true;//死んだらフェード開始
	/*if (feed_flag) {//ホワイトアウト
		if (ScreenFunc::FeedOut(ScreenHelperGraph::white_graph)) {
			ct->change_scene(Scene::gameover);
		}
	}*/
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

void GameTaskSystem::set_gameover_flag(bool flag)
{
	gameover = flag;
}

bool GameTaskSystem::get_gameover_flag()
{
	return gameover;
}

void GameTaskSystem::set_feed_flag(bool set)
{
	feed_flag = set;
}

void GameTaskSystem::attack_player_enemy()
{
	for (auto itr = enemys->begin(); itr != enemys->end(); itr++) {
		if (CheckHit(ct->gts->player->get_point(), (*itr)->get_point())) {
			if (!(ct->gts->player->damage())) {
				//PlayerのLifeが0になったら
				//処理未定
				//enemys->erase(itr);
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

void GameTaskSystem::deleted_bullet_enemy()
{
	for (auto bullet_itr = enemys->begin(); bullet_itr != enemys->end(); bullet_itr++) {
		if (!(*bullet_itr)->get_active()){
			enemys->erase(bullet_itr);
			break;//消したらブレイク
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
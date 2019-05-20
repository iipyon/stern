﻿#include "Player.h"
#include"Point.h"
#include"CoreTask.h"
#include"Keyboard.h"

//----------------------------------
//プレイヤー
//----------------------------------

Player::PlayerInterface::PlayerInterface()
{
	hpgraph = LoadGraph("img/hp.png");
	hpfreamgraph = LoadGraph("img/hpfream.png");
	lifegraph = LoadGraph("img/life.png");
}

void Player::PlayerInterface::draw()
{
	//残機
	DrawGraph(500, 0, lifegraph, FALSE);
	DrawFormatString(540, 0, GetColor(255, 255, 255), " × %d",life);
	//HP
	for (int i = 0; i < 3; ++i) {
		DrawGraph(40 * i, 0, hpfreamgraph, FALSE);
		for (int j = 0; j < hp; ++j) {
			DrawGraph(40 * j, 0, hpgraph, TRUE);
		}
	}
}

void Player::PlayerInterface::update(int hp_,int life_)
{
	hp = hp_;
	life = life_;
	draw();
}

Player::StarManager::StarManager()
{
	graph = LoadGraph("img/cursor.png");
}

void Player::StarManager::draw(double st, int x)
{
	DrawFormatString(200, 100, GetColor(255, 255, 0), "Map::get_camera().y : %d", Map::get_camera().y);
	DrawRotaGraph2(x - Map::get_camera().x+ ct->gts->player->get_point().w / 2, 0, 15, 0, 1, st, graph, FALSE);//Xにプレーヤー.wの半分だけついか
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);
	if (starmanagercoolCnt <= 0) {
		if (Keyboard::key_down(KEY_INPUT_Z)) {
			starmanagercoolCnt = 180;   //クールタイム180フレーム
			class Point point = { x_,Map::get_camera().y,30,30 };
			struct PhysicState physic_state = { 1 };//	float gravity;
			struct StarState star_state = { 10,10,10,50,ang };//	int bright, int radius, int power, int life, double angle;

			ct->gts->normalstar.push_back(NormalStar{ point,physic_state,star_state });	//新規インスタンスを生成して最後尾へ登録する
			//ノーマルスター
			//Point point_, PhysicState physic_state_, StarState star_state
		}
	}
	if (starmanagercoolCnt > 0) {
		starmanagercoolCnt--;
	}
	if (Keyboard::key_down(KEY_INPUT_V)) {
		ct->gts->gravityStar.clear();
		class Point point = { x_ ,Map::get_camera().y,30,30 };
		struct PhysicState physic_state = { 1 };//	float gravity;
		struct StarState star_state = { 10,10,10,50,ang };//	int bright, int radius, int power, int life, double angle;

		ct->gts->gravityStar.push_back(GravityStar{ point,physic_state,star_state });	//新規インスタンスを生成して最後尾へ登録する

	}
}

Player::Player(Point point_, PhysicState physic_state_, PlayerState player_state):BasicObject(point)
{
	life = player_state.life;
	hp = player_state.life;
	angle = 0;
	invincible = 0;
	jumpCnt = 0;
	interval = 0;
	//graph = LoadGraph("img/player.png");
	starmanager = std::make_unique<StarManager>();
	playerinterface = std::make_unique<PlayerInterface>();

}
void Player::spawn(int x_, int y_, int w_, int h_)
{
	p_point = { x_,y_,w_,h_ };
}
void Player::init()
{
	point = p_point;
	shape->set("player");//resource.jsonのnameが"player"のものをセットする
}

double Player::get_angle()
{
	return angle;
}

void Player::update()
{
	//仮の移動とカーソル角度調整-------------
	move();
	if (Keyboard::key_press(KEY_INPUT_Q)) {
		angle += 0.05;
	}
	if (Keyboard::key_press(KEY_INPUT_E)) {
		angle -= 0.05;
	}
	//---------------------------------------
	starmanager->update(angle, point.x);
	playerinterface->update(hp,life);
	if (invincible % 4 <= 2) {
		shape->draw(point);
	}
	if (jumpCnt <= 0) {
		point.y += physicshape->fall(point);
	}
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", point.x);//L
	DrawFormatString(0, 50, GetColor(255, 0, 0), "%d", point.y);//T
	if (invincible > 0) {
		invincible--;
	}
}

bool Player::damage()
{
	if (invincible <= 0) {
		invincible = 180;
		hp -= 1;
		if (hp <= 0) {
			return true;
		}
	}
	return false;
}

void Player::draw_interface(int)
{
}

void Player::move()
{
	//左右移動
	if (Keyboard::key_press(KEY_INPUT_LEFT)) {
		if (Keyboard::key_press(KEY_INPUT_C)/* && velocityX <= -6*/) { //仮のダッシュ処理
			/*velocityX--;*/
			point.x+= physicshape->Movement_X(point, -6);
		}
		else {
			point.x += physicshape->Movement_X(point, -3);
		}
	}
	if (Keyboard::key_press(KEY_INPUT_RIGHT)) {
		if (Keyboard::key_press(KEY_INPUT_C)) {  //仮のダッシュの処理
			/*if (velocityX <= +6) {
				velocityX++;
			}*/
			point.x += physicshape->Movement_X(point, 6);
		}
		else {
			point.x += physicshape->Movement_X(point, 3);
		}
	}
	//ジャンプ
	if (point.y==preY) {
		if (Keyboard::key_press(KEY_INPUT_X)) {


			if (Keyboard::key_down(KEY_INPUT_X)) {
				jumpCnt = 11;
			}
			if (jumpCnt > 0) {
				
				point.y += physicshape->Movement_Y(point, -jumpCnt - 8);//jumpCntを設けないと空中浮遊する
				Point extendpoint = point;
				extendpoint.y--;
				if (ct->gts->map->get_top(extendpoint)) {
					jumpCnt = 0;
				}

			}
		}
	}
	if (Keyboard::key_up(KEY_INPUT_X)) {
		jumpCnt = 0;
	}
	jumpCnt--;
	preY = point.y;
}

bool Player::knockback(int)
{
	return false;
}

void Player::jump(int pow) {
	while (pow > 0) {
		point.y += physicshape->Movement_Y(point, -pow);
		pow--;
	}
}



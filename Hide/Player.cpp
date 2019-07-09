﻿#include"GameTaskController.h"
#include "Player.h"
#include"Point.h"
#include"CoreTask.h"
#include"Keyboard.h"
#include "Mouse.h"
#include "PlayerConfig.h"
#include"System.h"
#include"environments.h"
#include"Audio.h"
//----------------------------------
//プレイヤー
//----------------------------------

Player::PlayerInterface::PlayerInterface()
{
	hpgraph = LoadGraph("img/graphics/UI/hp.png");
	hpfreamgraph = LoadGraph("img/graphics/UI/hpfream.png");
	lifegraph = LoadGraph("img/graphics/UI/life.png");
}

void Player::PlayerInterface::draw()
{
	//残機
	DrawGraph(System::width - 100, 0, lifegraph, FALSE);
	DrawFormatString(System::width - 60, 0, GetColor(255, 255, 255), " × %d", life);
	//HP
	for (int i = 0; i < 3; ++i) {
		DrawGraph(40 * i, 0, hpfreamgraph, FALSE);
		for (int j = 0; j < hp; ++j) {
			DrawGraph(40 * j, 0, hpgraph, TRUE);
		}
	}
}

void Player::PlayerInterface::update(int hp_, int life_)
{
	hp = hp_;
	life = life_;
	draw();
}


Player::Player(Point point_, PhysicState physic_state_) :BasicObject(point)
{
	life = PLAYER_MAX_LIFE;
	hp = PLAYER_MAX_HP;
	angle = 0;
	invincible = 0;
	jumpCnt = 0;
	interval = 0;
	playerinterface = std::make_unique<PlayerInterface>();
}
void Player::spawn(int x_, int y_, int w_, int h_)
{
	p_point = { x_,y_,w_,h_ };
}
void Player::init()
{
	point = p_point;
	shape->set("player_idol_Right");//resource.jsonのnameが"player"のものをセットする
}

bool Player::recover()
{
	bool ret = false;
	if (hp < PLAYER_MAX_HP) {
		hp++;
		ret = true;
	}
	return ret;
}



void Player::update()
{
	//仮の移動とカーソル角度調整-------------
	move();
	anim();
	//---------------------------------------
	if (Mouse::Mouse_press()) {
		int posX=0;
		int posY=0;
		GetMousePoint(&posX, &posY);
		Point clickpos{posX,posY,0,0 };
		createfook(clickpos);
	}
	playerinterface->update(hp, life);
	if (invincible % 4 <= 2) {
		shape->draw(point);
	}
	if (jumpCnt <= 0) {
		point.y += physicshape->fall(point);
	}
	if (invincible > 0) {
		invincible--;
	}
}

bool Player::damage()
{
	if (invincible <= 0) {
		invincible = PLAYER_INVINCIBLE;
		hp -= 1;
		damageanim = true;
		Audio::play("damage");
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
		angle_LR = Left;
		if (Keyboard::key_press(KEY_INPUT_C)) { //仮のダッシュ処理
			point.x += physicshape->Movement_X(point, -PLAYER_MAX_SPEED);
		}
		else {
			point.x += physicshape->Movement_X(point, -PLAYER_SPEED);
		}
	}
	if (Keyboard::key_press(KEY_INPUT_RIGHT)) {
		angle_LR = Right;
		if (Keyboard::key_press(KEY_INPUT_C)) {  //仮のダッシュの処理
			point.x += physicshape->Movement_X(point, PLAYER_MAX_SPEED);
		}
		else {
			point.x += physicshape->Movement_X(point, PLAYER_SPEED);
		}
	}
	//ジャンプ
	if (point.y == preY) {
		if (Keyboard::key_press(KEY_INPUT_X)) {
			if (Keyboard::key_down(KEY_INPUT_X)) {
				jumpCnt = PLAYER_MAX_JUMP;
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
void Player::anim() {
	bool anim_called = true;
	if (damageanim == true) {//ダメージを受けた時
		damageanim = false;
		if (angle_LR == Right) {
			if (anim_called) {
				anim_called = false;
				shape->set("player_damage_Right");
			}
		}
		else {
			if (anim_called) {
				anim_called = false;
				shape->set("player_damage_Left");
			}

		}
	}
	if ((Keyboard::key_press(KEY_INPUT_RIGHT) && Keyboard::key_down(KEY_INPUT_LEFT)) ||
		(Keyboard::key_down(KEY_INPUT_RIGHT) && Keyboard::key_press(KEY_INPUT_LEFT))) {		//キーが両方押された瞬間
		if (angle_LR == Right) {
			if (anim_called) {
				anim_called = false;
				shape->set("player_idol_Right");
			}
		}
		else {
			if (anim_called) {
				anim_called = false;
				shape->set("player_idol_Left");
			}

		}
	}
	if (Keyboard::key_press(KEY_INPUT_RIGHT) && Keyboard::key_up(KEY_INPUT_LEFT)) {		//キーが両方押された状態から左キーが離された瞬間

		if (anim_called) {
			anim_called = false;
			shape->set("player_walk_Right");
		}


	}
	if (Keyboard::key_up(KEY_INPUT_RIGHT) && Keyboard::key_press(KEY_INPUT_LEFT)) {//キーが両方押された状態から右キーが離された瞬間
		if (anim_called) {
			anim_called = false;
			shape->set("player_walk_Left");
		}
	}
	if (Keyboard::key_down(KEY_INPUT_X)) {		//Xキーを押した処理
		if (angle_LR == Right) {
			if (anim_called) {
				anim_called = false;
				shape->set("player_jump_Right");
			}
		}
		else {
			if (anim_called) {
				anim_called = false;
				shape->set("player_jump_Left");
			}
		}

	}
	if (Keyboard::key_down(KEY_INPUT_Z) || Keyboard::key_down(KEY_INPUT_V)) {		//Z、Vキーを押した処理
		if (angle_LR == Right) {
			if (anim_called) {
				anim_called = false;
				shape->set("player_attack_Right");
			}
		}
		else {
			if (anim_called) {
				anim_called = false;
				shape->set("player_attack_Left");
			}
		}

	}
	if (Keyboard::key_down(KEY_INPUT_LEFT)) {//左キーを押した処理
		if (anim_called) {
			anim_called = false;
			shape->set("player_walk_Left");
		}
	}
	if (Keyboard::key_down(KEY_INPUT_RIGHT)) {//右キーを押した処理
		if (anim_called) {
			anim_called = false;
			shape->set("player_walk_Right");
		}
	}
	if ((!(Keyboard::key_press(KEY_INPUT_RIGHT)) && Keyboard::key_up(KEY_INPUT_LEFT)) ||
		((Keyboard::key_up(KEY_INPUT_RIGHT)) && !(Keyboard::key_press(KEY_INPUT_LEFT)))) {		//キーが両方離された瞬間
		if (angle_LR == Right) {
			if (anim_called) {
				anim_called = false;
				shape->set("player_idol_Right");
			}
		}
		else {
			if (anim_called) {
				anim_called = false;
				shape->set("player_idol_Left");
			}

		}
	}
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

void Player::createfook(Point pos) {
	DrawFormatString(300, 0, GetColor(0, 0, 0), "%d", pos.x);
}


//アクセサメソッド

void Player::set_hp(int hp) {
	if (hp < 0) hp = 0;
	this->hp = hp;
}
int Player::get_hp() {
	return this->hp;
}
void Player::set_angle(double angle) {
	this->angle = angle;
}
double Player::get_angle()
{
	return this->angle;
}
void Player::set_invincible(int invincible) {
	this->invincible = invincible;
}
int Player::get_invincible() {
	return this->invincible;
}
void Player::set_life(int life) {
	this->life = life;
}
int Player::get_life() {
	return this->life;
}
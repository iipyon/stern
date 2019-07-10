#include"GameTaskController.h"
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




Player::Player(Point point_, PhysicState physic_state_) :BasicObject(point)
{
	speed = 10;
	angle = 0;
	invincible = 0;
	jumpCnt = 0;
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
		damageanim = true;
		Audio::play("damage");

	}
	return false;
}



void Player::move()
{
	//常にダッシュ
	point.x += physicshape->Movement_X(point, speed);
	
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

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
	dobblejumpCnt = 0;
	dobblejumpflag = false;
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
	move();
	//anim();
	
	if (Mouse::Mouse_press()) {
		int posX=0;
		int posY=0;
		GetMousePoint(&posX, &posY);
		Point clickpos{posX,posY,0,0 };
		createfook(clickpos);
	}


	if (jumpCnt <= 0 && dobblejumpCnt <= 0) {//落下中か否か
		point.y += physicshape->fall(point);
	}

	shape->draw(point);
	/*if (invincible % 4 <= 2) {//無敵状態の設定（現在必要なし）
		shape->draw(point);
	}
	if (invincible > 0) {
		invincible--;
	}*/
}

bool Player::damage()//使うかも？
{
	if (invincible <= 0) {
		invincible = PLAYER_INVINCIBLE;
		//damageanim = true;
		Audio::play("damage");

	}
	return false;
}



void Player::move()
{
	//常にダッシュ
	point.x += physicshape->Movement_X(point, speed);
	
	//ジャンプ
	if (Keyboard::key_press(KEY_INPUT_X)) {
		if (jumpCnt >= -10 && dobblejumpflag == false&&Keyboard::key_down(KEY_INPUT_X)) {
			dobblejumpflag = true;
			dobblejumpCnt = PLAYER_MAX_JUMP*3/4;

			if (dobblejumpCnt > 0) {
				point.y += physicshape->Movement_Y(point, -dobblejumpCnt - PLAYER_MIN_JUMP);
			}
		}
		else {

		if (preY == point.y) {
			if (Keyboard::key_down(KEY_INPUT_X)) {
				jumpCnt = PLAYER_MAX_JUMP;
				dobblejumpflag = false;
			}
			if (jumpCnt > 0) {
				point.y += physicshape->Movement_Y(point, -jumpCnt - PLAYER_MIN_JUMP);
			}
		}
	
		}
	}
	if (Keyboard::key_up(KEY_INPUT_X)) {//Xキーを離したら
		jumpCnt = 0;
		dobblejumpCnt=0;
	}

	preY = point.y;
	jumpCnt--;
	dobblejumpCnt--;
}


/*void Player::anim() {//アニメーション処理（未実装）
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
}*/



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

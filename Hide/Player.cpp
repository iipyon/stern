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
	motion = Dash;
	moveCnt = 0;
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
	think();
	move();
	//anim();
	
	//フックを出す処理
	if (Mouse::Mouse_press()) {
		int posX=0;//一時計算用
		int posY=0;
		GetMousePoint(&posX, &posY);
		Point clickpos{posX,posY,0,0 };
		createfook(clickpos);
	}
	if (ct->gts->map->total_mapsizex - System::width <= point.x) {
		ct->gts->map->Set_createflag();
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

void Player::think() {//move関数のするべき動きを指定する関数
    Motion now = this->motion;
	switch (now)
	{
	case Stop:

		break;
	case Dash:
		if (ct->gts->map->get_bottom(point) == 0) {
			now = Fall;
		}
		if (Keyboard::key_down(KEY_INPUT_X)) {
			now = Jump;
		}
		break;
	case Jump:
	
		if (moveCnt == 0) {
			now = Fall;
		}
		if (Keyboard::key_down(KEY_INPUT_X)) {
			now = Jump2;
		}
		break;
	case Fall:
		if (ct->gts->map->get_bottom(point) == 1) {
			now = Dash;
		}
		if (Keyboard::key_down(KEY_INPUT_X)) {
			now = Jump2;
		}
		break;
	case Jump2:
		if (moveCnt == 0) {
			now = Fall2;
		}
		break;
	case Fall2:
		if (ct->gts->map->get_bottom(point) == 1) {
			now = Dash;
		}
		break;
	}
	if (motion != now) {
		moveCnt = 0;
		this->motion = now;
	}

}

void Player::move()
{
	
	switch (this->motion)
	{
	case Stop:

		break;
	case Dash:
		physicshape->init_velocity();//落下速度の初期化
		this->point.x += physicshape->Movement_X(point,int( this->speed));
		break;
	case Jump:
		this->point.x += physicshape->Movement_X(point, int(this->speed));
		if (moveCnt == 0) {//ジャンプをした瞬間ならばジャンプの大きさを設定
			moveCnt = PLAYER_MAX_JUMP;
		}
		this->point.y += physicshape->Movement_Y(point, -moveCnt);
		moveCnt--;
		break;
	case Fall:
		this->point.x += physicshape->Movement_X(point, int(this->speed));
		
		point.y += physicshape->fall(point);
		break;
	case Jump2:
		physicshape->init_velocity();//落下速度の初期化
		this->point.x += physicshape->Movement_X(point, int(this->speed));
		if (moveCnt == 0) {//ジャンプをした瞬間ならばジャンプの大きさを設定
			moveCnt = PLAYER_MAX_JUMP;
		}
		this->point.y += physicshape->Movement_Y(point, -moveCnt);
		moveCnt--;
		break;
	case Fall2:
		this->point.x += physicshape->Movement_X(point, int(this->speed));
		point.y += physicshape->fall(point);
		break;
	}

	/*//左右移動//緊急用手動操作コード
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
	}*/
	

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

#include "Player.h"
#include"Point.h"
#include"GameTaskSystem.h"

//----------------------------------
//プレイヤー
//----------------------------------

void Player::PlayerInterface::Draw(int st)
{

}

Player::StarManager::StarManager()
{
	graph = LoadGraph("img/cursor.png");
}

void Player::StarManager::draw(double st, int x)
{
	DrawRotaGraph2(x, 20, 15, 15, 1.5, st, graph, FALSE);
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);
}

Player::Player()
{
	x = 200;
	y = 200;
	height = 30;
	width = 30;
	life = 0;
	angle = 0;
	invincible = 0;
	hp = 0;
	interval = 0;
	foot_status = false;
	graph = LoadGraph("img/player.png");
}

double Player::get_angle()
{
	return angle;
}

void Player::update()
{
	//仮の移動とカーソル角度調整-------------
	move();
	if (CheckHitKey(KEY_INPUT_Q)) {
		angle += 0.05;
	}
	if (CheckHitKey(KEY_INPUT_E)) {
		angle -= 0.05;
	}
	//---------------------------------------
	starmanager->update(angle, x);
	draw();

	DrawFormatString(0, 100, GetColor(255, 0, 0), "%d", foot_status);
	DrawFormatString(0, 0, GetColor(255, 0, 0), "%d", x);
	DrawFormatString(0, 50, GetColor(255, 0, 0), "%d", y);
}

bool Player::damage(void)
{
	return false;
}

void Player::draw_interface(int)
{
}

void Player::move()
{
	//固定数値ではなくvelocityを入れる
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 2;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 2;
	}
	if (CheckHitKey(KEY_INPUT_UP)) {
		y -= 2;
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		y += 2;
	}
	check_foot();
}

void Player::check_foot()
{
	//今の画像の大きさが30*30のため
	Point foot{ x,y + 30,30,1 };
	DrawBox(foot.x, foot.y, foot.x + foot.w, foot.y + foot.h, GetColor(0, 255, 0), TRUE);
	//仮の当たり判定
	//MapのGet_bottomを呼ぶ?
	if (gts->map->get_bottom(foot) != 0) {
		foot_status = true;
	}
	else {
		foot_status = false;
	}
}

bool Player::knockback(int)
{
	return false;
}



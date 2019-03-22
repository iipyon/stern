#include "Player.h"
#include"Point.h"
#include"CoreTask.h"
#include"Keyboard.h"

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
	DrawRotaGraph2(x, 0, 0, 0, 1, st, graph, FALSE);
}

void Player::StarManager::update(double ang, int x_)
{
	draw(ang, x_);
	if (CheckHitKey(KEY_INPUT_Z)){
		ct->gts->normalstar->lead();//リストを先頭に戻す
		//ノーマルスター
		std::shared_ptr<NormalStar> new_instance = std::make_shared<NormalStar>(0, 0, 0, ct->gts->player->x, ct->gts->player->get_angle());
		ct->gts->normalstar->create(new_instance);//新規オブジェクトをリスト管理対象とする
		ct->gts->normalstar->get()->update();
	}
	
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
	starmanager = std::make_unique<StarManager>();
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
	//Keyboardに変更する
	/*if (CheckHitKey(KEY_INPUT_RIGHT)) {
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
	}*/
	//左右移動--------------------------------------------
	if (ct->keyboard->key_press(KEY_INPUT_RIGHT)) {
		velocityX = 2;
		x += velocityX;
	}
	if (ct->keyboard->key_press(KEY_INPUT_LEFT)) {
		velocityX = 2;
		x -= velocityX;
	}
	//---------------------------------------------------
	//ダッシュ
	if (ct->keyboard->key_press(KEY_INPUT_Z) &&
			ct->keyboard->key_press(KEY_INPUT_LEFT) {

	}
	//ジャンプ
	if (ct->keyboard->key_press(KEY_INPUT_X)) {
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
	if (ct->gts->map->get_bottom(foot) != 0) {
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



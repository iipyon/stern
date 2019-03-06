#include "Player.h"

//----------------------------------
//ÉvÉåÉCÉÑÅ[
//----------------------------------


void Player::PlayerInterface::Draw(int st)
{
}

void Player::Cursor::Draw(double st)
{
}

void Player::update()
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		x += 1;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		x -= 1;
	}
	draw();

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
}

void Player::check_foot()
{
}

bool Player::knockback(int)
{
	return false;
}

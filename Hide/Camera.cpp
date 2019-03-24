#include "Camera.h"
#include "CoreTask.h"


void Camera::update()
{
	//X,Y座標を取り続ける
	ct->gts->player->get_point();
	
	//各キーに応じてmoveの処理を呼ぶ
	if (ct->keyboard->key_press(KEY_INPUT_W)) {};//Wキーが押され続けたらmoveの上処理
	if (ct->keyboard->key_press(KEY_INPUT_A)) {};//Wキーが押され続けたらmoveの左処理
	if (ct->keyboard->key_press(KEY_INPUT_D)) {};//Wキーが押され続けたらmoveの右処理
	if (ct->keyboard->key_press(KEY_INPUT_S)) {};//Wキーが押され続けたらmoveの下処理
}

void Camera::move(int, int)
{
}

bool Camera::get()
{
	return false;
}

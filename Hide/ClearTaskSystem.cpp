#include "ClearTaskSystem.h"
#include "CoreTask.h"

ClearTaskSystem::ClearTaskSystem()
{
	init();
}

void ClearTaskSystem::init()
{
	timer = 120;	//標準値(仮に2秒
}

void ClearTaskSystem::update()
{
	if (timer-- < 0) ct->scene = Scene::title;	//タイトル(？)に戻る
	draw();
}

void ClearTaskSystem::draw() {
	//ここでクリア画面を描画する
	//要件が不明なので仕様に基づく記述不可
	DrawFormatString(100, 100, GetColor(0, 255, 0), "ClearTaskSystem::draw()");
}
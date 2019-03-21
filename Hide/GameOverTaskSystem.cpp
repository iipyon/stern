#include "CoreTask.h"
#include "GameOverTaskSystem.h"

GameOverTaskSystem::GameOverTaskSystem()
{
	init();		//複数回ゲームオーバーになる可能性があるためコンストラクタではなく初期化に別の関数を用いる。
}

void GameOverTaskSystem::init()
{
	timer = 120;
}

void GameOverTaskSystem::update()
{
	if (timer-- < 0) ct->scene = Scene::title;
	draw();
}

void GameOverTaskSystem::draw()
{
	//実装不可
	DrawFormatString(100, 100, GetColor(0, 0, 255), "GameOverTaskSystem::draw()");
}
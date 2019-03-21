#include"StageselectChara.h"
#include"CoreTask.h"
#include"Dxlib.h"

StageSelectChara::StageSelectChara()
{
	point.x = 30;
	point.y = 100;
	graph = LoadGraph("img/stageselect/chara.png");
	velocityX = 0;
}

void StageSelectChara::update(int& stage_)
{
	select_stage(stage_);
	move();
	draw();
	DrawFormatString(0, 50, GetColor(255, 0, 0), "x座標 : %d", point.x);
}

void StageSelectChara::draw()
{
	DrawGraph(point.x, point.y, graph, TRUE);
}

void StageSelectChara::select_stage(int& stage_)
{
	if (ct->keyboard->key_down(KEY_INPUT_RIGHT)&& stage_ < 4 && velocityX == 0) {
		velocityX = 18;
		stage_++;//ステージセレクトタスクの方のステージ番号は加算されていない
	}
	if (ct->keyboard->key_down(KEY_INPUT_LEFT)&& stage_ > 1 && velocityX == 0) {
		velocityX = -18;
		stage_--;
	}
	if(velocityX > 0) velocityX--;
	if(velocityX < 0) velocityX++;
}

void StageSelectChara::move()
{
	point.x += (int)velocityX;
}

int StageSelectChara::get_velocity()
{
	return (int)velocityX;
}

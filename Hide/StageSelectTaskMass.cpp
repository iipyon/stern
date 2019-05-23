#include "StageSelectTaskMass.h"
#include"DxLib.h"
#include"System.h"

StageSelectTaskMass::StageSelectTaskMass()
{
	mass = 4;
	//x = System::width / 4;//画像を描画する始点(4マスの中の一番左のマスの左座標)
	y = 200;
	graph = LoadGraph("img/stageselect/mass.png");
	for (int i = 0; i < mass; i++) {
		mass_x[i] = (System::width / 10) + get_massline() * i;
	}
}

void StageSelectTaskMass::update()
{
	draw();
}

void StageSelectTaskMass::draw()
{
	//4マス描画
	for (int i = 0;i < mass;i++) {
		DrawGraph(mass_x[i], y, graph, TRUE);
	}
}

int * StageSelectTaskMass::get_masspos()
{
	return mass_x;
}

int StageSelectTaskMass::get_massX(int mass_num)
{
	return mass_x[mass_num];
}

int StageSelectTaskMass::get_massY()
{
	return y;
}

int StageSelectTaskMass::get_massline()
{
	return System::width / 4;
}



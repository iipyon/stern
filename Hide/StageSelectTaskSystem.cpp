#include "StageSelectTaskSystem.h"
#include"CoreTask.h"

StageSelectTaskSystem::StageSelectTaskSystem()
{
	stage = 1;
	for (int i = 0; i < sizeof(state); ++i) {
		state[i] = false;
	}
	backgraph = LoadGraph("img/stageselect/back.png");
}

void StageSelectTaskSystem::update()
{
	
	if(ct->keyboard->key_down(KEY_INPUT_Z)){
		switch (stage)
		{
		case 1:
			ct->gts->map->init((char*)"img/data.txt", (char*)"img/chip.png");
			break;
		case 2:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		case 3:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		case 4:
			ct->gts->map->init((char*)"", (char*)"");
			break;
		default:
			break;
		}
		ct->scene = Scene::game;//ゲームシーンに遷移
	}
	draw();
	DrawFormatString(0, 0, GetColor(0, 255, 0), "現在ステージ %d を選択中", stage);
}

void StageSelectTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}

int StageSelectTaskSystem::get_stage()
{
	return stage;
}

void StageSelectTaskSystem::clear(int num_)
{
	state[num_] = true;
}

#include "StageselectTaskTextBox.h"
#include"DxLib.h"

StageSelectTextBox::StageSelectTextBox()
{
	boxgraph = LoadGraph("img/stageselect/textbox.png");
}

void StageSelectTextBox::update(int stage_)
{
	draw(stage_);
}

void StageSelectTextBox::draw(int stage_)
{
	DrawGraph(0, 300, boxgraph, TRUE);
	DrawFormatString(250, 350, GetColor(0, 0, 0), " Stage %d", stage_);
}

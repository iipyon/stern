#include "StageselectTaskTextBox.h"
#include"DxLib.h"
#include"System.h"

StageSelectTextBox::StageSelectTextBox()
{
	boxgraph = LoadGraph("img/stageselect/textbox.png");
	start_x = 0;
	start_y = System::height - 300;//任意の描画スタート位置
	end_x = System::width;
	end_y = System::height;
}

void StageSelectTextBox::update()
{
	draw();
}

void StageSelectTextBox::draw()
{
	DrawExtendGraph(start_x, start_y, end_x, end_y,boxgraph,FALSE);
}

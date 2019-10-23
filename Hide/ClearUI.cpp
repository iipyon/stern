#include "ClearUI.h"
#include"DxLib.h"
#include"System.h"
#include"ClearConfig.h"

ClearUI::ClearUI()
{
	text.str = "Push to Z Key";
	text.color = GetColor(255, 0, 0);
	text.text_width = get_width(text);
	text.x = get_left(text) / 2;
	text.y = System::height / 2;

	text.font = CreateFontToHandle(NULL, 16, 3);
}

void ClearUI::init()
{
	b_state = Reduce;
	ui_brend = Brend_Max;
	deg_flag = false;
}

void ClearUI::update()
{
	if (b_state == Reduce) {
		ui_brend--;
		if (ui_brend < Brend_Min) {
			b_state = Increase;//増加
		}
	}
	if (b_state == Increase) {
		ui_brend++;
		if (ui_brend > Brend_Max) {
			b_state = Reduce;//減少
		}
	}
}

void ClearUI::draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ui_brend);		//ブレンドモードをαに設定
	DrawStringToHandle(text.x, text.y, text.str, text.color, text.font);
	//update_txt(text);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	
}

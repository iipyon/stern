#include "TitleUI.h"
#include"DxLib.h"

TitleUI::TitleUI()
{
	text[0].str = "Game Start";
	text[1].str = "Exit";
	for (int i = 0; i < 2; ++i) {
		text[i].color = GetColor(0, 0, 0);
		text[i].text_width = get_width(text[i]);
		text[i].x = get_left(text[i]) / 2;
		text[i].y = 340 + 50 * i;
	}
	button = Button::start;
	deg_flag = false;
	ui_brend = 160;
}

void TitleUI::init()
{
	button = Button::start;
	deg_flag = false;
	ui_brend = 160;
}

void TitleUI::update()
{
	//セレクターを点滅させるための処理--------------
	if (deg_flag) {
		ui_brend -= 2;
		if (ui_brend < 0) {
			deg_flag = false;
		}
	}
	else {
		ui_brend += 2;
		if (ui_brend >= 160) {
			deg_flag = true;
		}
	}
	//-------------------------------------------------
	for (int i = 0; i < 2; ++i) {
		update_txt(text[i]);
	}
	//-------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ui_brend);		//ブレンドモードをαに設定
	//セレクターの描画
	draw_selecter();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
}

void TitleUI::change_Select(Button b_)
{
	button = b_;
}

void TitleUI::draw_selecter()
{
	switch (button) {
	case Button::start:
		// + 16はフォントサイズ
		DrawBox(text[0].x - 1, text[0].y - 1, text[0].x + text[0].text_width + 1, text[0].y + 16 + 1, GetColor(255, 255, 255), TRUE);
		break;
	case Button::exit:
		DrawBox(text[1].x, text[1].y, text[1].x + text[1].text_width, text[1].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	}
}

Button TitleUI::getter()
{
	return button;
}

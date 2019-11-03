#include "PauseTaskUI.h"
#include"DxLib.h"
#include"System.h"

PauseUI::PauseUI()
{
	text[0].str = "ゲームに戻る";
	text[1].str = "ステージセレクトに戻る";
	text[2].str = "ゲーム終了";
	for (int i = 0; i < 3; ++i) {
		text[i].color = GetColor(255, 255, 0);
		text[i].text_width = get_width(text[i]);
		text[i].x = get_left(text[i]) / 2;
		text[i].y = 340 + 50 * i;
	}
	pausebutton = PauseButton::returngame;
	ui_brend = 160;
	deg_flag = false;

}

void PauseUI::update()
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
	//テキストの描画
	for (int i = 0; i < 3; ++i) {
		update_txt(text[i]);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ui_brend);		//ブレンドモードをαに設定
	//セレクターの描画
	draw_selecter();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
}

void PauseUI::change_Select(PauseButton pb_)
{
	pausebutton = pb_;
}

PauseButton PauseUI::getter()
{
	return pausebutton;
}

void PauseUI::draw_selecter()
{
	switch (pausebutton) {
	case PauseButton::returngame:
		// + 16はフォントサイズ
		DrawBox(text[0].x - 1, text[0].y - 1, text[0].x + text[0].text_width + 1, text[0].y + 16 + 1, GetColor(255, 255, 255), TRUE);
		break;
	case PauseButton::backssts:
		DrawBox(text[1].x, text[1].y, text[1].x + text[1].text_width, text[1].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	case PauseButton::exit:
		DrawBox(text[2].x, text[2].y, text[2].x + text[2].text_width, text[2].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	}
}
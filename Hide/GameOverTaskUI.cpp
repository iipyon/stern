#include "GameOverTaskUI.h"
#include"DxLib.h"

GameOverUI::GameOverUI()
{
	text[0].str = "コンテニュー";
	text[1].str = "タイトル";
	for (int i = 0; i < 2; ++i) {
		text[i].color = GetColor(255, 255,0);
		text[i].text_width = get_width(text[i]);
		text[i].x = get_left(text[i]) / 2;
		text[i].y = 340 + 50 * i;
	}
	select = SelectMode::Continue;
	deg_flag = true;
	ui_brend = 160;
}

void GameOverUI::update()
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
	//テキストの描画
	for (int i = 0; i < 2; ++i) {
		update_txt(text[i]);
	}
	//------------------------------------------------
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, ui_brend);		//ブレンドモードをαに設定
	//セレクターの描画
	draw_selecter();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ


}

void GameOverUI::draw_selecter()
{
	switch (select) {
	case SelectMode::Continue:
		// + 16はフォントサイズ
		DrawBox(text[0].x - 1, text[0].y - 1, text[0].x + text[0].text_width + 1, text[0].y + 16 + 1, GetColor(255, 255, 255), TRUE);
		break;
	case SelectMode::Title:
		DrawBox(text[1].x, text[1].y, text[1].x + text[1].text_width, text[1].y + 16, GetColor(255, 255, 255), TRUE);
		break;
	}
}

void GameOverUI::change_Select(SelectMode sm_)
{
	select = sm_;
}

SelectMode GameOverUI::getter()
{
	return select;
}

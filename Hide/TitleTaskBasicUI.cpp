#include "TitleTaskBasicUI.h"
#include"DxLib.h"

TitleTaskBasicUI::TitleTaskBasicUI()
{
	x = 0;
	y = 0;
	strwidth = 0;
}
//コンストラクタで呼ぶ----------------------------------------------
void TitleTaskBasicUI::get_width(const char* str)
{
	//常に文字幅をとる必要がないためコンストラクタで記述
	strwidth = (int)(GetDrawStringWidth(str, strlen(str)));
}
//以下Updateで呼ぶ---------------------------------------------------
void TitleTaskBasicUI::update_txt(const char* str)
{
	draw_txt(str);
}
void TitleTaskBasicUI::draw_txt(const char* str)
{
	//         300は画面サイズの半分
	DrawString(300 - strwidth / 2, y, str, GetColor(0, 0, 0));
}
int TitleTaskBasicUI::get_lextx()
{
	//文字の始点を返す
	return 300 - strwidth / 2;
}
int TitleTaskBasicUI::get_y()
{
	return y;
}
//-------------------------------------------------------------------

#include "BasicUI.h"
#include"DxLib.h"
#include"System.h"

BasicUI::BasicUI()
{
}
//コンストラクタで呼ぶ----------------------------------------------
int BasicUI::get_width(Text _txt)
{
	return (int)(GetDrawStringWidth(_txt.str, strlen(_txt.str)));
}
//以下Updateで呼ぶ---------------------------------------------------
void BasicUI::update_txt(Text _txt)
{
	draw_txt(_txt);
}
void BasicUI::draw_txt(Text _txt)
{
	//         300は画面サイズの半分
	DrawString(_txt.x, _txt.y, _txt.str, _txt.color);
}
int BasicUI::get_left(Text _txt)
{
	//文字の始点を返す(画面半分から文字列の半分を引いた値)
	return System::width - _txt.text_width;
}
int BasicUI::get_y(Text _txt)
{
	return _txt.y;
}
//-------------------------------------------------------------------

#include "BasicUI.h"
#include"DxLib.h"

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
	DrawString(_txt.x, _txt.y, _txt.str, GetColor(0, 0, 0));
}
int BasicUI::get_lextx(Text _txt)
{
	//文字の始点を返す(画面半分から文字列の半分を引いた値)
	return 300 - _txt.text_width / 2;
}
int BasicUI::get_y(Text _txt)
{
	return _txt.y;
}
//-------------------------------------------------------------------

#include "Mouse.h"

bool Mouse::work;
bool Mouse::previous;
bool Mouse::current;


void Mouse::initialize()
{
	work = false;
	previous = false;
	current = false;
}

void Mouse::update()
{
	//領域を入れ替える
	work = current;
	current = previous;
	previous = work;

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != false)//左ボタンを押しているかの判定
	{
		current = true;
	}
	else
	{
		current = false;
	}
}

bool Mouse::Mouse_down()
{

	return current == true && previous == false;
}

bool Mouse::Mouse_up()
{
	return current == false && previous==true;
}

bool Mouse::Mouse_press()
{
	return current== true;
}

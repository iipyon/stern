#include "Keyboard.h"

void Keyboard::update()
{
	for(int i=0;i<256;++i)
	previous[i] = current[i];
	char Buf[256];
	for (int i = 0; i < 256; ++i)
	current[i] = GetHitKeyStateAll(Buf);
	
}

bool Keyboard::key_down(int k_)
{

	return current[k_] == 1&& previous[k_] == 0;
}

bool Keyboard::key_up(int k_)
{
	return current[k_] == 0&& previous[k_]==1;
}

bool Keyboard::key_press(int k_)
{
	return current[k_]==1;
}

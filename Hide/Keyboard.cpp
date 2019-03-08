#include "Keyboard.h"

void Keyboard::update()
{
	*previous=*current;
	char Buf[256];
	GetHitKeyStateAll(Buf);
	*current = *Buf;
	
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

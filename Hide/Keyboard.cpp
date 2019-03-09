#include "Keyboard.h"

Keyboard::Keyboard()
{
	current = new char[KEY_BOARD_BUF_SIZE];
	previous = new char[KEY_BOARD_BUF_SIZE];
}

Keyboard::~Keyboard()
{
	delete[] current;
	delete[] previous;
}

void Keyboard::update()
{
	// —Ìˆæ‚ð“ü‚ê‘Ö‚¦‚é
	work = current;
	current = previous;
	previous = work;

	GetHitKeyStateAll(current);	
}

bool Keyboard::key_down(int k_)
{

	return *(current+k_) == 1 && *(previous+k_) == 0;
}

bool Keyboard::key_up(int k_)
{
	return *(current+k_) == 0&& *(previous+k_)==1;
}

bool Keyboard::key_press(int k_)
{
	return *(current + k_)==1;
}

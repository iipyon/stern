﻿#include "Keyboard.h"

char* Keyboard::current;
char* Keyboard::previous;
char* Keyboard::work;

void Keyboard::initialize()
{
	current = new char[KEY_BOARD_BUF_SIZE];
	previous = new char[KEY_BOARD_BUF_SIZE];
}

void Keyboard::finalize()
{
	delete[] current;
	delete[] previous;
}

void Keyboard::update()
{
	//領域を入れ替える
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

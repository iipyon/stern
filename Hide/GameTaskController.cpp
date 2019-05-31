#include "GameTaskController.h"

void GameOver::set_gameover(bool flag)
{
	gameover = flag;
}

bool GameOver::get_gameover_flag()
{
	return gameover;
}

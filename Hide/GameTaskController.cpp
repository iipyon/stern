#include "GameTaskController.h"

void GameOverController::set_gameover(bool flag)
{
	gameover = flag;
}

bool GameOverController::get_gameover_flag()
{
	return gameover;
}

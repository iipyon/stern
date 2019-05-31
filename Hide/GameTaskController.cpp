#include "GameTaskController.h"
bool GameOverController::get_gameover_flag() {
	return gameover;
}

void GameOverController::set_gameover(bool flag) {
	gameover = flag;
}
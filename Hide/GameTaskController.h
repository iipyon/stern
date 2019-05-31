#pragma once

namespace GameOverController {
	namespace {
		bool gameover;
	}
	void set_gameover(bool flag) {
		GameOverController::gameover = flag;
	}
	bool get_gameover_flag() {
		return GameOverController::gameover;
	}
}
#pragma once

namespace GameOverController {
	static bool gameover;
}

namespace{
	void set_gameover(bool flag) {
		GameOverController::gameover = flag;
	}
	//getter
	bool get_gameover_flag() {
		return GameOverController::gameover;
	}
}
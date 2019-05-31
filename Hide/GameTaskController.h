#pragma once

namespace GameOverController {
	namespace {
		bool gameover;
	}
	void set_gameover(bool flag) {
		gameover = flag;
	}
	bool get_gameover_flag() {
		return gameover;
	}
}
#pragma once
namespace {
	//ファイル内でのみ有効
	bool gameover;
}

namespace GameOverController {

	void set_gameover(bool flag);
	bool get_gameover_flag();
}
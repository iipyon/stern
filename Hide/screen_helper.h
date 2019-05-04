#pragma once
#include"DxLib.h"

namespace ScreenFunc {

	static bool FeedOut(bool& deg_flag_,int& feedcnt) {
		feedcnt -= 10;
		SetDrawBright(feedcnt, feedcnt, feedcnt);
		if (feedcnt <= 0) {
			feedcnt = 0;
			deg_flag_ = false;
			SetDrawBright(feedcnt, feedcnt, feedcnt);
			return true;
		}
		return false;
	}

	static void FeedIn(bool deg_flag_, int& feedcnt) {
		if (!deg_flag_) {
			feedcnt += 10;
			if (feedcnt >= 255) {
				feedcnt = 255;
			}
			SetDrawBright(feedcnt, feedcnt, feedcnt);
		}
	}
}
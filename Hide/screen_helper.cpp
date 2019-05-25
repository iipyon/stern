#include "screen_helper.h"
#include"screenhelper_config.h"
#include"DxLib.h"
#include"System.h"

int ScreenFunc::brendcnt;

void ScreenFunc::initialize()
{
	//フェードアウト、イン用の画像をロード
	ScreenHelperGraph::black_graph = LoadGraph("./img/screen/black_screen.png");
	ScreenHelperGraph::white_graph = LoadGraph("./img/screen/white_screen.png");
	brendcnt = 0;//初期は透明にしておく
}

bool ScreenFunc::FeedOut(int screen_graph)
{
	bool check = false;
	//画像を濃くしていく（真っ黒、真っ白になる）
	if (check_brend_max()) {//完全に真っ黒、真っ白になったら
		check = true;
	}
	else {//255未満なら
		brendcnt += FeedSpeed;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, brendcnt);		//ブレンドモードをαに設定
	DrawExtendGraph(0, 0, System::width, System::height, screen_graph, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ

	return check;
}

void ScreenFunc::FeedIn(int screen_graph)
{
	//画像を薄くしていく（透明になる）
	if (!check_brend_min()) {//0超過なら
		brendcnt -= FeedSpeed;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, brendcnt);		//ブレンドモードをαに設定
	DrawExtendGraph(0, 0, System::width, System::height, screen_graph, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
}

bool ScreenFunc::check_brend_max()
{
	return brendcnt >= 255;//255より大きいならtrue
}

bool ScreenFunc::check_brend_min()
{
	return brendcnt <= 0;//0より小さいならtrue
}

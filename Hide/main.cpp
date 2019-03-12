#include "DxLib.h"
#include"CoreTask.h"
#include"Player.h"

//----------------------------------
//クラス作成の際、関数（メソッド）はpublic
//変数はprivateで入れてください(W・T)
//----------------------------------

CoreTask *ct;

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードの設定
	SetGraphMode(600, 600, 32);//ウィンドウのサイズを決める
	ChangeWindowMode(TRUE);// ウィンドウモード変更

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return -1; };
	
	ct = new CoreTask;

	//-------------------------------------------------
	SetDrawScreen(DX_SCREEN_BACK);//裏画面設定

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新＆メッセージ処理&画面殺害
		
		ct->gts->update();

	}
	delete ct;
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}

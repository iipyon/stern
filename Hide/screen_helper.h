#pragma once
#include"DxLib.h"

class ScreenFunc {
private:
	//フィールド
	static int brendcnt;//画像の透明度を示す
	//ブレンドカウントのチェックメソッド
	static bool check_brend_max();//255になったらtrueを返す
	static bool check_brend_min();//0になったらtrueを返す
public:
	static void initialize();//画像のロードなど

	//どういうときに呼ぶかなどはシーンが決める
	static bool FeedOut(int screen_graph);//暗くする処理(true : シーン切り替えを行う, false : 続行など)
	static void FeedIn(int screen_graph);//明るくする処理

};
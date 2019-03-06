#pragma once

//----------------------------------
//基本となるクラス
//----------------------------------

class BasicObject {
public:
	//最低限の初期化
	BasicObject() {
		velocity = 0;
		x = 0;
		y = 0;
		height = 0;
		width = 0;
	}

	//メソッド（関数）
	virtual void update();
	void get_point();

protected:
	//座標
	int x;
	int y;
	//幅・高さ
	int height;
	int width;
	//移動量
	float velocity;
};
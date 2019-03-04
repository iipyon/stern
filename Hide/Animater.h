#pragma once
#include"BasicObject.h"

class Animater : public BasicObject {
public:
	Animater() {
		cnt = 0;
		limit = 0;
		//state st;
	}
	//アニメーションを切り替える
	void Switch_anime();
protected:
	int cnt;//何フレーム後に画像を切り替えるか
	int limit;//最大コマ数

	enum class state{

	};

};
#pragma once
#include"BasicObject.h"

//----------------------------------
//スイッチのベース
//----------------------------------

class BasicSwitch : public BasicObject {
public:
	BasicSwitch(Point);
	//メソッド
	void Switch();
protected:
	//変数
	bool status;//押されているかの判定?
};
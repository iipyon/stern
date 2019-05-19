#pragma once
//以下最適化済みヘッダー
#include"Point.h"
#include "BasicObject.h"

bool CheckHit(Point attack_, Point defense_);
bool CheckHit(BasicObject&, BasicObject&);
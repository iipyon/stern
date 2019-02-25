#pragma once
#include"Enemy.h"
#include"Star.h"

//------------------------------
//ì¬
//------------------------------

class Controller {
public:
	void Create(Enemy *enemy);
	void Create(Star *star);
};
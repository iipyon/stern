#pragma once
#include"Enemy.h"
#include"Star.h"

//------------------------------
//�쐬
//------------------------------

class Controller {
public:
	void Create(Enemy *enemy);
	void Create(Star *star);
};
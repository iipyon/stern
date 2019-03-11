#pragma once
#include "Player.h"
#include"Map.h"
#include<memory>
#include"BasicList.h"
#include"NormalStar.h"

class GameTaskSystem
{
private:
protected:
public:
	GameTaskSystem();
	~GameTaskSystem();
	void update();
	//~GameTaskSystem();
	std::unique_ptr<Player> player = std::make_unique<Player>();
	std::unique_ptr<Map> map = std::make_unique<Map>((char*)("img/data.txt"));
	std::shared_ptr<BasicList<NormalStar>> normalstar = std::make_shared<BasicList<NormalStar>>();
};

extern GameTaskSystem *gts;


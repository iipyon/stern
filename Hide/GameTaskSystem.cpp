#include "GameTaskSystem.h"


GameTaskSystem::GameTaskSystem()
{
	normalstar = std::make_shared<BasicList<NormalStar>>();
	normalstar->lead();//リストを先頭に戻す
}

GameTaskSystem::~GameTaskSystem()
{
}

void GameTaskSystem::update()
{
	//ノーマルスター
	std::shared_ptr<NormalStar> new_instance = std::make_shared<NormalStar>(0,0,0);
	normalstar->create(new_instance);//新規オブジェクトをリスト管理対象とする
	
	normalstar->get()->update();

	gts->map->update();
	gts->player->update();
}

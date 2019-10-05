#pragma once
#include"json11.hpp"
#include"Spawn.h"
#include<memory>
#include<vector>
#include"Item.h"

class SpawnItem : public Spawn{
public:
	SpawnItem(std::string path_, std::shared_ptr<std::vector<std::shared_ptr<Item>>> _item);
	void create(std::string stg,int posx) override;
private:
	std::shared_ptr<std::vector<std::shared_ptr<Item>>> item;
};
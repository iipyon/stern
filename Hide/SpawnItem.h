#pragma once
#include"json11.hpp"
#include <iostream>
#include<memory>

class SpawnItem {
public:
	SpawnItem();
	void create(std::string stg);
private:
	json11::Json item_data;
};
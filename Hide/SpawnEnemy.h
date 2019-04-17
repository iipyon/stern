#pragma once
#include"Spawn.h"
#include<memory>
#include<vector>
#include"Enemy.h"

class SpawnEnemy : public Spawn {
public:
	SpawnEnemy(std::string path_, std::shared_ptr<std::vector<std::shared_ptr<Enemy>>>);
	void create(std::string stg) override;
private:
	std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> enemys;
};
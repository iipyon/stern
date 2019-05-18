#include "model.h"

std::shared_ptr<Player> mdl::player;
std::unique_ptr<Goal> mdl::goal;
std::vector<NormalStar> mdl::normalstar;
std::vector<GravityStar> mdl::gravityStar;
std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> mdl::enemys;
std::shared_ptr<std::vector<std::shared_ptr<Enemy>>> mdl::enemy_transaction;
std::shared_ptr<std::vector<std::shared_ptr<Item>>> mdl::item;

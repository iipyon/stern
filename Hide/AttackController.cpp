#include "AttackController.h" 
//以下最適化済みヘッダー
#include "Model.h"

//以下GameTaskSystemクラスから切り離し予定
void AttackController::attack_player_enemy()
{
	for (auto itr = mdl::enemys->begin(); itr != mdl::enemys->end(); itr++) {
		if (CheckHit(mdl::player->get_point(), (*itr)->get_point())) {
			if (!(mdl::player->damage())) {
				mdl::enemys->erase(itr);
				break;
			}

		}
	}
}

void AttackController::attack_player_item()
{
	for (auto itr = mdl::item->begin(); itr != mdl::item->end(); itr++) {
		if (CheckHit(mdl::player->get_point(), (*itr)->get_point())) {
			break;
		}
	}
}

void AttackController::attack_star_enemy()
{
	bool deleted = false;
	for (auto enemy_itr = mdl::enemys->begin(); enemy_itr != mdl::enemys->end(); enemy_itr++) {
		for (auto star_itr = mdl::normalstar.begin(); star_itr != mdl::normalstar.end(); star_itr++) {
			if (CheckHit((*enemy_itr)->get_point(), (*star_itr).get_point())) {
				mdl::enemys->erase(enemy_itr);
				mdl::normalstar.erase(star_itr);
				deleted = true;
				break;
			}

		}
		if (deleted == true)break;
	}
}
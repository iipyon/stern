#pragma once
#include "CoreTask.h"

//以下GameTaskSystemクラスから切り離し予定
namespace AttackController {
	void attack_player_enemy();
	void attack_player_item();
	void attack_star_enemy();
}
#include "PlayerController.h"
#include "PlayerConfig.h"
#include "CoreTask.h"	//modelに移行する

void PlayerController::initialize() {

	ct->gts->player->set_invincible(0);

}
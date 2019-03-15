#pragma once
#include<memory>
#include"GameTaskSystem.h"
#include"TitleTaskSystem.h"
#include"Keyboard.h"
#include "ClearTaskSystem.h"

enum class Scene {
	title,
	stageselect,
	game,
	gameover,
	clear
};

class CoreTask {
private:
public:
	Scene scene;//‚Ç‚ÌƒV[ƒ“‚©‚ç‚Å‚à•Ï‚¦‚ç‚ê‚é‚æ‚¤‚É

	CoreTask();
	void update();
	std::unique_ptr<GameTaskSystem> gts;
	std::unique_ptr<TitleTaskSystem> tts;
	std::unique_ptr<Keyboard> keyboard;
	std::unique_ptr<ClearTaskSystem> cts;
};

extern CoreTask *ct;
#pragma once
#include<memory>
#include"GameTaskSystem.h"
#include"TitleTaskSystem.h"
#include"StageSelectTaskSystem.h"
#include"Keyboard.h"
#include "ClearTaskSystem.h"
#include "GraphicResource.h"
#include "GameOverTaskSystem.h"
#include"Audio.h"
#include"PauseTaskSystem.h"

enum class Scene {
	title,
	stageselect,
	game,
	gameover,
	clear,
	pause
};

class CoreTask {
private:
public:
	Scene scene;//どのシーンからでも変えられるように

	CoreTask();
	void update();
	void init();
	void finalize();
	std::shared_ptr<GameTaskSystem> gts;
	std::shared_ptr<TitleTaskSystem> tts;
	std::shared_ptr<StageSelectTaskSystem> ssts;
	std::shared_ptr<ClearTaskSystem> cts;
	std::shared_ptr<GameOverTaskSystem> gots;
	std::shared_ptr<PauseTask> pts;
};

extern CoreTask *ct;
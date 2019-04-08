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
	Scene scene;//どのシーンからでも変えられるように

	CoreTask();
	void update();
	std::unique_ptr<GameTaskSystem> gts;
	std::unique_ptr<TitleTaskSystem> tts;
	std::unique_ptr<StageSelectTaskSystem> ssts;
	std::unique_ptr<Keyboard> keyboard;
	std::unique_ptr<ClearTaskSystem> cts;
	std::unique_ptr<GraphicResource> graph;
	std::unique_ptr<GameOverTaskSystem> gots;
	std::unique_ptr<Audio> audio;
};

extern CoreTask *ct;
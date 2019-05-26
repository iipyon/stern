#include "ClearTaskSystem.h"
#include "CoreTask.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include "Scene.h"
#include "Keyboard.h"
#include "Audio.h"

ClearTaskSystem::ClearTaskSystem()
{
	init();
}

void ClearTaskSystem::init()
{
	feed_flag = false;
}

void ClearTaskSystem::init_member()
{
	feed_flag = false;
}

void ClearTaskSystem::update()
{
	if (Keyboard::key_down(KEY_INPUT_Z) && !feed_flag) {
		feed_flag = true;
		Audio::play("decision");
	}
	draw();
	if (feed_flag) {
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			Scene::set_scene(SceneType::stageselect);
		}
	}
	else {
		ScreenFunc::FeedIn(ScreenHelperGraph::white_graph);
	}
}

void ClearTaskSystem::draw() {
	DrawFormatString(100, 100, GetColor(0, 255, 0), "Push Z key");
}
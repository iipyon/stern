#include "ClearTaskSystem.h"
#include "CoreTask.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include "Scene.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Audio.h"
#include"System.h"

bool ClearTaskSystem::feed_flag;
int ClearTaskSystem::backgraph;
std::unique_ptr<ClearUI> ClearTaskSystem::c_ui;


void ClearTaskSystem::init()
{
	backgraph = LoadGraph("./img/clear/clear.png", FALSE);
	c_ui = std::make_unique<ClearUI>();
	c_ui->init();
	feed_flag = false;
}

void ClearTaskSystem::init_member()
{
	c_ui->init();
	feed_flag = false;
}

void ClearTaskSystem::update()
{
	if (Keyboard::key_down(KEY_INPUT_Z) && !feed_flag) {
		feed_flag = true;
		Audio::play("decision");
	}
	c_ui->update();
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
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	c_ui->draw();
}
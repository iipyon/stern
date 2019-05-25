#include "StageSelectTaskSystem.h"
#include"Screen_helper.h"
#include"CoreTask.h"
#include"System.h"
#include"screenhelper_config.h"

//静的定義----------------------------------------------------------------
int StageSelectTaskSystem::stage;//ステージ識別番号
bool StageSelectTaskSystem::state[4];//クリアフラグ（ステージ総数によって変える）

bool StageSelectTaskSystem::feed_flag;

int StageSelectTaskSystem::backgraph;//背景画像
std::unique_ptr<StageSelectTaskMass> StageSelectTaskSystem::mass;
std::unique_ptr<StageSelectChara> StageSelectTaskSystem::chara;
std::unique_ptr<StageSelectTextBox> StageSelectTaskSystem::txtbox;

std::unique_ptr<SpawnEnemy> StageSelectTaskSystem::spawnenemy;//敵の生成
std::unique_ptr<SpawnItem> StageSelectTaskSystem::spawnitem;

//------------------------------------------------------------------------

StageSelectTaskSystem::StageSelectTaskSystem()
{
	mass = std::make_unique<StageSelectTaskMass>();
	class Point point = { mass->get_massX(0),200,30,30 };
	chara = std::make_unique<StageSelectChara>(point);
	txtbox = std::make_unique<StageSelectTextBox>();

	spawnenemy = std::make_unique<SpawnEnemy>("img/epath.json", ct->gts->enemys);
	spawnitem = std::make_unique<SpawnItem>("img/item.json", ct->gts->item);

	feed_flag = false;

	stage = 1;
	for (int i = 0; i < sizeof(state); ++i) {
		state[i] = false;
	}
	backgraph = LoadGraph("img/stageselect/back.png");
}

void StageSelectTaskSystem::init_member()
{
	feed_flag = false;
}

void StageSelectTaskSystem::initialize()
{
	class Point point = { mass->get_massX(0),200,30,30 };
	chara->initialize(point);
	feed_flag = false;
	//stage = 1;
}

void StageSelectTaskSystem::update()
{
	draw();

	mass->update();
	chara->update(stage, feed_flag, mass->get_massline());
	txtbox->update();
	//フェードアウトしていきながらゲームシーンに切り替える
	if (feed_flag) {
		//黒くなっていく
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			switch (stage)
			{
			case 1:
				ct->gts->map->init((char*)"1");
				ct->gts->player->spawn(600, 30, 64, 128);
				ct->gts->goal->spawn(30, 400, 128, 128);
				spawnenemy->create("1");
				spawnitem->create("1");
				break;
			case 2:
				ct->gts->map->init((char*)"2");
				ct->gts->player->spawn(256, 1728, 64, 128);
				ct->gts->goal->spawn( 7488, 1728, 128, 128);
				spawnenemy->create("2");
				spawnitem->create("2");
				break;
			case 3:
				ct->gts->map->init((char*)"");
				break;
			case 4:
				ct->gts->map->init((char*)"");
				break;
			}
			ct->gts->init();
			ct->cts->init();
			ct->change_scene(Scene::game);
		}
	}
	else {
		//黒から明るくなる
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
	}
	//ステージ決定時
	if (Keyboard::key_down(KEY_INPUT_Z) && chara->get_velocity() == 0 && !feed_flag) {
		feed_flag = true;
	}
}

void StageSelectTaskSystem::draw()
{
	DrawExtendGraph(0, 0, System::width, System::height, backgraph, FALSE);
	//DrawGraph(0, 0, backgraph, FALSE);
}

int StageSelectTaskSystem::get_stage()
{
	return stage;
}

void StageSelectTaskSystem::finalize()
{
	DeleteGraph(backgraph);
}

void StageSelectTaskSystem::clear(int num_)
{
	state[num_] = true;
}
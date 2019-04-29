
#include "TitleTaskSystem.h"
#include"CoreTask.h"

TitleTaskSystem::TitleTaskSystem()
{
	title_ui = std::make_unique<TitleUI>();
	selecter = std::make_unique<TitleSelecter>();
	backgraph = LoadGraph("img/title/title.png");
	deg_flag = false;
	feedcnt = 255;
}

void TitleTaskSystem::update()
{
	ScreenFunc::FeedIn(deg_flag, feedcnt);
	if (deg_flag) {
		if(ScreenFunc::FeedOut(deg_flag, feedcnt)){
			switch (selecter->button) {
			case Button::start:
				ct->scene = Scene::stageselect;
				break;
			case Button::exit:
				//exeを閉じる
				break;
			}
		}
	}
	if (Keyboard::key_down(KEY_INPUT_Z) && !deg_flag) {
		deg_flag = true;
		Audio::play("decision");
	}

	draw();
	title_ui->update();
	//カーソルの大きさが40のため余裕をもってあけておく

	selecter->update(title_ui->get_lextx(title_ui->text[0]) - 50,
		title_ui->get_lextx(title_ui->text[1]) - 50,
		deg_flag);

}

void TitleTaskSystem::draw()
{
	DrawGraph(0, 0, backgraph, FALSE);
}

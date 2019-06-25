#include "Demo.h"
#include"DxLib.h"
#include"System.h"
#include"screen_helper.h"
#include"screenhelper_config.h"
#include"Scene.h"
#include"Keyboard.h"
#include"Audio.h"

bool Demo::check_state()
{
	//　もし０が返ってきたら停止中、１なら再生中となります。
	//	因みに動画の再生が終了するか PauseMovieGraph 関数で再生に ポーズを掛けると停止中となります。
	bool check = false;//デフォルトで未再生状態とする
	//再生中なら
	if (GetMovieStateToGraph(movie_handle) == 1){
		check = true;
	}
	//エラーが発生したら例外処理(強制的にストップさせるとここでエラーが発生するためコメントアウト)
	//代替え案があれば至急連絡くれや
	//else if (GetMovieStateToGraph(movie_handle) == -1) throw "mp4 file is not found";
	return check;
}

void Demo::stop_movie()
{
	//再生中なら
	if (GetMovieStateToGraph(movie_handle) == 1) {
		DeleteGraph(movie_handle);
	}
}

void Demo::initialize()
{
	//読み込む
	movie_handle = LoadGraph("./movie/demo.mp4");
	PlayMovieToGraph(movie_handle);
}

void Demo::finalize()
{
	//メモリ削除
	DeleteGraph(movie_handle);
}

void Demo::update()
{
	//再生中
	if (check_state() == 1) {
		ScreenFunc::FeedIn(ScreenHelperGraph::black_graph);
		draw();
		if (Keyboard::key_down(KEY_INPUT_Z)) {
			stop_movie();
		}
	}
	//再生終了
	else {
		if (ScreenFunc::FeedOut(ScreenHelperGraph::black_graph)) {
			Scene::set_scene(SceneType::title);
			finalize();
		}
	}
}

void Demo::draw()
{
	//動画再生
	DrawExtendGraph(0, 0, System::width, System::height, movie_handle, FALSE);
	//Push to Z key追加予定
}

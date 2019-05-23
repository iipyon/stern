#pragma once
#include<memory>
#include"StageselectChara.h"
#include"StageSelectTaskMass.h"
#include"StageselectTaskTextBox.h"
#include"SpawnEnemy.h"//敵生成をステージ選択直後に行うため
#include"SpawnItem.h"

class StageSelectTaskSystem {
protected:
	static int stage;//ステージ識別番号
	static bool state[4];//クリアフラグ（ステージ総数によって変える）
private:
	static bool deg_flag;
	static int feedcnt;
	static int backgraph;//背景画像
public:
	StageSelectTaskSystem();
	static void initialize();
	static void update();//Map_Initをステージ番号に基づき中身を変えて呼ぶ
	static void draw();
	static int get_stage();
	static void finalize();
	static void clear(int);
	
	static std::unique_ptr<StageSelectTaskMass> mass;
	static std::unique_ptr<StageSelectChara> chara;
	static std::unique_ptr<StageSelectTextBox> txtbox;

	static std::unique_ptr<SpawnEnemy> spawnenemy;//敵の生成
	static std::unique_ptr<SpawnItem> spawnitem;
};
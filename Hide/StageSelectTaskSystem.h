#pragma once
#include<memory>
#include"StageselectChara.h"
#include"StageSelectTaskMass.h"
#include"StageselectTaskTextBox.h"
#include"Point.h"
#include"SpawnEnemy.h"//敵生成をステージ選択直後に行うため

class StageSelectTaskSystem {
protected:
	int stage;//ステージ識別番号
	bool state[4];//クリアフラグ（ステージ総数によって変える）
	int backgraph;//背景画像
public:
	StageSelectTaskSystem();
	void update();//Map_Initをステージ番号に基づき中身を変えて呼ぶ
	void draw();
	int get_stage();
	void clear(int);
	
	std::unique_ptr<StageSelectTaskMass> mass;
	std::unique_ptr<StageSelectChara> chara;
	std::unique_ptr<StageSelectTextBox> txtbox;

	std::unique_ptr<SpawnEnemy> spawnenemy;//敵の生成
};
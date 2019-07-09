﻿#pragma once
#include<memory>
#include"StageselectChara.h"
#include"StageSelectTaskMass.h"
#include"StageselectTaskTextBox.h"
#include"SpawnItem.h"
#include"SelectTaskConfig.h"

class StageSelectTaskSystem {
protected:
	static int stage;//ステージ識別番号
	static bool state[MAX_STAGE];//クリアフラグ（ステージ総数によって変える）
private:
	static bool feed_flag;

	static int backgraph;//背景画像
public:
	StageSelectTaskSystem();
	static void init_member();
	static void initialize();
	static void update();//Map_Initをステージ番号に基づき中身を変えて呼ぶ
	static void draw();
	static int get_stage();
	static void finalize();
	static void clear(int);
	
	static std::unique_ptr<StageSelectTaskMass> mass;
	static std::unique_ptr<StageSelectChara> chara;
	static std::unique_ptr<StageSelectTextBox> txtbox;

	static std::unique_ptr<SpawnItem> spawnitem;
};
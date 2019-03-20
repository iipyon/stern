#include"GraphicResource.h" 
#include"DxLib.h" 
#include<fstream> 

//インストラクタ
GraphicResource::GraphicResource()
{
	handle = 0;
}
GraphicResource::GraphicResource(int** G_hundle)
{
	handle = G_hundle;
}
//デストラクタ
GraphicResource::~GraphicResource()
{
	DeleteGraph(**handle);
}
bool GraphicResource::load(char* FileName, int XNum, int YNum, int XSize, int YSize)
{
	//ファイル読み込み
	std::ifstream Graphic_R(FileName);
	//読み込み失敗したら返す
	if (!Graphic_R) { return false; }
	switch (graphicstate)
	{
	case GraphicState::player_stay_right:

		//分割総数は手入力(10のところ) 
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;

	case GraphicState::player_stay_left:
		LoadDivGraph(FileName, 10, XNum, YNum, XSize, YSize, *handle);
		break;
	}
	//
	Graphic_R.close();
	return true;
}

int GraphicResource::get(int kg_)
{
	//ハンドルを返す
	return *handle[kg_];
}
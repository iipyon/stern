#include"GraphicResource.h" 
#include"DxLib.h" 
#include<fstream> 

//インストラクタ
GraphicResource::GraphicResource()
{
	*handle = new int[256];
}
//デストラクタ
GraphicResource::~GraphicResource()
{
	for (int c = 0; c < 256; ++c)
	{
		DeleteGraph(*handle[c]);
	}
}
bool GraphicResource::load(char* FileName, int AllNum, int XNum, int YNum, 
						   int XSize, int YSize, int **G_handle)
{
	//ファイル読み込み
	std::ifstream Graphic_R(FileName);
	//読み込み失敗したら返す
	if (!Graphic_R) { return false; }
	switch (graphicstate)
	{
	case GraphicState::player_stay_right:
		*handle = *G_handle;
		break;
	case GraphicState::player_stay_left:
		*handle = *G_handle;
		break;
	}
	LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, *handle);

	//ファイルを閉じる
	Graphic_R.close();

	return true;
}

int GraphicResource::get(int kg_)
{
	//ハンドルを返す
	return *handle[kg_];
}
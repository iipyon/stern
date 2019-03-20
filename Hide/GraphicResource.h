#pragma once
class GraphicResource
{
	//ハンドル 
	int** handle;
	//状態
	enum class GraphicState {
		player_stay_right, player_stay_left,
	};
	GraphicState graphicstate;
public:
	//インストラクタ
	GraphicResource();
	GraphicResource(int** G_handle);
	//デストラクタ
	~GraphicResource();
	bool load(char* FileName, int XNum, int YNum, int XSize, int YSize);
	int get(int);
protected:
};
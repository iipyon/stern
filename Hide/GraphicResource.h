#pragma once
class GraphicResource
{

public:
	//状態
	enum class GraphicState {
		player_stay_right, player_stay_left,
	};
	//インストラクタ
	GraphicResource();
	//デストラクタ
	~GraphicResource();
	bool load(char* FileName, int AllNum,int XNum, int YNum,
		      int XSize, int YSize, int** G_handl);
	int get(int);
private:
	GraphicState graphicstate;
	//ハンドル 
	int** handle;
protected:
};
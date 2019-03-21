#pragma once
#include "GraphicState.h"
#define HANDLE_MAX 10	//10種類のアニメーション画像
class GraphicResource
{
public:

	GraphicResource();
	~GraphicResource();
	bool load(char* FileName, int AllNum,int XNum, int YNum,
		      int XSize, int YSize, int** G_handl);
	int get(int);
private:
	GraphicState graphicstate;
	//ハンドル 
	int handle[HANDLE_MAX];
};
#pragma once
#include<iostream>

class StageSelectTextBox {
private:
	int boxgraph;//�e�L�X�g�{�b�N�X�̉摜
	//���W�͌Œ�̂��߃v���p�e�B�͕K�v�Ȃ��Ɣ��f
	int start_x, start_y, end_x, end_y;
public:
	StageSelectTextBox();
	void update();
	void draw();
};
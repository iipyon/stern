#pragma once
class ClearTaskSystem {
private:
	bool feed_flag;
	void draw();
public:
	ClearTaskSystem();
	void init();
	void init_member();//ui増加の見込みがあるため
	void update();	
};
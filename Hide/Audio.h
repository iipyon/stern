#pragma once
#include<iostream>
#include"json11.hpp"

struct AudioObject {
	bool loop;
	bool exist;
	std::string  name;
	std::string  path;
	int handle;
};

class Audio {
private:
	int count_size;
	bool loop;
	std::unique_ptr<AudioObject[]> audio;
	json11::Json json;
	bool exist(std::string);
	void set_default();
public:
	Audio();
	~Audio();
	void play(std::string name);
	void load(std::string name);
};
#pragma once
#include<iostream>
#include"json11.hpp"

class AudioObject {
	friend class Audio;
	bool exist;
	std::vector<std::string> scopes;

	bool exist_scope(std::string);
	void set_default();
public:
	bool loop;
	std::string  name;
	std::string  path;
	int handle;
};

class Audio {
private:
	static std::vector<std::shared_ptr<AudioObject>> audioobj;
	static void register_audio(AudioObject&);
public:
	static void init();
	static void play(std::string name);
	static int load(std::string name);
	static void stop(std::string name);
};
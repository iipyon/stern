#pragma once
#include"json11.hpp"
#include <iostream>
#include<memory>
#include<fstream>

class Spawn {
public:
	Spawn(std::string path_);
	virtual void create(std::string stg) = 0;
protected:
	json11::Json data;
};
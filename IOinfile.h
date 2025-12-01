#pragma once
#include <iostream>
#include<string>
#include<vector>

class file {
public:
	enum MODE { READ=1, WRITE };
	void open();
	std::vector<std::string> open(std::string fname, MODE mod = READ );
};
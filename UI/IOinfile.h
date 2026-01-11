#pragma once
/*这是一个文件读写模块，包含交互式，程序式模块，旨在一定程度上减少源代码在写时减少工作量*/
#include <iostream>
#include<string>
#include<vector>
#include<cstdio>

class file {
public:
	enum MODE { READ=1, WRITE , ALL};
	void open();
	std::vector<std::string> open(std::string fname , MODE mod = READ, bool ifapp = false, std::vector<std::string>out = std::vector<std::string>(), int idofout = 1e9);
	bool Delete(std::string file_name);
};
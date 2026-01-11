#pragma once
/*这部分为运行的核心，提供了管理，类似命令集的功能，同时为本项目中使用关于系统部分的模块提供了接口*/
#include<string>
#include"user.h"

class SystemManagement{
private:
	std::string system_name;
	std::string version;
	std::string Id;
public:
	USERS::User* now_user;
	SystemManagement() : now_user(nullptr), system_name("Unknown"), version("0.0"), Id("0000") {}
	std::string getSystemName() const { return system_name; }
	std::string getVersion() const { return version; }
	std::string getId() const { return Id; }
	void setSystemName(const std::string& name) { system_name = name; }
	void setVersion(const std::string& ver) { version = ver; }
	void setId(const std::string& id) { Id = id; }
};

bool prepare(SystemManagement &SM);
void wait();
void overnow(std::string dscribe = "用户输入指令");
void start(SystemManagement &SM);
void show_screen();
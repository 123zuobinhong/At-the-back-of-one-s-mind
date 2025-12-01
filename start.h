#pragma once
#include<string>

class SystemManagement{
private:
	std::string system_name;
	std::string version;
	std::string Id;
public:
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
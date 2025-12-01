#include"start.h"
#include<fstream>
#include<iostream>
#include<string>
#include"string_game.h"
#include"IOinfile.h"

using namespace std;

const std::string kaywords[100] = { "","login","start","stop","wait","quit","help","overnow","run","check","retrun"};

const string screen_or_function[100] = { "------------------------------------------------------------" , 
										"注册或登录账号（login）","关闭程序（overnow / quit）","结束当前模块（stop / return）" ,
										"待机状态（wait）","运行某一模块（run）","获取说明（help）" ,
										"检查配置文件（check）","文件读写（file）","猜词游戏（SGame）" ,
										"------------------------------------------------------------" };

void show_screen() {
	int id = 1;
	for (int i = 0; i < 11; i++) {
		if (screen_or_function[i] != "------------------------------------------------------------"){
			cout << id << ":" << screen_or_function[i] << endl;
			id++;
		}
		else {
			cout << screen_or_function[i] << endl;
		}
	}
}

void LineBreak() {
	for (int i = 0; i < 16; i++) {
		cout << endl;
	}
}

bool prepare(SystemManagement &SM) {
	cout << "准备开始启动..." << endl;
	ifstream START;
	START.open("System_file.txt");
	if(!START.is_open()) {
		cout << "无法打开系统文件或系统文件已缺失，启动失败！" << endl;
		return false;
	}
	string key;
	double development=0;
	int n=3;
	while (getline(START,key)) {
		if (key.find("name") != string::npos) {
			SM.setSystemName(key.substr(key.find(":") + 1));
			development += 100.0 / n;
		}
		else if (key.find("Version") != string::npos) {
			SM.setVersion(key.substr(key.find(":") + 1));
			development += 100.0 / n;
		}
		else if (key.find("ID") != string::npos) {
			SM.setId(key.substr(key.find(":") + 1));
			development += 100.0 / n;
		}
		else {
			continue;
		}
		cout << "加载中：" << development << "%" << endl;
	}
	cout << "启动完成！" << endl;
	return true;
}

void wait() {
	cout << "系统已进入待机（休眠）状态，输入 \"start\" 以恢复" << endl;
	string cmd;
	while (getline(cin, cmd)) {
		if (cmd == "start") {
			return;
		}
		else {
			cout << "Error input! System is still in wait state. Please input again:\n";
		}
	}
}

void overnow(std::string dscribe) {
	cout << "系统关闭，原因：" << dscribe << endl;
	exit(0);
}



void start(SystemManagement &SM) {
	show_screen();
	cout << "输入指令以继续操作：（输入英文单词，注意大小写）" << endl;
	string cmd;
	while (getline(cin, cmd)) {
		if (cmd == "overnow" || cmd == "quit") {
			overnow();
		}
		else if (cmd == "wait") {
			wait();
			LineBreak();
		}
		else if (cmd == "run") {
			cout << "运行模块功能尚未完成，敬请期待！" << endl;
			LineBreak();
		}
		else if (cmd == "check") {
			cout << "检查配置文件功能尚未完成，敬请期待！" << endl;
			LineBreak();
		}
		else if (cmd == "SGame") {
			StringGame now;
			now.Gmain();
		}
		else if (cmd == "file") {
			file now;
			now.open();
		}
		else if (cmd == "login") {
			cout << "该部分尚未完成，敬请期待！\n";
			LineBreak();
		}
		else{
			cout << "Error input! Please input again:\n";
			continue;
		}
		show_screen();
		cout << "输入指令以继续操作：（输入英文单词，注意大小写）" << endl;
	}
}
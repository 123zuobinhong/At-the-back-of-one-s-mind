#include"start.h"
#include<fstream>
#include<iostream>
#include<string>
#include"string_game.h"
#include"IOinfile.h"

using namespace std;
/*一些关键字*/
const std::string kaywords[100] = { "","login","start","stop","wait","quit","help","overnow","run","check","retrun"};
/*功能目录*/
const string screen_or_function[100] = { "------------------------------------------------------------" , 
										"注册或登录账号（login）","关闭程序（overnow / quit）","结束当前模块（stop / return）" ,
										"待机状态（wait）","运行某一模块（run）","获取说明（help）" ,
										"检查配置文件（check）","文件读写（file）","猜词游戏（SGame）" };
/*显示了主屏*/
void show_screen() {
	cout << screen_or_function[0]<<endl;
	int id = 1;
	for (int i = 1; i < 10; i++) {
		cout << id << ":" << screen_or_function[i] << endl;
		id++;
	}
	cout << screen_or_function[0] << endl;
}
/*暂时无明显作用*/
void LineBreak() {
	for (int i = 0; i < 16; i++) {
		cout << endl;
	}
}
/*启动的引导*/
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
/*休眠（锁定）模式*/
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
/*类似于关机*/
void overnow(std::string dscribe) {
	cout << "系统关闭，原因：" << dscribe << endl;
	exit(0);
}


/*真正意义上的运行*/
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
			if (SM.now_user->locked_user() != true) {
				cout << "您已登录！\n";
			}
			else {
				cout << "请输入您的用户名，及其密码\n";
				string name, password;
				SM.now_user->login(name, password);
			}
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
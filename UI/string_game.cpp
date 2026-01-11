#include"string_game.h"
#include<ctime>
#include<cstdlib>
#include<iostream>

using namespace std;

void StringGame::Gmain() {
	string theword = getword();
	bool correct[33];
	for (int i = 0; i < 30; i++) {
		correct[i] = false;
	}
	char ch;
	int mistakes = 0;
	cout << "现在你将进行一场猜词游戏，规则如下\n";
	cout << "1.每次输入一个字母（超过一个可能会导致程序崩溃）\n";
	cout << "2.你有10次错误的机会，猜错10次以上，游戏将会结束\n";
	cout << "3.可以输入Q提前结束游戏\n";
	cout << "我们将在词典上百个词（全部由小写字母组成）中选择一个，祝你好运！\n";
	cout << "现在输入一个小写字母猜词：\n";
	while (true) {
		cin >> ch;
		cin.get();
		if (ch == 'Q') {
			return;
		}
		if (ch > 'z' || ch < 'a') {
			cout << "Error input! Please Enter a lowercase letter:\n";
			continue;
		}
		if (!checkchar(ch, theword,correct)) {
			mistakes++;
		}
		for (int i = 0; i < theword.size(); i++) {
			if (correct[i]) {
				cout << theword[i];
			}
			else {
				cout << '-';
			}
		}
		cout << endl;
		bool check1 = false;
		for (int i = 0; i < theword.size(); i++) {
			if (!correct[i]) {
				check1 = true;
			}
		}
		if (!check1) {
			cout << "You are right.\n";
			return;
		}
		cout << "你还有" << mistakesmax - mistakes << "次机会试错\n";
		if (mistakes >= mistakesmax) {
			cout << "游戏失败 T.T\n正确答案为：" << theword << endl;
			return;
		}
		cout << "请输入一个小写字母：\n";
	}
}

string StringGame::getword() {
	srand(time(nullptr));
	return dictionary[rand() % 1000];
}

bool StringGame::checkchar(char ch,const std::string& word,bool correct[33]) {
	bool check = false;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == ch) {
			correct[i] = true;
			check = true;
		}
	}
	return check;
}
#include"IOinfile.h"
#include<fstream>
#include"string_game.h"

void file::open() {
	using namespace std;
	char ch;
	cout << "输入0或1选择打开文件模式（0表示读，1表示写）"<<endl;
	cin >> ch;
	while (ch != '0' && ch != '1') {
		cout << "Error input! It isn't 0 or 1. Please input again:\n";
		cin >> ch;
	}
	if (ch == '0') {
		cout << "关于读取文件的说明，是否查看（输入Y表示查看，输入N表示跳过）\n";
		char intro;
		cin >> intro;
		while (intro != 'Y' && intro != 'N') {
			cout << "Error input! It isn't Y or N. Please input again:\n";
			cin >> intro;
		}
		if ('Y' == intro) {
			cout << "读取文件说明：\n"
				<< "1. 请确保文件存在于当前工作目录下，或提供完整的文件路径。\n"
				<< "2. 文件名区分大小写，请确保输入正确的文件名。\n"
				<< "3. 如果文件无法打开，程序将提示错误并要求重新输入文件名。\n"
				<< "4. 请确保有足够的权限访问该文件。\n"
				<< "5. 默认使用字符串的形式读入。\n";
		}
		cout << "请输入要读取的文件名（包括后缀）或文件路径：\n";
		string fname;
		getline(cin, fname);
		ifstream fin;
		fin.open(fname);
		while (!fin.is_open()) {
			cout << "Error! File doesn't exist. input again:\n";
			getline(cin, fname);
			fin.open(fname);
		}
		string line;
		while (getline(fin, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "关于写入文件的说明，是否查看（输入Y表示查看，输入N表示跳过）\n";
		char intro;
		cin >> intro;
		cin.get();
		while (intro != 'Y' && intro != 'N') {
			cout << "Error input! It isn't Y or N. Please input again:\n";
			cin >> intro;
		}
		if ('Y' == intro) {
			cout << "写入文件说明：\n"
				<< "1. 如果指定的文件不存在，程序将自动创建一个新文件。\n"
				<< "2. 如果文件已存在，写入操作将覆盖原有内容，请谨慎操作。\n"
				<< "3. 请确保有足够的权限在目标位置创建或修改文件。\n"
				<< "4. 文件名区分大小写，请确保输入正确的文件名。\n"
				<< "5. 默认使用字符串的形式写入。\n";
		}
		cout << "请输入要写入的文件名（包括后缀）或文件路径：\n";
		string fname;
		getline(cin, fname);
		ofstream fout;
		fout.open(fname);
		cout << "请输入要写入的内容（输入单独一行的EOF(注意大小写)表示结束）\n";
		string line;
		while (getline(cin, line)) {
			if (line == "EOF"){
				break;
			}
			fout << line << endl;
		}
		fout.close();
	}
}

std::vector<std::string> file::open(std::string fname, MODE mod) {
	using namespace std;
	vector<string>err;
	err.push_back("ERROR");
	switch (mod) {
	case READ: {
		ifstream fin;
		fin.open(fname);
		if (!fin.is_open()) {
			return err;
		}
		string line;
		vector<string>input;
		while (getline(fin, line)) {
			input.push_back(line);
		}
		return input;
	}
	case WRITE: {
		ofstream fout;
		fout.open(fname);
		if (!fout.is_open()) {
			return err;
		}
		string line;
		while (getline(cin, line)) {
			fout << line << endl;
		}
		return vector<string>();
	}
	}
}

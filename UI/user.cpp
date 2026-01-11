#include"user.h"

using namespace USERS;

bool User::login(const std::string& user, const std::string& pass) {
	file visit;
	visit.open("configuration_of_user.txt", file::READ);
	if (user == username && pass == password) {
		logged_in = true;
		std::cout << "µÇÂ¼³É¹¦£¡\n";
		return true;
	}
	else {
		std::cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó£¬µÇÂ¼Ê§°Ü£¡\n";
		return false;
	}
}

std::vector<std::string> User::iofile(fileio mod, std::string file_name, bool ifapp, std::vector<std::string>write) {
	switch (mod) {
	case WRITE: {
		file now;
		if (ifapp) {
			now.open(file_name, file::WRITE, ifapp, write);
		}
		else {
			now.open(file_name, file::WRITE, false, write);
		}
		break;
	}
	case READ:
		file now;
		write = now.open(file_name, file::READ);
		break;
	case DELETE:
		file now;
		now.Delete(file_name);
		write.push_back("DELETE_SUCCESS");
		break;
	}
	return write;
}

bool USERS::register_user(const std::string& user, const std::string& pass) {
	
}
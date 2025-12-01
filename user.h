#pragma once
#include<string>
#include<fstream>
#include<iostream>

namespace USERS {
	class User {
		std::string username;
		std::string password;
		bool logged_in, locked;
	public:
		User (const std::string& user, const std::string& pass)
			: username(user), password(pass), logged_in(false), locked(false) {}
		virtual bool login(const std::string& user, const std::string& pass) {}
		bool reset_password(const std::string& old_pass, const std::string& new_pass) {
			if (old_pass == password) {
				password = new_pass;
				std::cout << "请再次输入以确认新密码：\n";
				std::string confirm_pass;
				std::cin >> confirm_pass;
				while (confirm_pass != new_pass) {
					std::cout << "两次输入的密码不一致，请重新确认新密码：\n";
					std::cin >> confirm_pass;
				}
				std::cout << "密码修改成功！\n";
			}
			else {
				std::cout << "旧密码错误，无法修改密码！\n";
				return false;
			}
		}
	};

	class Admin : public User {
		bool special_access, Administrator;
	public:
		Admin(const std::string& user = "ADMIN", const std::string& pass = "000000")
			: User(user, pass) {
			special_access = true;
			Administrator = true;
		}
		bool login(const std::string& user, const std::string& pass, const std::string special_key);
	};
}



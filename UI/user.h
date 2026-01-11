#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
#include"IOinfile.h"

namespace USERS {
	static int user_count;
	enum privilege_level { NORMAL_USER = 1, BLACKLISTED_USER, WRITELISTED_USER, ADMIN_USER };
	enum fileio { READ = 1, WRITE, DELETE };
	std::vector<std::string> empty_vector;
	bool register_user(const std::string& user, const std::string& pass);
	class User {
		file nowfile, userinf;
		std::string username;
		std::string password;
		bool logged_in, locked;
	public:
		User (const std::string& user = "EMPTY", const std::string& pass = "It is a mistake.")
			: username(user), password(pass), logged_in(false), locked(false) {
			empty_vector.push_back("EMPTY");
		}
		virtual bool login(const std::string& user, const std::string& pass);
		virtual std::vector<std::string> iofile(fileio mod, std::string file_name, bool ifapp, std::vector<std::string>write = empty_vector);
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
		const bool locked_user() { return locked; }
		const bool logged_user() { return logged_in; }
	};

	class NormalUser : public User {
	public:
		NormalUser(const std::string& user, const std::string& pass)
			: User(user, pass) {}
		privilege_level getprivileges() const { return NORMAL_USER; };
	};

	class BlacklistedUser : public NormalUser {
	public:
		BlacklistedUser(const std::string& user, const std::string& pass)
			: NormalUser(user, pass) {}
		privilege_level getprivileges() const { return BLACKLISTED_USER; };
	};

	class WhitelistedUser : public NormalUser {
		public:
		WhitelistedUser(const std::string& user, const std::string& pass)
			: NormalUser(user, pass) {}
		privilege_level getprivileges() const { return WRITELISTED_USER; };
	};

	class AdminUser : public WhitelistedUser {
	public:
		AdminUser(const std::string& user, const std::string& pass)
			: WhitelistedUser(user, pass) {
		}
		privilege_level getprivileges() const { return ADMIN_USER; }
	};
}
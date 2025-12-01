#include<iostream>
#include"IOinfile.h"
#include"start.h"

SystemManagement SM;

int main() {
	using namespace std;
	if (!prepare(SM)) {
		return 0;
	}
	start(SM);
	return 0;
}
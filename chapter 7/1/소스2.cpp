#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* friendname, int friendage) : age(friendage) {
		cout << "new name" << endl;
		name = new char[strlen(friendname) + 1];
		strcpy(name, friendname);
	}
	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		cout << "delete name" << endl;
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* friendname, int friendage, const char* friendaddr, const char* friendphone) : MyFriendInfo(friendname, friendage) {
		cout << "new addr,phone" << endl;
		addr = new char[strlen(friendaddr) + 1];
		strcpy(addr, friendaddr);
		phone = new char[strlen(friendphone) + 1];
		strcpy(phone, friendphone);
	}
	void ShowMyFriendDetaInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
	~MyFriendDetailInfo() {
		cout << "delete addr,phone" << endl;
		delete[]addr;
		delete[]phone;
	}
};

int main(void) {
	MyFriendInfo f1("Kim", 20);
	f1.ShowMyFriendInfo();

	cout << endl;
	MyFriendDetailInfo f2("Lee", 24, "Seoul", "010-1234-5528");
	f2.ShowMyFriendDetaInfo();

	return 0;
}
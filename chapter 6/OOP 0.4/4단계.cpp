#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Account {
private:
	int id;
	char* name;
	int amount;
public:
	Account() : id(0), amount(0) {
		name = new char[1];
		name[0] = '\0';
	}

	Account(int user_id, const char* user_name, int user_amount) : id(user_id), amount(user_amount) {
		name = new char[strlen(user_name) + 1];
		strcpy(name, user_name);
	}

	Account(const Account& copy) : id(copy.id), amount(copy.amount) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetID() const { return id; }

	bool dealAccount(int user_id, int money) {
		if (user_id == id) {
			if (amount + money < 0) {
				cout << "잔액부족\n";
				return false;
			}
			amount += money;
			return true;
		}
		return false;
	}

	void ShowAccount() const {
		cout << "계좌ID: " << id << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << amount << endl;
		return;
	}

	~Account() {
		delete[]name;
	}
};

void ShowMenu(void);
void MakeAccont(void);
void Deposit(void);
void Withdraw(void);
void ShowInfo(void);

Account* info[100];
int info_num = 0;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cin >> choice;
		cout << "\n\n";
		if (choice == 1) MakeAccont();
		else if (choice == 2) Deposit();
		else if (choice == 3) Withdraw();
		else if (choice == 4) ShowInfo();
		else break;
	}

	for (int i = 0; i < info_num; i++) {
		delete info[i];
	}

	return 0;
}

void ShowMenu(void) {
	cout << "\n-----Menu-----\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
	cout << "선택: ";
}

void MakeAccont(void) {
	int id, amount;
	char name[100];
	cout << "[계좌개설]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> amount;
	info[info_num++] = new Account(id, name, amount);
}

void Deposit(void) {
	int id;
	int amount;
	cout << "[입   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> amount;

	for (int i = 0; i < info_num; i++) {
		if (info[i]->dealAccount(id, amount)) return;
	}

	cout << "유효하지 않은 ID 입니다.\n";
}

void Withdraw(void) {
	int id;
	int amount;
	cout << "[출   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> amount;

	for (int i = 0; i < info_num; i++) {
		if (info[i]->dealAccount(id, -amount)) return;
	}

	cout << "유효하지 않은 ID 입니다.\n";
}

void ShowInfo(void) {
	for (int i = 0; i < info_num; i++) {
		info[i]->ShowAccount();
	}
}


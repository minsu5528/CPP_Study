#include <iostream>
#include <string>
using namespace std;

void ShowMenu(void);
void MakeAccont(void);
void Deposit(void);
void Withdraw(void);
void ShowInfo(void);

typedef struct Info {
	int id;
	string name;
	int amount;
};

Info info[100];
int check = 0;

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

	return 0;
}

void ShowMenu(void) {
	cout << "-----Menu-----\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
	cout << "선택: ";
}

void MakeAccont(void) {
	cout << "[계좌개설]\n";
	cout << "계좌ID: "; cin >> info[check].id;
	cout << "이 름: "; cin >> info[check].name;
	cout << "입금액: "; cin >> info[check].amount;
	check++;
}

void Deposit(void) {
	int id;
	int amount;
	cout << "[입   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> amount;

	for (int i = 0; i < check; i++) {
		if (info[i].id == id) {
			info[i].amount += amount;
			cout << "입금완료\n";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다.\n";
}

void Withdraw(void) {
	int id;
	int amount;
	cout << "[출   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> amount;

	for (int i = 0; i < check; i++) {
		if (info[i].id == id) {
			info[i].amount -= amount;
			cout << "출금완료";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다.\n";
}

void ShowInfo(void) {
	for (int i = 0; i < check; i++) {
		cout << "계좌ID: " << info[i].id << endl;
		cout << "이 름: " << info[i].name << endl;
		cout << "잔 액: " << info[i].amount << endl;
	}
}
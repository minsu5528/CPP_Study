#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//----------------------------Acccount 클래스-------------------------
class Account {
private:
	int id;
	char* name;
	int amount;
public:
	Account(int user_id, const char* user_name, int user_amount);
	Account(const Account& copy);
	int GetID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccount() const;
	~Account();
};

Account::Account(int user_id, const char* user_name, int user_amount) : id(user_id), amount(user_amount) {
	name = new char[strlen(user_name) + 1];
	strcpy(name, user_name);
}

Account::Account(const Account& copy) : id(copy.id), amount(copy.amount) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::GetID() const { return id; }

void Account::Deposit(int money) {
	amount += money;
}

int Account::Withdraw(int money) {
	if (amount < 0) return 0;
	amount -= money;
	return money;
}


void Account::ShowAccount() const {
	cout << "계좌ID: " << id << endl;
	cout << "이 름: " << name << endl;
	cout << "잔 액: " << amount << endl;
	return;
}

Account::~Account() {
	delete[]name;
}

//----------------------------AcccountHander 클래스-------------------------
class AccountHander {
private:
	Account* info[100];
	int infoNum;
public:
	AccountHander();
	void ShowMenu(void)  const;
	void MakeAccont(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowInfo(void);
	~AccountHander();
};

AccountHander::AccountHander() : infoNum(0) {

}

AccountHander::~AccountHander() {
	for (int i = 0; i < infoNum; i++)
		delete info[i];
}

void AccountHander::ShowMenu() const {
	cout << "\n-----Menu-----\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n";
	cout << "선택: ";
}

void AccountHander::MakeAccont(void) {
	int id, amount;
	char name[NAME_LEN];
	cout << "[계좌개설]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> amount;
	cout << endl;

	info[infoNum++] = new Account(id, name, amount);
}

void AccountHander::Deposit(void) {
	int id;
	int amount;
	cout << "[입   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> amount;

	for (int i = 0; i < infoNum; i++) {
		if (info[i]->GetID() == id) {
			info[i]->Deposit(amount);
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다.\n";
}

void AccountHander::Withdraw(void) {
	int id;
	int amount;
	cout << "[출   금]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> amount;

	for (int i = 0; i < infoNum; i++) {
		if (info[i]->GetID() == id) {
			if (info[i]->Withdraw(amount) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금 완료" << endl;
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다.\n";
}

void AccountHander::ShowInfo(void) {
	for (int i = 0; i < infoNum; i++) {
		info[i]->ShowAccount();
		cout << endl;
	}
}





//----------------------------Main 함수-------------------------
int main(void) {
	int choice;
	AccountHander manager;


	while (1) {
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << "\n\n";
		switch (choice)
		{
		case MAKE:
			manager.MakeAccont();
			break;
		case DEPOSIT:
			manager.Deposit();
			break;
		case WITHDRAW:
			manager.Withdraw();
			break;
		case INQUIRE:
			manager.ShowInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}

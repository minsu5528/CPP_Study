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
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccount() const;
	~Account();
};


//----------------------------Acccount 멤버 함수 정의-------------------------

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

//----------------------------NormalAcccount 클래스-------------------------
enum { NORMAL = 1, CREDIT = 2 };
class NormalAccount : public Account {
private:
	int interest;
public:
	NormalAccount(int user_id, const char* user_name, int user_amount, int user_interest);
	void Deposit(int money);
	double GetINT() const;
};

//----------------------------NormalAcccount 멤버함수-------------------------
NormalAccount::NormalAccount(int user_id, const char* user_name, int user_amount, int user_interest) : Account(user_id, user_name, user_amount), interest(user_interest) {

}

double NormalAccount::GetINT() const { return interest; }

void NormalAccount::Deposit(int money) {
	Account::Deposit(money + int(money * interest / 100));
}


//----------------------------HighCreditAcccount 클래스-------------------------
enum { A = 7, B = 4, C = 2 };

class HighCreditAccount : public NormalAccount {
private:
	int credit;
public:
	HighCreditAccount(int user_id, const char* user_name, int user_amount, int user_interest, int user_credit);
	void Deposit(int money);
};

//----------------------------HighCreditAcccount 멤버함수-------------------------
HighCreditAccount::HighCreditAccount(int user_id, const char* user_name, int user_amount, int user_interest, int user_credit) : NormalAccount(user_id, user_name, user_amount, user_interest), credit(user_credit) {

}

void HighCreditAccount::Deposit(int money) {
	NormalAccount::Deposit(money);
	Account::Deposit(int(money * (credit / 100)));
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
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

//----------------------------AcccountHander 멤버함수 정의-------------------------

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
	int choice;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: "; cin >> choice;
	switch (choice) {
	case NORMAL:
		MakeNormalAccount();
	case CREDIT:
		MakeCreditAccount();
	default:
		cout << "Illegal account selection.." << endl;
	}
}

void AccountHander::MakeNormalAccount() {
	int id, amount;
	int interest;
	char name[NAME_LEN];

	cout << "[보통예금계좌 신설]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> amount;
	cout << "이자율: "; cin >> interest;
	cout << endl;

	info[infoNum++] = new NormalAccount(id, name, amount, interest);
}

void AccountHander::MakeCreditAccount() {
	int id, amount;
	int interest;
	int credit;
	char name[NAME_LEN];

	cout << "[신용신뢰계좌 신설]\n";
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> amount;
	cout << "이자율: "; cin >> interest;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> credit;
	cout << endl;

	switch (credit) {
	case 1:
		info[infoNum++] = new HighCreditAccount(id, name, amount, interest, A);
	case 2:
		info[infoNum++] = new HighCreditAccount(id, name, amount, interest, B);
	case 3:
		info[infoNum++] = new HighCreditAccount(id, name, amount, interest, C);
	default:
		cout << "Illegal credit selection.." << endl;
	}
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

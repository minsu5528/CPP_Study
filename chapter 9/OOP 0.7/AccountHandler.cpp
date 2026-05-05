#include "BankingCommonDec1.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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
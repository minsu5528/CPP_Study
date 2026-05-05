#include "Account.h"
#include "BankingCommonDec1.h"

//----------------------------Acccount ¸â¹ö ÇÔ¼ö Á¤ÀÇ-------------------------

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
	cout << "°èÁÂID: " << id << endl;
	cout << "ÀÌ ¸§: " << name << endl;
	cout << "ÀÜ ¾×: " << amount << endl;
	return;
}

Account::~Account() {
	delete[]name;
}
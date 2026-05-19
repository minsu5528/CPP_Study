#include "BankingCommonDec1.h"
#include "Account.h"

int main(void) {
	int choice;
	AccountHander manager;


	while (1) {
		manager.ShowMenu();
		cout << "¼±ÅÃ: ";
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

#inndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
	int interest;
public:
	NormalAccount(int user_id, const char* user_name, int user_amount, int user_interest) : Account(user_id, user_name, user_amount), interest(user_interest) {

	}
	double GetINT() const { return interest; }

	virtual void Deposit(int money) {
		Account::Deposit(money + int(money * interest / 100));
	}
};

#endif
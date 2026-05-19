#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int credit;
public:
	HighCreditAccount(int user_id, const char* user_name, int user_amount, int user_interest, int user_credit) : NormalAccount(user_id, user_name, user_amount, user_interest), credit(user_credit) {

	}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(int(money * (credit / 100)));
	}
};

#endif
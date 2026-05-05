#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

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

#endif
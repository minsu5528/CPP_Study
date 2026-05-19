#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHander {
private:
	BoundCheckAccountPtrArray accArr;
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
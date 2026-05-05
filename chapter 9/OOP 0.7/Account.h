#inndef __ACCOUNT_H__
#define __ACCOUNT_H__


//----------------------------Acccount Å¬·¡½º-------------------------
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

#endif

#pragma once
class BankRekening
{
public:
	BankRekening(int Id, double Balance);
	~BankRekening();
	int id;
	double getBalance(){
		return balance / 2;
	};
	double getMoney(double money){
		balance -= money * 2;
		return money;
	};
	BankRekening& operator<<(double money){
		balance += money;
		return BankRekening(id, balance);
	};
private:
	double balance;
};


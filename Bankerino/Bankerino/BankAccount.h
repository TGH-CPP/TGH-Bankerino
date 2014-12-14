#pragma once
#include <string>
#include "BankRekening.h"
class BankAccount
{
public:
	BankAccount(std::string Naam, std::string Pass, int Level, BankRekening Rekening);
	BankAccount(std::string Naam, std::string Pass, int Level, int RekeningId, double RekeningBalance);
	BankAccount(std::string Naam, std::string Pass, BankRekening Rekening);
	BankAccount(std::string Naam, std::string Pass, int RekeningId, double RekeningBalance);
	BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, BankRekening Rekening);
	BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int RekeningId, double RekeningBalance);
	BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int Level, BankRekening Rekening);
	BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int Level, int RekeningId, double RekeningBalance);
	BankAccount();
	~BankAccount();
	int level = 0;
	std::string naam = "Piet";
	std::string pass = "Piet1996";
	std::string adress = "Pietersweg 12";
	std::string woonplaats = "Groningen";
	BankRekening rekening = BankRekening(1, 9001);
};


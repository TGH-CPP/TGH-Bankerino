#include "stdafx.h"
#include "BankAccount.h"
#include <string>

BankAccount::BankAccount(){
	naam = ""; pass = ""; level = 0; woonplaats = ""; adress = "";
}

BankAccount::BankAccount(std::string Naam, std::string Pass, int Level, BankRekening Rekening){
	naam = Naam; pass = Pass; level = Level; rekening = Rekening; woonplaats = ""; adress = "";
};

BankAccount::BankAccount(std::string Naam, std::string Pass, int Level, int RekeningId, double RekeningBalance){
	naam = Naam; pass = Pass; level = Level, rekening = BankRekening(RekeningId, RekeningBalance); woonplaats = ""; adress = "";
};

BankAccount::BankAccount(std::string Naam, std::string Pass, BankRekening Rekening){
	naam = Naam; pass = Pass; level = 0; rekening = Rekening; woonplaats = ""; adress = "";
};

BankAccount::BankAccount(std::string Naam, std::string Pass, int RekeningId, double RekeningBalance){
	naam = Naam; pass = Pass; level = 0; rekening = BankRekening(RekeningId, RekeningBalance); woonplaats = ""; adress = "";
};

BankAccount::BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, BankRekening Rekening){
	naam = Naam; pass = Pass; level = 0; rekening = Rekening; woonplaats = Woonplaats; adress = Adress; 
};

BankAccount::BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int RekeningId, double RekeningBalance){
	naam = Naam; pass = Pass; level = 0; rekening = BankRekening(RekeningId, RekeningBalance); woonplaats = Woonplaats; adress = Adress;
};

BankAccount::BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int Level, BankRekening Rekening){
	naam = Naam; pass = Pass; level = Level; rekening = Rekening; woonplaats = Woonplaats; adress = Adress; 
};

BankAccount::BankAccount(std::string Naam, std::string Pass, std::string Adress, std::string Woonplaats, int Level, int RekeningId, double RekeningBalance){
	naam = Naam; pass = Pass; level = Level; rekening = BankRekening(RekeningId, RekeningBalance); woonplaats = Woonplaats; adress = Adress;
};

BankAccount::~BankAccount()
{
}

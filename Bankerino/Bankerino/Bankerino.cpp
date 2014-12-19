// Bankerino.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include "BankAccount.h"

void section_command(std::string Cmd, std::string &wd1, std::string &wd2, bool makeUpper)
{
	std::string sub_str;
	std::vector<std::string> words;
	char search = ' ';
	size_t i, j;

	// Split Command into vector
	for (i = 0; i < Cmd.size(); i++)
	{
		if (Cmd.at(i) != search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i));
		}
		if (i == Cmd.size() - 1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
	// Clear out blanks
	for (i = words.size() - 1; i > 0; i--)
	{
		if (words.at(i) == "")
		{
			words.erase(words.begin() + i);
		}
	}
	// Make words upper case
	if (makeUpper){
		for (i = 0; i < words.size(); i++)
		{
			for (j = 0; j < words.at(i).size(); j++)
			{
				if (islower(words.at(i).at(j)))
				{
					words.at(i).at(j) = toupper(words.at(i).at(j));
				}
			}
		}
	}
	// Get 2 words.
	if (words.size() == 0)
	{
		std::cout << "No command given" << std::endl;
	}
	if (words.size() == 1)
	{
		wd1 = words.at(0);
	}
	if (words.size() == 2)
	{
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2)
	{
		std::cout << "Command too long. Only type one or two words (verb and noun)" << std::endl;
	}
}

void initializeObjects(std::list<BankAccount> &accounts){
	accounts.push_back(BankAccount("admin", "admin", 2, 0, 9001));
	accounts.push_back(BankAccount("Armando", "Armandreano1992", 0, 1, 2000));
}

void getCommand(std::string command, std::string &word_1, std::string &word_2, bool makeUpper){
	std::cout << std::endl;
	getline(std::cin, command);
	std::cout << "Your raw command was " << command << std::endl << std::endl;
	word_1 = "";
	word_2 = "";
	section_command(command, word_1, word_2, makeUpper);
}

void loginHandler(std::string& word_1, std::string& word_2, std::list<BankAccount>& accounts, BankAccount& currentAccount, bool& loggedIn){
	bool match = false;
	for (BankAccount& account : accounts){
		if (word_1 == account.naam){
			match = true;
			if (word_2 == account.pass){
				currentAccount = account;
				std::cout << "Logged in succesfully as " + account.naam + "." << std::endl;
			}
			else{
				std::cout << "Incorrect password." << std::endl;
			}
		}
	}
	if (match){
		loggedIn = true;
	}
	else{
		std::cout << "This name does not match any account names." << std::endl;
	}
}
void transferHandler(std::string& command, std::string& word_1, std::string& word_2, std::list<BankAccount>& accounts, BankAccount& currentAccount){
	std::cout << "Transfer has started, please input the ID you want to transfer too and the amount of MONEY you want to transfer (Formatted as ID MONEY in next command)." << std::endl;
	getCommand(command, word_1, word_2, false);
	try
	{
		std::stringstream stream(word_1);
		long id;
		char test;

		if ((!(stream >> id)) || (stream >> test))
		{
			throw std::runtime_error("NaN");
		}

		std::stringstream stream1(word_2);;
		double money;
		char test1;

		if ((!(stream1 >> money)) || (stream1 >> test1))
		{
			throw std::runtime_error("NaN");
		}
		bool match = false;
		for (BankAccount& account : accounts){
			if (account.rekening.id == id){
				match = true;
				account.rekening << currentAccount.rekening.getMoney(money);
				std::cout << "Transfer succeeded" << std::endl;
			}
		}

		if (!match)
			throw std::runtime_error("404 ID not found");
	}
	catch (const std::runtime_error err)
	{
		std::cout << "Transfer failed. Error: " << err.what() << std::endl;
	}
};
void newAccountHandler(std::string& command, std::list<BankAccount>& accounts){
	std::string word_2;
	std::cout << "Initiated new account, please input NAME & PASS for the new account" << std::endl;
	std::string newName, newPass;
	getCommand(command, newName, newPass, false);
	std::cout << "Correctly got NAME & PASS, do you want to add an Adress and City? YES/NO" << std::endl;
	std::string yesNo;
	getCommand(command, yesNo, word_2, true);
	if (yesNo == "YES"){
		std::string newAdress, newCity;
		std::cout << "Please enter the ADRESS & CITY you want to add to this new account" << std::endl;
		getCommand(command, newAdress, newCity, false);

		std::cout << "Please enter the LEVEL (0,1,2) & BALANCE the account should have" << std::endl;
		std::string newLevelStr, newBalance;
		getCommand(command, newLevelStr, newBalance, false);
		try{
			std::stringstream stream(newLevelStr);
			int newLevel;
			char test;

			if ((!(stream >> newLevel)) || (stream >> test))
			{
				throw std::runtime_error("NaN");
			}

			std::stringstream stream1(newBalance);
			double newBalance;

			if ((!(stream1 >> newBalance)) || (stream1 >> test))
			{
				throw std::runtime_error("NaN");
			}

			accounts.push_back(BankAccount(newName, newPass, newAdress, newCity, newLevel, accounts.size(), newBalance));
			std::cout << "Added the account!" << std::endl;

		}
		catch (const std::runtime_error err){
			std::cout << "Failed to add account. Error: " << err.what() << std::endl;
		}
	}
	else if (yesNo == "NO"){
		std::cout << "Please enter the LEVEL (0,1,2) & BALANCE the account should have" << std::endl;
		std::string newLevelStr, newBalanceStr;
		getCommand(command, newLevelStr, newBalanceStr, false);

		try{
			std::stringstream stream(newLevelStr);
			int newLevel;
			char test;

			if ((!(stream >> newLevel)) || (stream >> test))
			{
				throw std::runtime_error("NaN");
			}

			std::stringstream stream1(newBalanceStr);
			double newBalance;

			if ((!(stream1 >> newBalance)) || (stream1 >> test))
			{
				throw std::runtime_error("NaN");
			}

			accounts.push_back(BankAccount(newName, newPass, newLevel, accounts.size(), newBalance));
			std::cout << "Added the account!" << std::endl;

		}
		catch (const std::runtime_error err){
			std::cout << "Failed to add account. Error: " << err.what() << std::endl;
		}
	}
	else{
		std::cout << "Didn't find YES or NO, please try to ADD ACCOUNT again" << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string command, word_1, word_2;
	bool initialized = false, loggedIn = false;
	std::list<BankAccount> accounts;
	BankAccount currentAccount;
	while (word_1 != "QUIT"){
		command.clear();

		if (initialized){
			if (!loggedIn){
				loginHandler(word_1, word_2, accounts, currentAccount, loggedIn);
			}
			else{
				if (word_1 == "LOGOUT"){
					loggedIn = false;
					std::cout << "Succesfully logged out. Log back in with NAME PASS." << std::endl;
				}
				else if (word_1 == "SHOW"){
					if (word_2 == "BALANCE"){
						std::cout << "Balance: " << currentAccount.rekening.getBalance() << std::endl;
					}
					else if (word_2 == "ACCOUNT"){
						std::cout << "Name: " << currentAccount.naam << std::endl;
						std::cout << "Pass: " << currentAccount.pass << std::endl;
						std::cout << "Adress: " << currentAccount.adress << std::endl;
						std::cout << "Woonplaats: " << currentAccount.woonplaats << std::endl;
					}
				}
				else if (word_1 == "TRANSFER"){
					if (word_2 == "MONEY"){
						transferHandler(command, word_1, word_2, accounts, currentAccount);
					}
				}
				else if (word_1 == "ADD" && word_2 == "ACCOUNT" && currentAccount.level >= 1){
					newAccountHandler(command, accounts);
				}
				else if (word_1 == "HELP"){
					std::cout << "Current usable commands are:" << std::endl;
					std::cout << "\tLOGOUT\t\tLogs you out of current account" << std::endl;
					std::cout << "\tSHOW PARAM\tShows BALANCE or ACCOUNT info" << std::endl;
					std::cout << "\tTRANSFER MONEY\tTransfer money to another account" << std::endl;
					if (currentAccount.level >= 1)
						std::cout << "\tADD ACCOUNT\tLet's you add another account" << std::endl;
				}
			}
			if (loggedIn){
				getCommand(command, word_1, word_2, true);
			}
			else{
				getCommand(command, word_1, word_2, false);
			}
		}

		if (!initialized){
			std::cout << "Please log in by entering your account's NAME and PASS." << std::endl;
			initializeObjects(accounts);
			initialized = true;
			getCommand(command, word_1, word_2, false);
		}
	}

	return 0;
}


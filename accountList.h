//Author: Patrick germaine
//contains the accountList class. parameterised contructor reads in account information from seperate text file and stores in in the
//data member "accounts" which is an array of pointers to account objects. Also contains a function for adding new account
//objects to the accounts array as well as for retrieving account according to a search criteria, e.g. getting an 
//account with and particular username.
#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "account.h"
#include "productList.h"
#include <ctype.h> //for toupper
using std::vector;
using std::string;
using std::ios;


class accountList
{
public:
	//paramterised constructor
	accountList(string filePath, vector<string>);
	//destructor
	~accountList(){
		delete[] accounts;
	}
	//function to return account of a given account number
	Account getAccountByNum(int accountNumber);
	//function to return account of a given username
	Account getAccountByUser(string userName, vector<string>);
	//function to create a new account
	void createAccount(string filePath);
	//function which counts the number of accounts in the accounts textfile
	int calcNumAccounts(string filePath);
	//function which retrieved the value of the data member specifying the number of accounts in the accountList object
	int getNumAccounts();
	// function to check that input name contains only alphabetical characters
	bool valid_name(string name);
private:
	int numAccounts;
	Account *accounts;
};

#endif
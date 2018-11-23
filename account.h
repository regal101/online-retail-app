//Author: Patrick germaine
//account.h
//contains the class "account" for storing information on user accounts. Contains data members for storing information such as
//username, and account number, and bought products. Also contains member functions for retrieve private datamembers.

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "product.h"
#include <memory> //for shared pointer
using std::cout; using std::cin; using std::endl; using std::string;
using std::stringstream; using std::ifstream; using std::ofstream;
using std::vector;using std::shared_ptr;

//class for creating user accounts, contains datamembers and access functions for storing the information
//associated with each account
class Account
{
	friend class productList;
public:
	//account default constructor
	Account();
	//account paramterised constructor
	Account(string accountInformation, vector<string> fileVector);
	// Getters for returning private data members of each account
	string getFirstName();
	string getLastName();
	string getName();
	string getUserName();
	int getAccountNumber();
	vector<shared_ptr<Product>> getMyListings();
	vector<shared_ptr<Product>> returnMyListings(vector<string> fileVector);
	vector<shared_ptr<Product>> getMyBought();
	vector<shared_ptr<Product>> returnMyBought(vector<string> fileVector);
private:
	//private data members associated with each account
	string firstName;
	string lastName;
	string userName;
	int accountNumber;
	vector < std::shared_ptr<Product> > myListings ;
	vector < std::shared_ptr<Product> > myBought;
};

#endif
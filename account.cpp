//Author: Patrick germaine
//account.cpp
#include "account.h"
#include "product.h"
#include "productList.h"
//account default constructor
Account::Account(){
	firstName = "firstName";
	lastName = "lastName";
	accountNumber = 0;
}
//account parameterized constructor: takes line from account information
//text file, parses, and inputs information into the an account object.
Account::Account(string accountInformation, vector<string> fileVector){
	stringstream accountStream(accountInformation);
	accountStream >> firstName;
	accountStream >> lastName;
	accountStream >> accountNumber;
	userName = firstName + lastName;
	myListings = this->returnMyListings(fileVector);
	myBought = this->returnMyBought(fileVector);
}
// getters for returning the private data members associated with each account
string Account::getFirstName(){return firstName;}
string Account::getLastName(){return lastName;}
string Account::getName(){return firstName + " " + lastName;}
int Account::getAccountNumber(){return accountNumber;}
string Account::getUserName(){return firstName + lastName;}
vector<shared_ptr<Product>> Account::getMyListings(){ return this->myListings; }
vector<shared_ptr<Product>> Account::getMyBought(){ return this->myBought; }

// returns all the listings for a the account which is in use
vector<shared_ptr<Product>> Account::returnMyListings(vector<string> fileVector){
	vector<shared_ptr<Product>> myProducts;
	productList prodList(fileVector);
	for (auto it : prodList.returnAllProducts()){
		if (it->getSeller() == this->getUserName())
		{
			std::shared_ptr<Product> temp(std::move(it));
			myProducts.push_back(temp);
		}
	}
	return myProducts;
}
// returns all the bought items for a the account which is in use
vector<shared_ptr<Product>> Account::returnMyBought(vector<string> fileVector){
	vector<shared_ptr<Product>> myBought;
	productList prodList(fileVector);
	for (auto it : prodList.returnAllProducts()){
		if (it->getBuyer() == this->getUserName()){
			std::shared_ptr<Product> temp(move(it));
			myBought.push_back(temp);
		}
	}
	return myBought;
}


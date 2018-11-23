//Author: Patrick germaine
//accountList.cpp
#include "accountList.h"
#include "account.h"

//paramterised constructor
accountList::accountList(string filePath, vector<string> fileVector)
{
	// opens the account information text file
	ifstream accountFile(filePath);
	// calculated the number of accounts in the text file
	numAccounts = this->accountList::calcNumAccounts(filePath);
	//create a new pointer to an array of Accounts
	accounts = new Account[numAccounts];
	int accountNum = 0;
	string this_line;
	//reads in the account text file line by line and passes each line into the
	//parameterised constructor of an account object
	while (!accountFile.eof()){
		getline(accountFile, this_line);
		Account this_account(this_line, fileVector);
		accountNum += 1;
		//adds account to the accounts array
		accounts[accountNum - 1] = this_account;
	}
	accountFile.close();
}

//calculates the number of accounts in the account text file
int accountList::calcNumAccounts(string filePath)
{
	ifstream accountFile(filePath);
	int accountNum = 0;
	string this_line;
	while (!accountFile.eof()){
		getline(accountFile, this_line);
		accountNum += 1;	
	}
	accountFile.close();
	return accountNum;
}
//returns the number of accounts
int accountList::getNumAccounts(){
	return numAccounts;
}
// function for creating a new account
void accountList::createAccount(string filePath)
{
	ofstream accountFile(filePath, ios::in);
	if (accountFile.is_open())
	{
		string firstName;
		string lastName;
		int AccNum = getNumAccounts()+1;
		///takes user input for first name
		cout << "Please enter your first name" << endl;
		getline(cin, firstName);
		//checks the name contains only alphabetical characters
		while (valid_name(firstName) == false){
			cout << "Name must only contain letters\nPlease enter a valid name" << endl;
			getline(cin, firstName);
		}
		int i = 0;
		//converts to lowercase
		while (firstName[i]){
			firstName[i] = tolower(firstName[i]);
			i++;
		}
		///takes user input for first name
		cout << "Please enter your last name" << endl;
		getline(cin, lastName);
		//checks the name contains only alphabetical characters
		while (valid_name(lastName) == false){
			cout << "Name must only contain letters" << endl;
			getline(cin, lastName);
		}
		i = 0;
		//converts to lower case
		while (lastName[i]){
			lastName[i] = tolower(lastName[i]);
			i++;
		}
		cout << endl;
		//adds new account information to end of account information text file
		accountFile.seekp(0, ios::end);
		accountFile << endl;
		accountFile << firstName << " " << lastName << " " << AccNum;

		cout << "Account successfully created" << endl << endl;
		cout << "Your username is " << firstName + lastName << endl << endl;
		
	}
	else{ cout << "Account file failed to open" << endl; }
	accountFile.close();
}

//returns the account from the accounts array which has username that matches
//input username
Account accountList::getAccountByUser(string userName, vector<string> fileVector)
{
	accountList list("account_information.txt", fileVector);
	bool foundAccount = false;
	Account test_account;
	for (int i = 0; i < numAccounts; i++)
	{
		//compares input username to usernames of accounts in accounts array
		if (accounts[i].Account::getUserName().compare(userName) == 0){
			foundAccount = true;
			test_account = accounts[i];
			break;
		}
	}
	if (foundAccount == true){
		return test_account;
	}
	else{
		cout << "Account does not exist" << endl;
		return Account();
	}
}
//functions for checking if a string contrains only alphabetical characters
bool accountList::valid_name(string name){
	int i = 0;
	bool valid = true;
	while (name[i] && valid == true){
		if (!isalpha(name[i])){
			valid = false;
		}
		i++;
	}
	return valid;
}
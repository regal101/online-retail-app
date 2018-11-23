//Author: Patrick germaine
//main.cpp
//contains the main program loop as well as menu functions which run the majority of the code for the user interface
#include <iostream>
#include "account.h"
#include "accountList.h"
#include "product.h"
#include "productList.h"
#include "my_functions.h"
using std::fstream; using std::to_string;

//variable for storing if the user would like to login
bool logIn = false;
//variable for storing if the user has logged in
bool loggedIn = false;
//variable for storing if the user wants to exit program
bool exitProgram = false;

void startMenu(vector<string>fileVector);
void homePage(Account* current_account, vector<string> *fileVector );
void searchAndBuy(productList prodlist, Account *current_user, vector<string> *fileVector);

// Features used: smart pointers, hierachical classes, virtual functions, .h/.cpp files,
// lamda functions, ssteam, fstream, various containers, overloaded <<, static_pointer_cast

int main()
{
	fstream productFile("product_information2.txt");
	vector <string> thisFileVector;
	string this_line;
	//reads product information file line by line into a vector
	while (!productFile.eof()){
		getline(productFile, this_line);
		thisFileVector.push_back(this_line);
	}
	productFile.close();
	
	// loads in account and product informaion
	while (exitProgram == false)
	{
		//opens start menu
		startMenu(thisFileVector);
		//sets a default account to be replaced after login
		Account current_user("firstName lastName 000000", thisFileVector);
		
		if (logIn == true)
		{
			string inputUsername;
			//if an account has firstname jim and last name bob, stored in the account information tex file,
			//the input username must be jimbob
			cout << "please enter your username to login or x to return to start menu" << endl;
			getline(cin, inputUsername);
			cout << endl;
			if (inputUsername.compare("x") != 0)
			{
				//creates instance of accountList object
				accountList acclist("account_information.txt", thisFileVector);
				//creates a test user, if input username matches one of the accounts, test user is set equal to matching account
				//otherwise test user is set equal to a default account
				Account test_user = acclist.accountList::getAccountByUser(inputUsername, thisFileVector);
				//if test user is the defaukt account, user is asked to input credentials which match one the accounts in the account
				//information text file
				while (test_user.getUserName().compare("firstNamelastName") == 0)
				{
					cin.clear(); //This corrects the stream.
					cout << "Sorry, no account with the username exists\nPlease enter the correct username, or x to return to start menu" << endl;
					getline(cin, inputUsername);
					if (inputUsername.compare("x") == 0){ break; }
					cout << endl;
					test_user = acclist.accountList::getAccountByUser(inputUsername, thisFileVector);
				}
				//sets current user to test with test user if login credentials are valid
				current_user = test_user;
				if (current_user.getUserName().compare("firstNamelastName") != 0){
					loggedIn = true;
				}
				logIn = false;
			}
			else{
				logIn = false;
			}
		}
		while (loggedIn == true)
		{
			cout << "Welcome to cBay " << current_user.Account::getName() << "!" << endl << endl;
			//homepage is initiated with current user
			homePage(&current_user, &thisFileVector);
		}
	}
	//when user chooses to exit, the updated product information is written to the product information
	//text file, replacing the old data.
	productFile.open("product_information2.txt");
	if (productFile.is_open()){
		for (size_t i = 0; i < thisFileVector.size(); i++){
			productFile << thisFileVector[i] << endl;
		}
	}
	else{ cout << "Product file is closed" << endl; }
	productFile.close();
	system("pause");
	return 0;
}

void startMenu(vector<string> fileVector)
{
	//account information reloaded in start menu
	accountList accList("account_information.txt",fileVector);
	string option = choose_option("What would you like to do?", { "Login", "Create account", "Exit" });

	//sets login to true so when start menus is exited, the login menu function will run
	if (option.compare("1") == 0){
		logIn = true;
	}
	//opens create account function
	else if (option.compare("2") == 0){
		accList.accountList::createAccount("account_information.txt");
	}
	//Exits program
	else if (option.compare("3") == 0){
		exitProgram = true;
	}
}

void homePage(Account *current_user, vector<string> *fileVector)
{
	//reloads product information so if a modifications has been made, the product list will be updates
	productList prodlist(*fileVector);

	string option = choose_option("What would you like to do?", { "Search and buy", "Add listing",
																  "My listings","Purchase history",
																  "Logout" });
	//search
	if (option.compare("1") == 0){
		searchAndBuy(prodlist, current_user, fileVector);
	}
	//runs create product function
	else if (option.compare("2") == 0){
		prodlist.productList::createProduct(current_user, prodlist.checkLastProductNumber(), fileVector);
	}
	//runs function which returns current users listings
	else if (option.compare("3") == 0){
		cout << endl << "My listings" << endl << endl;
		for (auto it : current_user->Account::getMyListings()){
			it->printProductInfo();
		}
	}
	//runs functions which returns current users purchase history
	else if (option.compare("4") == 0){
		cout << endl << "My purchase history" << endl << endl;
		for (auto it : current_user->Account::returnMyBought(*fileVector)){
			
			it->printProductInfo();
		}
	}
	//sets logged in to false so homepage loop will exit
	else if (option.compare("5") == 0){
		loggedIn = false;
	}
}
//function allows users to browse and purchase products
void searchAndBuy(productList prodlist, Account *current_user, vector<string> *fileVector)
{
	vector<shared_ptr<Product>> refinedList;
	while (1)
	{
		string search_method = choose_option("Please choose an search method", { "Show all products", "Search by category", "Search by gender", "Return to Home Page" });
		if (search_method.compare("1") == 0){
			//overloaded << used to print out all products in product list
			cout << prodlist << endl;
			refinedList = prodlist.returnAllActiveProducts();
		}
		//if user chooses to search by category, user is asked to specify which category and this is then
		//passed into the returnAllCategory function.
		else if (search_method.compare("2") == 0){
			string category_choice = choose_option("Choose a category", { Product::categories });
			if (category_choice.compare("1") == 0){
				refinedList = prodlist.returnAllCategory("Top");
			}
			else if (category_choice.compare("2") == 0){
				refinedList = prodlist.returnAllCategory("Shirt");
			}
			else if (category_choice.compare("3") == 0){
				refinedList = prodlist.returnAllCategory("Jumper");
			}
			else if (category_choice.compare("4") == 0){
				refinedList = prodlist.returnAllCategory("Bottom");
			}
			else if (category_choice.compare("5") == 0){
				refinedList = prodlist.returnAllCategory("Shoe");
			}
			for (auto it : refinedList){
				it->printProductInfo();
			}
		}
		//if user chooses to search by gender, user is asked to specify which gender and this is then
		//passed into the retunrAllGender function.
		else if (search_method.compare("3") == 0){
			string gender_choice = choose_option("Which section?", { "Mens", "Womens", "Neutral" });
			if (gender_choice.compare("1") == 0){
				refinedList = prodlist.returnAllGender("M");

			}
			else if (gender_choice.compare("2") == 0){
				refinedList = prodlist.returnAllGender("F");
			}
			else if (gender_choice.compare("3") == 0){
				refinedList = prodlist.returnAllGender("N");
			}
			for (auto it : refinedList){
				it->printProductInfo();
			}
		}
		else if (search_method.compare("4") == 0){
			break;
		}
		//user is asked how they would like to order their refined search results.
		if (refinedList.size() > 0){
			string sort_method = choose_option("Please choose an option", { "Sort by price (Ascending)", "Sort by price (descending)", "Return to Home Page" });
			if (sort_method.compare("1") == 0){
				//lambda function for sorting by price
				sort(refinedList.begin(), refinedList.end(), [](shared_ptr<Product> a1, shared_ptr<Product> a2) { return a1->getPrice() < a2->getPrice(); });
				for (auto it : refinedList){
					it->printProductInfo();
				}
			}
			if (sort_method.compare("2") == 0){
				sort(refinedList.begin(), refinedList.end(), [](shared_ptr<Product> a1, shared_ptr<Product> a2) { return a1->getPrice() > a2->getPrice(); });
				for (auto it : refinedList){
					it->printProductInfo();
				}
			}
			else if (sort_method.compare("3") == 0){ break; }

			if (search_method.compare("4") != 0 && sort_method.compare("3") != 0){
				string buy_item = choose_option("What would you like to do?", { "Buy an item", "Return to Search" });
				//if the user chooses to buy item, they are asked to specify which by inputting the product number
				if (buy_item.compare("1") == 0){
					string this_item;
					cout << "Enter the product number of the item you which to purchase, e.g. 3" << endl << endl;
					getline(cin, this_item);

					while (check_if_available(prodlist.returnAllActiveProducts(), this_item) == false){
						cin.clear();
						//cin.ignore();
						cout << "Please enter a product number from one of the products in the list" << endl << endl;
						getline(cin, this_item);
					}
					cin.clear();
					bool is_yours = false;
					//check for ensuring user cant buy products they have listed.
					for (auto it : current_user->getMyListings()){
						if (it->getProductNumber() == this_item){
							cout << "You cannot buy your own product" << endl << endl;
							is_yours = true;
						}
					}
					if (is_yours == false){
						changeInfo(fileVector, this_item, 5, current_user->getUserName());
						cout << "Congractulations!, your item has been purchased.\nYou can see the details of your item in your bought items list from the home page." << endl << endl;
						break;
					}
				}
				else if (buy_item.compare("1") == 0){
					break;
				}
			}
		}
	}	
}
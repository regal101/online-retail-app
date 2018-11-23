//Author: Patrick germaine
//my_functions.cpp
#include "my_functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <locale>
#include <ctype.h>
#include "product.h"
#include "account.h"
#include "cmath" // used for trunc
using std::to_string;

//checks that a user inputs a valid option from a list of a given options
string choose_option(string message ,vector<string> option_list){
	string input;
	bool valid = false;
	cout << message << endl;
	//prints out the list of options specified
	for (size_t i = 0; i < option_list.size(); i++){
		cout << to_string(i + 1) + ". " + option_list[i] << endl;
	}
	cout << endl;
	getline(cin, input);
	//checks that the user input matches one of the possible options
	for (size_t i = 0; i < option_list.size(); i++){
		if (to_string(i + 1).compare(input) == 0){
			valid = true;
		}
	}
	//repeats until user enters an allowed option
	while (valid == false){
		cout << "invalid option, please enter one of the number from the following list" << endl << endl;
		for (size_t i = 0; i < option_list.size(); i++){
			cout << to_string(i + 1) + ". " + option_list[i] << endl;
		}
		getline(cin, input);
		for (size_t i = 0; i < option_list.size(); i++){
			if (to_string(i + 1).compare(input) == 0){
				valid = true;
			}
		}
		cin.clear(); //This corrects the stream.
	}
	// returns the option
	return input;
}

//splits a string of words by a given delimiter into a vector and returns vector
vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}
// edits the information associated with a given product
void changeInfo(vector<string> *fileVector, string productNum, int attributeNum, string newInfo){
	auto index = 0;
	//finds the location of the product whos info is to be edited
	auto it = std::find(fileVector->begin(), fileVector->end(), productNum);
	if (it == fileVector->end()){
		cout << "Product does not exist" << endl;
	}
	//determined the vector index of the info to be edited
	else{
		index = std::distance(fileVector->begin(), it);
	}
	// replaces old info with new info at specified position
	(*fileVector)[index + attributeNum] = newInfo;
	
}
//checks if a product has a buyer
bool check_if_available(vector<shared_ptr<Product>> products, string this_num){
	bool is_available = false;
	for (auto it : products){
		if (it->getProductNumber().compare(this_num) == 0){
			if (it->getBuyer().compare("x") == 0){
				is_available = true;
			}
		}
	}
	return is_available;
}
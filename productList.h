//Author: Patrick germaine
//productList.h
//contains the productList class. parameterised contructor reads in product information from seperate text file and stores in in the
//data member "products" which is a vector of pointers in product objects. Also contains functions for sorting and manipulating
//the products vector.
#ifndef PRODUCTTLIST_H
#define PRODUCTTLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <locale>
#include <memory>
#include <ctype.h> //for toupper
#include "product.h"
#include "my_functions.h"
#include "cmath" // used for trunc
using std::ios;
using std::to_string;
using std::distance;
using std::ostream;

class productList
{
	friend ostream & operator<<(ostream &os, const productList &list);
	friend class Account;
public:
	//parameterised constructor
	productList(vector<string> fileVector);
	//destructor
	~productList(){}
	//function to add products
	void createProduct(Account *account, string, vector<string> *fileVector);
	//function which checks the product number of the last product in the database
	string checkLastProductNumber();
	//functions which return sublists of products according to particular
	//search criteria
	vector<shared_ptr<Product>> returnAllProducts();
	vector<shared_ptr<Product>> returnAllActiveProducts();
	vector<shared_ptr<Product>> returnAllCategory(string category);
	vector<shared_ptr<Product>> returnAllGender(string category);
	//checks that string contrains only alphanumerical characters
	bool productList::valid_product_name(string name);
	
private:
	//vector for storing product type objects
	vector<shared_ptr<Product>> products;
	int numProducts;
};

#endif
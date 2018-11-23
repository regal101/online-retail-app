//Author: Patrick germaine
//my_functions.h
#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H
//contains functions which are used throughout the program and do not belong to any particular class
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <locale>
#include <ctype.h>
#include "account.h"
#include "cmath" // used for trunc
//checks that a user inputs a valid option from a list of a given options
string choose_option(string message, vector<string> option_list);
//splits a string of words by a given delimiter into a vector and returns vector
vector<string> split(const string &s, char delim);
// edits the information associated with a given product
void changeInfo(vector<string>*, string productNum, int attributeNum, string newInfo);
//checks if a product has a buyer
bool check_if_available(vector<shared_ptr<Product>>, string);
#endif
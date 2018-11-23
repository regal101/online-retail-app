//Author: Patrick germaine
//product.h
//contains the class "product" for storing information on all products such as name, price and seller. Also has classes derived from
//the product class, these are the top, bottom and shoe classes. A shirt and jumper class is derived from the top class. These contain
//data members for storing information specific to their respective category of product, such as shoe size for shoe.
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <typeinfo> // for typeid function
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector; using std::list;

//base class for general products
class Product
{
public:
	//product default constructor
	Product();
	//product virtual destrcutor
	virtual ~Product(){};

	// Getters for returning private data members of each product class
	string getProductNumber();
	string getName();
	double getPrice();
	string getDescription();
	string getSeller();
	string getGender();
	string getSize();
	string getBuyer();
	//setters for setting the data members of each product class
	void setProductNumber(string);
	void setName(string);
	void setPrice(double);
	void setDescription(string);
	void setSeller(string);
	void setGender(string);
	void setSize(string);
	void setBuyer(string);

	//list of product categories
	static const vector<string> categories;

	virtual void printProductInfo(){};

protected:
	//private data members associated with each product
	string productNumber;
	string name;
	double price;
	string description;
	string seller;
	string gender;
	string size;
	string buyer;
};
//derived class for top products
class Top: public Product
{
public:
	Top() : Product(){}
	virtual ~Top(){}
	virtual void printProductInfo();
protected:
};
//derived class for shirt products
class Shirt : public Top
{
public:
	Shirt() : Top(){}
	~Shirt(){}
	void printProductInfo() ;
	//returns sleeve length
	string getSleeveLength();
	//sets sleeve length
	void setSleeveLength(string);
protected:
	//data member for sleeve length
	string sleeveLength;
};

class Jumper : public Top
{
public:
	Jumper() : Top(){}
	~Jumper(){}
	void printProductInfo() ;
	//returns material
	string getMaterial();
	//sets material
	void setMaterial(string);

	static const vector<string> materials;
protected:
	//data member for material
	string material;
};

class Bottom : public Product
{
public:
	Bottom() : Product(){}
	~Bottom(){};
	void printProductInfo() override ;
	// returns measurements
	int getWaist();
	int getLength();
	//sets measurements
	void setLength(int);
	void setWaist(int);
protected:
	//data members for measurements
	int length;
	int waist;
};

class Shoe: public Product
{
public:
	Shoe() : Product(){}
	~Shoe(){};

	void printProductInfo() override;
	static const vector<string> shoe_types;
	static const vector<string> shoe_sizes;
	// returns shoe type
	string getType();
	//sets shoe type
	void setType(string);
protected:
	//data member for shoe type
	string type;
};

#endif
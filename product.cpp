//Author: Patrick germaine
//product.cpp
#include "product.h"

const vector<string> Shoe::shoe_types = { "casual", "formal", "running", "boots" };
const vector<string> Product::categories = { "top", "shirt", "jumper", "bottom", "shoe" };
const vector<string> Shoe::shoe_sizes = { "size 1", "size 2", "size 3", "size 4", "size 5", "size 6", "size 7", "size 8", "size 9", "size 10", "size 11", "size 12" };
const vector<string> Jumper::materials = { "wool", "cotton" };

Product::Product(){
	name = "None";
	price = 0;
	description = "None";
	seller = "Seller Name";
	buyer = "x";
}

// Getters for returning private data members of each product and drived class objects
string Product::getProductNumber(){ return productNumber; }
string Product::getName(){return name;}
double Product::getPrice(){return price;}
string Product::getDescription(){return description;}
string Product::getSeller(){return seller;}
string Product::getGender(){return gender;}
string Product::getSize(){return size;}
string Product::getBuyer(){return buyer;}
int Bottom::getLength(){return length;}
int Bottom::getWaist(){return waist;}
string Shoe::getType(){return type;}
string Shirt::getSleeveLength(){return sleeveLength;}
string Jumper::getMaterial(){return material;}
//setters for setting the data members of each product and derived class objects
void Product::setProductNumber(string newProductNumber){productNumber = newProductNumber;}
void Product::setName(string newName){name = newName;}
void Product::setPrice(double newPrice){price = newPrice;}
void Product::setDescription(string newDescription){description = newDescription;}
void Product::setSeller(string newSeller){seller = newSeller;}
void Product::setGender(string newGender){gender = newGender;}
void Product::setSize(string newSize){size = newSize;}
void Product::setBuyer(string newBuyer){buyer = newBuyer;}
void Bottom::setLength(int newLength){length = newLength;}
void Bottom::setWaist(int newWaist){waist = newWaist;}
void Shoe::setType(string newType){	type = newType;}
void Shirt::setSleeveLength(string newSleeveLength){	sleeveLength = newSleeveLength;}
void Jumper::setMaterial(string newMaterial){material = newMaterial;}

// functions for printing out the attributes of top,shirt,jumper,bottom, and shoe
void Top::printProductInfo(){
	cout << "Product number: " << this->getProductNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "price: " << this->getPrice() << endl;
	cout << "Description: " << this->getDescription() << endl;
	cout << "Seller: " << this->getSeller() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "Size: " << this->getSize() << endl << endl;
}
void Shirt::printProductInfo(){
	cout << "Product number: " << this->getProductNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "price: " << this->getPrice() << endl;
	cout << "Description: " << this->getDescription() << endl;
	cout << "Seller: " << this->getSeller() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "Size: " << this->getSize() << endl;
	cout << "Sleeve Length: " << this->getSleeveLength() << endl << endl;
}
void Jumper::printProductInfo(){
	cout << "Product number: " << this->getProductNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "price: " << this->getPrice() << endl;
	cout << "Description: " << this->getDescription() << endl;
	cout << "Seller: " << this->getSeller() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "Size: " << this->getSize() << endl;
	cout << "Material: " << this->getMaterial() << endl << endl;
}
void Bottom::printProductInfo(){
	cout << "Product number: " << this->getProductNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "price: " << this->getPrice() << endl;
	cout << "Description: " << this->getDescription() << endl;
	cout << "Seller: " << this->getSeller() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "waist: " << this->getWaist() << endl;
	cout << "length: " << this->getLength() << endl << endl;
}
void Shoe::printProductInfo(){
	cout << "Product number: " << this->getProductNumber() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "price: " << this->getPrice() << endl;
	cout << "Description: " << this->getDescription() << endl;
	cout << "Seller: " << this->getSeller() << endl;
	cout << "Gender: " << this->getGender() << endl;
	cout << "Size: " << this->getSize().substr(1, this->getSize().size() - 1) << endl;
	cout << "Type: " << this->getType() << endl << endl;
}


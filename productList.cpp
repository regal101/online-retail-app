//Author: Patrick germaine
//productlist.cpp
#include "productList.h"
#include "account.h"
#include "product.h"
#include "my_functions.h"
using std::to_string;
using std::distance;
using std::shared_ptr;

productList::productList(vector<string> fileVector)
{
	//counters for counting the number of products which have been read and which line of the file is being read
	int productNum = 0;
	int lineNum = 0;
	for (auto it: fileVector){
		//auto this_product = std::make_shared<Product>();
		if (it.compare("'PRODUCT'top") == 0)
		{
			//creates a shared pointer to a top
			auto this_top = std::make_shared<Top>();
			//sets the top data members by reading them from the product file
			this_top->Product::setProductNumber(fileVector[lineNum +1]);
			this_top->Product::setName(fileVector[lineNum + 2]);
			this_top->Product::setPrice(stod(fileVector[lineNum + 3]));
			this_top->Product::setDescription(fileVector[lineNum + 4]);			
			this_top->Product::setSeller(fileVector[lineNum + 5]);
			this_top->Product::setBuyer(fileVector[lineNum + 6]);
			this_top->Product::setGender(fileVector[lineNum + 7]);			
			this_top->Product::setSize(fileVector[lineNum + 8]);			

			products.push_back(this_top);
			productNum += 1;

		}
		else if (it.compare("'PRODUCT'shirt") == 0)
		{
			//creates a shared pointer to a shirt
			auto this_shirt = std::make_shared<Shirt>();
			//sets the shirt data members by reading them from the product file
			this_shirt->Product::setProductNumber(fileVector[lineNum + 1]);
			this_shirt->Product::setName(fileVector[lineNum + 2]);
			this_shirt->Product::setPrice(stod(fileVector[lineNum + 3]));
			this_shirt->Product::setDescription(fileVector[lineNum + 4]);
			this_shirt->Product::setSeller(fileVector[lineNum + 5]);
			this_shirt->Product::setBuyer(fileVector[lineNum + 6]);
			this_shirt->Product::setGender(fileVector[lineNum + 7]);
			this_shirt->Product::setSize(fileVector[lineNum + 8]);
			this_shirt->Shirt::setSleeveLength(fileVector[lineNum + 9]);

			products.push_back(this_shirt);
			productNum += 1;

		}
		else if (it.compare("'PRODUCT'jumper") == 0)
		{
			//creates a shared pointer to a jumper
			auto this_jumper = std::make_shared<Jumper>();
			//sets the jumper data members by reading them from the product file
			this_jumper->Product::setProductNumber(fileVector[lineNum + 1]);
			this_jumper->Product::setName(fileVector[lineNum + 2]);
			this_jumper->Product::setPrice(stod(fileVector[lineNum + 3]));
			this_jumper->Product::setDescription(fileVector[lineNum + 4]);
			this_jumper->Product::setSeller(fileVector[lineNum + 5]);
			this_jumper->Product::setBuyer(fileVector[lineNum + 6]);
			this_jumper->Product::setGender(fileVector[lineNum + 7]);
			this_jumper->Product::setSize(fileVector[lineNum + 8]);
			this_jumper->Jumper::setMaterial(fileVector[lineNum + 9]);

			products.push_back(this_jumper);
			productNum += 1;

		}
		else if (it.compare("'PRODUCT'bottom") == 0)
		{
			//creates a shared pointer to a bottom
			auto this_bottom = std::make_shared<Bottom>();
			//sets the bottom data members by reading them from the product file
			this_bottom->Product::setProductNumber(fileVector[lineNum + 1]);
			this_bottom->Product::setName(fileVector[lineNum + 2]);
			this_bottom->Product::setPrice(stod(fileVector[lineNum + 3]));
			this_bottom->Product::setDescription(fileVector[lineNum + 4]);
			this_bottom->Product::setSeller(fileVector[lineNum + 5]);
			this_bottom->Product::setBuyer(fileVector[lineNum + 6]);
			this_bottom->Product::setGender(fileVector[lineNum + 7]);
			this_bottom->Product::setSize(fileVector[lineNum + 8]);
			string delim = ",";
			vector<string> measurements = split(fileVector[lineNum + 8], delim[0]);
			this_bottom->Bottom::setLength(stoi(measurements[0]));
			this_bottom->Bottom::setWaist(stoi(measurements[1]));

			products.push_back(this_bottom);
			productNum += 1;

		}

		else if (it.compare("'PRODUCT'shoe") == 0)
		{
			//creates a shared pointer to a shoe
			auto this_shoe = std::make_shared<Shoe>();
			//sets the shoe data members by reading them from the product file
			this_shoe->Product::setProductNumber(fileVector[lineNum + 1]);
			this_shoe->Product::setName(fileVector[lineNum + 2]);
			this_shoe->Product::setPrice(stod(fileVector[lineNum + 3]));
			this_shoe->Product::setDescription(fileVector[lineNum + 4]);
			this_shoe->Product::setSeller(fileVector[lineNum + 5]);
			this_shoe->Product::setBuyer(fileVector[lineNum + 6]);
			this_shoe->Product::setGender(fileVector[lineNum + 7]);
			this_shoe->Product::setSize(fileVector[lineNum + 8]);
			this_shoe->Shoe::setType(fileVector[lineNum + 9]);

			products.push_back(this_shoe);
			productNum += 1;

		}
		lineNum += 1;	
	}	
}

string productList::checkLastProductNumber(){
	return products.back()->Product::getProductNumber();
}
//function which takes user inputs and creates a product based on the information based on the input
//this information is the written to the file and the product is added to the product list.
void productList::createProduct(Account *account, string lastProdNum, vector<string> *fileVector)
{
	//general attributes for all clothing are set here first
	//choose category
	string category_choice = choose_option("Please select one of the following categories e.g 2", Product::categories);
	if (category_choice.compare("1") == 0){ category_choice = "top"; }
	else if (category_choice.compare("2") == 0){ category_choice = "shirt"; }
	else if (category_choice.compare("3") == 0){ category_choice = "jumper"; }
	else if (category_choice.compare("4") == 0){ category_choice = "bottom"; }
	else if (category_choice.compare("5") == 0){ category_choice = "shoe"; }

	

	string productNum = to_string(stoi(lastProdNum) + 1);

	//enter title for listing
	string Name;
	cout << "Please enter the name of your product" << endl;
	getline(cin, Name);
	while (valid_product_name(Name) == false){
		cout << "The product name can only contain letters and numbers\nPlease enter a valid name" << endl;
		getline(cin, Name);
	}

	//enter price for listing
	double price;
	cout << "Please enter a price for your product e.g 23.22" << endl;
	cin >> price;
	
	while (cin.fail() == true || price < 0.01)
	{
		cin.clear(); //This corrects the stream.
		cin.ignore();
		cout << "Please enter a valid price to sell at" << endl;
		cin >> price;
	};

	//enter description for listing
	cin.ignore();
	string description;
	cout << "Please enter a short description of your product" << endl;
	getline(cin, description);

	//seller is set using login credentials
	string seller = account->Account::getUserName();

	//enter gender for clothing
	string gender;
	cout << "Please specify whether the item is for males (M), females (F) or neutral (N)" << endl;
	getline(cin, gender);
	while (gender.compare("M") != 0 && gender.compare("m") != 0 && gender.compare("F") != 0 && gender.compare("f") != 0 && gender.compare("N") != 0 && gender.compare("n") != 0){
		cin.clear(); //This corrects the stream.
		cout << "Please enter M, F or N to specify male, female or neutral" << endl;
		getline(cin, gender);
	}
	gender[0] = toupper(gender[0]);

	// specialised attributes are set here

	//set top specialised attributes
	string size;
	if (category_choice.compare("top") == 0 || category_choice.compare("shirt") == 0 || category_choice.compare("jumper") == 0)
	{
		cout << "Please specify a size: small (S), medium (M) or large (L)," << endl;
		getline(cin, size);
		while (size.compare("S") != 0 && size.compare("s") != 0 && size.compare("M") != 0 && size.compare("m") != 0 && size.compare("L") != 0 && size.compare("l") != 0)
		{
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Please enter S, M or L to specify small, medium or large" << endl;
			getline(cin, size);
		}
		size[0] = toupper(size[0]);
		// product attributes are added to the file vector contain information on all products
		fileVector->push_back("'PRODUCT'" + category_choice); fileVector->push_back(productNum); fileVector->push_back(Name); fileVector->push_back(to_string(price));
		fileVector->push_back(description); fileVector->push_back(seller); fileVector->push_back("x"); fileVector->push_back(gender); fileVector->push_back(size);
		if (category_choice.compare("top") == 0){
			// product is created and is added to the myListings data member of the account being used
			fileVector->push_back("-");
			auto newTop = std::make_shared<Top>();
			newTop->setProductNumber(productNum); newTop->setName(Name); newTop->setPrice(price); newTop->setDescription(description); newTop->setSeller(seller); newTop->setBuyer("x");
			newTop->setGender(gender); newTop->setSize(size);
			account->myListings.push_back(newTop);
		}
		else if (category_choice.compare("shirt") == 0){
			string sleeveLength = choose_option("Please choose a sleeve length", { "short", "long" });
			if (sleeveLength.compare("1") == 0){ sleeveLength = "short"; }
			if (sleeveLength.compare("2") == 0){ sleeveLength = "long"; }
			fileVector->push_back(sleeveLength); fileVector->push_back("-");
			// product is created and is added to the myListings data member of the account being used
			auto newShirt = std::make_shared<Shirt>();
			newShirt->setProductNumber(productNum); newShirt->setName(Name); newShirt->setPrice(price); newShirt->setDescription(description); newShirt->setSeller(seller); newShirt->setBuyer("x");
			newShirt->setGender(gender); newShirt->setSize(size); newShirt->setSleeveLength(sleeveLength);
			account->myListings.push_back(newShirt);
		}
		else if (category_choice.compare("jumper") == 0){
			string material = choose_option("Please choose a material", Jumper::materials);
			material = Jumper::materials[stoi(material) - 1];
			fileVector->push_back(material); fileVector->push_back("-");
			// product is created and is added to the myListings data member of the account being used
			auto newJumper = std::make_shared<Jumper>();
			newJumper->setProductNumber(productNum); newJumper->setName(Name); newJumper->setPrice(price); newJumper->setDescription(description); newJumper->setSeller(seller); newJumper->setBuyer("x");
			newJumper->setGender(gender); newJumper->setSize(size); newJumper->setMaterial(material);
			account->myListings.push_back(newJumper);
		}
	}

	// set bottom specialised attributes
	else if (category_choice.compare("bottom") == 0)
	{
		cout << "Please specify the length and waist size in inches e.g enter 30,32 for a length of 30 inches and waist of 32 inches " << endl;
		getline(cin, size);
		bool valid = false;
		vector<string> measurements;
		string delim = ",";
		while (valid == false)
		{
			measurements = split(size, delim[0]);
			valid = true;
			for (size_t i = 0; i < measurements.size(); i++){
				try{stoi(measurements[i]);}
				catch (...){
					cout << "invalid size input" << endl;
					valid = false;
				}
			}
			if (measurements.size() != 2){ valid = false; }
			if (valid == false){
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				cout << "Please enter length and waist measurements e.g enter 30,32 for a length of 30 inches and waist of 32 inches" << endl;
				getline(cin, size);
			}
		}
		// product attributes are added to the file vector contain information on all products
		fileVector->push_back("'PRODUCT'" + category_choice); fileVector->push_back(productNum); fileVector->push_back(Name); fileVector->push_back(to_string(price));
		fileVector->push_back(description); fileVector->push_back(seller); fileVector->push_back("x"); fileVector->push_back(gender); fileVector->push_back(size);
		fileVector->push_back("-");
		measurements = split(size, delim[0]);
		// product is added to the myListings data member of the account being used
		auto newBottom = std::make_shared<Bottom>();
		newBottom->setProductNumber(productNum); newBottom->setName(Name); newBottom->setPrice(price); newBottom->setDescription(description); newBottom->setSeller(seller);
		newBottom->setBuyer("x"); newBottom->setGender(gender); newBottom->setSize(size); newBottom->setLength(stoi(measurements[0])); newBottom->setWaist(stoi(measurements[1]));
		account->myListings.push_back(newBottom);
		cout << "Product successfully created" << endl << endl;
	}

	//set shoe specialised attibributes
	else if (category_choice.compare("shoe") == 0){
		string size = choose_option("Please enter a shoe size e.g. 7", Shoe::shoe_sizes);
		size = "s" + size;
		string shoe_type = choose_option("Please choose a category", Shoe::shoe_types);
		shoe_type = Shoe::shoe_types[stoi(shoe_type) - 1];
		// product attributes are added to the file vector contain information on all products
		fileVector->push_back("'PRODUCT'" + category_choice); fileVector->push_back(productNum); fileVector->push_back(Name); fileVector->push_back(to_string(price));
		fileVector->push_back(description); fileVector->push_back(seller); fileVector->push_back("x"); fileVector->push_back(gender); fileVector->push_back(size);
		fileVector->push_back(shoe_type); fileVector->push_back("-");
		// product is added to the myListings data member of the account being used
		auto newShoe = std::make_shared<Shoe>();
		newShoe->setProductNumber(productNum); newShoe->setName(Name); newShoe->setPrice(price); newShoe->setDescription(description); newShoe->setSeller(seller);
		newShoe->setBuyer("x"); newShoe->setGender(gender); newShoe->setSize(size); newShoe->setType(shoe_type);
		account->myListings.push_back(newShoe);
	}
	cout << "Product successfully created" << endl << endl;
}


//overloaded << operator to print out product info
ostream & operator<<(ostream &os, const productList &list){
	for (auto it : list.products){
		if (it->getBuyer().compare("x") == 0){
			os << "Product number: " << it->getProductNumber() << endl;
			os << "Name: " << it->getName() << endl;
			os << "Price: " << it->getPrice() << endl;
			os << "Description: " << it->getDescription() << endl;
			os << "Seller: " << it->getSeller() << endl;
			os << "Gender: " << it->getGender() << endl;
			os << "Size: " << it->getSize() << endl;
			string class_type = typeid(*it).name();
			if (class_type.compare("class Bottom") == 0){
				os << "Length: " << std::static_pointer_cast<Bottom>(it)->getLength() << endl;
				os << "Waist: " << std::static_pointer_cast<Bottom>(it)->getWaist() << endl << endl;
			}
			else if (class_type.compare("class Shoe") == 0){
				os << "Type: " << std::static_pointer_cast<Shoe>(it)->getType() << endl << endl;
			}
			else if (class_type.compare("class Shirt") == 0){
				os << "Sleeve Length: " << std::static_pointer_cast<Shirt>(it)->getSleeveLength() << endl << endl;
			}
			else if (class_type.compare("class Jumper") == 0){
				os << "Material: " << std::static_pointer_cast<Jumper>(it)->getMaterial() << endl << endl;
			}
		}
	}
	return os;
}
//returns all products
vector<shared_ptr<Product>> productList::returnAllProducts(){
	return productList::products;
}
// returns all active products, i.e. products without a buyer
vector<shared_ptr<Product>> productList::returnAllActiveProducts(){
	vector<shared_ptr<Product>> subList;
	for (auto it : products){
		if (it->getBuyer().compare("x") == 0){
			subList.push_back(it);
		}
	}
	return subList;
}
// returns all products whos category matches input category
vector<shared_ptr<Product>> productList::returnAllCategory(string category){
	vector<shared_ptr<Product>> subList;
	for (auto it : products){
		string class_type = typeid(*it).name();
		if (class_type.compare("class " + category) == 0 && it->getBuyer().compare("x") == 0){
			subList.push_back(it);
		}
	}
	return subList;
}
// returns all products whos gender matches input gender
vector<shared_ptr<Product>> productList::returnAllGender(string gender){
	vector<shared_ptr<Product>> subList;
	for (auto it : products){
		if (!it->getGender().compare(gender) && it->getBuyer().compare("x") == 0){
			subList.push_back(it);
		}
	}
	return subList;
}
// checks that the input product name contains only alphanumerical characters
bool productList::valid_product_name(string name){
	int i = 0;
	bool valid = true;
	while (name[i] && valid == true){
		if (  !isalpha(name[i]) && !isdigit(name[i]) && !isspace(name[i])){
			valid = false;
		}
		i++;
	}
	return valid;
}
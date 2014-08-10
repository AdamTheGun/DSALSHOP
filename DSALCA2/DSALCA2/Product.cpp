
#include "Product.h"

using namespace std;

//Default Constructor
Product::Product(void)
{
	ProdTitle = "";
	ProdDescription = "";
	ProdCost = -1.0f;
	ProdYear = -1;
}

Product::Product(string inTitle,string inDescription,int inID,float inCost,string inYear)
{
	ProdTitle = inTitle;
	ProdDescription = inDescription;
	ProdCost = inCost;
	ProdYear = inYear;
	ProdID = inID;
}

//Default Destructor
Product::~Product(void)
{

}

void Product::printTitle()
{
	cout << "Title: " << ProdTitle << endl;
}

void Product::printDescription()
{
	cout << "Description: " << ProdDescription << endl;
}

void Product::printYear()
{
	cout << "Year: " << ProdYear << endl;
}

void Product::printCost()
{
	cout << "Cost: " << ProdCost << endl;
}

void Product::printID()
{
	cout << "ID: " << ProdID << endl;
}

void Product::printProdInfo()
{
	printTitle();
	printDescription();
	printCost();
	printYear();
	printID();
}

int Product::getID() const
{
	return ProdID;
}

float Product::getCost() const
{
	return ProdCost;
}

string Product::getTitle() const
{
	return ProdTitle;
}
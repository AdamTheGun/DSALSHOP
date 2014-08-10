#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Product
{
public:
	Product(void);
	Product(string,string,int,float = -1.0f,string = "");
	virtual ~Product(void);

	void printTitle();
	void printDescription();
	void printCost();
	void printYear();
	void printID();
	void virtual printProdInfo() = 0;

<<<<<<< HEAD
	int getID();
	float getCost();
	string getTitle();
	string getDescription();
=======
	int getID() const;
	float getCost() const;
	string getTitle() const;
>>>>>>> 5ccba16738a5aefcc897fb33fa048521d122a33b

protected:
	string ProdTitle;
	string ProdDescription;
	float ProdCost;
	string ProdYear;
	int ProdID;
};


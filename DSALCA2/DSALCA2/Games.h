#pragma once
#include "product.h"
class Games :
	public Product
{
public:
	Games(void);
	Games(string,string,string,string,string,int,int = 0,int = 0,int = 0,int = 0,int = 0, float= -1.0f,int = -1);
	~Games(void);

	void printGenre();
	void printDeveloper();
	void printPublisher();
	void printRating();
	void printProdInfo();

	void calculateAvgRating();
	float getAvgRating();
	string getPublisher();
	string getDeveloper();
	string getYear();
private:
	string ProdGenre;
	string ProdDeveloper;
	string ProdPublisher;
	list<int> ProdRating;
	float averageRating;
};


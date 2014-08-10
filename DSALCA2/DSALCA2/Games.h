#pragma once
#include "product.h"
class Games :
	public Product
{
public:
	Games(void);
	Games(string,string,string,string,string,int,int = 0,int = 0,int = 0,int = 0,int = 0, float= -1.0f,string = "");
	~Games(void);

	void printGenre();
	void printDeveloper();
	void printPublisher();
	void printRating();
	void printProdInfo();

	void calculateAvgRating();
	float getAvgRating();
	string getPublisher() const;
	string getDeveloper() const;
	string getYear() const;
	string getGenre();
	int getStarRating(int);
	
	
private:
	string ProdGenre;
	string ProdDeveloper;
	string ProdPublisher;
	list<int> ProdRating;
	float averageRating;
	int ratingOneStar;
	int ratingTwoStar;
	int ratingThreeStar;
	int ratingFourStar;
	int ratingFiveStar;
};


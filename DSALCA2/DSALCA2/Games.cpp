#include "Games.h"


Games::Games(void)
{
}

Games::Games(string inTitle,string inDescription,string inGenre,string inDeveloper,string inPublisher,int inID,int inRatingOneStar,int inRatingTwoStar
	,int inRatingThreeStar,int inRatingFourStar,int inRatingFiveStar,float inCost,string inYear)
	: ratingOneStar(inRatingOneStar), ratingTwoStar(inRatingTwoStar), ratingThreeStar(inRatingThreeStar), ratingFourStar(inRatingFourStar), ratingFiveStar(inRatingFiveStar)
{
	ProdGenre = inGenre;
	ProdDeveloper = inDeveloper;
	ProdPublisher = inPublisher;

	ProdRating.push_back(inRatingOneStar);
	ProdRating.push_back(inRatingTwoStar);
	ProdRating.push_back(inRatingThreeStar);
	ProdRating.push_back(inRatingFourStar);
	ProdRating.push_back(inRatingFiveStar);
	calculateAvgRating();

	ProdTitle = inTitle;
	ProdDescription = inDescription;
	ProdCost = inCost;
	ProdYear = inYear;
	ProdID = inID;
}


Games::~Games(void)
{
}

void Games::printGenre()
{
	cout << "Genre: " << ProdGenre << endl;
}

void Games::printDeveloper()
{
	cout << "Developer: " << ProdDeveloper << endl;
}

void Games::printRating()
{
	list<int>::iterator GameItor = ProdRating.begin();
	list<int>::iterator GameEnd = ProdRating.end();
	
	for(int count = 1;GameItor!=GameEnd;GameItor++)
	{
		cout  << count << "-Star: " << *GameItor << endl;
		count++;
	}
	cout << "Average Rating: ";
	printf("%.2f",averageRating);
	cout << endl << endl;
}

void Games::printPublisher()
{
	cout << "Publisher: " << ProdPublisher << endl;
}

void Games::printProdInfo()
{
	Product::printProdInfo();
	printGenre();
	printDeveloper();
	printPublisher();
	printRating();
}

void Games::calculateAvgRating()
{
	float numOfRatings = 0.0f;
	float totalRatingNum = 0.0f;
	list<int>::iterator GameItor = ProdRating.begin();
	list<int>::iterator GameEnd = ProdRating.end();

	for(float count = 1;GameItor!=GameEnd;GameItor++)
	{
		numOfRatings+=*GameItor;
		totalRatingNum += (count * *GameItor);
		count++;
	}
	averageRating = (totalRatingNum/numOfRatings);
}

string Games::getDeveloper() const
{
	return ProdDeveloper;
}

string Games::getPublisher() const
{
	return ProdPublisher;
}

string Games::getYear() const
{
	return ProdYear;
}

string Games::getGenre()
{
	return ProdGenre;
}

int Games::getStarRating(int num)
{
	switch(num)
	{
	case 1: return ratingOneStar;
		break;
	case 2: return ratingTwoStar;
		break;
	case 3: return ratingThreeStar;
		break;
	case 4: return ratingFourStar;
		break;
	case 5: return ratingFiveStar;
		break;
	}
}
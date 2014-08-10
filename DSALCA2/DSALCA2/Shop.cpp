#include "Shop.h"


Shop::Shop(void)
{
	string inTitle, inDescription, inGenre, inDeveloper, inPublisher,inYear;
	int inID, inRatingOneStar, inRatingTwoStar, inRatingThreeStar, inRatingFourStar, inRatingFiveStar;
	float inCost;

	string tempS;
	ifstream in("gameList.txt");
	while(getline(in, inTitle, ','))
	{
		inTitle.erase(remove(inTitle.begin(), inTitle.end(), '\n'), inTitle.end());

		getline(in, inDescription, ',');
		getline(in, inGenre, ',');
		getline(in, inDeveloper, ',');
		getline(in, inPublisher, ',');

		getline(in, tempS, ',');
		inID = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inRatingOneStar = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inRatingTwoStar = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inRatingThreeStar = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inRatingFourStar = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inRatingFiveStar = (int)atof(tempS.c_str());

		getline(in, inYear, ',');

		getline(in, tempS, ',');
		inCost = (float)atof(tempS.c_str());

		

		Games* game = new Games(inTitle, inDescription, inGenre, inDeveloper, inPublisher,
								 inID, inRatingOneStar, inRatingTwoStar, inRatingThreeStar,
								 inRatingFourStar, inRatingFiveStar, inCost, inYear);
		
		AllGames.push_back(game);
	}
}


Shop::~Shop(void)
{
}

void Shop::loadGame()
{	
	cout << "===========================================================================" << endl;
	cout << "====================WELCOME TO AK-DUO VIDEO GAMES STORE====================" << endl;
	cout << "===========================================================================" << endl << endl;

	bool check = false;
	string temp;
	while(!check){
		cout << "Are you a new user? (Y/N)" << endl;
		
		cin >> temp;
		/*
		To be used IF we are using file reading and writing
		Currently there is no implementation
		*/
		if(temp == "Y" || temp == "y")
		{
			check = true;
		}
		else if(temp == "N" || temp == "n")
		{
			check = true;
		}
		else
		{
			cout << endl << "Invalid Input! Please try again." << endl << endl;
		}
	}

	cout << endl << "Please enter your username:  ";
	cin >> temp;

	if(temp == "Admin")
	{
		currentUser = "Admin";
	}
	else
	{
		currentUser = "Shopper";
		Shoppers.push_back(new Shopper(temp,rand()));
	}
	mainMenu();
}	

void Shop::mainMenu()
{
	if(currentUser == "Shopper")
	{
		Shoppers.front()->shopperMainMenu(AllGames);
	}

}

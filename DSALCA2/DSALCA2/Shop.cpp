#include "Shop.h"


Shop::Shop(void)
{
}


Shop::~Shop(void)
{
}

void Shop::loginScreen()
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

	}
	else
	{
		Shoppers.push_back(new Shopper(temp,rand()));
		mainMenu();
	}
}	

void Shop::mainMenu()
{
	int input;
	input = Shoppers.front()->shopperMainMenu();
	switch(input)
	{
		case 1:Shoppers.front()->viewGames(AllGames);
			break;
		case 2:Shoppers.front()->searchGames(AllGames);
			break;
		case 3:
			break;
		case 4:
			break;
	}
}

void Shop::setGameLibrary()
{
	string inTitle, inDescription, inGenre, inDeveloper, inPublisher;
	int inID, inRatingOneStar, inRatingTwoStar, inRatingThreeStar, inRatingFourStar, inRatingFiveStar, inYear;
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

		getline(in, tempS, ',');
		inYear = (int)atof(tempS.c_str());

		getline(in, tempS, ',');
		inCost = (float)atof(tempS.c_str());

		AllGames.push_back(Games(inTitle, inDescription, inGenre, inDeveloper, inPublisher,
								 inID, inRatingOneStar, inRatingTwoStar, inRatingThreeStar,
								 inRatingFourStar, inRatingFiveStar, inYear, inCost));
	}
}

void Shop::displayAllGames()
{
	cout << "List of Games" << endl;

	int num = 1;
	Games g;
	list<Games>::iterator GameItor = AllGames.begin();
	list<Games>::iterator GameEnd = AllGames.end();
	for(;GameItor != GameEnd; GameItor++)
	{
		cout << num << ". " << GameItor->getTitle() << endl;
		num++;
	}

	cout << endl;
}
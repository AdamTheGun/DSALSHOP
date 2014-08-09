#include "Shop.h"


Shop::Shop(void)
{
	Games game1 = Games("Hitman","Kill people as hitman","Stealth","IO Interactive","Square Enix",1,432,352,34,3532,1242,59.99,"2012");
	Games game2 = Games("Bioshock","BioShock is a first-person shooter with role-playing game customization and stealth elements, and is similar to System Shock 2.",
		"FPS","2K Boston","2K Games",2,123,345,53,1040,2403,29.99,"2007");
	Games game3 = Games("Mafia 2","Vito Scaletta has started to make a name for himself on the streets of Empire Bay as someone who can be trusted to get a job done.",
		"Action","2K Czech","2K Games",3,534,354,234,2342,2411,29.99,"2010");
	Games game4 = Games("Mount&Blade Warband","n a land torn asunder by incessant warfare, it is time to assemble your own band of hardened warriors and enter the fray. Lead your men into battle, expand your realm, and claim the ultimate prize: the throne of Calradia!",
		"Action","TalesWold Entertainment","Paradox Interactive",4,132,423,24,411,1244);
	AllGames.push_back(game1);
	AllGames.push_back(game2);
	AllGames.push_back(game3);
	AllGames.push_back(game4);
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
<<<<<<< HEAD
		Shoppers.front()->shopperMainMenu(&AllGames);
		
=======
		cout << num << ". " << GameItor->getTitle() << endl;
		num++;
>>>>>>> c07b03107e0e0089b98d6ffbc0029dd2330f516a
	}

	cout << endl;
}
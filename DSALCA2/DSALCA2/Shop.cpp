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
	int input;
	if(currentUser == "Shopper")
	{
		Shoppers.front()->shopperMainMenu(&AllGames);
		
	}

}
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
	}
}	

void Shop::mainMenu()
{
	

}
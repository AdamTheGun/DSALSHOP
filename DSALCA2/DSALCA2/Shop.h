#pragma once

#include "Games.h"
#include "Shopper.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Shop
{
public:
	Shop(void);
	~Shop(void);
	void loadGame();
	void mainMenu();
	void setGameLibrary();
	void displayAllGames();
private:
	string currentUser;
	list<Shopper*> Shoppers;
	
	list<Games*> AllGames;
};


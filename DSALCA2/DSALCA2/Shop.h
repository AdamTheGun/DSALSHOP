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

	void getGameLibrary(list<Games*>&);
	void displayAllGames();
	void setGameLibrary();

private:
	string currentUser;
	list<Shopper*> Shoppers;
	
	list<Games*> AllGames;
};


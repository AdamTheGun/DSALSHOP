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
	void loginScreen();
	void mainMenu();

	void getGameLibrary(list<Games>&);
	void displayAllGames();

private:
	list<Shopper*> Shoppers;
protected:
	list<Games> AllGames;
};


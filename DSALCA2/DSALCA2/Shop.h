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
<<<<<<< HEAD

	void getGameLibrary(list<Games>&);
	void displayAllGames();

=======
	void setGameLibrary();
	void displayAllGames();
>>>>>>> 5ccba16738a5aefcc897fb33fa048521d122a33b
private:
	string currentUser;
	list<Shopper*> Shoppers;
	
	list<Games*> AllGames;
};


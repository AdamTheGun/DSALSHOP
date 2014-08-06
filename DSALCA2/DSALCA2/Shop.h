#pragma once

#include "Games.h"
#include "Shopper.h"
#include <iostream>
#include <string>

using namespace std;

class Shop
{
public:
	Shop(void);
	~Shop(void);
	void loginScreen();
private:
	list<Shopper*> Shoppers;
};


#pragma once
#include "user.h"
#include "Games.h"
#include <algorithm>
#include <list>

class Shopper :
	public User
{
public:
	Shopper(void);
	~Shopper(void);
	Shopper(string,int);
	void addToCart(Games);
	void removeFromCart(int);
	void printCart();
	void calculateTotal();
	float getTotal();
	int shopperMainMenu();
	void viewGames(list<Games> );
	void searchGames(list<Games> );
private:
	list<Games> CartOfGames;
	float totalAmount;	
	bool sameTotal;
	
};


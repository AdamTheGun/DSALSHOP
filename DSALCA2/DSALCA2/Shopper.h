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
	Shopper(string,int,list<Games*>);
	void addToCart(Games&);
	void removeFromCart(int);
	void printCart();
	void calculateTotal();
	float getTotal();
	void shopperMainMenu();
	void viewGames();
	void searchGames();
private:
	list<Games> CartOfGames;
	float totalAmount;	
	bool sameTotal;
	list<Games*> shopAllGames;
};


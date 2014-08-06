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
	void addToCart(Games&);
	void removeFromCart(int);
	void printCart();
	void calculateTotal();
	float getTotal();
private:
	list<Games> CartOfGames;
	float totalAmount;	
	bool sameTotal;
};

